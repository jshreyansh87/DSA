// Problem Statement  =>   https://leetcode.com/problems/distance-between-bus-stops/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        
        if(start == destination)
            return 0;
        
        if(start > destination){
            int temp = destination;
            destination = start;
            start = temp;
        }
        
        
        int dist1 = 0, dist2 = 0;
        for(int i = start; i < destination; i++){
            dist1 += distance[i];
        }
        
        for(int i = start - 1; i >=0; i--){
            dist2 += distance[i];
        }
        for(int i = destination; i < distance.size(); i++){
            dist2 += distance[i];
        }
        
        if(dist1 > dist2){
            return dist2;
        }
        else{
            return dist1;
        }
        
        return 0;
    }
};