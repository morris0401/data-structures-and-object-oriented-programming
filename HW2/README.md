# HW2

This directory contains the files for **HW2**.

## 📄 Project Introduction

# A Modular and Robust 2D Painting System for Interactive Graphics Education

## Introduction
The development of interactive graphics applications serves as a cornerstone for teaching foundational principles in Object-Oriented Programming (OOP) and Data Structures. This project addresses the challenge of creating a versatile yet robust 2D painting system, `SIMPLE_PAINTER`, integrated into a larger `SOGLFramework`. The primary goal is to provide a platform for demonstrating sophisticated pixel manipulation, brush mechanics, and seamless subsystem integration, all while maintaining high numerical precision and stability. Existing frameworks often lack explicit guidance for robust boundary handling and modular subsystem design, prompting the need for a self-contained, extensible painting component capable of complex drawing operations without compromising system integrity. Our work focuses on building a painter module that not only performs fundamental graphic operations but also exemplifies rigorous software engineering practices crucial for real-world graphics development.

## Methods
The `SIMPLE_PAINTER` system is implemented in C++ within the .NET platform using Visual Studio 2019 and the v142 compiler, ensuring compatibility and leveraging modern compiler optimizations. All floating-point arithmetic throughout the system exclusively utilizes `double` precision, with results displayed up to 8 decimal places, guaranteeing numerical accuracy essential for nuanced color blending.

The core of the system is the `SIMPLE_PAINTER` class, designed for modularity and encapsulation. It manages a canvas represented as a two-dimensional array of `vector3` objects, where each `vector3` specifies the Red, Green, and Blue color components of a pixel, normalized to the range [0, 1].

### Brush Mechanism and Weighted Pixel Blending
Drawing operations are performed using a disk-shaped brush, activated by `clickAt(double x, double y)`. The brush's radius is dynamically controlled by `mBrushSize`, approximately `2*mBrushSize`. Critical to the system's visual fidelity is a weighted pixel drawing algorithm. For each pixel within the brush's active disk, a weight (`w`) is computed based on its distance from the brush's center. This weight follows a Gaussian-like distribution, assigning higher weights (up to 1.0 for uniform application) to pixels closer to the center and gradually decreasing for pixels further out.

The `drawAt(int x, int y, const vector3 &color, double w)` method then blends the `new color` with the existing pixel color using the formula: `new_color = current_color*(1.0-w*w) + w*w*color;`. This approach ensures smooth transitions and realistic color application, while rigorous boundary checks are performed to prevent crashes when the brush interacts with the canvas edges, a key design principle.

### User Interaction
The system supports interactive control via keyboard inputs:
*   `'n'` / `'N'` and `'m'` / `'M'` for decreasing and increasing brush size, respectively.
*   `'1'`, `'2'`, `'3'` for setting the current brush color to red, green, or blue.
*   `'r'` to `reset()` the canvas, filling all pixels with new randomly generated RGB colors.
*   `'s'` / `'S'` and `'i'` / `'I'` provide access to student and system information, illustrating robust system integration and information display.

## Results
This project successfully implemented `SIMPLE_PAINTER` as a fully functional and robust subsystem within the `SOGLFramework`. The object-oriented design facilitated seamless integration, allowing for clear separation of concerns and maintainable code. The weighted pixel blending algorithm produced visually coherent and smooth brush strokes, effectively demonstrating advanced pixel-level manipulation and color theory principles. Crucially, the system exhibited high stability, with all brush operations, even at canvas boundaries, executed without crashes, validating the robust error handling and boundary checks implemented.

The interactive nature of the application, driven by keyboard commands, provided a dynamic platform for real-time demonstration of painting functionalities. The accurate display of student and system information further confirmed the correct implementation of interface interactions and data propagation within the `SOGLFramework`. The project serves as a compelling example of leveraging OOP and data structures to build an extensible and stable interactive graphics application, proving the effectiveness of precise numerical computation and careful algorithmic design in achieving both functionality and reliability in graphics programming.

## 📂 Files

- `hw02_oop_01_202302.pdf`
- `hw02_oop_02_painter_202302.pdf`
- `mySystemApp.cpp`
- `mySystemApp.h`
- `mySystem_SimplePainter.cpp`
- `mySystem_SimplePainter.h`

A detailed project description and summary can be found in the [main repository README](../README.md).

