import styled from "styled-components"

export const ChatBox = () => {
  return (
    <Container>
      <TopBar></TopBar>
      <Content>
        <SearchBar></SearchBar>
        <MessageList></MessageList>
      </Content>
    </Container>
  )
}

const Container = styled.div``
const TopBar = styled.div`
  height: 60px;
  border-bottom: 1px solid gray;
`
const Content = styled.div``
const SearchBar = styled.div``
const MessageList = styled.div``
