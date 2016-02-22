#include "ofApp.h"

void ofApp::setup(){
	videoPlayer = new ofVideoPlayer();
	videoPlayer->load("video-a.mp4");
	videoPlayer->setLoopState(OF_LOOP_NONE);
	videoPlayer->play();
}

void ofApp::update(){
	videoPlayer->update();
	
	if(videoPlayer->getIsMovieDone()){
		string currentMoviePath = videoPlayer->getMoviePath();
		videoPlayer->close();
		delete videoPlayer;
		videoPlayer = new ofVideoPlayer();
		
		if(currentMoviePath == "video-a.mp4"){
			videoPlayer->load("video-b.mp4");
		}else{
			videoPlayer->load("video-a.mp4");
		}
		
		videoPlayer->setLoopState(OF_LOOP_NONE);
		videoPlayer->play();
	}
}

void ofApp::draw(){
	if(videoPlayer->isLoaded() && videoPlayer->isPlaying()){
		videoPlayer->draw(0, 0, ofGetWidth(), ofGetHeight());
	}else{
		ofPushStyle();
		ofSetHexColor(0xff0000);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		ofPopStyle();
	}
}
