#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    // out flie
    ofstream ofile("test.txt");
    if (ofile.is_open())
    {
        ofile << "line1 test\n";
        ofile << "line2 test\n";
        ofile << "12\n";
    }
    ofile.close();

    // ifile
    ifstream file("test.txt");
    string line;
    if (file.is_open())
    {
        while ( getline (file,line) )  //string 支持getline()函数: getline(file, string类对象)，getine(cin, string类对象)
        {
            if (line == "12")
                int line_int = stoi(line);
            cout << line << '\n';
        }
        file.close();
    }
    
    //读文件或者
    ifstream iFile("test.txt");
    const int buffSize = 1024;
    char* buff = new char[buffSize];
    if(iFile.is_open()){
        cout<<"file is open"<<endl;
        while(iFile.getline(buff, buffSize))
        {
            cout << buff << endl;
        }
    }
    delete[] buff;

    //重定向方式读区
    freopen("some.txt","r",stdin);
    char* buff = new char[20];
=    while(cin.getline(buff, 20)). // 从输入流中读取bufSize-1个字符到缓冲区buf(bufSize = 20)，或读到碰到‘\n’ 为止（哪个先到算哪个）。 //也可以getline(cin, string类对象)
    {
        cout << buff << endl;
    }
    
    return 0;
}
