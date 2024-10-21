import { BaseRepository } from "../../../databases/mongodb/repository/baseRepository"
import { IChat } from "../../../types/chat"
import { IChatRepository } from "../../../types/chat/Chat"
import { Chat } from "../models/Chat"

export class ChatRepository
  extends BaseRepository<IChat>
  implements IChatRepository
{
  constructor() {
    super(Chat)
  }
}
