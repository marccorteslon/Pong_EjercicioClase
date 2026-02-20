#pragma once

#include "ofMain.h"
#include "Paddle.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
	private:
		Paddle* ply1 = nullptr;

		bool player1_up_hold = false;
		bool player1_down_hold = false;

		Paddle* ply2 = nullptr;

		bool player2_up_hold = false;
		bool player2_down_hold = false;

		Ball* ball = nullptr;
};
