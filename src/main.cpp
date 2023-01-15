#include <main.h>

ESP32Timer ITimer(1);
ESP32_PWM ISR_PWM;

bool IRAM_ATTR TimerHandler(void *timerNo)
{
    ISR_PWM.run();

    return true;
}

void DisplayText(float timeSeconds, String line0, String line1, String line2, String line3, String line4, String line5)
{
    if (!_displayEnabledAndFound)
    {
        return;
    }

    Display.clearDisplay();
    Display.setTextSize(1);
    Display.setTextColor(WHITE);

    Display.setCursor(0, 0);
    Display.println(line0);

    Display.setCursor(0, 10);
    Display.println(line1);

    Display.setCursor(0, 20);
    Display.println(line2);

    Display.setCursor(0, 30);
    Display.println(line3);

    Display.setCursor(0, 40);
    Display.println(line4);

    Display.setCursor(0, 50);
    Display.println(line5);


    Display.display();

    delay(1000 * timeSeconds);

}

// format for control:
// start byte is security. end byte is security. 2nd byte is heartbeat.
// 6 pairs, frequency (1hz to 256hz) and duration (0ms to 1024ms), in bytes
//[secbyte][heartbeat4][heartbeat3][heartbeat2][heartbeat1][freq0][dur0][freq1][dur1][freq2][dur2][freq3][dur3][freq4][dur4][freq5][dur5][secbyte]

void InitializeDisplay()
{
    if (!Display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        _displayEnabledAndFound = false;

        Serial.println("no display");
    }
    else
    {
        DisplayText(1, "45654645");
        _displayEnabledAndFound = true;

        _line0 = "";
        _line1 = "";
        _line2 = "";
        _line3 = "";
        _line4 = "";
        _line5 = "";

        Serial.println("found display");
    }
    
    
}

void setup()
{
// write your initialization code here
    Serial.begin(115200);

    delay(1000);

    Wire.begin();

    delay(1000);
    
    InitializeDisplay();

    // Interval in microsecs
    if (ITimer.attachInterruptInterval(HW_TIMER_INTERVAL_US, TimerHandler))
    {
        startMicros = micros();
    }

    // not 5, 14, or 15

    // safe: PIN_D25, PIN_D12, PIN_D16, PIN_D17, PIN_D18, PIN_D19

    pinMode(PIN_GREY, OUTPUT);
    pinMode(PIN_ORANGE, OUTPUT);
    pinMode(PIN_YELLOW, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_PURPLE, OUTPUT);

    ISR_PWM.setPWM(PIN_GREY, 2.083333, 4);
    ISR_PWM.setPWM(PIN_ORANGE, 4, 8);
    ISR_PWM.setPWM(PIN_YELLOW, 8, 16);
    ISR_PWM.setPWM(PIN_GREEN, 16, 32);
    ISR_PWM.setPWM(PIN_BLUE, 32, 50);
    ISR_PWM.setPWM(PIN_PURPLE, 64, 50);

    pinMode(PIN_D2, OUTPUT);


}

void loop()
{
    DisplayText(1, String(micros()));
    /*
    if(millis()%2000 > 1000)
    {
        ISR_PWM.enableAll();
    }
    else
    {
        ISR_PWM.disableAll();
    }
     */
// write your code here
    /*
    if(millis()%2000 > 1000)
    {
        Serial.print("on");
        
        digitalWrite(PIN_D2, HIGH);   // turn the LED on (HIGH is the voltage level)

        ISR_PWM.enable(PIN_D15);
        ISR_PWM.enable(PIN_D4);
        ISR_PWM.enable(PIN_D5);
        ISR_PWM.enable(PIN_D12);
        ISR_PWM.enable(PIN_D13);
        ISR_PWM.enable(PIN_D14);
        
        ISR_PWM.setPWM(PIN_D15, 4, 50);
        ISR_PWM.setPWM(PIN_D4, 4, 50);
        ISR_PWM.setPWM(PIN_D5, 4, 50);
        ISR_PWM.setPWM(PIN_D12, 4, 50);
        ISR_PWM.setPWM(PIN_D13, 4, 50);
        ISR_PWM.setPWM(PIN_D14, 4, 50);
    }
    else
    {
        Serial.print("off");


        digitalWrite(PIN_D2, LOW);    // turn the LED off by making the voltage LOW

        ISR_PWM.disable(PIN_D15);
        ISR_PWM.disable(PIN_D4);
        ISR_PWM.disable(PIN_D5);
        ISR_PWM.disable(PIN_D12);
        ISR_PWM.disable(PIN_D13);
        ISR_PWM.disable(PIN_D14);
    }
     */
}