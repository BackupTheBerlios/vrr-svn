#include "FrameWork.h"
#include "FrameListener.h"

FrameWork::FrameWork(void)
{
}

FrameWork::~FrameWork(void)
{
}

void FrameWork::createScene(void)
{	
	mSceneMgr->setAmbientLight(ColourValue(0.4, 0.4, 0.4));

	mSceneMgr->setShadowTechnique(SHADOWTYPE_STENCIL_MODULATIVE);
	
	Light* l = mSceneMgr->createLight("MainLight");
	l->setType(Ogre::Light::LT_DIRECTIONAL);
	l->setDirection(-0.5, -0.5, -0.5);
	l->setDiffuseColour(1.0, 1.0, 1.0);	

	this->configPlane();	
}


void FrameWork::configPlane()
{
	Entity *ent;
	Plane p;
	p.normal = Vector3::UNIT_Y;
	p.d = 0;

	MeshManager::getSingleton().createPlane("FloorPlane",
			ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, 
			p,3000,3000,1,1,true,1,40,40,Vector3::UNIT_Z);

	ent = mSceneMgr->createEntity("floor", "FloorPlane");
	ent->setMaterialName("terra/RustySteel");
	mSceneMgr->getRootSceneNode()->attachObject(ent);
}


void FrameWork::createCamera(void)
{
	mCamera = mSceneMgr->createCamera("PlayerCam");

	mCamera->setPosition(Vector3(0,50,500));

	// Look back along -Z
	mCamera->lookAt(Vector3(0,0,-300));
	mCamera->setNearClipDistance(5);
}


void FrameWork::createFrameListener(void)
{
	mFrameListener= new FrameListenerEd(mWindow, mCamera, mSceneMgr);
	mRoot->addFrameListener(mFrameListener);
}

