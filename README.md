# ATS-GUARD — Monitoring and Interlocking System

## Overview

ATS-GUARD is a project under development that combines Industrial Electricity
and programming to monitor an electrical circuit designed to reverse the
direction of rotation of an electric motor.

The system uses two contactors, K1 and K2, responsible for reversing the
motor's direction of rotation. An ESP32 microcontroller is planned to process
signals received from the circuit and identify specific operating conditions.

The project also plans to use a PC817 optocoupler to provide electrical
isolation for selected signals through a properly designed interface.

## Objectives

- Monitor the states of contactors K1 and K2.
- Process electrical signals using an ESP32.
- Identify unexpected operating states.
- Apply practical knowledge of Industrial Electricity and programming.
- Explore the integration of microcontrollers into industrial monitoring
  applications.

## Components and Technologies

- ESP32 microcontroller
- C++ and Arduino framework
- Contactors K1 and K2
- Auxiliary contacts
- PC817 optocoupler
- Electric motor direction-reversing circuit

## How It Works

The electrical circuit uses K1 and K2 to reverse the direction of rotation
of an electric motor.

The planned ESP32-based system will read selected signals from the circuit,
process them, and identify conditions that may indicate abnormal operation.

The PC817 is planned as part of the signal interface between the electrical
circuit and the ESP32.

The actual implementation will depend on the final wiring and hardware
integration.

## Current Project Status

**Status: In Development**

The following materials are currently available:

- Electrical schematic of the direction-reversing circuit
- Initial software code
- Video demonstrating the operation of the contactors
- Project documentation

The ESP32 and PC817 have not yet been acquired. Hardware integration and
practical testing are still pending.

This repository documents the progress achieved so far and will be updated
as development continues.

## Safety Considerations

ATS-GUARD is intended as a complementary monitoring system.

It does not replace electrical protection devices or the electrical and
mechanical interlocking mechanisms required to prevent simultaneous
activation of K1 and K2.

The monitoring software must not be considered a safety-rated protection
system.


## Future Improvements

- Integrate ESP32 into the monitoring circuit
- Implement the PC817 optocoupler signal interface
- Test K1 and K2 feedback signals with ESP32 via PC817
- Verify abnormal state detection logic
- Document practical test results and measurements
- Update code and schematic according to the final implementation

## Project Documentation

Detailed technical documentation is available in the
[docs/DOCUMENTATION.md](docs/DOCUMENTATION.md)`file.

🎥 **Demo Video:** [Watch on YouTube](https://youtube.com/shorts/DIRaJ0ekB5Y?si=hce-8dxhDdu8e2tk)

**ATS-GUARD Project Schematics**: [ATS-GUARD_HW-REV-01_Motor-Reversing-Starter.pdf](ATS-GUARD_HW-REV-01_Motor-Reversing-Starter.pdf)

## Author

**Nunes Arlindo Chirrute**

Maputo, Mozambique  
2026

## License

A licence can be added when the project distribution terms have been defined.
