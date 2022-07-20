// Problem Statement  => https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
    // take 2 variables to store the lowestPrice observed till now and 
    // maxProfit to store the maximum profit observed till now
    int lowestPrice = INT_MAX, maxProfit = INT_MIN;
    
    // traverse the array
    for(int i = 0; i < prices.size(); i++){
        // if curr price is smaller than lowest price then update lowest price
        if(prices[i] < lowestPrice){
            lowestPrice = prices[i];
        }
        
        // find profit at current prrice
        int currProfit = prices[i] - lowestPrice;
        
        // compare with maxProfit observed till now
        if(currProfit > maxProfit){
            maxProfit = currProfit;
        }
    }
    
    return maxProfit;
}