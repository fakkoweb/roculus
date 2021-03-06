#include "Video3D.h"

Video3D::Video3D(Ogre::Entity *pSnapshot, Ogre::SceneNode *pSceneNode, const Ogre::TexturePtr &depthTexture, const Ogre::TexturePtr &rgbTexture) {
	this->snapshot = pSnapshot;
	this->targetSceneNode = pSceneNode;
	this->depthTexture = depthTexture;
	this->rgbTexture = rgbTexture;
	this->attached = false;
	//~ this->depthMask = depthMask;
}

Video3D::~Video3D() {
}

bool Video3D::update(const Ogre::Image &depth, const Ogre::Image &rgb, const Ogre::Vector3 &pos, const Ogre::Quaternion &orientation) {
	depthTexture->unload();
	depthTexture->loadImage(depth);
	rgbTexture->unload();
	rgbTexture->loadImage(rgb);
	//~ depthMask->unload();
	//~ depthMask->loadImage(depthMask)
	targetSceneNode->setPosition(pos);
	targetSceneNode->setOrientation(orientation);
	if (!attached) {
		targetSceneNode->attachObject(snapshot);
		attached = true;
	}
	return true;
}

Ogre::SceneNode* Video3D::getTargetSceneNode() {
	return this->targetSceneNode;
}

Ogre::TexturePtr Video3D::getAssignedDepthTexture() {
	return this->depthTexture;
}

//~ Ogre::TexturePtr Video3D::getAssignedDepthMask() {
	//~ return this->depthMask;
//~ }

Ogre::TexturePtr Video3D::getAssignedRGBTexture() {
	return this->rgbTexture;
}

void Video3D::setTargetSceneNode(Ogre::SceneNode* node) {
	this->targetSceneNode = node;
}

void Video3D::assignDepthTexture(const Ogre::TexturePtr &tex) {
	this->depthTexture = tex;
}

//~ void Video3D::assignDepthMask(const Ogre::TexturePtr &tex) {
	//~ this->depthMask;
//~ }

void Video3D::assignRGBTexture(const Ogre::TexturePtr &tex) {
	this->rgbTexture = tex;
}

