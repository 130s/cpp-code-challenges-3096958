// C++ Code Challenges, LinkedIn Learning

// Challenge #2: Sorting an Array
// Sort the elements in an array in ascending order.
// Implement the algorithm of your choice.
// Don't use STL vectors.
// Don't use a sorting function from a library.

#include <iostream>

/* The patition method used in quick sort. */
int partition(int *arr, int index_low, int index_high){
    // In this case we're automatically taking the element at 'index_high' as the pivot.
    // This is a major improvement point in the future.
    // --> TODO Isn't this approach what's mentioned as possibly O(n^2) https://interviewing.io/sorting-interview-questions#quick-sort ?
    int index_pivot = index_high;
    int val_pivot = arr[index_pivot];
    int index_left = index_low;
    
    for (int index_right = index_low; index_right < index_high; index_right++){
        if (arr[index_right] < val_pivot){
            int val_left = arr[index_left];
            int val_right = arr[index_right];
            arr[index_right] = val_left;
            arr[index_left] = val_right;
            index_left++;
        }
    }
    // By this point, the array should be split to 2 groups; the one lower and higher than pivot value.
    int val_left = arr[index_left];
    arr[index_left] = val_pivot;
    arr[index_pivot] = val_left;
    return index_left;
}

bool quick_sort(int *arr, int index_low, int index_high){
    // When index_low passes index_high so that index_low is larger, sort is done.
    if (index_low < index_high){
        int index_pivot = partition(arr, index_low, index_high);
        std::cout << "index_low: " << index_low << " index_high: " << index_high << " index_pivot: " << index_pivot << std::endl;
        quick_sort(arr, index_low, index_pivot - 1);
        quick_sort(arr, index_pivot + 1, index_high);
    }
    std::cout << "Done with a quick_sort run. Array returned: " << arr << std::endl;
    return true;
}

// sort_array()
// Summary: This function receives an array of integers and sorts it in ascending order.
// Arguments:
//           arr: A pointer acting as the array to sort.
//           n: The size of the array.
// Returns: A boolean value: True on success, false otherwise.
bool sort_array(int *arr, int n){
    return quick_sort(arr, 0, n);
}

// Main function
int main(){
    // The following array will be treated as an array of length len. 
    const int len = 7; // Don't exceed the length of the array below!
    int array[] = {2, 9, 4, 3, 5, 1, 6, 8, 0, 7};

    // Print the original array
    std::cout << "Original Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    sort_array(array, len); // Sort the array

    // Print the sorted array
    std::cout << "  Sorted Array: [ ";
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << "]" << std::endl << std::endl << std::flush;

    return 0;
}
