//内容：迷路探索(スタートとゴールをランダム生成)
//最終更新日：2020年10月23日

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max_x 10
#define max_y 10

//構造底の定義
struct Location{
    int Nx;//キャラクターのx座標
    int Ny;//キャラクターのx座標
    int Ex;//ゴールのx座標
    int Ey;//ゴールのy座標
};

//プロトタイプ宣言
void view(struct Location);
void visit(int,int,struct Location);

//グローバル変数
int success=0;//ゴール地点を見つけた時のフラグ
int m[max_y][max_x]={//迷路のマップ
    {2,2,2,2,2,2,2,2,2,2},
    {2,0,0,0,0,0,0,0,0,2},
    {2,0,2,2,2,2,2,2,0,2},
    {2,0,0,2,0,2,0,2,2,2},
    {2,0,2,0,0,0,0,0,0,2},
    {2,0,0,0,2,0,2,2,2,2},
    {2,0,2,0,2,0,0,0,0,2},
    {2,0,2,0,2,2,2,2,0,2},
    {2,0,0,0,2,0,0,0,0,2},
    {2,2,2,2,2,2,2,2,2,2},
};

//main関数
int main(){
    srand(time(NULL));
    int i,n1,n2;
    struct Location location;
    for(i=0;i<2;i++){
        n1=rand()%max_x;
        n2=rand()%max_y;
        if(m[n2][n1]==0){
            location.Nx=n1;//キャラクターのx座標の決定
            location.Ny=n2;//キャラクターのy座標の決定
        }else{
            i=i-1;
        }
    }
    for(i=0;i<2;i++){
        n1=rand()%max_x;
        n2=rand()%max_y;
        if(m[n2][n1]==0){
            location.Ex=n1;//ゴールのx座標の決定
            location.Ey=n2;//ゴールのy座標の決定
        }else{
            i=i-1;
        }
    }
    visit(0,0,location);
    if(success==1){
        printf("ゴール\n");
    }else{
        printf("出口は見つかりませんでした");
    }
    return 0;
}


//view関数(マップを表示)
void view(struct Location location){
    int i,j;
    system("clear");//コンソールアプリケーションで画面をクリアし任意の値を表示することができる
    for(i=0;i<max_y;i++){//縦方向
        for(j=0;j<max_x;j++){//横方向
            if(i==location.Ny&&j==location.Nx){//現在地を表示
                printf("A ");
            }else if(i==location.Ey&&j==location.Ex){//ゴールを表示
                printf("@ ");
            }else if(m[i][j]==0){//未通過地点を表示
                printf("  ");
            }else if(m[i][j]==1){//一度通過したことがある地点を表示
                printf("o ");
            }else if(m[i][j]==2){//壁を表示
                printf("[]");
            } 
        }
        printf("\n");
    }
    printf("\n");
    puts("");
    getc(stdin);//gets関数は標準入力から１行分の文字列を入力受け付ける
    //戻り値として、成功時は、読み取った文字の文字コードを返し、失敗時は、EOFを返す。
}

//visit関数(迷路探索を行う)
void visit(int y,int x,struct Location location){
    location.Ny=location.Ny+y;
    location.Nx=location.Nx+x;
    if(location.Ny==location.Ey&&location.Nx==location.Ex){//ゴール位置の判断
        success=1;
    }
    m[location.Ny][location.Nx]=1;
    view(location);
    if(success!=1&&m[location.Ny][location.Nx+1]==0){//右チェック
        visit(0,+1,location);//右移動
    }
    if(success!=1&&m[location.Ny][location.Nx-1]==0){//左チェック
        visit(0,-1,location);//左移動
    }
    if(success!=1&&m[location.Ny-1][location.Nx]==0){//上チェック
        visit(-1,0,location);//上移動
    }
    if(success!=1&&m[location.Ny+1][location.Nx]==0){//下チェック
        visit(+1,0,location);//下移動
    }
    if(success!=1){//ゴールチェック
        location.Ny=location.Ny-y;
        location.Nx=location.Nx-x;
        view(location);
    }
    return;
}