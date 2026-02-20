#include "Ball.h"
#include "Utils.h"

Ball::Ball() {
	ballBody = C_Rectangle { 0, 0, 0, 0 };
	fieldLimits = C_Rectangle{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	ballColor = ofColor::white;
	speedY = 500.0f;
	speedX = 500.0f;
}

Ball::~Ball() {

}

void Ball::Init(int x, int y, int w, int h) {
	ballBody.x = x;
	ballBody.y = y;
	ballBody.w = w;
	ballBody.h = h;

}
void Ball::Render() {
	ofSetColor(ballColor);
	ofDrawRectangle(ballBody.x, ballBody.y, ballBody.w, ballBody.h);
}

void Ball::Update(float delta_y) {
	ballBody.x = ballBody.x + speedX * delta_y;
	ballBody.y = ballBody.y + speedY * delta_y;
}

void Ball::CheckCollisionWithPaddle(Paddle* paddle) {
	if (paddle == nullptr) {
		return;
	}
	C_Rectangle paddleRect = paddle->GetRectangle();
	if (C_RectangleCollision(ballBody, paddleRect)) {
		if (ballBody.x < paddleRect.x) {
			ballBody.x = paddleRect.x - ballBody.w - 1;
		}
		else if (ballBody.x > paddleRect.x) {
			ballBody.x = paddleRect.x + ballBody.w + 1;
		}
		speedX = -speedX;
	}
}

void Ball::SetLimits(C_Rectangle limits) {
	fieldLimits = limits;
}

void Ball::ConstrainToLimits() {
	if (ballBody.x < fieldLimits.x) {
		//ballBody.x = fieldLimits.x;
		ballBody.x = SCREEN_WIDTH / 2 - ballBody.w / 2;
		speedX = -speedX;
	}
	if (ballBody.y < fieldLimits.y) {
		ballBody.y = fieldLimits.y;
		speedY = -speedY;
	}

	if (ballBody.x + ballBody.w >= fieldLimits.x + fieldLimits.w) {
		//ballBody.x = fieldLimits.x + fieldLimits.w - ballBody.w;
		ballBody.x = SCREEN_WIDTH / 2 - ballBody.w / 2;
		speedX = -speedX;
	}
	if (ballBody.y + ballBody.h >= fieldLimits.y + fieldLimits.h) {
		ballBody.y = fieldLimits.y + fieldLimits.h - ballBody.h;
		speedY = -speedY;
	}
}
