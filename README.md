# 3D Rotating Cube in C
Might have to be Linux to work.
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
