#include <bits/stdc++.h> 

int Recursion(vector<int>& coin, int amount){
    int count = 0;
    for(int i=0; i<coin.size(); i++){
        while(coin[i]<=amount){
            amount -= coin[i];
            count++;
        }
    }
    return count;
}



int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> coin = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

    return Recursion(coin, amount);

}
