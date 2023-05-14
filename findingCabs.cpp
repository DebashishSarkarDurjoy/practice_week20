#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Cab {
public:
    string id;
    int x, y;

    Cab (string id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int dist() const {
        return (this->x * this->x) + (this->y * this->y);
    }
};

class cabCompare {
public:
    bool operator()(Cab* A, Cab* B) {
        return A->dist() < B->dist(); 
    }
};

bool distCompare(Cab* A, Cab* B) {
    return A->dist() < B->dist();
}

void printNearestCabs(vector<Cab*> cabs, int k) {
    priority_queue<Cab*, vector<Cab*>, cabCompare> max_heap(cabs.begin(), cabs.begin()+k);

    for (int i = k; i < cabs.size(); i++) {
        if (cabs[i]->dist() < max_heap.top()->dist()) {
            max_heap.pop();
            max_heap.push(cabs[i]);
        }
    }

    vector<Cab*> output;
    while (!max_heap.empty()) {
        output.push_back(max_heap.top());
        max_heap.pop();
    }

    // reverse(output.begin(), output.end());
    sort(output.begin(), output.end(), distCompare);

    for (auto cab_ptr: output) {
        cout << cab_ptr->id << endl;
    }
}

int main(void) {
    int N, k;
    cin >> N >> k;

    int x, y;
    string id;
    vector<Cab*> cabs;
    for (int i = 0; i < N; i++) {
        cin >> id >> x >> y;
        Cab *newCab = new Cab(id, x, y);
        cabs.push_back(newCab);
    }

    printNearestCabs(cabs, k);

    return 0;
}