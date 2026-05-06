#include <iomanip>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include "Card_Pack.hpp"


using namespace std;

string Card_Type[8] = {"clubs", "spades", "diamonds", "hearts", "club", "spade", "diamond", "heart"};

string Cards[13] = {"ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king"};

string short_Cards[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

int FindCardNum(string GuessNum);

int FindSuitNum(string GuessSuit); 

string clean_input(string Guess); // converts to all lowercase

bool Check_Num(string Guess, int Actual); // checks if you got the right card

bool Check_Suit(string Guess, int Actual); // checks if you got the right suit

bool print(bool a, bool b); // prints your result

int closeness(int ActualNum, string GuessNum); // tells you how far away you are

bool Play(int difficulty_level); // driver code for the game, main is the wrapper for this function. 

int main(){

    bool PlayAgain = true;
    bool Win_Or_Lose = false;
    int difficulty_level = 4;
    string verdict = "Empty";

    cout << "Format for the game: Please pick a card from a deck (for example, ace of spades). Enter your suit (spades) and then you card (ace)." << endl;
    cout << "Inputs should be done one at a time." << endl;

    while (PlayAgain){

        if (verdict == "Y" || verdict == "y" || verdict == "Yes" || verdict == "yes"){
            cout << "Format for the game: Please pick a card from a deck (for example, ace of spades). Enter your suit (spades) and then you card (ace)." << endl;
            cout << "Inputs should be done one at a time, and your suit should be plural. (Not 2 of spade, but two of spades)." << endl;
        }

        Win_Or_Lose = Play(difficulty_level);

        if (difficulty_level > 2 && Win_Or_Lose == true){ //They win, and have not reached the end
            cout << endl << "You Win! Play again?" << endl; 
            cin >> verdict;
            if (verdict == "Y" || verdict == "y" || verdict == "Yes" || verdict == "yes"){
                PlayAgain = true;
                difficulty_level = difficulty_level - 1;
                cout << "Congratulations! You get to go up in difficulty!";

                if (difficulty_level == 3){
                    system("color 0A");
                } else if (difficulty_level == 2){
                    system("color 04");
                }
            }
            else {
                PlayAgain = false;
                system("color 0f");
            }
        }
        else if(Win_Or_Lose == false){ //The player loses
            cout << endl << "You Lose! Play again?" << endl;
            cin >> verdict;
            if (verdict == "Y" || verdict == "y" || verdict == "Yes" || verdict == "yes"){
                PlayAgain = true;
                difficulty_level = 4;
                system("color 0f");
            } else{
                PlayAgain = false;
                system("color 0f");
            }

        }
        else if (difficulty_level <= 2 && Win_Or_Lose == true){
            cout << endl << "You won! You are the best at this game! How does that make you feel about your life?";
            return 0;
        }

        
        system("cls"); //This is the only part that is not in the 240 curriculum. It is a simple system call to clear the screen. 
                       //It is located in the cstdlib header file. 
    }
    
    return 0;
}




bool Play(int difficulty_level){
    srand(time(0));
    string Initial_Guess_Num;
    string Initial_Guess_Suit;
    bool Flag;
    int which_direction; //if this is 0, then they could not find the actual result. 
    int random_card_num = (rand() % 13); //0 - 12, works for array indexing
    int random_card_suit = (rand() % 4); //0 - 4, works for array indexing



    cout << "Guess a card! Please give us a suit (clubs, spades, hearts, diamonds): " << endl;
    cin >> Initial_Guess_Suit;

    Initial_Guess_Suit = clean_input(Initial_Guess_Suit);

    cout << "Now give us the number or face card (ace - ten, jack, queen, king): " << endl;
    cin >> Initial_Guess_Num;

    Initial_Guess_Num = clean_input(Initial_Guess_Num);

    do {
        bool is_num = Check_Num(Initial_Guess_Num, random_card_num);
        bool is_suit = Check_Suit(Initial_Guess_Suit, random_card_suit);

        Flag = print(is_num, is_suit);
        
        which_direction = closeness(random_card_num, Initial_Guess_Num);
        
        if (Flag){
            cout << endl << "You won! Congrats!" << endl;
            cout << endl << endl << "The Winning Card Was: " << endl << endl;
            print_card(random_card_num, random_card_suit);
            return true;
        }
        else if (difficulty_level != 1) {
            if (which_direction < 0){
                cout << "You guessed too high!" << endl;
            }
            else if (which_direction > 0){
                cout << "You guessed too low!" << endl;
            }
            else if (which_direction == 0){
                cout << "Your card number was correct!" << endl;
            }
            cout << endl << "You currently have " << (difficulty_level - 1) << " guesses left" << endl;
            cout << "Last guess was: " << Initial_Guess_Num << " of " << Initial_Guess_Suit << endl << endl;
            print_card(FindCardNum(Initial_Guess_Num), FindSuitNum(Initial_Guess_Suit));
            cout << endl << endl;

            cout << "Guess your suit again! (clubs, spades, hearts, diamonds.): " << endl;
            cin >> Initial_Guess_Suit;
            Initial_Guess_Suit = clean_input(Initial_Guess_Suit);
            cout << "Guess your number/face again (ace - ten, jack, queen, king): " << endl;
            cin >> Initial_Guess_Num;
            Initial_Guess_Num = clean_input(Initial_Guess_Num);
        }
        else {
            if (Flag){
                cout << endl << "You won! Congrats!" << endl;
                cout << endl << endl << "The Winning Card Was: " << endl << endl;
                print_card(random_card_num, random_card_suit);
                return true;
            }

            if (which_direction < 0 ){
                cout << "You guessed too high!" << endl;
            } 
            else if (which_direction > 0){
                cout << "You guessed too low!" << endl;
            }
            else {
                cout << "Your card number was correct!" << endl;
            }
            cout << "Last guess was: " << Initial_Guess_Num << " of " << Initial_Guess_Suit << endl << endl;
            print_card(FindCardNum(Initial_Guess_Num), FindSuitNum(Initial_Guess_Suit));
            cout << endl << endl;
            cout << endl << "You ran out of Guesses!" << endl;
        }
        difficulty_level--;

    } while (difficulty_level > 0);
    
    cout << endl << "You Lost!" << endl;
    cout << endl << endl << "The Winning Card Was: " << endl << endl;
    print_card(random_card_num, random_card_suit);
    return false;
}





bool print(bool a, bool b){
    if (a && b){
        cout << "Congrats! You have guessed it!";
        return true;
    }
    if (b)
    {
        cout << "Your suit was correct!" << endl;
    }
    else{
        cout << "Your suit was incorrect!" << endl;
    }
    return false;
}

bool Check_Suit(string Guess, int Actual){
    if (Guess == Card_Type[Actual] || Guess == Card_Type[Actual + 4]){
        return true;
    }
    return false;
}

bool Check_Num(string Guess, int Actual){
    if (Guess == Cards[Actual]){
        return true;
    }
    else if (Guess == short_Cards[Actual]){
        return true;
    }
    return false;
}

string clean_input(string Guess){
    for (int i = 0; i < Guess.length(); i++){
        if ((Guess[i] >= 65) && Guess[i] <= 90){ //If uppercase
            Guess[i] = Guess[i] + 32; //Make it lowercase
        }
    }
    if (FindCardNum(Guess) == -9999 || FindSuitNum(Guess) == -9999){
        return "Not a Card";
    }
    return Guess;
}

int closeness(int ActualNum, string GuessNum){
    for(int i = 0; i < 13; i++){
        if(Cards[i] == GuessNum){
            return ActualNum - i;
        }
        if(short_Cards[i] == GuessNum){
            return ActualNum - i;
        }
    }
    return -9999;
}

int FindCardNum(string GuessNum){
    for(int i = 0; i < 13; i++){
        if(Cards[i] == GuessNum){
            return i;
        }
        if(short_Cards[i] == GuessNum){
            return i;
        }
    }
    return 0;
}

int FindSuitNum(string GuessSuit){
    for(int i = 0; i < 4; i++){
        if (Card_Type[i] == GuessSuit){
            return i;
        } if (Card_Type[i + 4] == GuessSuit){
            return i;
        }
    }
    return -9999;
}