const test = require('test')
var assert = require('assert');
const ffi = require('ffi-napi');

function toCString(text) {
  return new Buffer.from(text, 'ucs2').toString('binary');
};

// 通过 ffi 加载 user32.dll
const user32 = new ffi.Library('user32', {
  'MessageBoxW': // 声明这个dll中的一个函数
    [
      'int32', ['int32', 'string', 'string', 'int32'],
    ],
});

test('protobufjs ffi test', async t => {
  // 弹出一个对话框
  const isOk = user32.MessageBoxW(
    0, toCString('I am Node.JS!'), toCString('Hello, World!'), 1
  );
  assert(isOk);
})
