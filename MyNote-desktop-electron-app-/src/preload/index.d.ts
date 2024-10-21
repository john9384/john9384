/* eslint-disable @typescript-eslint/no-unused-vars */
import { ElectronAPI } from '@electron-toolkit/preload'

declare global {
  interface Window {
    // electron: ElectronAPI
    context: object
  }
}
