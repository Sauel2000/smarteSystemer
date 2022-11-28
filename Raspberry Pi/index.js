const {app, BrowserWindow} = require("electron");
//const Gpio = require("onoff").Gpio;

const ipc = require("electron").ipcMain;

app.on("ready", function() {
	var mainWindow = new BrowserWindow({
		show: false,
		autoHideMenuBar: false,
		webPreferences: {
		    nodeIntegration: true,
		    contextIsolation: false
		}
	});
	mainWindow.maximize();
	mainWindow.setFullScreen(true);
	mainWindow.loadFile("index.html");
	mainWindow.show();
});

//var led = new Gpio(4, "out");

ipc.on("syncMessage", (event, args) => {
    console.log(args);
    event.sender.send("syncReply", "Example");
});
