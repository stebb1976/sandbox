/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Serializer/VBeltOff.h"

#include <iostream>

VBeltOff::VBeltOff(Serializer& serializer) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({&serializer});
}

// Called when the command is initially scheduled.
void VBeltOff::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void VBeltOff::Execute() {
#ifdef DISPLAY_COMMAND_MESSAGES
  std::cout << "VBeltOff Command Executing" << std::endl;
#endif 
  //Serializer::GetInstance().Off();
}

// Called once the command ends or is interrupted.
void VBeltOff::End(bool interrupted) {}

// Returns true when the command should end.
bool VBeltOff::IsFinished() { return false; }
