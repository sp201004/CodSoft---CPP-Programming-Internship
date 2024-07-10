// CodSoft Internship
// Domain Name - C++ Programming
// Task - 3 (Tic-Tac-Toe)
// Intern Name - Surya Pratap Singh


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to draw the Tic-Tac-Toe board with the specified design
void drawBoard(char board[3][3])
{
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << "       |       |       \n";
        cout << "  " << board[i][0] << "    |   " << board[i][1] << "   |   " << board[i][2] << "   \n";
        if (i < 2)
            cout << "_______|_______|_______\n";
        else
            cout << "       |       |       \n";
    }
}

// Function to check for a win
bool checkWin(char board[3][3], char player)
{
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to make a move for the computer
void computerMove(char board[3][3])
{
    // Check if computer can win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][2] == ' ') {
            board[i][2] = 'O';
            return;
        }
        if (board[i][1] == board[i][2] && board[i][0] == ' ') {
            board[i][0] = 'O';
            return;
        }
        if (board[i][0] == board[i][2] && board[i][1] == ' ') {
            board[i][1] = 'O';
            return;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[2][i] == ' ') {
            board[2][i] = 'O';
            return;
        }
        if (board[1][i] == board[2][i] && board[0][i] == ' ') {
            board[0][i] = 'O';
            return;
        }
        if (board[0][i] == board[2][i] && board[1][i] == ' ') {
            board[1][i] = 'O';
            return;
        }
    }

    // Random move if no immediate win or block is possible
    int move;
    while (true) {
        move = rand() % 9;
        if (board[move / 3][move % 3] == ' ') {
            board[move / 3][move % 3] = 'O';
            break;
        }
    }
}

// Function to display game instructions
void gameInstructions()
{
    cout << "------------------ GAME INSTRUCTIONS -----------------" << endl;
    cout << endl << "Game Board --->\n" << endl << endl;
    cout << "       |       |       " << endl;
    cout << "   1   |   2   |   3   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   4   |   5   |   6   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   7   |   8   |   9   " << endl;
    cout << "       |       |       " << endl;
    cout << "\nGame Instructions --->" << endl << endl;
    cout << "1. To place X or O on the board, enter the number corresponding to the board position." << endl;
    cout << "   The numbers correspond to the positions as shown in the demo board above." << endl;
    cout << "2. The game is played in two modes:" << endl;
    cout << "   - **Single-Player:** Play against the Computer." << endl;
    cout << "     Default names: **Player vs Computer**" << endl;
    cout << "   - **Multi-Player:** Play against another Player." << endl;
    cout << "     Default names: **Player 1 vs Player 2**" << endl;
    cout << "3. You can choose to use default names or enter custom names for the players." << endl;
    cout << "4. After choosing your game mode, you will be prompted to choose who goes first." << endl;
    cout << "   - Enter **1** to go first or **2** to let the other player or computer go first." << endl;
    cout << "5. The game ends when a player wins or the board is full, resulting in a draw." << endl;
    cout << "   - To win, you need to align three of your symbols (X or O) in a row, column, or diagonal." << endl;
    cout << "   - If the board fills up and there is no winner, the game will end in a draw." << endl;
    cout << "6. After the game ends, you will have the option to play again or exit the game." << endl;
    cout << endl;
}

// Function to set default names
void setDefaultNames(string &player1Name, string &player2Name, bool isSinglePlayer)
{
    if (isSinglePlayer) {
        player1Name = "Player";
        player2Name = "Computer";
    } else {
        player1Name = "Player 1";
        player2Name = "Player 2";
    }
}

// Function to display end game messages
void displayEndGameMessage(int result, string player1Name, string player2Name)
{
    switch (result) {
        case 1: // Player 1 wins
            cout << "\nCongratulations! 🎉🥂🍾✨ ," << player1Name << "! 🏆 You Win! 🥇🏅🎖️" << endl;
            cout <<  player2Name << " loses 😔😞😕. Better luck next time! 🤞😣\n" << endl;
            break;
        case 2: // Player 2 wins
            cout << "\nCongratulations! 🎉🥂🍾✨ , " << player2Name << "! 🏆 You Win! 🥇🏅🎖️" << endl;
            cout << player1Name << " loses 😔😞😕. Better luck next time! 🤞😣\n" << endl;
            break;
        case 0: // Draw
            cout << "\nIt's a draw!  🤝😮‍💨\nNo winners this time 🏳️\n" << endl;
            break;
    }
}

