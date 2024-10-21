import { BadRequestError } from "../../../library/helpers/error"
import { IChatRepository } from "../../../types/chat/Chat"

export class ChatService {
  constructor(private chatRepository: IChatRepository) {}

  public async create(payload: any) {
    const newChat = await this.chatRepository.create(payload)
    return newChat
  }

  public async read(query: any) {
    const chat = await this.chatRepository.findOne(query)

    return chat
  }

  public async readMany(query: any) {
    const chat = await this.chatRepository.find(query)

    return chat
  }

  public async update(query: any, payload: any) {
    const existingChat = await this.chatRepository.findOne(query)

    if (!existingChat) throw new BadRequestError("No existing chat")

    const updatedChat = await this.chatRepository.update(query, payload)

    return updatedChat
  }

  public async delete(id: string) {
    const existingChat = await this.chatRepository.findOne({ id })

    if (!existingChat) throw new BadRequestError("No existing chat")

    await this.chatRepository.delete(id)

    return { id }
  }
}
