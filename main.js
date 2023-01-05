const path = require('path')
const { app, BrowserWindow } = require('electron')

function createWindow() {
  const win = new BrowserWindow({
    width: 1600,
    height: 1200
  })

  win.loadURL(`file://${__dirname}/dist/index.html`);

  win.webContents.openDevTools();
}


app.on('window-all-closed', function () {
  if (process.platform !== 'darwin') app.quit()
})

app.whenReady().then(() => {
  createWindow()

  app.on('activate', function () {
    if (BrowserWindow.getAllWindows().length === 0) createWindow()
  })
})
