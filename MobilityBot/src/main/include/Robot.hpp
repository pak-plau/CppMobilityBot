/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>
#include <rev/CANSparkMax.h>
#include <frc/TimedRobot.h>
#include <frc2/Timer.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/DifferentialDrive.h>
#include <frc/Joystick.h>
#include <frc/smartdashboard/SendableChooser.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  rev::CANSparkMax leftTop {7, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax leftBot {6, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax rightTop {4, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax rightBot {3, rev::CANSparkMax::MotorType::kBrushless};

  frc::SpeedControllerGroup lMotors {leftTop, leftBot};
  frc::SpeedControllerGroup rMotors {rightTop, rightBot};

  frc::DifferentialDrive motors {lMotors, rMotors};

  frc::Joystick joystick {0};

  frc2::Timer timer;

  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  void SetChannels();
};
