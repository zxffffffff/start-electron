const addon = require('bindings')('addon');

class Addon {
    static async Init(path, file) {
        return await addon.Init(path, file ?? "")
    }

    static async Func(name) {
        return await addon.Func(name);
    }
}

module.exports = Addon;