#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ply1 = new Paddle();
	ply1->Init(20, 100, 50, 200);
	ply1->SetLimits(C_Rectangle{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });

	ply2 = new Paddle();
	ply2->Init(SCREEN_WIDTH -70, 100, 50, 200);
	ply2->SetLimits(C_Rectangle{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });

	ball = new Ball();
	ball->Init(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 50, 50);
	ball->SetLimits(C_Rectangle{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });

}

//--------------------------------------------------------------
void ofApp::update(){
	float delta_time = ofGetLastFrameTime();

	int delta_ply1 = 0;
	if (player1_up_hold) {
		delta_ply1 = 0;
	}
	else if (player1_down_hold) {
		delta_ply1 = 1;
	}
	if (delta_ply1 != 0) {
		ply1->Move(delta_ply1 * delta_time);
	}

	int delta_ply2 = 0;
	if (player2_up_hold) {
		delta_ply2 = 0;
	}
	else if (player2_down_hold) {
		delta_ply2 = 1;
	}
	if (delta_ply2 != 0) {
		ply2->Move(delta_ply2 * delta_time);
	}

	ball->CheckCollisionWithPaddle(ply1);
	ball->CheckCollisionWithPaddle(ply2);
	ball->Update(delta_time);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ply1->Render();
	ply2->Render();
	ball->Render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	// Player1
	
	if (key == 119 || key == 87) {
		player1_up_hold = true;
		player1_down_hold = false;
	}
	if (key == 115 || key == 83) {
		player1_up_hold = false;
		player1_down_hold = true;
	}

	// Player2

	if (key == 57357) {
		player2_up_hold = true;
		player2_down_hold = false;
	}
	if (key == 57359) {
		player2_up_hold = false;
		player2_down_hold = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	// Player1
	
	if (key == 119 || key == 87) {
		player1_up_hold = false;
	}
	if (key == 115 || key == 83) {
		player1_down_hold = false;
	}

	// Player2

	if (key == 57357) {
		player2_up_hold = false;
	}
	if (key == 57359) {
		player2_down_hold = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
