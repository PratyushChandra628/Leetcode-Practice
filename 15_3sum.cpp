#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > threeSum (vector<int> &num) {
    
    // sorting array to apply 2 pointer approach
    sort(num.begin(),num.end());
    
    // declaring vector of vectors which is gonna be vector that we return
    vector<vector <int> > result;

    // moves for a
    // i starts at 0 and goes on upto third last element
    for(int i=0;i<num.size()-2;i++) {
        
        // checking for duplicates of a
        // || stands for OR
        if(i==0 || (i>0 && num[i]!=num[i-1])) {
           // 2 pointer approach
           // intitally low assigned to i+1 (leftmost pointer)
           // high assigned to num.size()-1 (rightmost pointer)
           // sum is 0-num[i] i.e. -a
           int lo = i+1, hi = num.size()-1, sum=0-num[i];

           // condition on loop till low is less than high
           while(lo<hi) {
               if(num[lo]+num[hi]==sum) {
                  
                  // if above condition satisfied
                  // we get our triplet
                  // putting it into a vector
                  vector<int> temp;
                  temp.push_back(num[i]);
                  temp.push_back(num[lo]);
                  temp.push_back(num[hi]);
                  result.push_back(temp);

                  // we need to make sure we ignore all the duplicates
                  // making sure no more duplicates of low being considered 
                  // && stands for AND
                  while(lo < hi && num[lo] == num[lo+1]) lo++;
                  // making sure no more duplicates of high being considered
                  while(lo < hi && num[hi] == num[hi-1]) hi--;

                  
                  // new index of low
                  lo++;
                  // new index of hi 
                  hi--;
               }
               // condition when our sum is less than num[i]
               else if(num[lo]+num[hi] < sum) {
                   lo++;
               }
               else {
                   hi--;
               }
           }
        }
    }
    return result;
}

int main() {
    
//    vector<int> num = {1,2,3,4,5,6,7,8,9, 15, 10,11};

//     vector<vector<int>> result = threeSum(num);

//     for(int i = 0; i < result.size(); i++){
//         for(int j = 0; j < result[0].size(); j++){
//             cout << result[i][j] << ",";
//         }
//         cout << endl;
//     }
//     return 0;


     vector<int> num = {-2,-2,-1,-1,-1,0,0,0,2,2,2};


     auto results = threeSum(num);

     for(auto v:results) {
         for(auto number:v) {
             cout<<number<<",";
         }
         cout<<endl;
     }
     return 0;
}
