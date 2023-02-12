//Een Infrarood afstandsbediening

/*KEYES IR afstandsbediening.
*/

#include <IRremote.hpp>

const int RECV_PIN = 7; // the pin where you connect the output pin of TSOP4838

// Define KEYES keyvalues
#define KEYES_Up 25245
#define KEYES_Left 0xFF22DD
#define KEYES_Ok 0xFF02FD
#define KEYES_Right 0xFFC23D
#define KEYES_Down 0xFFA857
#define KEYES_1 0xFF6897
#define KEYES_2 0xFF9867
#define KEYES_3 0xFFB04F
#define KEYES_4 0xFF30CF
#define KEYES_5 0xFF18E7
#define KEYES_6 0xFF7A85
#define KEYES_7 0xFF10EF
#define KEYES_8 0xFF38C7
#define KEYES_9 0xFF5AA5
#define KEYES_Asterix 0xFF42BD
#define KEYES_0 0xFF4AB5
#define KEYES_Hekje 0xFF52AD


void setup()
{
  Serial.begin(9600);   // you can comment this line
  Serial.println("Start IR ontvangst");
  IrReceiver.begin(RECV_PIN, DISABLE_LED_FEEDBACK);  // Start the receiver
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned int value = IrReceiver.decodedIRData.decodedRawData;
    switch (value) {
      case (KEYES_Up):
        Serial.println("KEYESRemote Up");
        break;
      case KEYES_Left:
        Serial.println("KEYESRemote Left");
        break;
      case KEYES_Ok:
        Serial.println("KEYESRemote OK");
        break;
      case KEYES_Right:
        Serial.println("KEYESRemote Right");
        break;
      case KEYES_Down:
        Serial.println("KEYESRemote Down");
        break;
      case KEYES_1:
        Serial.println("KEYESRemote 1");
        break;
      case KEYES_2:
        Serial.println("KEYESRemote 2");
        break;
      case KEYES_3:
        Serial.println("KEYESRemote 3");
        break;
      case KEYES_4:
        Serial.println("KEYESRemote 4");
        break;
      case KEYES_5:
        Serial.println("KEYESRemote 5");
        break;
      case KEYES_6:
        Serial.println("KEYESRemote 6");
        break;
      case KEYES_7:
        Serial.println("KEYESRemote 7");
        break;
      case KEYES_8:
        Serial.println("KEYESRemote 8");
        break;
      case KEYES_9:
        Serial.println("KEYESRemote 9");
        break;
      case KEYES_Asterix:
        Serial.println("KEYESRemote *");
        break;
      case KEYES_0:
        Serial.println("KEYESRemote 0");
        break;
      case KEYES_Hekje:
        Serial.println("KEYESRemote #");
        break;
      default: // Als de toets of de afstandsbediening onbekend is
        Serial.print("Unknown key: ");
        Serial.println(value);
        break;
    }
    IrReceiver.resume(); // Receive the next value
  }
}
