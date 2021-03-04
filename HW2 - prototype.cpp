#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_ROWS = 50;
const int MAX_COLS = 50;
char matrix[MAX_ROWS][MAX_COLS];
string wordToBeSearched;
int numRows, numCols;

ifstream inFile;                  // Name of the input file
string inFileName;                // Holds the input file name as a string


void openFile(){
      // Prompts user to enter the input file
   cout << "Enter input file name" << endl;
   cin >> inFileName;
   inFile.open(inFileName.c_str());  // Converts the inputted file name into a string
   while(!inFile){
      cout << "The file could not be opened" << endl;
      cout << "Enter another file name or type \"quit\" or \"exit\"" << endl;
      cin >> inFileName;
      if(inFileName != "quit" || inFileName != "exit")
         break;
   }
}

void ignoreComments(){
   string commentLine;
   char charToSkip = inFile.peek();
   while (charToSkip == '#' || charToSkip == '\n'){
      getline(inFile,commentLine);
      charToSkip = inFile.peek();
   }
}

void readMatrix(){
       // Get the dimensions of matrix
   if(inFile){
      ignoreComments();
      inFile >> numRows >> numCols;
      cout << "Rows: " << numRows << endl;
      cout << "Cols: " << numCols << endl;
      ignoreComments();
   }

       // Reads the matrix from the given file
   for (int currentRow = 0; currentRow < numRows; currentRow++){
      for (int currentCol = 0; currentCol < numCols; currentCol++){
         inFile >> matrix[currentRow][currentCol];
      }
   }
}

void displayMatrix(char matrix[][MAX_COLS]){
   for (int currentRow = 0; currentRow < numRows; currentRow++){
      for (int currentCol = 0; currentCol < numCols; currentCol++){
         cout << matrix[currentRow][currentCol];
      }
      cout << endl;
   }
   cout << endl;
}

//Searches the grid for words going to the right
bool searchForwardRows(int r, int c)
{
   string test="";
   for(int column=c; column<MAX_COLS; column++)
   {
      test=test+matrix[r][column];
      if(test==wordToBeSearched)
         return true;
   }

}

//Searches the grid for words going to the left
void searchBackwardRows(char matrix[MAX_ROWS][MAX_COLS], char word[], int length){
}

//Searches the grid for words going down
void searchDownCols(char matrix[MAX_ROWS][MAX_COLS], char word[], int length){
}

//Searches the grid for words going up
void searchUpCols(char matrix[MAX_ROWS][MAX_COLS], char word[], int length){
}

//Searches the grid for words going diagonalUpRight
void searchDiagonalUpRight(char matrix[MAX_ROWS][MAX_COLS], char word[], int length){
}

//Searches the grid for words going diagonalUpLeft
void searchDiagonalUpLeft(char matrix[MAX_ROWS][MAX_COLS], char word[], int length){
}

//Searches the grid for words going diagonalDownRight
void searchDiagonalDownRight(char matrix[MAX_ROWS][MAX_COLS], char word[], int length){
}

//Searches the grid for words going diagonalDownLeft
void searchDiagonalDownLeft(char matrix[MAX_ROWS][MAX_COLS], char word[], int length){
}


void getWordBeingSearched(){
   ignoreComments();
   getline(inFile, wordToBeSearched);
   int length = wordToBeSearched.length(); //stores the length of the searched word
        //Creates an array to store the word being searched for
   char word[length + 1];
   strcpy(word, wordToBeSearched.c_str()); //converts a string to a char array
   for (int index = 0; index < length; index++){
      cout << word[index];
   }
   cout << endl;
   
   int row=0;
   int column=0;
   searchForwardRows(row, column);
   //searchBackwardRows(matrix, word, length);
      //searchDownCols(matrix, word, length);
}

int main(){
   openFile();
   readMatrix();
   displayMatrix(matrix);
   getWordBeingSearched();
      //searchFullMatrix(matrix, word, length);
}