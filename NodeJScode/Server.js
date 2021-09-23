var http = require('http'); // Import Node.js core module
const fs = require('fs');
const WebSocket = require('ws');

var index = fs.readFileSync('Web_visualization.html');


var server = http.createServer(function (req, res) {   //create web server
    if (req.url == '/') { //check the URL of the current request
        
        // set response header
        res.writeHead(200, { 'Content-Type': 'text/html' }); 
        
        // set response content    
        fs.createReadStream('Web_visualization.html').pipe(res);    
        //res.end(index);
    }
    else if (req.url == "/admin") {
        res.writeHead(200);
        res.end(hello);
    }
    else
        res.end('Invalid Request!');

});

server.listen(5000); //6 - listen for any incoming requests

console.log('Node.js web server at port 5000 is running..')

const wss = new WebSocket.Server({ port: 8001 });


 var WebSocketServer = require("ws").Server2;
  
  wss.on('connection', function connection(ws) {
      ws.on('message', function(message) {
         wss.broadcast(message);
      }); 
  
  }) ;

  
  wss.broadcast = function broadcast(msg) {
     //console.log(msg.toString());
     wss.clients.forEach(function each(client) {
         client.send(msg.toString());
      });
  };
      
   