/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "commands/Intake/DeployIntake.h"
#include "commands/Intake/Suck.h"

#include "subsystems/Intake.h"

class Deploy_and_Suck
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 Deploy_and_Suck> {
 public:
  Deploy_and_Suck(Intake& intake);
};
