#include "SpherePanel.h"

void SpherePanel::setup()
{
	sphere = new Sphere(10);

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->addHeader("Sphere Panel");
	sx = gui->addSlider("SPHERE X", 0, ofGetWidth());
	sy = gui->addSlider("SPHERE Y", 0, ofGetHeight());
	sz = gui->addSlider("SPHERE Z", -500, 500);
	sr = gui->addSlider("SPHERE RADUIS", 0, ofGetWidth() / 2);
	picker = gui->addColorPicker("COLOR PICKER", ofColor::fromHex(0xCECECE));
	picker->onColorPickerEvent(this, &SpherePanel::onColorPickerEvent);

	sx->bind(sphere->x);
	sy->bind(sphere->y);
	sz->bind(sphere->z);
	sr->bind(sphere->mRadius);

	sphere -> x = ofGetWidth() / 2;
	sphere -> y = ofGetHeight() / 2;
}

void SpherePanel::update()
{
	if (ofGetMousePressed() && gui->getMouseDown() == false) {
		ofPoint mouse = ofPoint(ofGetMouseX(), ofGetMouseY());
		if (sphere->inside(mouse)) {
			sphere->x = mouse.x;
			sphere->y = mouse.y;
		}
	}
}

void SpherePanel::draw()
{
	sphere->draw();
	update();
}

void SpherePanel::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	sphere->color = e.color;
}
