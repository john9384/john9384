import React, { useState } from "react"
import styled from "styled-components"

const ChatUI: React.FC = () => {
  const [messages, setMessages] = useState<string[]>([])
  const [input, setInput] = useState<string>("")
  const [socket, setSocket] = useState<WebSocket | null>(null)

  React.useEffect(() => {
    const newSocket = new WebSocket("ws://localhost:8080")

    newSocket.onopen = () => {
      console.log("WebSocket connected")
    }

    newSocket.onmessage = (event) => {
      const receivedMessage = event.data
      setMessages((prevMessages) => [...prevMessages, receivedMessage])
    }

    newSocket.onclose = () => {
      console.log("WebSocket disconnected")
    }

    setSocket(newSocket)

    return () => {
      newSocket.close()
    }
  }, [])

  const handleInputChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    setInput(e.target.value)
  }

  const handleSendMessage = () => {
    if (input.trim() !== "") {
      if (socket) {
        socket.send(input)
      }
      setMessages([...messages, input])
      setInput("")
    }
  }

  return (
    <ChatContainer>
      <div>
        {messages.map((message: string, index: number) => (
          <MessageBox key={index}>{message}</MessageBox>
        ))}
      </div>
      <div>
        <UserInput
          type="text"
          value={input}
          onChange={handleInputChange}
          placeholder="Type a message..."
        />
        <SendButton onClick={handleSendMessage}>Send</SendButton>
      </div>
    </ChatContainer>
  )
}

const ChatContainer = styled.div`
  width: 400px;
  border: 1px solid #ccc;
  border-radius: 5px;
  padding: 20px;
  margin: 20px;
`

const MessageBox = styled.div`
  background-color: #f0f0f0;
  padding: 10px;
  border-radius: 5px;
  margin-bottom: 10px;
`

const UserInput = styled.input`
  width: calc(100% - 20px);
  padding: 5px;
  margin: 0 10px;
`

const SendButton = styled.button`
  padding: 5px 10px;
  background-color: #007bff;
  color: #fff;
  border: none;
  border-radius: 5px;
  cursor: pointer;
`

export default ChatUI
