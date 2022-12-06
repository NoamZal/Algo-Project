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

vector<bool> algorithem_five(vector<bool>& array1, vector<bool>& array2)
{
    int N = array1.size();
    if(N <= 128)
    {
        return algorithem_four(array1, array2);
    }

    else
    {
        vector<bool> n1 = first_half_array(array1);
        vector<bool> n2 = second_half_array(array1);
        vector<bool> m1 = first_half_array(array2);
        vector<bool> m2 = second_half_array(array2);

        vector<bool> n1m1 = algorithem_five(n1, m1);
        vector<bool> n1m2 = algorithem_five(n1, m2);
        vector<bool> n2m1 = algorithem_five(n2, m1);
        vector<bool> n2m2 = algorithem_five(n2, m2);

        // Calc : n1m2 + (2^(N/2) * (n1m2 + n2m1)) + 2^N * (n2m2)

        // before sending to an algorithem we assume the numbers in the same size
        make_numbers_same_len(n1m2, n2m1); 
        vector<bool> mid_calc = algorithem_two(n1m2, n2m1);
        times(mid_calc, N/2);
        times(n2m2, N);
        // before sending to an algorithem we assume the numbers in the same size
        make_numbers_same_len(mid_calc, n2m2);
        mid_calc = algorithem_two(mid_calc, n2m2);
        // before sending to an algorithem we assume the numbers in the same size
        make_numbers_same_len(mid_calc, n1m2);
        vector<bool> res = algorithem_two(mid_calc, n1m2);
        
    }

    
    

}
vector<bool> first_half_array(vector<bool>& array1)
{
    vector<bool> res;
    for (int i = 0; i < array1.size() / 2; i++)
    {
        res.push_back(array1[i]);
    }
    
}

vector<bool> second_half_array(vector<bool>& array1)
{
    vector<bool> res;
    for (int i = array1.size() / 2; i < array1.size(); i++)
    {
        res.push_back(array1[i]);
    }
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
void make_numbers_same_len(vector<bool>& array1, vector<bool>& array2)
{
    if(array1.size() > array2.size())
    {
        make_number(array1, array2.size());
    }
    else
    {
        make_number(array2, array1.size());
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


