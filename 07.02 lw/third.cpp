#include "Windows.h"
#include "windowsx.h"
#include "tchar.h"
#include "string"

    LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

 int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
    WCHAR className[] = L"Window";

    WNDCLASSEX wndClass;
    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wndClass.hInstance = hInstance;
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hIconSm = NULL;
    wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = className;

    wndClass.lpfnWndProc = WindowProc;

      if (!RegisterClassEx(&wndClass)) {
          return 0;
      }

    HWND hWnd = CreateWindowEx(
        0,
        className,
        L"First window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 
        400, 400, 
        NULL,
        NULL,
        hInstance,
        NULL
    );

   ShowWindow(hWnd, nShowCmd);
   UpdateWindow(hWnd);

      MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
           DispatchMessage(&msg);
        }

      return msg.wParam;
     }

  LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        if (wParam == VK_RETURN) {
            RECT rect;
            rect.left = 0;
            rect.top = 0;
            rect.right = 300;
            rect.bottom = 300;
            AdjustWindowRect(&rect, GetWindowLong(hwnd, GWL_STYLE), FALSE);
            MoveWindow(hwnd, 0, 0, rect.right - rect.left, rect.bottom - rect.top, TRUE);
        }
        else if (wParam == VK_LEFT) {
            RECT rect;
            GetWindowRect(hwnd, &rect);
            int xPos = rect.left - 10;
            int yPos = rect.top;
            SetWindowPos(hwnd, NULL, xPos, yPos, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        }
        else if (wParam == VK_RIGHT) {
            RECT rect;
            GetWindowRect(hwnd, &rect);
            int xPos = rect.left + 10;
            int yPos = rect.top;
            SetWindowPos(hwnd, NULL, xPos, yPos, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        }
        else if (wParam == VK_UP) {
            RECT rect;
            GetWindowRect(hwnd, &rect);
            int xPos = rect.left;
            int yPos = rect.top - 10;
            SetWindowPos(hwnd, NULL, xPos, yPos, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        }
        else if (wParam == VK_DOWN) {
            RECT rect;
            GetWindowRect(hwnd, &rect);
            int xPos = rect.left;
            int yPos = rect.top + 10;
            SetWindowPos(hwnd, NULL, xPos, yPos, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        }
        break;

    case WM_KEYUP:
        break;
    case WM_LBUTTONDOWN:
        break;
    case WM_RBUTTONDOWN:
        break;
    case WM_MBUTTONDOWN:
        break;
    case WM_MOUSEMOVE:
    {
        int x = GET_X_LPARAM(lParam);
        int y = GET_Y_LPARAM(lParam);
        break;
    }
    case WM_RBUTTONUP:
    {
        RECT rect;
        GetWindowRect(hwnd, &rect); 
        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;
        MoveWindow(hwnd, rect.left, rect.top, width, height, true);
        break;
    }
    case WM_MBUTTONUP:
    {
        RECT rect;
        GetClientRect(hwnd, &rect);
        break;
    }
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

      return 0;
  }