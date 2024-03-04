#include <iostream>
#include <vector>

using namespace std;

// Function to perform binary search on a sorted vector
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }

        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // If target is not present in the vector
    return -1;
}

int main() {
    // Example usage
    vector<int> sortedVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    int result = binarySearch(sortedVector, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the vector." << endl;
    }

    return 0;
}

