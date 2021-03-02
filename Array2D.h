#ifndef ARRAY2D_H_
#define ARRAY2D_H_
#include <iostream>
class Array2D {
private:
   Array2D(int numR, int numC, char differentiator);
   void deleteAry(int** ary);
   bool sameSize(const Array2D& other) const;
   
    //New stuff
   Array2D(const Array2D& other); // copy constructor 

public:
   Array2D(int numR, int numC); 
   Array2D(int numR, int numC, int val); 

   virtual int& operator( )(int row, int col);
   virtual int operator( )(int row, int col) const;
   //New stuff
   int getNumRows();  
   int getNumCols(); 
   ~Array2D(); 

};
#endif /* ARRAY2D_H_ */
