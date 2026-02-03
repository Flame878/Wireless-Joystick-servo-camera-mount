# Wireless-Joystick-servo-camera-mount
Wireless joystick controlled camera mount using Arduino , NRF24L01 and Servo motor

# Wireless Joystick-Controlled Camera Mount

-- Overview --
This project is a wireless camera mount system controlled using a joystick. 
Joystick input is transmitted via NRF24L01 RF modules to a receiver Arduino, 
which controls a servo motor to rotate a phone-mounted camera platform.

-- Features --
- Wireless RF communication
- Joystick-based servo control
- External power delivery for servo motor
- Power integrity and brown-out mitigation
- Modular transmitter/receiver architecture

-- Hardware Used --
- Arduino Nano (Transmitter & Receiver)
- NRF24L01 RF Modules
- Joystick Module
- Servo Motor
- External USB Power Bank
- Decoupling Capacitors
- Breadboard and jumper wires

-- System Architecture --
- Transmitter Arduino reads joystick input
- Joystick data sent wirelessly via NRF24L01
- Receiver Arduino maps data to servo angle
- Servo powered externally to prevent brown-out resets
- Common ground shared across all components

-- Key Engineering Challenges Solved --
- RF communication debugging and validation
- Power bank auto-shutoff mitigation
- Servo-induced brown-out resets
- Ground reference stabilization
- PWM signal control over wireless link

-- Future Improvements --
- Add second axis (pan/tilt)
- Implement dead-zone filtering
- Enclosure design
- Battery voltage monitoring
