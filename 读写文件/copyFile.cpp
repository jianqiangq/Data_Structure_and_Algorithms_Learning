// 实现文件拷贝功能
// copyFile src.dat dest.dat
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout << "file name missing!" << endl;
		return 0;
	}

	ifstream inFile(argv[1], ios::binary|ios::in); //打开文件用于读
	if(! inFile)
	{
		cout << "source file open error." << endl;
		return 0;
	}

	ofstream outFile(argv[2], ios::binary|ios::out); //打开文件用于写
	if(!outFile)
	{
		cout << "new file open error." << endl;
		inFile.close();
		return 0;
	}

	char c;
	while(inFile.get(c)) //每次读取一个字符
		outFile.put(c);  //每次写入一个字符

    //每次读多个字节
    /************************
    inFile.seekg(0, ios::end);
    long length = inFile.tellg();  //获取文件长度
    inFile.seekg(0, ios::beg);     //文件指针定位到开头

    int loops = pos / 5;       //读文件次数，每次读5个字节
    int leaveBytes = pos % 5;  //最后还剩几个字节

    string str;
    for(int i = 0; i < loops; i++)
    {
        if(inFile.read((char*)&str, 5))
            outFile.write((char*)&str, 5);
    }

    if(leaveBytes != 0)
    {
	    if(inFile.read((char*)&str, leaveBytes))
	        outFile.write((char*)&str, leaveBytes);
    }
    ************************/


	outFile.close();
	inFile.close();
	return 0;

} 




//另外一种写法
// #include<iostream>
// #include<fstream>
// using namespace std ;
// void Tranfile( char* pszFileCopee, char* pszFileCoper )
// {
//     fstream fsCopee( pszFileCopee, ios::binary | ios::in ) ;
//     fstream fsCoper( pszFileCoper, ios::binary | ios::out ) ;
//     fsCoper << fsCopee.rdbuf() ;
// }
// int main() {
//     Tranfile("students.dat", "test.txt");
// }