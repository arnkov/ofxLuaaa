#pragma once

#include "ofMain.h"
#include "ofxLuaaa.h"

//This is important, especially for gcc
using namespace luaaa;

class luaBindings {
public:

	luaBindings() {};
	virtual ~luaBindings() {};

	void awesomeFunction(int resolution) {

		ofSetCircleResolution(resolution);
		ofDrawCircle(ofGetWidth() * .5, ofGetHeight() * .5, ofGetHeight() * .25);

	}

	void bindToLua(lua_State* state) {

		LuaClass<luaBindings> bindings(state, "draw");
		bindings.ctor();
		bindings.fun("awesomeFunction", &luaBindings::awesomeFunction);

	}
};