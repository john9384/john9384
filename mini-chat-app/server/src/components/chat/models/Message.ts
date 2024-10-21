import { model, Schema } from "mongoose"
import { IMessage } from "../../../types/chat"

export const DOCUMENT_NAME = "Message"
export const COLLECTION_NAME = "messages"

const messageSchema = new Schema<IMessage>(
  {
    chatId: {
      type: String,
      trim: true,
    },
    senderId: {
      type: String,
      required: true,
    },
    recieverId: {
      type: String,
      required: true,
    },
    text: {
      type: String,
      required: true,
    },
    isRead: {
      type: Boolean,
      required: true,
      default: false,
    },
  },
  {
    timestamps: true,
    toJSON: {
      virtuals: true,
    },
  }
)

export const Message = model<IMessage>(
  DOCUMENT_NAME,
  messageSchema,
  COLLECTION_NAME
)
