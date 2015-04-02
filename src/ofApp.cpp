#include "ofApp.h"

/*
 Jinnie Templin
 Advanced Coding - Seaweed Quiz - APRIL 2015
 */

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(5); //slow down the frame rate so the seaweed doesn't move too quickly

}

//--------------------------------------------------------------
void ofApp::update(){
    //update each of the vertex points on the curve - some move, some are constant -- this could be rewritten so that the constants are located in the setup and only the movement variables need to be updated in this function
    seaweed.curveTo(ofGetWindowWidth()/2, ofGetWindowHeight());
    seaweed.curveTo(ofGetWindowWidth()/2, ofGetWindowHeight());  // this duplicate point is necessary for control
    seaweed.curveTo(ofGetWindowWidth()/2, ofGetWindowHeight()-150);
    seaweed.curveTo(ofMap(cos(p1x),-1, 1, ofGetWindowWidth()/2-20, ofGetWindowWidth()/2+20), ofGetWindowHeight()-400);
    seaweed.curveTo(ofGetWindowWidth()/2, ofGetWindowHeight()-550);
    seaweed.curveTo(ofMap(cos(p1x), -1, 1, ofGetWindowWidth()/2-40, ofGetWindowWidth()/2+40), 75);
    seaweed.curveTo(ofMap(cos(topX), -1, 1, ofGetWindowWidth()/2-40, ofGetWindowWidth()/2+40), 75);  // this duplicate point is necessary for control

    
    p1x++;
    topX++;

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 242, 255);
    
    //draw the seaweed stem
    ofColor green(0, 255, 82);
    ofSetColor(green);
    ofSetLineWidth(3);
    seaweed.draw();
    
    //draw the seaweed leaves
    ofSetLineWidth(1);
    float numPoints = seaweed.size();
    float normalLength = 100;
    
    for (int p=0; p<100; p+=2) {
        ofVec3f point = seaweed.getPointAtPercent(p/100.0);
        float floatIndex = p/100.0 * (numPoints-1);
        //set the length of the seaweed leaves to be dependent upon the normal point's y position
        normalLength = ofMap(point.y, 0, ofGetWindowHeight(), 10, 100);
        ofVec3f normal = seaweed.getNormalAtIndexInterpolated(floatIndex) * normalLength;
        //make the seaweed leaf color brightness dependent upon the length of the the seaweed leaf
        green.setBrightness(ofMap(normalLength, 10, 100, 250, 150));
        ofSetColor(green);
        ofLine(point-normal/2, point+normal/2);
    }

    //clear the seaweed polyline so we have a draw a fresh polyline next frame
    seaweed.clear();
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
