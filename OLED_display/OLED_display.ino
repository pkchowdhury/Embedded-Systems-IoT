#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(-1);

void text()
{
    // Display Text
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,28);
  display.println("Hello!");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void invertedText()
{
  // Display Inverted Text
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.setCursor(0,28);
  display.println("Hello world!");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void fontChange()
{
    // Changing Font Size
  display.setTextColor(WHITE);
  display.setCursor(0,24);
  display.setTextSize(2);
  display.println("Hello!");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void disNumber()
{
    // Display Numbers
  display.setTextSize(1);
  display.setCursor(0,28);
  display.println(123456789);
  display.display();
  delay(2000);
  display.clearDisplay();
}

void disHex()
{
    // Specifying Base For Numbers
  display.setCursor(0,28);
  display.print("0x"); display.print(0xFF, HEX); 
  display.print("(HEX) = ");
  display.print(0xFF, DEC);
  display.println("(DEC)"); 
  display.display();
  delay(2000);
  display.clearDisplay();
}

void disAscii()
{
    // Display ASCII Characters
  display.setCursor(0,24);
  display.setTextSize(15);
  display.write(3);
  display.display();
  delay(2000);
  display.clearDisplay();
}

void disFullscr()
{
  
  // Scroll full screen
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("Full");
  display.println("screen");
  display.println("scrolling!");
  display.display();
  display.startscrollright(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);    
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  display.clearDisplay();
}

void scrollpart()
{
    // Scroll part of the screen
  display.setCursor(0,0);
  display.setTextSize(2);
  display.println("Hello!");
  display.println("World");
  //display.println("of the screen.");
  display.display();
  display.startscrollright(0x00, 0x00);
  display.clearDisplay();
}

void setup()   
{                
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

  // Clear the buffer.
  display.clearDisplay();

}

void loop()
{
  text();
  delay(200);
  invertedText();
  delay(200);
  fontChange();
  delay(200);
  disNumber();
  delay(200);
  disHex();
  delay(200);
  disAscii();
  delay(200);
  disFullscr();
  delay(200);
  scrollpart();
  delay(200);
    
}