int main()
{
    srand(time(0)); // Initialize random seed
    int choice;

    while (true) {
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "------------------------ WELCOME TO TIC-TAC-TOE -----------------------------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "\nSelect any choice --->" << endl << endl;
        cout << "1. Game Instructions >>>" << endl;
        cout << "2. Single-Player >>>" << endl;
        cout << "3. Multi-Player >>>" << endl;
        cout << "4. Exit >>>" << endl;
        cout << endl << "\nEnter your choice : ";
        cin >> choice;
        cout << "\n";

        // Check for valid input for the main menu
        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear(); // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\n🚫 Invalid choice! Please enter between 1 and 4.\n" << endl;
            continue;
        }

        if (choice == 4) {
            cout << "\nExiting...\n" << endl;
            cout << "\nThank you for playing the game!\n" << endl << endl;
            break;
        } else if (choice == 1) {
            gameInstructions();
            continue;
        }

        // Initialize the board and players
        char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
        char player = 'X';
        int position;
        int turn;

        string player1Name, player2Name;

        cout << "\nWelcome to Tic-Tac-Toe!\n" << endl;

        // Set default names
        setDefaultNames(player1Name, player2Name, choice == 2);

        if (choice == 2) {
            cout << "1. Default Names (Player vs Computer)\n2. Enter Custom Names\n" << endl;
            cout << "\nEnter your choice for player names: ";
            int nameChoice;
            cin >> nameChoice;
            cin.ignore();  // To ignore any leftover characters in the input buffer

            // Check for valid input for name choices
            if (cin.fail() || (nameChoice != 1 && nameChoice != 2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n🚫Invalid choice! Please enter 1 or 2.\n" << endl;
                continue;
            }

            if (nameChoice == 2) {
                cout << "\nEnter your name: ";
                getline(cin, player1Name);
                player2Name = "Computer";
            }

            cout << "\n" << player1Name << " vs " << player2Name << "!\n" << endl;
            cout << "Enter 1 to go first or 2 to let the computer go first: ";
            int playOrder;
            cin >> playOrder;
            cin.ignore();  // To ignore any leftover characters in the input buffer

            // Check for valid input for play order
            if (cin.fail() || (playOrder != 1 && playOrder != 2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n🚫Invalid choice! Please enter 1 or 2.\n" << endl;
                continue;
            }

            // Game loop for single-player mode
            for (turn = 0; turn < 9; turn++) {
                // Draw the board
                drawBoard(board);

                if ((turn + playOrder) % 2 == 0) {
                    // Computer's move
                    computerMove(board);
                    cout << "\nComputer has made its move.\n" << endl;
                } else {
                    // User's move
                    while (true) {
                        cout << "\n" << player1Name << ", enter position (1-9): ";
                        cin >> position;

                        // Check for valid input for the position
                        if (cin.fail() || position < 1 || position > 9 || board[(position-1)/3][(position-1)%3] != ' ') {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\n🚫 Invalid move! Choose 1-9 for empty positions.\n" << endl;
                        } else {
                            break; // Valid input, exit the loop.
                        }
                    }

                    // Make the move
                    board[(position-1)/3][(position-1)%3] = 'X';
                }

                // Check for a win after making a move
                if (checkWin(board, 'X')) {
                    drawBoard(board);
                    displayEndGameMessage(1, player1Name, player2Name); // Player 1 wins
                    break; // Exit the loop after a win.
                } else if (checkWin(board, 'O')) {
                    drawBoard(board);
                    displayEndGameMessage(2, player1Name, player2Name); // Computer wins
                    break; // Exit the loop after a win.
                }
            }

            // Check for a draw
            if (turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')) {
                drawBoard(board);
                displayEndGameMessage(0, player1Name, player2Name); // Draw
            }
        } else if (choice == 3) {
            cout << "1. Default Names (Player 1 vs Player 2)\n2. Enter Custom Names\n" << endl;
            cout << "\nEnter your choice for player names: ";
            int nameChoice;
            cin >> nameChoice;
            cin.ignore();  // To ignore any leftover characters in the input buffer

            // Check for valid input for name choices
            if (cin.fail() || (nameChoice != 1 && nameChoice != 2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n🚫 Invalid choice! Please enter 1 or 2.\n" << endl;
                continue;
            }

            if (nameChoice == 2) {
                cout << "\nEnter the name for Player 1: ";
                getline(cin, player1Name);
                cout << "\nEnter the name for Player 2: ";
                getline(cin, player2Name);
            } else {
                setDefaultNames(player1Name, player2Name, false);
            }

            cout << "\n" << player1Name << " vs " << player2Name << "!\n" << endl;

            // Game loop for multi-player mode
            for (turn = 0; turn < 9; turn++) {
                // Draw the board
                drawBoard(board);

                // Prompt for valid input
                while (true) {
                    cout << "\n" << (player == 'X' ? player1Name : player2Name) << ", enter position (1-9): ";
                    cin >> position;

                    // Check for valid input for the position
                    if (cin.fail() || position < 1 || position > 9 || board[(position-1)/3][(position-1)%3] != ' ') {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n🚫 Invalid move! Choose 1-9 for empty positions.\n" << endl;
                    } else {
                        break; // Valid input, exit the loop.
                    }
                }

                // Make the move
                board[(position-1)/3][(position-1)%3] = player;

                // Check for a win after making a move
                if (checkWin(board, 'X')) {
                    drawBoard(board);
                    displayEndGameMessage(1, player1Name, player2Name); // Player 1 wins
                    break; // Exit the loop after a win.
                } else if (checkWin(board, 'O')) {
                    drawBoard(board);
                    displayEndGameMessage(2, player1Name, player2Name); // Player 2 wins
                    break; // Exit the loop after a win.
                }

                // Switch to the other player
                player = (player == 'X') ? 'O' : 'X';
            }

            // Check for a draw
            if (turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')) {
                drawBoard(board);
                displayEndGameMessage(0, player1Name, player2Name); // Draw
            }
        }

        // Ask if the player wants to play again
        cout << "\nDo you want to play again? (y/n): ";
        char playAgain;
        cin >> playAgain;
        cin.ignore();  // To ignore any leftover characters in the input buffer

        // Check for valid input for replay choice
        if (cin.fail() || (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n🚫 Invalid choice! Please enter 'y' or 'n'.\n" << endl;
            continue;
        }

        if (playAgain == 'N' || playAgain == 'n') {
            cout << "\nThank you for playing the game!\n" << endl;
            break;
        }
    }

    return 0;
}