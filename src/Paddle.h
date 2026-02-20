#pragma once
#include "ofMain.h"
#include "includes.h"

class Paddle {
	public:
		Paddle();	//Constructor
		~Paddle();	//Destructor

		void Init(int x, int y, int w, int h);
		void Render();

		//void Move
		//void SetLimits

	private:
		C_Rectangle paddleBody;
		ofColor paddleColor;
};