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
            int a = sc.nextInt();
            int b = sc.nextInt();
            System.out.print("Case " + (cs++) + ": ");
            if( a == 1 && b == 1) System.out.println("Habb Yakk");
            else if( a == 2 && b == 2) System.out.println("Dobara");
            else if( a == 3 && b == 3) System.out.println("Dousa");
            else if( a == 4 && b == 4) System.out.println("Dorgy");
            else if( a == 5 && b == 5) System.out.println("Dabash");
            else if( a == 6 && b == 6) System.out.println("Dosh");
            else if( a == 5 && b == 6) System.out.println("Sheesh Beesh");
            else if( a == 6 && b == 5) System.out.println("Sheesh Beesh");
            else {
                String[] mp = {"", "Yakk","Doh","Seh","Ghar","Bang","Sheesh"};
                System.out.println(mp[Math.max(a,b)] + " " + mp[Math.min(a,b)]);
            }
        }
    }
}