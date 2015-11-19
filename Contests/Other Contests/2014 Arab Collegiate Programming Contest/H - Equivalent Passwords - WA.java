import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public class Solution {
    public static class DisJointSet{
        int[] par,rnk,cnt; int numOfsets;

        DisJointSet(int n){
            par = new int[n]; rnk = new int[n]; cnt = new int[n];
            Arrays.fill(par, -1); Arrays.fill(rnk, 0); Arrays.fill(cnt, 1);
            numOfsets=n; // if we wanna count number of disjoint sets
        }

        int Find(int a){
            int i=a,j=a,tmp;
            while(par[i]!=-1){ i=par[i]; }
            while(par[j]!=-1){ tmp=par[j]; par[j]=i; j=tmp; } //path compression
            return i;
        }
        int Uni(int a, int b){
            int A=Find(a),B=Find(b);
            if(A!=B){
                if(rnk[A]<rnk[B]) {
                    int t = A;
                    A = B; B = t;
                }// union using rank
                if(rnk[A]==rnk[B]) rnk[A]++;
                par[B]=A;
                cnt[A]+=cnt[B]; // if we wanna count each set size
                numOfsets--; // if we wanna count number of disjoint sets
            }
        return cnt[A]; // if we wanna count each set size
        }
    }

    public static ArrayList<String> all;
    public static TreeMap<String, Integer> stringId; // group
    public static DisJointSet grp;

    public static void init() {
        String str;
        all = new ArrayList<>();
        stringId = new TreeMap<>();
        for(int i=0; i<(int)1e5 ; i++) {
            str = String.valueOf(i); all.add(str);
            stringId.put(all.get(all.size()-1), all.size()-1);
            while (str.length()<5) {
                str = "0"+str; all.add(str);
                stringId.put(all.get(all.size() - 1), all.size() - 1);
            }
        }

        int gg = 0, g; grp = new DisJointSet(all.size());
        for(int i=0 ; i<all.size() ; i++) {
            String u = all.get(i);
            for(int bit=0 ; bit<(1<<5) ; bit++) {
                StringBuilder sb = new StringBuilder("");
                boolean ok = true;
                for(int j=0 ; j<u.length() && j<5 && ok ; j++) {
                    if(u.charAt(j) != '9' &&  (bit&(1<<j)) != 0) sb.append((char)(u.charAt(j)+1));
                    else if(u.charAt(j) != '0' &&  (bit&(1<<j)) != 0) sb.append((char)(u.charAt(j)-1));
                    else ok = false;
                }
                if(ok) grp.Uni(i, stringId.get(sb.toString()));
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int cs = 1; init();
        int tc = sc.nextInt();

        while (tc-->0) {
            int n = sc.nextInt();
            boolean[] containsGroup = new boolean[(int)1e6];
            Arrays.fill(containsGroup, false);
            for(int i=0 ; i<n ; i++) {
                String str = sc.next();
                containsGroup[grp.Find(stringId.get(str))] = true;
            }

            int ans = 0;
            for(int i=0 ; i<containsGroup.length ; i++) {
                if(containsGroup[i]) ans++;
            }
            System.out.println("Case " + (cs++) +": " + ans);
        }


    }
}