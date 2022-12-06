#include <fstream>
#include <iostream>
#include <string>
//#include <vector>
#include "Algorithems.h"
using namespace std;

int main(int argc, char** args)
{
    // ifstream file;
    // file.open(args[1]);
    // string line;
    // getline(file, line);
    // bool num_of_function = stoi(line);
    string str1,str2;
    int n = 10;

    cin >> str1;
    cin >> str2;
    vector<bool> array1 = setBoolArr(str1);
    vector<bool> array2 = setBoolArr(str2);
    vector<bool>res = algorithem_four(array1, array2);
    deleteZeros(res);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    //make_number(array1, n);
    //times(array1, m);
    //deleteZeros(array1);
    //int m = 3;
}
