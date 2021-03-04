#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

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


void getWordBeingSearched(){
        ignoreComments();
            int length = wordToBeSearched.length(); //stores the length of the searched word
            //Creates an array to store the word being searched for
            char word[length + 1];
            strcpy(word, wordToBeSearched.c_str()); //converts a string to a char array
            for (int index = 0; index < length; index++){
                cout << word[index];
            }
            cout << endl;

//      searchForwardRows(matrix, word, length);
//      searchBackwardRows(matrix, word, length);
//      //searchDownCols(matrix, word, length);
}

int main(){
      openFile();
      readMatrix();
      displayMatrix(matrix);
      while (getline(inFile, wordToBeSearched))
      getWordBeingSearched();
}


//C:\Shriya\College\WordSearchFinal.txt




//cout << "Found: " << matrix[currentRow][currentCol] << " at row " << currentRow << " and col " << currentCol << endl;
//cout<<numMatches;

//void searchFullMatrix(char matrix[MAX_ROWS][MAX_COLS], char word[], int length){
//      searchForwardRows(matrix, word, length);
//      searchBackwardRows(matrix, word, length);
////    searchDownCols(matrix, word, length);
//}


//                    if(matrix[currentRow][currentCol] == word[index] && currentCol >= 0)
//                    {
//                        found[index] = word[index];
//                        index++;
//                    }
//                    else
//                        index = 0;

//                if(matrix[currentRow][currentCol] == word[index] && index < length && currentCol >= 0)
//                {
//                    found[index] = word[index];
//                    index++;
//                }
//                else
//                {
//                    index = 0;
//                    currentCol--;
//                }

//
////Searches the grid for words going to the right
//void searchForwardRows(char matrix[MAX_ROWS][MAX_COLS], char word[], int length){
//        bool wordFound = false;
//        int  index = 0;          //array position of the letter being searched for
//        int  counter = 0;        //counts the number of times the letters in the word and found array match
//        char found[length + 1];  //array to hold the letters found
//        //Loop to control the rows
//        for (int currentRow = 0; currentRow < numRows && currentRow >= 0; currentRow++){
//            //Loop to control the columns
//            for (int currentCol = 0; currentCol < numCols && currentCol >= 0; currentCol++){
//                //checks if the letters in the word search match the letters being
//                //searched for
//                if(matrix[currentRow][currentCol] != word[index]){
//                    index = 0;
//                    if (currentCol != 0)
//                    currentCol--;
//                }
//                else if (matrix[currentRow][currentCol] == word[index] && index < length && currentCol >= 0){ //if the indexes match
//                    found[index] = word[index];
//                    index++;
//                }
//            }
//
//        }
//
//        for(int match = 0; match < length; match++)
//            if(found[match] == word[match]){
//                cout << found[match] << endl;
//                counter++;
//            }
//                if(counter == length)
//                cout << "Word Found" << endl;
//}
//
////Searches the grid for words going to the left
//void searchBackwardRows(char matrix[MAX_ROWS][MAX_COLS], char word[], int length){
//        bool wordFound = false;
//        int  index = 0;         //array position of the letter being searched for
//        int  counter = 0;
//        char found[length + 1];
//        //Loop to control the rows
//        for (int currentRow = 0; currentRow < numRows && currentRow >= 0; currentRow++){
//            //Loop to control the columns
//            for (int currentCol = numCols - 1; currentCol >= 0 ; currentCol--){
//                //checks if the letters in the word search match the letters being
//                //searched for
//                if(matrix[currentRow][currentCol] == word[index] && index < length){
//                    found[index] = word[index];
//                    index++;
//                    currentCol--; //moves to the next letter (left) to find a match
//                    if(matrix[currentRow][currentCol] == word[index] && currentCol >= 0){
//                        found[index] = word[index];
//                        index++;
//                    }
//                    else{
//                        index = 0;
//                    }
//                }
//            }
//        }
//        for(int match = 0; match < length; match++)
//            if(found[match] == word[match])
//                counter++;
//                if(counter == length)
//                cout << "Word Found" << endl;
//}

////Searches the grid for words going down
//void searchDownCols(char matrix[MAX_ROWS][MAX_COLS], char word[], int length){
//        bool wordFound = false;
//        int  index = 0;         //array position of the letter being searched for
//        int  numMatches = 1;    //counts how many times a match is found
//        int  counter = 0;
//        char found[length + 1];
//        //Loop to control the columns
//        for (int currentCol = 0; currentCol < numCols && currentCol >= 0; currentCol++){
//            //Loop to control the rows
//            for (int currentRow = 0; currentRow < numRows && currentRow >= 0; currentRow++){
//                //checks if the letters in the word search match the letters being
//                //searched for
//                if(matrix[currentCol][currentRow] == word[index] && index < length){
//                    found[index] = word[index];
//                    numMatches = 0;
//                    numMatches++;
//                    index++;
//                    currentRow++; //moves to the next letter (right) to find a match
//                    if(matrix[currentCol][currentRow] == word[index] && currentRow >= 0){
//                        found[index] = word[index];
//                        numMatches++;
//                        index++;
//                    }
//                    else{
//                        numMatches--;
//                        index = 0;
//                    }
//                }
//            }
//        }
//        //checks if the number of matches found is the same as the length of the word
//        cout << numMatches;
//        for(int match = 0; match < length; match++)
//            if(found[match] == word[match])
//                counter++;
//                if(counter == length)
//                cout << "Word Found" << endl;
//
//}

