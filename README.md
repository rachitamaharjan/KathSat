# Background
A CanSat is a miniature satellite, roughly the size of a soda can, designed to mimic the key functions of a spacecraft (equipped with sensors to measure environmental conditions) in a small, cost-effective format. It provides a practical way to learn about satellite development, covering design, construction, and launch principles.

They also include onboard systems for data collection, processing, and transmission, making them a valuable tool for testing space-related technologies on a smaller scale.

KathSat is an Arduino-driven CanSat designed on a PCB containing environmental sensors like pressure, humidity, altitude, acceleration, gyroscope and wireless communication modules interfaced using SPI, UART, and I2C communications. 

The KathSat was dropped from 150 meters via octocopter and a robot equipped with a robotic arm retrieved it and carried it to the extraction zone.

# Overview
This CanSat was developed for a National Competition (Aavishkar CanSat Competition) with the objective of simulating a Lunar Exploration Mission.

## Why was it Designed?
Measure environmental conditions such as temperature, atmospheric pressure, and humidity to assess the characteristics of an unfamiliar location.
Record acceleration and altitude during descent to analyze landing dynamics.

## What were its Subsystems?
- Payload System – Carried scientific instruments for data collection.
- Electrical Power System – Supplied energy for all onboard components.
- Structural System – Provided a protective frame for the CanSat.
- Communication System – Enabled data exchange with the ground station and rover.
- On-Board Computer – Processed sensor data and managed operations.

## What sensors were integrated?
To accomplish its mission, the CanSat was equipped with the following sensors and modules:

- Adafruit BMP085 – Measures atmospheric pressure, essential for altitude estimation.
- Real-Time Clock (DS3231 RTC) – Provides precise timekeeping for data logging.
- Temperature & Humidity (DHT11) – Records temperature and humidity levels.
- MPU6050 – Integrates an accelerometer and gyroscope for motion and orientation tracking.
- SD Card Module – Stores collected data for later analysis.
- Arduino Uno – Acts as the primary microcontroller, processing sensor data and managing communication.
  
# Mission Objectives
The mission was divided into two phases:

## Data Collection & Descent Monitoring
The CanSat was deployed/released from a hexacopter mid-flight. During descent, it continuously measured altitude, acceleration, and environmental conditions to study its landing behavior.

## Post-Landing Analysis & Rover Communication
Once landed, the CanSat assessed the safety of the environment using temperature, pressure, and humidity data.
If the data confirmed a safe landing site, the rover transported the CanSat to a designated retrieval point, simulating an extraterrestrial exploration mission.

### Some images:

Launch            |  Extraction
:-------------------------:|:-------------------------:
![one](https://user-images.githubusercontent.com/28466502/94254171-1c8cbb00-ff46-11ea-9c40-309eabd6e27c.gif)  |  ![two](https://user-images.githubusercontent.com/28466502/94254651-cf5d1900-ff46-11ea-9141-f1a143d21246.gif)

| Team | Event |
|--|--|
|<img width="1024" height="768" alt="IMG_9573" src="https://github.com/user-attachments/assets/ced89dc2-a2c0-4f36-9003-eb19a5d54887" />|<img width="960" height="720" alt="img" src="https://github.com/user-attachments/assets/cd2bf3c1-5bd5-4bef-9ef5-a73f5c7aa1f1" />|

