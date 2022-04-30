// #include<iostream>
// #include<vector>
// using namespace std;


// int highest_mountain(vector<int> a){
// 	int n = a.size();

// 	int largest = 0;

// 	for(int i=1;i<=n-2;){

// 		//check a[i] is peak or not
// 		if(a[i]>a[i-1] and a[i]>a[i+1]){
// 			//do some work
// 			int cnt = 1;
// 			int j = i;
// 			//cnt backwards (left)
// 			while(j>=1 and a[j]>a[j-1]){
// 				j--;
// 				cnt++;
// 			}
// 			//cnt forwards (right)
// 			while(i<=n-2 and a[i]>a[i+1]){
// 				i++;
// 				cnt++;
// 			}
// 			largest = max(largest,cnt);

// 		}
// 		else{
// 			i++;
// 		}
// 	}
// 	return largest;

// }

// int main(){

// 	vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

// 	cout<< highest_mountain(arr)<<endl;



// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int highest_mountain(vector<int> a) {
    
    // dynamic size of array
    int n = a.size();

    // keeping a track of largest so far
    int largest = 0;

    // starting from first positin and ending at second last position
    // putting i=0 can give a segmentation fault, similar for ending at n-2
    for(int i=1;i<=n-2;) {
     
        // check whether a[i] is a peak or not
        if(a[i] > a[i-1] and a[i] > a[i+1]) {
            
            // some work
            int count = 1;
            int j = i;

            // count backwards (left)
            while(j>=1 and a[j]>a[j-1]) {
                j--;
                count++;
            }
            // count forwards (right)
            while(i<=n-2 and a[i]>a[i+1]) {
                i++;
                count++;
            }
            largest = max(largest,count);
        }
        // if not a peak we move on to next element
        else {
            i++;
        }
    }
    return largest;
}

int main() {

    vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

    cout<<highest_mountain(arr)<<endl;

    return 0;
}