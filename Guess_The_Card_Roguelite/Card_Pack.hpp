#ifndef CARDPACK_H
#define CARDPACK_H

#include <string>
#include <iostream>


std::string Line_1_All = " _____ ";
                           //  _____      _____      _____      _____      _____      _____      _____      _____      _____      _____      _____      _____
std::string Line_2_Spades [13] = {"|A .  |", "|2    |", "|3    |", "|4    |", "|5    |", "|6    |", "|7    |", "|8    |", "|9    |", "|10 ^ |", "|J  WW|", "|Q  WW|", "|K  WW|"};
std::string Line_3_Spades [13] ={"| /.\\ |", "|  ^  |", "| ^ ^ |", "| ^ ^ |", "| ^ ^ |", "| ^ ^ |", "| ^ ^ |", "|^ ^ ^|", "|^ ^ ^|", "|^ ^ ^|", "| ^ {)|", "| ^ {(|", "| ^ {)|"};
std::string Line_4_Spades [13] ={"|/_._\\|", "|     |", "|     |", "|     |", "|  ^  |", "| ^ ^ |", "|^ ^ ^|", "| ^ ^ |", "|^ ^ ^|", "|^ ^ ^|", "|(.)\% |", "|(.)\%\%|", "|(.)\%\%|"};
std::string Line_5_Spades [13] = {"|  |  |", "|  ^  |", "|  ^  |", "| ^ ^ |", "| ^ ^ |", "| ^ ^ |", "| ^ ^ |", "|^ ^ ^|", "|^ ^ ^|", "|^ ^ ^|", "| | \% |", "| |\%\%\%|", "| |\%\%\%|"};
std::string Line_6_Spades [13] = {"|____V|", "|____Z|", "|____E|", "|____h|", "|____S|", "|____9|", "|____L|", "|____8|", "|____6|", "|___0I|", "|__\%\%[|", "|_\%\%\%O|", "|_\%\%\%>|"};



std::string Line_2_Clubs [13] = {"|A _  |", "|2    |", "|3    |", "|4    |", "|5    |", "|6    |", "|7    |", "|8    |", "|9    |", "|10 & |", "|J  WW|", "|Q  WW|", "|K  WW|"};
std::string Line_3_Clubs [13] = {"| (.) |", "|  &  |", "| & & |", "| & & |", "| & & |", "| & & |", "| & & |", "|& & &|", "|& & &|", "|& & &|", "| o {)|", "| o {(|", "| o {)|"};
std::string Line_4_Clubs [13] = {"|(_._)|", "|     |", "|     |", "|     |", "|  &  |", "| & & |", "|& & &|", "| & & |", "|& & &|", "|& & &|", "|o o\% |", "|o o\%\%|", "|o o\%\%|"};
std::string Line_5_Clubs [13] = {"|  |  |", "|  &  |", "|  &  |", "| & & |", "| & & |", "| & & |", "| & & |", "|& & &|", "|& & &|", "|& & &|", "| | \% |", "| |\%\%\%|", "| |\%\%\%|"};
std::string Line_6_Clubs [13] = {"|____V|", "|____Z|", "|____E|", "|____h|", "|____S|", "|____9|", "|____L|", "|____8|", "|____6|", "|___0I|", "|__\%\%[|", "|_\%\%\%O|", "|_\%\%\%>|"};

std::string Line_2_Hearts [13] = {"|A_ _ |", "|2    |", "|3    |", "|4    |", "|5    |", "|6    |", "|7    |", "|8    |", "|9    |", "|10 v |", "|J  WW|", "|Q  WW|", "|K  WW|"};
std::string Line_3_Hearts [13] = {"|( v )|", "|  v  |", "| v v |", "| v v |", "| v v |", "| v v |", "| v v |", "|v v v|", "|v v v|", "|v v v|", "|   {)|", "|   {(|", "|   {)|"};
std::string Line_4_Hearts [13] ={"| \\ / |", "|     |", "|     |", "|     |", "|  v  |", "| v v |", "|v v v|", "| v v |", "|v v v|", "|v v v|", "|(v)\% |", "|(v)\%\%|", "|(v)\%\%|"};
std::string Line_5_Hearts [13] = {"|  .  |", "|  v  |", "|  v  |", "| v v |", "| v v |", "| v v |", "| v v |", "|v v v|", "|v v v|", "|v v v|", "| v \% |", "| v\%\%\%|", "| v\%\%\%|"};
std::string Line_6_Hearts [13] = {"|____V|", "|____Z|", "|____E|", "|____h|", "|____S|", "|____9|", "|____L|", "|____8|", "|____6|", "|___0I|", "|__\%\%[|", "|_\%\%\%O|", "|_\%\%\%>|"};

