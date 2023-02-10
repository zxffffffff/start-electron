const test = require('test')
var assert = require('assert');
const winston = require('winston');
const fs = require('fs');
const path = require('path')

const err_log = path.join(__dirname, 'error.log');
const com_log = path.join(__dirname, 'combined.log');

const logger = winston.createLogger({
  level: 'info',
  format: winston.format.json(),
  defaultMeta: { service: 'user-service' },
  transports: [
    //
    // - Write all logs with importance level of `error` or less to `error.log`
    // - Write all logs with importance level of `info` or less to `combined.log`
    //
    new winston.transports.File({ filename: err_log, level: 'error' }),
    new winston.transports.File({ filename: com_log }),
  ],
});

//
// If we're not in production then log to the `console` with the format:
// `${info.level}: ${info.message} JSON.stringify({ ...rest }) `
//
if (process.env.NODE_ENV !== 'production') {
  logger.add(new winston.transports.Console({
    format: winston.format.simple(),
  }));
}

test('winston log test', async t => {
  /*
    error: 0,
    warn: 1,
    info: 2,
    http: 3,
    verbose: 4,
    debug: 5,
    silly: 6
  */
  const errMsg = "this is [error] level msg.";
  const warnMsg = "this is [warn] level msg.";
  const infoMsg = "this is [info] level msg.";
  const debugMsg = "this is [debug] level msg.";
  logger.error(errMsg);
  logger.warn(warnMsg);
  logger.info(infoMsg);
  logger.debug(debugMsg);

  while (!fs.existsSync(err_log) || !fs.existsSync(com_log)) {
    await new Promise((resolve, reject) => {
      setTimeout(() => {
        resolve();
      }, 100);
    });
  }

  fs.readFileSync(err_log, (err, data) => {
    if (err) {
      assert.fail(err);
    } else {
      assert.notEqual(data.toString().indexOf(errMsg), -1);
    }
  });

  fs.readFileSync(com_log, (err, data) => {
    if (err) {
      assert.fail(err);
    } else {
      assert.notEqual(data.toString().indexOf(errMsg), -1);
      assert.notEqual(data.toString().indexOf(warnMsg), -1);
      assert.notEqual(data.toString().indexOf(infoMsg), -1);
      assert.notEqual(data.toString().indexOf(debugMsg), -1);
    }
  });

  fs.rm(err_log);
  fs.rm(com_log);
})
