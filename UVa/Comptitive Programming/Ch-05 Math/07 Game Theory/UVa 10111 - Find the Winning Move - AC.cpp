import java.util.Scanner;

public class Main {
	final static int SIZE = 4;
	static enum EvalState {
		LOSE(-1),
		WIN(1),
		DRAW(0),
		INPROGESS(2);
		int currrentEval;

		private EvalState(int currrentEval) {
			this.currrentEval = currrentEval;
		}

		public int getEvalState() {

			return currrentEval;
		}

	};

	/**
	 * The Class State.
	 */
	static class State {

		/** The a. state keeper of a particular instance of the tic-tac-toe */
		static char[] a;

		/**
		 * Instantiates a new state.
		 */
		public State() {

			a = new char[SIZE * SIZE];
		}

		/**
		 * Win.
		 *
		 * @param c
		 *            the c
		 * @return the int
		 */
		public int win(char c) {

			int j, cnt = 0;

			for (int i = 0; i < SIZE; i++) {
				for (j = 0; j < SIZE && a[i * SIZE + j] == c; j++)
					;
				if (j == SIZE)
					return 1;

			}

			for (int i = 0; i < SIZE; i++) {
				for (j = 0; j < SIZE && a[j * SIZE + i] == c; j++)
					;
				if (j == SIZE)
					return 1;

			}

			for (j = 0; j < SIZE && a[j * SIZE + (SIZE - 1 - j)] == c; j++)
				;

			if (j == SIZE)
				return 1;

			for (j = 0; j < SIZE && a[j * SIZE + j] == c; j++)
				;

			if (j == SIZE)
				return 1;

			for (int i = 0; i < SIZE; i++)
				for (j = 0; j < SIZE; j++)
					if (a[i * SIZE + j] == '.')
						cnt++;

			if (cnt > 0)
				return 2;

			return 3;
		}

		/*
		 * (non-Javadoc)
		 * 
		 * @see java.lang.Object#toString()
		 */
		public String toString() {
			String st = "";
			for (int i = 0; i < SIZE; i++)
				for (int j = 0; j < SIZE; j++)
					st += a[i * SIZE + j] + ".";
			return st;

		}

	}

	/**
	 * Terminal test.
	 *
	 * @param s
	 *            the s
	 * @return the int
	 */
	public static int terminalTest(State s) {

		int v = s.win('x');
		if (v == 1)
			return EvalState.WIN.getEvalState();

		v = s.win('o');
		if (v == 1)
			return EvalState.LOSE.getEvalState();
		else if (v == 2)
			return EvalState.INPROGESS.getEvalState();
		else
			return EvalState.DRAW.getEvalState();

	}

	/**
	 * Alpha beta search.
	 *
	 * @param init
	 *            the init
	 * @param alpha
	 *            the alpha
	 * @param beta
	 *            the beta
	 * @param player
	 *            the player
	 * @return the int
	 */
	public static int alphaBetaSearch(State init, int alpha, int beta,
			boolean player) {

		State s;
		int terminal = terminalTest(init);

		if (terminal != 2) {
			return terminal;
		}

		if (player == true) {

			for (int i = 0; i < SIZE * SIZE; i++) {

				if (init.a[i] == '.') {

					s = init;
					s.a[i] = 'x';

					alpha = Math.max(alpha,
							alphaBetaSearch(s, alpha, beta, false));
					s.a[i] = '.';
					if (alpha >= beta)
						return alpha;

				}
			}

			return alpha;
		}

		else {

			for (int i = 0; i < SIZE * SIZE; i++)

				if (init.a[i] == '.') {

					s = init;

					s.a[i] = 'o';

					beta = Math.min(beta,
							alphaBetaSearch(init, alpha, beta, true));
					s.a[i] = '.';
					if (beta <= alpha)
						return beta;
				}

			return beta;

		}

	}

