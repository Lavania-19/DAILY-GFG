/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

    
        if (!head) {
            newNode->next = newNode;
            return newNode;
        }

        Node* curr = head;

        while (true) {
            Node* nextNode = curr->next;

           
            if (curr->data <= data && data <= nextNode->data) {
                break;
            }

        
            if (curr->data > nextNode->data) {
                if (data >= curr->data || data <= nextNode->data) {
                    break;
                }
            }

            curr = curr->next;

            if (curr == head) {
                break;
            }
        }

        newNode->next = curr->next;
        curr->next = newNode;

        if (data < head->data)
            return newNode;

        return head;
    }
};
