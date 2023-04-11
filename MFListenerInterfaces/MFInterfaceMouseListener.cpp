/*
 * MFInterfaceMouseListener.cpp
 *
 *  Created on: 17.10.2019
 *      Author: michl
 */

#include "MFInterfaceMouseListener.h"

MFInterfaceMouseListener::MFInterfaceMouseListener(GLFWwindow *pWindow) {
	mp_window=pWindow;
}

MFInterfaceMouseListener::~MFInterfaceMouseListener() {
	// TODO Auto-generated destructor stub
}

void MFInterfaceMouseListener::pollPosition(double &xPos,double &yPos){
	if(mp_window!=nullptr)//TODO static lock for glfw usage!!
		glfwGetCursorPos(mp_window, &xPos, &yPos);
}
int MFInterfaceMouseListener::pollButtonState(int button){
	return glfwGetMouseButton(mp_window, button);
}
bool MFInterfaceMouseListener::isCursorWithingWindowBounds(){
	return glfwGetWindowAttrib(mp_window, GLFW_HOVERED);
}
