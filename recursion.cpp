#include<bits/stdc++.h>

using namespace std;

void print(int i, int n){// print name n times
    if(i>n){
        return;
    }
    cout<<"Devansh"<<endl;
    print(i+1,n);
}// time complexity - O(n)

// print 1-n using backtracking
void print1toN(int i, int n){
    if(i<1){
        return;
    }
    print1toN(i-1,n);
    cout<<i<<endl;
}

// print n-1 using backtracking
void printNto1(int i,int n){
    if(i>n){
        return;
    }
    printNto1(i+1,n);
    cout<<i<<endl;
}

// sum of first n numbers
int sumOfN(int n){
    if(n==0){
        return 0;
    }
    return n + sumOfN(n-1);
}

// reverse an array
void reverseArray(int i, int arr[], int n){
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    reverseArray(i+1,arr,n);
}

bool checkPalindrome(int i, string &s){
    if(i>=s.size()/2) return true;
    if(s[i] != s[s.size()-i-1]) return false;
    checkPalindrome(i+1,s);
}

int main(){
    int n;
    string s;
    // cout << "line 48";
    // cout << "enter the value of n: ";
    // cin >> n;
    // int arr[n];
    // print(1,n);
    // print1toN(n,n);
    // printNto1(1,n);
    // cout<<endl<< "sum:"<< sumOfN(n)<< endl;
    // cout<< "enter size of array: "<<endl;
    // int lenArr;
    // cin >> lenArr;
    // cout<< "enter array elements: "<< endl;
    // for (int i = 0; i < lenArr; i++) cin >> arr[i];
    // reverseArray(0,arr,lenArr);
    // for (int i = 0; i < lenArr; i++) cout << arr[i] << " ";
    cout<< endl << "enter string to check for palindrome: ";
    cin>> s;
    cout<<checkPalindrome(0,s);
}