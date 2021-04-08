//内容：バブルソート
//最終更新日：2020年11月10日

#include <stdio.h>
#define DATASIZE 10

//プロトタイプ宣言

//グローバル宣言

int main(void){
    int data[DATASIZE]={9,3,5,4,1,7,2,6,10,8};
    int i,j,tmp;

    for(i=0;i<DATASIZE-1;i++){
        for(j=DATASIZE-1;j>i;j--){
            if(data[j]<data[j-1]){
                tmp=data[j];
                data[j]=data[j-1];
                data[j-1]=tmp;
            }
        }
        int k;
    for(k=0;k<DATASIZE;k++){
        printf("%d,",data[k]);
    }
    printf("\n");
    }
}