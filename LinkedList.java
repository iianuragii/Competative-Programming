import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList<Integer> l= new LinkedList<Integer>();
        int i,a = 0;
        System.out.println("Enter the numbers\n");
        for(i = 0;i < 4;i++){
            a = sc.nextInt();
            l.addFirst(a);
        }
        l.removeFirst();

        System.out.println("The Numbers in Linked List are:");
        System.out.println(l);

        if(l.contains(2) == true)
            System.out.println("2 is present in the list");
        else
            System.out.println("False");
        System.out.println("The position of 2 is "+l.get(2));
        System.out.println("Size of the List is "+l.size());
        Integer arr[] = new Integer[10];
        String str;
        str=l.toString();
        System.out.println("The String is"+str);
        l.toArray(arr);
        System.out.println("The Array elements are:-");
        for(i = 0;i < l.size();i++)
            System.out.println(arr[i]);

    }
}
