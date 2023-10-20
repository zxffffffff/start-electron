export interface IElectronAPI {
  Call: (string) => Promise<string>,
}

declare global {
  interface Window {
    electronAPI: IElectronAPI
  }
}
