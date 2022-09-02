const { contextBridge, ipcRenderer } = require('electron')

contextBridge.exposeInMainWorld('electronAPI', {
    startCamera: (device, framework) => ipcRenderer.send('start-camera', device, framework),
    stopCamera: () => ipcRenderer.send('stop-camera'),
    handleUpdateFPS: (callback) => ipcRenderer.on('update-fps', callback)
})