#include <windows.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <assert.h>

const char NazwaKlasy[] = "Klasa Okienka";
MSG Komunikat;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
HWND g_hPrzyciskDodaj;
HWND g_hPrzycisk7;
HWND g_hPrzycisk8;
HWND g_hPrzycisk9;
HWND g_hPrzyciskDziel;
HWND g_hPrzycisk4;
HWND g_hPrzycisk5;
HWND g_hPrzycisk6;
HWND g_hPrzyciskMnoz;
HWND g_hPrzycisk1;
HWND g_hPrzycisk2;
HWND g_hPrzycisk3;
HWND g_hPrzyciskMinus;
HWND g_hPrzyciskC;
HWND g_hPrzycisk0;
HWND g_hPrzyciskRowna;
HWND hText;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = NazwaKlasy;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Wysoka Komisja odmawia rejestracji tego okna!", "Niestety...",
            MB_ICONEXCLAMATION | MB_OK);
        return 1;
    }

    HWND hwnd;

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, NazwaKlasy, "Oto okienko", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 720, 480, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL)
    {
        MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        return 1;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);



    g_hPrzycisk7 = CreateWindowEx(0, "BUTTON", "7", WS_CHILD | WS_VISIBLE,
        10, 10, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzycisk8 = CreateWindowEx(0, "BUTTON", "8", WS_CHILD | WS_VISIBLE,
        40, 10, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzycisk9 = CreateWindowEx(0, "BUTTON", "9", WS_CHILD | WS_VISIBLE,
        70, 10, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzyciskDziel = CreateWindowEx(0, "BUTTON", "/", WS_CHILD | WS_VISIBLE,
        100, 10, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzycisk4 = CreateWindowEx(0, "BUTTON", "4", WS_CHILD | WS_VISIBLE,
        10, 40, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzycisk5 = CreateWindowEx(0, "BUTTON", "5", WS_CHILD | WS_VISIBLE,
        40, 40, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzycisk6 = CreateWindowEx(0, "BUTTON", "6", WS_CHILD | WS_VISIBLE,
        70, 40, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzyciskMnoz = CreateWindowEx(0, "BUTTON", "*", WS_CHILD | WS_VISIBLE,
        100, 40, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzycisk1 = CreateWindowEx(0, "BUTTON", "1", WS_CHILD | WS_VISIBLE,
        10, 70, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzycisk2 = CreateWindowEx(0, "BUTTON", "2", WS_CHILD | WS_VISIBLE,
        40, 70, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzycisk3 = CreateWindowEx(0, "BUTTON", "3", WS_CHILD | WS_VISIBLE,
        70, 70, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzyciskMinus = CreateWindowEx(0, "BUTTON", "-", WS_CHILD | WS_VISIBLE,
        100, 70, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzyciskC = CreateWindowEx(0, "BUTTON", "C", WS_CHILD | WS_VISIBLE,
        10, 100, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzycisk0 = CreateWindowEx(0, "BUTTON", "0", WS_CHILD | WS_VISIBLE,
        40, 100, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzyciskRowna = CreateWindowEx(0, "BUTTON", "=", WS_CHILD | WS_VISIBLE,
        70, 100, 30, 30, hwnd, NULL, hInstance, NULL);
    g_hPrzyciskDodaj = CreateWindowEx(0, "BUTTON", "+", WS_CHILD | WS_VISIBLE,
        100, 100, 30, 30, hwnd, NULL, hInstance, NULL);

    hText = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER , 150, 10, 150, 30, hwnd, NULL, hInstance, NULL);



    while (GetMessage(&Komunikat, NULL, 0, 0))
    {
        TranslateMessage(&Komunikat);
        DispatchMessage(&Komunikat);
    }
    return Komunikat.wParam;
}
void AppendText(const HWND& hwnd, TCHAR* newText)
{
    // get edit control from dialog
    HWND hwndOutput = GetDlgItem(hwnd, 0);

    // get new length to determine buffer size
    int outLength = GetWindowTextLength(hwndOutput) + lstrlen(newText) + 1;

    // create buffer to hold current and new text
    TCHAR* buf = (TCHAR*)GlobalAlloc(GPTR, outLength * sizeof(TCHAR));
    if (!buf) return;

    // get existing text from edit control and put into buffer
    GetWindowText(hwndOutput, buf, outLength);

    // append the newText to the buffer
    _tcscat_s(buf, outLength, newText);

    // Set the text in the edit control
    SetWindowText(hwndOutput, buf);

    // free the buffer
    GlobalFree(buf);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case  WM_COMMAND:
        if ((HWND) lParam == g_hPrzyciskDodaj){
            AppendText(hText, new TCHAR('+'));
        }
        if ((HWND)lParam == g_hPrzyciskDziel) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzyciskMnoz) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzyciskMinus) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzyciskRowna) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzycisk7) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzycisk8) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzycisk9) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzycisk4) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzycisk5) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzycisk6) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzycisk1) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzycisk2) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzycisk3) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzyciskC) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }
        if ((HWND)lParam == g_hPrzycisk0) {
            MessageBox(NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
        }


    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}