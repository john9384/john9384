import { contextBridge } from 'electron'

if (!process.contextIsolated) {
  throw new Error('contextIsolation must be enabled in the BrowserWindonw')
}

try {
  contextBridge.exposeInIsolatedWorld('context', {
    // TODO
  })
} catch (error) {
  console.log(error)
}
