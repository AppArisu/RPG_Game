#pragma once
#include "Character.h"

class Enemy :public Character
{
public:
    Enemy() {}
    ~Enemy() override {}

    void Update(float elapsedTime) override {}
    void Render() override {}

    // ”j‰ó
    void Destroy();
};