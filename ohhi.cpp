/**
 * ohhi.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 *
 * <Mish Jude>
 * <mishmish>
 *
 * <Functions definitions to run the game, 0h h1>
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"



/**
 * --------------------------------------------------------
 * ---------- UTILITY FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    int unknownNum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == UNKNOWN) {
                unknownNum++;
            }
        }
    }
    return unknownNum;
}


/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    
    bool threeInRow = true;

    if (size == 2) {
        return true;
    }

    int i = row;
    for (int j = 0; j < size - 2; j++) {
        if (threeInRow == true) {
            if ((board[i][j] == color) && (board[i][j + 1] == color) && (board[i][j + 2] == color)) {
                threeInRow = false;
            }
            else {
                threeInRow = true;
            }
        }
    }
    return threeInRow;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    
    bool threeInCol = true;
    
    if (size == 2) {
        return true;
    }

    int i = col;
    for (int j = 0; j < size - 2; j++) {
        if (threeInCol == true) {
            if ((board[j][i] == color) && (board[j + 1][i] == color) && (board[j + 2][i] == color)) {
                threeInCol = false;
            }
            else {
                threeInCol = true;
            }
        }
    }
    return threeInCol;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        if ((!row_has_no_threes_of_color(board, size, i, RED) || (!row_has_no_threes_of_color(board, size, i, BLUE)))) {
            return false;
        }
        if ((!col_has_no_threes_of_color(board, size, i, RED)) || (!col_has_no_threes_of_color(board, size, i, BLUE))) {
            return false;
        }
        
    }
    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {

    for (int i = 0; i < size; i++) {
        if (board[row1][i] == UNKNOWN) {
            return true;
        }
        else if (board[row1][i] != board[row2][i]) {
            return true;
        }
    }
    return false;
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    for (int i = 0; i < size; i++) {
        if (board[i][col1] == UNKNOWN) {
            return true;
        } else if (board[i][col1] != board[i][col2]) {
            return true;
        }
     
    }
    return false;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((!rows_are_different(board, size, i, j)) || (!cols_are_different(board, size, i, j))) {
                return false;
            }
        }
    }

    return true;
}


/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

 void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    
    for (int i = 0; i < size; i++) {
        if (i < size - 2 && board[row][i] == board[row][i + 2]) {
            //if two sandwiched are red (X-X) 
            if (board[row][i + 1] == UNKNOWN && board[row][i] == RED) {
                mark_square_as(board, size, row, i + 1, opposite_color(RED), announce);
            }
            //if two sandwiched together are blue (O-O)
            else if (board[row][i + 1] == UNKNOWN && board[row][i] == BLUE) {
                mark_square_as(board, size, row, i + 1, opposite_color(BLUE), announce);
            }
        }
        //if two red are adjacent 
        if (i < size - 1 && board[row][i] == board[row][i + 1] && board[row][i] == RED) {
            if (board[row][i - 1] == UNKNOWN && i != 0) {
                mark_square_as(board, size, row, i - 1, opposite_color(RED), announce);
            }
            if (board[row][i + 2] == UNKNOWN && (i != size - 2)) {
                mark_square_as(board, size, row, i + 2, opposite_color(RED), announce);
            }
        }
        //if two blue are adjacent
        else if (i < size - 1 && board[row][i] == board[row][i + 1] && board[row][i] == BLUE) {
            if (board[row][i - 1] == UNKNOWN && i != 0) {
                mark_square_as(board, size, row, i - 1, opposite_color(BLUE), announce);
            }
            if (board[row][i + 2] == UNKNOWN && (i != size - 2)) {
                mark_square_as(board, size, row, i + 2, opposite_color(BLUE), announce);
            }
            
        }
    }
} 

 void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {

    for (int i = 0; i < size; i++) {
        //if two red are sandwiched
        if ((i < size - 2) && (board[i][col] == board[i + 2][col])) {
            if (board[i + 1][col] == UNKNOWN && board[i][col] == RED) {
                mark_square_as(board, size, i + 1, col, opposite_color(RED), announce);
            }
            if (board[i + 1][col] == UNKNOWN && board[i][col] == BLUE) {
                mark_square_as(board, size, i + 1, col, opposite_color(BLUE), announce);
            }
        }
        //if two red are adjacent
        if (i < size - 1 && (board[i][col] == board[i + 1][col]) && board[i][col] == RED) {
            if (board[i - 1][col] == UNKNOWN && i != 0) {
                mark_square_as(board, size, i - 1, col, opposite_color(RED), announce);
            }
            if (board[i + 2][col] == UNKNOWN && i != size - 2) {
                mark_square_as(board, size, i + 2, col, opposite_color(RED), announce);
            }
        }
        //if two blue are adjacent
        else if (i < size - 1 && (board[i][col] == board[i + 1][col]) && board[i][col] == BLUE) {
            if (board[i - 1][col] == UNKNOWN && i != 0) {
                mark_square_as(board, size, i - 1, col, opposite_color(BLUE), announce);
            }
            if (board[i + 2][col] == UNKNOWN && i != size - 2) {
                mark_square_as(board, size, i + 2, col, opposite_color(BLUE), announce);
            }
        }
    }
    return;
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    int countRed = 0;
    int countBlue = 0;
    for (int i = 0; i < size; i++) {
        //count number of each color in row
        if (board[row][i] == RED) {
            countRed++;
        }
        else if (board[row][i] == BLUE) {
            countBlue++;
        }
    }

    if (countRed == (size / 2)) {
        for (int i = 0; i < size; i++) {
            if (board[row][i] == UNKNOWN) {
                announce = true;
                mark_square_as(board, size, row, i, opposite_color(RED), announce);
            }
        }
    }
    
    if (countBlue == (size / 2)) {
        for (int i = 0; i < size; i++) {
            if (board[row][i] == UNKNOWN) {
                announce = true;
                mark_square_as(board, size, row, i, opposite_color(BLUE), announce);
            }
        }
    }
   
    return;
   
} 

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    int countRed = 0;
    int countBlue = 0;
    for (int i = 0; i < size; i++) {
        //count number of each color in column
        if (board[i][col] == RED) {
            countRed++;
        }
        else if (board[i][col] == BLUE) {
            countBlue++;
        }
    }

    if (countRed == (size / 2)) {
        for (int i = 0; i < size; i++) {
            if (board[i][col] == UNKNOWN) {
                announce = true;
                mark_square_as(board, size, i, col, opposite_color(RED), announce);
            }
        }
    }
    else if (countRed > (size / 2)) {
        announce = false;
    }
    if (countBlue == (size / 2)) {
        for (int i = 0; i < size; i++) {
            if (board[i][col] == UNKNOWN) {
                announce = true;
                mark_square_as(board, size, i, col, opposite_color(BLUE), announce);
            }
        }
    }
    else if (countRed > (size / 2)) {
        announce = false;
    }

    return;
}


/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    if (count_unknown_squares(board, size) != 0) {
        return false;
    }
    else if (board_is_valid(board, size) == false) {
        return false;
    }
    else {
        return true;
    }
}

bool check_valid_input(int size, int row_input, char col_input,
    char color_char, int& row, int& col) {

    const int A_UPPERCASE = 65;
    const int A_LOWERCASE = 97;
    bool valid_input = false;

    color_char = toupper(color_char);

    if (row_input > 0 && row_input <= size) {
        if (color_char == RED_LETTER || color_char == BLUE_LETTER || color_char == UNKNOWN_LETTER) {
            if (col_input >= 'a' && col_input <= ('a' + size - 1)) {
                row = row_input - 1;
                col = (static_cast<int>(col_input) - A_LOWERCASE);
                valid_input = true;
            }
            else if (col_input >= toupper('a') && col_input <= (toupper('a') + size - 1)) {
                row = row_input - 1;
                col = (static_cast<int>(col_input) - A_UPPERCASE);
                valid_input = true;
            }
            else {
                cout << "Sorry, that's not a valid input." << endl;
                valid_input = false;
            }
        }
        else {
            cout << "Sorry, that's not a valid input." << endl;
            valid_input = false;
        }
    }
    else {
        cout << "Sorry, that's not a valid input." << endl;
        valid_input = false;
    }
    return valid_input;
}



bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
    const int current_board[MAX_SIZE][MAX_SIZE],
    int size, int row, int col, int color) {

    if (original_board[row][col] == RED || original_board[row][col] == BLUE) {
        cout << "Sorry, original squares cannot be changed." << endl;
        return false;
    }
    else {
        int copy[MAX_SIZE][MAX_SIZE];
        copy_board(current_board, copy, size);
        copy[row][col] = color;

        if (!board_is_valid(copy, size)) {
            cout << "Sorry, that move violates a rule." << endl;
            return false;
        }
        else {
            return true;
        }
    }
}    


