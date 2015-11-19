import java.math.BigInteger;
import java.util.*;

public class Solution {
    public static long[] fact;
    public static int MAX = 17;

    public static void initFact() {
        fact = new long[MAX];

        fact[0] = 1;
        for(int i=1 ; i<MAX ; i++) {
            fact[i] = fact[i-1]*(long)i;
        }
    }

    public static String sortStr(String str) {
        char[] arr = str.toCharArray();
        Arrays.sort(arr);
        return new String(arr);
    }

    public static String removeIndexFromStr(String str, int id) {
        StringBuilder sb = new StringBuilder();
        for(int i=0 ; i<str.length() ; i++) {
            if(i!=id) sb.append(str.charAt(i));
        }
        return sb.toString();
    }

    public static long cntPerms(String str, Character removed) {

        int[] freq = new int[26];
        Arrays.fill(freq, 0);

        for(int i=0 ; i<str.length() ; i++) {
            freq[str.charAt(i) - 'A']++;
        }
        long perms = fact[str.length()];
        if(removed!=null) {
            if(str.length()==1) return 0;
            freq[removed - 'A']--;
            perms = fact[str.length() - 1];
        }


        for(int i=0 ; i<26 ; i++) {
            perms/=fact[freq[i]];
        }
        return perms;
    }

    public static String getNthPerm(String str, long n) {
        if(str.length() <= 1) return str;
        long cnt; char cur = '2'; int i;
        for(i=0 ,cnt = 0; i<str.length() ; ) {
            long tmp = cntPerms(str, str.charAt(i));
            if(cnt+tmp >= n) break;
            cnt += tmp; cur = str.charAt(i);
            while (i<str.length() && str.charAt(i)==cur) i++;
        }
        if(i>=str.length()) return str;
        return str.charAt(i) + getNthPerm(removeIndexFromStr(str,i), n-cnt);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        initFact();

        while(true) {
            String str = sc.next();
            long n  = sc.nextLong();

            if(str.equals("#") && n == 0 ) break;
            System.out.println(getNthPerm(sortStr(str), n));
        }
    }
}