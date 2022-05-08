/* Selection Sort Program
 *
 * Name   Matthew Flegg
 * Email  matthewflegg@outlook.com
 * Date   7/5/22
 */
#include <iostream>
#include <vector>

using std::vector, std::cout, std::swap;

/* Uses the selection sort algorithm to sort a vector
 *
 * @param vec  The vector to be sorted
 */
void selection_sort(vector<int>& vec) {
    for (int x = 0; x < vec.size(); x++) {
        int* min = &vec[x];

        for (int y = x + 1; y < vec.size(); y++)
            if (vec[y] < *min)
                swap(vec[y], *min);

        if (vec[x] != *min)
            swap(vec[x], *min);
    }
}

/* Prints a vector's items to the console
 *
 * @param vec  The vector to print the items of
 */
void print_vector(vector<int> vec) {
    for (auto x : vec)
        cout << x << ' ';

    cout << '\n';
}

/* This is where the program starts and finishes
 */
int main() {
    vector<int> vec = {20, 12, 10, 15, 2};
    print_vector(vec);

    selection_sort(vec);
    print_vector(vec);
}