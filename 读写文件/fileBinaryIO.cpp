#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    // out flie
    ofstream ofile("test.txt", ios::out|ios::binary);
    if (ofile.is_open())
    {
        int x = 10;
        ofile.seekp(20, ios::beg);
        ofile.write((const char*)(&x), sizeof(int));
    }
    ofile.close();
    
    // ifile
    ifstream file("test.txt", ios::in|ios::binary);
    string line;
    if (file.is_open())
    {
        int x;
        file.seekg(20, ios::beg);
        file.read((char*)(&x), sizeof(int));
        cout << x << endl;
        file.close();
    }
    return 0;
}
