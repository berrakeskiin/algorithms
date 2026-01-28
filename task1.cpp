#include <array>
#include <iostream>

const int MAXNUMBEROFROWS = 100;
const int MAXNUMBEROFCOLUMNS = 100;

void printArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr,
                int nrrows, int nrcolumns) {
    for (int i = 0; i < nrrows; i++) {
        for (int j = 0; j < nrcolumns; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void fillArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr,
               int nrrows, int nrcolumns) {
    for (int i = 0; i < nrrows; i++) {
        for (int j = 0; j < nrcolumns; j++) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            std::cin >> arr[i][j];
        }
    }
}

int main() {
    std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS> matrix;
    fillArray(matrix, 5, 4);
    printArray(matrix, 5, 4);
}