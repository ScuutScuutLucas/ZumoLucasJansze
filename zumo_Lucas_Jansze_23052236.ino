#include <Wire.h>
#include <Zumo32U4.h>

// De Serial1 verbinding wordt hier verklaard naar xbee
#define xbee Serial1 

// Initalisatie van het 'buzzer' object
Zumo32U4Buzzer buzzer;

void setup() {
// Buzzer
  // Afspelen van een melodie op de buzzer
  buzzer.play(F("l8 cdefgab>c"));

  // Ledjes
  // Ledjes worden gedurende 1 seconden in geschakeld en daarna 1 seconde uitgeschakeld
  ledYellow(1);
  delay(1000);
  ledYellow(0);
  delay(1000);
  ledYellow(1);
  delay(1000);
  ledYellow(0);
  delay(1000);
  ledYellow(1);
  delay(1000);
  ledYellow(0);

}

void loop() {


// Batterij sensor
  // Controleren of er USB-stroom aanwezig is
  bool usbPower = usbPowerPresent();

  // Lezen van het batterijniveau in millivolt
  uint16_t batteryLevel = readBatteryMillivolts();

// Xbee
  // Afdrukken van USB-Stroomstatus
  xbee.print(F("USB="));
  // Afdrukken 'Y' als er USB-strooms aanwezig is, anders 'N'
  xbee.print(usbPower ? 'Y' : 'N');
  // Afdrukken van batterijniveau label
  xbee.print(F(" B="));
  // Afdrukken van het batterijniveau
  xbee.print(batteryLevel);
  // Afdrukken van de eenheid (millivolt)
  xbee.println(F(" mV"));

  // 2 seconden delay voordat de bovenstaande loop code opnieuw wordt uitgevoerd
  delay(2000);

}