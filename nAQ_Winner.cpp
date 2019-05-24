//=========================================================
// author: nvatuan
// n-queens game brute-force to predict the winner
//=========================================================
#include <bits/stdc++.h>
using namespace std;

int N;

const int SIZE = 1001;
int row[SIZE+1], col[SIZE+1];
int d[SIZE*4+4];
int *d1 = d+SIZE;
int *d2 = d+SIZE*3+2;

int valid(int x, int y){
	return (!row[x] && !col[y] && !d1[x-y] && !d2[x+y]);
}

int play(int player, int move){
	if(move == 1){
		for(int i = 1; i <= (N+1)/2; i++)
			for(int j = i; j <= (N+1)/2; j++){
				row[i] = col[j] = d1[i-j] = d2[i+j] = 1;
				if(!play(player ^ 1, move+1)) {
					row[i] = col[j] = d1[i-j] = d2[i+j] = 0;
					return 1;
				}
				row[i] = col[j] = d1[i-j] = d2[i+j] = 0;
			}
		return 0;
	}
	else{
		for(int i = 1; i <= N; i++){
			if(!row[i])
			for(int j = 1; j <= N; j++){
				if(valid(i, j)){
					row[i] = col[j] = d1[i-j] = d2[i+j] = 1;
					if(!play(player ^ 1, move+1)) {
						row[i] = col[j] = d1[i-j] = d2[i+j] = 0;
						return 1;
					}
					row[i] = col[j] = d1[i-j] = d2[i+j] = 0;
				}
			}
		}
		return 0;
	}
}

int main(){
	cout << "N = "; cin >> N;
	cout << "\nWith board " << N << "*" << N <<'\n';
	cout << (play(0, 1) ? "First player wins\n" : "Second player wins\n");
}