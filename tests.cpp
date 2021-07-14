/**
 * @file: tests.cpp
 *
 * @description: Program contains all the tests that check public functions in grid.h and escape the labyrinth.
 *
 * Code Written by
 * @author: Sai Samarth Patipati Umesh
 * U. of Illinois, Chicago
 * @date: 03/2/21
 *
 */
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include "maze.h"
#include "grid.h"
#include "EscapeTheLabyrinth.h"
// tests the default constructor of grid using the int type
TEST(grid, defaultConstructorInt){
    Grid <int> g1;
    Grid <int> g2;
    Grid <int> g3;
    int random;
    ASSERT_EQ(g1.numrows(), 4);  // checking th default number of rows
    for (int k = 0; k < g3.numrows(); k++) {  // adding values to see if the objects are created
        for (int l = 0; l < g3.numcols(k); l++) {
            random = rand();
           g2(k, l) = random;
           g3(k, l) = random + 1;
        }
    }
    for (int i = 0; i < g1.numrows(); i++) {
        ASSERT_EQ(g1.numcols(i), 4);  // checks the default number of columns
        EXPECT_EQ(g1.numcols(i), g2.numcols(i));  // 
        for (int j = 0; j < g1.numcols(i); j++) {
            ASSERT_EQ(g1(i,j), 0);  // g1 has default values
            EXPECT_NE(g1(i,j), g2(i,j));  // g1 and g2 will not be equal
            EXPECT_LT(g2(i,j), g3(i, j));  // values in g2 are equal to values in g3 minus 1
        }
    }
}
// tests the default constructor of grid using the string type
TEST(grid, defaultConstructorString){
    // array containing letters as characters
    const char alphabets[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 
    'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 
    'v', 'w', 'x', 'y', 'z' };
    Grid <string> g1;
    Grid <string> g2;
    Grid <string> g3;
    for (int k = 0; k < g2.numrows(); k++) {
        for (int l = 0; l < g2.numcols(k); l++) {
            string res = "";
            int num = rand() % 7 + 2; // generates a random num between 2 and 7
            for (int n = 0; n < num; n++) {  // creates a random word between 2-7 characters
                res = res + alphabets[rand() % 26];
            }
            g2(k, l) = res;  // adds the string to the grids to compare
            g3(k, l) = res;
        }
    }
    EXPECT_EQ(g1.numrows(), 4);  // checking the number of rows
    for (int i = 0; i < g1.numrows(); i++) {
        ASSERT_EQ(g1.numcols(i), 4);  // checking the default number of columns
        EXPECT_EQ(g1.numcols(i), g2.numcols(i));  // checking the number of columns
        for (int j = 0; j < g1.numcols(i); j++) {
            ASSERT_EQ(g1(i,j), "");  // checking the default value of string
            EXPECT_NE(g1(i,j), g2(i,j));  // checking g1 and g2, they are not equal
            EXPECT_EQ(g2(i, j), g3(i, j));  // checking g2 and g3, they are equal
        }
    }
}
// tests the default constructor of grid using double type
TEST(grid, defaultConstructorDouble){
    Grid <double> g1;
    Grid <double> g2;
    Grid <double> g3;
    for (int k = 0; k < g3.numrows(); k++) {
        for (int l = 0; l < g3.numcols(k); l++) {
            double random = (double)rand(); // generates a random double number and adds to grids
            g2(k, l) = random;
            g3(k, l) = random - 1;
        }
    }
    EXPECT_EQ(g1.numrows(), 4);  // checking the number of rows
    for (int i = 0; i < g1.numrows(); i++) {
        ASSERT_EQ(g1.numcols(i), 4); // checking the number of default columns
        EXPECT_EQ(g1.numcols(i), g2.numcols(i));  // checking g1 and g2, they are not equal  
        for (int j = 0; j < g1.numcols(i); j++) {
            ASSERT_EQ(g1(i,j), 0.0);  // checking the default value of double
            EXPECT_NE(g1(i, j), g2(i, j));  // checking g1 and g2, they are not equal
            EXPECT_GT(g2(i, j), g3(i, j));  // checking g2 and g3, they are equal
        }
    }
}
// tests the default constructor of grid using char type
TEST(grid, defaultConstructorChar){
     // array containing letters as characters
    const char alphabets[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 
    'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 
    'v', 'w', 'x', 'y', 'z' };
    Grid <char> g1;
    Grid <char> g2;
     for (int k = 0; k < g2.numrows(); k++) {
        for (int l = 0; l < g2.numcols(k); l++) {
            char c = alphabets[rand() % 26]; // generates a random character and adds to grids
            ASSERT_EQ(g1(k, l), g2(k, l));  // checks if both have default values
            g2(k, l) = c;
        }
    }
    EXPECT_EQ(g1.numrows(), 4);  // checking the number of rows
    for (int i = 0; i < g1.numrows(); i++) {
        ASSERT_EQ(g1.numcols(i), 4);  // checking the number of default columns
        EXPECT_EQ(g1.numcols(i), g2.numcols(i));
        for (int j = 0; j < g1.numcols(i); j++) {
            ASSERT_EQ(g1(i,j), NULL);  // checking the default value of double
            EXPECT_NE(g1(i, j), g2(i, j));  // checking g1 and g2, they are not equal
        }
    }
}
// tests the default constructor of grid using float type
TEST(grid, defaultConstructorFloat){
    Grid <float> g1;
    Grid <float> g2;
    Grid <float> g3;
    for (int k = 0; k < g3.numrows(); k++) {
        for (int l = 0; l < g3.numcols(k); l++) {
            float random = (float)rand();  // generates a random float and adds it to grids
            g2(k, l) = random;
            g3(k, l) = random;
        }
    }
    EXPECT_EQ(g1.numrows(), 4);  // checking the number of rows
    for (int i = 0; i < g1.numrows(); i++) {
        ASSERT_EQ(g1.numcols(i), 4);  // checks the number of default columns
        EXPECT_EQ(g1.numcols(i), g2.numcols(i));
        for (int j = 0; j < g1.numcols(i); j++) {
            ASSERT_EQ(g1(i,j), 0.0);  // checks the default value of float
            EXPECT_NE(g1(i, j), g2(i, j));  // checking g1 and g2, they are not equal 
            EXPECT_FLOAT_EQ(g2(i, j), g3(i, j));  // checking g2 and g3, they are equal
        }
    }
}
// tests the exception when invalid sizes are passed
TEST(grid, ConstructorInvalid) {
    try {
        Grid <int>  g1(-1, 20);  // row size is invalid
        Grid <string> g2(-2, -4);  // both are invalid
        Grid <float> g3(0, -30);  // column size is invalid
        EXPECT_TRUE(false);  // exception was NOT thrown
    } catch (const exception& e) {
        EXPECT_TRUE(true);  // exception was thrown
    }
}
// tests the constructor of grid using int type 
TEST(grid, ConstructorInt){
    Grid <int> g(7, 9);
    vector <int> nums;  // used to store the numbers to compare
    EXPECT_EQ(g.numrows(), 7);  // checking the number of rows
    for (int k = 0; k < g.numrows(); k++) {
        for (int l = 0; l < g.numcols(k); l++) {
            int random = rand();
            ASSERT_EQ(g(k, l), 0);
            // trying to add some numbers that are less than generated number
            if (l % 2 == 0) {
                g(k, l) = random - 2;
            } else {
                g(k, l) = random;
            }
            nums.push_back(random);  // adding the generated number into vector
        }
    }
    int num = 0;
    for (int i = 0; i < g.numrows(); i++) {
        EXPECT_EQ(g.numcols(i), 9);  // checks if the number of columns are the same as given
        for (int j = 0; j < g.numcols(i); j++) {
            EXPECT_LE(g(i,j), nums.at(num));  // contents of g are <= the contents of nums
            num++;
        }
    }
}
// tests the constructor of grid using string type
TEST(grid, ConstructorString){
    Grid <string> g(50, 100);
    // array containing letters as characters
    const char alphabets[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 
    'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 
    'v', 'w', 'x', 'y', 'z' };
    vector <string> words;
    for (int k = 0; k < g.numrows(); k++) {
        for (int l = 0; l < g.numcols(k); l++) {
            ASSERT_EQ(g(k, l), "");  // checks if the grid has default string values
            string res = "";
            int num = rand() % 7 + 2;  // generates a random number between 7 and 2
            for (int n = 0; n < num; n++) {
                res = res + alphabets[rand() % 26];  // generates a random string of length 2-7
            }
            g(k, l) = res;
            words.push_back(res);
        }
    }
    int ind = 0;
    EXPECT_EQ(g.numrows(), 50);  // checking the number of rows
    for (int i = 0; i < g.numrows(); i++) {
        EXPECT_EQ(g.numcols(i), 100);  // checks the number of columns
        for (int j = 0; j < g.numcols(i); j++) {
            EXPECT_EQ(g(i,j), words.at(ind)); // compares to see if the strings are equal
            ind++;
        }
    }
}
// tests the constructor of grid using double type
TEST(grid, ConstructorDouble){
    Grid <double> g(100, 100);
    vector <double> nums;  // vector to hold the numbers
    EXPECT_EQ(g.numrows(), 100);  // checking the number of rows
    for (int k = 0; k < g.numrows(); k++) {
        for (int l = 0; l < g.numcols(k); l++) {
            double random = (double)rand();  // generates random double numbers and adds to grid and vector
            if (l % 2 == 0) {  // creating some numbers which are +2 than the regular number
                g(k, l) = random + 2;
            } else {
                g(k, l) = random;
            }
            nums.push_back(random);
        }
    }
    int ind = 0;
    for (int i = 0; i < g.numrows(); i++) {
        EXPECT_EQ(g.numcols(i), 100);  // checks the number of columns
        for (int j = 0; j < g.numcols(i); j++) {
            EXPECT_GE(g(i, j), nums.at(ind));  // checks all the contents
            ind++;
        }
    }
}
// tests the constructor of grid using char type
TEST(grid, ConstructorChar){
    // array to hold all the letters as characters
    const char alphabets[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 
    'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 
    'v', 'w', 'x', 'y', 'z' };
    Grid <char> g(50, 100);
    vector <char> characters;  // vector to hold letters
    EXPECT_EQ(g.numrows(), 50);  // checking the number of rows
    for (int k = 0; k < g.numrows(); k++) {
        for (int l = 0; l < g.numcols(k); l++) {
            char c = alphabets[rand() % 26];  // generates a random char and adds to grid and vector
            ASSERT_EQ(g(k, l), NULL);  // checking the default of char
            g(k, l) = c;
            characters.push_back(c);
        }
    }
    int ind = 0;
    for (int i = 0; i < g.numrows(); i++) {
        EXPECT_EQ(g.numcols(i), 100);  // checks the columns
        for (int j = 0; j < g.numcols(i); j++) {
            EXPECT_EQ(g(i, j), characters.at(ind));  // checks all the elements
            ind++;
        }
    }
}
// tests the constructor of grid using float type
TEST(grid, ConstructorFloat){
    Grid <float> g1(20, 30);
    vector <float> nums;  // vector to hold numbers
    for (int k = 0; k < g1.numrows(); k++) {
        for (int l = 0; l < g1.numcols(k); l++) {
            float random = (float)rand();  // creates random float numbers and adds to grid and vector
            g1(k, l) = random;
            nums.push_back(random);
        }
    }
    int ind = 0;
    EXPECT_EQ(g1.numrows(), 20);  // checking the number of rows
    for (int i = 0; i < g1.numrows(); i++) {
        ASSERT_EQ(g1.numcols(i), 30);  // checking the number of columns
        for (int j = 0; j < g1.numcols(i); j++) {
            EXPECT_FLOAT_EQ(g1(i, j), nums.at(ind));  // checking all the elements
            ind++;
        }
    }
}
// tests the copy constructor of grid using int type
TEST(grid, CopyConstructorInt){
    Grid <int> g1(20, 10);
    Grid <int> g2(g1);  // uses copy constructor on default grid
    EXPECT_EQ(g1.numrows(), g2.numrows());  // checking the number of rows
    for (int k = 0; k < g1.numrows(); k++) {
        EXPECT_EQ(g1.numcols(k), g2.numcols(k));  // checking the number of columns
        for (int l = 0; l < g1.numcols(k); l++) {
            ASSERT_EQ(g1(k, l), g2(k, l));  // checking all the elements
            int random = rand();  // generates a random int and adds to grid
            g1(k, l) = random;
        }
    }
    Grid <int> g3(g1);  // uses the copy constructor on grid with added elements
    EXPECT_EQ(g1.numrows(), g3.numrows());  // checking the number of rows
    for (int i = 0; i < g3.numrows(); i++) {
        EXPECT_EQ(g1.numcols(i), g3.numcols(i));  // checking the number of columns
        for (int j = 0; j < g3.numcols(i); j++) {
            EXPECT_EQ(g1(i,j), g3(i, j));  // checking all the elements
        }
    }
}
// tests the copy constructor of grid using string type
TEST(grid, CopyConstructorString){
    const char alphabets[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 
    'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 
    'v', 'w', 'x', 'y', 'z' };
    Grid <string> g1(47, 78);
    Grid <string> g2(g1);  // uses copy constructor on default grid
    EXPECT_EQ(g1.numrows(), g2.numrows());  // checking the number of rows
    for (int k = 0; k < g1.numrows(); k++) {
        ASSERT_EQ(g1.numcols(k), g2.numcols(k));  // checking the number of columns
        for (int l = 0; l < g1.numcols(k); l++) {
            ASSERT_EQ(g1(k, l), g2(k, l));  // checking all the elements
            string res = "";
            int num = rand() % 7 + 2;  // generates a random integer
            for (int n = 0; n < num; n++) { // generates a random string and adds to grid
                res = res + alphabets[rand() % 26];
            }
            g1(k, l) = res;
        }
    }
    Grid <string> g3(g1);  // uses the copy constructor on grid with added elements
    ASSERT_EQ(g1.numrows(), g3.numrows());  // checking the number of rows
    for (int i = 0; i < g1.numrows(); i++) {
        ASSERT_EQ(g1.numcols(i), g3.numcols(i));  // checking the number of columns
        for (int j = 0; j < g1.numcols(i); j++) {
            EXPECT_NE(g1(i,j), g2(i,j));  // checking all the elements of g2 and g3
            EXPECT_EQ(g1(i, j), g3(i, j));  // elements of g1 and g3 should be equal
        }
    }
}
// tests the copy constructor of grid using double type
TEST(grid, CopyConstructorDouble){
    Grid <double> g1;
    Grid <double> g2(g1);  // uses copy constructor on default grid
    ASSERT_EQ(g1.numrows(), g2.numrows());  // checking the number of rows
    for (int k = 0; k < g1.numrows(); k++) {
        ASSERT_EQ(g1.numcols(k), g2.numcols(k));  // checking the number of columns
        for (int l = 0; l < g1.numcols(k); l++) {
            ASSERT_EQ(g1(k, l), g2(k, l));  // checking all the elements
            double random = (double)rand();  // generates a random double and adds to grid
            g1(k, l) = random;
        }
    }
    Grid <double> g3(g1);  // uses the copy constructor on grid with added elements
    EXPECT_EQ(g1.numrows(), g3.numrows());  // checking the number of rows
    for (int i = 0; i < g1.numrows(); i++) {
        ASSERT_EQ(g1.numcols(i), g3.numcols(i));  // checking the number of columns
        for (int j = 0; j < g1.numcols(i); j++) {
            EXPECT_NE(g3(i, j), g2(i, j));  // checking all the elements of g2 and g3
            EXPECT_EQ(g1(i, j), g3(i, j));  // elements of g1 and g3 should be equal
        }
    }
}
// tests the copy constructor of grid using char type
TEST(grid, CopyConstructorChar){
    // array of alphabets as characters
    const char alphabets[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 
    'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 
    'v', 'w', 'x', 'y', 'z' };
    Grid <char> g1;
    Grid <char> g2(g1);  // uses copy constructor on default grid
    ASSERT_EQ(g1.numrows(), g2.numrows());  // checking the number of rows
    for (int k = 0; k < g2.numrows(); k++) {
        ASSERT_EQ(g1.numcols(k), g2.numcols(k));  // checking the number of columns
        for (int l = 0; l < g2.numcols(k); l++) {
            char c = alphabets[rand() % 26];  // generates a random char and adds to grid
            ASSERT_EQ(g1(k, l), g2(k, l));  // checking all the elements
            g1(k, l) = c;
        }
    }
    Grid <char> g3(g1);  // uses the copy constructor on grid with added elements
    EXPECT_EQ(g1.numrows(), g3.numrows());  // checking the number of rows
    for (int i = 0; i < g1.numrows(); i++) {
        ASSERT_EQ(g1.numcols(i), g3.numcols(i));  // checking the number of columns
        for (int j = 0; j < g1.numcols(i); j++) {
            ASSERT_EQ(g1(i,j), g3(i, j));  // elements of g1 and g3 should be equal
            EXPECT_NE(g2(i, j), g3(i, j));  // checking all the elements of g2 and g3
        }
    }
}
// tests the copy constructor of grid using int type
TEST(grid, CopyConstructorFloat){
    Grid <float> g1(20, 10);
    Grid <float> g2(g1);  // uses copy constructor on default grid
    EXPECT_EQ(g1.numrows(), g2.numrows());  // checking the number of rows
    for (int k = 0; k < g1.numrows(); k++) {
        EXPECT_EQ(g1.numcols(k), g2.numcols(k));  // checking the number of columns
        for (int l = 0; l < g1.numcols(k); l++) {
            ASSERT_EQ(g1(k, l), g2(k, l));  // checking all the elements
            int random = (float)rand();  // generates a random float and adds to grid
            g1(k, l) = random;
        }
    }
    Grid <float> g3(g1);  // uses the copy constructor on grid with added elements
    EXPECT_EQ(g1.numrows(), g3.numrows());  // checking the number of rows
    for (int i = 0; i < g3.numrows(); i++) {
        EXPECT_EQ(g1.numcols(i), g3.numcols(i));  // checking the number of columns
        for (int j = 0; j < g3.numcols(i); j++) {
            EXPECT_FLOAT_EQ(g1(i,j), g3(i, j));  // checking all the elements
        }
    }
}
// tests the copy operator of grid using int type
TEST(grid, CopyOperatorInt){
    Grid <int> g1(27, 11);
    Grid <int> g2 = g1;  // uses copy operator on default grid
    EXPECT_EQ(g1.numrows(), g2.numrows());  // checking the number of rows
    for (int k = 0; k < g1.numrows(); k++) {
        EXPECT_EQ(g1.numcols(k), g2.numcols(k));  // checks the default numcols
        for (int l = 0; l < g1.numcols(k); l++) {
            ASSERT_EQ(g1(k, l), g2(k, l));  // compares the default values
            int random = rand();  // generates a random int and adds to grid
            g1(k, l) = random;
        }
    }
    Grid <int> g3 = g1;  // uses the copy operator on grid with added elements
    EXPECT_EQ(g1.numrows(), g3.numrows());  // checking the number of rows
    for (int i = 0; i < g3.numrows(); i++) {
        EXPECT_EQ(g1.numcols(i), g3.numcols(i));  // checking the number of columns
        for (int j = 0; j < g3.numcols(i); j++) {
            EXPECT_EQ(g1(i,j), g3(i, j));  // checking all the elements
        }
    }
}
// tests the copy operator of grid using string type
TEST(grid, CopyOperatorString){
    // array of letters as characters
    const char alphabets[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 
    'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 
    'v', 'w', 'x', 'y', 'z' };
    Grid <string> g1(47, 78);
    Grid <string> g2 = g1;  // uses copy operator on default grid
    EXPECT_EQ(g1.numrows(), g2.numrows());  // checking the number of rows
    for (int k = 0; k < g1.numrows(); k++) {
        ASSERT_EQ(g1.numcols(k), g2.numcols(k));  // checks the default numcols
        for (int l = 0; l < g1.numcols(k); l++) {
            ASSERT_EQ(g1(k, l), g2(k, l));  // compares the default values
            string res = "";
            int num = rand() % 7 + 2;  // generates a random number between 2 and 7
            for (int n = 0; n < num; n++) {  // generates a random string and adds to grid
                res = res + alphabets[rand() % 26];
            }
            g1(k, l) = res;
        }
    }
    Grid <string> g3 = g1;  // uses the copy operator on grid with added elements
    ASSERT_EQ(g1.numrows(), g3.numrows());
    for (int i = 0; i < g1.numrows(); i++) {  // checking the number of rows
        ASSERT_EQ(g1.numcols(i), g3.numcols(i));  // checks the numcols of g3 and g1
        for (int j = 0; j < g1.numcols(i); j++) {
            EXPECT_NE(g1(i,j), g2(i,j));  // checking if g3 and g2 are not equal
            EXPECT_EQ(g1(i, j), g3(i, j));  // checking if g1 and g3 are equal
        }
    }
}
// tests the copy operator of grid using double type
TEST(grid, CopyOperatorDouble){
    Grid <double> g1;
    Grid <double> g2 = g1;  // uses copy operator on default grid
    ASSERT_EQ(g1.numrows(), g2.numrows());  // checks the default numrows
    for (int k = 0; k < g1.numrows(); k++) {
        ASSERT_EQ(g1.numcols(k), g2.numcols(k));  // checks the default numcols
        for (int l = 0; l < g1.numcols(k); l++) {
            ASSERT_EQ(g1(k, l), g2(k, l));  // compares the default values
            double random = (double)rand();  // generates a random double and adds to grid
            g1(k, l) = random;
        }
    }
    Grid <double> g3 = g1;  // uses the copy operator on grid with added elements
    EXPECT_EQ(g1.numrows(), g3.numrows());  // checking the number of rows
    for (int i = 0; i < g1.numrows(); i++) {
        ASSERT_EQ(g1.numcols(i), g3.numcols(i));  // checks the numcols of g3 and g1
        for (int j = 0; j < g1.numcols(i); j++) {
            EXPECT_NE(g3(i, j), g2(i, j));  // checking if g3 and g2 are not equal
            EXPECT_EQ(g1(i, j), g3(i, j));  // checking if g1 and g3 are equal
        }
    }
}
// tests the copy operator of grid using char type
TEST(grid, CopyOperatorChar){
    // array containing letters as characters
    const char alphabets[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 
    'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u', 
    'v', 'w', 'x', 'y', 'z' };
    Grid <char> g1;
    Grid <char> g2 = g1;  // uses the copy operator on a default grid
    ASSERT_EQ(g1.numrows(), g2.numrows());  // checks the numrows of default
    for (int k = 0; k < g2.numrows(); k++) {
        ASSERT_EQ(g1.numcols(k), g2.numcols(k));  // checks the numcols of default
        for (int l = 0; l < g2.numcols(k); l++) {
            ASSERT_EQ(g1(k, l), g2(k, l));  // checks the default contents
            char c = alphabets[rand() % 26];  // generating a random char and adding to grid
            g1(k, l) = c;
        }
    }
    Grid <char> g3 = g1;  // uses the copy operator on grid with added elements
    EXPECT_EQ(g1.numrows(), g3.numrows());  // checking the number of rows
    for (int i = 0; i < g1.numrows(); i++) {
        ASSERT_EQ(g1.numcols(i), g3.numcols(i));
        for (int j = 0; j < g1.numcols(i); j++) {
            ASSERT_EQ(g1(i,j), g3(i, j));  // checking if g1 equals g3
            EXPECT_NE(g2(i, j), g3(i, j));  // checking if g2 is != g3
        }
    }
}
// tests the copy operator of grid using float type
TEST(grid, CopyOperatorFloat){
    Grid <float> g1(34, 9);
    Grid <float> g2 = g1;  // uses the copy operator on grid with default elements
    EXPECT_EQ(g1.numrows(), g2.numrows());  // checking the numrows of default
    for (int k = 0; k < g1.numrows(); k++) {
        EXPECT_EQ(g1.numcols(k), g2.numcols(k));  // checking the numcols of default
        for (int l = 0; l < g1.numcols(k); l++) {
            ASSERT_EQ(g1(k, l), g2(k, l));  // checking the default values
            int random = (float)rand();  // adding random float numbers into the grid
            g1(k, l) = random;
        }
    }
    Grid <float> g3 = g1;  // uses the copy operator on grid with elements
    EXPECT_EQ(g1.numrows(), g3.numrows());  // checking the number of rows
    for (int i = 0; i < g3.numrows(); i++) {
        EXPECT_EQ(g1.numcols(i), g3.numcols(i));  // checking the number of columns
        for (int j = 0; j < g3.numcols(i); j++) {
            EXPECT_FLOAT_EQ(g1(i,j), g3(i, j));  // checking all the elements
        }
    }
}
// tests the numrows function of the grid using all types
TEST(grid, NumRows) {
    Grid <int> g(67, 90);
    Grid <string> g1(10, 400);
    Grid <char> g2(42, 60);
    Grid <double> g3(600, 5);
    Grid <float> g4(35, 54);
    // checks if the grids have the given number of rows
    EXPECT_EQ(g.numrows(), 67);
    EXPECT_EQ(g1.numrows(), 10);
    EXPECT_EQ(g2.numrows(), 42);
    EXPECT_EQ(g3.numrows(), 600);
    EXPECT_EQ(g4.numrows(), 35);
}
// tests the numcols function of the grid using all types
TEST(grid, NumCols) {
    Grid <int> g(67, 90);
    Grid <string> g1(112, 46);
    Grid <char> g2(37, 22);
    Grid <double> g3(600, 5);
    Grid <float> g4(56, 500);
    // checks if every column has the assigned size
    for (int i = 0; i < g.numrows(); i++) {
        EXPECT_EQ(g.numcols(i), 90);
    }
    for (int j = 0; j < g1.numrows(); j++) {
        EXPECT_EQ(g1.numcols(j), 46);
    }
    for (int k = 0; k < g2.numrows(); k++) {
        EXPECT_EQ(g2.numcols(k), 22);
    }
    for (int l = 0; l < g3.numrows(); l++) {
        EXPECT_EQ(g3.numcols(l), 5);
    }
     for (int t = 0; t < g4.numrows(); t++) {
        EXPECT_EQ(g4.numcols(t), 500);
    }
}
// tests the size function of the grid
TEST(grid, Size) {
    Grid <int> g(45, 90);
    Grid <string> g1(28, 200);
    Grid <char> g2(33, 77);
    Grid <double> g3(99,100);
    Grid <float> g4(999, 999);
    // checks if the size function returns the right size
    ASSERT_EQ(g.size(), 45 * 90);
    ASSERT_EQ(g1.size(), 28 * 200);
    ASSERT_EQ(g2.size(), 33 *77);
    ASSERT_EQ(g3.size(), 99 * 100);
    ASSERT_EQ(g4.size(), 999 * 999);
}
// tests the exception when invalid operator indices are used
TEST(grid, OperatorInvalid) {
    try {
        Grid <int>  g1;  
        g1(5, 5) = 2;  // indices are greater than the size which is 4
        Grid <string> g2(10, 4); 
        g2(-1,-1) = "WRONG";  // indices are less than 0 which is invalid
        Grid <double> g3(1, 30);
        g3(2, -1) = 27.4;  // indices are either greater than size or less than 0
        EXPECT_TRUE(false);  // exception was NOT thrown
    } catch (const exception& e) {
        EXPECT_TRUE(true);  // exception was thrown
    }
}
// Provided Test: sample maze from handout, make lots more yourself!
TEST(maze, basic) {
    vector<string> textMaze;
    // created a regular maze
    textMaze.push_back("* *-W *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("S *-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-* P");

    Maze m(textMaze);
    MazeCell* start = m.getStart(2, 2);

    /* These paths are the ones in the handout. They all work. */
    EXPECT_TRUE(isPathToFreedom(start, "ESNWWNNEWSSESWWN"));
    EXPECT_TRUE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES"));
    EXPECT_TRUE(isPathToFreedom(start, "WNNEWSSESWWNSEENES"));

    /* These paths don't work, since they don't pick up all items. */
    EXPECT_FALSE(isPathToFreedom(start, "ESNW"));
    EXPECT_FALSE(isPathToFreedom(start, "SWWN"));
    EXPECT_FALSE(isPathToFreedom(start, "WNNE"));

    /* These paths don't work, since they aren't legal paths. */
    EXPECT_FALSE(isPathToFreedom(start, "WW"));
    EXPECT_FALSE(isPathToFreedom(start, "NN"));
    EXPECT_FALSE(isPathToFreedom(start, "EE"));
    EXPECT_FALSE(isPathToFreedom(start, "SS"));
}
// Provided Test: don't allow going through walls
TEST(maze, tryingToGoThroughWalls) {
    vector<string> textMaze;
    // created a small maze
    textMaze.push_back("* S *");
    textMaze.push_back("     ");
    textMaze.push_back("W * P");
    textMaze.push_back( "     ");
    textMaze.push_back( "* * *");

    Maze m(textMaze);
    MazeCell* start = m.getStart(1, 1);
    // checks if the function returns false when an invalid instruction is given
    EXPECT_FALSE(isPathToFreedom(start, "WNEES"));
    EXPECT_FALSE(isPathToFreedom(start, "NWSEE"));
    EXPECT_FALSE(isPathToFreedom(start, "ENWWS"));
    EXPECT_FALSE(isPathToFreedom(start, "SWNNEES"));
}

// Provided Test: Works when starting on an item
TEST(maze, startOnItem) {
    vector<string> textMaze;
    textMaze.push_back("P-S-W");
    
    Maze m(textMaze);
    MazeCell* start = m.getStart(0, 0);
    // checks if the function collects items when we start on an item.
    EXPECT_TRUE(isPathToFreedom(start, "EE"));
    start = m.getStart(0, 1);
    EXPECT_TRUE(isPathToFreedom(start, "WEE"));
    start = m.getStart(0, 2);
    EXPECT_TRUE(isPathToFreedom(start, "WW"));
}
// Test to check when path is invalid after collecting items
TEST(maze, invalidPathAfterCollecting) {
    vector<string> textMaze;
    // created a random maze
    textMaze.push_back("*-*-W-*");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("    | |");
    textMaze.push_back("* *-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("S-*-* P");
    
    Maze m(textMaze);
    
    MazeCell* start = m.getStart(1, 2);
    /* This path collect the items but make an invalid move after starting in the middle */
    EXPECT_FALSE(isPathToFreedom(start, "SESNWSWWEENENNWN"));
    /* This path collect the items but make an invalid move after starting in the corner */
    start = m.getStart(0, 0);
    EXPECT_FALSE(isPathToFreedom(start, "EEESSSNWSWWNN"));
    /* This path collect the items but make an invalid move after starting in the edge */
    start = m.getStart(1, 3);
    EXPECT_FALSE(isPathToFreedom(start, "NWESSSNWSWWEEE"));
}
// Test to check if I escape a big maze
TEST(maze, bigMaze) {
    // created a big maze
    vector<string> textMaze;
    textMaze.push_back("*-*-W-*-*");
    textMaze.push_back("      |  ");
    textMaze.push_back("*-*-* *-*");
    textMaze.push_back("    |   |");
    textMaze.push_back("S *-*-* *");
    textMaze.push_back("|   | | |");
    textMaze.push_back("*-*-* * *");
    textMaze.push_back("  |   | |");
    textMaze.push_back("*-*-*-P-*");
    
    Maze m(textMaze);
    
    /* These paths collect the items but take a long path */
    MazeCell* start = m.getStart(2, 2);  // starts in the middle
    EXPECT_TRUE(isPathToFreedom(start, "SWWNSESEEENNNWNWEWEWEWEWEWE"));
    
    start = m.getStart(4,4);  // starts in the corner
    EXPECT_TRUE(isPathToFreedom(start, "NNNWNWESESSSWNNWSWSWENWN"));
    
    start = m.getStart(3,0); // starts on the edge
    EXPECT_TRUE(isPathToFreedom(start, "NSEENNSESSWWWEEEENNNWNEWWW"));
}
// Test to check with skinnyMaze
TEST(maze, skinnyMaze) {
    vector<string> textMaze;
    // created a skinny maze
    textMaze.push_back("W-*-*");
    textMaze.push_back("    |");
    textMaze.push_back("*-*-*");
    textMaze.push_back("  |  ");
    textMaze.push_back("S *-*");
    textMaze.push_back("|   |");
    textMaze.push_back("*-*-*");
    textMaze.push_back("  |  ");
    textMaze.push_back("*-*-P");
    
    Maze m(textMaze);
    
    /* These paths collect the items in skinny maze */
    MazeCell* start = m.getStart(2, 1);  // starts in the middle
    EXPECT_TRUE(isPathToFreedom(start, "NENWWEESWSESWWNSESE"));
    
    start = m.getStart(0,2);  // starts in the corner
    EXPECT_TRUE(isPathToFreedom(start, "WWEESWSESWWNSESE"));
    
    start = m.getStart(2,0); // starts on the edge
    EXPECT_TRUE(isPathToFreedom(start, "SESEWNENWNENWW"));
}
// Provided Test: This tests your personalized regular maze to see if you were
// able to escape.
TEST(maze, escapeRegularMaze) {
    Maze m(4, 4);
    MazeCell* start = m.mazeFor(kYourName);
    EXPECT_TRUE(isPathToFreedom(start, kPathOutOfRegularMaze));
}
// Provided Test: This tests your personalized twisty maze to see if you were
// able to escape.
TEST(maze, escapeTwistyMaze) {
    Maze m(4, 4);
    MazeCell* start = m.twistyMazeFor(kYourName);
    EXPECT_TRUE(isPathToFreedom(start, kPathOutOfTwistyMaze));
}
