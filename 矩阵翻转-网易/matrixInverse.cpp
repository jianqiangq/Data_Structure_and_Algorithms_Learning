#include <iostream>
// 一个m*n的矩阵棋盘上面放着被子，杯口朝上，遍历每一个格子，
// 格子和格子周围的8个格子上的杯子都做一次反转。遍历完完所有的格子后，有多少被子杯口朝下。
// 例子：
// 1*1 -> 1
// 1*2 -> 0
// 3*1 -> 1
// 4*1 -> 2
// 2*2 -> 0

using namespace std;

int main()
{
    int N = 0;
    int m,n;
    cin>>N;


    for(int iter=0; iter< N; iter++){
        cin >> m >>n;

        int count = 0;

        if(m>=3 && n>=3)
        {
            count = (m-2)*(n-2);
        }
        else if(m ==1 && n >=3 || n ==1 && m >=3){

            if(n>=3) count = n-2;
            if(m>=3) count = m-2;

        }
        else if(m ==2 && n >=3 || n ==2 && m >=3) {
            count = 0;

        }


        else {
            int map[m][n];
            for(int i = 0; i<m;i++)
                for(int j=0; j<n; j++)
                {
                    map[i][j] = 1;
                }


            for(int i = 0; i<m;i++)
                for(int j=0; j<n; j++)
                {
                    map[i][j] *= -1;
                    for(int t1 = -1; t1<=1; t1++)
                        for(int t2 = -1; t2<=1; t2++)
                        {
                            if((i+t1 >= 0) && (i+t1 < m) && (j+t2 >= 0) && (j+t2 < n))
                            {
                                if(t1==0 && t2==0)
                                {
                                    continue;
                                } else {
                                    map[i+t1][j+t2] *= -1;
                                }
                            }

                        }
                }

            for(int i = 0; i<m;i++)
                for(int j=0; j<n; j++)
                {
                    if(map[i][j] < 0) count++;
                }
        }
        cout<<count<<endl;
    }

    return 0;

}
