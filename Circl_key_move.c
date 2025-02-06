/*

Sure! Let's modify the code to move the circle left and right using the arrow keys.
```c
*/
#include <windows.h>
#include <math.h>

// Function declarations
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

// Global variables
char szClassName[] = "CircleWindowClass";
int centerX = 400, centerY = 300, radius = 50, speed = 10;

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
        "Moving Circle Window",
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

            // Draw the circle at the current position
            DrawCircle(hdc, centerX, centerY, radius);

            EndPaint(hwnd, &ps);
        } break;
        case WM_KEYDOWN:
            if (wParam == VK_LEFT) {
                centerX -= speed;  // Move left
            } else if (wParam == VK_RIGHT) {
                centerX += speed;  // Move right
            }
            InvalidateRect(hwnd, NULL, TRUE);  // Force the window to repaint
            break;
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

/*
```

### Explanation:

1. **Global Variables:**
   - `centerX`, `centerY`: Coordinates of the circle's center.
   - `radius`: Radius of the circle.
   - `speed`: Speed at which the circle moves.

2. **Key Handling:**
   - `WM_KEYDOWN`: Checks if the left or right arrow key is pressed (`VK_LEFT`, `VK_RIGHT`).
     - If `VK_LEFT` is pressed, it decreases `centerX` to move the circle left.
     - If `VK_RIGHT` is pressed, it increases `centerX` to move the circle right.
   - `InvalidateRect(hwnd, NULL, TRUE)`: Forces the window to repaint, which triggers `WM_PAINT`.

3. **Drawing the Circle:**
   - `WM_PAINT`: Handles the paint message and draws the circle at the current position.

With this code, the circle will move left and right when you press the arrow keys.
If you have any questions or need further assistance, feel free to ask!
*/



