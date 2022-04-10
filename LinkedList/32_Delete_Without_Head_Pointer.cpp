// Delete without head pointer
// https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1#
// https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/



struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;



class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       // Your code here
      Node *temp = del->next;
      del->data = temp->data;
      del->next = temp->next;
    }

};