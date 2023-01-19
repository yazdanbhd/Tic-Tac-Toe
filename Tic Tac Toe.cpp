#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void startGame();
void drawBoard();
void markBoard(char );
int checkWin();

char board[3][3] = { '1','2','3',
                     '4','5','6',
                     '7','8','9' };
int player ,choice;
string Players[2];


int main()
{
    startGame();
    player = 1;
    char mark;
    int winSituation;
    do
    {
        drawBoard();
        player = (player % 2) ? 1 : 2;
        if (player == 1)
            cout << Players[0] << ", enter a number: ";
        else
            cout << Players[1] << ", enter a number: ";
        cin >> choice;
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 0)
        {
            if (player == 1)
            {
                system("cls");
                cout << Players[0] << " has quit the game so "<<Players[1]<<" is winner!"<< endl;
                break;
            }
            else
            {
                system("cls");
                cout << Players[1] << " has quit the game so "<<Players[0]<<" is winner!"<< endl;
                break;
            }
        }
        markBoard(mark);
        winSituation = checkWin();
        if (winSituation == 1)
        {
            system("cls");
            if (player == 1)
            {
                cout << "----------- " << Players[0] << " wins! ----------";
                getch();
            }

            else
            {
                cout << "----------- " << Players[1] << " wins! ----------";
                getch();
            }
            break;
        }
        else if (winSituation == 0)
        {
            system("cls");
            cout << "---------- It's a draw! ----------";
            getch();
            break;
        }
        player++;
    }
    while (winSituation == -1);

    return 0;
}
void startGame()
{

    system("cls");
    cout << endl <<"Enter the name of player 1: ";
    cin >> Players[0];
    cout << "Enter the name of player 2: ";
    cin >> Players[1];
    if (Players[0] == Players[1])
    {
        Players[0] = Players[0] + " (1)";
        Players[1] = Players[1] + " (2)";
    }
    system("cls");
    cout << Players[0] << " is X" << endl;
    cout << Players[1] << " is O" << endl;
    cout << "Press any key to start the game. ";
    getch();
    system("cls");
}
void markBoard(char mark)
{
    if (choice == 1 && board[0][0] == '1')
        board[0][0] = mark;
    else if (choice == 2 && board[0][1] == '2')
        board[0][1] = mark;
    else if (choice == 3 && board[0][2] == '3')
        board[0][2] = mark;
    else if (choice == 4 && board[1][0] == '4')
        board[1][0] = mark;
    else if (choice == 5 && board[1][1] == '5')
        board[1][1] = mark;
    else if (choice == 6 && board[1][2] == '6')
        board[1][2] = mark;
    else if (choice == 7 && board[2][0] == '7')
        board[2][0] = mark;
    else if (choice == 8 && board[2][1] == '8')
        board[2][1] = mark;
    else if (choice == 9 && board[2][2] == '9')
        board[2][2] = mark;
    else
    {
        cout << "Invalid move ";
        player--;
        getch();
    }
    system("cls");
}
int checkWin()
{
    //check if player 1 or 2 has won
    char marker = (player == 1) ? 'X' : 'O';
    if (board[0][0] == marker && board[0][1] == marker && board[0][2] == marker)
        return 1;
    if (board[1][0] == marker && board[1][1] == marker && board[1][2] == marker)
        return 1;
    if (board[2][0] == marker && board[2][1] == marker && board[2][2] == marker)
        return 1;
    if (board[0][0] == marker && board[1][0] == marker && board[2][0] == marker)
        return 1;
    if (board[0][1] == marker && board[1][1] == marker && board[2][1] == marker)
        return 1;
    if (board[0][2] == marker && board[1][2] == marker && board[2][2] == marker)
        return 1;
    if (board[0][0] == marker && board[1][1] == marker && board[2][2] == marker)
        return 1;
    if (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker)
        return 1;
    // Game has no winner
    else if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
             board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
             board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
        return 0;
    // Game is still going on
    else
        return -1;
}
void drawBoard()
{
    cout << "------ Tic Tac Toe Game ------\n\n" << endl;
    cout <<"-> You can quit the game with enter number 0 <-. \n\n\n"<<endl;
    cout << Players[0] << "  vs  " << Players[1] <<"\n\n"<<endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl;
}