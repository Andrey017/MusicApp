export default {    
    generateRandomString(){
        return Math.random().toString(36).slice(2).substring(0, 15);
    },


    closeVideo(elemId){
        if(document.getElementById(elemId)){
            document.getElementById(elemId).remove();
        }
    },


    pageHasFocus(){
        return !(document.hidden || document.onfocusout || window.onpagehide || window.onblur);
    },


    getQString(url='', keyToReturn=''){
        url = url ? url : location.href;
        let queryStrings = decodeURIComponent(url).split('#', 2)[0].split('?', 2)[1];
        
        if(queryStrings){
            let splittedQStrings = queryStrings.split('&');
            
            if(splittedQStrings.length){
                let queryStringObj = {};
                
                splittedQStrings.forEach(function(keyValuePair){
                    let keyValue = keyValuePair.split('=', 2);
                    
                    if(keyValue.length){
                        queryStringObj[keyValue[0]] = keyValue[1];
                    }
                });            
                
                return keyToReturn ? (queryStringObj[keyToReturn] ? queryStringObj[keyToReturn] : null) : queryStringObj;
            }
            
            return null;
        }
        
        return null;
    },

    userMediaAvailable(){
        return !!(navigator.getUserMedia || navigator.webkitGetUserMedia || navigator.mozGetUserMedia || navigator.msGetUserMedia);
    },

    getConnectedDevices(type) {
        const devices = navigator.mediaDevices.enumerateDevices();

        Object.keys(devices).forEach(function(device) {
            console.log(device.kind + ": " + device.label +
                        " id = " + device.deviceId);
            
            if(device.kind === type){
                return "" + 1;
            }else {
                return "" + 0;
            }
        });
    },
    
    openCamera(cameras) {

        if(cameras == '1'){

        const devices = navigator.mediaDevices.enumerateDevices();

        Object.keys(devices).forEach(function(device) {
            console.log(device.kind + ": " + device.label +
                        " id = " + device.deviceId);
            
            if(device.kind === type){
                cameras = '' + 1;
            }else {
                cameras = '' + 0;
            }
        });
        
        }

        if(cameras == '1'){
            const constraints1 = {
                'audio': {'echoCancellation': true},
                'video': true
            }

            return navigator.mediaDevices.getUserMedia(constraints1);
        }else {
            const constraints2 = {
                'audio': {'echoCancellation': true},
                'video': false
            }

            return navigator.mediaDevices.getUserMedia(constraints2);
        }
    },
    


    getUserMedia(){
           
        if(this.userMediaAvailable()){

            return navigator.mediaDevices.getUserMedia({
                video:  true, 
                audio: {
                    echoCancellation: true
                }
            });
            
        }

        else{
            console.log('User media not available');
            throw new Error('User media not available');
        }
        
        
    },


    getIceServer(){        
        return {iceServers: [{ urls: 'stun:elsedel.starlink.ru:3478' },
                {
                    urls: 'turn:elsedel.starlink.ru:3478',
                    credential: 'dipl',
                    username: 'diplom'
                }
            ]
        };
    },
    
    
    addChat(data, senderType){
        let chatMsgDiv = document.querySelector('#chat-messages');
        let contentAlign = 'justify-content-end';
        let senderName = 'You';
        let msgBg = 'bg-white';

        if(senderType === 'remote'){
            contentAlign = 'justify-content-start';
            senderName = data.sender;
            msgBg = '';

            this.toggleChatNotificationBadge();
        }

        let infoDiv = document.createElement('div');
        infoDiv.className = 'sender-info';
        infoDiv.innerHTML = `${senderName} - ${moment().format('Do MMMM, YYYY h:mm a')}`;

        let colDiv = document.createElement('div');
        colDiv.className = `col-10 card chat-card msg ${msgBg}`;
        colDiv.innerHTML =  data.msg;

        let rowDiv = document.createElement('div');
        rowDiv.className = `row ${contentAlign} mb-2`;


        colDiv.appendChild(infoDiv);
        rowDiv.appendChild(colDiv);

        chatMsgDiv.appendChild(rowDiv);

        if(this.pageHasFocus){
            rowDiv.scrollIntoView();
        }
    },


    toggleChatNotificationBadge(){
        if(document.querySelector('#chat-pane').classList.contains('chat-opened')){
            document.querySelector('#new-chat-notification').setAttribute('hidden', true);
        }

        else{
            document.querySelector('#new-chat-notification').removeAttribute('hidden');
        }
    }
};