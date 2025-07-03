
<h1 align="center"><strong>🚦 Automatic Railway Gate Control System</strong></h1>

An embedded automation and safety project designed to minimize human errors and accidents at railway level crossings through a fully automatic, sensor-driven gate control mechanism using Arduino.

---

## 📌 Problem Statement

Traditional railway gate systems are mostly operated manually, especially in rural and semi-urban areas. These gates require personnel to be present for opening and closing at the right time based on the train’s arrival. This human-dependent process is prone to delay, misjudgment, or negligence — often resulting in severe accidents and fatalities.

According to Indian Railways data, in 2024, there were 313 deaths due to train accidents, with 335 additional fatalities recorded in early 2025 within the East Central Railway zone alone. Many of these were at unmanned or poorly operated level crossings.

This project aims to address that issue by building a cost-effective, efficient, and automatic railway gate control system that minimizes human involvement and enhances commuter safety.

---

## 🎯 Objectives

- Detect incoming and outgoing trains using **ultrasonic sensors**
- Automatically open and close the railway gate using **servo motors**
- Use **LEDs** to simulate traffic lights for visual cues
- Include a **buzzer** for auditory warning during gate operation
- Replace manual gate systems with low-cost automation
- Reduce the number of accidents at railway crossings
- Design the system for **low power consumption**, making it suitable for remote or rural areas
- Ensure scalability for future enhancements like cloud monitoring or GSM alerts

---

## 💡 Project Significance

The system enhances public safety by eliminating human error, one of the leading causes of railway crossing accidents. It is particularly effective in rural or semi-urban regions where resources and trained personnel are limited. By relying on real-time object detection and simple yet effective logic, the solution can be deployed widely with minimal infrastructure changes.

It also lays the groundwork for future improvements such as:
- Solar-powered operation
- IoT-based train tracking
- Mobile notifications and alerts for gate status

---

## 🧱 System Overview

### Input Devices:
- **Ultrasonic Sensor 1** (Placed at train entry point): Detects approaching train
- **Ultrasonic Sensor 2** (Placed at exit point): Detects when train has passed

### Controller:
- **Arduino Uno (ATmega328P)**: Core controller that processes sensor input and controls actuators

### Output Devices:
- **Servo Motors**: Simulate the physical gate
- **LEDs (Red, Yellow, Green)**: Act as traffic lights for road traffic
- **Buzzer**: Activates when gate is closing or during danger

### Flow of Operation:
1. Initially, the gate is open and the **green LED** is ON.
2. When Sensor 1 detects an object (train), the gate **automatically closes**, **red LED** turns ON, and **buzzer** alerts for 3 seconds.
3. Once Sensor 2 detects the train has passed, the gate **opens again**, and **green LED** resumes.

---

## 🔩 Hardware Components Used

| Component               | Quantity | Description                                |
|-------------------------|----------|--------------------------------------------|
| Arduino Uno             | 1        | Controls the logic and interfaces with components |
| Ultrasonic Sensor       | 2        | Detects approaching and leaving train      |
| SG90 Servo Motor        | 2        | Simulates gate movement                    |
| Passive Buzzer          | 1        | Alerts during gate operation               |                |
| Traffic Light Module    | 1        | Combines the LEDs into one signal          |
| Breadboard + Wires      | -        | Circuit assembly                           |
| 12V Adapter             | 1        | External power supply                      |
| Toy Train Model         | 1        | Demonstration purposes                     |

---

## 💻 Software Details

- **Programming Language**: Arduino C++
- **Platform**: Arduino IDE
- **Libraries Used**: `Servo.h`

### Code Logic:
```c
if (Sensor1 detects object) {
    close gate (servo at 90 degrees);
    turn ON red LED;
    activate buzzer;
}
if (Sensor2 detects object) {
    open gate (servo at 0 degrees);
    turn OFF red LED and buzzer;
    turn ON green LED;
}
```

---

## 📊 Performance and Results

The system was tested under multiple scenarios using a toy train and various object speeds.  
**Performance Highlights**:
- Train detection accuracy within ±1 cm
- Gate closes within 1.2 seconds of detection
- System resets within 2 seconds after train passes
- Real-time operation without delay
- 100% success rate in demo trials
- Low power consumption, making it ideal for solar integration

