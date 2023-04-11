/*
 * MFJoystickConfiguration.cpp
 *
 *  Created on: 29.10.2020
 *      Author: michl
 */

#include "MFJoystickConfiguration.h"

MFJoystickConfiguration::MFJoystickConfiguration() {
}

void MFJoystickConfiguration::useMSXBOX1ControlerSetup(){
  m_axisIndexLeftStickBack=1;
  m_axisIndexLeftStickFront=1;
  m_axisIndexLeftStickLeft=0;
  m_axisIndexLeftStickRight=0;
  m_axisIndexRightStickFront=4;
  m_axisIndexRightStickBack=4;
  m_axisIndexRightStickLeft=3;
  m_axisIndexRightStickRight=3;
}
