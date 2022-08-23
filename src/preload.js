const { contextBridge, ipcRenderer } = require('electron')

contextBridge.exposeInMainWorld('electronAPI', {
    startCamera: (device) => ipcRenderer.send('start-camera', device),
    stopCamera: () => ipcRenderer.send('stop-camera'),
    handleUpdateFPS: (callback) => ipcRenderer.on('update-fps', callback)
})