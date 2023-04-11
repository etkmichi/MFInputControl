/*
 * MFInputManager.cpp
 *
 *  Created on: 15.10.2019
 *      Author: michl
 */

#include "MFInputManager.h"

std::vector<MFInterfaceKeyListener*>* MFInputManager::mp_vecKeyCallback=new std::vector<MFInterfaceKeyListener*>();
MFInputManager::MFInputManager() {
	mp_window=nullptr;
	m_glfwKeyCallback=&(MFInputManager::dispatchKeyEvent);
}

MFInputManager::~MFInputManager() {
	for(auto cb:*mp_vecKeyCallback){
		delete cb;
	}
	delete mp_vecKeyCallback;
}


void MFInputManager::initInputManager(GLFWwindow* pWindow){
	mp_window=pWindow;
	glfwSetKeyCallback(mp_window,m_glfwKeyCallback);
}
bool MFInputManager::registerKeyboardListener(MFInterfaceKeyListener* keyListener){
	mp_vecKeyCallback->push_back(keyListener);

	return true;
}
bool MFInputManager::registerMouseCallback(){
	return true;
}
bool MFInputManager::registerCursorPositionCallback(){
	return true;
}
void MFInputManager::setWindow(GLFWwindow* pWindow){
	mp_window=pWindow;
}

void MFInputManager::dispatchKeyEvent(GLFWwindow* pWindow, int key, int scancode, int action, int mods){
	for(MFInterfaceKeyListener* kcb: *mp_vecKeyCallback){
		kcb->keyEventDispatch(key,action,mods);
	}
}
