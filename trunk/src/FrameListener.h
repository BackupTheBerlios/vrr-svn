#pragma once
#include "mainframelistener.h"
#include "Road.h"
#include <vector>

 
class FrameListenerEd :
	public CMainFrameListener
{
private:	
	std::vector<Road> roads;

protected:
	SceneManager* sceneManager;

public:
	FrameListenerEd(RenderWindow* win, Camera* cam, SceneManager* man);
	virtual ~FrameListenerEd(void);

	bool frameStarted(const FrameEvent& evt);
};
