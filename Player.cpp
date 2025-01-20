#include "Player.h"
#include <Novice.h>
#include "PlayerBullet.h"
#include <cmath>

Player::~Player()
{
}

void Player::Initialize(int texture, const Vector2& position)
{
	SetName(PLAYER);
	gh_ = texture;
	SetRadius(32.0f);
	worldTransform_.Initialize(radius_,{1,1},0, position);

	SetCollisionAttribute(kCollisionAttributePlayer);
	//
	SetCollisionMask(GetCollisionMask() - kCollisionAttributePlayer);
}

void Player::Update()
{
	Novice::GetMousePosition(&mouseX, &mouseY);
	mouse = { float(mouseX) - 640,float(mouseY) - 360};

	//playerBullet_->SetTheta(playerBullet_->GetTheta() - atan2f(mouse.y - GetWorldPosition().y, mouse.x - GetWorldPosition().x) * MyMath::GetPI() / 180);
	worldTransform_.rotation_ = atan2f(-(mouse.y + GetWorldPosition().y), mouse.x - GetWorldPosition().x);

	Vector2 velocity = {
		cosf(worldTransform_.rotation_) * playerBullet_->GetLength(),
		sinf(worldTransform_.rotation_) * playerBullet_->GetLength()
	};
	playerBullet_->SetVelocity(velocity);
	
	Move();
	Attack();

	worldTransform_.TransferMatrix();
}

void Player::Draw(ViewProjection2D& viewProjection)
{
	Matrix3x3 wvpVpMatrix = MyMath::Multiply(worldTransform_.matWorld_, viewProjection.wvpVpMatrix_);
	worldTransform_.screen_ = MyMath::MakeScreenVertex(worldTransform_.local_, wvpVpMatrix);
	MyMath::DrawSprite(worldTransform_.screen_, 64, 64, gh_, 0xffffffff);
	
}

void Player::OnCollision(ColliderName name)
{
	if (name == PLAYER) {

	}
	hp_--;
	if (hp_ <= 0) {
		isDead_ = true;
	}
}

void Player::Move()
{
	const float kMoveSpeed = 3.0f;

	if (inputManager->GetKeys()[DIK_A]) {
		worldTransform_.translation_.x += -kMoveSpeed;
	}
	else if (inputManager->GetKeys()[DIK_D]) {
		worldTransform_.translation_.x += kMoveSpeed;
	}
	if (inputManager->GetKeys()[DIK_W]) {
		worldTransform_.translation_.y += kMoveSpeed;
	}
	else if (inputManager->GetKeys()[DIK_S]) {
		worldTransform_.translation_.y += -kMoveSpeed;
	}
	worldTransform_.TransferMatrix();
	playerBullet_->SetWorldPosition(GetWorldPosition());
}

void Player::Attack()
{
	float kBulletSpeed = 10;
	Vector2 playerBulletPos = playerBullet_->GetWorldPosition();
	float playerBulletLength = playerBullet_->GetLength();
	playerBulletLength = playerBulletLength - kBulletSpeed;
	if (playerBulletLength <= 0) {
		playerBulletLength = 0;
	}
	playerBullet_->SetLength(playerBulletLength);
	if (Novice::IsPressMouse(0)) {
		playerBulletPos = playerBullet_->GetWorldPosition();
		playerBulletLength = playerBullet_->GetLength();
		playerBulletLength = playerBulletLength + kBulletSpeed * 2;
		playerBullet_->SetLength(playerBulletLength);
	}
	if (playerBulletLength < 100) {
		IsShield_ = true;
	}
	else {
		IsShield_ = false;
	}
}

Vector2 Player::GetWorldPosition()
{
	worldTransform_.TransferMatrix();
	Vector2 worldPos;
	worldPos.x = worldTransform_.matWorld_.m[2][0];
	worldPos.y = worldTransform_.matWorld_.m[2][1];
	return worldPos;
}
