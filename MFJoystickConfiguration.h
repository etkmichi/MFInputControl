/*
 * MFJoystickConfiguration.h
 *
 *  Created on: 29.10.2020
 *      Author: michl
 */

#ifndef MFJOYSTICKCONFIGURATION_H_
#define MFJOYSTICKCONFIGURATION_H_

class MFJoystickConfiguration {
protected:
  int
    m_axisIndexLeftStickBack=1,
    m_axisIndexLeftStickFront=1,
    m_axisIndexLeftStickLeft=0,
    m_axisIndexLeftStickRight=0,
    m_axisIndexRightStickFront=4,
    m_axisIndexRightStickBack=4,
    m_axisIndexRightStickLeft=3,
    m_axisIndexRightStickRight=3,
    m_axisIndexLeftTriggerAxe=2,
    m_axisIndexRightTriggerAxe=5;//TODO indices for triggers

  float/*already squared values (treshold=0.1f)*/
    m_lsTresholdFront=.01f,
    m_lsTresholdBack=.01f,
    m_lsTresholdLeft=.01f,
    m_lsTresholdRight=.01f,
    m_rsTresholdFront=.01f,
    m_rsTresholdBack=.01f,
    m_rsTresholdLeft=.01f,
    m_rsTresholdRight=.01f,
    m_lsTresholdTrigger=.01f,
    m_rsTresholdTrigger=.01f;

public:
  MFJoystickConfiguration();
  void useMSXBOX1ControlerSetup();
  void setIndexLeftStickBack(int index){m_axisIndexLeftStickBack=index;};
  void setIndexLeftStickFront(int index){m_axisIndexLeftStickFront=index;};
  void setIndexLeftStickLeft(int index){m_axisIndexLeftStickLeft=index;};
  void setIndexLeftStickRight(int index){m_axisIndexLeftStickRight=index;};
  void setIndexRightStickBack(int index){m_axisIndexRightStickBack=index;};
  void setIndexRightStickFront(int index){m_axisIndexRightStickFront=index;};
  void setIndexRightStickLeft(int index){m_axisIndexRightStickLeft=index;};
  void setIndexRightStickRight(int index){m_axisIndexRightStickRight=index;}

  int getIndexLSBack(){return m_axisIndexLeftStickBack;};
  int getIndexLSFront(){return m_axisIndexLeftStickFront;};
  int getIndexLSRight(){return m_axisIndexLeftStickLeft;};
  int getIndexLSLeft(){return m_axisIndexLeftStickRight;};
  int getIndexRSBack(){return m_axisIndexRightStickBack;};
  int getIndexRSFront(){return m_axisIndexRightStickFront;};
  int getIndexRSRight(){return m_axisIndexRightStickLeft;};
  int getIndexRSLeft(){return m_axisIndexRightStickRight;};

  //TODO implement threshold array bc. a controler may provide more axis f.e. vr controler!
  bool checkLStTresholdFront(float val){return (m_lsTresholdFront<=(val*val));}
  bool checkLStTresholdBack(float val){return (m_lsTresholdBack<=(val*val));}
  bool checkLStTresholdLeft(float val){return (m_lsTresholdLeft<=(val*val));}
  bool checkLStTresholdRight(float val){return (m_lsTresholdRight<=(val*val));}

  bool checkRStTresholdFront(float val){return (m_rsTresholdFront<=(val*val));}
  bool checkRStTresholdBack(float val){return (m_rsTresholdBack<=(val*val));}
  bool checkRStTresholdLeft(float val){return (m_rsTresholdLeft<=(val*val));}
  bool checkRStTresholdRight(float val){return (m_rsTresholdRight<=(val*val));}

  bool checkLStTresholdTrigger(float val){return (m_lsTresholdTrigger<=(val*val));}
  bool checkRStTresholdTrigger(float val){return (m_rsTresholdTrigger<=(val*val));}
};

#endif /* MFJOYSTICKCONFIGURATION_H_ */
