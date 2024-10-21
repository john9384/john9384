import { BadRequestError } from "../../../library/helpers/error"
import { IMessageRepository } from "../../../types/chat/Message"

export class MessageService {
  constructor(private messageRepository: IMessageRepository) {}

  public async create(payload: any) {
    const newMessage = await this.messageRepository.create(payload)
    return newMessage
  }

  public async read(query: any) {
    const message = await this.messageRepository.findOne(query)

    return message
  }

  public async readMany(query: any) {
    const message = await this.messageRepository.find(query)

    return message
  }

  public async update(query: any, payload: any) {
    const existingChat = await this.messageRepository.findOne(query)

    if (!existingChat) throw new BadRequestError("No existing message")

    const updatedChat = await this.messageRepository.update(query, payload)

    return updatedChat
  }

  public async delete(id: string) {
    const existingChat = await this.messageRepository.findOne({ id })

    if (!existingChat) throw new BadRequestError("No existing message")

    await this.messageRepository.delete(id)

    return { id }
  }
}
