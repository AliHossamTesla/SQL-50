template<bool MAX_HEAP = true>
class Heap {
private:
    vector<int>heap ;
    int f(int a, int b) {
        if (MAX_HEAP) return max(a, b );
        return min(a, b);
    }
    int parent(int i) const {return (i - 1)/2;}
    int left(int i) const {return 2*i + 1;}
    int right(int i) const {return 2*i + 2;}
    void siftUp(int i) {
        while (i > 0 && heap[parent(i)] == f(heap[i], heap[parent(i)])) {
            swap(heap[i], heap[parent(i)]) ;
            i = parent(i);
        }
    }
    void siftDown(int i) {
        int targetIndex = i ;
        int l = left(i), r = right(i) ;
        int n = heap.size() ;
        if (l < n && heap[l] == f(heap[l], heap[targetIndex])) {
            targetIndex = l;
        }
        if (r < n && heap[r] == f(heap[r], heap[targetIndex])){
            targetIndex = r;
        }
        if (targetIndex != i) {
            swap(heap[i], heap[targetIndex]) ;
            siftDown(targetIndex) ;
        }
    }
public:
    Heap(){}
    Heap(vector<int>& arr) { // O(N)
        heap = arr;
        int n = arr.size() ;
        for (int i = n/2 - 1; i >= 0 ; i --) {
            siftDown(i) ;
        }
    }
    void push(int v) {
        heap.push_back(v);
        siftUp(heap.size() - 1) ;
    }
    void pop() {
        if (heap.empty()) throw runtime_error("Heap is empty") ;
        heap[0] = heap.back() ;
        heap.pop_back() ;
        siftDown(0) ;
    }
    int top() const {
        if (heap.empty()) throw runtime_error("Heap is empty") ;
        return heap[0] ;
    }
    bool empty() const {return heap.empty();}
    int size() const {return heap.size();}
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        Heap hp(nums) ;
        while(k-- > 1){
            hp.pop() ;
        }
        return hp.top() ;
        return -1 ;
    }
};