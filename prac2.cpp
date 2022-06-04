#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template <class T = int> class Matrix {
private:
  int rows, cols;
  vector<vector<T>> core;

public:
  Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    this->core.resize(rows);
  };

  T getByPosition(int row, int col) {
    io_errc idx_out_of_range;

    if (row > this->rows || col > this->cols)
      throw invalid_argument("row or column index out of declration");
    return this->core[row][col];
  }

  vector<int> operator[](int idx) { return this->core[idx]; }
};

int main() {
  Matrix<> mtx1(3, 3);

  cout << mtx1.getByPosition(3, 3) << endl;

  return 0;
}
