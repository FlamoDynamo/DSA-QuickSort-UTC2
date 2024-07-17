#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include "Item.h"

class QuickSort {
public:
    // Constructor
    QuickSort();

    // Public method to sort a vector of items
    void sort(std::vector<Item*>& items, int left, int right);

private:
    // Private helper method for partitioning the array
    int partition(std::vector<Item*>& items, int left, int right);
};

#endif // QUICKSORT_H