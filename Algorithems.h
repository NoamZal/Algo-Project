#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <math.h>
#include <string.h>

using namespace std;

vector<bool> algorithem_one(vector<bool>& array1, vector<bool>& array2);
vector<bool> algorithem_two(vector<bool>& array1, vector<bool>& array2);
vector<bool> algorithem_three(vector<bool>& array1, vector<bool>& array2);
vector<bool> algorithem_four(vector<bool>& array1, vector<bool>& array2);
vector<bool> algorithem_five(vector<bool>& array1, vector<bool>& array2);
vector<bool> algorithem_six(vector<bool>& array1, vector<bool>& array2);
vector<bool> algorithem_seven(vector<bool>& array1, vector<bool>& array2, vector<bool>& r);
vector<bool> algorithem_eight(vector<bool>& array1, vector<bool>& array2, vector<bool>& r);
void allHellBreaksloos(vector<bool>& array1, vector<bool>& array2, vector<bool>& r, ofstream& ofile);
vector<bool> addOne(const vector<bool>& array1);

vector<bool> setBoolArr(string num);
void make_number(vector<bool>& number, int sizeToGetTo);
void times(vector<bool>& number, int pow);
void deleteZeros(vector<bool>& number);
void make_numbers_same_len(vector<bool>& array1, vector<bool>& array2);
vector<bool> first_half_array(vector<bool>& array1);
vector<bool> second_half_array(vector<bool>& array1);
void printArr(vector<bool>& vec);
void printVecToFile(vector<bool>& vec, ofstream& file);
vector<bool> Subtract(vector<bool>& array1, vector<bool>& array2);
int checkBiggerNumber(const vector<bool>& array1, const vector<bool>& array2);
vector<bool> divideBytwo(vector<bool>& array1);
//int decodeBoolArr(BoolArr numToDecode);



