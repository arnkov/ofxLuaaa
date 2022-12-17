#include "ofxLuaaa.h"

ofxLuaaa::ofxLuaaa(){}

ofxLuaaa::~ofxLuaaa() {
	clearLua();
	lua_close(L);
}


void ofxLuaaa::runScript(lua_State* ls, const std::string& script) {
	if (ls != NULL) {
		std::string scriptPath = ofFilePath::getAbsolutePath(ofToDataPath(script));
		int luaFile = luaL_loadfile(ls, scriptPath.c_str());
		luaFile = lua_pcall(ls, 0, LUA_MULTRET, 0);
	}
	else {
		ofLog() << "Lua is not initialized";
	}
}

void ofxLuaaa::fnSetup(lua_State* ls) {
	if (ls == NULL) { return; }
	lua_getglobal(ls, "setup");
	if (lua_pcall(ls, 0, 0, 0) != 0) {
		ofLog() << "error running update function";
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
	lua_gc(ls, LUA_GCCOLLECT, 0);
	if (lua_pcall(ls, 0, 0, 0) != 0) {
		ofLog() << "error running exit function";
	}
}

void ofxLuaaa::clearLua(lua_State* ls) {
	if (L != NULL) {
		L = NULL;
		lua_gc(ls, LUA_GCCOLLECT, 0);
	}
}
