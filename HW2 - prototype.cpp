#include <iostream>
#include <iomanip>
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
int foundCount=0;
vector<string> notFound {};
string originalVersion="";

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
   for(int column=c; column<numCols; column++)
   {
      test=test+matrix[r][column];
      if(test==wordToBeSearched)
      {
         //cout<<"CURATED WORD"<<test<<endl;
         return true;
      }
   }
   return false;
}

//Searches the grid for words going to the left
bool searchBackwardRows(int r, int c)
{
   string test="";
   for(int column=c; column>-1; column--)
   {
      test=test+matrix[r][column];
      if(test==wordToBeSearched)
         return true;
   }
   return false;
}

//Searches the grid for words going down
bool searchDownCols(int r, int c)
{
   string test="";
   for(int row=r; row<numRows; row++)
   {
      test=test+matrix[row][c];
      if(test==wordToBeSearched)
         return true;
   }
   return false;
}

//Searches the grid for words going up
bool searchUpCols(int r, int c){
   string test="";
   for(int row=r; row>-1; row--)
   {
      test=test+matrix[row][c];
      if(test==wordToBeSearched)
         return true;
   }
   return false;
}

//Searches the grid for words going diagonalUpRight
bool searchDiagonalUpRight(int r, int c){
   string test="";
   int column=c;
   for(int row=r; row>-1; row--)
   {
      if(column<numCols)
         test=test+matrix[row][column];
      if(test==wordToBeSearched)
         return true;
      column++;
   }
   return false;
}

//Searches the grid for words going diagonalUpLeft
bool searchDiagonalUpLeft(int r, int c){
   string test="";
   int column=c;
   for(int row=r; row>-1; row--)
   {
      if(column>-1)
         test=test+matrix[row][column];
      if(test==wordToBeSearched)
         return true;
      column--;
   }
   return false;
}

//Searches the grid for words going diagonalDownRight
bool searchDiagonalDownRight(int r, int c){
   string test="";
   int column=c;
   for(int row=r; row<numRows; row++)
   {
      if(column<numCols)
         test=test+matrix[row][column];
      if(test==wordToBeSearched)
         return true;
      column++;
   }
   return false;
}

//Searches the grid for words going diagonalDownLeft
bool searchDiagonalDownLeft(int r, int c){
   string test="";
   int column=c;
   for(int row=r; row<numRows; row++)
   {
      if(column>-1)
         test=test+matrix[row][column];
      if(test==wordToBeSearched)
         return true;
      column--;
   }
   return false;
}
string removeSpace(string original)
{
   string clean="";
   char spaceCharacter=' ';
   
   for(int i=0; i<original.length(); i++)
   {
      if(original.at(i)!=spaceCharacter)
         clean=clean+original.at(i);
   }
   
   return clean;
}

   
bool isFound()
{  
   //foundCount=0;
   originalVersion=wordToBeSearched;
   wordToBeSearched=removeSpace(wordToBeSearched);
   bool status=false;
   for(int row=0;row<numRows;row++)
   {
      for(int column=0;column<numCols;column++)
      {
         if(searchForwardRows(row, column)==true)
         {  //cout<<"ISFOUNDMETHOD"<<endl;
            foundCount++;
            cout << wordToBeSearched <<" found at "<<(row+1)<<", "<<(column+1)<<":"<<"       (direction = "<<"E)" << endl;
            status= true;
         }
      
         if(searchBackwardRows(row, column)==true)
         {  //cout<<"ISFOUNDMETHOD"<<endl;
            foundCount++;
            cout << wordToBeSearched <<" found at "<<(row+1)<<", "<<(column+1)<<":"<<"       (direction = "<<"W)" << endl;
            status= true;
         }
         
         if(searchDownCols(row, column)==true)
         {  //cout<<"ISFOUNDMETHOD"<<endl;
            foundCount++;
            cout << wordToBeSearched <<" found at "<<(row+1)<<", "<<(column+1)<<":"<<"       (direction = "<<"S)" << endl;
            status= true;
         }
         
         if(searchUpCols(row, column)==true)
         {  //cout<<"ISFOUNDMETHOD"<<endl;
            foundCount++;
            cout << wordToBeSearched <<" found at "<<(row+1)<<", "<<(column+1)<<":"<<"       (direction = "<<"N)" << endl;
            status= true;
         }
         
         if(searchDiagonalUpRight(row, column)==true)
         {  //cout<<"ISFOUNDMETHOD"<<endl;
            foundCount++;
            cout << wordToBeSearched <<" found at "<<(row+1)<<", "<<(column+1)<<":"<<"       (direction = "<<"NE)" << endl;
            status= true;
         }
         
         if(searchDiagonalUpLeft(row, column)==true)
         {  //cout<<"ISFOUNDMETHOD"<<endl;
            foundCount++;
            cout << wordToBeSearched <<" found at "<<(row+1)<<", "<<(column+1)<<":"<<"       (direction = "<<"NW)" << endl;
            status= true;
         }
         
         if(searchDiagonalDownRight(row, column)==true)
         {  //cout<<"ISFOUNDMETHOD"<<endl;
            foundCount++;
            cout << wordToBeSearched <<" found at "<<(row+1)<<", "<<(column+1)<<":"<<"       (direction = "<<"SE)" << endl;
            status= true;
         }
         if(searchDiagonalDownLeft(row, column)==true)
         {  //cout<<"ISFOUNDMETHOD"<<endl;
            foundCount++;
            cout << wordToBeSearched <<" found at "<<(row+1)<<", "<<(column+1)<<":"<<"       (direction = "<<"SW)" << endl;
            status= true;
         }
      }
   }
   
   return status;
}

void getWordBeingSearched(){
   ignoreComments();
   /*int length = wordToBeSearched.length(); //stores the length of the searched word
        //Creates an array to store the word being searched for
   char word[length + 1];
   strcpy(word, wordToBeSearched.c_str()); //converts a string to a char array
   for (int index = 0; index < length; index++){
      cout << word[index];
   }
   cout << endl;*/
   if(isFound())
   {
      //word is found
   }
   else
   {
      notFound.push_back(originalVersion); 
   }
   
   //searchForwardRows(row, column);
   //searchBackwardRows(matrix, word, length);
      //searchDownCols(matrix, word, length);
}



int main(){
   openFile();
   readMatrix();
   displayMatrix(matrix);
   while (getline(inFile, wordToBeSearched))
      getWordBeingSearched();
  
   //cout<<foundCount<<endl;    
  
   cout<<"\nMovies not Found: ";
   for (int i = 0; i < notFound.size(); i++)
      cout << notFound[i] << endl;
   
}