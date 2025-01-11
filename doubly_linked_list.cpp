#include<bits/stdc++.h>
using namespace std;

class Node
{
   public:
   int data;
   Node* next;
   Node* back;

   public:
   Node(int data1, Node* next1, Node* back1){
    data = data1;
    next = next1;
    back = back1;
   }
    
   Node(int data1){
    data = data1;
    next = nullptr;
    back = nullptr;
   }
};

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* convertArr2DLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head == NULL) return head;
    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;

    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL) return head;
    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }
    tail->back->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node* deleteK(Node* head, int k){
    if(head == NULL) return head;
    if(head->next == NULL){
        if (k == 1) {
            delete head;
            return NULL;
        }
        return head;
    }
    if(k==1){
        Node* prev = head;
        head = head->next;
        head->back = nullptr;
        delete prev;
        return head;
    }
    int cnt = 1;
    Node* temp = head;
    while(temp){
        if(cnt == k){
            if(temp->next!= NULL){
                temp->next->back = temp->back;
            }
            if(temp->back!= NULL){
                temp->back->next = temp->next;
            }
            delete temp;
            break;
        }
        temp = temp->next;
        cnt++;
    }
    return head;
}

int main(){
    vector<int> arr = {2,5,8,7};
    vector<int> arr2 = {27, 61, 91, 95, 42, 27, 36, 91, 4, 2, 53, 92, 82, 21, 16};
    Node* head = convertArr2DLL(arr);
    // print(head);

    // // delete the head of DLL
    // head = deleteHead(head);
    // print(head);

    // // delete the tail of DLL
    // head = deleteTail(head);
    // print(head);

    // delete the kth element of DLL
    head = deleteK(head, 2);
    print(head);
    return 0;
}