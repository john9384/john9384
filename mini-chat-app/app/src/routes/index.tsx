import { useRoutes } from "react-router-dom"
import { PrivateRoute, PublicRoute } from "./guard"
import { authRoutes } from "./authRoutes"
import { chatRoutes } from "./chatRoutes"

export const AppRoutes = () => {
  return useRoutes([
    {
      path: "/auth",
      element: <PublicRoute />,
      children: authRoutes,
    },
    {
      path: "/",
      element: <PrivateRoute />,
      children: chatRoutes,
    },
    {
      path: "*",
      element: <div> Page not found</div>,
    },
  ])
}
