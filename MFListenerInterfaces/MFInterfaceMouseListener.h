/*
 * MFInterfaceMouseListener.h
 *
 *  Created on: 17.10.2019
 *      Author: michl
 */

#ifndef MFLISTENERINTERFACES_MFINTERFACEMOUSELISTENER_H_
#define MFLISTENERINTERFACES_MFINTERFACEMOUSELISTENER_H_

#include <vector>
#include "MFObjects/MFObject.h"
#include <GLFW/glfw3.h>

class MFInterfaceMouseListener {
private:
	GLFWwindow
		*mp_window;
public:
	MFInterfaceMouseListener(){mp_window=nullptr;};
	MFInterfaceMouseListener(GLFWwindow *pWindow);
	virtual ~MFInterfaceMouseListener();
	void pollPosition(double &xPos,double &yPos);
	int pollButtonState(int button);
	bool isCursorWithingWindowBounds();
	void setWindow(GLFWwindow *pWindow){mp_window=pWindow;};
};

#endif /* MFLISTENERINTERFACES_MFINTERFACEMOUSELISTENER_H_ */
