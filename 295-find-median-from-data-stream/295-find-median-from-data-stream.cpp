class MedianFinder {
public:
    priority_queue<long> small, large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        while((int)small.size()<(int)large.size()){
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return (int)small.size()>(int)large.size()?small.top():(small.top()-large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */