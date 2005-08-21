#pragma once

#include "mainframework.h"

class FrameWork : public CMainFrameWork
{
public:
	FrameWork(void);
	virtual ~FrameWork(void);
	
protected:
	void configPlane();
	
	virtual void createScene(void);   
    virtual void createCamera(void);
	void createFrameListener(void);
};

