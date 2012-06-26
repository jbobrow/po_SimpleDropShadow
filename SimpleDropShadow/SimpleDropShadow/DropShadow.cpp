#include "DropShadow.h"

DropShadow::DropShadow( poObject *src, float spread, float a )
{
	poPoint dimensions = src->getBounds().getSize();
	
	top_left = new poRectShape( spread, spread );
	top_center = new poRectShape( dimensions.x, spread );
	top_right = new poRectShape( spread, spread );
	center_left = new poRectShape( spread, dimensions.y );
	center_center = new poRectShape( dimensions.x, dimensions.y );
	center_right = new poRectShape( spread, dimensions.y );
	bottom_left = new poRectShape( spread, spread );
	bottom_center = new poRectShape( dimensions.x, spread );
	bottom_right = new poRectShape( spread, spread );
	
	poTexture* tex;
	
	tex = poGetTexture("dropShadowAssets/dropShadow_top_left.png");
	top_left->setAlignment( PO_ALIGN_BOTTOM_RIGHT );
	top_left->position = poPoint( 0.f, 0.f );
	top_left->placeTexture( tex, PO_TEX_FIT_EXACT);
	top_left->alpha = a;
	
	tex = poGetTexture("dropShadowAssets/dropShadow_top_center.png");
	top_center->setAlignment( PO_ALIGN_BOTTOM_LEFT );
	top_center->position = poPoint( 0.f, 0.f );
	top_center->placeTexture( tex, PO_TEX_FIT_EXACT);
	top_center->alpha = a;
	
	tex = poGetTexture("dropShadowAssets/dropShadow_top_right.png");
	top_right->setAlignment( PO_ALIGN_BOTTOM_LEFT );
	top_right->position = poPoint( dimensions.x, 0.f );
	top_right->placeTexture( tex, PO_TEX_FIT_EXACT);
	top_right->alpha = a;
	
	tex = poGetTexture("dropShadowAssets/dropShadow_center_left.png");
	center_left->setAlignment( PO_ALIGN_TOP_RIGHT );
	center_left->position = poPoint( 0.f, 0.f );
	center_left->placeTexture( tex, PO_TEX_FIT_EXACT);
	center_left->alpha = a;
	
	center_center->fillColor = poColor::black;
	center_center->setAlignment( PO_ALIGN_TOP_LEFT );
	center_center->position = poPoint( 0.f, 0.f );
	center_center->alpha = a;
	
	tex = poGetTexture("dropShadowAssets/dropShadow_center_right.png");
	center_right->setAlignment( PO_ALIGN_TOP_LEFT );
	center_right->position = poPoint( dimensions.x, 0.f );
	center_right->placeTexture( tex, PO_TEX_FIT_EXACT);
	center_right->alpha = a;
	
	tex = poGetTexture("dropShadowAssets/dropShadow_bottom_left.png");
	bottom_left->setAlignment( PO_ALIGN_TOP_RIGHT );
	bottom_left->position = poPoint( 0.f, dimensions.y );
	bottom_left->placeTexture( tex, PO_TEX_FIT_EXACT);
	bottom_left->alpha = a;
	
	tex = poGetTexture("dropShadowAssets/dropShadow_bottom_center.png");
	bottom_center->setAlignment( PO_ALIGN_TOP_LEFT );
	bottom_center->position = poPoint( 0.f, dimensions.y );
	bottom_center->placeTexture( tex, PO_TEX_FIT_EXACT);
	bottom_center->alpha = a;
	
	tex = poGetTexture("dropShadowAssets/dropShadow_bottom_right.png");
	bottom_right->setAlignment( PO_ALIGN_TOP_LEFT );
	bottom_right->position = poPoint( dimensions.x, dimensions.y );
	bottom_right->placeTexture( tex, PO_TEX_FIT_EXACT);
	bottom_right->alpha = a;
	
	addChild(top_left);
	addChild(top_center);
	addChild(top_right);
	addChild(center_left);
	addChild(center_center);
	addChild(center_right);
	addChild(bottom_left);
	addChild(bottom_center);
	addChild(bottom_right);
	
	addChild(src);
	
}

DropShadow::~DropShadow() 
{
}

void DropShadow::update() 
{
}

void DropShadow::eventHandler(poEvent *event)
{
}

void DropShadow::messageHandler(const std::string &msg, const poDictionary& dict) 
{
}

void DropShadow::setAlpha(float a){
	
	top_left->alpha = a;
	top_center->alpha = a;
	top_right->alpha = a;
	center_left->alpha = a;
	center_center->alpha = a;
	center_right->alpha = a;
	bottom_left->alpha = a;
	bottom_center->alpha = a;
	bottom_right->alpha = a;
}

void DropShadow::setSpread( poPoint dimensions, float spread){
	
	top_left->reshape( spread, spread );
	top_center->reshape( dimensions.x, spread );
	top_right->reshape( spread, spread );
	center_left->reshape( spread, dimensions.y );
	center_center->reshape( dimensions.x, dimensions.y );
	center_right->reshape( spread, dimensions.y );
	bottom_left->reshape( spread, spread );
	bottom_center->reshape( dimensions.x, spread );
	bottom_right->reshape( spread, spread );
	
}


FadeOut::FadeOut( poPoint dimensions, float spread, fadeOutOrientation orientation)
{
	
	center_center = new poRectShape( dimensions.x, dimensions.y );
	
	center_center->fillColor = poColor::black;
	center_center->setAlignment( PO_ALIGN_TOP_LEFT );
	center_center->position = poPoint( 0.f, 0.f );
	
	addChild(center_center);
	
	poTexture* tex;
	
	switch (orientation) {
		case PO_FADE_OUT_TOP:
			top_center = new poRectShape( dimensions.x, spread );
			tex = poGetTexture("dropShadowAssets/dropShadow_top_center.png");
			top_center->setAlignment( PO_ALIGN_BOTTOM_LEFT );
			top_center->position = poPoint( 0.f, 0.f );
			top_center->placeTexture( tex, PO_TEX_FIT_EXACT);
			addChild(top_center);
			break;
			
		case PO_FADE_OUT_RIGHT:
			center_right = new poRectShape( spread, dimensions.y );
			tex = poGetTexture("dropShadowAssets/dropShadow_center_right.png");
			center_right->setAlignment( PO_ALIGN_TOP_LEFT );
			center_right->position = poPoint( dimensions.x, 0.f );
			center_right->placeTexture( tex, PO_TEX_FIT_EXACT);
			addChild(center_right);
			break;
			
		case PO_FADE_OUT_BOTTOM:
			bottom_center = new poRectShape( dimensions.x, spread );
			tex = poGetTexture("dropShadowAssets/dropShadow_bottom_center.png");
			bottom_center->setAlignment( PO_ALIGN_TOP_LEFT );
			bottom_center->position = poPoint( 0.f, dimensions.y );
			bottom_center->placeTexture( tex, PO_TEX_FIT_EXACT);
			addChild(bottom_center);
			break;
			
		case PO_FADE_OUT_LEFT:
			center_left = new poRectShape( spread, dimensions.y );
			tex = poGetTexture("dropShadowAssets/dropShadow_center_left.png");
			center_left->setAlignment( PO_ALIGN_TOP_RIGHT );
			center_left->position = poPoint( 0.f, 0.f );
			center_left->placeTexture( tex, PO_TEX_FIT_EXACT);
			addChild(center_left);
			break;
			
		default:
			break;
	}
	
}

FadeOut::~FadeOut(){
	
}