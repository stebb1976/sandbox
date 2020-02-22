/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>

//Subsystems
#include "subsystems/Drivetrain.h"
#include "subsystems/Shooter.h"
#include "subsystems/Serializer.h"
#include "subsystems/Intake.h"
#include "subsystems/Lift.h"
#include "subsystems/ControlPanelManipulator.h"

//Commands
#include "commands/drivetrain/TankDrive.h"

#include "commands/Intake/Suck.h"
#include "commands/Intake/DontSuck.h"
#include "commands/Intake/DeployIntake.h"
#include "commands/Intake/RetractIntake.h"
#include "commands/Intake/Deploy_And_Suck.h"
#include "commands/Intake/Retract_and_DontSuck.h"
#include "commands/CollectBalls.h"

#include "commands/Serializer/VBeltOff.h"

#include "commands/Shooter/SpinUp_and_Shoot.h"
#include "commands/Shooter/IdleShooter.h"

#include "commands/ControlPanel/DeployCPM.h"
#include "commands/ControlPanel/StowCPM.h"
#include "commands/ControlPanel/AutomaticallySpinControlPanel.h"
#include "commands/ControlPanel/ManuallySpinControlPanel.h"

#include "commands/Lift/RetractLift.h"
#include "commands/Lift/ExtendLift.h"
#include "commands/Lift/LengthenWinch.h"
#include "commands/Lift/ShortenWinch.h"


using namespace frc;

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  // frc2::Command* GetAutonomousCommand();

 private:

  ///////////////////////////////////////////////////////////////////////////////////////
  //Controller(s)
  ///////////////////////////////////////////////////////////////////////////////////////
  frc::XboxController m_controller_0 { constants::oi::kDriverXboxControllerPort0 };
  frc::XboxController m_controller_1 { constants::oi::kDriverXboxControllerPort1 };

  ///////////////////////////////////////////////////////////////////////////////////////
  //Subsystems
  ///////////////////////////////////////////////////////////////////////////////////////
  Drivetrain& m_drivetrain = Drivetrain::GetInstance();
  Intake& m_intake = Intake::GetInstance();
  Serializer& m_serializer = Serializer::GetInstance();//V-Belt
  Shooter& m_shooter = Shooter::GetInstance();
  ControlPanelManipulator& m_controlPanelManipulator = ControlPanelManipulator::GetInstance();
  Lift& m_lift = Lift::GetInstance();

  ///////////////////////////////////////////////////////////////////////////////////////
  //Commands
  ///////////////////////////////////////////////////////////////////////////////////////
  Deploy_and_Suck m_deployAndSuckCommand {m_intake};
  VBeltForward m_vBeltForwardCommand {m_serializer};
  Preload m_preloadCommand {m_shooter};
  CollectBalls m_CollectBallsCommand {m_intake, m_serializer, m_shooter};

  DeployCPM m_deployCPMCommand {m_controlPanelManipulator};
  StowCPM m_stowCPMCommand {m_controlPanelManipulator};
  AutomaticallySpinControlPanel m_automaticallySpinControlPanelCommand {m_controlPanelManipulator};
  ManuallySpinControlPanel m_manuallySpinControlPanelCommand {m_controlPanelManipulator, m_controller_0};
  // MoveControlPanelToColor m_spinCPMCWCommand {m_controlPanelManipulator};

  ///////////////////////////////////////////////////////////////////////////////////////
  //Buttons
  ///////////////////////////////////////////////////////////////////////////////////////
  //Drivetrain (Non Default Commands)
  //sfs: You may want a slower drivetrain for lining up shoots.
  //sfs: You could use a button to toggle in and out of a slower response drivetrain mode
  frc2::JoystickButton m_precisionDrivetrainControlButton { &m_controller_0, (int)XboxController::Button::kB };   //Toggle button to switch between normal and precision mode

  //Collect & Shoot Balls
  frc2::JoystickButton m_retractIntakeButton { &m_controller_1, (int)XboxController::Button::kX };
  frc2::JoystickButton m_collectBallsButton { &m_controller_1, (int)XboxController::Button::kBumperRight };   //Deploy (if not deployed / Suck balls / Move ball to shooter)
  frc2::JoystickButton m_enableLimeLightDrivetrainControlButton { &m_controller_0, (int)XboxController::Button::kA };   //Hold down button
  frc2::JoystickButton m_shootButton { &m_controller_0, (int)XboxController::Button::kBumperLeft };
  // frc2::JoystickButton m_manuallyAdjustShooterSpeedButton { &m_controller_0, (int)XboxController::Button::kBumperLeft };
  // frc2::JoystickButton m_automaticallyAdjustShooterSpeedButton { &m_controller_0, (int)XboxController::Button::kBumperLeft };

  //Spin Control Panel
  frc2::JoystickButton m_toggleCPMDeploymentButton { &m_controller_1, (int)XboxController::Button::kY };
  frc2::JoystickButton m_toggleSpinControlPanelModeButton_ { &m_controller_1, (int)XboxController::Button::kA };    //Toggle between manual control and automatic control
  // frc2::JoystickButton m_manuallySpinControlPanelButton_ { &m_controller_1, m_controller_0 };    //right trigger = clockwise, left trigger = counter clockwise
  frc2::JoystickButton m_automaticallySpinControlPanelButton_ { &m_controller_1, (int)XboxController::Button::kA };
  // frc2::JoystickButton m_moveControlPanelToColorButton_ { &m_controller_1, (int)XboxController::Button::kA };
  
  //Lift
  frc2::JoystickButton m_toggleLiftDeploymentButton { &m_controller_1, (int)XboxController::Button::kY };
  frc2::JoystickButton m_moveLiftUpDownButton { &m_controller_1, (int)XboxController::Button::kY };     //POV Up extends Lift, POV down retracts
  frc2::JoystickButton m_moveLiftSide2SideButton { &m_controller_1, (int)XboxController::Button::kY };  //POV right & left to move robot balancer wheel

  void ConfigureButtonBindings();
};
