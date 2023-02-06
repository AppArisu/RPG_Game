#pragma once
#include <DirectXMath.h>
#include <wrl.h>
#include <d3d11.h>

//	UV�X�N���[�����
struct UVScrollData
{
	DirectX::XMFLOAT2	uvScrollValue;	// UV�X�N���[���l
};

// �}�X�N�f�[�^
struct MaskData
{
	ID3D11ShaderResourceView* maskTexture;
	float					dissolveThreshold;
};

// �����_�[�R���e�L�X�g
struct RenderContext
{
	ID3D11DeviceContext* deviceContext;

	DirectX::XMFLOAT4X4		view;
	DirectX::XMFLOAT4X4		projection;
	DirectX::XMFLOAT4		lightDirection;
	DirectX::XMFLOAT4		viewPosition;

	ID3D11ShaderResourceView* shaderResourceView = nullptr;
	ID3D11ShaderResourceView* envShaderResourceView = nullptr;
	DirectX::XMFLOAT4X4 shadowViewProjection;

	float timer = 0.0f;

	// UV�X�N���[���f�[�^
	UVScrollData uvScrollData;
	// �}�X�N�f�[�^
	MaskData				maskData;
};