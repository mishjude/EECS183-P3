/**
 * test.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 *
 * <Mish Jude>
 * <mishmish>
 *
 * <Test functions to ensure the functions defined in ohhi.cpp are working as expected>
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void solve_balance_column();
void test_board_is_solved();
void test_check_valid_input();
void test_check_valid_move();

// declare more test functions here

void startTests() {
    test_count_unknown_squares();
    test_row_has_no_threes_of_color();
    test_col_has_no_threes_of_color();
    test_board_has_no_threes();
    test_rows_are_different();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_solve_balance_row();
    solve_balance_column();
    test_board_is_solved();
    test_check_valid_input();
    test_check_valid_move();

    // add your calls to test functions here
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    cout << "Begin testing count_unknown_squares()" << endl;

    // test case #1
    string test_board_1[] = {"XOXO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 8, actual: " << count_unknown_squares(board, size_1) << endl;

    // test case #2
    string test_board_2[] = {"-X---X",
                            "------",
                            "---XX-",
                            "X----X",
                            "-O-OX-",
                            "---O--" };
    int size_2 = 6;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 26, actual: " << count_unknown_squares(board, size_2) << endl;

    // test case #3
    string test_board_3[] = {"XXOO",
                             "OXXO",
                             "XOOX",
                             "OOXX"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 0, actual: " << count_unknown_squares(board, size_3) << endl;

    cout << "Finished testing count_unknown_squares()" << endl<< endl;
    
}

void test_row_has_no_threes_of_color() {
    
    
    cout << "Begin testing row_has_no_threes_of_color()" << endl;

    //test case #1 
    int board1[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = { "XOXO",
                             "-OOO",
                             "---X",
                             "--O-" };
    int size_1 = 4;
    read_board_from_string(board1, test_board_1, size_1);
    cout << "Expected: 0, actual: " << row_has_no_threes_of_color(board1, size_1, 1, BLUE) << endl;  

    //test case #2
    string test_board_2[] = { "XXXO",
                             "--OO",
                             "---X",
                             "--O-" };
    int size_2 = 4;
    read_board_from_string(board1, test_board_2, size_2);
    cout << "Expected: 0, actual: " << row_has_no_threes_of_color(board1, size_2, 0, RED) << endl;

    //test case #3 
    string test_board_3[] = { "XOXO",
                             "--OO",
                             "---X",
                             "OOO-" };
    int size_3 = 4;
    read_board_from_string(board1, test_board_3, size_3);
    cout << "Expected: 0, actual: " << row_has_no_threes_of_color(board1, size_3, 3, BLUE) << endl;

    //test case #4 
    string test_board_4[] = { "XOXO",
                             "--OO",
                             "-XXX",
                             "--O-" };
    int size_4 = 4;
    read_board_from_string(board1, test_board_4, size_4);
    cout << "Expected: 0, actual: " << row_has_no_threes_of_color(board1, size_4, 2, RED) << endl;

    //test case #5
    string test_board_5[] = { "XOXO",
                            "--OO",
                            "-X-X",
                            "--O-" };
    int size_5 = 4;
    read_board_from_string(board1, test_board_5, size_5);
    cout << "Expected: 1, actual: " << row_has_no_threes_of_color(board1, size_4, 2, RED) << endl;

    cout << "Finished testing row_has_no_threes_of_color()" << endl << endl;
}

void test_col_has_no_threes_of_color() {

    cout << "Begin testing col_has_no_threes_of_color()" << endl;

    //test case #1 
    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"XOXO",
                             "--OO",
                             "---O",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 0, actual: " << col_has_no_threes_of_color(board, size_1, 3, BLUE) << endl;

    //test case #2
    string test_board_2[] = {"X---",
                             "X-OO",
                             "X--X",
                             "--O-" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 0, actual: " << col_has_no_threes_of_color(board, size_2, 0, RED) << endl;

    //test case #3 
    string test_board_3[] = {"X---",
                             "-O-O",
                             "-O-X",
                             "OOO-" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 0, actual: " << col_has_no_threes_of_color(board, size_3, 1, BLUE) << endl;

    //test case #4 
    string test_board_4[] = {"XOXO",
                             "--XO",
                             "--XX",
                             "--O-" };
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: 0, actual: " << col_has_no_threes_of_color(board, size_4, 2, RED) << endl;

    //test case #5
    string test_board_5[] = {"XOXO",
                             "--OO",
                             "-X-X",
                             "--O-" };
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << "Expected: 1, actual: " << col_has_no_threes_of_color(board, size_4, 2, RED) << endl;

    cout << "Finished testing col_has_no_threes_of_color()" << endl << endl;
}

void test_board_has_no_threes() {
   
    cout << "Begin testing board_has_no_threes()" << endl;

    int board[MAX_SIZE][MAX_SIZE];

    //test case #1
    string test_board_1[] = {"XOXO",
                             "--OO",
                             "-X-X",
                             "--O-" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 1, actual: " << board_has_no_threes(board, size_1) << endl;

    //test case #2
    string test_board_2[] = {"XOOO",
                             "--OO",
                             "-X-X",
                             "----" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 0, actual: " << board_has_no_threes(board, size_2) << endl;

    //test case #3
    string test_board_3[] = {"X-OO",
                             "--OO",
                             "-X-O",
                             "----" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 0, actual: " << board_has_no_threes(board, size_3) << endl;

    //test case #4
    string test_board_4[] = {"X-OO",
                             "--OO",
                             "XXXO",
                             "----" };
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: 0, actual: " << board_has_no_threes(board, size_4) << endl;

    cout << "Finished testing board_has_no_threes()" << endl << endl;
}

void test_rows_are_different() {

    cout << "Begin testing rows_are_different()" << endl;

    int board[MAX_SIZE][MAX_SIZE];

    //test case #1
    string test_board_1[] = {"X-OO",
                             "--O-",
                             "-X-O",
                             "----" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 1, actual: " << rows_are_different(board, size_1, 0, 1) << endl;

    //test case #2
    string test_board_2[] = {"XXOO",
                             "XXOO",
                             "-X-O",
                             "----" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 0, actual: " << rows_are_different(board, size_2, 0, 1) << endl;

    //test case #3
    string test_board_3[] = {"X-OO",
                             "--O-",
                             "-X-O",
                             "X-OO" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 1, actual: " << rows_are_different(board, size_3, 0, 3) << endl;

    //test case #4
    string test_board_4[] = {"X-O-",
                             "----",
                             "-X-O",
                             "----" };
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: 1, actual: " << rows_are_different(board, size_4, 1, 3) << endl;

    //test case #5
    string test_board_5[] = {"X-O-",
                             "----",
                             "X-O-",
                             "----" };
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << "Expected, 1, actual: " << rows_are_different(board, size_5, 0, 2) << endl;

    cout << "Finished testing rows_are_different()" << endl << endl;
}

void test_cols_are_different() {

    cout << "Begin testing cols_are_different()" << endl;

    int board[MAX_SIZE][MAX_SIZE];

    //test case #1
    string test_board_1[] = {"X-OO",
                             "--O-",
                             "-X-O",
                             "----" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 1, actual: " << cols_are_different(board, size_1, 0, 1) << endl;

    //test case #2
    string test_board_2[] = {"XXOO",
                             "OO--",
                             "XX--",
                             "OO--" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 0, actual: " << cols_are_different(board, size_2, 0, 1) << endl;

    //test case #3
    string test_board_3[] = {"-XO-",
                             "-O--",
                             "-X--",
                             "-O--" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 1, actual: " << cols_are_different(board, size_3, 0, 3) << endl;

    //test case #4
    string test_board_4[] = {"-XX-",
                             "-OO-",
                             "-XX-",
                             "-OO-" };
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: 0, actual: " << cols_are_different(board, size_4, 1, 2) << endl;

    //test case #5
    string test_board_5[] = {"-XX-",
                             "-OO-",
                             "-XX-",
                             "-OO-" };
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << "Expected: 1, actual: " << cols_are_different(board, size_5, 1, 3) << endl;

    cout << "Finished testing cols_are_different()" << endl << endl;
}

void test_board_has_no_duplicates() {

    cout << "Begin testing board_has_no_duplicates()" << endl;

    int board[MAX_SIZE][MAX_SIZE];

    //test case #1 
    string test_board_1[] = {"X-OO",
                             "--O-",
                             "-X-O",
                             "----" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 1, actual: " << board_has_no_duplicates(board, size_1) << endl;

    //test case #2
    string test_board_2[] = {"----",
                             "OO--",
                             "----",
                             "OO--" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 1, actual: " << board_has_no_duplicates(board, size_2) << endl;

    //test case #3
    string test_board_3[] = {"-XO-",
                             "-O--",
                             "-X--",
                             "-O--" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 1, actual: " << board_has_no_duplicates(board, size_3) << endl;

    //test case #4
    string test_board_4[] = {"-XX-",
                             "XOOX",
                             "-XX-",
                             "XOOX" };
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: 0, actual: " << board_has_no_duplicates(board, size_4) << endl;

    //test case #5
    string test_board_5[] = {"--X-",
                             "XOOX",
                             "--X-",
                             "XOOX" };
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << "Expected: 0, actual: " << board_has_no_duplicates(board, size_5) << endl;

    cout << "Finished testing board_has_no_duplicates()" << endl << endl;
}

void test_solve_three_in_a_row() {

    cout << "Begin testing solve_three_in_a_row()" << endl;

    int board[MAX_SIZE][MAX_SIZE];

    //test case #1
    string test_board_1[] = {"--X-",
                             "X-X-",
                             "----",
                             "XOOX" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: marking (2, B) as O, actual: ";
    solve_three_in_a_row(board, size_1, 1, true);
    
    //test case #2
    string test_board_2[] = {"--X-",
                             "XX--",
                             "----",
                             "XOOX" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: marking (2, C) as O, actual: ";
    solve_three_in_a_row(board, size_2, 1, true);

    //test case #3
    string test_board_3[] = {"--XX",
                             "X---",
                             "----",
                             "XOOX" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: marking (1, B) as O, actual: ";
    solve_three_in_a_row(board, size_3, 0, true);

    //test case #4
    string test_board_4[] = {"--X-",
                             "X---",
                             "--OO",
                             "XOOX" };
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: marking (3, B) as X, actual: ";
    solve_three_in_a_row(board, size_4, 2, true);

    //test case #5
    string test_board_5[] = {"--X-",
                             "X---",
                             "-O-O",
                             "XOOX" };
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << "Expected: marking (3, C) as X, actual: ";
    solve_three_in_a_row(board, size_5, 2, true);
    cout << "Finished testing solve_three_in_a_row()" << endl << endl;
}

void test_solve_three_in_a_column() {
    cout << "Begin testing solve_three_in_a_column()" << endl;

    int board[MAX_SIZE][MAX_SIZE];

    //test case #1
    string test_board_1[] = {"--X-",
                             "X---",
                             "----",
                             "XOOX" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: marking (3, A) as O, actual: ";
    solve_three_in_a_column(board, size_1, 0, true);

    //test case #2
    string test_board_2[] = {"--X-",
                             "-X--",
                             "---X",
                             "XOOX" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: marking (2,D) as O, actual: ";
    solve_three_in_a_column(board, size_2, 3, true);

    //test case #3
    string test_board_3[] = {"--X-",
                             "-O--",
                             "-O--",
                             "X---" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: marking (1, B) as X, marking (4, B) as X,  actual: ";
    solve_three_in_a_column(board, size_3, 1, true);

    //test case #4
    string test_board_4[] = {"--X-",
                             "XO--",
                             "----",
                             "XOOX" };
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: marking (3, B) as X, actual: ";
    solve_three_in_a_column(board, size_4, 1, true);

    //test case #5
    string test_board_5[] = {"--X-",
                             "X--O",
                             "-O-O",
                             "XOO-" };
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << "Expected: marking (4, D) as X, marking (1, D) as X,  actual: ";
    solve_three_in_a_column(board, size_5, 3, true);

    cout << "Finished testing solve_three_in_a_column()" << endl << endl;
}

void test_solve_balance_row() {
    cout << "Begin testing solve_balance_row()" << endl;

    int board[MAX_SIZE][MAX_SIZE];

    //test case #1
    string test_board_1[] = {"--X-",
                             "X---",
                             "----",
                             "X--X" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: marking (4, B) as O, marking (4, C) as O, actual: ";
    solve_balance_row(board, size_1, 3, true);

    //test case #2
    string test_board_2[] = {"O-O-",
                             "-X--",
                             "---X",
                             "XOOX" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: marking (1, B) as X, marking (1, D) as X, actual: ";
    solve_balance_row(board, size_2, 0, true);

    //test case #3
    string test_board_3[] = {"-XXX",
                             "-O--",
                             "-O--",
                             "X---" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected:  , actual: ";
    solve_balance_row(board, size_3, 0, false);

    cout << endl;

    //test case #4
    string test_board_4[] = {"-O-O",
                             "XOX-",
                             "----",
                             "XOOX" };
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: marking (2, D) as O, actual: ";
    solve_balance_row(board, size_4, 1, true);

    //test case #5
    string test_board_5[] = {"----",
                             "X--O",
                             "----",
                             "-OOX" };
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << "Expected: marking (4, A) as X,  actual: ";
    solve_balance_row(board, size_5, 3, true);

    cout << "Finished testing solve_balance_row()" << endl << endl;
    
}
void solve_balance_column() {
    cout << "Begin testing solve_balance_column()" << endl;
    int board[MAX_SIZE][MAX_SIZE];

    //test case #1
    string test_board_1[] = {"--X-",
                             "X---",
                             "----",
                             "X--X" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: marking (1, A) as O, marking (3, A) as O, actual: ";
    solve_balance_column(board, size_1, 0, true);

    //test case #2
    string test_board_2[] = {"O-O-",
                             "-X--",
                             "---X",
                             "XOOX" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: marking (1, D) as O, marking (2, D) as O, actual: ";
    solve_balance_column(board, size_2, 3, true);

    //test case #3
    string test_board_3[] = {"-X-X",
                             "-O--",
                             "-O--",
                             "X---" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: marking (4, B) as X, actual: ";
    solve_balance_column(board, size_3, 1, true);

    //test case #4
    string test_board_4[] = {"-O-O",
                             "XOX-",
                             "X---",
                             "X--X" };
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: , actual: ";
    solve_balance_column(board, size_4, 0, false);

    cout << endl;

    //test case #5
    string test_board_5[] = {"-O--",
                             "XO-O",
                             "----",
                             "-OOX" };
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << "Expected: ,  actual: ";
    solve_balance_column(board, size_5, 1, false);
    
    cout << endl;

    cout << "Finished testing solve_balance_column()" << endl << endl;
}

void test_board_is_solved() {
    cout << "Begin testing board_is_solved()" << endl;

    int board[MAX_SIZE][MAX_SIZE];

   
    //test case #1
    string test_board_1[] = {"XO-X",
                             "OXOX",
                             "--XO",
                             "XOXO" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 0, actual: " << board_is_solved(board, size_1) << endl;

    //test case #2
    string test_board_2[] = {"XXOX",
                             "OXOX",
                             "OXXO",
                             "XOXO" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 0, actual: " << board_is_solved(board, size_2) << endl;

    //test case #3
    string test_board_3[] = {"OXXO",
                             "XOXO",
                             "OXXO",
                             "XOXO" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 0, actual: " << board_is_solved(board, size_3) << endl;

    //test case #4
    string test_board_4[] = {"XOOX",
                             "OOOX",
                             "OXXO",
                             "XXXO" };
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: 0, actual: " << board_is_solved(board, size_4) << endl;

    //test case #5
    string test_board_5[] = {"XOOX",
                             "OXOX",
                             "OXXO",
                             "XOXO" };
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << "Expected: 1, actual: " << board_is_solved(board, size_5) << endl;

    cout << "Finished testing board_is_solved()" << endl << endl;
}

void test_check_valid_input() {
    cout << "Begin testing check_valid_input()" << endl;

    int board[MAX_SIZE][MAX_SIZE];
    int row;
    int col;

    int size = 4;

    //test case #1
    cout << "Expected: 1, actual: " << check_valid_input(size, 1, 'C', BLUE_LETTER, row, col) << endl;

    //test case #2
    cout << "Expected: 0, actual: " << check_valid_input(size, 1, 'f', BLUE_LETTER, row, col) << endl;

    //test case #3
    cout << "Expected: 0, actual: " << check_valid_input(size, 7, 'a', RED_LETTER, row, col) << endl;

    //test case #4
    cout << "Expected: 1, actual: " << check_valid_input(size, 2, 'd', UNKNOWN_LETTER, row, col) << endl;

    //test case #5
    cout << "Expected: 1, actual: " << check_valid_input(size, 4, 'a', RED_LETTER, row, col) << endl;

    cout << "Finished testing check_valid_input()" << endl << endl;
}

void test_check_valid_move() {
    cout << "Begin testing check_valid_move()" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];

    const int max_size = 8;
    int copy[max_size][max_size];

    //test case #1
    string test_board_1[] = {"XO-X",
                             "OXOX",
                             "--XO",
                             "XOXO" };
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    read_board_from_string(copy, test_board_1, size_1);
    cout << "Expected: 1, actual: " << check_valid_move(board, copy, size_1, 0, 2, BLUE) << endl;

    //test case #2
    string test_board_2[] = { "XO-X",
                             "OXOX",
                             "--XO",
                             "XOXO" };
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    read_board_from_string(copy, test_board_2, size_2);
    cout << "Expected: 0, actual: " << check_valid_move(board, copy, size_2, 0, 3, BLUE) << endl;

    //test case #3
    string test_board_3[] = {"XO-X",
                             "OXOX",
                             "--XO",
                             "XOXO" };
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    read_board_from_string(copy, test_board_3, size_3);
    cout << "Expected: 0, actual: " << check_valid_move(board, copy, size_3, 0, 2, RED) << endl;

    cout << "Finished testing check_valid_move()" << endl << endl;
}