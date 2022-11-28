const {SerialPort} = require("serialport");

const port = new SerialPort({path: "/dev/ttyACM0", baudRate: 9600});

port.write("Example", function(err) {
    if (err) {
        return console.log(err.message);
    }

    console.log("Message written");
});

port.on("error", function(err) {
   console.log(err.message);
});
