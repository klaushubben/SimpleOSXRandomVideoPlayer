#pragma once

#include "ofMain.h"
#include "ofxAVFVideoPlayer.h"
#include "ofxMouseAutoHider.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		  
    
    ofxAVFVideoPlayer player;
    
    int currentId;
    vector<ofFile> paths;
    bool hasLoaded;
    
     
};
