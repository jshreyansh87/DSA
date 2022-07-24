// Problem Statement  => https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1

#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       // traverse the array and calculate petrol - distance to check if travel is possible from current petrol pump to next one, store the balance petrol left at each travel, if balance
       // is less than 0 then travel from starting petrol pump to current petrol pump is not possible, so store this -ve balance in deficit which represents the amount of petrol required to cover
       // such travels
       int deficit = 0;
       int balance = 0;
       int start = 0;
       
       // for each petrol pump
       for(int i = 0; i < n; i++){
           // find the balance petrol
           balance += p[i].petrol - p[i].distance;
           // if balance is -ve then travel from start to current pump is not possible
           if(balance < 0){
               // so store this -ve balance in deficit
               deficit += balance;
               // update balance to 0 and put start at next petrol pump from the current petrol pump
               balance = 0;
               start = i + 1;
           }
       }
       
       // once all the petrol pump are visited add the balance and deficit to check if the deficit can now be covered if yes then return this start point, else return -1
       if(balance + deficit >= 0){
           return start;
       }
       else{
           return -1;
       }
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}