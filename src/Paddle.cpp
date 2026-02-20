#include "Paddle.h"

Paddle::Paddle() {
	paddleColor = ofColor::white;
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
	C_Rectangle(paddleBody.x, paddleBody.y, paddleBody.w, paddleBody.h);
}