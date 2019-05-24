//=========================================================
// author: nvatuan
// n-queens game interactive play program
//=========================================================
#include <bits/stdc++.h>
#include "BMP.h"
using namespace std;
#define fillBlack(x, y, w, h) fill_region(x, y, w, h, 0, 0, 0, 255)
#define fillBlue(x, y, w, h) fill_region(x, y, w, h, 255, 80, 80, 255)
#define fillGrey(x, y, w, h) fill_region(x, y, w, h, 200, 200, 200, 255)

//=========================================================
void drawQueen(BMP &canvas, int x, int y){
	canvas.fillBlack(x, y, 60, 12 );
	canvas.fillBlack(x + 3, y + 12, 54, 3);
	canvas.fillBlack(x, y + 15, 60, 15);
	//
	canvas.fillBlack(x - 6, y + 30, 12, 9);
	canvas.fillBlack(x - 12, y + 36, 12, 36);
	//
	canvas.fillBlack(x + 18, y + 30, 24, 9);
	canvas.fillBlack(x + 24, y + 36, 12, 36);
	//
	canvas.fillBlack(x + 54, y + 30, 12, 9);
	canvas.fillBlack(x + 60, y + 36, 12, 36);
}
void drawQueen2(BMP &canvas, int x, int y){
	canvas.fillBlue(x, y, 60, 12 );
	canvas.fillBlue(x + 3, y + 12, 54, 3);
	canvas.fillBlue(x, y + 15, 60, 15);
	//
	canvas.fillBlue(x - 6, y + 30, 12, 9);
	canvas.fillBlue(x - 12, y + 36, 12, 36);
	//
	canvas.fillBlue(x + 18, y + 30, 24, 9);
	canvas.fillBlue(x + 24, y + 36, 12, 36);
	//
	canvas.fillBlue(x + 54, y + 30, 12, 9);
	canvas.fillBlue(x + 60, y + 36, 12, 36);
}
//=========================================================

int N;

const int SIZE = 1001;
int row[SIZE+1], col[SIZE+1];
int d[SIZE*4+4];
int *d1 = d+SIZE;
int *d2 = d+SIZE*3+2;

int valid(int x, int y){
	// this fucntion returns 1 if move (x; y) is valid
	// otherwise returns 0
	return (0 < x && x <= N) && (0 < y && y <= N) && (!row[x] && !col[y] && !d1[x-y] && !d2[x+y]);
}

pair<int, int> CPUMOVE;

int play(int player, int move){
	for(int i = 1; i <= N; i++){
		if(!row[i])
		for(int j = 1; j <= N; j++){
			if(valid(i, j)){
				// cout << "Player " << player+1 << " is testing move: " << move << endl;
				// cout << " moving... " << i << ' ' << j << endl;
				row[i] = col[j] = d1[i-j] = d2[i+j] = 1;
				if(!play(player ^ 1, move+1)) {
					if(move == 1) CPUMOVE.first = i, CPUMOVE.second = j;
					row[i] = col[j] = d1[i-j] = d2[i+j] = 0;
					return 1;
				}
				row[i] = col[j] = d1[i-j] = d2[i+j] = 0;
			}
		}
	}
	return 0;
}

int vx, vy;
int noMoreMove(){
	for(int i = 1; i <= N; i++){
		if(!row[i])
		for(int j = 1; j <= N; j++)
			if(valid(i, j)){
				vx = i, vy = j;
				return 0;
			}
	}
	return 1;
}

int queen[1001][1001];
void markAttacked(int x, int y, BMP &bmp2){
    for(int i = 1; i <= N; i++){
        if(!queen[x][i]){
            bmp2.fillGrey(100*(x-1)+2, 100*(i-1)+2, 96, 96);
        }
        if(!queen[i][y]){
            bmp2.fillGrey(100*(i-1)+2, 100*(y-1)+2, 96, 96);
        }
    }
    for(int i = -N; i <= N; i++){
        if(y+i > 0 && y+i < N+1){
            if(x+i > 0 && x+i < N+1)    
            if(!queen[x+i][y+i]){
                bmp2.fillGrey(100*(x+i-1)+2, 100*(y+i-1)+2, 96, 96);
            }
            if(x-i > 0 && x-i < N+1)
            if(!queen[x-i][y+i]){
                bmp2.fillGrey(100*(x-i-1)+2, 100*(y+i-1)+2, 96, 96);
            }
        }
    }
}

