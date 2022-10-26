// Write a program to program to implement bucket sort in java

import java.util.*;

public class BucketSort {
    public static void main(String[] args) {
        int[] arr = { 5, 4, 3, 2, 1 };
        int[] sorted = bucketSort(arr);
        System.out.println(Arrays.toString(sorted));
    }

    public static int[] bucketSort(int[] arr) {
        int[] bucket = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            bucket[i] = 0;
        }
        for (int i = 0; i < arr.length; i++) {
            bucket[arr[i] - 1]++;
        }
        int outPos = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < bucket[i]; j++) {
                arr[outPos++] = i + 1;
            }
        }
        return arr;
    }
}
