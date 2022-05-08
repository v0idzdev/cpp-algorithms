/* Pascal's Triangle Program
 *
 * Name   Matthew Flegg
 * Email  matthewflegg@outlook.com
 * Date   7/5/22
 */
#include <cmath>
#include <iostream>

// Usings
using std::string, std::cout, std::cin;

// Function declarations
int pascal(int row, int col);
bool is_invalid(int row, int col);

/* This is where the program's execution starts and ends
 *
 * @returns  0 if the program ran successfully, -1 if the given
 *           inputs were invalid
 */
int main() {
    int row, col;

    cout << "Enter an X value: \n";
    cin >> row;
    cout << "Enter a Y value: \n";
    cin >> col;

    if (is_invalid(row, col))
        return -1;

    cout << pascal(row, col) << '\n';
    return 0;
}

/* Gets the value at a co-ordinate in pascal's triangle
 *
 * @param row  The nth row within the triangle
 * @param col  The nth number in the row, starting from the left
 * @returns    The value at the given co-ordinates
 */
int pascal(const int row, const int col) {
    int triangle[row + 1][row + 1] = {0};
    triangle[0][0] = 1;

    for (int i = 1; i <= row; i++) {
        triangle[i][0] = triangle[i][i] = 1;

        for (int j = 1; j <= i; j++)
            triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
    }

    return triangle[row][col];
}

/* Validates whether a co-ordinate exists within pascal's triangle
 *  // Values cannot be below 0, etc
 * @param row  The nth row within the triangle
 * @param col  The nth number in the row, starting from the left
 * @returns    Whether the value is valid
 */
bool is_invalid(int row, int col) {
    return col < 0 || row < 0 || col > row;
}