#include "Algorithems.h"
vector<bool> algorithem_one(vector<bool>& array1, vector<bool>& array2)
{
    bool flag = true;
    vector<bool> m = array2;
    vector<bool> res = array1;
    do
    {
        for (int i = m.size()-1; i >= 0; i--)
        {
            if (m[i] == false)
                m[i] = true;
            else
            {
                m[i] = false;
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
vector<bool> algorithem_three(vector<bool>& array1, vector<bool>& array2)
{
    vector<bool>res(array1.size(),0);
    vector<bool>iter = array2;
    vector<bool> one(1, 1);
    while (iter.size() != 0)
    {
        res = algorithem_one(res, array1);
        iter = Subtract(iter, one);
    }
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
       

        vector<bool> n1m1 = algorithem_five(n1, m1); 
        vector<bool> n1m2 = algorithem_five(n1, m2);
        vector<bool> n2m1 = algorithem_five(n2, m1);
        vector<bool> n2m2 = algorithem_five(n2, m2);


        // Calc : 2^N * n1m1 + (2^(N/2) * (n1m2 + n2m1)) + (n2m2)

        // before sending to an algorithem we assume the numbers in the same size
        make_numbers_same_len(n1m2, n2m1); 
        vector<bool> mid_calc = algorithem_two(n1m2, n2m1);
        times(mid_calc, N/2);
        times(n1m1, N);
        // before sending to an algorithem we assume the numbers in the same size
        make_numbers_same_len(mid_calc, n1m1);
        mid_calc = algorithem_two(mid_calc, n1m1);
        // before sending to an algorithem we assume the numbers in the same size
        make_numbers_same_len(mid_calc, n2m2);
        vector<bool> res = algorithem_two(mid_calc, n2m2);
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

  

        vector<bool> F = algorithem_six(n1, m1);
        vector<bool> n1Plusn2 = algorithem_two(n1, n2);
        vector<bool> m1Plusm2 = algorithem_two(m1, m2);
        vector<bool> H = algorithem_six(n1Plusn2, m1Plusm2);
        vector<bool> G = algorithem_six(n2, m2);




        // Calc : 2^N * F + (2^(N/2) * (H-(F+G)) + (G)

        // before sending to an algorithem we assume the numbers in the same size
        //create F+G
        vector<bool> FPlusG = algorithem_two(F, G);
        vector<bool> mid_calc;
        int flag = checkBiggerNumber(H, FPlusG);
        if (flag == 0)
        {
            //handle error
            exit(1);
        }
        else if (flag == 1)
        {
            mid_calc = Subtract(H, FPlusG);
        }
        times(mid_calc, N / 2);
        //cout << "mid_calc after times ="; printArr(FPlusG);
        times(F, N);

        // before sending to an algorithem we assume the numbers in the same size
        //make_numbers_same_len(mid_calc, F);
        mid_calc = algorithem_two(mid_calc, F);

        // before sending to an algorithem we assume the numbers in the same size
        //make_numbers_same_len(mid_calc, G);
        vector<bool> res = algorithem_two(mid_calc, G);
        return res;
    }
}
vector<bool> algorithem_seven(vector<bool>& array1, vector<bool>& array2, vector<bool>& r)
{
    vector<bool> q(1, 1);
    vector<bool> one(1, 1);
    vector<bool> mulCheck;
    do
    {
        mulCheck = algorithem_four(array2, q);
        q = algorithem_two(q, one);
    } while (checkBiggerNumber(mulCheck, array1) == 0);
    q = Subtract(q, one);
    q = Subtract(q, one);
    mulCheck = algorithem_four(array2, q);
    r = Subtract(array1, mulCheck);
    return q;

}
vector<bool> algorithem_eight(vector<bool>& array1, vector<bool>& array2, vector<bool>& r)
{
    vector<bool> mid ; //q=n/2
    vector<bool> right = array1, left(1,0);
    vector<bool> one(1, 1);
    vector<bool> mulCheck;
    vector<bool> resCheck;
    do
    {
        mid = algorithem_two(right, left);
        mid = divideBytwo(mid);
        mulCheck = algorithem_four(array2, mid); //m*q
        if (checkBiggerNumber(mulCheck, array1) == 0) //m*q < n
        {
            left = mid;
            resCheck = algorithem_two(mulCheck, array2);
            if (checkBiggerNumber(resCheck, array1) == 1) //m*q +m > n
            {
                break;
            }
        }
        else if (checkBiggerNumber(mulCheck, array1) == 1) // m*q>n
        {
            right = mid;  
        }
        else
        {
            break;
        }

    } while (true);
    r = Subtract(array1, mulCheck);
    return mid;

}
void allHellBreaksloos(vector<bool>& array1, vector<bool>& array2, vector<bool>& r,ofstream& ofile)
{
    vector<bool>res;
    res = algorithem_one(array1, array2);
    printVecToFile(res, ofile);

    res = algorithem_two(array1, array2);
    printVecToFile(res, ofile);

    res = algorithem_three(array1, array2);
    printVecToFile(res, ofile);


    res = algorithem_four(array1, array2);
    printVecToFile(res, ofile);


    res = algorithem_five(array1, array2);
    printVecToFile(res, ofile);


    res = algorithem_six(array1, array2);
    printVecToFile(res, ofile);

    res = algorithem_seven(array1, array2, r);
    printVecToFile(res, ofile);
    printVecToFile(r, ofile);



    res = algorithem_eight(array1, array2, r);
    printVecToFile(res, ofile);
    printVecToFile(r, ofile);

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
        else if(num[i] == '0')
            res.push_back(false);
        else
        {
            cout << "Error: Invalid input" << endl;
            exit(1);
        }
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
void printVecToFile(vector<bool>& vec, ofstream& file)
{
    string vecToWrite;
    if (vec.size() > 0)
    {
        for (int i = 0; i <= vec.size() - 1; i++)
        {
            if (vec[i])
                vecToWrite.append("1");
            else
                vecToWrite.append("0");
        }
        file << vecToWrite << endl;
    }
    else
    {
        file << "0" << endl;
    }
}
vector<bool> Subtract(vector<bool>& array1, vector<bool>& array2)
{
    make_numbers_same_len(array1, array2);
    int len = array1.size();
    vector<bool> arr1cpy = array1;
    vector<bool> res(len, 0);
    bool curry = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (arr1cpy[i] == true && array2[i] == true) // 1 - 1
        {
            if (curry == 0)
                res[i] = 0;
            else
                res[i] = 1;
        }
        else if (arr1cpy[i] == true && array2[i] == false) // 1-0
        {
            res[i] = 1;
        }
        else if (arr1cpy[i] == false && array2[i] == true) //0-1
        {
            res[i] = 1;
            for (int  j = i-1;j>=0; j--)
            {
                if (arr1cpy[j] == false)
                {
                    arr1cpy[j] = true;
                }
                else
                {
                    arr1cpy[j] = false;
                    break;
                }
            }
        }
        else if (arr1cpy[i] == false && array2[i] == false) // 0 - 0
        {
            if (curry == 0)
                res[i] = false;
            else
            {
                res[i] = true;
                curry = 0;
            }
        }
    }
    /*if (curry == 1)
        res[0] = true;*/
    deleteZeros(res);
    return res;

}
int checkBiggerNumber(const vector<bool>& array1,const vector<bool>& array2)
{
    if (array1.size() > array2.size())
    {
        return 1;
    }
    else if (array2.size() > array1.size())
    {
        return 0;
    }
    //make_numbers_same_len(array1, array2)
    else
    {
        for (int i = 0; i < array1.size(); i++)
        {
            if (array1[i] && array2[i] || !array1[i] && !array2[i])
                continue;
            if (array1[i] && !array2[i])
                return 1;
            else if (!array1[i] && array2[i])
                return 0;
        }
        return 2;
    }
}
vector<bool> divideBytwo(vector<bool>& array1)
{
    vector<bool>& res(array1);
    res.pop_back();
    return res;
}


