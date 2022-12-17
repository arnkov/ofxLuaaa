#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//chose the standard lua libraries to use, if you need some
	luaopen_base(ls);
	//load your bindings
	bindings.bindToLua(ls);
	//load your script
	lua.runScript(ls, "test.lua");
	//call a lua function
	lua.fnSetup(ls);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//call another lua function
	lua.fnDraw(ls);
}

void ofApp::exit() {

	lua.fnExit(ls);

	lua.clearLua(ls);
	lua_close(ls);
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
