/*
 * MFInterfaceKeyListener.cpp
 *
 *  Created on: 16.10.2019
 *      Author: michl
 */

#include "MFInterfaceKeyListener.h"
#include <MFBasicDefines.h>
#include <MFTime/MFTickCounter.h>
MFInterfaceKeyListener::MFInterfaceKeyListener() {
	mp_vecKeys=new std::vector<KeyAction>();
}

MFInterfaceKeyListener::~MFInterfaceKeyListener() {
	delete mp_vecKeys;
}

void MFInterfaceKeyListener::addKey(int key){
  if(key==-1){
    P_WRN("no valid key! Key will not be added for listening! key=-1");
    return;
  }
  KeyAction data{};
	data.key=key;
	mp_vecKeys->push_back(data);
}
std::vector<KeyAction>* MFInterfaceKeyListener::getKeys(){
	return mp_vecKeys;
}

void MFInterfaceKeyListener::pollKeyboardEvents(GLFWwindow *pWindow){
	if(pWindow==nullptr)
		return;
	for(KeyAction& regKey:*mp_vecKeys){
		glfwPollEvents();
		regKey.action=glfwGetKey(pWindow, regKey.key);
		if(regKey.action==GLFW_PRESS){
		  if(!regKey.isPressed){
		    const char* pCharKey=glfwGetKeyName(regKey.key,-1);
		    if(pCharKey==nullptr)pCharKey="Unknown";
		    P_INF("resetting press timepoint! for key "+ std::string(pCharKey));
        regKey.pressTimepoint=MFTickCounter::current();
        regKey.isPressed=true;
		  }
      regKey.mods=0;
			if(glfwGetKey(pWindow, GLFW_KEY_LEFT_SHIFT)==GLFW_PRESS){
        regKey.mods|=GLFW_KEY_LEFT_SHIFT;
			}
      if(glfwGetKey(pWindow, GLFW_KEY_RIGHT_SHIFT)==GLFW_PRESS){
        regKey.mods|=GLFW_KEY_RIGHT_SHIFT;
      }
			keyAction(regKey);
		}else if(regKey.action==GLFW_RELEASE){
		  if(regKey.isPressed){
	      regKey.releaseTimepoint=MFTickCounter::current();
	      regKey.isPressed=false;
	      const char* pCharKey=glfwGetKeyName(regKey.key,-1);
	      if(pCharKey==nullptr)pCharKey="Unknown";
	      P_INF("key release! "+std::string(pCharKey));
		  }
		}
	}
}

void MFInterfaceKeyListener::keyEventDispatch(int key,int action,int mods){
	for(KeyAction& regKey:*mp_vecKeys){
		if(regKey.key==key){
			regKey.action=action;
			regKey.mods=mods;
			if(action==GLFW_PRESS){
			  if(!regKey.isPressed)
			    regKey.pressTimepoint=MFTickCounter::current();
        regKey.isPressed=true;
        keyAction(regKey);
			}else if(action==GLFW_RELEASE){
				regKey.isPressed=false;
			}
		}
	}
	glfwPollEvents();
	//TODO run with external thread and add setup functions to switch between external thread dispatching and action execution
	//TODO if(externalDispatch) add task. if(externalActionExecution) add action execution task to external thread
}
