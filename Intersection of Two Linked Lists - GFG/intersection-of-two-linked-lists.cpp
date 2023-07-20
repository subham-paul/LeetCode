//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_map<int, int> map;
        Node* curr = head2;
        // hash L2 items
        while(curr){
            map[curr->data]++;
            curr=curr->next;
        }
        Node*IL = NULL;
        Node*it = 0;
        curr = head1;
        
        while(curr){
            if(map.find(curr->data) != map.end()){
                // node val found in L2
                if(!IL){
                    IL = curr;
                    it = IL;
                } else {
                    if(map[curr->data] > 0){
                        it->next = curr;
                        it = it->next;
                        map[curr->data]--;
                    }
                }
            }
            curr = curr->next;
        }
        it->next = NULL;
        return IL;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends