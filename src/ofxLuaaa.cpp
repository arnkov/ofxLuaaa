#include "ofxLuaaa.h"

ofxLuaaa::ofxLuaaa(){}

ofxLuaaa::~ofxLuaaa() {}


void ofxLuaaa::runScript(lua_State* ls, std::string& script) {
	if (ls != NULL) {
		clearLua(ls);
		//std::string text = ofBufferFromFile(script);
		//luaL_dostring(ls, text.c_str());
		std::string scriptPath = ofFilePath::getAbsolutePath(ofToDataPath(script));
		int luaFile = luaL_loadfile(ls, scriptPath.c_str());
		luaFile = lua_pcall(ls, 0, LUA_MULTRET, 0);
		ofLog() << "loaded Script " + script;
	}
	else {
		ofLog() << "Lua is not initialized";
	}
}

void ofxLuaaa::fnSetup(lua_State* ls) {
	if (ls == NULL) { return; }
	lua_getglobal(ls, "setup");
	if (lua_pcall(ls, 0, 0, 0) != 0) {
		ofLog() << "error running setup function";
	}
}

void ofxLuaaa::fnUpdate(lua_State* ls) {
	if (ls == NULL) {return;}
	lua_getglobal(ls, "update");
	if (lua_pcall(ls, 0, 0, 0) != 0) {
		ofLog() << "error running update function";
	}
}

void ofxLuaaa::fnDraw(lua_State* ls) {
	if (ls == NULL) {return;}
	lua_getglobal(ls, "draw");
	if (lua_pcall(ls, 0, 0, 0) != 0) {
		ofLog() << "error running draw function";
	}
}

void ofxLuaaa::fnExit(lua_State* ls) {
	if (ls == NULL) {return;}
	lua_getglobal(ls, "exit");
	if (lua_pcall(ls, 0, 0, 0) != 0) {
		ofLog() << "error running exit function";
	}
}

void ofxLuaaa::clearLua(lua_State* ls) {
	if (ls != NULL) {
		lua_settop(ls, 0);
		lua_gc(ls, LUA_GCCOLLECT, 0);
	}
}

void ofxLuaaa::setBool(lua_State* ls, string var, bool val) {
	if (ls != NULL) {
		lua_pushglobaltable(ls);
		lua_pushboolean(ls, val);
		lua_setfield(ls, -2, var.c_str());
		lua_pop(ls, 1);
	}
}

void ofxLuaaa::setNumber(lua_State* ls, string var, float val) {
	if (ls != NULL) {
		lua_pushglobaltable(ls);
		lua_pushnumber(ls, val);
		lua_setfield(ls, -2, var.c_str());
		lua_pop(ls, 1);
	}
}

