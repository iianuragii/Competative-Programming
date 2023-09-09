import java.util.*;
class Slide {
    int window(int arr[],int k,int n)
    {
        if(n < k)
            return -1;
        int i,max = 0,sum = 0;
        for(i = 0;i < k;i++){
            max+=arr[i];
        }
        for(i = k;i < n;i++){
            sum += arr[i] - arr[i - k];
            max = Math.max(max,sum);
        }
        return max;
    }
}
public class Main {
    public static void main(String[] args) {
        int arr[] = {5,2,-1,0,3};
        int p = 0;
        int k = 3;
        Slide ob = new Slide();
        p = ob.window(arr,k,5);
        System.out.println("Maximum = "+p);
    }
}
