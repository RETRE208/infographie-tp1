#pragma once

#ifndef MainController_Included
#define MainController_Included

#include "ofMain.h"
#include "../views/PrimitivePanel.h"
#include "../system/files.h"
#include <vector>
#include "../views/MainPanel.h"
#include "ofxAssimpModelLoader.h"

enum class MeshRenderMode { fill, wireframe, vertex };

class MainController
{
public:

	bool mode3DState = false;

	int DRAWING_ZONE_X_LIMIT = 200;
	int DRAWING_ZONE_Y_LIMIT = 200;
	int DRAWING_ZONE_WIDTH = 964;
	int DRAWING_ZONE_HEIGHT = 539;

	void setup();
	void draw();

	void exportImage();
	void importImage();
	void switch3DMode();
	void switch2DMode();

	ofLight light;
	float center_x;
	float center_y;
	void switchMeshFill();
	void switchMeshWireframe();
	void switchMeshVertex();
	MeshRenderMode mesh_render_mode;

	Files files;
	std::vector<ofImage> images;
	std::vector<ofxAssimpModelLoader> models;

	MainPanel mainPanel;
	PrimitivePanel primitivePanel;
};

#endif