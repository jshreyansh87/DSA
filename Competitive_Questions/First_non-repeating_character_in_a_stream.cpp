// Problem Statement => https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    string ans = "";
		    // map to count the frequency of chars
		    unordered_map <char, int> count;
		    // queue to store the visited elements
		    queue <char> q;
		    
		    int size = A.length();
		    for(int i = 0; i < size; i++){
		        char curr = A[i];
		        // update frequncy
		        count[curr]++;
		        // push in queue
		        q.push(curr);
		        
		        // while queue is not empty
		        while(!q.empty()){
		            // if front element of queue is repeating then pop it
		            if(count[q.front()] > 1){
		                q.pop();
		            }
		            // else push in ans and break this while loop
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        // check if q is empty if yes then push # in ans
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    
		    return ans;
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}