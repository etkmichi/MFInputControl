/*
 * MFInterfaceJoystickListener.cpp
 *
 *  Created on: 29.10.2019
 *      Author: michl
 */

#include "MFInterfaceJoystickListener.h"
#include <MFObjects/MFObject.h>

MFInterfaceJoystickListener::MFInterfaceJoystickListener() {
	// TODO Auto-generated constructor stub
	mp_vecJoystickIDs=new std::vector<uint32_t>();
	mp_joystickAxisAction=new JoystickAxisAction();
	mp_joystickButtonAction=new JoystickAction();
	mp_joystickHatAction=new JoystickAction();
}

MFInterfaceJoystickListener::~MFInterfaceJoystickListener() {
	// TODO Auto-generated destructor stub
}

void MFInterfaceJoystickListener::pollJoystickEvents() {
	for(uint32_t jsID:*mp_vecJoystickIDs){
    glfwPollEvents();/*this will add all currently plugged controlers!*/
		int count=0;
		const float *axisData=glfwGetJoystickAxes(jsID, &count);
		if(axisData!=nullptr){
			mp_joystickAxisAction->joystickID=jsID;
			mp_joystickAxisAction->axesArray=axisData;
			mp_joystickAxisAction->axesCount=count;
			joystickAxeAction(mp_joystickAxisAction);
		}
		const unsigned char* btnArray=glfwGetJoystickButtons(jsID, &count);
		if(btnArray!=NULL){
			mp_joystickButtonAction->buttonsCount=count;
			mp_joystickButtonAction->data=btnArray;
			mp_joystickButtonAction->joystickID=jsID;
			joystickButtonAction(mp_joystickButtonAction);
		}
		const unsigned char* hatArray=glfwGetJoystickHats(jsID, &count);
		if(hatArray!=NULL){
			mp_joystickHatAction->buttonsCount=count;
			mp_joystickHatAction->data=hatArray;
			mp_joystickHatAction->joystickID=jsID;
			joystickHatAction(mp_joystickHatAction);
		}
	}
}
void MFInterfaceJoystickListener::addJoystick(int number) {
	mp_vecJoystickIDs->push_back(number);
}

std::vector<uint32_t> MFInterfaceJoystickListener::getAvailableJoysticks(){
	std::vector<uint32_t> avJs;
	std::string info="Joysticks: \n";
	for(uint32_t i=0;i<=15;i++){
		const char* jostickName=glfwGetJoystickName(i);
		if(GLFW_TRUE==glfwJoystickPresent(i)){
			avJs.push_back(i);
		}
		if(jostickName==NULL){
			info+="Joystick no. "+std::to_string(i)+" not available!\n";
		}else{
			info+="Joystick no. "+std::to_string(i)+" "+std::string(jostickName)+"\n";
		}
	}
	MFObject::printInfo(info);
	return avJs;
}

void MFInterfaceJoystickListener::printJoystickAxes(int joystickID){
	int count=0;
	const float* pData=glfwGetJoystickAxes(joystickID,&count);
	if(pData==nullptr || count<=0){
		P_INF("No valid data for joystick found. Joystick id:"+
				std::to_string(joystickID));
		return;
	}
	std::string info="Axis values:\n";
	for(int i=0;i<count;i++){
		info+="axis no. "+std::to_string(i)+"=";
		info+=std::to_string((pData[i]))+"\n";
	}
	P_INF(info);
}

void MFInterfaceJoystickListener::printJoystickInputs(){
	std::string info="Joysticks: \n";
	for(uint32_t i=0;i<=15;i++){
		const char* jostickName=glfwGetJoystickName(i);
		if(jostickName==NULL){
			info+="Joystick no. "+std::to_string(i)+" not available!\n";
		}else{
			info+="Joystick no. "+std::to_string(i)+" "+std::string(jostickName)+"\n";
		}
	}
	MFObject::printInfo(info);
}
