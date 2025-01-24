##Weather Station Project
This is a project for monitoring weather conditions using multiple sensors, developed to apply fundamental concepts of embedded systems programming and sensor integration.

#Features
Temperature and Humidity Monitoring:
Uses a DHT11 sensor to measure ambient temperature and humidity levels.

#Pressure and Altitude Calculation:
Utilizes the BMP280 sensor for atmospheric pressure measurement and altitude estimation based on sea-level pressure.

#Wind Speed Measurement:
Implements an anemometer to calculate wind speed in meters per second (m/s) using interrupts.

#Solar Incidence:
Employs an LDR (Light Dependent Resistor) to measure sunlight intensity as a percentage.

#LCD Display:
Displays key weather information (temperature, humidity, and wind speed) on a 16x2 LCD screen with I2C interface.

#Serial Communication:
Outputs detailed weather data (temperature, humidity, pressure, altitude, wind speed, and solar incidence) to the Serial Monitor for logging or debugging.

#Requirements
Arduino board (e.g., Uno, Mega)
Sensors:
DHT11 (temperature and humidity)
BMP280 (pressure and altitude)
Anemometer (wind speed)
LDR with a resistor (solar incidence)
LCD 16x2 with I2C module
Wires and breadboard for connections
Arduino IDE installed
#How to Run the Project
Clone the Repository:
Download the code to your local machine:
git clone https://github.com/your-username/Weather-Station.git
Open the Code in Arduino IDE:

Launch the Arduino IDE.
Open the file weather_station.ino.
Install Required Libraries:

Install the following libraries via the Arduino Library Manager:
Adafruit_Sensor
Adafruit_BMP280
DHT
LiquidCrystal_I2C
Upload the Code:

Select the appropriate board and port in the Arduino IDE.
Click "Upload" to flash the code to the Arduino board.
View the Output:

Connect the sensors and power up the Arduino.
Open the Serial Monitor (9600 baud) to view real-time weather data.
The LCD will display key metrics like temperature, humidity, and wind speed.
Project Structure
weather_station.ino: The main file containing the implementation of weather monitoring features.
Future Features
Wireless Connectivity:
Adding a Wi-Fi module (e.g., ESP8266) to send data to a cloud server or web interface.

Data Logging:
Storing weather data on an SD card for historical analysis.

Graphical User Interface (GUI):
Developing a web or mobile app to visualize weather data in real-time.

Expanded Sensor Suite:
Integration of additional sensors like rain gauges or CO2 meters for more comprehensive environmental monitoring.
