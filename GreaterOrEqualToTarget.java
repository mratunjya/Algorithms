package GitCowls;

public class GreaterOrEqualToTarget {

    // To Search no. Greater or equal to the target element
    public static void main(String[] args) {
        int[] arr ={-22, -13, -6, -3, 2, 4 ,10, 14, 28, 31, 45};
        int target =14;
        int ans = GreaterOrEqual(arr,target);
        System.out.println(ans);
    }
    static int GreaterOrEqual(int[] arr , int target){
        if(target>arr[arr.length-1]){return -1;}
        int start =0;
        int end = arr.length - 1 ;


        while (start <= end){
            int mid = start + (end-start)/2;

            if(target< arr[mid]){
                end = mid-1;
            } else if (target > arr[mid]) {
                start = mid+1;
            }else{
                return mid;
            }
        }
        return start;
    }
}
