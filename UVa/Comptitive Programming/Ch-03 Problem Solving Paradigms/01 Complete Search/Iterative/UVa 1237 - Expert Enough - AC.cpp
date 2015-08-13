#include <cstdio>

const int Max = 1e4+10;

int L[Max], H[Max]; char M[Max][25];

int main(){
    int tc; scanf("%d", &tc);
    while(tc--){
        int n, q, p;
        scanf("%d", &n);
        for(int i=0 ; i<n ; i++){
            scanf("%s %d %d", M[i], &L[i], &H[i]);
        }
        scanf("%d", &q);
        while( q-- ){
            scanf("%d", &p);
            int cnt=0, id;
            for(int i=0 ; i<n ; i++){
                if(L[i]<=p && p<=H[i]) cnt++, id=i;
                if(cnt > 1) break;
            }
            if(cnt == 1) puts(M[id]);
            if(cnt != 1) puts("UNDETERMINED");
        }
        if(tc) puts("");
    }
}