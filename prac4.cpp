#include <iostream>

using namespace std;

struct player {
  string name, sign;
  int score = 0;

  bool operator!=(struct player player) {
    return !(this->name == player.name && this->score == player.score);
  }
  void operator=(struct player player) {
    this->name = player.name,
    this->sign = player.sign,
    this->score = player.score;
  }
};

template <class T = int> struct matrix {
private:
  int rows, cols;
  T **_rows;

public:
  matrix<T>(int rows, int cols) : rows(rows), cols(cols) {
    this->_rows = (T **)malloc(sizeof(T *) * rows);
    for(int i=0; i < rows; i++){
      this->_rows[i] = (T *)malloc(sizeof(T) * cols);
    }
  }
  int get_rows() { return this->rows; }
  int get_cols() { return this->cols; }
  void set_col(int row, int col, T value) { this->_rows[row][col] = value; }
  T *operator[](int idx) { return this->_rows[idx]; }
};

template <typename T = int> void printBoard(struct matrix<T> board) {
  int rows = board.get_rows(), cols = board.get_cols();

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      cout << board[i][j] << ' ';

    cout << endl;
  }
}

void clear() { system("clear"); }

// Tic Tac Toe
int main() {
  struct player player1, player2;
  clear();

  cout << "Enter the first player name: ";
  cin >> player1.name; player1.sign = "X";
  cout << "Enter the second player name: ";
  cin >> player2.name; player2.sign = "O";

  bool running = true;
  struct matrix<string> board(3, 3);

  for (int i=0; i < board.get_rows(); i++){
    for (int j=0; j < board.get_cols(); j++)
      board.set_col(i, j, "•");
  }
  {
    struct player player = player1;
    int x, y;
    while (running) {
      clear();
      cout << player.name << "'s turn:\n";
      printBoard(board);

      cout << "Enter (x, y) position: ";
      scanf("%d%d", &x, &y);
      board.set_col(x-1, y-1, player.sign);

      player = (player != player1) ? player1 : player2;
    }
  }

  return 0;
}
