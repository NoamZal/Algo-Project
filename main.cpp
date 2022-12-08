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
    Subtract(array1, array2);
    //vector<bool> res1 = algo_one(array1, array2);
    //vector<bool>res = algorithem_four(array1, array2);
    vector<bool>res5 = algorithem_five(array1, array2);
    //deleteZeros(res5);
    cout << "\n";
    for (int i = 0; i < res5.size(); i++)
    {
        cout << res5[i];
    }
    //make_number(array1, n);
    //times(array1, m);
    //deleteZeros(array1);
    //int m = 3;
}
