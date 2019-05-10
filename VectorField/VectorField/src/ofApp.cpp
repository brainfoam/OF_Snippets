#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 0, 255);
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
	gui->addHeader("Controls");
	auto s1 = gui->addSlider("Spacing", 1, 30);
	auto s2 = gui->addSlider("Resolution", 40, 150);
	auto s3 = gui->addSlider("Length", 3, 20);
	auto s4 = gui->addSlider("Speed", .1f, 3.0f);
	auto s5 = gui->addSlider("Radius", 30, 200);
	gui->addFooter();
	s1->setValue(6);
	s2->setValue(122);
	s3->setValue(3);
	s4->setValue(.3f);
	s5->setValue(100);
}

//--------------------------------------------------------------
void ofApp::update(){
	spacing        = gui-> getSlider("Spacing")    -> getValue();
	resolution     = gui-> getSlider("Resolution") -> getValue();
	length         = gui-> getSlider("Length")     -> getValue();
	speed          = gui-> getSlider("Speed")      -> getValue();
	influence_area = gui-> getSlider("Radius")     -> getValue();
	mouse_pos = ofVec2f(ofGetMouseX(), ofGetMouseY());
}

//--------------------------------------------------------------
void ofApp::draw(){ 
	for (float y = 0; y < ofGetWindowHeight(); y += spacing) {
		for (float x = 0; x < ofGetWindowWidth(); x += spacing) {
			float counter = ofGetElapsedTimef() * speed;
			float noise = ofNoise((x / resolution) + counter, (y / resolution));
			float degree = noise * (2 * PI);
			float unit_x = cos(degree);
			float unit_y = sin(degree);
			ofVec2f unit_vector      = ofVec2f(unit_x, unit_y);
			ofVec2f start            = ofVec2f(x, y);
			ofVec2f influence_vector = ofVec2f(0.0f, 0.0f);
			float influence          = influence_area - start.distance(mouse_pos);
			float map = 0.0f;
			if (influence > 0.0f) {
				map = ofMap(influence, 0.0f, influence_area, 0.0f, 1.0f);
				influence_vector = mouse_pos - start;
			}
			ofVec2f final = (unit_vector + (influence_vector * map).normalize()) * length;
			float r = unit_x * 255;
			float g = noise  * 255;
			float b = unit_y * 255;
			ofSetColor(r, g, b);
			ofDrawLine(start, start + final);
			ofDrawCircle(start + final, length / 4);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
