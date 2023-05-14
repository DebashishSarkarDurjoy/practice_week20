#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minMergeCost(vector<int> ropes) {
    priority_queue<int, vector<int>, greater<int>> min_heap(ropes.begin(), ropes.end());

    int cost = 0;
    while (min_heap.size() > 1) {
        int a = min_heap.top();
        min_heap.pop();
        int b = min_heap.top();
        min_heap.pop();

        int c = a + b;
        cost += c;
        // cout << cost << "." << endl;
        min_heap.push(c);
    }
    // cost += min_heap.top();

    return cost;
}

int main(void) {
    vector<int> ropes = {4,3,2,6};

    cout << minMergeCost(ropes) << endl;

    return 0;
}