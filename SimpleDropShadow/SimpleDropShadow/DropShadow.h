#pragma once

/*	Created by Jonathan Bobrow on 7/27/11.
 *	Copyright 2011 Potion. All rights reserved.
 *
 *
 *	poDropShadow employs a 9 space grid to create a dynamically sized
 *	rectangular drop shadow.  Circles can also use this method, but the
 *	dimensions should be set to poPoint(0,0,0).
 *	
 *	currently uses loaded pngs for textures
 */

#include "poObject.h"
#include "poShapeBasics2D.h"

#define PATH_TO_DROP_SHADOW_TEXTURES "dropShadowAssets/"

class DropShadow : public poObject
{
public:
	DropShadow( poObject *src, float spread = 30.f, float a = .5f);
	virtual ~DropShadow();
	
	virtual void update();
	virtual void eventHandler(poEvent *event);
	virtual void messageHandler(const std::string &msg, const poDictionary& dict=poDictionary());
	
	void setAlpha( float a );
	void setSpread( float spread );
	poTexture* getTextureClamped( std::string s );
	
	poRectShape* top_left;
	poRectShape* top_center;
	poRectShape* top_right;
	poRectShape* center_left;
	poRectShape* center_center;
	poRectShape* center_right;
	poRectShape* bottom_left;
	poRectShape* bottom_center;
	poRectShape* bottom_right;
	
	poPoint dimensions;
};


#pragma mark FADE OUT
// ex. Give the appearance of text fading out when scrolling to edges

enum fadeOutOrientation{
	PO_FADE_OUT_TOP = 0,
	PO_FADE_OUT_RIGHT = 1,
	PO_FADE_OUT_BOTTOM = 2,
	PO_FADE_OUT_LEFT = 3
};

class FadeOut : public poShape2D{
public:
	FadeOut( poPoint dimensions, float spread, fadeOutOrientation orientation );
	virtual ~FadeOut();
	
	
	poRectShape* top_center;
	poRectShape* center_left;
	poRectShape* center_center;
	poRectShape* center_right;
	poRectShape* bottom_center;
	
	poPoint* dimensions;
};