#include <iostream>
#include <cstdlib>
#include "Array2D.h"

// The character parameter exists to give this a different signature than any of 
// the public constructors.
Array2D::Array2D(int numR, int numC, char differentiator) : numRows(numR), numCols(numC) {

   int** ary = new int*[numRows];
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

//__________________________________________________________________________________________
// _o-^-o
//------------------------------------------------------------------------------------------
//__________________________________________________________________________________________

Array2D::Array2D(const Array2D& other) : Array2D(numR, numC, 'c') // copy constructor            #1
{
   int cols = ar1.getNumCols(); 
   int rows = ar2.getNumRows();

   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = i;
      }
   }

}

int Array2D::getNumRows()                                                 //Getters for rows and cols     #2 
{
   return numRows; 
}

int Array2D::getNumCols()                                                
{
   return numCols; 
}                                                                //end                           


Array2D::~Array2D()                                              //Destructor for Array2D        #3
{
for(int i = 0 ; i < numRows ; i++)
{
   delete[] ary[i]
}
delete[] ary; 
} 

Array2D& Array2D::operator= (const Array2D& ar1, const Array2D& ar2)
   {

   int rows = ar1->getNumRows();
   int cols = ar1->getNumCols();
   Array2D *arNew = new Array2D(rows,cols); //Temp array
   
   	for (int i=0 ; i< rows ; i++){
		   for (int j=0 ; j<cols ;  j++){
             ar1[i][j] = ar2[i][j]; 
         }
      }
   return storage;
   }
   

  bool Array2D::operator== (const Array2D& ar1, const Array2D& ar2)
   {
      bool tf = 0; 
      int rows = ar1->getNumRows();
      int cols = ar1->getNumCols();
   	for (int i=0 ; i< rows ; i++){
		   for (int j=0 ; j<cols ;  j++){
            if(ar1[i][j] != ar2[i][j])
            {
               return(0);
            }
         }
      }
      return(1); 
   }

   //Overload * operator to perform 2D matrix multiplication and return the array filled with -1's 
   Array2D& Array2D::operator* (const Array2D& ar1, const Array2D& ar2)
   {
      int rows = ar1->getNumRows();
      int cols = ar2->getNumCols();

      Array2D  *boyo =  new Array2D(rows,cols); 

      if (rows != cols)
      {
         printf("ERROR IN operator*(const Array2D& ar1, const Array2D& ar2):        1st Array Rows != 2nd Array Cols");
             
      }
      else
      {
         for( int i = 0 ; i < rows ; i++ )
         {
            for(int k = 0 ; k < cols ; k++ ) {
            boyo[i][k] = -1; 
            }
         }
         return(*boyo); 
      }

      return nullptr; 
   
   }

   std::ostream& Array2D::operator<<(std::ostream&, const Array2D& ar2)
   {
      int rows = ar2->getNumRows();
      int cols = ar2->getNumCols();
   	for (int i=0 ; i< rows ; i++){
		   for (int j=0 ; j<cols ;  j++){
            std::cout << ar2[i][j] << " " ; 
         }
         std::cout << "\n"; 
      }
   }







