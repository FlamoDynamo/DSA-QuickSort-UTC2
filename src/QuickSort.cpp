#include "QuickSort.h"
#include "Item.h"

QuickSort::QuickSort() {
    // Constructor implementation (optional)
}

void QuickSort::sort(std::vector<Item*>& items, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(items, left, right);
        sort(items, left, pivotIndex - 1); // Sort the left subarray
        sort(items, pivotIndex + 1, right); // Sort the right subarray
    }
}

int QuickSort::partition(std::vector<Item*>& items, int left, int right) {
    // Choose the rightmost element as the pivot
    Item* pivot = items[right];

    // Partition the array around the pivot
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (items[j]->getSKU() < pivot->getSKU()) { // Compare using SKU
            i++;
            std::swap(items[i], items[j]);
        }
    }
    std::swap(items[i + 1], items[right]);
    return i + 1;
}