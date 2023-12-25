# 3D Rotating Cube in C(English)

## Overview
This program creates a dynamic simulation of a rotating 3D cube in a console window. It utilizes trigonometric functions for rotation, a z-buffer for depth handling, and character mapping for rendering.

## Variables
- \(A, B, C\): Rotation angles around the x, y, and z axes, respectively.
- `cubeWidth`: The edge length of the cube.
- `width`, `height`: The dimensions of the console window.
- `zBuffer`: An array to store depth information for each pixel.
- `buffer`: The character buffer for the console display.
- `distanceFromCam`: The distance from the camera to the cube.
- `K1`: A scaling factor for perspective projection.

## Rotation Algorithm
The cube's rotation is achieved by updating the angles \(A, B, C\) over time. The new positions of the cube's vertices are calculated using these rotation matrices:

- **Rotation around the X-axis (A):**
  $$x' = x$$
  $$y' = y \cdot \cos(A) - z \cdot \sin(A)$$
  $$z' = y \cdot \sin(A) + z \cdot \cos(A)$$

- **Rotation around the Y-axis (B):**
  $$x' = x \cdot \cos(B) + z \cdot \sin(B)$$
  $$y' = y$$
  $$z' = -x \cdot \sin(B) + z \cdot \cos(B)$$

- **Rotation around the Z-axis (C):**
  $$x' = x \cdot \cos(C) - y \cdot \sin(C)$$
  $$y' = x \cdot \sin(C) + y \cdot \cos(C)$$
  $$z' = z$$

The `calculateX`, `calculateY`, and `calculateZ` functions implement these transformations.

## Projection
The program uses perspective projection to transform 3D points onto a 2D console screen:
- **Perspective Projection:**
  $$xp = \frac{width}{2} + K1 \cdot \frac{x'}{z'} \cdot 2$$
  $$yp = \frac{height}{2} + K1 \cdot \frac{y'}{z'}$$

Where \((xp, yp)\) are the projected 2D screen coordinates.

## Rendering
- **Z-Buffer Algorithm:** For each pixel, the program stores the closest z-value (depth) to the camera. It ensures that only the nearest object at each pixel is rendered, handling object overlap correctly.
- **Character Mapping:** The cube is rendered using ASCII characters, with different characters representing different parts of the cube.

## Main Loop
The main loop of the program continually updates the rotation angles, recalculates the positions of the cube's vertices, applies the z-buffer algorithm, and renders the updated cube to the console.

## Time Control
The program uses `nanosleep` to control the speed of rotation, making the animation smooth.


# C言語による3D回転キューブ(日本語)

## 概要
このプログラムは、コンソールウィンドウで動的に3Dキューブを回転させるシミュレーションを作成します。回転には三角関数を、深度処理にはzバッファを、レンダリングにはキャラクターマッピングを利用しています。

## 変数
- \(A, B, C\): x軸、y軸、z軸周りの回転角度。
- `cubeWidth`: キューブの辺の長さ。
- `width`, `height`: コンソールウィンドウの寸法。
- `zBuffer`: 各ピクセルの深さ情報を格納する配列。
- `buffer`: コンソール表示用のキャラクターバッファ。
- `distanceFromCam`: カメラからキューブまでの距離。
- `K1`: 視点のスケーリングファクター。

## 回転アルゴリズム
キューブの回転は、時間の経過とともに角度\(A, B, C\)を更新することで達成されます。キューブの頂点の新しい位置は、これらの回転行列を使用して計算されます。

- **X軸周りの回転(A):**
  $$x' = x$$
  $$y' = y \cdot \cos(A) - z \cdot \sin(A)$$
  $$z' = y \cdot \sin(A) + z \cdot \cos(A)$$

- **Y軸周りの回転(B):**
  $$x' = x \cdot \cos(B) + z \cdot \sin(B)$$
  $$y' = y$$
  $$z' = -x \cdot \sin(B) + z \cdot \cos(B)$$

- **Z軸周りの回転(C):**
  $$x' = x \cdot \cos(C) - y \cdot \sin(C)$$
  $$y' = x \cdot \sin(C) + y \cdot \cos(C)$$
  $$z' = z$$

これらの変換を実装するのは`calculateX`、`calculateY`、そして`calculateZ`関数です。

## 投影
プログラムは3D点を2Dコンソールスクリーンに変換するために透視投影を使用します：
- **透視投影:**
  $$xp = \frac{width}{2} + K1 \cdot \frac{x'}{z'} \cdot 2$$
  $$yp = \frac{height}{2} + K1 \cdot \frac{y'}{z'}$$

ここで\((xp, yp)\)は投影された2Dスクリーン座標です。

## レンダリング
- **Zバッファアルゴリズム:** 各ピクセルについて、カメラに最も近いz値（深度）を格納します。これにより、各ピクセルで最も近いオブジェクトのみがレンダリングされ、オブジェクトの重なりが正しく処理されます。
- **キャラクターマッピング:** キューブはASCII文字を使用してレンダリングされ、異なる文字がキューブの異なる部分を表しています。

## メインループ
プログラムのメインループは、回転角度を継続的に更新し、キューブの頂点の位置を再計算し、zバッファアルゴリズムを適用し、更新されたキューブをコンソールにレンダリングします。

## 時間制御
プログラムは`nanosleep`を使用して回転速度を制御し、アニメーションをスムーズにします。
