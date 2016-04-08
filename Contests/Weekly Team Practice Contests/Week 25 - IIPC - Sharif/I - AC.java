import sun.reflect.generics.tree.Tree;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

/**
 * Created by IMAN on 11/26/2015.
 *
 */
public class Main {
    public static TreeSet<BigInteger> st;
    public static BigInteger reverse(BigInteger a){
        return new BigInteger(new StringBuilder(a.toString()).reverse().toString());
    }

    public static BigInteger sort(BigInteger a){
        char[] str = a.toString().toCharArray();
        Arrays.sort(str);
        return new BigInteger(new String(str));
    }

    public static boolean isOnChain(String str){
        return (str.matches("1233+4444") || str.matches("5566+7777"));
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();
        while (tc-->0){
            TreeSet<BigInteger> visited = new TreeSet<BigInteger>();
            int m = sc.nextInt();
            BigInteger a = sc.nextBigInteger();
            BigInteger next = new BigInteger("0");
            BigInteger prev = new BigInteger("0");
            int iter;
            prev = a;
            for(iter = 1; iter <= m ; ++iter){
                if(isOnChain(a.toString())){
                    System.out.println("C " + iter);
                    break;
                }
                if(visited.contains(a)){
                    System.out.println("R " + iter); //???????
                    break;
                }

                visited.add(a);
                next = a.add(reverse(a));
                next = sort(next);
                prev = a;
                a = next;
            }

            if(iter > m){
                System.out.println(prev.toString());
            }
        }
    }
}
//        if(str.length() >= 8 && str.substring(0,3).equals("123")){
//            int i = 3;
//            while(i<str.length() && str.charAt(i)=='3') i++;
//            if(i<str.length() && i != 3){
//                if (str.substring(i).equals("4444")){
//                    return true;
//                }
//            }
//        }
//        if(str.length() >= 8 && str.substring(0,3).equals("556")){
//            int i = 3;
//            while(i<str.length() && str.charAt(i)=='6') i++;
//            if(i<str.length() && i != 3){
//                if (str.substring(i).equals("7777")){
//                    return true;
//                }
//            }
//        }
//        return false;
