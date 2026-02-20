#pragma once
#include "ofMain.h"
#include "includes.h"

class Paddle {
	public:
		Paddle();	//Constructor
		~Paddle();	//Destructor

		void Init(int x, int y, int w, int h);
		void Render();

		void Move(float delta_y);
		void SetLimits(C_Rectangle limits);

		C_Rectangle GetRectangle() { return paddleBody; };

	private:
		void ConstrainToLimits();

		C_Rectangle paddleBody;
		ofColor paddleColor;
		C_Rectangle fieldLimits;

		static int numPaddles;

		float speedY;
};