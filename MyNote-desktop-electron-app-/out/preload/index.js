"use strict";
const electron = require("electron");
if (!process.contextIsolated) {
  throw new Error("contextIsolation must be enabled in the BrowserWindonw");
}
try {
  electron.contextBridge.exposeInIsolatedWorld("context", {
    // TODO
  });
} catch (error) {
  console.log(error);
}
