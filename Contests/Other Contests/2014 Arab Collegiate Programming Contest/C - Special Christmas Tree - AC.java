import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int cs = 1;
        int tc = sc.nextInt();

        while (tc-->0) {
            long h = sc.nextLong();
            long l = sc.nextLong();

            l--;
            long pow2 = 1;
            long additional = h;
            long nodes = (h+1);
            while (true) {
                if(l < pow2) break;
                nodes += additional*pow2;
                l-=pow2; pow2*=2; additional--;
            }
            nodes += additional*l;
            System.out.println("Case " + (cs++) + ": " + nodes);
        }
    }
}