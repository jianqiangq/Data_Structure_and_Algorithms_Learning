#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int N = 9;
    int a[N];
    int min_index, min_value;
    min_index = 0;
    for(int i=0; i<N; i++)
    {
        cin >> a[i];
        if(i == 0) min_value = a[i];
        else if(a[i] < min_value) { // 找最低点
            min_index = i;
            min_value = a[i];
        }
    }

    // 找左边界
    int temp1, temp2;
    int left_max_index, left_max_value;
    temp1 = min_value;
    for(int i=min_index-1; i>=0; i--)
    {
        temp2 = a[i];
        if(temp2 >= temp1)
        {
            temp1 = temp2;
        }
        else {
            left_max_index = i+1;
            left_max_value = temp1;
            break;
        }
    }

    // 找右边界
    int right_max_index, right_max_value;
    temp1 = min_value;
    for(int i=min_index+1; i<=N; i++)
    {
        temp2 = a[i];
        if(temp2 >= temp1)
        {
            temp1 = temp2;
        }
        else {
            right_max_index = i-1;
            right_max_value = temp1;
            break;
        }
    }

    int sum = 0;
    int low_value;
    if(left_max_value >= right_max_value) {
        low_value = right_max_value;
    }
    else {
        low_value = left_max_value;
    }

    sum += low_value-a[min_index];
    for(int i = min_index-1; i > left_max_index; i--)
    {
        if(low_value-a[i] > 0) sum += low_value-a[i];
    }

    for(int i = min_index+1; i < right_max_index; i++)
    {
        if(low_value-a[i] > 0) sum += low_value-a[i];
    }

    cout << sum << endl;

    return 0;
}
