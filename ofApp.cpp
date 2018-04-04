#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.5);

	int length = 250;
	int span = 10;
	for (int x = -length / 2 + span / 2; x <= length / 2 - span / 2; x += span) {

		for (int y = -length / 2 + span / 2; y <= length / 2 - span / 2; y += span) {

			for (int z = -length / 2 + span / 2; z <= length / 2 - span / 2; z += span) {

				this->draw_box(ofPoint(x, y, z), span);
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::draw_box(ofPoint point, float length) {

	for (int x = point.x - length / 2; x < point.x + length / 2; x += 1) {

		int y_1 = point.y - length / 2;
		int y_2 = point.y + length / 2;
		int z_1 = point.z - length / 2;
		int z_2 = point.z + length / 2;

		this->draw_line(ofPoint(x, y_1, z_1), ofPoint(x + 1, y_1, z_1));
		this->draw_line(ofPoint(x, y_1, z_2), ofPoint(x + 1, y_1, z_2));
		this->draw_line(ofPoint(x, y_2, z_1), ofPoint(x + 1, y_2, z_1));
		this->draw_line(ofPoint(x, y_2, z_2), ofPoint(x + 1, y_2, z_2));
	}

	for (int y = point.y - length / 2; y < point.y + length / 2; y += 1) {

		int x_1 = point.x - length / 2;
		int x_2 = point.x + length / 2;
		int z_1 = point.z - length / 2;
		int z_2 = point.z + length / 2;

		this->draw_line(ofPoint(x_1, y, z_1), ofPoint(x_1, y + 1, z_1));
		this->draw_line(ofPoint(x_1, y, z_2), ofPoint(x_1, y + 1, z_2));
		this->draw_line(ofPoint(x_2, y, z_1), ofPoint(x_2, y + 1, z_1));
		this->draw_line(ofPoint(x_2, y, z_2), ofPoint(x_2, y + 1, z_2));
	}

	for (int z = point.z - length / 2; z < point.z + length / 2; z += 1) {

		int x_1 = point.x - length / 2;
		int x_2 = point.x + length / 2;
		int y_1 = point.y - length / 2;
		int y_2 = point.y + length / 2;

		this->draw_line(ofPoint(x_1, y_1, z), ofPoint(x_1, y_1, z + 1));
		this->draw_line(ofPoint(x_1, y_2, z), ofPoint(x_1, y_2, z + 1));
		this->draw_line(ofPoint(x_2, y_1, z), ofPoint(x_2, y_1, z + 1));
		this->draw_line(ofPoint(x_2, y_2, z), ofPoint(x_2, y_2, z + 1));
	}
}

//--------------------------------------------------------------
void ofApp::draw_line(ofPoint p_1, ofPoint p_2) {

	float noise_value = ofNoise(p_1.x * 0.005, p_1.y * 0.005 + ofGetFrameNum() * 0.025, p_1.z * 0.005);
	if (noise_value > 0.5) {
	
		ofSetColor(239, ofMap(noise_value, 0, 1, 0, 255));
		ofDrawLine(p_1, p_2);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}