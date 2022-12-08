#include "Algorithems.h"
vector<bool> algo_one(vector<bool>& n, vector<bool>& m)
{
    bool flag = true;
    vector<bool> array2;
    vector<bool> res = n;
    do
    {
        for (int i = array2.size()-1; i >= 0; i--)
        {
            if (array2[i] == false)
                array2[i] = true;
            else
            {
                array2[i] = false;
                flag = true;
                break;
            }
            flag = false;
        }
        if (!flag)
            break;
        for (int i = res.size() - 1; i >= 0; i--)
        {
            if (res[i] == true)
                res[i] = false;
            else
            {
                res[i] = true;
                break;
            }
            if(i==0)
                res.insert(res.begin(), true);
        }
    } while (flag);
    return res;
    
}
vector<bool> algorithem_two(vector<bool>& array1, vector<bool>& array2)
{
    make_numbers_same_len(array1, array2);
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
    deleteZeros(res);
    return res;
}
vector<bool> algo_three(vector<bool>  n, vector<bool>  m)
{
    vector<bool>res;
    return res;
}
vector<bool> algorithem_four(vector<bool>& array1, vector<bool>& array2)
{
    int len = array2.size();
    
    vector<bool> res(len*3,0);
    vector<bool> curr_sum;
    int k = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        bool digit = array2[i];
        if (digit == 0)
        {
            k++;
            continue;
        }
        else
        {
            curr_sum = array1;
            times(curr_sum, k);
            make_numbers_same_len(curr_sum,res);
            res = algorithem_two(curr_sum,res);
        }
        k++;
    }
    deleteZeros(res);
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
        cout << "n1 ="; printArr(n1);
        cout << "n2 ="; printArr(n2);
        cout << "m1 ="; printArr(m1);
        cout << "m2 ="; printArr(m2);

        vector<bool> n1m1 = algorithem_five(n1, m1); 
        vector<bool> n1m2 = algorithem_five(n1, m2);
        vector<bool> n2m1 = algorithem_five(n2, m1);
        vector<bool> n2m2 = algorithem_five(n2, m2);

        cout << "n1m1 ="; printArr(n1m1);
        cout << "n2m1 ="; printArr(n2m1);
        cout << "n1m2 ="; printArr(n1m2);
        cout << "n2m2 ="; printArr(n2m2);


        // Calc : 2^N * n1m1 + (2^(N/2) * (n1m2 + n2m1)) + (n2m2)

        // before sending to an algorithem we assume the numbers in the same size
        make_numbers_same_len(n1m2, n2m1); 
        vector<bool> mid_calc = algorithem_two(n1m2, n2m1);
        cout << "mid_calc ="; printArr(mid_calc);
        times(mid_calc, N/2);
        cout << "mid_calc after times ="; printArr(mid_calc);

        times(n1m1, N);
        cout << "n2m2 after times ="; printArr(n1m1);

        // before sending to an algorithem we assume the numbers in the same size
        make_numbers_same_len(mid_calc, n1m1);
        mid_calc = algorithem_two(mid_calc, n1m1);
        cout << "midcalc +n2m2 after times ="; printArr(mid_calc);

        // before sending to an algorithem we assume the numbers in the same size
        make_numbers_same_len(mid_calc, n2m2);
        vector<bool> res = algorithem_two(mid_calc, n2m2);
        cout << "midcalc +n1m2  ="; printArr(res);
        return res;
    }
}
vector<bool> algorithem_six(vector<bool>& array1, vector<bool>& array2)
{
    int N = array1.size();
    if (N <= 128)
    {
        return algorithem_four(array1, array2);
    }
    else
    {
        vector<bool> n1 = first_half_array(array1);
        vector<bool> n2 = second_half_array(array1);
        vector<bool> m1 = first_half_array(array2);
        vector<bool> m2 = second_half_array(array2);

        cout << "n1 ="; printArr(n1);
        cout << "n2 ="; printArr(n2);
        cout << "m1 ="; printArr(m1);
        cout << "m2 ="; printArr(m2);

        vector<bool> F = algorithem_six(n1, m1);
        vector<bool> n1Plusn2 = algorithem_two(n1, n2);
        vector<bool> m1Plusm2 = algorithem_two(m1, m2);
        vector<bool> H = algorithem_six(n1Plusn2, m1Plusm2);
        vector<bool> G = algorithem_six(n2, m2);

        cout << "n1m1 ="; printArr(F);
        cout << "n1+n2 ="; printArr(n1Plusn2);
        cout << "m1+m2 ="; printArr(m1Plusm2);
        cout << "n2m2 ="; printArr(G);


        // Calc : 2^N * n1m1 + (2^(N/2) * (n1m2 + n2m1)) + (n2m2)

        // before sending to an algorithem we assume the numbers in the same size
        vector<bool> mid_calc = algorithem_two(F, G);
        cout << "mid_calc ="; printArr(mid_calc);
        times(mid_calc, N / 2);
        cout << "mid_calc after times ="; printArr(mid_calc);

        times(F, N);
        cout << "n2m2 after times ="; printArr(F);

        // before sending to an algorithem we assume the numbers in the same size
        make_numbers_same_len(mid_calc, F);
        mid_calc = algorithem_two(mid_calc, F);
        cout << "midcalc +n2m2 after times ="; printArr(mid_calc);

        // before sending to an algorithem we assume the numbers in the same size
        make_numbers_same_len(mid_calc, G);
        vector<bool> res = algorithem_two(mid_calc, G);
        cout << "midcalc +n1m2  ="; printArr(res);
        return res;
    }
}

vector<bool> first_half_array(vector<bool>& array1)
{
    vector<bool> res;
    for (int i = 0; i < array1.size() / 2; i++)
    {
        res.push_back(array1[i]);
    }
    return res;
    
}

vector<bool> second_half_array(vector<bool>& array1)
{
    vector<bool> res;
    for (int i = array1.size() / 2; i < array1.size(); i++)
    {
        res.push_back(array1[i]);
    }
    return res;
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
        make_number(array2, array1.size());
    }
    else
    {
        make_number(array1, array2.size());
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
void printArr(vector<bool>& vec)
{
    for (int i = 0; i < vec.size();  i++)
    {
        cout << (vec[i]);
    }
    cout << "\n";
}
vector<bool> Subtract(vector<bool>&array1, vector<bool>& array2)
{
    make_numbers_same_len(array1, array2);
    int len = array1.size();
    vector<bool> res(len + 1, 0);
    bool curry = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (array1[i] == true && array2[i] == true) // 1 - 1
        {
            if (curry == 0)
                res[i + 1] = 0;
            else
                res[i + 1] = 1;
            //curry = 1;
        }
        else if (array1[i] == true && array2[i] == false) // 1-0
        {
            res[i + 1] = 1;
        }
        else if (array1[i] == false && array2[i] == true) //0-1
        {
            array1[i - 1]
        }
        else if (array1[i] == false && array2[i] == false) // 0 - 0
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
    deleteZeros(res);
    return res;
}


