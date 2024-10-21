import styled from "styled-components"

export const ChatList = () => {
  return (
    <Container>
      <TopBar></TopBar>
      <Content>
        <SearchBar></SearchBar>
        <Chats></Chats>
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
const Chats = styled.div``
