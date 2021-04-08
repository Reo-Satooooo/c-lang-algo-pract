//内容：クイックソート(任意の個数のデータ)
//作成者：佐藤玲央
//最終更新日：2020年11月10日

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define N 100

//プロトタイプ宣言
void quickSort(int,int,int data[]);
long getTime(void);

//main関数
int main(void){
    int data[N];
    int i;
    time(NULL);
    for(i=0;i<N;i++){
        int x=(rand()%N)+1;
        data[i]=x;
    }
    quickSort(0,N-1,data);
    return 0;
}

//quickSort関数
void quickSort(int left,int right,int data[]){//leftは左端のインデックス、rightは右端のインデックスを表す。
    //leftはpivoteのインデックスとして扱う。
    int pivot=left;
    int i,j,tmp1,tmp2;
    if(left>=right){//leftがright以上であればreturn
        return;
    }
    i=left+1;
    j=right;
    while (1){
        //a[i]がa[left]よりも大きくなるか、iがright以上になるまで、iをインクリメントし続ける。
        while (1){
            if(data[i]>data[left]||i>=right){
                break;
            }
            i=i+1;
        }
        //a[j]がa[left]よりも小さくなるか、jがleft以下になるまで、jをデクリメントし続ける。
        while (1){
            if(data[j]<data[left]||j<=left){
                break;
            }
            j=j-1;
        }
        if(i>=j){//iがj以上であれば、ループを抜ける。
            break;
        }
    //a[i]とa[j]を交換する。
    tmp1=data[i];
    data[i]=data[j];
    data[j]=tmp1;    
    }
    //a[left]とa[j]を交換する。
    tmp2=data[left];
    data[left]=data[j];
    data[j]=tmp2;
    //配列の内容を表示する
    int k;
    for(k=0;k<N;k++){
        printf("%d,",data[k]);
    }
    printf("\n");
    //再帰処理
    quickSort(left,j-1,data);
    quickSort(j+1,right,data);
}

//getTime関数
long getTime(void){
    struct timeval t;
    gettimeofday(&t,NULL);
    localtime(&t.tv_sec);
    return time(NULL)*1000+t.tv_usec/1000;
}