#include <memory>
#include <assert.h>
#include <tchar.h>

#include "Framework.h"

// �X�N���[���T�C�Y
const LONG SCREEN_WIDTH = 1280;
const LONG SCREEN_HEIGHT = 720;

HWND ghWnd;

// �E�B���h�E�Y�v���V�[�W��
LRESULT CALLBACK WndProc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam) {
	Framework* f = reinterpret_cast<Framework*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	return f ? f->HandleMessage(hwnd, message, wParam, lParam) : DefWindowProc(hwnd, message, wParam, lParam);
}

// �E�B���h�E
INT WINAPI WinMain(
	HINSTANCE hInstance,			// ���݂̃C���X�^���X�̃n���h��
	HINSTANCE hPrevInstance,		// �ȑO�̃C���X�^���X�̃n���h��
	LPSTR lpCmdLine,					// �R�}���h���C��
	INT nCmdShow						// �\�����
) {
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(237);
#endif

	LPCTSTR szclassName = _T("Window");
	LPCTSTR gameName = _T("GameWindow");
	LPCTSTR iconName = _T("Data/Sprite/Icon/test.ico");
	WNDCLASSEX wcex{};

	ZeroMemory((LPVOID)&wcex, sizeof(WNDCLASSEX));

	//�E�B���h�E�N���X��o�^
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = NULL;
	wcex.cbWndExtra = NULL;
	wcex.hInstance = hInstance;
	wcex.hIcon = (HICON)LoadImage(          // �A�C�R��
		NULL, iconName, IMAGE_ICON,
		NULL, NULL, LR_SHARED | LR_LOADFROMFILE
	);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szclassName;
	wcex.hIconSm = NULL;
	RegisterClassEx(&wcex);


	//�E�B���h�E�쐬
	RECT rc = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	HWND hWnd = CreateWindow(szclassName, gameName,
		WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top,		// �E�B���h�E�T�C�Y
		NULL, NULL, hInstance, NULL);

	ghWnd = hWnd;

	//�E�B���h�E�\��
	ShowWindow(hWnd, nCmdShow);

	//���b�Z�[�W���[�v
	Framework f(hWnd);
	SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(&f));
	f.Run();
}