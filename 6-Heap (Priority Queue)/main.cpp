#include <bits/stdc++.h>
using namespace std;

#define left(i) (2*i);
#define right(i) (2*i + 1);
#define parent(i) ((int)i/2);

template <class T>
class Heap {
private:
    int hSize;
    vector<T> heap;

    void maxHeapify(int idx) {
        int l = left(idx);
        int r = right(idx);
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

    void buildHeap() {
        for (int i = hSize / 2; i > 1; --i) {
            maxHeapify(i);
        }
    }

public:
    Heap() : hSize(0) {}

    Heap(int size) : hSize(size){
        heap.resize(size + 1);
    }
    void resize(int n) {
        hSize = n;
        heap.resize(n+1);
    }
    void clear() {
        heap.clear();
        hSize = 0;
    }

    void fillHeap() {
        for (int i = 1; i <= hSize; ++i) {
            cin >> heap[i];
        }
        buildHeap();
    }

	T top() {
        maxHeapify(1);
		return heap.at(1);
	}
    T pop() {
        T val = top();
        heap.erase(heap.begin()+1);
        hSize--;
        return val;
    }

    int heapSize() {
        return hSize;
    }
};


int main() {
    int n;
    cin >> n;
    Heap<int> h(n);

    h.fillHeap();
    cout<<h.pop()<<endl;
	cout<<h.pop()<<endl;
    cout<<h.pop()<<endl;
    cout<<h.pop()<<endl;
    cout<<h.pop()<<endl;

    h.clear();
    h.resize(n);
    h.fillHeap();
    cout<<h.pop()<<endl;
    cout<<h.pop()<<endl;
    cout<<h.pop()<<endl;
    cout<<h.pop()<<endl;
    cout<<h.pop()<<endl;

}
