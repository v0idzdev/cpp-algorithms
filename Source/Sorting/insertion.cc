/* Insertion Sort Program
 *
 * Name   Matthew Flegg
 * Email  matthewflegg@outlook.com
 * Date   7/5/22
 */
#include <ctime>
#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl, std::time, std::rand, std::srand;

/* Implements insertion sort to sort a list
 *
 * @param vec  The vector to be sorted
 */
void insertion_sort(vector<int>& vec) {
    for (int i = i; i < vec.size(); i++) {
        int key = vec[i];
        int j = i - 1;

        while (key < vec[j] && j >= 0) {
            vec[j + 1] = vec[j];
            j--;
        }

        vec[j + 1] = key;
    }
}

/* Utility function to print an array to the screen
 *
 * @param vec  The vector to be printed
 */
void print_vector(vector<int> vec) {
    for (auto x : vec)
        cout << x << ' ';

    cout << endl;
}

/* Creates a test vector with a random length between
 * two values and randomly selected integerss
 *
 * @param min_items  The min number of items
 * @param max_items  The max number of items
 */
vector<int> create_random_vector(int min, int max) {
    srand(time(0));

    int length = min + rand() % max;
    vector<int> vec(length);

    for (int i = 0; i < length; i++) {
        vec[i] = rand() % 256;
    }

    return vec;
}

/* This is where the program starts and finishes
 */
int main() {
    vector<int> vec = create_random_vector(10, 100);

    print_vector(vec);
    insertion_sort(vec);
    print_vector(vec);
}