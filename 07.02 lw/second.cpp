#include "Windows.h"
#include "windowsx.h"
#include "tchar.h"
#include "string"

  LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

 int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
    WCHAR className[] = L"FirstWindow";

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
        L"My first window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 500, 
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
    case WM_LBUTTONDOWN:
        SetWindowText(hwnd, L"Calculator");
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