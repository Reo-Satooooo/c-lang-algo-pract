//内容：ヒープソート
//最終更新日：2020年11月6日

#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

//グローバル変数
int m=SIZE-1;//二分木の最大インデックス
int array[SIZE]={4,2,6,1,3,7,5};

//プロトタイプ宣言
void heap(void);
void swap(int*,int*);
void heapSort();
void view();
void viewTree(char *);
void heapDown(int);

//main関数
int main(void){
    viewTree("初期状態");
    heapSort();
}

//heap関数(配列のヒープ構造化)
void heap(){
    int i,j;
    for(i=(m-1)/2;i>=0;i--){
        j=i;
        while(1){
            heapDown(j);
            break; 
        }
    }
}

//swap関数(2変数を交換する関数)
void swap(int*a,int*b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
    return;
}

//heapSort関数(ヒープの再構築を繰り返す)
void heapSort(){
    while(m>=1){
        heap();
        swap(&array[m],&array[0]);
        if(m==1){
            viewTree("ソートを終了します。");
            return;
        }
        viewTree("ソートします");
        m--;
    }
    return;
}

//view関数(ヒープの状態を確認する)
void view(){
    int i;
    for(i=0;i<SIZE;i++){
        printf("%d",array[i]);
    }
    printf("\n");
    return;
}

//viewTree関数(ヒープを二分木で表示する)
void viewTree(char *hoge){
    int i,j;
    //iは二分木の各段の先頭のインデックスとなる
    printf("%s\n",hoge);
    for(i=1;i<=SIZE;i*=2){
        //jは各段の先頭からの相対位置となる
        for(j=0;j<i;j++){
            printf("%d",array[i+j-1]);
        }
        getchar();
    }
    if(m!=1){
        system("clear");
    }
}

//heapDown関数(heap関数の再帰化)
void heapDown(int j){
    if(2*j+2<m&&array[2*j+2]>array[j]&&array[2*j+2]>array[2*j+1]){
        swap(&array[j],&array[2*j+2]);//親と右の子を交換
        heapDown(2*j+2);//j＝右の子のインデックス
        viewTree("ソートします");
    }else if(2*j+1<m&&array[2*j+1]>array[j]){
        swap(&array[j],&array[2*j+1]);//親と左の子を交換
        heapDown(2*j+1);//j＝左の子のインデックス
        viewTree("ソートします");
    }
}