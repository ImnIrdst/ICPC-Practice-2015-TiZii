import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while(tc--!=0){
            StringBuilder s1= new StringBuilder(sc.nextBigInteger().toString());
            StringBuilder s2= new StringBuilder(sc.nextBigInteger().toString());
            BigInteger a = new BigInteger(s1.reverse().toString());
            BigInteger b = new BigInteger(s2.reverse().toString());

            StringBuilder s3= new StringBuilder(a.add(b).toString());
            BigInteger ans = new BigInteger(s3.reverse().toString());
            System.out.println(ans);
        }
    }
}
