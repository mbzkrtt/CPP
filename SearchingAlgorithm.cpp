#include "SearchingAlgorithm.h"

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() {
    numberComparisons = 0;
}

void SearchingAlgorithm::displaySearchResults(
    std::ostream& os, int results, int target) {

    os << "Target : " << target << std::endl;
    os << "Result : " << results << std::endl;

    totalComparisons += numberComparisons;
    totalSearch++;

    averageComparisons =
        static_cast<double>(totalComparisons) / totalSearch;
}