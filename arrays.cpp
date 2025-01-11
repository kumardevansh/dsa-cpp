#include<bits/stdc++.h>
using namespace std;

int arr[6]; // this array defined globally, contains all elements as 0 unless specified
// int arr3[10^7]; -- maximum size of an array declared globally


vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans(2);
        map<int,int> mp;
        for(int i = 0; i<n; i++){
            // mp[i] = 0;
            mp[arr[i]]++;
        }

        int i = 1;
        for(auto it: mp){
            cout<<"it.first: "<<it.first<<" it.second: "<<it.second<<endl;
            if(it.second==2){
                // cout<<"if1"<<endl;
                ans[0] = it.first;
                // cout<<"if1 line2"<<endl;
            }
            // if(i!=it.first && i<n){
            //     cout<<"i: "<<i<<endl;
            //     ans[1] = i;
            //     return ans;
            // }
            // i++;
        }

        for(auto it: mp){
            if(i!=it.first && i<n){
                cout<<"i: "<<i<<endl;
                ans[1] = i;
                return ans;
            }
            else if( ans[1]==0) ans[1] = n;
            i++;
        }
        
        return ans;
}

int main(){
    int arr1[6]; // this contains garbage values which we can't predict
    // int arr2[10^6]; -- maximum size of an array in int main()


    vector<int> nums = {12 ,7 ,5 ,1 ,13 ,1 ,10 ,8 ,11 ,9 ,2 ,4 ,3 ,6};
    vector<int> temp =  findTwoElement(nums,14);
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " "; 
    }
    cout << "\n";
}