---
## 📁 Project Directory Structure

B.Tech-Final-Year-Project/
├── Certificate of Approval/
│   └── Certificate_of_Approval.jpg
│
├── Documentation/
│   ├── Project Report - Group.pdf
│   └── Project Report - Satyam.pdf
│
├── Project Images/
│   ├── Image 1.jpg
│   ├── Image 2.jpg
│   ├── Image 3.jpg
│   ├── Image 4.jpg
│   └── Image 5.jpg
│
├── Software/
│   └── Arduino IDE
│
├── Presentation/
│   ├── Automatic Railway Gate Control System.pptx
│   └── Automatic Railway Gate Control System.pdf
│
├── Working Video/
│   ├── Video 1.mp4
│   └── Video 2.mp4
│
├── Code Used/
│   └── Code/
│       └── Code.ino
│
└── README.md



## 📽️ Demonstration

You can view the project in action through the included video file located in the:
📁 `Working Video.mp4`  
This video shows real-time detection, gate closure, buzzer, and LED functionality.

---

## 🚀 Future Scope

- Add **GSM module** for message alerts to control room
- Integrate with **cloud platforms** (e.g., Firebase, AWS) for real-time analytics
- Support **mobile apps** for live status
- Add **camera module** for train recognition
- **Solar panel integration** for energy independence
- Build a **custom PCB** to reduce size and increase reliability

---

## 📄 Project Approval Certificate

This project was officially reviewed and approved as part of the B.Tech Final Year submission at  
**DAV Institute of Engineering and Technology, Daltonganj**, affiliated to **Jharkhand University of Technology, Ranchi**.

It carries the signatures of the following authorities:
- ✅ **External Expert** – *Mr. Ranjit Kumar*
- ✅ **Internal Expert** – *Mr. Suraj Pratap Saw*
- ✅ **Principal** – *Dr. Sanjeev Kumar Shrivastava*
- ✅ **Project Supervisor** – *Mr. Deepak (Assistant Professor, ECE)*
- ✅ **Head of Department (ECE)** – *Mr. Deepak*
---

## 👨‍💻 Team Members

| Name             | Roll Number     |
|------------------|-----------------|
| Satyam Kumar     | 21020460010     |
| Kanchan Kumar    | 21020460006     |
| Bhart Bharti     | 21020460002     |
| Chanda Kumari    | 21020460003     |

---

## 🙏 Acknowledgment

We would like to express our sincere gratitude to everyone who supported us throughout the successful completion of this project titled **"Automatic Railway Gate Control System"**.

First and foremost, we are extremely thankful to **Mr. Deepak Sir**, our project supervisor and Head of the Department (ECE), for his invaluable guidance, continuous support, and encouragement throughout the project. His insights and suggestions helped us to improve our work significantly.

We extend our heartfelt thanks to our **Principal**, **internal and external evaluators**, and all the respected **faculty members of the Department of Electronics and Communication Engineering** at **DAV Institute of Engineering and Technology, Daltonganj**, for providing us with the platform, resources, and confidence to carry out this project successfully.

We are also grateful to our fellow classmates, lab technicians, and friends for their encouragement, timely help, and moral support during the various phases of development.

Finally, we acknowledge the role of our families, who have always been our biggest motivators, for their unconditional support, patience, and encouragement throughout our academic journey.

This project would not have been possible without the collective effort and collaboration of all those mentioned above.

---


## 🏁 Conclusion

This project successfully demonstrates a working prototype of a **low-cost, fully automated railway gate system**. It proves that with minimal investment and components, safety can be drastically improved at railway level crossings. The project blends **practical electronics, automation, and embedded programming** to address a real-world problem.

---

## 🔗 Connect with Me

👤 **Satyam Kumar**  
🔗 [LinkedIn](https://www.linkedin.com/in/satyam-kumar-5a229222b)  
📧 *satyamkv123@gmail.com*  

---

## 📝 License

This project was created for academic purposes.  
It is open for personal, academic, and research use.  
Please credit the authors if reused or modified.

---
