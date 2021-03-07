#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class CStudent {
public:
    char szName[20];
    int nScore;
};

int main()
{
    CStudent s;

    //写文件
    ofstream outFile("students.dat", ios::out|ios::binary);
    while(cin >> s.szName >> s.nScore)
    {
        if(strcmp(s.szName, "exit") == 0) //名字为exit则结束
            break;
        outFile.write((char*) &s, sizeof(CStudent));
    }
    outFile.close();

    /*键盘输入：
    Tom 60
    Jack 80
    Jane 40
    exit 0
    */

    //读文件
    ifstream inFile("students.dat", ios::in|ios::binary);
    if(!inFile)
    {
        cout << "error" << endl;
        return 0;
    }
    while(inFile.read((char*) &s, sizeof(s)))
    {
        int nReaderBytes = inFile.gcount(); //查看刚才读了多少子节
        cout << s.szName << " " << s.nScore << endl;
    }
    inFile.close();


    //读写文件
    //将students.dat文件中的Jane名字改为Mike
    fstream ioFile("students.dat", ios::in|ios::out|ios::binary);
    if(!ioFile)
    {
        cout << "error" << endl;
        return 0;
    }

    ioFile.seekp(2*sizeof(CStudent), ios::beg); //定位写指针到第三个记录
    ioFile.write("Mike", strlen("Mike")+1);
    ioFile.seekg(0, ios::beg); //定位到开头指针
    while(ioFile.read((char*) &s, sizeof(s)))
        cout << s.szName << " " << s.nScore << endl;
    ioFile.close();


    return 0;
}