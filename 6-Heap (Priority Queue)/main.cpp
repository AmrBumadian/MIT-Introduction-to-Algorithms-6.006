#include <bits/stdc++.h>

using namespace std;

#define LEFT(i) (2*i)
#define RIGHT(i) (2*i + 1)
#define PARENT(i) ((int)i/2)

template<typename T, typename Sequence = vector<T>, // type template, sequence container (vector is the default)
        typename Compare  = less<typename Sequence::value_type>> // biFunctor compare (less is the default)
// Compare = less for implementing a min heap, Compare = greater for implementing a max heap
class Heap {
private:
    int hSize; // heap size
    Sequence heap; // Container
    Compare comp; // instantiating a comparator

    void Heapify(int start) { // maintain the heap property
        int replaced = start; // current largest key index
        int l, r;
        int cnt = 1, idx = start;
        do {
            if (cnt > 1) idx = replaced; // start point for next iterations
            l = LEFT(idx); // left child
            r = RIGHT(idx); // right child
            // if left child index is in the heap, compare it with current idx
            if (l <= hSize and comp(heap[l], heap[idx]))
                replaced = l; // the element to be replaced is l
            // compare the element to be replaced with the r
            if (r <= hSize and comp(heap[r], heap[replaced]))
                replaced = r;
            // now we know what element to replace
            swap(heap[idx], heap[replaced]); // put element at replaced into its right position
            // next step we will need to start from replaced
            ++cnt; // increase the count so we know the initial iteration finished and we can use idx = replaced the next iteration
        } while (replaced != idx); // if replaced was equal idx (self replacement), end loop
    }

    void heapIncreaseKey(int i) { // to move the inserted element along the path to the right position
        // while i not the root and inserted element can be swapped with its parent, swap then go up
        while (i > 1 && comp(heap[i], heap[PARENT(i)])) {
            swap(heap[i], heap[PARENT(i)]);
            i = PARENT(i);
        }
    }

public:
    Heap() : hSize(0) { heap.resize(1); }

    Heap(int capacity) : hSize(0) {
        heap.resize(capacity + 1);
    }

    void push(T key) {
        ++hSize;
        if (heap.size() - 1 < hSize) { // if heap is full
            heap.emplace_back(key);
        } else heap[hSize] = key;
        heapIncreaseKey(hSize);
    }

    T top() {
        return heap[1];
    }

    T pop() {
        T val = heap[1];
        swap(heap[1], heap[hSize]); // throw max heap[1] to the bottom of the heap
        hSize--; // decrease the heap size
        Heapify(1); // maintain the heap property once from the root
        return val;
    }

    int heapSize() {
        return hSize;
    }

    bool empty() {
        return hSize == 0;
    }

    void clear() {
        heap.resize(1);
        hSize = 0;
    }
};

int main() {
    //Heap<int> q;
    Heap<int, vector<int>, greater<int>> q; // max heap

    for (int i = 1; i <= 10000; ++i) {
        q.push(i);
    }
    while (!q.empty()) {
        cout << q.pop() << " ";
    }
    cout << endl;
    q.clear();
    for (int i = 1; i <= 10000; ++i) {
        q.push(i);
    }
    for (int i = 1; i <= 10000; ++i) {
        q.push(i);
    }
    q.clear();
}
