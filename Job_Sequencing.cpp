#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparator to sort jobs in decreasing order of profit (Greedy approach)
bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void jobSequencing(Job arr[], int n) {
    sort(arr, arr + n, comparison); // Sort jobs by highest profit first
    int result[100];
    bool slot[100] = {false}; // Keep track of free time slots
    
    for (int i = 0; i < n; i++) {
        // Find a free slot from the last possible deadline downwards
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i; // Assign job to slot
                slot[j] = true;
                break;
            }
        }
    }
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < n; i++)
        if (slot[i]) cout << arr[result[i]].id << " ";
    cout << endl;
}

int main() {
    Job arr[] = {{'A', 2, 100}, {'B', 1, 19}, {'C', 2, 27}, {'D', 1, 25}, {'E', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    jobSequencing(arr, n);
    return 0;
}