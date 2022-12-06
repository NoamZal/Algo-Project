#include <fstream>
#include <iostream>
#include <string>
//#include <vector>
#include "Algorithems.h"
using namespace std;

//vector<bool> algorithem_four(vector<bool> array1, vector<bool> array2)
//{
//    int len = array1.size();
//    vector<bool> res;
//    vector<bool> curr_sum;
//    int k = 0;
//    for (int i = len - 1; i >= 0; i--)
//    {
//        bool digit = array1[i];
//        if (digit == 0)
//            continue;
//        else
//        {
//            //res = algorithem_two(algorithem_two(res, array1), make_number(times(2, k)));
//        }
//        k++;
//    }
//    //      curr_sum = algorithem_three(make_number(digit), array2) * make_number(pow(2, i))
//    //      res = algorithrm_two(curr_sum, res)
//
//    return res;
//}

//vector<bool> algorithem_two(vector<bool> array1, vector<bool> array2)
//{
//    int len = array1.size();
//    vector<bool> res(len + 1, 0);
//    bool curry = 0;
//    for (int i = len - 1; i >= 0; i--)
//    {
//        if (array1[i] == true && array2[i] == true) // 1 + 1
//        {
//            if (curry == 0)
//                res[i + 1] = 0;
//            else
//                res[i + 1] = 1;
//            curry = 1;
//        }
//        else if ((array1[i] == false && array2[i] == true) // 1 + 0 
//            || (array1[i] == true && array2[i] == false))
//        {
//            if (curry == 0)
//                res[i + 1] = 1;
//            else
//                res[i + 1] = 0;
//
//        }
//        else if (array1[i] == false && array2[i] == false) // 0 + 0
//        {
//            if (curry == 0)
//                res[i + 1] = 0;
//            else
//            {
//                res[i + 1] = true;
//                curry = 0;
//            }
//        }
//    }
//    if (curry == 1)
//        res[0] = true;
//    return res;
//}
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
