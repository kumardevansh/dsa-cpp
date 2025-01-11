#include<iostream>
#include<algorithm>// for algorithms like binary search
#include<bits/stdc++.h> /* it contains all libraries like vector ,array , string . 
So you don't need to write different header files for different data structure again & again */

using namespace std;
int main(){
    // Array
    array<int, 4> a = {1,2,3,4};

    int size = a.size();// for finding the size of the array
    cout<<"ARRAY"<<endl;
    cout<<"Element at 3rd index - "<< a.at(3)<<endl;
    cout<<"If empty array then print 1 else 0 - "<< a.empty()<<endl;
    cout<<"First element - "<< a.front()<<endl;
    cout<<"Last element - "<< a.back()<<endl;
    cout<<endl<<endl;
    // Vector
    vector<int> v;
    vector<int> v2(5,1); // this stores 1, 5 times in the vector
    vector<int> v3(v2); // copies the elements of v2 in v3
    cout<<"VECTOR"<<endl;
    for(int i:v2){
        cout<<i<<" ";
    }
    cout<<endl<<"capacity"<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"capacity"<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"capacity"<<v.capacity()<<endl;
    v.push_back(4);
    cout<<"capacity"<<v.capacity()<<endl;
    cout<<"size"<<v.size()<<endl;

    cout<<"Element at 2nd index - "<< v.at(2)<<endl;

    // Dequeue
    deque<int> d; // doubly ended queue - elements can be added from both ends of the queue
    d.push_back(23);//adds element to the back of the queue
    d.push_front(45);//adds element to the front of the queue
    cout<<endl<<endl<<"DEQUEUE"<<endl;
    for(int i:d){// loops over all 'd'
        cout<<i<<" ";
    }
    d.pop_back();// removes element from the back of the queue
    // d.pop_front();// removes element from the front of the queue
    cout<<endl<<"After pop back"<<endl;
    for(int i:d){
        cout<<i<<" ";
    }
    d.push_back(89);
    cout<<endl<<"Element at 1st index - "<< d.at(1)<<endl;
    cout<<"front "<<d.front()<<endl;
    cout<<"back "<<d.back()<<endl;
    cout<<"If empty array then print 1 else 0 :- "<< d.empty()<<endl;
    cout<<"Before erase size - "<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);// this erases the elements starting from beginning and deleting the 1st element
    cout<<"After erase size - "<<d.size()<<endl;

    // LIST
    cout<<endl<<endl<<"LIST"<<endl;//implemented using doubly linked list
    list<int> l;
    l.push_back(11);
    l.push_front(22);
    for(int i: l){
        cout<<i<<" ";
    }
    cout<<endl;
    l.erase(l.begin());
    cout<<"after erase"<<endl;
    for(int i: l){
        cout<<i<<" ";
    }
    cout<<endl;
    // similarly pop_back, pop_front, size is implemented as before

    // STACK
    cout<<endl<<endl<<"STACK"<<endl;
    stack<string> s;
    s.push("one");
    s.push("two");
    s.push("three");
    cout<<"top element - "<<s.top()<<endl;
    s.pop();
    cout<<"top element after pop - "<<s.top()<<endl;
    // size, empty works same

    // QUEUE
    cout<<endl<<endl<<"QUEUE"<<endl;
    queue<string> q;
    q.push("one");
    q.push("two");
    q.push("three");
    cout<<"first element - "<<q.front()<<endl;
    q.pop();
    cout<<"first element after pop - "<<q.front()<<endl;
    // size() remains same as before

    // PRIORITY QUEUE
    cout<<endl<<endl<<"PRIORITY QUEUE"<<endl;
    // max heap
    priority_queue<int> maxi;
    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(10);
    maxi.push(20);
    maxi.push(15);
    maxi.push(25);
    maxi.push(5);

    int size_maxi = maxi.size();
    for(int i=0; i<size_maxi; i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }cout<<endl;

    mini.push(10);
    mini.push(20);
    mini.push(15);
    mini.push(25);
    mini.push(5);

    int size_mini = mini.size();
    for(int i=0; i<size_mini; i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<endl;

    // empty() works the same

    // SET
    cout<<endl<<endl<<"SET"<<endl;
    // only unique elements stored
    set<int> se;
    se.insert(50);// time complexity of insert is O(log n)
    se.insert(10);
    se.insert(20);
    se.insert(10);
    se.insert(40);
    se.insert(20);

    for(auto i: se){
        cout<<i<<" ";
    }cout<<endl;
    set<int>::iterator it = se.begin();
    it++;

    se.erase(it); // deletes the index 1 element
    for(auto i: se){
        cout<<i<<" ";
    }cout<<endl;

    cout<<"if element is present 1, else 0 - "<<se.count(40)<<endl; //if element is present - 1, else 0

    set<int>::iterator itr = se.find(40);// starts the set from 40
    for(auto it =itr; it!=se.end(); it++){// this loop is to print the set using find, which starts the set from 40
        cout<<*it<<" ";
    }cout<<endl;

    // MAP
    cout<<endl<<endl<<"MAP"<<endl;
    map<int,string> m;// ordered hota hai
    // values can be inserted in 2 ways
    // 1
    m[1]="one";
    m[10]="ten";
    m[5]="five";
    // 2
    m.insert({8,"eight"});

    for(auto i:m){
        cout<<i.first<<" ";
    }cout<<endl;
    // count,find works same as in set
    // erase works as in list,i.e. erase(8) - deletes 8 and its value

    // ALGORITHMS
    cout<<endl<<endl<<"ALGORITHMS"<<endl;

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(5);
    v1.push_back(8);
    v1.push_back(9);

    cout<<"Finding 8-> "<<binary_search(v1.begin(),v1.end(),8)<<endl;// returns 1 if found, else 0
    cout<<"lower bound-> "<<lower_bound(v.begin(),v.end(),5)-v.begin()<<endl;
    cout<<"upper bound-> "<<upper_bound(v.begin(),v.end(),8)-v.begin()<<endl;

    rotate(v1.begin(),v1.begin()+1,v.end());//unexpected result, samajh nhi aaya
    cout<<"after rotate - ";
    for(int i:v1){
        cout<<i<<" ";
    }cout<<endl;
    
    int a1 = 5;
    int a2 = 9;
    cout<<"max-> "<<max(a1,a2)<<endl;
    cout<<"min-> "<<min(a1,a2)<<endl;
    swap(a1,a2);
    cout<<"a1 - "<<a1<<"; a2 - "<<a2<<endl;

    string str = "qwerty";
    reverse(str.begin(),str.end());
    cout<<"string - "<<str<<endl;
    
}