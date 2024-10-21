import { SuccessResponse } from "../../../library/helpers/response"
import { ChatRepository } from "../repositories/ChatRepository"
import { ChatService } from "../services/ChatService"

const chatService = new ChatService(new ChatRepository())

export class ChatController {
  public async index(req: any, res: any) {
    const userId = req.user.id
    const outcome = await chatService.readMany({ creatorId: userId })
    return new SuccessResponse("Chat fetched", outcome).send(res)
  }

  public async read(req: any, res: any) {
    const outcome = await chatService.read({ id: req.params.id })
    return new SuccessResponse("Chat fetched", outcome).send(res)
  }

  public async update(req: any, res: any) {
    const payload = req.body
    const outcome = await chatService.update({ id: req.params.id }, payload)
    return new SuccessResponse("Chat updated", outcome).send(res)
  }

  public async delete(req: any, res: any) {
    const outcome = await chatService.delete(req.params.id)
    return new SuccessResponse("Chat deleted", outcome).send(res)
  }
}

export default ChatController
