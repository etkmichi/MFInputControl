/*
 * MFInterfaceKeyListener.h
 *
 *  Created on: 16.10.2019
 *      Author: michl
 */

#ifndef MFLISTENERINTERFACES_MFINTERFACEKEYLISTENER_H_
#define MFLISTENERINTERFACES_MFINTERFACEKEYLISTENER_H_

#include <vector>
#include "MFObjects/MFObject.h"
#include <MFBasicDefines.h>
#include <GLFW/glfw3.h>

struct KeyAction{
	int key=-1;
	int action=-1;
	int mods=-1;
  bool isPressed=false;
	int64_t pressTimepoint=-1;
	int64_t releaseTimepoint=-1;
	void init();
	static void printAction(const KeyAction &action){
    const char* keyName=glfwGetKeyName(action.key, -1);
    P_INF("action: "+T_HEX_S(action.action));
    if(keyName!=nullptr)
      P_INF("key: ("+std::string(keyName)+") key id: "+T_S(action.key));
    else
      P_INF("key: (key unknown!) key id: "+T_S(action.key));
    P_INF("mods: "+T_HEX_S(action.mods));
  }
};

class MFInterfaceKeyListener {
private:
	std::vector<KeyAction>
		*mp_vecKeys;
public:/*virtual functions MFInterfaceKeyListener*/
//  virtual void keyAction(int key,int action,int mods){
//    MFObject::printInfo("Abstract function called!");
//  };
  virtual void keyAction(const KeyAction &action) = 0;

public:
	MFInterfaceKeyListener();
	virtual ~MFInterfaceKeyListener();
	/**
	 * Used for callback
	 * @param key
	 * @param action
	 * @param mods
	 */
	void keyEventDispatch(int key,int action,int mods);

	/**
	 * This function manually polls every registered button and executes the action if the button is pressed.
	 */
	void pollKeyboardEvents(GLFWwindow *pWindow);
	void addKey(int key);
	std::vector<KeyAction>* getKeys();

};

#endif /* MFLISTENERINTERFACES_MFINTERFACEKEYLISTENER_H_ */
