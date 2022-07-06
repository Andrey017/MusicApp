let express = require('express');
const forceSSL = require('express-force-ssl');
const fs = require('fs');
const pathCERT = require('path');
let https = require('https');
let http = require('http');

let app = express();

app.set('forceSSLOptions', {
    httpsPort: 8443
});

let server = http.createServer(app);
let serverSSL = https.createServer({
    key: fs.readFileSync(pathCERT.join(__dirname, 'cert', 'key.pem')),
    cert: fs.readFileSync(pathCERT.join(__dirname, 'cert', 'cert.pem'))
}, app);

app.use(forceSSL);

app.set('view engine', 'ejs')

let io = require('socket.io')(serverSSL);
let stream = require('./ws/stream');
let path = require('path');

app.use('/assets', express.static(path.join(__dirname, 'assets')));

app.get('/', (req, res)=>{
    res.sendFile(__dirname+'/index.html');
});

app.get('/temp', (req, res)=>{
    res.sendFile(__dirname+'/temp.html');
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

io.of('/stream').on('connection', stream);

serverSSL.listen(8443, () => console.log('Secure server START on port 8443'));
server.listen(3000, () => console.log('Server START on port 3000'));