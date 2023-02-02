#pragma once
#include<Windows.h>

#include"HighResolutionTimer.h"
#include"Graphic/Graphics.h"

class Framework
{
public:
    Framework(HWND hWnd);
    ~Framework();
private:
    void Update(float elapsedTime);
    void Render(float elapsedTime);

    void CalculateFrameStats();
public:
    int Run();

    LRESULT CALLBACK HandleMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
private:
    const HWND                  hWnd;
    HighResolutionTimer		timer;
    Graphics                        graphics;
};