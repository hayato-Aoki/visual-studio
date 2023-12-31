// pro11.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#pragma warning(disable:4996)
#include<math.h>
#include<limits.h>
#include<windows.h>
#define COUNTOF(array) (sizeof(array)/sizeof(array[0]))

typedef struct record {
    char city[50];
    char country[50];
    double data[20]; 
}record;

void PrintD(struct record D[], int D_SIZE, int target) {
    for (int i = 99; i < 110; i++) {
        printf("%s %s %f\n", D[i].city, D[i].country, D[i].data[target]);
    }
    printf("\n");
}

void swap(struct record* a, struct record* b) {
    record temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void Merge(record D[], record M[], int left, int mid, int right,int target) {
    int x = left; int y = mid + 1;
    printf("aaaa");
    for (int i = 0; i <= right - left; i = i + 1) {
        if (x == mid + 1) { M[i] = D[y]; y = y + 1; }
        else if (y == right + 1) {
            M[i] = D[x]; x = x + 1;
        }
        else if (D[x].data[target] >= D[y].data[target]) {
            M[i] = D[x]; x = x + 1;
        }
        
        else { M[i] = D[y]; y = y + 1; }
    }

    for (int i = 0; i <= right - left; i = i + 1) {
        D[left + i] = M[i];
   
    }
}
void MergeSort(record D[], record M[], int left, int right,int target) {
    printf("bbbb");
    int mid = (left + right) / 2;
   
    if (left < mid) { MergeSort(D,M, left, mid,target); }
    if (mid + 1 < right) { MergeSort(D, M, mid + 1, right,target); }
    Merge(D, M, left, mid, right,target);
}

int main()
{
    FILE* fpi;
    fopen_s(&fpi, "city_population.txt", "r");
    /*いつものようにファイルを読み込み、配列 D に
     値を代入する。D_SIZEは配列Dの大きさ*/
    int D_SIZE=1692;
    char city[50];
    char county[50];
    int target = 9;
    double a, b, c, d, e, f, g, h, j;
    record* D = (record*)(malloc(sizeof(record) * D_SIZE));
    record* M = (record*)(malloc(sizeof(record) * D_SIZE));
    memset(M, 0, D_SIZE * sizeof(int));
    for (int i = 0; i < D_SIZE; i++) { 
        fscanf(fpi, "%s %s %lf %lf %lf %lf %lf %lf %lf %lf %lf", city, county, &a, &b, &c, &d, &e, &f, &g, &h, &j);
        strcpy(D[i].city, city);
        strcpy(D[i].country, county);
        D[i].data[0] = a;
        D[i].data[1] = b;
        D[i].data[2] = c;
        D[i].data[3] = d;
        D[i].data[4] = e;
        D[i].data[5] = f;
        D[i].data[6] = g;
        D[i].data[7] = h;
        D[i].data[8] = j;
        D[i].data[9] = (d + e + f + g) / 4.0;
    }
     //タイマースタート
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    // 計算の開始時にカウンタ値を記録
    LARGE_INTEGER start, end;
    QueryPerformanceCounter(&start);
    MergeSort(D, M, 0, D_SIZE - 1,target);
    QueryPerformanceCounter(&end);
    // 経過時間を計算
    LONGLONG span = end.QuadPart - start.QuadPart;
    double sec = (double)span / (double)frequency.QuadPart;
  
    printf("cccc");
    PrintD(D, D_SIZE, target);
    //ソート後の配列に対するハッシュ値
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
