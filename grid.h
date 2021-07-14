/**
 * @file: grid.h
 *
 * @description: Program contains the information for the grid
 *
 * Code Written by
 * @author: Sai Samarth Patipati Umesh
 * U. of Illinois, Chicago
 * @date: 03/2/21
 *
 */
#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>
using namespace std;
template<typename T>
class Grid {
 private:
  struct ROW {
    T*  Cols;     // array of column elements
    size_t NumCols;  // total # of columns (0..NumCols-1)
  };
  ROW* Rows;     // array of ROWs
  size_t  NumRows;  // total # of rows (0..NumRows-1)

 public:
  //
  // default constructor:
  //
  // Called automatically by C++ to construct a 4x4 Grid.  All
  // elements are initialized to the default value of T.
  //
  Grid() {
    Rows = new ROW[4];  // 4 rows
    NumRows = 4;
    // initialize each row to have 4 columns:
    for (size_t r = 0; r < NumRows; ++r) {
      Rows[r].Cols = new T[4];
      Rows[r].NumCols = 4;
      // initialize the elements to their default value:
      for (size_t c = 0; c < Rows[r].NumCols; ++c) {
        Rows[r].Cols[c] = T();  // default value for type T:
      }
    }
  }
  //
  // parameterized constructor:
  //
  // Called automatically by C++ to construct a Grid with R rows,
  // where each row has C columns. All elements are initialized to
  // the default value of T.
  //
  Grid(size_t R, size_t C) {
      if (R < 0 || C < 0) {
          // throws an error if the indices are out of bounds.
          throw out_of_range("Invalid size.");
      }
      Rows = new ROW[R];
      NumRows = R;
      // initialising each row to have C columns
      for (size_t i = 0; i < NumRows; i++) {
          Rows[i].Cols = new T[C];
          Rows[i].NumCols = C;
          // initialising the elements to their default T value
          for (size_t j = 0; j < Rows[i].NumCols; j++) {
              Rows[i].Cols[j] = T();  // default value of type T
          }
      }
  }
  //
  // destructor:
  //
  // Called automatically by C++ to free the memory associated by the vector.
  //
  virtual ~Grid() {
      if (Rows != nullptr) {
         for (size_t r = 0; r < this->NumRows; r++) {
             delete [] Rows[r].Cols;  // delete each column if Rows is not null
         }
         delete[] Rows;  // delete the whole array after deleting the columns
     }
  }
  //
  // copy constructor:
  //
  // Called automatically by C++ to construct a Grid that contains a
  // copy of an existing Grid.  Example: this occurs when passing
  // Grid as a parameter by value
  //
  //   void somefunction(Grid<int> G2)  <--- G2 is a copy:
  //   { ... }
  //
  Grid(const Grid<T>& other) {
      this-> Rows = new ROW[other.NumRows];
      this-> NumRows = other.NumRows;
      // initialising each row to have C columns
      for (size_t i = 0; i < this->NumRows; i++) {
          this-> Rows[i].Cols = new T[other.Rows[i].NumCols];
          this -> Rows[i].NumCols = other.Rows[i].NumCols;
          // copying the elements from other to this Rows
          for (size_t j = 0; j < this-> Rows[i].NumCols; j++) {
              // copying the elements from other
              this-> Rows[i].Cols[j] = other.Rows[i].Cols[j];
          }
      }
  }
  //
  // copy operator=
  //
  // Called when you assign one vector into another, i.e. this = other;
  //
  Grid& operator=(const Grid& other) {
      Grid<T> temp;
      // delete the current Rows if it exists
     if (Rows != nullptr) {
         for (size_t r = 0; r < this->NumRows; r++) {
             delete [] Rows[r].Cols;
         }
         delete[] Rows;
     }
     Rows = new ROW[other.NumRows];  // creating a new Rows using the numrows or other
     NumRows = other.NumRows;
     for (size_t i = 0; i < NumRows; i++) {
         // copying the size and creating new cols
         Rows[i].Cols = new T[other.Rows[i].NumCols];
         Rows[i].NumCols = other.Rows[i].NumCols;
         // copying the elements from other to this Rows
         for (size_t j = 0; j < this-> Rows[i].NumCols; j++) {
             Rows[i].Cols[j] = other.Rows[i].Cols[j]; // copying the elements from other
             }
     }
     return *this;  // TO DO:  update this, it is only here so code compiles.
     }
  //
  // numrows
  //
  // Returns the # of rows in the Grid.  The indices for these rows
  // are 0..numrows-1.
  //
  size_t numrows() const {
    return NumRows;  // returns the number of rows
  }
  //
  // numcols
  //
  // Returns the # of columns in row r.  The indices for these columns
  // are 0..numcols-1.  For now, each row will have the same number of columns.
  //
  size_t numcols(size_t r) const {
      size_t counter = 0;
      while (counter < NumRows) {
          if (r == counter) {
              return Rows[counter].NumCols;  // returns the number of columns for the given row
          }
          counter++;
      }
      return 0;  
  }
  //
  // size
  //
  // Returns the total # of elements in the grid.
  //
  size_t size() const {
     size_t size = NumRows * Rows[0].NumCols;  // size is equal to numrows times numcols
     return size; 
  }
  //
  // ()
  //
  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //
  //    grid(r, c) = ...
  //    cout << grid(r, c) << endl;
  //
  T& operator()(size_t r, size_t c) {
      if (r < 0 || c < 0 || r >= NumRows || c >= Rows[0].NumCols) {
          // throws an error if the indices are out of bounds.
          throw out_of_range("Indices are out of range.");
      }
      return Rows[r].Cols[c];
  }
  //
  // _output
  //
  // Outputs the contents of the grid; for debugging purposes.  This is not
  // tested.
  //
  void _output() {
      // outputs basic details for debugging
      cout << "NumRows: " << NumRows << endl;
      cout << "NumCols: " << Rows[0].NumCols << endl;
      cout << "Size: " << NumRows * Rows[0].NumCols << endl;
      cout << "Grid: " << endl;
      for (int i = 0; i < NumRows; i++) {
          for (int j = 0; j < Rows[i].NumCols; j++) {
              cout << Rows[i].Cols[j] << " ";
          }
          cout << endl;
      }
  }
};