int px, py;
void oddN_play(){
	if(!px){
		CPUMOVE.first = CPUMOVE.second = N/2 + 1;
	}
	else{
		int median = (N/2 + 1);
		CPUMOVE.first  = median + (median - px);
		CPUMOVE.second = median + (median - py);
	}
}

string input;
int inputIsNatural(){
	N = 0;
	for(unsigned i = 0; i < input.length(); i++){
		if(!('0' <= input[i] && input[i] <= '9')) return 0;
		N = N*10 + (input[i] - '0');
	}
	if(!N) return 0;
	return 1;
}

int main(){
restart:
	cout << "Game will be played on a N*N board.\n";
	cout << "Please bear in mind that calculation would take too long if N is greater than 11.\n";
	do {
		cout << "\nPlease input a positive integer.";
		cout << "\n N = ";
		cin >> input;
	} while( !inputIsNatural() );
	if( N > 100 ){
		cout << "Warning! N is larger than intended. Unexpected behaviours might happen.\n"; 
		cout << "Type \"YES\" if you want to proceed, or type anything else to restart.\n > ";
		cin >> input;
		if(input != "YES") goto restart;
	}
// ====== initialize board ==================================================
	BMP bmp2(100*N, 100*N);

    bmp2.fill_region(0, 0, 100*N, 100*N, 255, 255, 255, 255);

    bmp2.fillBlack(0, 0, 2, 100*N);
    bmp2.fillBlack(100*N-2, 0, 2, 100*N);
    bmp2.fillBlack(0, 0, 100*N, 2);
    bmp2.fillBlack(0, 100*N-2, 100*N, 2);

    for(int i = 1; i < N; i++){
    	bmp2.fillBlack(100*i - 2, 0, 4, 100*N);
    	bmp2.fillBlack(0, 100*i - 2, 100*N, 4);
    }
    //
    bmp2.write("screen.bmp");
    cout << "Board has been initialized. Please open \"screen.bmp\" in your image viewer to have visual of the game.\n";
    cout << "CPU will play first.\n";
	// ==
	srand(time(NULL));
	//
	do{
		cout << "\nIt's CPU's turn.\n CPU is calculating...\n";
		if(noMoreMove()){
			cout << "\n    Player wins! Gameover";
			getchar(); getchar();
			return 0;
		}
// ======== CPU TURN ==================================================
		CPUMOVE.first = CPUMOVE.second = 0;
		if((N > 12) && (N & 1)) oddN_play();
		else play(0, 1);
		//
		if(!CPUMOVE.first){
			cout << "CPU has predicted its defeat and has decided to play randomly!\n";
			do {
				CPUMOVE.first = (rand() % N) + 1;
				CPUMOVE.second = (rand() % N) + 1;
			} while (!valid(CPUMOVE.first, CPUMOVE.second));
		}
		//
		cout << "\n CPU's X = " << CPUMOVE.first << '\n';
		cout << " CPU's Y = " << CPUMOVE.second << '\n';
		row[CPUMOVE.first] = col[CPUMOVE.second] = d1[CPUMOVE.first-CPUMOVE.second] = d2[CPUMOVE.first+CPUMOVE.second] = 1;
		queen[CPUMOVE.first][CPUMOVE.second] = 1;

		// == Visualize CPU's move
		drawQueen(bmp2, 20 + 100*(CPUMOVE.first -1), 15 + 100*(CPUMOVE.second-1));
		markAttacked(CPUMOVE.first, CPUMOVE.second, bmp2);
		bmp2.write("screen.bmp");


// ========= YOUR TURN ==================================================
		if(noMoreMove()){
			cout << "No more move!\n";
			cout << "\n    CPU wins! Gameover.";
			getchar(); getchar();
			return 0;
		}
		//
		cout << "\nIt's your turn.\n";
		cout << "Input X = 0 and Y = 0 to auto move.\n";
		while (1) {
			cout << "\n X = "; cin >> px;
			cout << " Y = "; cin >> py;
			if(!px && !py){
				noMoreMove();
				px = vx, py = vy;
				cout << "Moving automatically... X = " << px << " Y = " << py <<'\n';
			}
			if(valid(px, py)) break;
			cout << "You input an invalid move! Please re-input.\n";
		};
		//
		row[px] = col[py] = d1[px-py] = d2[px+py] = 1;
		queen[px][py] = 1;
		// == Visualize your move
		drawQueen2(bmp2, 20 + 100*(px-1), 15 + 100*(py-1));
		markAttacked(px, py, bmp2);
		bmp2.write("screen.bmp");		
		//
	} while( 1 );
}