#ifndef ARRAY2D_H_
#define ARRAY2D_H_
#include <iostream>
class Array2D {
private:
   Array2D(int numR, int numC, char differentiator);
   void deleteAry(int** ary);
   bool sameSize(const Array2D& other) const;
   
    //New stuff
    
   


public:
   Array2D(int numR, int numC); 
   Array2D(int numR, int numC, int val); 
   Array2D(const Array2D& other); // copy constructor

   virtual int& operator( )(int row, int col);
   virtual int operator( )(int row, int col) const;
   //New stuff
   int numRows; 
   int numCols;
   
   
   int getNumRows();  
   int getNumCols(); 
   virtual~Array2D(); 
   
   //OP OVERLOADS I ADDED 
   Array2D& operator= (const Array2D& ar2);
   Array2D& operator* (const Array2D& ar2);

   bool operator==(const Array2D& ar2); 
   std::ostream& operator<<(Array2D& ar1); 

};
#endif /* ARRAY2D_H_ */
