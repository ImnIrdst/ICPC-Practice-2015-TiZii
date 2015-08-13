import java.util.Scanner;
import java.math.*;

class Main{//Main
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(true){
			int n = sc.nextInt(); if(n==0) break;
			double[] a = new double[1000+10]; double avg=0;
			for(int i=0 ; i<n ; i++){
				a[i] = sc.nextDouble(); avg+=a[i];
			}
			double neg=0, pos=0; avg/=n; avg=(int)(avg*100+0.5)/100.;
			for(int i=0 ; i<n ; i++){
				if(a[i]-avg>0) pos+=a[i]-avg;
				else neg-=a[i]-avg;
			}
			double ans=Math.min(pos, neg);
			//System.out.println(ans);
			System.out.printf("$%.2f\n",ans);
			
		}
	}
}

