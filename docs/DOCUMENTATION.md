# ATS-GUARD — Project Documentation

**Author:** Nunes Arlindo Chirrute
**Location:** Maputo, Mozambique
**Year:** 2026
**Field:** Industrial Electricity and Programming
**Project Status:** In Development

## 1. Introduction

ATS-GUARD is a project under development that combines Industrial Electricity and programming to monitor an electrical circuit designed to reverse the direction of rotation of an electric motor.

The project uses two contactors, identified as K1 and K2, which are responsible for reversing the motor's direction of rotation. The proposed system will integrate an ESP32 microcontroller to monitor the circuit's state and identify conditions that may indicate incorrect operation.

The system is intended to complement the existing electrical circuit. It will not replace electrical protection devices or the electrical and mechanical interlocking mechanisms required for safe operation.

## 2. Project Objectives

The main objective of ATS-GUARD is to develop a monitoring solution for an electric motor direction-reversing circuit.

The specific objectives are:

* Monitor the states of contactors K1 and K2.
* Use the ESP32 to process signals received from the electrical circuit.
* Identify operating conditions that may indicate an abnormal state.
* Explore the use of the PC817 optocoupler to provide electrical isolation between selected circuit signals and the ESP32 inputs.
* Apply practical knowledge of Industrial Electricity and programming in a technical project.

## 3. Project Components

The main components planned for the project are listed below.

| Component                  | Function                                                                                         |
| -------------------------- | ------------------------------------------------------------------------------------------------ |
| ESP32                      | Process input signals and execute the monitoring logic.                                          |
| Contactor K1               | Establish the electrical connections corresponding to one direction of motor rotation.           |
| Contactor K2               | Establish the electrical connections corresponding to the opposite direction of motor rotation.  |
| Auxiliary contacts         | Provide information about the contactors' states, depending on the electrical connections used.  |
| PC817 optocoupler          | Provide electrical isolation for selected signals through a properly designed interface circuit. |
| Electrical control circuit | Control the reversal of the motor's direction of rotation.                                       |

**Note:** The ESP32 and PC817 have not yet been acquired. Their physical integration into the project remains pending.

## 4. System Operation

The electrical circuit uses contactors K1 and K2 to reverse the direction of rotation of the motor.

When K1 is activated, the circuit establishes the connections corresponding to one direction of rotation. When K2 is activated, it establishes the connections required for the opposite direction.

To prevent dangerous operating conditions, the circuit must include an appropriate electrical and, where applicable, mechanical interlocking system to prevent both contactors from being activated simultaneously.

The ESP32 will perform a complementary monitoring function. It is intended to receive signals from the electrical circuit through a suitable interface, process those signals, and check whether the observed states match the conditions defined in the program.

For example, the system may identify a condition in which the received signals indicate that K1 and K2 are activated simultaneously. However, the ability to detect this condition depends on the actual wiring and the signals made available to the ESP32.

**Safety note:** Software-based monitoring does not replace electrical or mechanical interlocking. The physical prevention of simultaneous contactor activation must be ensured by the electrical control circuit.

## 5. Software Development

The project code is being developed in C++, using the Arduino programming framework for the ESP32.

The software logic is designed to organise signal reading, analyse the states of contactors K1 and K2, and identify specific operating conditions.

The program is expected to follow these general steps:

1. **Initialisation:** Configure the inputs and outputs used by the system.
2. **Signal reading:** Receive the states of the auxiliary contacts through the planned interface.
3. **Analysis:** Check whether the received states match the conditions defined in the program.
4. **Abnormal-state detection:** Identify signal combinations that indicate an unexpected operating condition.
5. **System response:** Execute the monitoring response defined in the code for the detected condition.

The final implementation must match the actual electrical connections and the signals available to the ESP32. Therefore, the complete behaviour of the software can only be confirmed after hardware integration and practical testing.

## 6. Use of the PC817 Optocoupler

The PC817 is an optocoupler that transfers a signal through an optical interface, providing electrical isolation between two circuits when correctly implemented.

In ATS-GUARD, the PC817 is planned for use in the interface between selected electrical circuit signals and the ESP32 inputs.

The interface must be designed according to the signal voltage, resistor values, current limits, and the electrical requirements of the ESP32 inputs. The circuit must be properly dimensioned before physical connection.

Since the PC817 has not yet been acquired, this part of the project remains to be implemented and tested.

## 7. Current Project Status

ATS-GUARD is currently in the development stage. The following materials are available to demonstrate the progress made so far:

* An electrical schematic of the motor direction-reversing circuit.
* An initial version of the software developed for future ESP32 integration.
* A video demonstrating the operation of the contactors.
* Technical documentation describing the project's objectives and intended operation.

The remaining work includes acquiring the ESP32 and PC817, implementing the signal interface, integrating the components, and conducting practical tests to verify the system's behaviour.

The project should therefore not yet be presented as a fully assembled or validated electronic system. The existing documentation and demonstration materials represent the progress achieved up to this stage.

## 8. Future Development
The following steps are planned for the continued development of ATS-GUARD:

1. Integrate ESP32 into the monitoring circuit.
2. Implement the PC817 optocoupler signal interface.
3. Test K1 and K2 feedback signals with ESP32 via PC817.
4. Verify abnormal operating state detection.
5. Document practical tests and results.
6. Update code and wiring diagrams based on test results.

## 9. Conclusion

ATS-GUARD is a practical application of knowledge acquired in Industrial Electricity and programming. The project aims to introduce electronic monitoring into an electric motor direction-reversing circuit using contactors K1 and K2, with a planned ESP32-based monitoring system.

Although the project is still under development, an electrical schematic, initial software, and demonstration materials are available to show the progress made. The next stages will focus on hardware integration and practical testing.

Developing this project provides an opportunity to improve knowledge of electrical control circuits, contactors, microcontroller programming, and industrial electrical system monitoring.
