#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

#define PI 3.14159265358979323846
#define WINDOW_WIDTH  650
#define WINDOW_HEIGHT 650

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
		
		ofxDatGui* gui;
		ofVec2f mouse_pos;

		float spacing;
		float length;
		float resolution;
		float speed;
		float influence_area;
};
