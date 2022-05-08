/* Insertion Sort Program
 *
 * Name   Matthew Flegg
 * Email  matthewflegg@outlook.com
 * Date   7/5/22
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using std::vector, std::cout, std::swap, std::map;

/* Implements insertion sort to sort a list
 *
 * @param vec  The vector to be sorted
 */
void insertion_sort(vector<int>& vec) {
}

/* This is where the program starts and finishes
 */
int main() {
    vector<int> vec = {9, 5, 1, 4, 3};

    for (auto x : vec)
        cout << x << ' ';

    insertion_sort(vec);

    cout << '\n';
    for (auto x : vec)
        cout << x << ' ';
}