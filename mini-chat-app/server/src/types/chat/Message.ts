import { Read, Write } from "../../databases/mongodb/interface"

export interface IMessage {
  id: string
  chatId: string
  senderId: string
  recieverId: string
  text: string
  isRead: boolean
}

export interface IMessageRepository extends Read<IMessage>, Write<IMessage> {}
