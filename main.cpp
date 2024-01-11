#include <iostream>

using namespace std;

void printFreeFields(char** myPtr, int numRows, int numCols);
void updateField(char** myPtr, int numRows, int numCols, int fieldNum, char playerSymbol);
bool checkVictory(char** myPtr, int numRows, int numCols, char playerSymbol);
const int ROWS = 3;
const int COLS = 3;

int main()
{
    char** myPtr = new char* [ROWS];
    char myArr[ROWS][COLS];
    int counter = 1;
    bool ongoing = true;
    int number;
   
    for (int i = 0; i < ROWS; i++) 
    {
        myPtr[i] = myArr[i];
        for (int j = 0; j < COLS; j++)
        {
            myArr[i][j] = ' ';
        }
    }

    while ((counter < 10) && (ongoing == true)) 
    {
        cout << "The fields with the following field ID numbers are still free: ";
        printFreeFields(myPtr, ROWS, COLS);

        if (counter % 2 == 0)
        {
            cout << "Black choose empty field! ";
            char playerSymbol = 'b';
            cin >> number;
            updateField(myPtr, ROWS, COLS, number, playerSymbol);
            if (checkVictory(myPtr, ROWS, COLS, playerSymbol)) 
            {
                cout << "Victory for Black";
                ongoing = false;
            }
        }
        else
        {
            cout << "White choose empty field! ";
            char playerSymbol = 'w';
            cin >> number;
            updateField(myPtr, ROWS, COLS, number, playerSymbol);
            if (checkVictory(myPtr, ROWS, COLS, playerSymbol)) 
            {
                cout << "Victory for White";
                ongoing = false;
            }
        }
        counter = counter + 1;
    }
    cout << endl << "The game has ended" << endl;
}

void printFreeFields(char** myPtr, int numRows, int numCols) 
{
    cout << endl << "-------------" << endl;
    int counter = 1;
    for (int i = 0; i < numRows; i++) 
    {
        cout << "| ";
        for (int j = 0; j < numCols; j++) 
        {
            if (myPtr[i][j] == ' ') 
            {
                cout << counter << " | ";
            } else {
                cout << myPtr[i][j] << " | ";
            }
            counter++;
        }
        cout << endl << "-------------" << endl;
    }
}

void updateField(char** myPtr, int numRows, int numCols, int fieldNum, char playerSymbol)
{
    int row = (fieldNum - 1) / ROWS;
    int col = (fieldNum - 1) % COLS;
    if (myPtr[row][col] == ' ') 
    {
        myPtr[row][col] = playerSymbol;
    }
    else 
    {
        cout << "That field is already occupied. Choose another field: ";
        int newFieldNum;
        cin >> newFieldNum;
        updateField(myPtr, numRows, numCols, newFieldNum, playerSymbol);
    }
}


bool checkVictory(char** myPtr, int numRows, int numCols, char playerSymbol)
{
    for (int i = 0; i < numRows; i++) 
    {
        bool rowVictory = true;
        for (int j = 0; j < numCols; j++) 
        {
            if (myPtr[i][j] != playerSymbol) 
            {
                rowVictory = false;
                break;
            }
        }
        if (rowVictory) {
            return true;
        }
    }

    for (int j = 0; j < numCols; j++) 
    {
        bool colVictory = true;
        for(int i = 0; i < numRows; i++) 
        {
            if (myPtr[i][j] != playerSymbol)
            {
                colVictory = false;
                break;
            }
        }
        if (colVictory) 
        {
            return true;
        }
    }

    bool diagonalVictory = true;
    for (int i = 0; i < numRows; i++) 
    {
        if (myPtr[numRows - i - 1][i] != playerSymbol) 
        {
            diagonalVictory = false;
            break;
        }
    }
    if (diagonalVictory) 
    {
        return true;
    }

    return false;
}