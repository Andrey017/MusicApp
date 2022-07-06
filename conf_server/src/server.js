const express = require('express');
const mysql = require('mysql');
const bodyParser = require('body-parser');

const fs = require('fs');

const multer = require('multer');

const crypto = require('crypto');

var hel = require('./assets/js/server_function.js');

const jwt = require('jsonwebtoken');
const ACCESS_TOKEN_SECRET='dea7b23ae0c847fac9c6c956a24c1a37588c5be6ea6177fa395b788f56485227dc1670317af746be782aadb9b675c7c52334751b08b763d7fc25bc7bb07456ce';
const REFRESH_TOKEN_SECRET='742db7f6e0161628d01fe4764720067cf57226337788367a2db5ca8c530f69ff9362aeebc8b40d6e541bc2abec796282f6daa091da0fda30fa5cefbc6b7cc3ba';

var app = express();

const pool = mysql.createPool({
    host: 'localhost',
    user: 'root',
    database: 'diplom',
    password: 'dip'
});

const storageConfig = multer.diskStorage({
    destination: (req, file, cb) => {
        var flName = req.query.folderNameMu;
        if (!fs.existsSync(__dirname + "/uploads/" + flName)){
            try {
                fs.mkdirSync(__dirname + "/uploads/" + flName, {recursive: true});
            }catch(error) {
                console.error(error);
            }
        } else {
            console.log('SUCCESSFUL');
        }

        cb(null, __dirname + "/uploads/" + flName);
    },

    filename: (req, file, cb) => {
        cb(null, file.originalname);
    }
});

app.use(express.static(__dirname));
app.use(multer({
    storage: storageConfig
}).single("filedata"));

app.post('/upload', function(req, res, next) {
    let filedata = req.file;

    console.log(filedata);

    if(!filedata){
        res.send("Ошибка при загрузке файла");
    } else {
        res.send("Файл загружен");
    }
});

app.get('/uploads', (req, res) => {
    console.log('URL: ' + req.url);

    const filePath = req.url.substr(1);
    console.log('FILE Path: ' + filePath);

    fs.access(filePath, fs.constants.R_OK, err => {
        if(err){
            res.statusCode = 404;
            res.end("NOT Found");
        } else {
            fs.createReadStream(filePath).pipe(res);
        }
    });
});

app.get('/readFolder', (req, res) => {
    var r_room_id = req.query.room_id;

    const dir = __dirname + "/uploads/" + r_room_id + "/";

    try {
        const files = fs.readdirSync(dir);

        console.log(files);

        res.send(files);
    }catch (error){
        console.error(error);
    }
});

