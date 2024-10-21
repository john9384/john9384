import express from "express"
import { authenticate } from "../../../library/middlewares/authentication"
import { errorCatcher } from "../../../library/helpers/errorCatcher"
import { ChatController } from "../controllers"

const chatController = new ChatController()

const chatRouter = express.Router()

chatRouter.get("/", authenticate, errorCatcher(chatController.index))

export default chatRouter
