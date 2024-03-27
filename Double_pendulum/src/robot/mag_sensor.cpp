#include <Arduino.h>
#include <UMS3.h>
#include <SimpleFOC.h>

UMS3 ums3;

// instance of AS5600 sensor
MagneticSensorI2C sensor = MagneticSensorI2C(AS5600_I2C);


void setup() {
  // Initialize all board peripherals, call this first
  ums3.begin();
  
    // monitoring port
  Serial.begin(115200);

  // put your setup code here, to run once:
  sensor.init();
  ums3.setPixelBrightness(255 / 3);
  ums3.setPixelColor(UMS3::colorWheel(0));
  Serial.println("AS5600 ready");
  _delay(1000);
}

void loop() {
  sensor.update();
  // display the angle and the angular velocity to the terminal
  Serial.print(sensor.getAngle());
  Serial.print("\t");
  Serial.println(sensor.getVelocity());
}
