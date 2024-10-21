#include <iostream>
#include <cstring>


void printScore(int userScore, int computerScore);
void printValues(int userValue, int computerValue, std::string winner, bool isATie);

int main(int argc, const char * argv[]) {
    const char ROCK = 'R';
    const char PAPER =  'P';
    const char SCISSORS = 'S';
    char gameOptions[3] = {ROCK, PAPER, SCISSORS};
    int userScore = 0;
    int computerScore = 0;
    
    int currentRound = 0;
    char userInput;
    int gameRounds;
    
    std::cout << "How many rounds of game do you want to play" << std::endl;
    std::cin>>gameRounds;
    
    while(currentRound < gameRounds){
        std::cout<< "Enter your choice" << std::endl;
        std::cout<< "R - Rock" << std::endl;
        std::cout<< "P - Paper" << std::endl;
        std::cout<< "S - Scissors" << std::endl;
        std::cout<< "Enter 'X' to close the game" << std::endl;
        std::cin>> userInput;
        
        char userValue = std::toupper(userInput);
        char computerValue = gameOptions[std::rand() % 3];
        if(userValue == 'X'){
            break;
        }
        
        if(userValue == ROCK){
            if(computerValue == SCISSORS){
                userScore+=1;
                printValues(userValue, computerValue, "User", false);
            }
            if(computerValue == PAPER){
                computerScore+=1;
                printValues(userValue, computerValue, "Computer", false);
            }
            if(computerValue == ROCK){
                userScore = userScore;
                computerScore = computerScore;
                printValues(userValue, computerValue, "None", true);
            }
        }
        else if(userValue == PAPER){
            if(computerValue == SCISSORS){
                computerScore+=1;
                printValues(userValue, computerValue, "Computer", false);
            }
            if(computerValue == PAPER){
                userScore = userScore;
                computerScore = computerScore;
                printValues(userValue, computerValue, "None", true);
            }
            if(computerValue == ROCK){
                userScore+=1;
                printValues(userValue, computerValue, "User", false);
            }
        }
        else if(userValue == SCISSORS){
            if(computerValue == SCISSORS){
                userScore = userScore;
                computerScore = computerScore;
                printValues(userValue, computerValue, "None", true);
            }
            if(computerValue == PAPER){
                userScore+=1;
                printValues(userValue, computerValue, "User", false);
            }
            if(computerValue == ROCK){
                computerScore+=1;
                printValues(userValue, computerValue, "Computer", false);
            }
        }else{
            currentRound = currentRound;
            continue;
        }
        
        printScore(userScore, computerScore);
        currentRound++;
    }
    
    return 0;
}

void printScore(int userScore, int computerScore){

    std::cout << " ====================================" << std::endl;
    std::cout << "      User " << userScore << " : " << computerScore << " Computer" << std::endl;
    std::cout << " ====================================" << std::endl;
    std::cout << "\n" << std::endl;
}

void printValues(int userValue, int computerValue, std::string winner, bool isATie){
    const char ROCK = 'R';
    const char PAPER =  'P';
    const char SCISSORS = 'S';
    std::string userValueText, computerValueText;
    
    if(userValue == 'R'){
        userValueText = "Rock";
    }else if(userValue == 'P'){
        userValueText = "Paper";
    }
    else if(userValue == 'S'){
        userValueText = "Scissors";
    }
    
    if(computerValue == 'R'){
        computerValueText = "Rock";
    }else if(computerValue == 'P'){
        computerValueText = "Paper";
    }
    else if(computerValue == 'S'){
        computerValueText = "Scissors";
    }
    std::cout << "You chose " << userValueText << std::endl;
    std::cout << "Computer chose " << computerValueText << std::endl;
    
    if(isATie){
        std::cout << "This round is a tie" << std::endl;
    }else{
        std::cout << winner << " wins the round" << std::endl;
    }
}
