/* Insertion Sort Program
 *
 * Name   Matthew Flegg
 * Email  matthewflegg@outlook.com
 * Date   7/5/22
 */
#include <bits/stdc++.h>

typedef unsigned long ulong;

template <typename T>
class VectorUtils {
public:
    static std::vector<T> Slice(std::vector<T> vec, ulong start, ulong end) {
        auto x = vec.begin() + start;    // Get starting iterator
        auto y = vec.begin() + end + 1;  // Get ending iterator

        std::vector<T> sliced(y - x + 1);
        std::copy(start, end, sliced.begin());
        return sliced;
    }

    static void Print(std::vector<T> vec, const char delimiter) {
        for (auto x : vec)
            std::cout << vec << delimiter;
    }    
};

template <typename T>
class Sorter {
public:
    static void Sort(std::vector<T> &vec) {
        SortRange(vec, 0, vec.size() - 1);
    }

private:
    static void SortRange(std::vector<T> &vec, ulong start, ulong end) {
        if (start > end) return;

        ulong midpoint = (start + end) / 2;

        SortRange(vec, start, midpoint);
        SortRange(vec, midpoint + 1, end);
        Merge(vec, start, midpoint, end);
    }

    static void Merge(std::vector<T> &vec, ulong start, ulong midpoint, ulong end) {
        std::vector<T> one = VectorUtils<int>::Slice(vec, start, midpoint);
        std::vector<T> two = VectorUtils<int>::Slice(vec, midpoint + 1, end);

        ulong i = 0, j = 0;
        ulong k = start;

        while (i < one.size() && j < two.size()) {
            if (one[i] <= two[j]) {
                vec[k] = one[i];
                i++;
            } else {
                vec[k] = two[j];
                j++;
            }

            k++;
        }
    }
};

int main() {
    std::vector<int> vec(100 + rand() % 1000);

    for (auto x : vec)
        x = -1000 + rand() % 1000;
    
    Sorter<int>::Sort(vec);
    VectorUtils<int>::Print(vec, ' ');
}