app.get('/reg', (req, res) => {
    var email = req.query.email;
    var name = req.query.name;
    var surname = req.query.surname;
    var password = req.query.password;

    var active = "0";

    var access_token = "access";
    var refresh_token = "refresh";

    var path_avatar = "def";

    var password_sec = md(email, password);

    pool.query('INSERT INTO user SET email=?, name=?, surname=?, password=?, active=?, access_token=?, refresh_token=?, path_avatar=?;', [email, name, surname, password_sec, active, access_token, refresh_token, path_avatar], (error, result) => {
        if(error){
            throw error;
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send("" + result.insertId);
    });
});

app.get('/load_avatar', (req, res) => {
    var user_id = req.query.user_id;
    var name_avatar = req.query.name_avatar;

    pool.query('UPDATE user SET path_avatar=? WHERE id=?;', [name_avatar, user_id], (error, result) => {
        if(error){
            throw error;
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send(result);
    });
});

app.get('/auth', (req, res) => {
    var email = req.query.email;
    var password = req.query.pass;
    
    const access_token = generateAccessToken(email, password);
    res.json({ access_token: access_token });
})

app.get('/login', (req, res) => {
    var email = req.query.email;
    var password = req.query.password;

    var password_sec = md(email, password);

    pool.query('SELECT id, email, name, surname, active, access_token, refresh_token, path_avatar FROM user WHERE email=? AND password=?;', [email, password_sec], (error, result) => {
        if(error) {
            throw error;
        }

        var str_result = result;

        if (str_result != ""){
            result[0].access_token = generateAccessToken(email, password_sec);
            result[0].refresh_token = generateRefreshToken(email, password_sec);
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send(result);
    });
});

app.get('/create_room', (req, res) => {
    var user_id = req.query.user_id;
    var name_room = req.query.name_room;
    var path_picture = req.query.path_picture;
    
    var link_room = `${name_room.trim().replace(' ', '_')}_${Math.random().toString(36).slice(2).substring(0, 15)}`;

    pool.query('INSERT INTO room SET name=?, link=?, path_picture=?;', [name_room, link_room, path_picture], (error, result) => {
        if(error) {
            throw error;
        }

        var room_id = result.insertId;

        pool.query('INSERT INTO userroom SET user_id=?, room_id=?;', [user_id, room_id], (error, result) => {
            if(error) {
                throw error;
            }

            res.setHeader('Access-Control-Allow-Origin', '*');
            res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
            res.send("" + room_id);
        });
    });
});

app.get('/load_room_user', (req, res) => {
    var user_id = req.query.user_id;

    pool.query('SELECT r.id, r.name, r.path_picture FROM room r INNER JOIN userroom ur ON ur.room_id=r.id WHERE ur.user_id=?;', [user_id], (error, result) => {
        if(error) {
            throw error;
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send(result);
    });
});

app.get('/load_link_room', (req, res) => {
    var room_id = req.query.room_id;

    pool.query('SELECT link FROM room WHERE id=?;', [room_id], (error, result) => {
        if(error) {
            throw error;
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send("" + result[0].link);
    });
});

app.get('/load_id_user', (req, res) => {
    var email_user = req.query.email_user;

    pool.query('SELECT id FROM user WHERE email=?;', [email_user], (error, result) => {
        if(error) {
            throw error;
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send("" + result[0].id);
    });
});

app.get('/add_new_user', (req, res) => {
    var id_user = req.query.id_user;
    var id_room = req.query.id_room;

    pool.query('INSERT INTO userroom SET user_id=?, room_id=?;', [id_user, id_room], (error, result) => {
        if(error) {
            throw error;
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send("" + result.affectedRows);
    });
});

app.get('/join_room', (req, res) => {
    var id_user = req.query.id_user;
    var invite_room = req.query.code;

    pool.query('SELECT id FROM room WHERE link=?;', [invite_room], (error, result) => {
        if(error) {
            throw error;
        }

        var id_room = result[0].id;

        if(id_room != ""){
            pool.query('INSERT INTO userroom SET user_id=?, room_id=?;', [id_user, id_room], (error, result) => {
                if(error) {
                    throw error;
                }
        
                res.setHeader('Access-Control-Allow-Origin', '*');
                res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
                res.send("" + result.affectedRows);
            });
        }else {
            res.setHeader('Access-Control-Allow-Origin', '*');
            res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
            res.send("0");    
        }
    });
});

app.get('/load_user_in_room', (req, res) => {
    var room_id = req.query.room_id;

    pool.query('SELECT u.id, u.name, u.surname, u.path_avatar FROM user u INNER JOIN userroom ur ON ur.user_id=u.id WHERE ur.room_id=?;', [room_id], (error, result) => {
        if(error) {
            throw error;
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send(result);
    });
});

app.get('/add_new_audio', (req, res) => {
    var name_audio = req.query.name_audio;
    var name_creators = req.query.name_creators;
    var id_room = req.query.id_room;
    var acceess = req.query.access;
    var path_picture = req.query.path_picture;
    var type = req.query.type;

    pool.query('INSERT INTO audio_info SET name_audio=?, name_creators=?, id_room=?, access=?, path_picture=?, type=?;', [name_audio, name_creators, id_room, acceess, path_picture, type], (error, result) => {
        if(error) {
            throw error;
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send("" + result.affectedRows);
    });
});

app.get('/load_audio_info', (req, res) => {
    var user_id = req.query.user_id;
    var type = req.query.type;

    pool.query('SELECT ai.id, ai.name_audio, ai.name_creators, ai.id_room, ai.access, ai.path_picture, ai.type, r.name FROM audio_info ai INNER JOIN room r ON r.id=ai.id_room INNER JOIN userroom us ON us.room_id=r.id WHERE us.user_id=? AND ai.type=?;', [user_id, type], (error, result) => {
        if(error) {
            throw error;
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send(result);
    });
});

app.get('/add_new_tab', (req, res) => {
    var name = req.query.name;
    var creator = req.query.creator;
    var id_room = req.query.id_room;
    var access = req.query.access;
    var description = req.query.user_id;//req.query.description;

    pool.query('INSERT INTO tab SET name=?, creator=?, access=?, description=?, id_room=?;', [name, creator, access, description, id_room], (error, result) => {
        if(error) {
            throw error;
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send("" + result.affectedRows);
    });
});

app.get('/load_tab', (req, res) => {
    var user_id = req.query.user_id;
    var access = req.query.access;

    pool.query('SELECT name, creator FROM tab WHERE description=? AND access=?;', [user_id, access], (error, result) => {
        if(error) {
            throw error;
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send(result);
    });
});

app.get('/load_tab_search', (req, res) => {
    var user_id = req.query.user_id;
    var name = req.query.name;

    pool.query('SELECT name, creator FROM tab WHERE description=? AND name=?;', [user_id, name], (error, result) => {
        if(error) {
            throw error;
        }

        res.setHeader('Access-Control-Allow-Origin', '*');
        res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
        res.send(result);
    });
});

app.get('/token', (req, res) => {
    var user_id = req.query.id;
    var token = req.query.token;

    pool.query('SELECT email, password, access_token FROM user WHERE id=? AND refresh_token=?;', [user_id, token], (error, result) => {
        if(error) {
            throw error;
        }

        var result_str = result;

        if(result_str != '[]'){
            var access_token = generateAccessToken(result[0].email, result[0].password);

            pool.query('UPDATE user SET access_token=? WHERE id=?;', [access_token, user_id], (error, result) => {
                if(error) {
                    throw error;
                }

                res.setHeader('Access-Control-Allow-Origin', '*');
                res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
                res.send("" + access_token);    
            });
        }else {
            res.setHeader('Access-Control-Allow-Origin', '*');
            res.setHeader('Access-Control-Allow-Headers', 'origin, content-type, accept');
            res.send("0");    
        }
    });
});

function md(email, code){
    var string = "" + email + code;
    var pass_crypto = crypto.createHash('md5').update(string).digest('hex');

    return pass_crypto;
}

function generateAccessToken(email, password){
    var date = Math.floor(Date.now() / 1000) + (60 * 60);
    const data = {
        email: email,
        pass: password,
        date_generate: date
    }

    return jwt.sign(data, ACCESS_TOKEN_SECRET, { expiresIn: '6h'} );
}

function generateRefreshToken(email, password){
    var date = Math.floor(Date.now() / 1000) + (60 * 60);

    const data = {
        email: email,
        pass: password,
        date_generate: date
    }

    return jwt.sign(data, REFRESH_TOKEN_SECRET);
}

app.listen(8011, () => console.log('Start server PORT 8011'));