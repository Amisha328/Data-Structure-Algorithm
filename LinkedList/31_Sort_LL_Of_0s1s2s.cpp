// Sort linked list of 0s 1s 2s
// https://www.codingninjas.com/codestudio/problem-details/sort-linked-list-of-0s-1s-2s_1071937
// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1#


#include <bits/stdc++.h>
using namespace std;
/* Link list Node */

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// // ################################### MAIN LOGIC ########################################################

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Changing the data:  TC->O(n) | SC->O(1)
        /*
        Node *curr = head;
        int zero = 0, one = 0, two = 0;
        while(curr != NULL)
        {
            if(curr->data == 0)
                zero++;
            else if(curr->data == 1)
                one++;
            else
                two++;
            curr = curr->next;
        }
        
        curr = head;
        while(zero--)
        {
            curr->data = 0;
            curr = curr->next;
        }
        while(one--)
        {
            curr->data = 1;
            curr = curr->next;
        }
        while(two--)
        {
            curr->data = 2;
            curr = curr->next;
        }
        return head;
        */
        
        // By changing links
        // TC->O(n) | SC->O(1)
        if(head == NULL || head->next == NULL) return head;
        
        Node *zeroH = new Node(0);
        Node *oneH = new Node(0); 
        Node *twoH = new Node(0);
        
        Node *zero = zeroH;
        Node *one = oneH;
        Node *two = twoH;
        
        Node *curr = head;
        while(curr)
        {
            if(curr->data == 0)
            {
                zero->next = curr;
                zero = zero->next;
            }
            else if(curr->data == 1)
            {
                one->next = curr;
                one = one->next;
            }
            else
            {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }
        
        zero->next = (oneH->next)? oneH->next : twoH->next;
        one->next = twoH->next;
        two->next = NULL;
        
        return zeroH->next;
    }
};


/// // ########################################################################################################


// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    scanf("%d", &n);

    insert(n);
    Solution ob;
    struct Node *newHead = ob.segregate(start);
    printList(newHead);


    return 0;
}  // } Driver Code Ends