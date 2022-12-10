#include <fstream>
#include <iostream>
#include <string>
#include "Algorithems.h"
using namespace std;

int main(int argc, char** argv)
{
    ifstream file(argv[1]);
    ofstream ofile;
    ofile.open(argv[2]);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file" << std::endl;
        return 1;
    }
    string num1,num2,choice;
    getline(file, choice);
    getline(file, num1);
    getline(file, num2);
    vector<bool>array1 = setBoolArr(num1);
    vector<bool>array2 = setBoolArr(num2);
    vector<bool>res;
    vector<bool> r;
    int algoChoice = stoi(choice);
    switch (algoChoice)
    {
    case 1:
        res = algorithem_one(array1, array2);
        printVecToFile(res, ofile);
        break;
    case 2:
        res = algorithem_two(array1, array2);
        printVecToFile(res, ofile);

        break;
    case 3:
        res = algorithem_three(array1, array2);
        printVecToFile(res, ofile);

        break;
    case 4:
        res = algorithem_four(array1, array2);
        printVecToFile(res, ofile);

        break;
    case 5:
        res = algorithem_five(array1, array2);
        printVecToFile(res, ofile);

        break;
    case 6:
        res = algorithem_six(array1, array2);
        printVecToFile(res, ofile);

        break;
    case 7:
        res = algorithem_seven(array1, array2,r);
        printVecToFile(res, ofile);
        printVecToFile(r, ofile);
        break;
    case 8:
        res = algorithem_eight(array1, array2,r);
        printVecToFile(res, ofile);
        printVecToFile(r, ofile);
        break;
    case 9:
        allHellBreaksloos(array1, array2, r,ofile);
        break;
    default:
        //error
        break;
    }
    ofile.close();
    file.close();
}
