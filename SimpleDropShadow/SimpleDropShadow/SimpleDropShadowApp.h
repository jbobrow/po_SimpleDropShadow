/*	Created by Jonathan Bobrow on 6/26/12.
 *	Copyright 2012 __MyCompanyName__. All rights reserved.
 */

#include "poObject.h"
#include "poShapeBasics2D.h"
#include "DropShadow.h"

class SimpleDropShadowApp : public poObject {
public:
	SimpleDropShadowApp();
	virtual ~SimpleDropShadowApp();
	
    virtual void update();
    
    virtual void draw();
	
    virtual void eventHandler(poEvent *event);
	
    virtual void messageHandler(const std::string &msg, const poDictionary& dict=poDictionary());
	
	DropShadow	*imageAndShadow;
	poRectShape	*image;
};

