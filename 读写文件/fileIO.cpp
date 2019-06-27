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
        while ( getline (file,line) )
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

    //重定向方式读区
    freopen("some.txt","r",stdin);
    char* buff = new char[20];
=    while(cin.getline(buff, 20))
    {
        cout << buff << endl;
    }
    
    return 0;
}
