#include "Algorithems.h"
//vector<bool>  algo_one(vector<bool>& n, vector<bool>& m)
//{
//
//}
vector<bool> algorithem_two(vector<bool>& array1, vector<bool>& array2)
{
    int len = array1.size();
    vector<bool> res(len + 1, 0);
    bool curry = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (array1[i] == true && array2[i] == true) // 1 + 1
        {
            if (curry == 0)
                res[i + 1] = 0;
            else
                res[i + 1] = 1;
            curry = 1;
        }
        else if ((array1[i] == false && array2[i] == true) // 1 + 0 
            || (array1[i] == true && array2[i] == false))
        {
            if (curry == 0)
                res[i + 1] = 1;
            else
                res[i + 1] = 0;

        }
        else if (array1[i] == false && array2[i] == false) // 0 + 0
        {
            if (curry == 0)
                res[i + 1] = 0;
            else
            {
                res[i + 1] = true;
                curry = 0;
            }
        }
    }
    if (curry == 1)
        res[0] = true;
    return res;
}
//int  algo_three(vector<bool>  n, vector<bool>  m)
//{
//
//}
vector<bool> algorithem_four(vector<bool>& array1, vector<bool>& array2)
{
    int len = array1.size();
    
    vector<bool> res(len*3,0);
    vector<bool> curr_sum;
    int k = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        bool digit = array1[i];
        if (digit == 0)
            continue;
        else
        {
            curr_sum = array2;
            times(curr_sum, k);
            make_number(curr_sum,res.size());
            res = algorithem_two(curr_sum,res);
        }
        k++;
    }
    return res;
}
int  algo_five(vector<bool> n, vector<bool> m)
{

}
vector<bool> setBoolArr(string num)
{
    vector<bool> res;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == '1')
            res.push_back(true);
        else
            res.push_back(false);
    }
    return res;
}
void make_number(vector<bool>& number,int sizeToGetTo)
{
    while (number.size() < sizeToGetTo)
    {
        number.insert(number.begin(), false);
    }
}
void times(vector<bool>& number, int pow)
{
    for (int i = 0; i < pow; i++)
    {
        number.push_back(false);
    }
}
void deleteZeros(vector<bool>& number)
{
    int size = number.size();
    for (int i = 0; i <size; i++)
    {
        if (number[0] == false)
            number.erase(number.begin());
        else
            break;
    }
}


