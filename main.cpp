#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include "Algorithems.h"
using namespace std;
using namespace std::chrono;
void testForCheck();

int main(int argc, char** argv)
{

    /*ifstream file(argv[1]);
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
    if (num1.empty() || num2.empty())
    {
        cout << ("Error: invalid input,missing number") << endl;
        exit(1);
    }
    vector<bool>array1 = setBoolArr(num1);
    vector<bool>array2 = setBoolArr(num2);
    vector<bool>res;
    vector<bool> r;
    int algoChoice = stoi(choice);
    if (algoChoice < 1 || algoChoice > 9)
    {
        cout <<("Error: invalid input") << endl;
        exit(1);
    }
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
    }
    ofile.close();
    file.close();*/
    testForCheck();
}
void testForCheck()
{
    int N = 2;
    vector<bool> num1;
    vector<bool> num2;
    vector<bool> stam;
    vector<bool> flags(8, 0);
    vector<int> res(8,0);
    while (N<= 2048)
    {
        num1.clear();
        num2.clear();
        num1.push_back(1);
        num2.push_back(1);
        for (int i = 1; i < N; i++)
        {
            num1.push_back(rand() % 2);
            num2.push_back(rand() % 2);
        }
        if (!flags[0])
        {
            auto start = chrono::high_resolution_clock::now();
            algorithem_one(num1, num2);
            auto stop = chrono::high_resolution_clock::now();
            auto duration = duration_cast<minutes>(stop - start);
            if (duration.count() > 1)
            {
                res[0] = N;
                flags[0] = true;
            }
        }
        if (!flags[1])
        {
            auto start = chrono::high_resolution_clock::now();
            algorithem_two(num1, num2);

            auto stop = chrono::high_resolution_clock::now();

            auto duration = duration_cast<minutes>(stop - start);

            if (duration.count() > 1)
            {
                res[1] = N;
                flags[1] = true;

            }
        }
        if (!flags[2]) {
            auto start = chrono::high_resolution_clock::now();
            algorithem_three(num1, num2);
            auto stop = chrono::high_resolution_clock::now();

            auto duration = duration_cast<minutes>(stop - start);
            if (duration.count() > 1)
            {
                res[2] = N;
                flags[2] = true;

            }
        }
        if (!flags[3]) {
            auto start = chrono::high_resolution_clock::now();
            algorithem_four(num1, num2);
            auto stop = chrono::high_resolution_clock::now();

            auto duration = duration_cast<minutes>(stop - start);
            if (duration.count() > 1)
            {
                res[3] = N;
                flags[3] = true;

            }
        }
        if (!flags[4]) {
            auto start = chrono::high_resolution_clock::now();
            algorithem_five(num1, num2);
            auto stop = chrono::high_resolution_clock::now();

            auto duration = duration_cast<minutes>(stop - start);
            if (duration.count() > 1)
            {
                res[4] = N;
                flags[4] = true;

            }
        }
        if (!flags[5]) {
            auto start = chrono::high_resolution_clock::now();
            algorithem_six(num1, num2);
            auto stop = chrono::high_resolution_clock::now();

            auto duration = duration_cast<minutes>(stop - start);
            if (duration.count() > 1)
            {
                res[5] = N;
                flags[5] = true;

            }
        }
        if (!flags[6])
        {
            auto start = chrono::high_resolution_clock::now();
            algorithem_seven(num1, num2, stam);
            auto stop = chrono::high_resolution_clock::now();

            auto duration = duration_cast<minutes>(stop - start);
            if (duration.count() > 1)
            {
                res[6] = N;
                flags[6] = true;

            }
        }
        if (!flags[7])
        {
            auto start = chrono::high_resolution_clock::now();
            algorithem_eight(num1, num2, stam);
            auto stop = chrono::high_resolution_clock::now();

            auto duration = duration_cast<minutes>(stop - start);
            if (duration.count() > 1)
            {
                res[7] = N;
                flags[7] = true;

            }
        }
        N *= 2;
        cout << N << endl;
    }
    for (int i = 0; i <8; i++)
    {
        cout << "Res for algo num " << i+1 << " : " << res[i] << endl;
    }
}
