#include "Paddle.h"

int Paddle::numPaddles = 0;

Paddle::Paddle() {
	numPaddles++;
	paddleBody = C_Rectangle { 0, 0, 0, 0 };
	fieldLimits = C_Rectangle{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	paddleColor = ofColor::white;
	speedY = 500.0f;
}

Paddle::~Paddle() {

}

void Paddle::Init(int x, int y, int w, int h) {
	paddleBody.x = x;
	paddleBody.y = y;
	paddleBody.w = w;
	paddleBody.h = h;

}
void Paddle::Render() {
	ofSetColor(paddleColor);
	ofDrawRectangle(paddleBody.x, paddleBody.y, paddleBody.w, paddleBody.h);
}

void Paddle::Move(float delta_y) {
	paddleBody.y = paddleBody.y + speedY * delta_y;
}

void Paddle::SetLimits(C_Rectangle limits) {
	fieldLimits = limits;
}

void Paddle::ConstrainToLimits() {
	if (paddleBody.x < fieldLimits.x) {
		paddleBody.x = fieldLimits.x;
	}
	if (paddleBody.y < fieldLimits.y) {
		paddleBody.y = fieldLimits.y;
	}

	if (paddleBody.x + paddleBody.w >= fieldLimits.x + fieldLimits.w) {
		paddleBody.x = fieldLimits.x + fieldLimits.w - paddleBody.w;
	}
	if (paddleBody.y + paddleBody.h >= fieldLimits.y + fieldLimits.h) {
		paddleBody.y = fieldLimits.y + fieldLimits.h - paddleBody.h;
	}
}
