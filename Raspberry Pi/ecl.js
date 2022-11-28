const Gpio = require("onoff").Gpio;
const {SerialPort} = require("serialport");
const {ReadlineParser} = require("@serialport/parser-readline");

const args = process.argv.slice(2);

console.log(args);

const serialport = new SerialPort({path: "/dev/ttyACM0", baudRate: 9600});

setTimeout(function() {
    serialport.write(args[0] + args[1]);
    serialport.close();
}, 1000);

/*const parser = serialport.pipe(new ReadlineParser({delimiter: "\n"}));
parser.on("data", function(data) {
    console.log(data);
});*/

/*
serialport.on("data", function(data) {
    console.log(data);
});
*/
