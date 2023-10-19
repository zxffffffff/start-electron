const path = require('path')
const { app, BrowserWindow, dialog, ipcMain } = require('electron')
//var addon = require('bindings')('hello');

// IPC 渲染器进程到主进程（双向）
async function handleFileOpen() {
  const { canceled, filePaths } = await dialog.showOpenDialog()
  if (canceled) {
    return
  } else {
    return filePaths[0]
  }
}

function createWindow() {
  const win = new BrowserWindow({
    width: 1600,
    height: 1200,
    webPreferences: {
      preload: path.join(__dirname, 'preload.js')
    }
  })

  //win.loadURL(`http://localhost:3000`);
  win.loadURL(`file://${process.resourcesPath}/build/index.html`);

  win.webContents.openDevTools();
}

app.on('window-all-closed', function () {
  if (process.platform !== 'darwin') app.quit()
})

app.whenReady().then(() => {
  // IPC 渲染器进程到主进程（双向）
  ipcMain.handle('ipcOpenFile', handleFileOpen)

  createWindow()

  app.on('activate', function () {
    if (BrowserWindow.getAllWindows().length === 0) createWindow()
  })
})
