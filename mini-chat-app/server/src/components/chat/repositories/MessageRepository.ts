import { BaseRepository } from "../../../databases/mongodb/repository/baseRepository"
import { IMessage } from "../../../types/chat"
import { IMessageRepository } from "../../../types/chat/Message"
import { Message } from "../models/Message"

export class MessageRepository
  extends BaseRepository<IMessage>
  implements IMessageRepository
{
  constructor() {
    super(Message)
  }
}
