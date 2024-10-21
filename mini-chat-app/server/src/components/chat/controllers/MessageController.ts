import { SuccessResponse } from "../../../library/helpers/response"
import { MessageRepository } from "../repositories/MessageRepository"
import { MessageService } from "../services/MessageService"

const messageService = new MessageService(new MessageRepository())

export class MessageController {
  public async index(req: any, res: any) {
    const query = req.query
    const outcome = await messageService.read(query)
    return new SuccessResponse("Message fetched", outcome).send(res)
  }

  public async read(req: any, res: any) {
    const outcome = await messageService.read({ id: req.params.id })
    return new SuccessResponse("Message fetched", outcome).send(res)
  }

  public async update(req: any, res: any) {
    const payload = req.body
    const outcome = await messageService.update({ id: req.params.id }, payload)
    return new SuccessResponse("Message updated", outcome).send(res)
  }

  public async delete(req: any, res: any) {
    const outcome = await messageService.delete(req.params.id)
    return new SuccessResponse("Message deleted", outcome).send(res)
  }
}

export default MessageController
