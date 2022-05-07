#include <iostream>
#include <vector>

int Pascal(int row, int col);

int main() {
    // Test co-ordinates
    int tests[3][2] = {
        {4, 1},  // Should be 4
        {2, 1},  // Should be 2
        {3, 2},  // Should be 3
    };

    // Test and print results
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        std::cout << Pascal(tests[i][0], tests[i][1]) << '\n';  // If this is 0, we fucked up
    }

    return 0;  // Everything went swimmingly
}

int Pascal(int row, int col) {
    if (row < 0 || col < 0 || col > row) {  // Invalid row or col
        return 0;                           // Indicates that an error occured
    }

    // Keep track of the current row
    // Temporarily store the whole triangle up to the row we need
    int i = 0;
    std::vector<std::vector<int>> triangle;

    // Loop over this at least once
    do {
        // Gradually build the current row, so we can add it to
        // The triangle
        std::vector<int> currentRow(i + 1);

        // Current row is row 0
        // Set to 1
        if (currentRow.size() == 1) {
            currentRow[0] = 1;
            triangle.push_back(currentRow);
            i++;
            continue;
        }

        // Else, we set the first and last col in the row to 1
        currentRow[0] = currentRow[currentRow.size() - 1] = 1;

        // If the row isn't 1 or 2 (which are just filled with 1s),
        // set each cell that isn't a 1 to the cell directly above it,
        // + the cell one above and one to the left
        if (i >= 2)
            for (int j = 1; j < currentRow.size() - 1; j++) {
                currentRow[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
            }

        // Add the current row to the triangle
        // Increment counter so we can do the next row
        triangle.push_back(currentRow);
        i++;

        // If we've reached the last row, break out of the loop
    } while (i <= row);

    // Return the value at the co-ords the user wanted
    // -1 because we want to input 1, 1 as 0, 0 etc
    return triangle[row][col];
}