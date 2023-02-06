#pragma once
#include<wrl.h>
#include<d3d11.h>
#include<DirectXMath.h>

class Sprite
{
public:
    Sprite();
    Sprite(const char* filename);
    ~Sprite() {}

    struct Vertex
    {
        DirectX::XMFLOAT3 position;
        DirectX::XMFLOAT4 color;
        DirectX::XMFLOAT2 texcoord;
    };

    // �o�b�t�@�X�V
    void Update(
        float dx, float dy,
        float dw, float dh,
        float sx, float sy,
        float sw, float sh,
        float angle,
        float r, float g, float b, float a) const;

    // �`����s
    void Render(ID3D11DeviceContext* dc,
        float dx, float dy,
        float dw, float dh,
        float sx, float sy,
        float sw, float sh,
        float angle,
        float r, float g, float b, float a) const;

    // �e�N�X�`�����擾
    int GetTextureWidth() const { return textureWidth; }

    // �e�N�X�`�������擾
    int GetTextureHeight() const { return textureHeight; }

    // �V�F�[�_�[���\�[�X�r���[�̐ݒ�
    void SetShaderResourceView(const Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>& srv, int texWidth, int texHeight);

    // ���_�o�b�t�@�̎擾
    const Microsoft::WRL::ComPtr<ID3D11Buffer>& GetVertexBuffer() const { return vertexBuffer; }

    // �V�F�[�_�[���\�[�X�r���[�̎擾
    const Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>& GetShaderResourceView() const { return shaderResourceView; }

protected:

    Microsoft::WRL::ComPtr<ID3D11VertexShader>			vertexShader;
    Microsoft::WRL::ComPtr<ID3D11PixelShader>			pixelShader;
    Microsoft::WRL::ComPtr<ID3D11InputLayout>			inputLayout;

    Microsoft::WRL::ComPtr<ID3D11Buffer>				vertexBuffer;

    Microsoft::WRL::ComPtr<ID3D11BlendState>			blendState;
    Microsoft::WRL::ComPtr<ID3D11RasterizerState>		rasterizerState;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilState>		depthStencilState;

    Microsoft::WRL::ComPtr<ID3D11SamplerState>			samplerState;
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	shaderResourceView;
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	maskShaderResourceView;

    int textureWidth = 0;
    int textureHeight = 0;
};