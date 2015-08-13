#include <iostream>
#include <algorithm>

using namespace std;
int  n=1,m=1; 
char a[100][100], b[100][100];

char calc(int p, int q){
	int c=0;
	if(a[p][q]=='*') return '*';
	for(int i=p-1 ; i<=p+1 ; i++){
		for(int j=q-1 ; j<=q+1 ; j++){
			if( !((i==p && j==q) && (i<0 && i>=n) && (j<0 && j>=m)) )
				if(a[i][j]=='*') c++;
		}
	}
	return c+'0';
}

int main(){
	
	int tc=0;
	while(true){
		cin >> n >> m;
		if(n==0 && m==0) break;
		tc++;
		for(int i=0 ; i<n; i++){
			for(int j=0 ; j<m; j++){
				cin >> a[i][j];
			}
		}
		for(int i=0 ; i<n; i++){
			for(int j=0 ; j<m; j++){
				b[i][j]=calc(i,j);
			}
		}

		cout << "Field #" << tc << ":" << endl;
		for(int i=0 ; i<n; i++){
			for(int j=0 ; j<m; j++){
				cout << b[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}

#include <cstdio>
#include <algorithm>

using namespace std;

int  n=1,m=1; 
char a[100][100], b[100][100];

char calc(int p, int q){
	int c=0;
	if(a[p][q]=='*') return '*';
	for(int i=p-1 ; i<=p+1 ; i++){
		for(int j=q-1 ; j<=q+1 ; j++){
			if( !((i==p && j==q) && (i<0 && i>=n) && (j<0 && j>=m)) )
				if(a[i][j]=='*') c++;
		}
	}
	return c+'0';
}

int main(){
	
	int tc=0;
	while(true ){
		scanf("%d %d",&n ,&m);

		tc++;
		for(int i=0 ; i<n; i++){
			for(int j=0 ; j<m; j++){
				scanf("%d", &a[i][j]);
			}
		}
		for(int i=0 ; i<n; i++){
			for(int j=0 ; j<m; j++){
				b[i][j]=calc(i,j);
			}
		}

		printf( "Field #%d:\n",tc);
		for(int i=0 ; i<n; i++){
			for(int j=0 ; j<m; j++){
				printf( "Field #%d:\n", b[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		scanf("%d %d",n,m);
	}
};
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
#include <stdio.h>

int field[100][100]; //mine squares will be denoted by -1
//current bounds:
int nLines = 100;
int nColumns = 100;

void clearField() {
    int i;
    for (i = 0; i < nLines; i++) {
        int j;
        for (j = 0; j < nColumns; j++) {
            field[i][j] = 0;
        }
    }
}

void setBounds(int l, int c) {
    nLines = l;
    nColumns = c;
}

int isInsideBounds(int i, int j) {
    return i >= 0 && i < nLines && j >=0 && j < nColumns;
}

void increment(int i, int j) {
    if (isInsideBounds(i, j) && field[i][j] != -1) {
        ++field[i][j];
    }
}

void setMine(int i, int j) {
    field[i][j] = -1;
    
    //increment neighbours
    int m;
    for (m = -1; m <= 1; m++) {
        int n;
        for (n = -1; n <= 1; n++) {
            increment(i + m, j + n);
        }
    }
}

void printField(int nField) {
    printf("Field #%d:\n", nField);
    
    int i;
    for (i = 0; i < nLines; i++) {
        int j;
        for (j = 0; j < nColumns; j++) {
            int x = field[i][j];
            
            if (x == -1) { //if is mine, print *
                printf("*");
            } else {
                printf("%d", x);
            }
        }
        printf("\n");
    }
}

int main() {
    int l, c; //input vars (field lines and columns)
    int nField = 1;
    
    for (;;) {
        scanf("%d %d", &l, &c);
        if (l == 0 && c == 0) { //if end of input, break
            break;
        }
        
        setBounds(l, c);
        clearField();
        
        int i;
        for (i = 0; i < l; i++) {
            char line[101]; //remeber \0
            scanf("%s", line);
            
            int j;
            for (j = 0; j < c; j++) {
                char currentChar = line[j];
                if (currentChar == '*') {
                    setMine(i, j);
                }
            }
        }
        
        if (nField > 1) {
            printf("\n");
        }
        printField(nField);
        
        ++nField;
    }
    return 0;
}



#include <iostream>
#include <algorithm>

using namespace std;
int  n=1,m=1; 
char a[101][101], b[101][101];

char calc(int p, int q){
	int c=0;
	if(a[p][q]=='*') return '*';
	for(int i=p-1 ; i<=p+1 ; i++){
		for(int j=q-1 ; j<=q+1 ; j++){
			if( !((i==p && j==q) && (i<0 && i>=n) && (j<0 && j>=m)) )
				if(a[i][j]=='*') c++;
		}
	}
	return c+'0';
}

int main(){
	
	int tc=0;
	while(true){
		cin >> n >> m;
		if(n==0 && m==0) break;
		
		for(int i=0 ; i<n; i++){
			for(int j=0 ; j<m; j++){
				cin >> a[i][j];
			}
		}
		for(int i=0 ; i<n; i++){
			for(int j=0 ; j<m; j++){
				b[i][j]=calc(i,j);
			}
		}

		cout << "Field #" << ++tc << ":" << endl;
		for(int i=0 ; i<n; i++){
			for(int j=0 ; j<m; j++){
				cout << b[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}
