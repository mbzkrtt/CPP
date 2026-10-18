#include "JumpSearch.h"
#include <cmath>
#include <algorithm>

int JumpSearch::search(const std::vector<int>& elements, int target) {
    numberComparisons = 0;

    int n = elements.size();
    int step = std::sqrt(n);
    int previous = 0;

    while (previous < n && elements[std::min(step, n) - 1] < target) {
        numberComparisons++;

        previous = step;
        step += std::sqrt(n);

        if (previous >= n) {
            return -1;
        }
    }

    for (int i = previous; i < std::min(step, n); i++) {
        numberComparisons++;

        if (elements[i] == target) {
            return i;
        }

        if (elements[i] > target) {
            return -1;
        }
    }

    return -1;
}