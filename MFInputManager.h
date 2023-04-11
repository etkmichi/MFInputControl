/*
 * MFInputManager.h
 *
 *  Created on: 15.10.2019
 *      Author: michl
 */

#ifndef MFINPUTMANAGER_H_
#define MFINPUTMANAGER_H_
#include <vector>
#include <GLFW/glfw3.h>
#include "MFListenerInterfaces/MFInterfaceKeyListener.h"
class MFInputManager {
private:
	GLFWwindow*
		mp_window;

	static std::vector<MFInterfaceKeyListener*>
		*mp_vecKeyCallback;
	//TODO implement another callback vector as class member. Overwrite the static pointer for switching input manager...

	void (*m_glfwKeyCallback)(GLFWwindow*, int , int , int , int );

public:
	MFInputManager();
	virtual ~MFInputManager();
	void initInputManager(GLFWwindow* pWindow);
	/**
	 *
	 * @param key
	 * @param callback(int action,int mods)
	 * @return
	 */
	bool registerKeyboardListener(MFInterfaceKeyListener* keyListener);//registerScancodeCallback
	bool registerMouseCallback();
	bool registerCursorPositionCallback();
	void setWindow(GLFWwindow* pWindow);
	static void dispatchKeyEvent(GLFWwindow* pWindow, int key, int scancode, int action, int mods);
};

#endif /* MFINPUTMANAGER_H_ */
