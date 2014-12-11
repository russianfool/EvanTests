/* Standard game of tic tac toe, coded in a mix of C/C++.
 * Functions written in such a way as to make it easy to go from a
 * size 9 board to something else, but not implemented yet.
 */

#include <iostream>
#include <cstdio>
#include <climits>

void print_intro() {
  std::cout << "Welcome to this exciting game of Tic-Tac-Toe! If you don't know the rules, go fuck yourself (or just go read them online). Enter the number corresponding to the cell to place your piece." << std::endl;
}

void print_turn(char player) {
  std::cout << "It is now " << player << "'s turn!" << std::endl;
}

void print_board(char arr[], int size) {
  for(int i = 0; i < size; ++i) {
    std::cout << arr[i];
  
    if (i%3 < 2) { //these have to change based on board size
      std::cout << '|';
    }
    else if (i%3 == 2) {
      std::cout << std::endl << "-----" << std::endl;
    }
  }
}

void initialize_board(char arr[], int size) {//size default 3
  for(int i = 0; i < size; ++i) arr[i] = i+49;
}

void get_input(char arr[], int size, char player) {
  int input;
  bool legit = false;

  do {
    std::cout << "Please enter a number from 1-9 corresponding to the square you want to play your piece on: ";
    std::cin >> input;

    std::cin.clear(); std::cin.ignore(INT_MAX,'\n'); //flush buffer to prevent cheating

    if (input > 0 && input <= 9 && arr[input-1] == input+48)
      legit = true;
    else 
      std::cout << "Naw, that's not gonna work" << std::endl;

  } while (!legit);

  arr[input-1] = player;
}

char check_wins(char arr[], int size) {
  //slow implementation, has to recheck all cells every single time
  bool win = false;
  char c;

  for (int i = 0; i < 9; i+=3) { //check rows
    c = arr[i];

    win = win || 
          ((c == arr[i+1]) && (c == arr[i+2]));
    if (win) return c;
  }

  for (int i = 0; i < 3; ++i) { //check columns
    c = arr[i];
    win = win ||
          ((c == arr[i+3]) && (c == arr[i+6]));
    if (win) return c;
  }

  //check diagonals
  c = arr[0];
  if (c == arr[4] && c == arr[8]) return c;

  c = arr[2];
  if (c == arr[4] && c == arr[6]) return c;  

  if (win) return c;
  else return 'N';
}

int main() {
  char cur_player = 'X';
  char board[9];
  char temp;

  initialize_board(board, 9);

  print_intro();

  do {
    print_board(board, 9);
    print_turn(cur_player);
    get_input(board, 9, cur_player);
    temp = check_wins(board, 9);

    std::cout << '\n' << std::endl;

    //swap player to the other one
    if (cur_player == 'X') cur_player = 'O';
    else cur_player = 'X';

  } while(temp != 'X' && temp != 'O'); //win condition

  print_board(board, 9);
  std::cout << "Player " << temp << " has won!" << std::endl;
}