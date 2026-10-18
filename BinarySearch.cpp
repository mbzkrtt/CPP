#include "BinarySearch.h"

int BinarySearch::search(const std::vector<int>& elements, int target) {
    numberComparisons = 0;

    int left = 0;
    int right = elements.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        numberComparisons++;

        if (elements[middle] == target) {
            return middle;
        }

        numberComparisons++;

        if (elements[middle] < target) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    return -1;
}