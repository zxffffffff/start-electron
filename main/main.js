const path = require('path')
const { app, BrowserWindow, dialog, ipcMain } = require('electron')
const Addon = require('./addon/sample')

// IPC 渲染器进程到主进程（双向）
async function handleCall(msg) {
  if (msg === 'Init') {
    let path = '';
    let path2 = '';
    if (process.platform == 'darwin') {
      if (app.isPackaged) path = `${process.resourcesPath}/libsample-dynamic-lib.dylib`;
      else path = '../cpp/install/Release/bin/libsample-dynamic-lib.dylib'
    }
    else if (process.platform == 'win32') {
      if (app.isPackaged) path = `${process.resourcesPath}/todo`;
      else path = 'todo';
      path2 = 'todo';
    }
    else {
      // todo
    }
    const ok = await Addon.Init(path, path2)
    return `init ${ok ? 'ok' : 'err'}`;
  }
  else if (msg === 'Func') {
    return await Addon.Func('Electron')
  }
  else {
    console.log(`ipc 未知参数 ${msg}`)
    return '';
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

  if (app.isPackaged) {
    win.loadURL(`file://${process.resourcesPath}/build/index.html`);
  }
  else {
    win.loadURL(`http://localhost:3000`);
    win.webContents.openDevTools();
  }
}

app.on('window-all-closed', function () {
  if (process.platform !== 'darwin') app.quit()
})

app.whenReady().then(async () => {
  // IPC 渲染器进程到主进程（双向）
  ipcMain.handle('ipcCall', async (event, ...args) => {
    return await handleCall(...args);
  })

  createWindow()

  app.on('activate', function () {
    if (BrowserWindow.getAllWindows().length === 0) createWindow()
  })
})
