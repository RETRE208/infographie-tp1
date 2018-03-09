#include "Rectangle.h"
using namespace tp1;

Rectangle::Rectangle() {
	x = 100;
	y = 100;
	height = 100;
	width = 100;
	color = ofColor::red;
}

bool Rectangle::inside(ofPoint mouse)
{
	return mouse.distance(ofPoint(x, y)) <= height;
}

void Rectangle::draw() {
	
	ofSetColor(color);
	ofRectangle myRect(x, y, height, width);
	ofDrawRectangle(myRect);
}