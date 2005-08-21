#include "Road.h"

int Road::countName = 0;

Road::Road (Ogre::SceneManager& sceneMgr, const Ogre::String& meshFile) : 
	entity(0), sceneNode(0)															  
{
	meshName = Ogre::String("road") + Ogre::StringConverter::toString(countName);
	entity = sceneMgr.createEntity(meshName, meshFile);
	sceneNode = sceneMgr.getRootSceneNode()->createChildSceneNode();
	sceneNode->attachObject(entity);
	addLevel();
	Road::countName++;
}

void Road::addPosition ( Ogre::Real x, Ogre::Real y, Ogre::Real z)
{
	const Ogre::Vector3 v = sceneNode->getPosition();
	sceneNode->setPosition(v.x + x, v.y + y, v.z + z);
}

void Road::rotate(const Ogre::Vector3& axis, const Ogre::Radian& angle)
{
	sceneNode->rotate(axis, angle);
}

bool Road::addLevel()
{
	const Ogre::Vector3 v = sceneNode->getPosition();
	if (v.y == 50 * 2)
		return false;
	
	addPosition(0, 50, 0);
	return true;
}

bool Road::subLevel()
{
	const Ogre::Vector3 v = sceneNode->getPosition();
	if (v.y == 0)
		return false;

	addPosition(0, -50, 0);
	return true;
}

void Road::showChoice(bool show)
{
	sceneNode->showBoundingBox(show);
}

