import { model, Schema } from "mongoose"
import { IChat } from "../../../types/chat"

export const DOCUMENT_NAME = "Chat"
export const COLLECTION_NAME = "chats"

const messageSchema = new Schema<IChat>(
  {
    creatorId: {
      type: String,
      trim: true,
    },
    title: {
      type: String,
      required: true,
    },
    adminList: [{ type: String }],
    participants: [{ type: String }],
  },
  {
    timestamps: true,
    toJSON: {
      virtuals: true,
    },
  }
)

export const Chat = model<IChat>(DOCUMENT_NAME, messageSchema, COLLECTION_NAME)
