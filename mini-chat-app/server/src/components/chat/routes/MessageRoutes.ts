import express from "express"
import { authenticate } from "../../../library/middlewares/authentication"
import { errorCatcher } from "../../../library/helpers/errorCatcher"
import { MessageController } from "../controllers/MessageController"

const messageController = new MessageController()

const messageRouter = express.Router()

messageRouter.get("/", authenticate, errorCatcher(messageController.index))

export default messageRouter
