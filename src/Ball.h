#pragma once
#include "Paddle.h"

class Ball {
	public:
		Ball();		//Constructor
		~Ball();	//Destructor

		void Init(int x, int y, int w, int h);
		void Render();

		void Update(float delta_time);
		void SetLimits(C_Rectangle limits);

		void CheckCollisionWithPaddle(Paddle* paddle);

	private:
		void ConstrainToLimits();

		C_Rectangle ballBody;
		ofColor ballColor;
		C_Rectangle fieldLimits;

		float speedY;
		float speedX;
		float initialSpeedX;
};