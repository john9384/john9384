import { Chat } from "../pages/Chat"

export const chatRoutes = [
  {
    path: "",
    element: <Chat />,
  },

  {
    path: "*",
    element: <div></div>,
  },
]
