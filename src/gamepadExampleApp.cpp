#include "gamepadExampleApp.h"

int axis=0;

//--------------------------------------------------------------
void gamepadExampleApp::setup(){
	ofSetWindowTitle("gamepadExampleApp");
	ofBackground(0,0,0);

	ofSetFrameRate(120);
	ofSetLogLevel(OF_LOG_VERBOSE);
	vidPlayer.loadMovie("fingers.mov");
    vidPlayer.play();
    colorImg.allocate(320,240);

	ofxGamepadHandler::get()->enableHotplug();

	//CHECK IF THERE EVEN IS A GAMEPAD CONNECTED
	if(ofxGamepadHandler::get()->getNumPads()>0){
			ofxGamepad* pad = ofxGamepadHandler::get()->getGamepad(0);
			ofAddListener(pad->onAxisChanged, this, &gamepadExampleApp::axisChanged);
			ofAddListener(pad->onButtonPressed, this, &gamepadExampleApp::buttonPressed);
			ofAddListener(pad->onButtonReleased, this, &gamepadExampleApp::buttonReleased);
	}
}

//--------------------------------------------------------------
void gamepadExampleApp::update(){
	bool bNewFrame = false;
	float x=ofRandom(-1,1);
	axis=(int)ofMap(x,-1,1,0,200);
	vidPlayer.update();
	bNewFrame = vidPlayer.isFrameNew();
    //cout << "Mapped Axis" << axis;
	if (bNewFrame){

		colorImg.setFromPixels(vidPlayer.getPixels(), 320,240);
		colorImg.setROI(axis,0,axis+100,240);

    }


}

//--------------------------------------------------------------
void gamepadExampleApp::draw(){
	ofxGamepadHandler::get()->draw(10,10);
	ofSetColor(255,0,0);
	ofRect(axis,500,30,30);

	colorImg.drawROI(200,200);
}

//--------------------------------------------------------------

void gamepadExampleApp::axisChanged(ofxGamepadAxisEvent& e)
{
	cout << "AXIS " << e.axis << " VALUE " << ofToString(e.value) << endl;
	axis=e.axis;
}

void gamepadExampleApp::buttonPressed(ofxGamepadButtonEvent& e)
{
	cout << "BUTTON " << e.button << " PRESSED" << endl;
}

void gamepadExampleApp::buttonReleased(ofxGamepadButtonEvent& e)
{
	cout << "BUTTON " << e.button << " RELEASED" << endl;
}

//--------------------------------------------------------------
void gamepadExampleApp::keyPressed(int key){

}

//--------------------------------------------------------------
void gamepadExampleApp::keyReleased(int key){

}

//--------------------------------------------------------------
void gamepadExampleApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void gamepadExampleApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void gamepadExampleApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void gamepadExampleApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void gamepadExampleApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void gamepadExampleApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void gamepadExampleApp::dragEvent(ofDragInfo dragInfo){

}



