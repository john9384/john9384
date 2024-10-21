import { Login } from "../pages/auth/Login"
import { SignUp } from "../pages/auth/Signup"

export const authRoutes = [
  {
    path: "signup",
    element: <SignUp />,
  },
  {
    path: "login",
    element: <Login />,
  },

  {
    path: "*",
    element: <div></div>,
  },
]
