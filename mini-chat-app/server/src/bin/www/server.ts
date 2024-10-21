import config from "../../config"
import appConfiguration from "../../app"
import { MongoDBConnection } from "../../databases/mongodb/access/dbConnection"

initializeServer()
  .then(() => {
    console.info(`
    ################################################
      ${config.appName} has been initialized
    ################################################
            `)
  })
  .catch((error: Error) => {
    console.error(error)
    throw error
  })

async function initializeServer(): Promise<void> {
  const server = appConfiguration()

  await MongoDBConnection.initConnection()

  server.listen(config.port || 4000, () => {
    console.log(`
    ################################################
      Express Server listening on port: ${config.port}
    ################################################
    `)
  })
}
