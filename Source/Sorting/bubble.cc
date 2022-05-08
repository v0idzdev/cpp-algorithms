/* Bubble Sort Program
 *
 * Name   Matthew Flegg
 * Email  matthewflegg@outlook.com
 * Date   7/5/22
 */
#include <iostream>
#include <vector>

using std::vector, std::cout, std::swap;

/* Implements the bubble sort algorithm
 *
 * @param items  The vector of items to be sorted
 */
void bubble_sort(vector<int>& items) {
    int pass = 1;
    bool swapped;

    do {
        swapped = false;

        for (int i = 0; i < items.size() - pass; i++)
            if (items[i] > items[i + 1]) {
                std::swap(items[i], items[i + 1]);
                swapped = true;
            }

        pass++;
    } while (swapped);
}

/* This is where the program starts and finishes
 */
int main() {
    vector<int> items = {-2, 45, 0, 11, -9};

    // Print the list before sorting
    for (auto x : items)
        cout << x << ' ';

    bubble_sort(items);

    // Print the list after sorting
    cout << '\n';
    for (auto x : items)
        cout << x << ' ';
}