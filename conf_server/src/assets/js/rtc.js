import h from './helpers.js';

window.addEventListener('load', ()=>{
    const room = h.getQString(location.href, 'room');
    const username = h.getQString(location.href, 'user_name');
    const cam_on = h.getQString(location.href, 'cam_on');
    sessionStorage.setItem('username', username);

    if(!room){
        document.querySelector('#room-create').attributes.removeNamedItem('hidden');
    }

    else if(!username){
        document.querySelector('#username-set').attributes.removeNamedItem('hidden');
    }

    else{
        let commElem = document.getElementsByClassName('room-comm');

        for(let i = 0; i < commElem.length; i++){
            commElem[i].attributes.removeNamedItem('hidden');
        }

        var pc = [];

        let socket = io('/stream');

        var socketId = '';
        var myStream = '';

        socket.on('connect', ()=>{
            //set socketId
            var name_id_user = '' + username + '_' + socket.io.engine.id;

            socketId = name_id_user;
        

            socket.emit('subscribe', {
                room: room,
                socketId: socketId
            });


            socket.on('new user', (data)=>{
                socket.emit('newUserStart', {to:data.socketId, sender:socketId});
                pc.push(data.socketId);
                init(true, data.socketId);
            });


            socket.on('newUserStart', (data)=>{
                pc.push(data.sender);
                init(false, data.sender);
            });


            socket.on('ice candidates', async (data)=>{
                data.candidate ? await pc[data.sender].addIceCandidate(new RTCIceCandidate(data.candidate)) : '';
            });


            socket.on('sdp', async (data)=>{
                if(data.description.type === 'offer'){
                    data.description ? await pc[data.sender].setRemoteDescription(new RTCSessionDescription(data.description)) : '';

                    h.openCamera().then(async (stream)=>{
                        if(!document.getElementById('local').srcObject){
                            document.getElementById('local').srcObject = stream;
                        }

                        myStream = stream;

                        stream.getTracks().forEach((track)=>{
                            pc[data.sender].addTrack(track, stream);
                        });

                        let answer = await pc[data.sender].createAnswer();
                        
                        await pc[data.sender].setLocalDescription(answer);

                        socket.emit('sdp', {description:pc[data.sender].localDescription, to:data.sender, sender:socketId});
                    }).catch((e)=>{
                        console.error(e);
                    });                    
                }

                else if(data.description.type === 'answer'){
                    await pc[data.sender].setRemoteDescription(new RTCSessionDescription(data.description));
                }
            });


            socket.on('chat', (data)=>{
                h.addChat(data, 'remote');
            })
        });


        function sendMsg(msg){
            let data = {
                room: room,
                msg: msg,
                sender: username
            };

            socket.emit('chat', data);

            h.addChat(data, 'local');
        }

        function init(createOffer, partnerName){
            pc[partnerName] = new RTCPeerConnection(h.getIceServer());
            
            h.openCamera('' + cam_on).then((stream)=>{
                myStream = stream;

                stream.getTracks().forEach((track)=>{
                    pc[partnerName].addTrack(track, stream);
                });

                document.getElementById('local').srcObject = stream;
            }).catch((e)=>{
                console.error(`stream error: ${e}`);
            });

            if(createOffer){
                pc[partnerName].onnegotiationneeded = async ()=>{
                    let offer = await pc[partnerName].createOffer();
                    
                    await pc[partnerName].setLocalDescription(offer);

                    socket.emit('sdp', {description:pc[partnerName].localDescription, to:partnerName, sender:socketId});
                };
            }

            pc[partnerName].onicecandidate = ({candidate})=>{
                socket.emit('ice candidates', {candidate: candidate, to:partnerName, sender:socketId});
            };

            pc[partnerName].ontrack = (e)=>{
                let str = e.streams[0];
                if(document.getElementById(`${partnerName}-video`)){
                    document.getElementById(`${partnerName}-video`).srcObject = str;
                }

                else{
                    let newVid = document.createElement('video');
                    newVid.id = `${partnerName}-video`;            
                    newVid.srcObject = str;
                    newVid.autoplay = true;
                    newVid.className = 'remote-video';

                    var strString = '' + partnerName;
                    var str_arr = strString.split('_');

                    let newIId = document.createElement('p');
                    newIId.textContent = '' + str_arr[0];
                    
                    let cardDiv = document.createElement('div');
                    cardDiv.className = 'card mb-3';

                    let cardDivText = document.createElement('div');
                    cardDivText.className = 'card-body';
                    
                    cardDiv.appendChild(newVid);
                    cardDiv.appendChild(newIId);
                    
                    //create a new div for everything
                    let div = document.createElement('div');
                    div.className = 'col-sm-12 col-md-6';
                    div.id = partnerName;
                    div.appendChild(cardDiv);
                    document.getElementById('videos').appendChild(div);
                }
            };



            pc[partnerName].onconnectionstatechange = (d)=>{
                switch(pc[partnerName].iceConnectionState){
                    case 'disconnected':
                    case 'failed':
                        h.closeVideo(partnerName);
                        break;
                        
                    case 'closed':
                        h.closeVideo(partnerName);
                        break;
                }
            };



            pc[partnerName].onsignalingstatechange = (d)=>{
                switch(pc[partnerName].signalingState){
                    case 'closed':
                        console.log("Signalling state is 'closed'");
                        h.closeVideo(partnerName);
                        break;
                }
            };
        }


        document.getElementById('chat-input').addEventListener('keypress', (e)=>{
            if(e.which === 13 && (e.target.value.trim())){
                e.preventDefault();
                
                sendMsg(e.target.value);

                setTimeout(()=>{
                    e.target.value = '';
                }, 50);
            }
        });


        document.getElementById('toggle-video').addEventListener('click', (e)=>{
            e.preventDefault();

            myStream.getVideoTracks()[0].enabled = !(myStream.getVideoTracks()[0].enabled);

            //toggle video icon
            e.srcElement.classList.toggle('fa-video');
            e.srcElement.classList.toggle('fa-video-slash');
        });


        document.getElementById('toggle-mute').addEventListener('click', (e)=>{
            e.preventDefault();

            myStream.getAudioTracks()[0].enabled = !(myStream.getAudioTracks()[0].enabled);

            //toggle audio icon
            e.srcElement.classList.toggle('fa-volume-up');
            e.srcElement.classList.toggle('fa-volume-mute');
        });
    }
});