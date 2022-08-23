const { app, BrowserWindow, ipcMain } = require('electron');
const path = require('path');
const { fork } = require('child_process');

let mainWindow = null;
let cameraProcess = null;

// Handle creating/removing shortcuts on Windows when installing/uninstalling.
if (require('electron-squirrel-startup')) {
  // eslint-disable-line global-require
  app.quit();
}

function handleStartCamera(event, device) {
  console.log(`Starting camera: ${device}`);
  cameraProcess.send({ cmd: "START_CAMERA", device: device });
}

function handleStopCamera(event) {
  console.log(`Stopping camera`);
  cameraProcess.send({ cmd: "STOP_CAMERA" });
}

function updateFPS(fps) {
  mainWindow.webContents.send('update-fps', fps);
}

const createWindow = () => {
  // Create the browser window.
  mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      preload: path.join(__dirname, 'preload.js')
    }
  });

  // and load the index.html of the app.
  mainWindow.loadFile(path.join(__dirname, 'index.html'));

  cameraProcess = fork(path.join(__dirname, 'camera'));
  cameraProcess.on('message', (msg) => {
    if (msg.cmd == 'FPS') {
      updateFPS(msg.fps);
    }
  });
};

// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.on('ready', () => {
  ipcMain.on('start-camera', handleStartCamera);
  ipcMain.on('stop-camera', handleStopCamera);
  createWindow();
});

// Quit when all windows are closed, except on macOS. There, it's common
// for applications and their menu bar to stay active until the user quits
// explicitly with Cmd + Q.
app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit();
  }
});

app.on('activate', () => {
  // On OS X it's common to re-create a window in the app when the
  // dock icon is clicked and there are no other windows open.
  if (BrowserWindow.getAllWindows().length === 0) {
    createWindow();
  }
});

// In this file you can include the rest of your app's specific main process
// code. You can also put them in separate files and import them here.
