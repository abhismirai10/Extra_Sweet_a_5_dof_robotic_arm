# Extra Sweet - 3D Printed 5 DOF Robotic Arm with Teleoperation and Behavior Cloning

## Project Overview

This project aims to develop a low-cost, 3D-printed robotic arm that can be controlled via a teleoperation system. The primary objective is to collect data using the teleoperation setup and a RealSense camera, enabling behavior cloning for basic pick-and-place tasks. The system is designed to be affordable and accessible for hobbyists and researchers.

## [Video](https://youtu.be/Ar9KFWRWLPI?feature=shared)

## Images
![Screenshot 2024-06-09 at 7 16 42 PM](https://github.com/abhismirai10/Extra_Sweet_a_5_dof_robotic_arm/assets/121724635/3c96c35a-6c96-48cf-bad2-141b518839f3)
![Screenshot 2024-06-09 at 7 16 55 PM](https://github.com/abhismirai10/Extra_Sweet_a_5_dof_robotic_arm/assets/121724635/63f651cb-a280-4a0c-9e23-e406b4dbf9bf)

## Hardware Components

- **3D Printed Parts:** Custom-designed and 3D-printed components for the robotic arm and teleoperation system. (check design folder)
- **Servos:** 5 standard servos to control the robotic arm's joints.
- **Arduino:** Microcontroller for processing teleoperation commands and controlling the servos.
- **RealSense Camera:** Used for capturing visual data to aid in behavior cloning.
- **Developer PC:** For running computer vision algorithms and neural network models.
- **Position Encoders:** 5 encoders used in the teleoperation system to accurately capture operator movements.

## Software Components

### Arduino Control System

The Arduino microcontroller is programmed to receive position data from the teleoperation system's position encoders. It processes this data to control the servos of the robotic arm, ensuring smooth and precise movements.

### Data Collection and Behavior Cloning

Using the teleoperation system, data is collected through the RealSense camera, capturing both visual and positional information. This data is then used to train a neural network to mimic the demonstrated behaviors, enabling the robotic arm to perform tasks autonomously.

### Computer Vision and Neural Networks

The developer PC runs computer vision algorithms to process the visual data captured by the RealSense camera. Neural network models are trained using this data to replicate the teleoperated movements, allowing the robotic arm to perform basic pick-and-place tasks without direct human control.

## Getting Started

1. **Hardware Setup:**
   - Assemble the 3D printed parts to build the robotic arm and the teleoperation system.
   - Connect the servos to the Arduino as specified.
   - Set up the position encoders and integrate them into the teleoperation system.
   - Connect the RealSense camera and ensure it is properly configured with the developer PC.

2. **Software Installation:**
   - Upload the Arduino code to the microcontroller.
   - Install necessary drivers and libraries for the RealSense camera.
   - Set up the development environment on the PC for running computer vision and neural network training scripts.

3. **Data Collection:**
   - Use the teleoperation system to perform various tasks, capturing data with the RealSense camera.
   - Ensure data is stored in a format suitable for training the neural network.

4. **Training and Deployment:**
   - Train the neural network using the collected data to perform behavior cloning.
   - Deploy the trained model to control the robotic arm autonomously.

## Contributing

Contributions to this project are welcome. Feel free to fork the repository and submit pull requests. Please ensure your contributions are well-documented and tested.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

## Acknowledgements

- Special thanks to the open-source community for providing tools and resources.
- Gratitude to all contributors and testers who helped refine this project.

---

For more detailed instructions and code examples, please refer to the individual files in this repository.
