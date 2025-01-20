#pragma once
#include "MyMath.h"
class ViewProjection2D
{
public:
	Matrix3x3 viewMatrix_{};
	Matrix3x3 orthoMatrix_{};
	Matrix3x3 viewportMatrix_{};
	Matrix3x3 cameraWorldMatrix_{};
	Matrix3x3 screenMatrix_{};
	Matrix3x3 wvpVpMatrix_{};

	ViewProjection2D() = default;
	~ViewProjection2D() = default;

	void Initialize();
	void ViewProjectionUpdate();
private:
	// コピー禁止
	ViewProjection2D(const ViewProjection2D&) = delete;
	ViewProjection2D& operator=(const ViewProjection2D&) = delete;
};

