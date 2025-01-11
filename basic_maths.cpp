#include<bits/stdc++.h>

using namespace std;

// Extraction of digits

int count(int n){//count the number of digits of a given number
    int cnt = 0;
    while (n>0)
    {
        int lastDigit = n%10;
        cnt+=1;
        n = n/10;
    }
    // OR
    // int cnt = (int) log10(n) + 1;
    return cnt;
}// time complexity in both cases - O(log10(n))

int reverseNum(int n){
    int revNum = 0;
    while (n>0)
    {
        int lastDigit = n%10;
        revNum = (revNum * 10) + lastDigit;
        n = n/10;
    }
    return revNum;
}

bool checkPalindrome(int n){
    int revNum = 0;
    int duplicateOfn = n;
    while (n>0)
    {
        int lastDigit = n%10;
        revNum = (revNum * 10) + lastDigit;
        n = n/10;
    }
    if(revNum==duplicateOfn) return true;
    else return false;
}

bool checkArmstrongNum(int n){// armstrong number e.g. 371 = 3^3 + 7^3 + 1^3, no. equals the sum of digits raised to the power count of digits,
    // int revNum = 0;
    int sum = 0;
    // int cnt = 0;
    int cnt = (int) log10(n) + 1;
    int duplicateOfn = n;
    while (n>0)
    {
        int lastDigit = n%10;
        // cnt += 1;
        // revNum = (revNum * 10) + lastDigit;
        sum = sum + pow(lastDigit,cnt);
        n = n/10;
    }
    if(sum==duplicateOfn) return true;
    else return false;
}

void checkPrime(int n){
    int cnt = 0;
    for (int i = 1; i*i <= n; i++){
        if (n%i==0){
            cnt++;
            if ((n/i)!=i) cnt++;// time complexity = O(sqrt(n))
        }   
    }
    if (cnt==2){
        cout << "true"<< endl;
    }
    else cout << "false"<< endl;
}

int main(){
    int counter = count(45699);
    cout<<"number of digits = "<< counter << endl;
    int revNum = reverseNum(7789);
    cout<<"reverse number = "<< revNum << endl;
    bool palin = checkPalindrome(1221);
    cout<<"is plaindrome = "<< palin << endl;
    bool armstrongNum = checkArmstrongNum(1634);//1634 = (1^4 + 6^4 + 3^4 + 4^4)
    cout<<"is armstrong number = "<< armstrongNum << endl;
    checkPrime(10);
}