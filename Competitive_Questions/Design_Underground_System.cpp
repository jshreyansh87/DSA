// Problem Statement  =>   https://leetcode.com/problems/design-underground-system/


#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
public:
    map <int, vector <pair <string, int>>> person;
    map <string, vector <pair <string, int>>> station;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        vector <pair <string, int>> v;
        
        v.push_back({stationName, t});
        
        person[id] = v;
    }
    
    void checkOut(int id, string stationName, int t) {
        pair <string, int> v;
        
        for(auto i: person[id]){
            v = { stationName, t - i.second };
            
            station[i.first].push_back(v);
        }
        
        person.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        double count = 0, tot = 0;
        
        for(int i = 0; i < station[startStation].size(); i++){
            if(station[startStation][i].first == endStation){
                tot += station[startStation][i].second;
                count++;
            }
        }
        
        return tot / count;
    }
};