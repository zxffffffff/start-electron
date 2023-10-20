export default class IpcBridge {
    static async Call(msg: string) {
        return await window.electronAPI.Call(msg);
    }
}
