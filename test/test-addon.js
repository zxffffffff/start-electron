const test = require('test')
var assert = require('assert');
var addon = require('bindings')('hello');

test('addon dll test', t => {
  const r = addon.hello();
  assert(r === "456", "r = " + r);
})