	/**
	 * The main method.
	 *
	 * @param args
	 *            the arguments
	 */
	public static void main(String[] args) {

		int p = 0;
		Scanner in = new Scanner(System.in);

		char[] ch = new char[SIZE * SIZE];

		for (;;) {

			String s = null;
			s = in.nextLine();
			if (s.equals("$"))
				break;
			int cnt = 0;

			for (int i = 0; i < SIZE; i++) {

				s = in.nextLine();
				for (int j = 0; j < s.length(); j++)
					ch[cnt++] = s.charAt(j);

			}

			boolean isFound = false;

			State init = new State();

			for (int k = 0; k < SIZE * SIZE; k++)
				init.a[k] = ch[k];

			for (int i = 0; i < SIZE && isFound == false; i++)
				for (int j = 0; j < SIZE && isFound == false; j++)
					if (ch[i * SIZE + j] == '.') {

						init.a[i * SIZE + j] = 'x';
						if (alphaBetaSearch(init, Integer.MIN_VALUE,
								Integer.MAX_VALUE, false) == 1) {
							System.out.println("(" + i + "," + j + ")");
							isFound = true;
							break;

						}
						init.a[i * SIZE + j] = '.';
					}

			if (isFound == false)
				System.out.println("#####");

		}
	}
}

/* MY CPP CODE

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <climits>
#include <algorithm>
#define int64 long long int

using namespace std;

enum state{LOSE,WIN,DRAW,INPROGRESS};

int n=4;

state win(string& mp, char c){
    int j, cnt=0;
    //row
    for(int i=0; i<n ; i++){
        for(j=0; j<n && mp[i*n+j]==c ; j++);
        if(j==n) return WIN;
    }
    //col
    for(int i=0; i<n ; i++){
        for(j=0; j<n && mp[j*n+i]==c ; j++);
        if(j==n) return WIN;
    }
    //diag
    for (j = 0; j<n && mp[j*n + (n-1-j)]==c; j++);
    if(j==n) return WIN;
    for (j = 0; j<n && mp[j*n + j]==c; j++);
    if(j==n) return WIN;
    //if inprogress
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(mp[i*n+j]=='.') cnt++;
        }
    }
    if(cnt>0) return INPROGRESS;
    // Draw
    return DRAW;

}

int TerminateTest(string& mp){
    state v = win(mp,'x');
    if( v==WIN) return 1;
    v=win(mp,'o');
    if(v==WIN) return -1;
    else if (v==INPROGRESS) return 2;
    else return 0;
}
void print(string& mp){
    cout << endl;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout << mp[i*n+j];
        }
        cout << endl;
    }

}

int search(string& mp,int alpha, int beta, int player){
    int Terminate = TerminateTest(mp);
    if(Terminate != 2 ){
        //print(mp); cout << Terminate << endl << endl;
        return Terminate;
    }
    string tmp;
    if(player==1){
        for(int i=0 ; i<n*n ; i++){
            if(mp[i]=='.'){
                tmp=mp; tmp[i]='x';
                alpha=max(alpha,search(tmp,alpha,beta,0));
                tmp[i]='.';
                if(alpha>=beta) return alpha;
            }
        }
        return alpha;
    }else{
        for(int i=0 ; i<n*n ; i++){
            if(mp[i]=='.'){
                tmp=mp; tmp[i]='o';
                beta=min(beta,search(tmp,alpha,beta,1));
                tmp[i]='.';
                if(alpha>=beta) return beta;
            }
        }
        return beta;
    }
}

int main(){
    string str;
    while(cin >> str && str!="$"){
        string mp="";
        for(int i=0 ; i<n ; i++){
            //int a=2/i;
           cin >> str; mp+=str;
        }
        bool found=false;
        for(int i=0; i<n && !found ; i++){
            for(int j=0 ; j<n && !found ; j++){
                if(mp[i*n+j]=='.'){
                    mp[i*n+j]='x';
                    if(search(mp,INT_MIN,INT_MAX,0)==1){
                        printf("(%d,%d)\n",i,j);
                        found=true; break;
                    }
                    mp[i*n+j]='.';
                }
            }
        }
        if(!found)  printf("#####\n");
    }
    return 0;
}



*/