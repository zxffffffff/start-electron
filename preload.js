const { contextBridge, ipcRenderer } = require('electron')

contextBridge.exposeInMainWorld('electronAPI', {
  // IPC 渲染器进程到主进程（双向）
  // 出于安全原因，我们不会直接暴露整个 ipcRenderer.invoke API
  openFile: () => ipcRenderer.invoke('ipcOpenFile')
})
