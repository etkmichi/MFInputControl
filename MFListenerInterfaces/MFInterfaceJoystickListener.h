/*
 * MFInterfaceJoystickListener.h
 *
 *  Created on: 29.10.2019
 *      Author: michl
 */

#ifndef MFLISTENERINTERFACES_MFINTERFACEJOYSTICKLISTENER_H_
#define MFLISTENERINTERFACES_MFINTERFACEJOYSTICKLISTENER_H_
#include "GLFW/glfw3.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include <MFBasicDefines.h>
struct JoystickAxisAction{
	int joystickID=-1;
	const float* axesArray=nullptr;
	int axesCount=0;
};
struct JoystickAction{
	int joystickID=-1;
	const unsigned char* data=nullptr;
	int buttonsCount=0;
};
class MFInterfaceJoystickListener {
private:
	std::vector<uint32_t>
		*mp_vecJoystickIDs;
	JoystickAxisAction
		*mp_joystickAxisAction;
	JoystickAction
		*mp_joystickButtonAction,
		*mp_joystickHatAction;
public:/*virtual functions of MFInterfaceJoystickListener*/
  virtual void joystickAxeAction(JoystickAxisAction* axisActionData){P_WRN("no impl.!");};
  virtual void joystickButtonAction(JoystickAction* btnActionData){P_WRN("no impl.!");};
  virtual void joystickHatAction(JoystickAction* hatActionData){P_WRN("no impl.!");};
public:
	MFInterfaceJoystickListener();
	virtual ~MFInterfaceJoystickListener();
	void addJoystick(int number);
//	int* getAvailableJoysticks(int &count){P_ERR("no impl.!");return nullptr;}; TODO

	/**
	 * this function will poll the joystick events, and execute the virtual joystick action functions.
	 * @param pWindow
	 */
	void pollJoystickEvents();

	static void printJoystickInputs();
	static void printJoystickAxes(int joystickID);
	static std::vector<uint32_t> getAvailableJoysticks();
};

#endif /* MFLISTENERINTERFACES_MFINTERFACEJOYSTICKLISTENER_H_ */
