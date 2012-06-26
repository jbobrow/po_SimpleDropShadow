/////////////////////////////////////////
//
// pocode application configuration
//
/////////////////////////////////////////


#include "poApplication.h"
#include "SimpleDropShadowApp.h"

poObject *createObjectForID(uint uid) {
	return new SimpleDropShadowApp();
}

void setupApplication() {
	lookUpAndSetPath("resources");
	applicationCreateWindow(0, WINDOW_TYPE_NORMAL, "SimpleDropShadow", 100, 100, 600, 400);
}

void cleanupApplication() {
}