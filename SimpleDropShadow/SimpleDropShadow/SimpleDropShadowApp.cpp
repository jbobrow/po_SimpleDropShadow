/*	Created by Jonathan Bobrow on 6/26/12.
 *	Copyright 2012 __MyCompanyName__. All rights reserved.
 */

#include "SimpleDropShadowApp.h"
#include "poApplication.h"
#include "poCamera.h"


// APP CONSTRUCTOR. Create all objects here.
SimpleDropShadowApp::SimpleDropShadowApp() {
	addModifier(new poCamera2D(poColor(.2f,.2f,.23f)));
	
	// load source image
	image = new poRectShape("ghostly.jpg");
	image->generateStroke(10.f).strokeColor = poColor::white;
	
	// send source image to new drop shadow
	imageAndShadow = new DropShadow(image);
	
	// set position of image and drop shadow
	imageAndShadow->position.set(70,50,0);
	
	// scale and rotate image and drop shadow...
	imageAndShadow->scaleTween
		.set(poPoint(.95f,.95f,0.f))
		.setDuration(2.f)
		.setTweenFunction(PO_TWEEN_SINUS_INOUT_FUNC)
		.setRepeat(PO_TWEEN_REPEAT_PINGPONG)
		.start();
	imageAndShadow->rotationTween
		.set(5.f)
		.setDuration(2.f)
		.setTweenFunction(PO_TWEEN_SINUS_INOUT_FUNC)
		.setRepeat(PO_TWEEN_REPEAT_PINGPONG)
		.start();
	
	// add image and drop shadow to screen
	addChild(imageAndShadow);
	
	// add control panel for drop shadow
	control = new poControlPanel( "controlPanel", poColor(0,0.3,0.3,0.6) );
	control->addSliderF( "amplitude",0.f, 100.f, this );
	control->addSliderF( "alpha",0.f, 1.f, this );
	control->addPointSlider( "offset", poPoint(-25,-25), poPoint(25,25), this );
	addChild(control);
}

// APP DESTRUCTOR. Delete all objects here.
SimpleDropShadowApp::~SimpleDropShadowApp() {
}

// UPDATE. Called once per frame. Animate objects here.
void SimpleDropShadowApp::update() {
	
}

// DRAW. Called once per frame. Draw objects here.
void SimpleDropShadowApp::draw() {
	
}

// EVENT HANDLER. Called when events happen. Respond to events here.
void SimpleDropShadowApp::eventHandler(poEvent *event) {
	
}

// MESSAGE HANDLER. Called from within the app. Use for message passing.
void SimpleDropShadowApp::messageHandler(const std::string &msg, const poDictionary& dict) {
	if ( msg == "amplitude" ) {
        imageAndShadow->setSpread(control->getFloat("amplitude"));
    }
	
	if ( msg == "alpha" ) {
        imageAndShadow->setAlpha(control->getFloat("alpha"));
    }
	
	if ( msg == "offset" ) {
		imageAndShadow->setShadowOffset(control->getPoint("offset"));
	}
}
