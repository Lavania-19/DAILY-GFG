//{ Driver Code Starts
// Initial Template for Java

import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {
    public int SumofMiddleElements(int[] arr1, int[] arr2) {
        // code here
        if(arr1.length>arr2.length) return SumofMiddleElements(arr2,arr1);

        int start = 0;
        int end =  arr1.length;
        int total_length = arr1.length + arr2.length;
        int partition1;
        int partition2;
        int max_left1,max_left2,min_right1,min_right2;

        while(start<=end){
            partition1 = start + (end-start)/2;
            partition2 = ((total_length+1)/2) - partition1;

            max_left1 = (partition1==0)?Integer.MIN_VALUE:arr1[partition1-1];
            max_left2 = (partition2==0)?Integer.MIN_VALUE:arr2[partition2-1];

            min_right1 = (partition1==arr1.length)?Integer.MAX_VALUE:arr1[partition1];
            min_right2 = (partition2==arr2.length)?Integer.MAX_VALUE:arr2[partition2];

            if(max_left1<=min_right2 && max_left2<=min_right1){
                if(total_length%2==0){
                    return (int)(Math.max(max_left1,max_left2) + Math.min(min_right1,min_right2));
                }
                return Math.max(max_left1,max_left2);
            }
            else if(max_left1>min_right2) end = partition1-1;
            else start = partition1+1;
        }
        return 0;
    }
}

//{ Driver Code Starts.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume newline
        while (t-- > 0) {
            String[] input1 = sc.nextLine().split(" ");
            int[] arr = new int[input1.length];
            for (int i = 0; i < input1.length; i++) {
                arr[i] = Integer.parseInt(input1[i]);
            }

            String[] input2 = sc.nextLine().split(" ");
            int[] brr = new int[input2.length];
            for (int i = 0; i < input2.length; i++) {
                brr[i] = Integer.parseInt(input2[i]);
            }

            Solution ob = new Solution();
            int res = ob.SumofMiddleElements(arr, brr);
            System.out.println(res);
        }
    }
}

// } Driver Code Ends