import { Read, Write } from "../../databases/mongodb/interface"

export interface IChat {
  id: string
  creatorId: string
  title: string
  adminList: string[]
  participants: string[]
}

export interface IChatRepository extends Read<IChat>, Write<IChat> {}
