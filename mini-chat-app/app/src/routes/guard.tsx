import React from "react"
import { Navigate, Outlet } from "react-router-dom"

export const PublicRoute = () => {
  const isAuthenticated = true
  if (isAuthenticated) {
    return <Navigate to="/" />
  }

  return <Outlet />
}

export const PrivateRoute = () => {
  const isAuthenticated = true
  if (!isAuthenticated) {
    return <Navigate to="/auth/login" />
  }

  return <Outlet />
}
