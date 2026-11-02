#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
};

// Comparator to sort items by value-to-weight ratio in descending order
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp); // Sort items greedily by density
    double curWeight = 0, finalvalue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value; // Take whole item
        } else {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double)remain / arr[i].weight); // Take fraction of item
            break;
        }
    }
    return finalvalue;
}

int main() {
    int W = 50;
    Item arr[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value: " << fractionalKnapsack(W, arr, n) << endl;
    return 0;
}