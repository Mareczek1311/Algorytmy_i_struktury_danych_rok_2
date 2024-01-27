#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int> maxHeap; // max heap for the lower half
priority_queue<int, vector<int>, greater<int> > minHeap; 

int findMedian(){
    if(maxHeap.size() == minHeap.size()){
        return (maxHeap.top() + minHeap.top()) / 2;
    }
    else{
        return maxHeap.top();
    }

}

void addValue(int value){
    if(maxHeap.empty() || value < maxHeap.top()){
        maxHeap.push(value);
    }
    else{
        minHeap.push(value);
    }

    if (maxHeap.size() > minHeap.size() + 1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    } else if (minHeap.size() > maxHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

int main(){
    int liczba;
    vector<int> arr;
    for(int i=0; i<7; i++){
        cin >> liczba;
        arr.push_back(liczba);
    }
    
    for(int i=0; i<arr.size(); i++){
        addValue(arr[i]);
        cout << findMedian() << " ";
    }

    return 0;
}
