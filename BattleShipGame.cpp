#include <bits/stdc++.h>
using namespace std;
bool inputCheck = true;
int runornot = 1;
char orien, y;
int x, cord, scoreOfPlayer1 = 0, scoreOfPlayer2 = 0;
char player1board[10][10], player2board[10][10];
char player1opp[10][10], player2opp[10][10];

// WELCOME message
void welcome()
{
    cout << "**************************************************************" << endl;
    cout << "**************************************************************" << endl;
    cout << "**************************************************************" << endl;
    cout << "******************* WELCOME TO BATTLESHIP!!*******************" << endl;
    cout << "**************************************************************" << endl;
    cout << "**************************************************************" << endl;
    cout << "**************************************************************" << endl
         << endl;
    return;
}

// Print error if any
void printError()
{
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    cout << "!!!!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!!!!!!" << endl;
    cout << "!!!!!!!!!!!!!!RESTART THE GAME!!!!!!!!!!!!!!!" << endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    return;
}

// check for fullfillment of rules for player1
bool check(char player1board[10][10], int x, int i)
{
    if (player1board[x][i] != '.')
    {
        return false;
    }
    return true;
}

// check for fullfillment of rules for player2
bool check2(char player2board[10][10], int x, int i)
{
    if (player2board[x][i] != '.')
    {
        return false;
    }
    return true;
}

// input Aircraft ship of Player 1
void InputCoordinatesforAircraft1(char player1board[10][10])
{
    // input ships for player1
    // Aircraft Carrier;
    cout << "Place your Aircraft Carrier." << endl;
    cout << "Write 'H' for horizontal and 'V' for Vertical: ";
    cin >> orien;
    cout << "initial y and x coordinates of ship: ";
    cin >> y >> x;
    cout << "***************************************" << endl;
    if (orien == 'H')
    {
        cord = y - 65;
        if (x > 9 || x < 0 || cord > 5 || cord < 0)
        {
            printError();
            runornot = 0;
            return;
        }
        else
        {
            x--;
            for (int i = cord; i < cord + 5; i++)
            {
                player1board[x][i] = 'A';
            }
        }
    }
    else if (orien == 'V')
    {
        cord = y - 65;
        if (cord > 9 || cord < 0 || x > 5 || x < 0)
        {
            printError();
            runornot = 0;
            return;
        }
        else
        {
            x--;
            for (int i = x; i < x + 5; x++)
            {
                player1board[i][cord] = 'A';
            }
        }
    }
    else
    {
        printError();
        runornot = 0;
        return;
    }
    return;
}

