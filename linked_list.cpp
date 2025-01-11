#include<bits/stdc++.h>
using namespace std;

class Node
{
   public:
   int data;
   Node* next;

   public:
   Node(int data1, Node* next1){
    data = data1;
    next = next1;
   }

   Node(int data1){
    data = data1;
    next = nullptr;
   }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while (temp)
    {
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* removesHead(Node* head){
    if(head == NULL) return head;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removesTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;

    return head;
}

Node* removeK(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeEl(Node* head, int el){
    if(head == NULL) return head;
    if(head->data == el){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp){
        if(temp->data == el){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertTail(Node* head, int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* tail = new Node(val);
    temp->next = tail;
    return head;
}

Node* insertK(Node* head, int k, int val){
    if(head == NULL){
        if(k==1) return new Node(val);
        else return NULL;
    }
    if(k==1){
        Node* temp = new Node(val, head);
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt == k-1){
            Node* nodeK = new Node(val);
            nodeK->next = temp->next;
            temp->next = nodeK;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeVal(Node* head, int el, int val){
    if(head == NULL)return NULL;

    if(head->data == val){
        Node* temp = new Node(el, head);
        return temp;
    }
    Node* temp = head;
    while(temp->next){
        if(temp->next->data == val){
            Node* nodeK = new Node(el);
            nodeK->next = temp->next;
            temp->next = nodeK;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};

    // Node* y = new Node(arr[0], nullptr);
    // cout<<y->data<<endl;
    // // or
    // Node z = Node(arr[1], nullptr);
    // cout<<z.data<<endl;

    // Array to Linked List
    Node* head = convertArr2LL(arr);
    // cout<<head->data<<endl;

    // traversal
    // Node* temp = head;
    // int cnt = 0;
    // while (temp){
    //     cout << temp->data <<" ";
    //     temp = temp->next;
    //     cnt++;
    // }
    // cout<<endl<<cnt<<endl;

    // cout<< checkIfPresent(head, 26)<<endl;

    // // remove the first element of LL
    // head = removesHead(head);
    // print(head);
    
    // // remove the last element of LL
    // head = removesTail(head);
    // print(head);

    // // remove Kth element
    // head = removeK(head, 4);
    // print(head);

    // // remove based on the value
    // head = removeEl(head, 2);
    // print(head);

    // // insert head
    // head = insertHead(head,1);
    // print(head);

    // // insert tail
    // head = insertTail(head, 9);
    // print(head);

    // // insert Kth element
    // head = insertK(head, 3, 66);
    // print(head);

    // insert element before vlaue x
    head = insertBeforeVal(head, 101, 7);
    print(head);
}