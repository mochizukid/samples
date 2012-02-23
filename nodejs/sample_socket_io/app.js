var app = require('http').createServer(handler);
var io = require('socket.io').listen(app);
var fs = require('fs');

app.listen(50080);

function handler(req, res) {
    fs.readFile(__dirname + '/index.html', function (error, data) {
        if (error) {
	    res.writeHead(500);
	    return res.end('Error loading index.html');
	}
	res.writeHead(200);
	res.end(data);
    });
}

io.sockets.on('connection', function (socket) {
    socket.emit('news', {hello: 'world'});
    socket.on('my other event', function (data) {
        console.log(data);
    });
});
