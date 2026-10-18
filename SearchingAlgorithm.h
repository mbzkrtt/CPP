#ifndef SEARCHING_ALGORITHM_H
#define SEARCHING_ALGORITHM_H

#include <vector>
#include <iostream>

class SearchingAlgorithm {
protected:
    int numberComparisons;

    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;

public:
    SearchingAlgorithm();

    virtual int search(const std::vector<int>& elements, int target) = 0;

    void displaySearchResults(std::ostream& os, int results, int target);
};

#endif