/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Lift/ExtendLift.h"

ExtendLift::ExtendLift(Lift& lift) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&lift});
}

// Called when the command is initially scheduled.
void ExtendLift::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ExtendLift::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "ExtendLift Command Executing" << std::endl;
#endif  
  //Lift::GetInstance().Extend();
}

// Called once the command ends or is interrupted.
void ExtendLift::End(bool interrupted) {}

// Returns true when the command should end.
bool ExtendLift::IsFinished() { return false; }
