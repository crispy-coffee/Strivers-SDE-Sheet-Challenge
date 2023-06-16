
#include <bits/stdc++.h>
//Brute force
/*
void maakacall(int index, string& str, vector<string>& result){

    if(index >= str.size()){
        result.push_back(str);
        return;
    }

    for(int i=index; i<str.size(); i++){
        swap(str[i], str[index]);
        maakacall(index+1, str, result);
        swap(str[i], str[index]);
    }

}

string kthPermutation(int n, int k) {
    // Write your code here.
    string str = "";
    vector<string> result;

    for(int i=1; i<=n; i++){
        str += to_string(i);
    }

    maakacall(0, str, result);
    sort(result.begin(), result.end());

    return result[k-1];
}
*/
string kthPermutation(int n, int k)
{
    // Write your code here.
    vector<int> numbers;
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
        numbers.push_back(i);
    }
    fact /= n; // making the boxes of size 24 / 4
    string ans = "";
    k = k - 1;
    while (1)
    {
        ans += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}