#include <iostream>
using namespace std;

int a[8] = {-1,3,-2,4,-6,1,6,-1};

int maxSubSeqSum(int*, int N);

int main() {
    cout<<maxSubSeqSum(a, 8);
    return 0;
}

int maxSubSeqSum(int* p, int N)
{
    int curSum = 0;
    int maxSum = 0;

    for(int i = 0; i < N; i++)
    {
        curSum += p[i];
        if(curSum > maxSum) maxSum = curSum;
        else if(curSum < 0) curSum = 0;
    }
    return maxSum;
}

