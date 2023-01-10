const test = require('test')
var assert = require('assert');
const axios = require('axios');

test('axios https test', async t => {
  await axios.get('https://www.baidu.com')
    .then(function (response) {
      // handle success
      //console.log(response);
    })
    .catch(function (error) {
      // handle error
      assert.fail(err);
    });
})
