#include <iostream>
#include <vector>
#include <cmath>

void print_result(const std::vector<std::vector<double>>& matrix){
    for (size_t i = 0; i < matrix.size(); i++){
        for (size_t j = matrix[0].size()/2; j < matrix[0].size(); j++){
            std::cout << matrix[i][j] << " ";
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

bool solve_matrix(std::vector<std::vector<double>>& matrix){
    const int init_matrix_size = matrix[0].size() / 2;
    
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

double dt(std::vector<std::vector<double>> matrix){
    for (size_t iteration = 0; iteration < matrix.size(); iteration++){
        double val = matrix[iteration][iteration];
        for (size_t i = iteration+1; i < matrix.size(); i++){
            double z = matrix[i][iteration]/ val;
            for (size_t j = iteration; j < matrix.size(); j++){
                matrix[i][j] -= matrix[iteration][j] * z;
            }
        }
    }

    double determinant = 1;
    for (size_t i = 0; i < matrix.size(); i++){
        for (size_t j = 0; j < matrix.size(); j++){
            if (i == j){
                determinant *= matrix[i][j];
            }
        }
    }
    return determinant;
}

int main(){
    int length = 0;
    int height = 0;
    std::cout << "Input matrix size (n x n):\n";
    std::cin >> length >> height;
    if (length != height){
        std::cout << "Height and Widht are different\n"; 
    }
    else{
        std::vector<std::vector<double>> matrix(length, std::vector<double>(2 * height, 0));
        fill_user_matrix(matrix);
        double matrix_dt = dt(matrix);
        if (matrix_dt != 0){
            if (solve_matrix(matrix)){ 
                print_result(matrix);
            }
        }
        else{
            std::cout << "Not possible to calculate invertible matrix";
            return -1;
        }
    }
}

