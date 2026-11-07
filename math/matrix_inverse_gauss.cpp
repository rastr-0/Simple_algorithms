#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

void print_result(const std::vector<std::vector<double>>& matrix){
    for (size_t i = 0; i < matrix.size(); i++){
        for (size_t j = matrix[0].size()/2; j < matrix[0].size(); j++){
            double value = matrix[i][j];
            if (std::fabs(value) < 1e-12)
                value = 0; // don't print "-0" or 1e-17 rounding noise
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

void fill_user_matrix(std::vector<std::vector<double>>& matrix){
    double val = 0;

    for (size_t i = 0; i < matrix[0].size()/2 ; i++){
        for (size_t j = 0; j < matrix[0].size()/2; j++){
            std::cin >> val;
            matrix[i][j] = val;
        }
    }
}

// Gauss-Jordan elimination on the augmented matrix [A | I].
// When it finishes, the right half holds A^-1.
// Returns false if A is singular (has no inverse).
bool solve_matrix(std::vector<std::vector<double>>& matrix){
    const size_t init_matrix_size = matrix.size();
    const double eps = 1e-12;

    for (size_t i = 0; i < init_matrix_size; i++){
        for (size_t j = 0; j < init_matrix_size; j++){
            if (i == j){
                matrix[i][j + init_matrix_size] = 1;
            }
            else {
                matrix[i][j + init_matrix_size] = 0;
            }
        }
    }

    for (size_t i = 0; i < init_matrix_size; i++){
        // partial pivoting: take the row with the biggest |value| in column i,
        // so we never divide by zero (or by a tiny, imprecise number)
        size_t pivot = i;
        for (size_t r = i + 1; r < init_matrix_size; r++){
            if (std::fabs(matrix[r][i]) > std::fabs(matrix[pivot][i]))
                pivot = r;
        }
        if (std::fabs(matrix[pivot][i]) < eps)
            return false; // the whole column is zero -> singular matrix
        std::swap(matrix[i], matrix[pivot]);

        for (size_t j = 0; j < init_matrix_size; j++){
            if (i != j){
                double val = matrix[j][i] / matrix[i][i];
                for(size_t k = 0; k < 2*init_matrix_size; k++){
                    matrix[j][k] = matrix[j][k] - val*matrix[i][k];
                }
            }
        }
    }

    for (size_t i = 0; i < init_matrix_size; i++){
        for (size_t j = init_matrix_size; j < 2*init_matrix_size; j++){
            matrix[i][j] = matrix[i][j]/matrix[i][i];
        }
    }
    return true;
}

int main(){
    int length = 0;
    int height = 0;
    std::cout << "Input matrix size (n x n):\n";
    std::cin >> length >> height;
    if (length != height){
        std::cout << "Height and Width are different\n";
        return 1;
    }
    if (length <= 0){
        std::cout << "Matrix size must be positive\n";
        return 1;
    }
    std::vector<std::vector<double>> matrix(length, std::vector<double>(2 * height, 0));
    fill_user_matrix(matrix);
    if (solve_matrix(matrix)){
        print_result(matrix);
    }
    else{
        std::cout << "Not possible to calculate invertible matrix\n";
        return 1;
    }
}
