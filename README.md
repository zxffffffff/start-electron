# start-electron
 一个 Electron 跨平台脚手架项目，使用 Vue3 + Element Plus 构建
- 使用 `npm run build` 编译生成 `dist` 前端项目资源
- 运行 Electron `npx electron .` 或使用 `.vscode\launch.json` F5运行

# Vue
- 参考：https://github.com/vuejs/create-vue
- 脚手架：`npm create vue@3`

# Element
- 参考：https://element-plus.gitee.io/zh-CN/guide/quickstart.html
- 安装：`npm install element-plus --save`
- 完整引入(main.js)：
    - `import ElementPlus from 'element-plus'`
    - `import 'element-plus/dist/index.css'`
    - `app.use(ElementPlus)`

# Electron
- 参考：https://www.electronjs.org/zh/docs/latest/tutorial/quick-start
- 安装：`npm install --save-dev electron`
- 处理 Vue 兼容性问题：
    - 资源文件改为相对路径 (vue.config.js) `publicPath: './'`
    - 资源文件改为相对路径 (vite.config.js) `base: './'`
    - 处理 CSP 提示 (index.html) `<meta http-equiv="Content-Security-Policy" content="script-src 'self' 'unsafe-inline';" />`
