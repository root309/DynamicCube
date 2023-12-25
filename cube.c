#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

float A = 0, B = 0, C = 0; // 回転のための変数

const float cubeWidth = 10; // キューブの幅
int width = 160, height = 44; // コンソールの幅と高さ
float zBuffer[160 * 44];
char buffer[160 * 44];
int backgroundASCIICode = ' ';
int distanceFromCam = 60; // カメラからの距離
float K1 = 40; // 視点のズーム

float incrementSpeed = 0.6; // キューブの回転速度

float x,y,z;
float ooz;
int xp,yp;
int idx;

// 8つの頂点を持つキューブの定義
float vertices[8][3] = {
    {-cubeWidth, -cubeWidth, -cubeWidth},
    {cubeWidth, -cubeWidth, -cubeWidth},
    {cubeWidth, cubeWidth, -cubeWidth},
    {-cubeWidth, cubeWidth, -cubeWidth},
    {-cubeWidth, -cubeWidth, cubeWidth},
    {cubeWidth, -cubeWidth, cubeWidth},
    {cubeWidth, cubeWidth, cubeWidth},
    {-cubeWidth, cubeWidth, cubeWidth}
};

// キューブの各面を構成する頂点のインデックス
int faces[6][4] = {
    {0, 1, 2, 3}, // 前面
    {4, 5, 6, 7}, // 背面
    {0, 3, 7, 4}, // 左面
    {1, 2, 6, 5}, // 右面
    {0, 1, 5, 4}, // 下面
    {3, 2, 6, 7}  // 上面
};

// 3D空間の点を2Dスクリーン上に変換するための関数
float calculateX(int i , int j, int k){
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
           j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}
float calculateY(int i, int j, int k){
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
           j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
           i * cos(B) * sin(C);
}
float calculateZ(int i ,int j ,int k ){
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

// 3Dの頂点で面を描画するための関数
void calculateForSurface(float cubeX,float cubeY,float cubeZ,int ch){
    x = calculateX(cubeX,cubeY,cubeZ);
    y = calculateY(cubeX,cubeY,cubeZ);
    z = calculateZ(cubeX,cubeY,cubeZ) + distanceFromCam;

    ooz = 1/z;

    xp = (int)(width/2 + K1 * ooz * x * 2);
    yp = (int)(height/2 + K1 * ooz * y);

    idx = xp + yp * width;
    if(idx>= 0 && idx < width * height){
        if(ooz> zBuffer[idx]){
            zBuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }
}

int main(){
    printf("\x1b[2J"); // コンソールをクリア

    while(1){
        memset(buffer, backgroundASCIICode, width * height);
        memset(zBuffer, 0, width * height * sizeof(float));

        // キューブの各面を描画
        for(int face = 0; face < 6; face++) {
            for(int v = 0; v < 4; v++) {
                // 頂点を取得
                float *vertex = vertices[faces[face][v]];
                // 頂点で面を描画
                calculateForSurface(vertex[0], vertex[1], vertex[2], 'X'); // または他の文字
            }
        }

        // バッファを出力
        printf("\x1b[H");
        for(int k = 0; k < width * height; k++){
            putchar(k % width ? buffer[k] : 10);
        }

        // キューブを回転
        A += 0.04;
        B += 0.04;
        C += 0.04;

        // 一時停止
        struct timespec sleepTime;
        sleepTime.tv_sec = 0;
        sleepTime.tv_nsec = 50000000;
        nanosleep(&sleepTime, NULL);
    }
    return 0;
}

