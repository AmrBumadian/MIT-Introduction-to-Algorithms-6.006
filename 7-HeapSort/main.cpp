#include <bits/stdc++.h>
using namespace std;

#define LEFT(i) (2*i)
#define RIGHT(i) (2*i + 1)
#define parent(i) ((int)i/2)

class Heap {
private:
    int hSize;
    int hLength;
    vector<int> heap;

    void maxHeapify(int idx) {
        int l = LEFT(idx);
        int r = RIGHT(idx);
        int largest = idx;
        if (l <= hSize and heap[l] > heap[idx])
            largest = l;
        if (r <= hSize and heap[r] > heap[largest])
            largest = r;
        if (largest != idx) {
            swap(heap[idx], heap[largest]);
            maxHeapify(largest);
        }
    }

    void iterativeMaxHeapify(int current) {
        int largest = current;
        int l, r;
        int cnt = 1, idx = current;
        do {
            if (cnt > 1) idx = largest;
            l = LEFT(idx);
            r = RIGHT(idx);
            if (l <= hSize && heap[l] > heap[idx]) {
                largest = l;
            }
            if (r <= hSize && heap[r] > heap[largest]) {
                largest = r;
            }
            swap(heap[idx], heap[largest]);
            ++cnt;
        } while (largest != idx);
    }

    void buildHeap() {
        for (int i = hSize / 2; i > 0; --i) {
            maxHeapify(i);
        }
    }

public:
    Heap() : hSize(0), hLength(0) {}

    Heap(int size) : hSize(size), hLength(size) {
        heap.resize(size + 1);
    }

    void fillHeap() {
        for (int i = 1; i <= hSize; ++i) {
            cin >> heap[i];
        }
    }

    void heapSort() {
        buildHeap();
        for (int i = hSize; i >= 2; --i) {
            swap(heap[1], heap[i]);
            --hSize;
            maxHeapify(1);
        }
    }

    void print() {
        for (int i = 1; i <= hLength; ++i)
            cout << heap[i] << " ";
    }
};


int main() {
    int n;
    cin >> n;
    Heap h(n);
    h.fillHeap();
    h.heapSort();
    h.print();
}
