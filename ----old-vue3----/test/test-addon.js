const test = require('test')
var assert = require('assert');
var addon = require('bindings')('hello');

test('addon dll test', t => {
  const r = addon.TestMulti(3, 4);
  assert(r === 12, "r = " + r);
})
