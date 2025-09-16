# HW1

This directory contains the files for **HW1**.

## 📄 Project Introduction

### Project Introduction

This assignment, "Programming Assignment One" for the "Data Structures and Object-oriented Programming" course, aims for students to develop two core components for a system that draws mathematical curves. The primary objective is to implement the `CURVE_FUNCTION` and `GRAPH_MANAGER` classes using a provided template, applying object-oriented programming principles. The system will display various curve types based on user interactions, showcasing their properties such as extreme points and boundary points, and summary statistics in the window's top bar.

### Methods Used

*   **Object-Oriented Programming (OOP)**: Fundamental to the assignment, requiring the design and implementation of two classes, `CURVE_FUNCTION` and `GRAPH_MANAGER`, to encapsulate curve logic and management.
*   **Mathematical Function Implementation**: Three specific mathematical functions (Exponential, Consine, Quadratic) are to be implemented to generate curve points based on `x`, `c`, and `d` parameters.
    *   **CURVE_TYPE_EXPONENTIAL**: `y = w / 10 - 1 + (c + sin(4 d w)) * e^-w` where `w = (x / 2.5)`
    *   **CURVE_TYPE_CONSINE**: `y = c x - d x cos(x)`
    *   **CURVE_TYPE_QUADRATIC**: `y = x^2 + c x + d`
*   **Double Precision Calculations**: All floating-point numbers and calculations must use `double` precision, with display values showing up to 8 decimal digits.
*   **Random Number Generation**: Parameter `c` for curves is randomly generated within a specified bound.
*   **User Interaction Handling**: Keyboard inputs (e.g., F1, F2, 's', '1', '2', '3', 'k', 'l', '<', '>', 'n', 'm') are used to control curve types, numbers, sample points, and parameters.
*   **Graphical Display**: The underlying system uses OpenGL (implied by the `SOGLFramework.sln` project) to render curves, including highlighting extreme and boundary points.

### Experimental Procedures

1.  **Environment Setup**:
    *   Convert the provided Visual Studio 2010 project template (`SOGLFramework.sln`) to Visual Studio 2019.
    *   Set the Platform Toolset to `Visual Studio 2019 (v142)` in project properties.
    *   Resolve any build errors, specifically `LNK1207` by deleting `.pdb` and `.obj` files in the `./Release` directory before rebuilding.
2.  **Student Information Integration**:
    *   Populate personal details (name, ID, email) in `mySystemApp.h`.
    *   Configure the `STUDENT_INFO` macro in `mySystem.cpp` to display this information in the window's top bar.
    *   Implement `showMyStudentInfo_2023()` in `mySystemApp.cpp` to display student information (date, ID, name, email) on the console when 's' or 'S' is pressed.
3.  **CURVE_FUNCTION Class Implementation**:
    *   Implement methods to define the number of sample points (`setNumOfSamplePoints`), specify the `x` interval (`getIntervalOfX` as `[-2, 5]`), compute `y` values for given `x` (`getValue`), identify boundary points (`getBoundaryPoint`), and determine extreme sample points (`getExtremePoints`).
    *   Implement the three specified mathematical curve functions.
4.  **GRAPH_MANAGER Class Implementation**:
    *   Instantiate and manage an array of `CURVE_FUNCTION` objects.
    *   Implement methods to return the total number of curves (`getNumCurves`), total sample points across all curves (`getNumOfSamplePoints`).
    *   Develop `setCurves_Random_C()` to randomly generate `c` values for all curves within `[mC_LowerBound, mC_UpperBound]`.
    *   Implement methods to retrieve the lowest, largest, and average `c` values (`getC_Lowest`, `getC_Largest`, `getC_Average`).
5.  **Interactive Control Implementation**:
    *   Implement keyboard handlers for:
        *   `F1`: Set number of curves to minimum.
        *   `F2`: Set number of curves to maximum.
        *   `1`, `2`, `3`: Change curve type (Exponential, Consine, Quadratic).
        *   `k`, `l`: Decrease/increase `mNumOfSamplePoints` by `delta_num`.
        *   `<`, `>`: Decrease/increase `mNumCurves` by 10 (regenerating `c` values).
        *   `n`, `m`: Decrease/increase `mParam_D` by `mDelta_D`.
6.  **Adherence to Specifications**: Ensure adherence to the specified `x` interval, default sample points (`MAX_NUM_SAMPLE_POINTS / 2`), and `double` precision for all calculations.

### Summary of Experimental Results

*(This section is typically completed by the student after finishing the assignment. The PDF describes expected outcomes.)*

Upon successful implementation and execution, the program is expected to display dynamically generated curves. The window's top bar will show real-time statistics including the number of curves, average `c` value, lowest `c` value, largest `c` value, `d` value, and the number of sample points. Extreme points of the curves will be highlighted in blue, while boundary points (leftmost/rightmost) will be drawn in different colors, demonstrating the functionalities of both `CURVE_FUNCTION` and `GRAPH_MANAGER`. User interaction via keyboard shortcuts will allow real-time modification and observation of these curve parameters and their visual representation.

### Potential Improvements

*   **Robust Error Handling**: Implement more comprehensive error checking and user feedback for invalid inputs or edge cases, especially concerning the bounds for `mNumOfSamplePoints`, `mNumCurves`, and `mParam_D`.
*   **Dynamic Curve Management**: Explore ways to add or remove individual curves dynamically rather than just increasing/decreasing the total count by a fixed amount.
*   **User Interface Enhancement**: Instead of solely relying on keyboard shortcuts, a basic graphical user interface (GUI) could be developed for more intuitive control of parameters and curve selection.
*   **Additional Curve Types**: Expand the system to support a wider variety of mathematical functions or custom curve definitions.
*   **Performance Optimization**: For a very large number of curves or high sample point counts, investigate optimizations for drawing and calculation, such as multi-threading or GPU acceleration if applicable.
*   **Code Quality**: Conduct thorough debugging to identify and fix any remaining bugs, as hinted by the assignment instruction, ensuring well-written and maintainable code.

### How to Run and Reproduce

1.  **Prerequisites**: Install Visual Studio 2019 (or a later compatible version) with the "Desktop development with C++" workload selected.
2.  **Obtain Project Template**: Get the `hw01_oop_202302.pdf` assignment template files, specifically locate the `SOGLFramework.sln` solution file.
3.  **Open and Upgrade Project**:
    *   Right-click `SOGLFramework.sln` and choose "Open with" -> "Visual Studio 2019".
    *   Visual Studio will likely prompt you to upgrade the project. Follow the prompts to upgrade the platform to the newest version and set the compiler version to `v142`. Confirm the changes.
    *   If not prompted, or for manual verification, open the project in Visual Studio. Go to `Project` -> `SOGLFramework Properties...`. In the configuration properties dialog, navigate to `Configuration Properties` -> `General`. Under `Project Defaults`, ensure "Platform Toolset" is set to `Visual Studio 2019 (v142)`. Click "Apply" and "OK".
4.  **Clean Build Artifacts**: Before building, navigate to the project directory (e.g., `..\OOP_HW01_NET2019_202202_Template_Student\Release`). Delete all files with `.obj` and `.pdb` extensions (e.g., `myFirstSystem.pdb`). This step is crucial to resolve potential `LNK1207` errors from the old Visual Studio 2010 template.
5.  **Build the Solution**: In Visual Studio, press `ALT + B + B` or go to `Build` -> `Build Solution`. For a clean rebuild, use `CTRL + ALT + F7` or `Build` -> `Rebuild Solution`. Ensure the build output shows "Build: 1 Succeeded, 0 Failed".
6.  **Run the Executable**: After a successful build, the executable `enjoy_programming.exe` will be located in the `./bin/Release` folder relative to your project's root directory. Run this executable to interact with the curve drawing system.
7.  **Submission**: Once the assignment requirements are met, rename your root source code folder to `ID_Name` (e.g., `012345678_Mary`), compress it into a `.zip` file, and upload it to the E3 platform. Be prepared to demo your work to the TAs.

## 📂 Files

- `hw01_oop_202302.pdf`

A detailed project description and summary can be found in the [main repository README](../README.md).

