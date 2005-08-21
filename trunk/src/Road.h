#pragma once

#include "Ogre.h"

class Road
{
	private:
		Ogre::Entity *entity;
		Ogre::SceneNode *sceneNode;
		Ogre::String meshName;
		static int countName;
	
	public:
		Road (Ogre::SceneManager& sceneMgr, const Ogre::String& meshfile);
		void addPosition ( Ogre::Real x, Ogre::Real y, Ogre::Real z);
		void rotate(const Ogre::Vector3& axis, const Ogre::Radian& angle);
		bool addLevel();
		bool subLevel();
		void showChoice(bool show);
};
