const test = require('test')
var assert = require('assert');
var protobuf = require("protobufjs");

test('protobufjs pb test', async t => {
  // This test passes because it does not throw an exception.
  assert.strictEqual(1, 1)

  await protobuf.load("pb/req/HeartbeatReq.proto")
    .then((root) => {
      var HeartbeatReq = root.lookupType("HeartbeatReq");
      var payload = { reqIndex: 12345 };
      var errMsg = HeartbeatReq.verify(payload);
      if (errMsg) {
        assert.fail(errMsg);
      }
      var message = HeartbeatReq.create(payload);
      var buffer = HeartbeatReq.encode(message).finish();
      var message2 = HeartbeatReq.decode(buffer);
      var object = HeartbeatReq.toObject(message2, {
        longs: Number,
        enums: String,
        bytes: String,
        // see ConversionOptions
      });
      assert.strictEqual(payload.reqIndex, object.reqIndex);
    })
    .catch((err) => {
      assert.fail(err);
    });
})
