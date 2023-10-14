import java.util.*;
class fib
{
    int fun(int n,HashMap<Integer,Integer> map)
    {
        int result = 0;
        if(n == 0 || n == 1)         
            return n;

        if(map.containsKey(n))
            return map.get(n);

        result =  fun(n-1,map)+fun(n-2,map);          //MEMOIZATION
        map.put(n,result);

        return result;
    }
}
public class Main
{
    public static void main(String[] args) {
        fib ob = new fib();
        int n = 10,p = 0;
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i = 0; i < n; i++){
            System.out.print(ob.fun(i,map) +" ");
        }
    }
}