std::string Line_2_Diamonds [13] = {"|A ^  |", "|2    |", "|3    |", "|4    |", "|5    |", "|6    |", "|7    |", "|8    |", "|9    |", "|10 o |", "|J  WW|", "|Q  WW|", "|K  WW|"};
std::string Line_3_Diamonds [13] ={"| / \\ |", "|  o  |", "| o o |", "| o o |", "| o o |", "| o o |", "| o o |", "|o o o|", "|o o o|", "|o o o|", "| /\\{)|", "| /\\{(|", "| /\\{)|"};
std::string Line_4_Diamonds [13] ={"| \\ / |", "|     |", "|     |", "|     |", "|  o  |", "| o o |", "|o o o|", "| o o |", "|o o o|", "|o o o|", "| \\/\% |", "| \\/\%\%|", "| \\/\%\%|"};
std::string Line_5_Diamonds [13] = {"|  .  |", "|  o  |", "|  o  |", "| o o |", "| o o |", "| o o |", "| o o |", "|o o o|", "|o o o|", "|o o o|", "| | \% |", "| |\%\%\%|", "| |\%\%\%|"};
std::string Line_6_Diamonds [13] = {"|____V|", "|____Z|", "|____E|", "|____h|", "|____S|", "|____9|", "|____L|", "|____8|", "|____6|", "|___0I|", "|__\%\%[|", "|_\%\%\%O|", "|_\%\%\%>|"};



std::string Joker [5] = {"|Joker|", "|==%, |", "| \\/>\\|", "| _>^^|", "|/_\\/_|"};

std::string CardBack [5] = {"|\\ ~ /|", "|}}:{{|", "|}}:{{|", "|}}:{{|", "|/_~_\\|"};

void print_card(int CardNum, int SuitNum){
    std::cout << Line_1_All << std::endl;
    if (SuitNum == 4){ //This is the Joker
        for (int i = 0; i < 5; i++){
            std::cout << Joker[i] << std::endl;
        }
    }
    else if (SuitNum == 0){ //This is the Clubs
        std::cout << Line_2_Clubs[CardNum] << std::endl << Line_3_Clubs[CardNum] << std::endl << Line_4_Clubs[CardNum] << std::endl << Line_5_Clubs[CardNum] << std::endl << Line_6_Clubs[CardNum] << std::endl; 
    }
    else if (SuitNum == 1){ //Spades
        std::cout << Line_2_Spades[CardNum] << std::endl << Line_3_Spades[CardNum] << std::endl << Line_4_Spades[CardNum] << std::endl << Line_5_Spades[CardNum] << std::endl << Line_6_Spades[CardNum] << std::endl; 
    }
    else if (SuitNum == 2){ // Diamonds
        std::cout << Line_2_Diamonds[CardNum] << std::endl << Line_3_Diamonds[CardNum] << std::endl << Line_4_Diamonds[CardNum] << std::endl << Line_5_Diamonds[CardNum] << std::endl << Line_6_Diamonds[CardNum] << std::endl; 
    }
    else if (SuitNum == 3){ // Hearts
        std::cout << Line_2_Hearts[CardNum] << std::endl << Line_3_Hearts[CardNum] << std::endl << Line_4_Hearts[CardNum] << std::endl << Line_5_Hearts[CardNum] << std::endl << Line_6_Hearts[CardNum] << std::endl; 
    }
}




#endif