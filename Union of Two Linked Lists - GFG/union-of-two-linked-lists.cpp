//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        map<int, Node*> map;
        Node*curr = head1;
        
        // LL1 hashed
        while(curr) {
            map[curr->data] = curr;
            curr = curr->next;
        }
        curr = head2;
        
        // LL2 hashed
        while(curr){
            map[curr->data] = curr;
            curr = curr->next;
        }
        Node*UL = NULL;
        curr = 0;
        // Iterate Map & make final UL
        for(auto it = map.begin(); it != map.end(); it++){
            if(!UL) {
                UL = it->second;
                curr = UL;
            } else {
                curr->next = it->second;
                curr = curr->next;
            }
        }
        curr->next = 0;
        return UL;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends