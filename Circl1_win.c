
/*********************************************************************************************
 * Sure! To create a circle using raw drawing functions instead of the `Ellipse` function,   *
 * you can manually plot points to form a circle.                                            * 
 * Here's an example using the `SetPixel` function to draw a circle:                         *
 *                                                                                           *              
 *```c                                                                                       *
 *********************************************************************************************/
#include <windows.h>
#include <math.h>

// Function declarations
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

// Global variables
char szClassName[] = "CircleWindowClass";

void DrawCircle(HDC hdc, int centerX, int centerY, int radius) {
    int x, y;
    for (int angle = 0; angle < 360; angle++) {
        x = centerX + (int)(radius * cos(angle * M_PI / 180.0));
        y = centerY + (int)(radius * sin(angle * M_PI / 180.0));
        SetPixel(hdc, x, y, RGB(0, 0, 0));
    }
}

int main() {
    HINSTANCE hInstance = GetModuleHandle(NULL);
    WNDCLASSEX wc;
    HWND hwnd;
    MSG msg;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WindowProcedure;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        szClassName,
        "Circle Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            // Draw a circle
            DrawCircle(hdc, 200, 200, 100);
            EndPaint(hwnd, &ps);
        } break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
/***********************************************************************************************
```

### Explanation:

1. **Include `windows.h` and `math.h`:
   ** These header files are necessary for Windows API functions and mathematical calculations.
2. **Global Variables:** Define a global variable for the window class name.
3. **Main Function:** 
   - **`HINSTANCE hInstance = GetModuleHandle(NULL);`** gets the handle to the current instance of the application.
   - **`WNDCLASSEX wc`:** Defines the properties of the window class.
   - **`RegisterClassEx(&wc)`:** Registers the window class.
   - **`CreateWindowEx`:** Creates the window.
   - **`ShowWindow` & `UpdateWindow`:** Displays the window.
   - **Message Loop:** Uses `GetMessage`, `TranslateMessage`, and `DispatchMessage` to handle window messages.
4. **Window Procedure:**
   - **`WM_PAINT`:** Handles the paint message and draws a circle using the `DrawCircle` function.
   - **`WM_CLOSE`:** Destroys the window when the close button is clicked.
   - **`WM_DESTROY`:** Posts a quit message when the window is destroyed.

### `DrawCircle` Function:
- **`DrawCircle(HDC hdc, int centerX, int centerY, int radius)`:
  ** This function calculates the coordinates of points on the circumference of a circle using trigonometric 
     functions `cos` and `sin`.
- **`SetPixel(hdc, x, y, RGB(0, 0, 0))`:** This function plots the pixel at the calculated coordinates.

This example manually plots points to form a circle. You can adjust the `centerX`, `centerY`, and `radius`
parameters to change the position and size of the circle.

If you have any questions or need further assistance, feel free to ask!
********************************************************************************************/
