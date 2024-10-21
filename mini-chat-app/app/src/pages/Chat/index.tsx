import styled from "styled-components"
import { ChatList } from "./ChatList"
import { ChatBox } from "./ChatBox"

export const Chat = () => {
  return (
    <ChatContainer>
      <LeftContainer>
        <ChatList />
      </LeftContainer>
      <RightContainer>
        <ChatBox />
      </RightContainer>
    </ChatContainer>
  )
}

const ChatContainer = styled.div`
  display: flex;
  height: 100vh;
  width: 100vw;
  background-color: white;
`
const LeftContainer = styled.div`
  height: 100%;
  width: 30%;
  border-right: 1px solid gray;
`
const RightContainer = styled.div`
  height: 100%;
  width: 70%;
`
