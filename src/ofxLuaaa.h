#pragma once

#include "ofMain.h"
#include "luaaa.hpp"

class ofxLuaaa {

public:

	ofxLuaaa();
	virtual ~ofxLuaaa();

	void runScript(lua_State* ls, std::string& script);
	void fnSetup(lua_State* ls);
	void fnUpdate(lua_State* ls);
	void fnDraw(lua_State* ls);
	void fnExit(lua_State* ls);
	void clearLua(lua_State* ls);

	void setBool(lua_State* ls, string var, bool val);
	void setNumber(lua_State* ls, string var, float val);
};