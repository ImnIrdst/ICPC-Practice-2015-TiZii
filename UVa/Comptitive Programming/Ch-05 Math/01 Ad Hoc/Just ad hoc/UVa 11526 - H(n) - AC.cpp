import java.util.Scanner;
import java.math.*;

class Main{//Main
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		while(tc-->0){
			long n = sc.nextLong() , res=0;
			if( n == 0){
				System.out.println(0);
				continue;
			}
			long sq = (long)(Math.sqrt(n));
			if(sq*sq==n){ 
				res+=n/sq; sq--;
			}
			for(long i=1 ; i<=sq ; i++){
				res+=n/i; res+=Math.max(0, n/i-sq);
			}
			System.out.println(res);
		}
	}
}

