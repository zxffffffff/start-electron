# start-electron
 一个 Electron 跨平台脚手架项目，使用 Electron (Node.js) 和 Web (React + Typescript) 分别搭建两个工程

> Electron development is unopinionated - there is no "one true way" to develop, build, package, or release an Electron application.
> Electron 开发是不固定的 - 没有“一种真正的方法”来开发、构建、打包或发布 Electron 应用程序。


## 一、创建 Web(React/TS) 工程
- 参考：https://github.com/zxffffffff/start-web-react.git
```bash
// 使用 React + Typescript 脚手架
npx create-react-app start-electron-web --template typescript
// 重命名工程：web
// 资源路径配置："homepage": "./"
```


## 二、创建 Electron(Node) 工程
- 参考：https://www.electronjs.org/zh/docs/latest/tutorial/quick-start
- 参考：https://www.electronforge.io/cli
```bash
// 新建工程文件夹：main
npm init
npm install --save-dev electron --verbose // 下载巨大，用verbose查看进度
// 添加代码：main.js preload.js

npm install --save-dev @electron-forge/cli
npx electron-forge import
// 打包Web：extraResource: ['../web/build']
```

### 可选：C++ Addon
- C++插件，node-addon-api is based on Node-API
- 参考：https://github.com/nodejs/node-addon-api
- 参考：https://github.com/TooTallNate/node-bindings
```bash
npm i node-addon-api bindings
// 插件支持："gypfile": true
// C++配置文件：binding.gyp
node-gyp configure // 生成C++项目
node-gyp build     // 编译C++项目
```


## 三、其他

### 国内npm镜像
- 参考：https://registry.npmmirror.com/
- 临时修改(阿里镜像)：`npm install xxx --registry https://registry.npm.taobao.org/`
- 全局修改(阿里镜像)：`npm config set registry https://registry.npm.taobao.org/`

### Vue
- 参考：https://www.electronjs.org/zh/docs/latest/tutorial/quick-start
- 安装：`npm install --save-dev electron`
- 处理 Vue 兼容性问题：
  - 资源文件改为相对路径 (vue.config.js) `publicPath: './'`
  - 资源文件改为相对路径 (vite.config.js) `base: './'`
  - 处理 CSP 提示 (index.html) `<meta http-equiv="Content-Security-Policy" content="script-src 'self' 'unsafe-inline';" />`
- 打包: `npm install --save-dev @electron-forge/cli`
  - `npx electron-forge import`
  - `npm run make`
  - todo：签名
- 使用 `npm run build` 编译生成 `dist` 前端项目资源
- 运行 Electron `npx electron .` 或使用 `.vscode\launch.json` F5运行

### Vue
- 参考：https://github.com/vuejs/create-vue
- 脚手架：`npm create vue@3`

### Element（Vue）
- 参考：https://element-plus.gitee.io/zh-CN/guide/quickstart.html
- 安装：`npm install element-plus --save`
- 完整引入(main.js)：
  - `import ElementPlus from 'element-plus'`
  - `import 'element-plus/dist/index.css'`
  - `app.use(ElementPlus)`

### Electron + Next.js
- 参考：https://github.com/vercel/next.js/tree/canary/examples/with-electron
https://github.com/vercel/next.js/tree/canary/examples/with-electron-typescript
- 创建：`create-next-app`

### protobufjs
- 参考：https://github.com/protobufjs/protobuf.js/
- 安装：`npm install protobufjs --save` 
- 可选反射和静态代码引入，两者在性能方面没有显着差异
- 1.反射 (Reflection)：
  - 引入：`var protobuf = require("protobufjs");` 
   - 使用：`protobuf.load("xxx.proto")`
- 2.静态代码 (static code)：
  - 安装 CLI：`npm install protobufjs-cli --save`

### Axios
- 用于浏览器和 node.js 的基于 Promise 的 HTTP 客户端
- 参考：https://github.com/axios/axios
- 安装：`npm install axios --save`
- 使用：`const axios = require('axios');` 

### test
- 参考：https://github.com/nodejs/node-core-test
- 安装：`npm install test`
- 使用：`node --test` 默认递归正则查找包含"test"关键字的文件，也可指定文件

### winston
- 日志库
- 参考：https://github.com/winstonjs/winston
- 安装：`npm i winston --save`
- 使用：`const winston = require('winston');` 
