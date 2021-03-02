#include <iostream>
#include <cstdlib>
#include "Array2D.H"

// The character parameter exists to give this a different signature than any of 
// the public constructors.
Array2D::Array2D(int numR, int numC, char differentiator) : numRows(numR), numCols(numC) {

   ary = new int*[numRows];
   for (int i = 0; i < numRows; i++) {
      ary[i] = new int[numCols];
      for (int j = 0; j < numCols; j++) {
            ary[i][j] = -1;
      }
   }
}

Array2D::Array2D(int numR, int numC) : Array2D(numR, numC, 'c') { 
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = i;
      }
   }
}

Array2D::Array2D(int numR, int numC, int val) : Array2D(numR, numC, 'c') { 
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = val;
      }
   }
}

Array2D::Array2D(const Array2D& other) : Array2D(numR, numC, 'c') // copy constructor            #1
{
   int cols = Array2D.getNumCols(); 
   int rows = Array2D.getNumRows();

   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = i;
      }
   }

}

int getNumRows()                                                 //Getters for rows and cols     #2 
{
   return numRows; 
}

int getNumCols()                                                
{
   return numCols; 
}                                                                //end                           


Array2D::~Array2D()                                              //Destructor for Array2D        #3
{
   deleteAry(this.Array2D)
} 




int& Array2D::operator( )(int row, int col) {
   return ary[row][col];
}
      
int Array2D::operator( )(int row, int col) const {
   return ary[row][col];
}

bool Array2D::sameSize(const Array2D& other) const {
   return (numRows == other.getNumRows( ) && numCols == other.getNumCols( ));
}

void Array2D::deleteAry(int** ary) {
   for (int i = 0; i < numRows; i++) {
      delete [ ] ary[i];
   }
   delete [ ] ary;
}
