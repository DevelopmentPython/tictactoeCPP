#include <iostream>
#include <vector>

using namespace std; 

bool isO = false; 
bool lastTurnStatic = true; 

void print(vector<vector<char>> board) {
    int lengthRow = board.size(); 
    int lengthCol = board[0].size(); 

    for (int row = 0; row < lengthRow; row++) {
	    for (int col = 0; col < lengthCol; col++) { 
	        // Check if the spot on the board was 'X'/'O'/blank (spot number) then print the board either blank, X, or O spots
	        if (board[row][col] == 'O') {
	            cout << "|O|"; 
	        } else if (board[row][col] == 'X') {
	            cout << "|X|"; 
	        } else {
	            cout << "| |"; 
	        }
	    }
		
		cout << endl; 
	}
}

vector<vector<char>> playerTurn(vector<vector<char>> board) { 
    char player; 
    char userInput; 

    if (isO == true) { 
        player = 'O';
    } else {
        player = 'X'; 
    } 

    cout << "Player " << player << ", which spot would you like to go with? "; 
    cin >> userInput; 

    int counter = 0; 
    int lengthRow = board.size(); 
    int lengthCol = board[0].size();  

    if (userInput == '1' || userInput == '2' || userInput == '3' || 
        userInput == '4' || userInput == '5' || userInput == '6' || 
        userInput == '7' || userInput == '8' || userInput == '9') { 
            for (int row = 0; row < lengthRow; row++) {
		        for (int col = 0; col < lengthCol; col++) {
                    counter++; 

                    int numInput = userInput - '0'; 

                    if (counter == numInput) { 
                        if (board[row][col] == 'O' || board[row][col] == 'X') { 
		                    cout << "The spot is already taken." << endl; 
		                    lastTurnStatic = false; 
		                    break;
		                }
		                
                        board[row][col] = player; 
                        lastTurnStatic = true; 
		                break; 
                    }
                }
            }
    } else { 
        cout << "The input is unknown!" << endl; 
        lastTurnStatic = false; 
    } 

    return board; 
}

bool checkWin(vector<vector<char>> board) { 
    int counter = 0; 
    int lengthRow = board.size(); 
    int lengthCol = board[0].size();  

    for (int row = 0; row < lengthRow; row++) {
		for (int col = 0; col < lengthCol; col++) { 
            if (board[row][col] == 'O' || board[row][col] == 'X') { 
                counter++; 

                if (counter == 9) { 
		            print(board); 
		            cout << "All spots taken, but no win. Tie!" << endl; 
		            return true; 
		        }
            } else { 
                break; 
            }
        }
    }

    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') {
	    cout << "Player O won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') {
	    cout << "Player O won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') { 
	    cout << "Player O won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') {
	    cout << "Player O won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') { 
	    cout << "Player O won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') {
	    cout << "Player O won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
	    cout << "Player O won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O') {
	    cout << "Player O won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
	    cout << "Player X won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') {
	    cout << "Player X won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') { 
	    cout << "Player X won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
	    cout << "Player X won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') { 
	    cout << "Player X won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
	    cout << "Player X won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
	    cout << "Player X won!" << endl; 
	    print(board);
	    return true; 
	} 
	else if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X') {
	    cout << "Player X won!" << endl; 
	    print(board);
	    return true; 
	} 
    
	return false;
}

int main() {
	vector<char> r1 = {'1', '2', '3'}; 
	vector<char> r2 = {'4', '5', '6'}; 
	vector<char> r3 = {'7', '8', '9'}; 
    vector<vector<char>> board = {r1, r2, r3}; 

    do {
        if (lastTurnStatic == true) {
		    if (isO == false) { 
		        isO = true; 
		    } else { 
		        isO = false; 
		    } 
		} 

        print(board); 
        board = playerTurn(board); 
    } while(!checkWin(board)); 
    
    return 0;
}