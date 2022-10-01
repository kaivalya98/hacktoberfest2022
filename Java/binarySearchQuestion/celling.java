package com.binarySearchQuestion;

public class celling {
    public static void main(String[] args) {
//         brutal force high time complexity
        int arr[]={2,3,5,9,14,16,18};
        int target = 11;
        int ans = ceiling(arr, target);
        System.out.println(ans);
    }
static int ceiling(int[] arr, int target) {
        if(target > arr[arr.length-1]){
            return -1;
        }
        int start = 0;
        int end = arr.length - 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if (target < arr[mid]) {
                end = mid - 1;
            } else if (target > arr[mid]) {
                start = mid + 1;
            } else {
                // ans found
                return mid;
            }
        }
        return start;

    }
}
    public static void main(String[] args) {
        int[] arr = {-18, -12, -4, 0, 2, 3, 4, 15, 16, 18, 22, 45, 89};
        int target = 99;
        int ans = ceiling(arr, target);
        System.out.println(ans);
    }
