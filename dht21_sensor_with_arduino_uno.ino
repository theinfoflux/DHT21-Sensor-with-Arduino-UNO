#include <DHT.h>;
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 3           
#define DHTTYPE DHT21       //DHT 21  (AM2301)
DHT dht(DHTPIN, DHTTYPE);   

float hum;  //Stores humidity value
float temp; //Stores temperature value

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Serial.begin(9600);
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  delay(10);
}

void loop()
{
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp= dht.readTemperature(); 
  //Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%,  Temperature: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print("T:"+String(temp));
  display.print((char)247);
  display.print("C");
  display.setTextSize(2);
  display.setCursor(0, 40);
  display.print("H:"+String(hum)+"%"); 
  display.display();
  delay(1000); 
}
