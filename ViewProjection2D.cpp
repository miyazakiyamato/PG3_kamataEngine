#include "ViewProjection2D.h"
void ViewProjection2D::Initialize()
{
	cameraWorldMatrix_ = {
		1,0,0,
		0,1,0,
		0,0,1
	};
	screenMatrix_ = {
		1,0,0,
		0,-1,0,
		640,360,1
	};
}
void ViewProjection2D::ViewProjectionUpdate()
{
	viewMatrix_ = MyMath::InverseMatrix(cameraWorldMatrix_);
	orthoMatrix_ = MyMath::MakeOrthographicMatrix(0, 0, 1280, 720);
	viewportMatrix_ = MyMath::MakeViewportMatrix(0, 0, 1280, 720);

	wvpVpMatrix_ = MyMath::Multiply(viewMatrix_, orthoMatrix_);
	wvpVpMatrix_ = MyMath::Multiply(wvpVpMatrix_, viewportMatrix_);
	wvpVpMatrix_ = MyMath::Multiply(wvpVpMatrix_, screenMatrix_);
}