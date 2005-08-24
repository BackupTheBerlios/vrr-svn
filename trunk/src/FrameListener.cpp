#include "FrameListener.h"

FrameListenerEd::FrameListenerEd(RenderWindow* win, Camera* cam, SceneManager* man) :
	CMainFrameListener(win, cam), sceneManager(man)
{
}

FrameListenerEd::~FrameListenerEd(void)
{
}


bool FrameListenerEd::frameStarted(const FrameEvent& evt)
{
	static int selected = 0;

	Real MoveFactor = 400.0 * evt.timeSinceLastFrame;

	if(!CMainFrameListener::frameStarted(evt))
		return false;

	if (roads.size() > 0) {
		if(	mInputDevice->isKeyDown(Ogre::KC_UP)) {
			roads[selected].addPosition(0, 0, -1 * MoveFactor);		
		}

		if(	mInputDevice->isKeyDown(Ogre::KC_DOWN))	{
			roads[selected].addPosition(0, 0, MoveFactor);
		}

		if(	mInputDevice->isKeyDown(Ogre::KC_LEFT) && !mInputDevice->isKeyDown(Ogre::KC_LCONTROL)) {
			roads[selected].addPosition(-1 * MoveFactor,	0, 0);
		}

		if(	mInputDevice->isKeyDown(Ogre::KC_RIGHT)	&& !mInputDevice->isKeyDown(Ogre::KC_LCONTROL) ) {
			roads[selected].addPosition(MoveFactor, 0, 0);
		}

		if(	mInputDevice->isKeyDown(Ogre::KC_PGUP) && mTimeUntilNextToggle <= 0) {
			roads[selected].addLevel();
			mTimeUntilNextToggle = 0.1;
		}

		if(	mInputDevice->isKeyDown(Ogre::KC_PGDOWN) &&	mTimeUntilNextToggle <=	0 )	{
			roads[selected].subLevel();
			mTimeUntilNextToggle = 0.1;
		}

		if(	mInputDevice->isKeyDown(Ogre::KC_LEFT) && mInputDevice->isKeyDown(Ogre::KC_LCONTROL)) {
			roads[selected].rotate(Vector3::UNIT_Y,	Ogre::Radian(-0.01 * MoveFactor));
		}

		if(	mInputDevice->isKeyDown(Ogre::KC_RIGHT)	&& mInputDevice->isKeyDown(Ogre::KC_LCONTROL)) {
			roads[selected].rotate(Vector3::UNIT_Y,	Ogre::Radian(0.01 * MoveFactor));		
		}

		if(mInputDevice->isKeyDown(Ogre::KC_M)  && mTimeUntilNextToggle <= 0) {			
			roads[selected].showChoice(false);
			++selected;
			selected = selected % roads.size();
			roads[selected].showChoice(true);
			mTimeUntilNextToggle = 0.1;
		}
	}

	if(mInputDevice->isKeyDown(Ogre::KC_N)  && mTimeUntilNextToggle <= 0) {			
		if(roads.size() > 0)
			roads[selected].showChoice(false);

		roads.push_back( Road(*sceneManager, "curva001.mesh") );
		selected = roads.size() - 1;
		roads[selected].showChoice(true);
		mTimeUntilNextToggle = 0.1;
	}

	if(mInputDevice->isKeyDown(Ogre::KC_H)  && mTimeUntilNextToggle <= 0) {			
		if(roads.size() > 0)
			roads[selected].showChoice(false);

		roads.push_back( Road(*sceneManager, "reta002.mesh") );
		selected = roads.size() - 1;
		roads[selected].showChoice(true);
		mTimeUntilNextToggle = 0.1;
	}

	return true;
}
