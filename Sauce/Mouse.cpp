#include "Mouse.h"

static FLOAT zero = 0.0f;

enum state
{
	Set,
	Get
};

static const int KeyMap[] =
{
	VK_LBUTTON,		// ���{�^��
	VK_MBUTTON,		// ���{�^��
	VK_RBUTTON,		// �E�{�^��
};

// �R���X�g���N�^
Mouse::Mouse(HWND hWnd) : hWnd(hWnd)
{
	RECT rc;
	GetClientRect(hWnd, &rc);
	screenWidth = rc.right - rc.left;
	screenHeight = rc.bottom - rc.top;
}

// �X�V����
void Mouse::Update()
{
	// �X�C�b�`���
	MouseButton newButtonState = zero;

	for (int i = 0; i < ARRAYSIZE(KeyMap); ++i)
	{
		if (::GetAsyncKeyState(KeyMap[i]) & 0x8000)
		{
			newButtonState |= (1 << i);
		}
	}

	// �z�C�[��
	wheel[state::Get] = wheel[state::Set];
	wheel[state::Set] = 0;

	// �{�^�����X�V
	buttonState[state::Get] = buttonState[state::Set];	// �X�C�b�`����
	buttonState[state::Set] = newButtonState;

	buttonDown = ~buttonState[state::Get] & newButtonState;	// �������u��
	buttonUp = ~newButtonState & buttonState[state::Get];	// �������u��

	// �J�[�\���ʒu�̎擾
	POINT cursor;
	::GetCursorPos(&cursor);
	::ScreenToClient(hWnd, &cursor);

	// ��ʂ̃T�C�Y���擾����B
	RECT rc;
	GetClientRect(hWnd, &rc);
	UINT screenW = rc.right - rc.left;
	UINT screenH = rc.bottom - rc.top;
	UINT viewportW = screenWidth;
	UINT viewportH = screenHeight;

	// ��ʕ␳
	positionX[state::Get] = positionX[state::Set];
	positionY[state::Get] = positionY[state::Set];
	positionX[state::Set] = (LONG)(cursor.x / static_cast<float>(viewportW) * static_cast<float>(screenW));
	positionY[state::Set] = (LONG)(cursor.y / static_cast<float>(viewportH) * static_cast<float>(screenH));
}
