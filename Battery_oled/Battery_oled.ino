#include "U8glib.h"

U8GLIB_SSD1306_ADAFRUIT_128X64 u8g(9, 10, 15, 14);  // SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
  u8g.drawFrame(99,0,27,10);
  u8g.drawBox(101,2,23,6);
  u8g.drawBox(126,3,2,4);

}

void setup(void) {

  u8g.getMode() == U8G_MODE_BW; 
    u8g.setColorIndex(1);         // pixel on
  }
void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(50);
}
