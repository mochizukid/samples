var fs = require('fs');

fs.readFile('/etc/passwd', function (error, data) {
	if (error) {
	    throw error;
	}
	console.log(data);
    })