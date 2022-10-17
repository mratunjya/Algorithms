
import java.util.*;
import java.io.*;

public class Main{

    public static int numToArray(int n,int[] num){
        int idx=0;
        while(n>0){
            num[idx++] = n%10;
            n=n/10;
        }

        return idx;
    }

    public static int multiply(int[] num,int length,int n){
        int currValue,carry=0;
        int i=0;
        while(carry>0 || i<length){
            currValue = num[i] * n + carry;
            carry = currValue / 10;
            num[i] = currValue % 10;
            i++;
        }
        return i;
    }
    public static String covertToDIgit(int[] num,int l){
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<l;i++){
            sb.append(num[i]);
        }

        StringBuilder rev = sb.reverse();

        return rev.toString();
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int[] fact = new int[200];
            int n = sc.nextInt();

            int length = numToArray(n,fact);
            n--;

            int carry=0,currValue;
            while(n>0){
                length = multiply(fact,length,n);
                n--;
            }
            String ans = covertToDIgit(fact,length);
            System.out.println(ans);
        }
    }
}
