#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 0);
}

bool record = false;
int frame = 0;

//--------------------------------------------------------------
void ofApp::update(){
	if (record) {
		ofSaveScreen(ofToString(ofGetFrameNum()) + ".png");
	}
	frame++;
}

//--------------------------------------------------------------
const float pi      = 3.1415927;
int elements        = 300;
float dist          = 200.0f;
float freq          = .005f;
float amp           = 60.0f;
float radius        = 10;
float offset        = 0.0f;
float wireframe     = false;
float influenceAmp  = 10.0f;
float influenceFreq = .005;

void ofApp::draw(){
	offset += ofGetLastFrameTime() / 10.0f;
	glm::vec3 center(ofGetViewportWidth() / 2.0f, ofGetViewportHeight() / 2.0f, 0.0f);
	
	for (float i = 0.0f; i < pi * 2; i += (2 * pi) / elements) {
		float currentDist = dist + sin(ofGetElapsedTimeMillis() * freq + i + offset) * amp;
		float currentX = center.x + sin(i + offset) * currentDist;
		float currentY = center.y + cos(i - offset) * currentDist;
		float currentR = radius + pow((currentDist / 10), 2.2f) / 60;

		currentY += sin(ofGetElapsedTimeMillis() * influenceFreq + i + (offset * .2)) * influenceAmp;

		float r = ofMap(currentX, 0, ofGetViewportWidth(), 0, 255, true);
		float g = ofMap(currentY, 0, ofGetViewportWidth(), 0, 255, true);
		float b = 255;
		ofSetColor(r, b, g);
		if (wireframe)
			ofNoFill();
		else
			ofFill();
		ofDrawCircle(currentX, currentY, currentR);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_UP) {
		elements += 10;
	}
	else if (key == OF_KEY_DOWN) {
		elements -= 10;
	}

	elements = ofMap(elements, 0, 300, 0, 300, true);

	if (key == OF_KEY_LEFT) {
		wireframe = !wireframe;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
