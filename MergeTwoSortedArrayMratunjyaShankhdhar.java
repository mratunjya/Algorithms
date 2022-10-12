import java.util.Scanner;

public class MergeTwoSortedArrayMratunjyaShankhdhar {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the first array");
        int n = sc.nextInt();
        int[] arr1 = new int[n];
        System.out.println("Enter the elements of the first array");
        for (int i = 0; i < n; i++) {
            arr1[i] = sc.nextInt();
        }
        System.out.println("Enter the size of the second array");
        int m = sc.nextInt();
        int[] arr2 = new int[m];
        System.out.println("Enter the elements of the second array");
        for (int i = 0; i < m; i++) {
            arr2[i] = sc.nextInt();
        }
        int[] arr3 = new int[n + m];
        int i = 0, j = 0, k = 0;
        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                arr3[k] = arr1[i];
                i++;
                k++;
            } else {
                arr3[k] = arr2[j];
                j++;
                k++;
            }
        }
        while (i < n) {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        while (j < m) {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
        System.out.println("The merged array is");
        for (int l = 0; l < n + m; l++) {
            System.out.print(arr3[l] + " ");
        }
    }
}