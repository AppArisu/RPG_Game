#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
#include"RenderContext.h"
#include"Sprite.h"

class SpriteShader
{
public:
    SpriteShader() {}
    virtual ~SpriteShader() {}

    // �`��J�n
    virtual void Begin(const RenderContext& rc) = 0;

    // �`��
    virtual void Draw(const RenderContext& rc, const Sprite* sprite) = 0;

    // �`��I��
    virtual void End(const RenderContext& rc) = 0;
};