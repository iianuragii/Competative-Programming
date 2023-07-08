import java.util.*;
public class arrange {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> str = new ArrayList<>();
        ArrayList<Integer> arr = new ArrayList<Integer>();
        int i,j,temp1,n = 0,phn = 0;
        String temp = "",name = "";
        System.out.println("Enter the range");
        n = sc.nextInt();
        
        for(i = 0;i < n;i++)
        {
            System.out.println("Enter the name and phn no.");
            name = sc.next();
            phn = sc.nextInt();
            str.add(name);
            arr.add(phn);
        }
        
        String str1[] = new String[n];
        int arr1[] = new int[n];
        for(i = 0;i < n;i++)
        {
            str1[i] = str.get(i);
            arr1[i] = arr.get(i);
        }
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < n-i-1;j++)
            {
                if (str1[j].compareTo(str1[j+1]) > 0) 
                {
                    temp = str1[j];
                    str1[j] = str1[j+1];
                    str1[j + 1] = temp;

                    temp1 = arr1[j];
                    arr1[j] = arr1[j+1];
                    arr1[j+1] = temp1;
                }
            }
        }
        System.out.println("Sorted list:-");
        for(i = 0;i < n;i++)
        {
            System.out.println(str1[i] + "\t" + arr1[i]);
        }
    }
}
