import java.math.BigInteger;
import java.util.Scanner;
//import java.util.

public class Main {
    // https://en.wikipedia.org/wiki/Integer_square_root
    public static BigInteger sqrt(BigInteger n) {
        BigInteger cur = null; // X(k)
        BigInteger nxt = n; // X(k+1)
        while(true) {
            cur = nxt;
            nxt = cur.add(n.divide(cur)).divide(BigInteger.valueOf(2));
            if(nxt.equals(cur)) break;
        }
        return cur;
        //if(cur.multiply(cur).equals(n)) return cur;
        //else return null;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = Integer.parseInt(sc.nextLine());
        while(tc-- > 0) {
            sc.nextLine();
            BigInteger y = new BigInteger(sc.nextLine());
            if(y.equals(BigInteger.ZERO)) System.out.println(0);
            else                          System.out.println(sqrt(y));
            if(tc>0) System.out.println();
        }
    }
}


// TLE
//import java.math.BigInteger;
//import java.util.Scanner;
////import java.util.
//
//public class Main {
//    public static void main(String[] Args) {
//        Scanner sc = new Scanner(System.in);
//        int tc = sc.nextInt();
//        while(tc-- > 0) {
//            BigInteger y = sc.nextBigInteger();
//
//            StringBuilder sb = new StringBuilder("1");
//            for(int i=0 ; i<5010; i++) sb.append("0");
//            BigInteger sdd = BigInteger.valueOf(2684512);
//            BigInteger lo = new BigInteger("1");
//            BigInteger hi = new BigInteger(sb.toString());
//            if(hi.compareTo(y) > 0) hi = y;
//            while(lo.compareTo(hi.subtract(BigInteger.valueOf(1)))<0) {
//                BigInteger mid = lo.add(hi).divide(BigInteger.valueOf(2));
//                if(mid.multiply(mid).compareTo(y) <= 0)
//                    lo = mid;
//                if(mid.multiply(mid).compareTo(y) >  0) hi = mid;
//            }
//
//            System.out.println(lo);
//            if(tc>0) System.out.println();
//        }
//    }
//}