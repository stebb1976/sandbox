/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/



/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with split arcade steering and an Xbox controller.
 */
class Robot : public frc::TimedRobot {


 public:
  void TeleopPeriodic() {

  }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
