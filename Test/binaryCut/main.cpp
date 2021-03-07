#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// 计算文本宽度
float getWidth(float* arr, int l, int r) {
    float sum = 0;
    for(int i=l; i<=r; i++){
        sum += arr[i];
    }
    return sum;
}


// 寻找行切点，l r 为段文本的起止点，lineWidth 为行宽度
int binarySearchCutPoint(float* arr, int l, int r, int lineWidth) {
    int mid;
    // cutPoint 在 left 和 right 闭区间查找
    int left = l;
    int right = r;

    if (getWidth(arr, l, r) <= lineWidth) return r;

    while(left <= right) {
        mid = (left + right) / 2;
        if(getWidth(arr, l, mid) <= lineWidth && getWidth(arr, l, mid+1) > lineWidth){
            return mid;
        } else if(getWidth(arr, l, mid) > lineWidth) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1; // 第一个字符宽度大于行宽度，出错
}

// 段文本切行，返回切点
vector<int> cutArray(float* arr, int l, int r, int lineWidth, bool& success) {
    vector<int> cutPointArray;    
    int cutPoint = l-1;
    while(cutPoint < r) {
        cutPoint = binarySearchCutPoint(arr, cutPoint+1, r, lineWidth);
        if (cutPoint != -1) {
            cutPointArray.push_back(cutPoint);
        } else {  // cutPoint == -1 第一个字符宽度大于行宽度
            success = false;
            return cutPointArray;
        }
    }
    return cutPointArray;
}


int main() {
    // 数组模拟每个字符的像素宽度
    float arr[22] = {1, 5, 2.2, 2, 1.3, 3, 2, 1.5, 2, 2, 3, 2, 2.5, 2, 1, 1, 4.5, 2, 2, 2, 1, 2};
    bool success = true; // 成功标志
    vector<int> cutPointArray = cutArray(arr, 0, 21, 9, success);
    if(success) {
        vector<int>::iterator it = cutPointArray.begin();
        while(it != cutPointArray.end()) {
            cout << *it << endl;
            it++;
        }
    }
    return 0;
}