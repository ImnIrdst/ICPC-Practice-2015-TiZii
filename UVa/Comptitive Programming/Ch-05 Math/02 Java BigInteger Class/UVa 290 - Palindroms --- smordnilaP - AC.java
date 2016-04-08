import java.lang.management.BufferPoolMXBean;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.regex.Matcher;
//import java.util.

public class Main {
    public static int calcSteps(BigInteger num, int base) {

        for(int step = 0 ; true ; step++) {
            StringBuilder sb = new StringBuilder(num.toString(base));

            String org = sb.toString();
            String rev = sb.reverse().toString();
            if(org.equals(rev)) return step;

            BigInteger iorg = new BigInteger(org, base);
            BigInteger irev = new BigInteger(rev, base);
            num = iorg.add(irev);
        }
    }

    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);

        String num; String str;
        while(sc.hasNext()) {
            num = sc.next();

            String ws = "";
            for(int base = 15 ; base>=2 ; base--) {
                try {
                    System.out.print(ws + calcSteps(new BigInteger(num, base), base)); ws = " ";
                }
                catch (Exception e) {
                    System.out.print(ws + "?"); ws = " ";
                }
            }
            System.out.println();
        }
    }
}