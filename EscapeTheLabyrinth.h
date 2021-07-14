/**
 * @file: EscapeTheLabyrinth.h
 *
 * @description: Program contains the function to check if the given path collects the spellbook, potion and wand from the maze to escape.
 *
 * Code Written by
 * @author: Sai Samarth Patipati Umesh
 * U. of Illinois, Chicago
 * @date: 03/2/21
 *
 */
#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;
/* Change this constant to contain your full first and last name (middle is ok too).
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
const string kYourName = "Sai Samarth Patipati Umesh";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "SSEENWNSENSSENN";  // solution of the regular maze
const string kPathOutOfTwistyMaze = "NEWWEWSWENN";  // solution of the twisty maze
//
// helper function: checkWhatsHere()
// parameter: bool potion, spellbook, wand and blank passed by
// reference and the MazeCell curr pointer
// Function checks if the current mazecell has a spellbook, wand or potion and updates the
// respective bool variable to reflect that.
//
void checkWhatsHere(bool& potion, bool& spellbook, bool& wand, MazeCell* curr) {
    if (curr->whatsHere == "Potion") {  // checks for potion
        potion = true;
    } else if (curr->whatsHere == "Spellbook") {  // checks for spellbook
        spellbook = true;
    } else if (curr->whatsHere == "Wand") {  // checks for wand
        wand = true;
    }
}
//
// function: isPathToFreedom()
// parameters: MazeCell* start and the string containing moves 
// Function checks if the given path exits the maze by picking a potion, spellbook and wand.
// It also makes sure that the path doesn't get out of bounds.
// If it does then the path is invalid.
//
bool isPathToFreedom(MazeCell *start, const string& moves) {
    MazeCell* curr = start;  // temporary pointer to hold the current mazecell
    // bool variables to hold the status of the things in the maze
    bool potion = false;
    bool spellbook = false;
    bool wand = false;
    bool success = false;
    checkWhatsHere(potion, spellbook, wand, curr);  // checks if the starting cell has any things
    // looping through the solution string
    for (const char& s : moves) {
        if (s == 'N' && curr->north != nullptr) {  // checks if the move is north and if it's valid
            curr = curr -> north;
            checkWhatsHere(potion, spellbook, wand, curr);  // checks if the north cell has any things
        } else if (s == 'S' && curr->south != nullptr) {  // checks if the move is south and if it's valid
            curr = curr -> south;
            checkWhatsHere(potion, spellbook, wand, curr);  // checks if the south cell has any things
        } else if (s == 'W' && curr->west != nullptr) {  // checks if the move is west and if it's valid
            curr = curr -> west;
            checkWhatsHere(potion, spellbook, wand, curr);  // checks if the west cell has any things
        } else if (s == 'E' && curr->east != nullptr) {  // checks if the move is east and if it's valid
            curr = curr -> east;
            checkWhatsHere(potion, spellbook, wand, curr);  // checks if the east cell has any things
        } else {
            return false;
        }
    }
    if (potion && wand && spellbook) {  // checks if all the things were found.
        success = true;  // exited the maze successfully
    }
    return success;
}
