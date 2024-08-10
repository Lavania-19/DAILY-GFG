//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}


// } Driver Code Ends
/* node of linked list:
/* node of linked list:

class Node{
    int data;
    Node next;
    Node(int d){
        data=d;
        next=null;
    }
}

*/
 
class Solution {
    public Node rotate(Node head, int k) {
        if (head == null) {
            return null;
        }

        // Step 1: Make the linked list circular.
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        // Connect the last node to the head to make it circular.
        temp.next = head;

        // Step 2: Move the head pointer to the (k-th) node.
        while (--k > 0) {
            head = head.next;
        }

        // Step 3: The node next to the current head is the new head.
        Node newHead = head.next;
        
        // Step 4: Break the circle.
        head.next = null;

        return newHead;
    }
}


//{ Driver Code Starts.

public class GFG {
    static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = br.readLine().trim();
            if (!input.isEmpty()) {
                String[] numbers = input.split("\\s+");
                for (String num : numbers) {
                    if (!num.isEmpty()) {
                        arr.add(Integer.parseInt(num));
                    }
                }
            }

            Node head = null;
            if (!arr.isEmpty()) {
                head = new Node(arr.get(0));
                Node tail = head;
                for (int i = 1; i < arr.size(); ++i) {
                    tail.next = new Node(arr.get(i));
                    tail = tail.next;
                }
            }
            int k = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            head = ob.rotate(head, k);
            printList(head);
        }
    }
}

// } Driver Code Ends