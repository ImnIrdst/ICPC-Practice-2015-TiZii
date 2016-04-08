import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
class Solution{
    public static void main(String []args) {
        Scanner sc= new Scanner(System.in);
        int n = 20;
        int tc = sc.nextInt();
        while(tc-->0) {
            int cs = sc.nextInt();
            int[] a = new int[n];
            for(int i=0 ; i<n ; i++) {
                a[i] = sc.nextInt();
            }

            int cnt = 0;
            for(int i=1, j ; i<n ; i++) { // new Student
                int newStudent = a[i];
                for(j=0 ; j<i; j++) { // find the taller
                    if(a[j]>a[i]) {
                        for(int k = i ; k>j ; k--) { // step back
                            a[k] = a[k-1]; cnt++;
                        }
                        break;
                    }

                }
                a[j] = newStudent;
            }

            System.out.println(cs + " " + cnt);
        }
    }
}