// input BattleShip of Player 1
bool InputCoordinatesforBattleShip1(char player1board[10][10])
{
    // Input Battleship for player 1
    //  Battleship Carrier
    cout << "Place your Battleship Carrier." << endl;
    cout << "Write 'H' for horizontal and 'V' for Vertical: ";
    cin >> orien;
    cout << "initial y and x coordinates of ship: ";
    cin >> y >> x;
    cout << "***************************************" << endl;
    if (orien == 'H')
    {
        cord = y - 65;
        if (x > 9 || x < 0 || cord > 6 || cord < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = cord; i < cord + 4; i++)
            {
                if (!check(player1board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player1board[x][i] = 'B';
            }
        }
    }
    else if (orien == 'V')
    {
        cord = y - 65;
        if (cord > 9 || cord < 0 || x > 6 || x < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = x; i < x + 4; i++)
            {
                if (!check(player1board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player1board[x][i] = 'B';
            }
        }
    }
    else
    {
        printError();
        runornot = 0;
        return false;
    }
    return true;
}

// input Destroyer of Player 1
bool InputCoordinatesforDestroyer1(char player1board[10][10])
{
    // Input Destroyer for player 1
    //  Destroyer Carrier
    cout << "Place your Destroyer Carrier." << endl;
    cout << "Write 'H' for horizontal and 'V' for Vertical: ";
    cin >> orien;
    cout << "initial y and x coordinates of ship: ";
    cin >> y >> x;
    cout << "***************************************" << endl;
    if (orien == 'H')
    {
        cord = y - 65;
        if (x > 9 || x < 0 || cord > 7 || cord < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = cord; i < cord + 3; i++)
            {
                if (!check(player1board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player1board[x][i] = 'D';
            }
        }
    }
    else if (orien == 'V')
    {
        cord = y - 65;
        if (cord > 9 || cord < 0 || x > 7 || x < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = x; i < x + 3; i++)
            {
                if (!check(player1board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player1board[x][i] = 'D';
            }
        }
    }
    else
    {
        printError();
        runornot = 0;
        return false;
    }
    return true;
}

// input Corvette of Player 1
bool InputCoordinatesforCorvette1(char player1board[10][10])
{
    // Input Corvette for player 1
    //  Corvette Carrier
    cout << "Place your Corvette Ship." << endl;
    cout << "Write 'H' for horizontal and 'V' for Vertical: ";
    cin >> orien;
    cout << "initial y and x coordinates of ship: ";
    cin >> y >> x;
    cout << "***************************************" << endl;
    if (orien == 'H')
    {
        cord = y - 65;
        if (x > 9 || x < 0 || cord > 8 || cord < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = cord; i < cord + 2; i++)
            {
                if (!check(player1board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player1board[x][i] = 'C';
            }
        }
    }
    else if (orien == 'V')
    {
        cord = y - 65;
        if (cord > 9 || cord < 0 || x > 8 || x < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = x; i < x + 2; i++)
            {
                if (!check(player1board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player1board[x][i] = 'C';
            }
        }
    }
    else
    {
        printError();
        runornot = 0;
        return false;
    }
    return true;
}

// input Frigate of Player 1
bool InputCoordinatesforFrigate1(char player1board[10][10])
{
    // Input Frigate for player 1
    //  Frigate Carrier
    cout << "Place your Frigate Ship." << endl;
    cout << "Write 'H' for horizontal and 'V' for Vertical: ";
    cin >> orien;
    cout << "initial y and x coordinates of ship: ";
    cin >> y >> x;
    cout << "***************************************" << endl;
    if (orien == 'H')
    {
        cord = y - 65;
        if (x > 9 || x < 0 || cord > 9 || cord < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = cord; i < cord + 1; i++)
            {
                if (!check(player1board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player1board[x][i] = 'F';
            }
        }
    }
    else if (orien == 'V')
    {
        cord = y - 65;
        if (cord > 9 || cord < 0 || x > 1 || x < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = x; i < x + 1; i++)
            {
                if (!check(player1board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player1board[x][i] = 'F';
            }
        }
    }
    else
    {
        printError();
        runornot = 0;
        return false;
    }
    return true;
}

// input Aircraft ship of Player 2
void InputCoordinatesforAircraft2(char player2board[10][10])
{
    // input ships for player2
    // Aircraft Carrier;
    cout << "Place your Aircraft Carrier." << endl;
    cout << "Write 'H' for horizontal and 'V' for Vertical: ";
    cin >> orien;
    cout << "initial y and x coordinates of ship: ";
    cin >> y >> x;
    cout << "***************************************" << endl;
    if (orien == 'H')
    {
        cord = y - 65;
        if (x > 9 || x < 0 || cord > 5 || cord < 0)
        {
            printError();
            runornot = 0;
            return;
        }
        else
        {
            x--;
            for (int i = cord; i < cord + 5; i++)
            {
                player2board[x][i] = 'A';
            }
        }
    }
    else if (orien == 'V')
    {
        cord = y - 65;
        if (cord > 9 || cord < 0 || x > 5 || x < 0)
        {
            printError();
            runornot = 0;
            return;
        }
        else
        {
            x--;
            for (int i = x; i < x + 5; x++)
            {
                player2board[i][cord] = 'A';
            }
        }
    }
    else
    {
        printError();
        runornot = 0;
        return;
    }
    return;
}

// input BattleShip of Player 2
bool InputCoordinatesforBattleShip2(char player2board[10][10])
{
    // Input Battleship for player 2
    //  Battleship Carrier
    cout << "Place your Battleship Carrier." << endl;
    cout << "Write 'H' for horizontal and 'V' for Vertical: ";
    cin >> orien;
    cout << "initial y and x coordinates of ship: ";
    cin >> y >> x;
    cout << "***************************************" << endl;
    if (orien == 'H')
    {
        cord = y - 65;
        if (x > 9 || x < 0 || cord > 6 || cord < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = cord; i < cord + 4; i++)
            {
                if (!check2(player2board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player2board[x][i] = 'B';
            }
        }
    }
    else if (orien == 'V')
    {
        cord = y - 65;
        if (cord > 9 || cord < 0 || x > 6 || x < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = x; i < x + 4; i++)
            {
                if (!check2(player2board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player2board[x][i] = 'B';
            }
        }
    }
    else
    {
        printError();
        runornot = 0;
        return false;
    }
    return true;
}

// input Destroyer of Player 2
bool InputCoordinatesforDestroyer2(char player2board[10][10])
{
    // Input Destroyer for player 2
    //  Destroyer Carrier
    cout << "Place your Destroyer Carrier." << endl;
    cout << "Write 'H' for horizontal and 'V' for Vertical: ";
    cin >> orien;
    cout << "initial y and x coordinates of ship: ";
    cin >> y >> x;
    cout << "***************************************" << endl;
    if (orien == 'H')
    {
        cord = y - 65;
        if (x > 9 || x < 0 || cord > 7 || cord < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = cord; i < cord + 3; i++)
            {
                if (!check2(player2board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player2board[x][i] = 'D';
            }
        }
    }
    else if (orien == 'V')
    {
        cord = y - 65;
        if (cord > 9 || cord < 0 || x > 7 || x < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = x; i < x + 3; i++)
            {
                if (!check2(player2board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player2board[x][i] = 'D';
            }
        }
    }
    else
    {
        printError();
        runornot = 0;
        return false;
    }
    return true;
}

// input Corvette of Player 2
bool InputCoordinatesforCorvette2(char player2board[10][10])
{
    // Input Corvette for player 2
    //  Corvette Carrier
    cout << "Place your Corvette Ship." << endl;
    cout << "Write 'H' for horizontal and 'V' for Vertical: ";
    cin >> orien;
    cout << "initial y and x coordinates of ship: ";
    cin >> y >> x;
    cout << "***************************************" << endl;
    if (orien == 'H')
    {
        cord = y - 65;
        if (x > 9 || x < 0 || cord > 8 || cord < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = cord; i < cord + 2; i++)
            {
                if (!check2(player2board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player2board[x][i] = 'C';
            }
        }
    }
    else if (orien == 'V')
    {
        cord = y - 65;
        if (cord > 9 || cord < 0 || x > 8 || x < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = x; i < x + 2; i++)
            {
                if (!check2(player2board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player2board[x][i] = 'C';
            }
        }
    }
    else
    {
        printError();
        runornot = 0;
        return false;
    }
    return true;
}

// input Frigate of Player 2
bool InputCoordinatesforFrigate2(char player2board[10][10])
{
    // Input Frigate for player 2
    //  Frigate Carrier
    cout << "Place your Frigate Ship." << endl;
    cout << "Write 'H' for horizontal and 'V' for Vertical: ";
    cin >> orien;
    cout << "initial y and x coordinates of ship: ";
    cin >> y >> x;
    cout << "***************************************" << endl;
    if (orien == 'H')
    {
        cord = y - 65;
        if (x > 9 || x < 0 || cord > 9 || cord < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = cord; i < cord + 1; i++)
            {
                if (!check2(player2board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player2board[x][i] = 'F';
            }
        }
    }
    else if (orien == 'V')
    {
        cord = y - 65;
        if (cord > 9 || cord < 0 || x > 1 || x < 0)
        {
            printError();
            runornot = 0;
            return false;
        }
        else
        {
            x--;
            for (int i = x; i < x + 1; i++)
            {
                if (!check2(player2board, x, i))
                {
                    printError();
                    runornot = 0;
                    return false;
                }
                else
                    player2board[x][i] = 'F';
            }
        }
    }
    else
    {
        printError();
        runornot = 0;
        return false;
    }
    return true;
}

void printPlayer1Board()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << player1board[i][j] << ' ';
        }
        for (int k = 0; k < 15; k++)
            cout << ' ';
        for (int j = 0; j < 10; j++)
        {
            cout << player1opp[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}

void printPlayer2Board()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << player2board[i][j] << ' ';
        }
        for (int k = 0; k < 15; k++)
            cout << ' ';
        for (int j = 0; j < 10; j++)
        {
            cout << player2opp[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}

void printPlayer1OppenentBoard(char player1opp[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << player1opp[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}

void printPlayer2OppenentBoard(char player2opp[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << player2opp[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}

int main()
{
    welcome();
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            player1board[i][j] = '.';
            player2board[i][j] = '.';
            player1opp[i][j] = '-';
            player2opp[i][j] = '-';
        }
    }

    map<char, int> storeOfPlayer1;
    storeOfPlayer1['A'] = 5;
    storeOfPlayer1['B'] = 4;
    storeOfPlayer1['D'] = 3;
    storeOfPlayer1['C'] = 2;
    storeOfPlayer1['F'] = 1;

    map<char, int> storeOfPlayer2;
    storeOfPlayer2['A'] = 5;
    storeOfPlayer2['B'] = 4;
    storeOfPlayer2['D'] = 3;
    storeOfPlayer2['C'] = 2;
    storeOfPlayer2['F'] = 1;

    cout << "**************************************************************" << endl;
    cout << "*******************PLAYER 1 PLACE SHIPS!!*********************" << endl;
    cout << "**************************************************************" << endl;

    while (inputCheck == true)
    {
        InputCoordinatesforAircraft1(player1board);
        if (!runornot)
            break;
        inputCheck = InputCoordinatesforBattleShip1(player1board);
        if (!inputCheck)
        {
            break;
        }
        inputCheck = InputCoordinatesforDestroyer1(player1board);
        if (!inputCheck)
        {
            break;
        }
        inputCheck = InputCoordinatesforCorvette1(player1board);
        if (!inputCheck)
        {
            break;
        }
        inputCheck = InputCoordinatesforFrigate1(player1board);
        if (!inputCheck)
        {
            break;
        }
        inputCheck = false;
    }

    if (runornot == 1)
    {
        cout << "**************************************************************" << endl;
        cout << "*******************PLAYER 2 PLACE SHIPS!!*********************" << endl;
        cout << "**************************************************************" << endl;
        inputCheck = true;
        while (inputCheck == true)
        {
            InputCoordinatesforAircraft2(player2board);
            if (!runornot)
                break;
            inputCheck = InputCoordinatesforBattleShip2(player2board);
            if (!inputCheck)
            {
                break;
            }
            inputCheck = InputCoordinatesforDestroyer2(player2board);
            if (!inputCheck)
            {
                break;
            }
            inputCheck = InputCoordinatesforCorvette2(player2board);
            if (!inputCheck)
            {
                break;
            }
            inputCheck = InputCoordinatesforFrigate2(player2board);
            if (!inputCheck)
            {
                break;
            }
            inputCheck = false;
        }
    }

    /********************************************************
    *********************************************************
    ***********************GUESSING BEGINS!******************
    *********************************************************
    *********************************************************/

    // Guessing....
    if (runornot == 1)
    {
        cout << "**************************************************************" << endl;
        cout << "**************************************************************" << endl;
        int x1, x2;
        char y1, y2;
        while (scoreOfPlayer1 != 15 && scoreOfPlayer2 != 15)
        {
            // input the guessing of Player1
            cout << "Player1 turn....." << endl;
            cout << "Enter the guessed coordinates: " << endl;
            cin >> y1 >> x1;
            int k1 = y1 - 65;
            x1--;
            bool flag1 = false;
            if (player2board[x1][k1] == 'A' || player2board[x1][k1] == 'B' || player2board[x1][k1] == 'C' || player2board[x1][k1] == 'D' || player2board[x1][k1] == 'F')
            {
                scoreOfPlayer1++;
                player2board[x1][k1] = 'H';
                player1opp[x1][k1] = 'H';
                if (storeOfPlayer1[y1] == 0)
                {
                    cout << "******************************";
                    cout << endl
                         << "Hit and Sunk!!! " << endl;
                    cout << "******************************" << endl;
                }
                else
                    cout << "HIT!!" << endl;
                storeOfPlayer1[y1]--;
                printPlayer1Board();
                flag1 = true;
            }
            else if (player2board[x1][k1] == 'H')
            {
                cout << "Already Hit!!" << endl;
                flag1 = true;
            }
            if (!flag1)
            {
                player1opp[x1][k1] = '*';
                cout << "Missed the Guess!!" << endl
                     << endl;
            }

            int count1 = 0;
            for (auto i : storeOfPlayer1)
            {
                if (i.second == 0)
                    count1++;
            }
            if (count1 == 5 || scoreOfPlayer1 == 15)
            {
                cout << "All the ships shunk!!!";
                cout << endl;
                cout << "Player1 Won" << endl;
                cout << "*******************************" << endl;
                break;
            }
            cout << "Player2 turn......" << endl;
            cout << "Enter the guessed coordinates: ";
            cin >> y2 >> x2;
            int k2 = y2 - 65;
            x2--;
            bool flag2 = false;
            if (player1board[x2][k2] == 'A' || player1board[x2][k2] == 'B' || player1board[x2][k2] == 'C' || player1board[x2][k2] == 'D' || player1board[x2][k2] == 'F')
            {
                scoreOfPlayer2++;
                player1board[x2][k2] = 'H';
                player2opp[x2][k2] = 'H';
                if (storeOfPlayer2[y2] == 0)
                {
                    cout << "******************************";
                    cout << endl
                         << "Hit and Sunk!!!" << endl;
                    cout << "******************************" << endl;
                }
                else
                    cout << "HIT!!" << endl;
                storeOfPlayer2[y]--;
                printPlayer2Board();
                flag2 = true;
            }
            else if (player1board[x2][k2] == 'H')
            {
                cout << "Already Hit!!" << endl;
                flag2 = true;
            }
            if (!flag2)
            {
                player2opp[x2][k2] = '*';
                cout << "Missed the Guess!!" << endl
                     << endl;
            }

            int count2 = 0;
            for (auto i : storeOfPlayer2)
            {
                if (i.second == 0)
                    count2++;
            }
            if (count2 == 5 || scoreOfPlayer2 == 15)
            {
                cout << endl;
                cout << "******************************" << endl;
                cout << "All the ships shunk!!" << endl;
                cout << "Player2 Won" << endl;
                cout << "******************************" << endl;
                break;
            }
        }
    }
}
