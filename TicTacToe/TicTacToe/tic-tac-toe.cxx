#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif


using namespace std;


//This class is for the players
class User{
    private:
        char Character;
        string Name;

    public:
        //Default Constructor using default arguments
        User(char sym = 'X', string N = "Player One") : Character(sym), Name(N) {};

        char getSymbol() const;
        string getName() const;
        void changeName(string);
        void changeSymbol(char);
};

//Changes the names
void User::changeName(string newname) {
    Name = newname;
}

//Changes the symbols
void User::changeSymbol(char newChar) {
    Character = newChar;
}


//Grabs the symbols
char User::getSymbol() const{
    return Character;
}

//Method for the names
string User::getName() const{
    return Name;
}


//This class controls the board
class Board{
    private:

        //By using a vector we can have a grid be as large as we want. What difficulty arises from this?
        //Hint: check the win conditions in the CheckWin method, are there any that are hard to code using size?
        vector<vector<char>> grid;
        //We have to initialize the filled cells to 0, otherwise the game could just... keep going, because the check depends on the size of the graph.
        int filledCells = 0;
        int in_a_row;

    public:
        Board(int);

        void drawBoard() const {
            string top;
            for (int i = 0; i < 2 + (grid.size() * 4); i++){
                top += '-';
            }
            cout << top << endl;
            for (int i = 0; i < grid.size(); i++){
                cout << "| ";
                for (int j = 0; j < grid.size(); j++){
                    cout << grid[i][j] << " | ";
                }
                cout << endl << top << endl;
            }
        }

        //Checks for valid moves
        bool isValidMove(int row, int col) const {
            if (row >= grid.size() || col >= grid.size()){
                return false;
            }
            if (row < 0 || col < 0){
                return false;
            }
            //Why would we use the .at instead of brackets? 
            //Hint: look up error codes for .at
            if (grid.at(row).at(col) != ' '){
                return false;
            }
            return true;
        }

        void set_goal(int goal){
            in_a_row = goal;
        }


        //Makes the moves
        void makeMove(int row, int col, char symbol) {
            if (isValidMove(row, col)){
                grid[row][col] = symbol;
                filledCells++;
            }
        }
		
		
        bool checkWin(char symbol) const {

            vector<char> row, col, leftdiag, rightdiag;
            //rows and columns
            leftdiag.clear();
            rightdiag.clear();
            for (int i = 0; i < grid.size(); i++) {

                row.clear();
                col.clear();
                

                for (int j = 0; j < grid.size(); j++){
                    if (grid[i][j] == symbol){
                        row.push_back(grid[i][j]);

                        //This is a check to see if enough symbols are in a row to win
                        if (row.size() == in_a_row){
                            return true;
                        }
                    } else{
                        row.clear();
                    }
                    if (grid[j][i] == symbol){
                        col.push_back(grid[j][i]);

                        if (col.size() == in_a_row){
                            return true;
                        }
                    }

                }

                if (grid[i][i] == symbol){              //Goes from (0, 0) to (size-1, size-1)
                    leftdiag.push_back(grid[i][i]);

                    if (leftdiag.size() == in_a_row){
                        return true;
                    }
                } else{
                    leftdiag.clear();
                }


                if (grid[grid.size() - i - 1][i] == symbol){  //Goes from (size-1, 0) ot (0, size - 1)
                    rightdiag.push_back(grid[grid.size() - i - 1][i]);

                    if (rightdiag.size() == in_a_row){
                        return true;
                    }
                } else{
                    rightdiag.clear();
                }
                
                
                
            }
            
                
            
            

            return false;
        }

        bool isFull() const{
            return (filledCells >= (grid.size() * grid.size()));
        }

        int getFilledCellsCount() const {
            return filledCells;
        }

};




//Default constructor example for building outside a class
Board::Board(int size = 3){
    for (int i = 0; i < size; i++){
        vector<char> column (size, ' ');
        grid.push_back(column);
    }
    in_a_row = grid.size();
}





//this class controls the actual gameplay
class TicTacToe {
    private:
        User Players[2];
        int currentPlayerIndex;

    public:
        //Default constructor
        TicTacToe() : currentPlayerIndex(0) {
            Players[0] = User('X', "Player X");
            Players[1] = User('O', "Player O");
        }


        User& getCurrentPlayer() {
            return Players[currentPlayerIndex];
        }

        //Switches turns using modulo for a base-2 system, how would this work for more players?
        void switchTurn() {
            currentPlayerIndex = (currentPlayerIndex + 1) % 2;
        }

        //This method plays the game
        void Play(){
            //Setup for the board
            int row, col;
            int size = 4;

            string Player1, Player2;
            char Play1, Play2;
            cout << "Play" << endl;
            while (size % 2 == 0){
                cout << "What size board do you want? (Only enter one number, odd numbers only): " << endl;
                cin >> size;
            }
            Board board(size);

            int goal = size;
            char choice;


            cout << "Do you want to set a specific goal? Y/N ";
            cin >> choice;

            if (choice == 'Y' || choice == 'y'){
                cout << endl << "How many in a row do you want? ";
                cin >> goal;
                board.set_goal(goal);
            }
            

            

            //Actual player setup
            cout << endl << "Enter your names and chosen symbols." << endl;
            cout << "Player 1, your name? ";
            cin >> Player1;
            Players[0].changeName(Player1);
            cout << endl << "And your symbol? ";
            cin >> Play1;
            Players[0].changeSymbol(Play1);
            cout << endl << "Player 2, your name? ";
            cin >> Player2;
            Players[1].changeName(Player2);
            cout << endl << "And your symbol? ";
            cin >> Play2;
            Players[1].changeSymbol(Play2);


            while (!board.isFull()){
                
                system(CLEAR_COMMAND);
                board.drawBoard();
                User & currentPlayer = getCurrentPlayer();
                
                //This while loop runs forever, can you figure out why?
                //Hint: Why does it break?
                while (true){
                    char initial_row, initial_col;

                    //Why would you initally want characters?
                    //Hint: Users don't always do what you want
                    cout << currentPlayer.getName() << "(" << currentPlayer.getSymbol()
                         << "), enter row (1-" << size << "): ";
                    cin >> initial_row;
                    cout << "enter column (1-" << size << "): ";
                    cin >> initial_col;
                    //What does this do? 
                    //Hint: ASCII tables
                    row = initial_row - '0';
                    col = initial_col - '0';
                    row--, col--;
                    

                    if (board.isValidMove(row, col) || board.isFull()) {
                        break;
                    }
                    else {
                        cout << "Invalid move. Try again." << endl;
                    }
                }

                board.makeMove(row, col, currentPlayer.getSymbol());

                if (board.checkWin(currentPlayer.getSymbol())){
                    board.drawBoard();
                    cout << currentPlayer.getName() << " wins!" << endl;
                    return;
                } else if (board.isFull()){
                	board.drawBoard();
                	cout << "Nobody Wins :(" << endl;
                	return;
				}
                

                switchTurn();
            }

            //Screen if nobody wins
            board.drawBoard();
            cout << "Nobody dies... This time." << endl;
        }
};




//Driver code for the game

int main(){

    bool Replay = true;

    char Choice;

    TicTacToe game;

    //gameplay loop
    while (Replay){
        Replay = false;

        //Actual game running

        game.Play();

        //Play again screen
        cout << "Do you want to play again? Y/N ";
        cin >> Choice;
        //Why would you only have to test two?
        if (Choice == 'Y' || Choice == 'y'){
            Replay = true;
        }

    }
    
    cout << "Goodbye, for now...";
    return 0;
}
