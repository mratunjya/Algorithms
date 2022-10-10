//Program for various Recursion problems
// GitHub username- paditya99

import java.util.*;
public class Recursion {

    public static void printIn(int n){
        if(n==0){
            return;
        }
        System.out.println(n);
        printIn(n-1);
       
    }

    public static void printSum(int s,int e,int sum){
       if(s==e){
        sum=sum+s;
        System.out.println(sum);
        return;
       }
       sum=sum+s;
       printSum(s+1, e, sum);
       System.out.println(s);

    }

    public static void printFib(int a,int b,int n){
        if(n==0){
            return;
        }
        int c=a+b;
        System.out.println(c);
        printFib(b, c, n-1);
        
    }

    //Print X^n(n=stack height)

    public static int calPow(int x,int n){
        if(x==0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        int ans=x*calPow(x, n-1);
       
        return ans;
    }

    //Print X^n(stack height= log n)
    //X^n->   X^n/2 * X^n/2 * X ( if n is odd )
    //X^n->   X^n/2 * X^n/2 ( if n is even )

    public static int calPow2(int x,int n){
        if(x==0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(n%2==0){
            return calPow2(x, n/2) * calPow2(x, n/2);
        }
        else{
            return calPow2(x, n/2) * calPow2(x, n/2) * x;
        }
    }

    //Tower of Hanoi problem       - time complexity=O(2^n)
    public static void towerOfHanoi(int n, String src, String helper, String dest){
            if(n==1){
                System.out.println("transfer disks "+ n + " from "+ src+" to "+ dest);
                return;
            }
            towerOfHanoi(n-1, src, dest, helper);
            System.out.println("transfer disks "+ n + " from "+ src+" to "+ dest);
            towerOfHanoi(n-1, helper, src, dest);
    }

    //Check if the array is sorted or not

    public static boolean arraycheck(int arr[],int idx){
        if(idx==arr.length-1){
            return true;
        }
        if(arr[idx]<arr[idx+1]){
            //array is sorted till now
            return arraycheck(arr, idx+1);
        }
        else{
            return false;
        }
        
    }

    // Getting all subsequences of a string   // Time Complexity= 2^n

    public static void subsequences(String str, int index, String newstr){
        if(index==str.length()){
            System.out.println(newstr);
            return;
        }

        char curr=str.charAt(index);
        //char to be
        subsequences(str, index+1, newstr+curr);
        //or not to be
        subsequences(str, index+1, newstr);
    }

     // Getting all unique subsequences of a string

     public static void unique_subsequences(String str, int index, String newstr, HashSet<String> set){
        if(index==str.length()){
            if(set.contains(newstr)){
                return;
            }
            else{
                System.out.println(newstr);
                set.add(newstr);
                return;
            }
           
        }

        char curr=str.charAt(index);
        //char to be
        unique_subsequences(str, index+1, newstr+curr, set);
        //or not to be
        unique_subsequences(str, index+1, newstr, set);
    }

// Print each combination of keypad strings    // Time complexity= 4^n

public static void printCombination(String str, int index, String combination){
    String keypad[]={".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

    if(index==str.length()){
        System.out.println(combination);
        return;
    }
    char curr=str.charAt(index);
    String mapping_string=keypad[curr-'0'];

    for(int i=0;i<mapping_string.length();i++){
        printCombination(str, index+1, combination+mapping_string.charAt(index));
    }
}

    public static void main(String[] args) {
      //  printIn(5);

       // printSum(1,5,0);

    //    int n=7;
    //    System.out.println(0);
    //    System.out.println(1);
    //    printFib(0, 1,n-2)
    
   // towerOfHanoi(3, "S", "H", "D");
        //  int arr[]={1,2,1,4};   
        //  boolean a=arraycheck(arr, 0);
        //  if(a){
        //     System.out.println("sorted");
        //  }
        //  else{
        //     System.out.println("not sorted");
        //  }
    	// String str="abcd";
		// char c=str.chatAt(1);
		// System.out.println(c);

    //    HashSet<String> set=new HashSet<>();
    // unique_subsequences("ABC", 0, "", set);

    String str="23";
    printCombination(str, 0, "");


    }
}
