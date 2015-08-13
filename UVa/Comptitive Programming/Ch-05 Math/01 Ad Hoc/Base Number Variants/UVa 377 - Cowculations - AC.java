import java.util.Scanner;

class Main{//Main
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); String str;
		System.out.println("COWCULATIONS OUTPUT");
		while(n-->0){
			str = sc.next();
			int num1 = StringtoNum(str);
			str = sc.next();
			int num2 = StringtoNum(str);
			for(int j=0 ; j<3 ; j++){
				char c = sc.next().charAt(0);
				if(c == 'A') num2+=num1;
				if(c == 'R') num2/=4;
				if(c == 'L') num2*=4;
			}
			str = sc.next();
			int ans = StringtoNum(str);
			if(ans == num2) System.out.println("YES");
			if(ans != num2) System.out.println("NO");
			
		}
		System.out.println("END OF OUTPUT");		
	}
	
	public static int StringtoNum(String str){
		int num=0;
		for(int i=0 ; i<str.length() ; i++){
			num*=4;
			if(str.charAt(i)=='U') num++;
			if(str.charAt(i)=='C') num+=2;
			if(str.charAt(i)=='D') num+=3;
		}
		return num;
	}
	
}

