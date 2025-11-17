#include<iostream>
#include<vector>
#include<functional>
#include<stdexcept>

template<typename T, typename Compare>
void siftDown(std::vector<T> &a, int n, int i, Compare cmp) {
    int root = i;
    while (true) {
        int left = 2*root + 1;
        int right = left + 1;
        int swapIdx = root;

        if (left < n && cmp(a[left], a[swapIdx])) swapIdx = left;
        if (right < n && cmp(a[right], a[swapIdx])) swapIdx = right;

        if (swapIdx == root) break;
        std::swap(a[root], a[swapIdx]);
        root = swapIdx;
    }
}
template<typename T, typename Compare>
void buildHeap(std::vector<T> &a, Compare cmp) {
    int n = (int)a.size();
    for (int i = (n/2) - 1; i >= 0; --i) siftDown<T,Compare>(a, n, i, cmp);
}
template<typename T>
void heapsortAscending(std::vector<T> &a) {
    auto cmp = [](const T &x, const T &y){ return x > y; }; 
    buildHeap<T>(a, cmp);
    int n = (int)a.size();
    for (int end = n - 1; end > 0; --end) {
        std::swap(a[0], a[end]);     
        siftDown<T>(a, end, 0, cmp);   
    }
}
template<typename T>
void heapsortDescending(std::vector<T> &a) {
    auto cmp = [](const T &x, const T &y){ return x < y; };
    buildHeap<T>(a, cmp);
    int n = (int)a.size();
    for (int end = n - 1; end > 0; --end) {
        std::swap(a[0], a[end]);       
        siftDown<T>(a, end, 0, cmp);
    }
}

template<typename T, typename Compare = std::less<T>>
class PQHeap {
public:
    PQHeap(Compare cmp = Compare()) : cmp(cmp) {}

    void push(const T &val) {
        data.push_back(val);
        siftUp((int)data.size() - 1);
    }

    void pop() {
        if (empty()) throw std::runtime_error("pop() on empty priority queue");
        std::swap(data[0], data.back());
        data.pop_back();
        if (!data.empty()) siftDown(0);
    }

    const T& top() const {
        if (empty()) throw std::runtime_error("top() on empty priority queue");
        return data[0];
    }
    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }

private:
    std::vector<T> data;
    Compare cmp;

    void siftUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (!cmp(data[idx], data[parent])) break;
            std::swap(data[idx], data[parent]);
            idx = parent;
        }
    }
    void siftDown(int idx) {
        int n = (int)data.size();
        while (true) {
            int left = 2*idx + 1;
            int right = left + 1;
            int best = idx;
            if (left < n && cmp(data[left], data[best])) best = left;
            if (right < n && cmp(data[right], data[best])) best = right;
            if (best == idx) break;
            std::swap(data[idx], data[best]);
            idx = best;
        }
    }
};

int main() {
    std::vector<int> v1 = {4, 10, 3, 5, 1, 8, 7, 2};
    std::vector<int> v2 = v1;

    std::cout << "Original: ";
    for (int x : v1) std::cout << x << ' ';
    std::cout << '\n';

    heapsortAscending(v1);
    std::cout << "Heapsort ascending: ";
    for (int x : v1) std::cout << x << ' ';
    std::cout << '\n';

    heapsortDescending(v2);
    std::cout << "Heapsort descending: ";
    for (int x : v2) std::cout << x << ' ';
    std::cout << '\n';

    PQHeap<int, std::greater<int>>maxpq;
    maxpq.push(5);
    maxpq.push(1);
    maxpq.push(9);
    maxpq.push(3);

    std::cout << "Max-PQ pop order: ";
    while (!maxpq.empty()) {
        std::cout << maxpq.top() << ' ';
        maxpq.pop();
    }
    std::cout << '\n';

    PQHeap<int, std::less<int>> minpq;
    minpq.push(5);
    minpq.push(1);
    minpq.push(9);
    minpq.push(3);

    std::cout << "Min-PQ pop order: ";
    while (!minpq.empty()) {
        std::cout << minpq.top() << ' ';
        minpq.pop();
    }
    std::cout<<'\n';

    return 0;
}
