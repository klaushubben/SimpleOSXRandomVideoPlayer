#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    ofDirectory dir;
    dir.listDir(ofFilePath::getUserHomeDir() + "/Desktop/movies/" );
    paths = dir.getFiles();
    
    for( int i = 0; i < paths.size(); ++i){
        cout << i << " : " << paths[i].getAbsolutePath() << endl;
    }
    
    // load first movie
    currentId = 3;
    
    player.loadMovie( paths[currentId].getAbsolutePath() );
    hasLoaded = false;
    
    
    ofToggleFullscreen();
    ofxMouseAutoHider::enable(2);

}

//--------------------------------------------------------------
void ofApp::update(){
    
     player.update();
    
    if( player.isLoaded() && !player.isPlaying()  ){
        player.play();
        player.setLoopState ( OF_LOOP_NONE );
        hasLoaded = true;
    }
    
    if( player.getIsMovieDone() ){
        
        int newId = (int)ofRandom( paths.size() );
        if( newId == currentId ){
            while( newId == currentId ){
                newId = (int)ofRandom( paths.size() );
            }
        }
        
        player.loadMovie( paths[currentId].getAbsolutePath() );
        currentId = newId;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    player.draw(0,0,ofGetWidth(),ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    switch( key ){
            case 'f':
            case ' ':
                ofToggleFullscreen();
            
            if(  ofGetWindowMode() == OF_FULLSCREEN){
                ofxMouseAutoHider::enable();
            } else {
                ofxMouseAutoHider::disable();
            }
            
            break;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
