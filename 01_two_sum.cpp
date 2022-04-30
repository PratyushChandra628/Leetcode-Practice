#include<bits/stdc++.h>
using namespace std;

// Two sum function
// requires vector of int as answer
// basically stores the pair of index which gives us the target
vector<int> pairSum(vector<int> nums, int target) {
    // declaring the hash table
    unordered_map<int,int> s;
    vector<int> result;

    // we iterate in the nums vector
    for(int i=0;i<nums.size();i++) {
     
     // x is number to find
     int x = target-nums[i];

    // if x is found in set, return them

    // we check if the remaining value exist in hash table or not
    // if our value is present it will not point to s.end()
    // s.end() means iterator pointing to element right after the last element in hash table
     if(s.find(x)!=s.end()) {
         // we store the index from the map of the remaining element
         result.push_back(s[x]);
         // the other index is the current index i
         result.push_back(i);
         return result;
         }

        // if the above IF is not executed
        // we have to store the current (nums of i) in the hash table
        // key is nums[i]
        // index i is the value
         s[nums[i]]=i;
    }
    // in case we don't get our pair
    // we return answer which is an empty vector
    return {};
}

int main() {

    vector<int> nums{10, 5, 2, 3, -6, 9, 11};
    int S =4;

    auto p = pairSum(nums,S);
    if(p.size()==0) {
        cout<<"no such pair";
    }
    else{
        cout<<p[0]<<","<<p[1]<<endl;
    }

    return 0;
}
