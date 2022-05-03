// Problem Statement  =>   https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int currProfit = 0, maxProfit = 0, smallestPrice = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < smallestPrice){
                smallestPrice = prices[i];
            }
            
            currProfit = prices[i] - smallestPrice;
            
            if(currProfit > maxProfit){
                maxProfit = currProfit;
            }
        }
        
        return maxProfit;
    }
};