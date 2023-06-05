void gpsInit();
#include <TinyGPSPlus.h>

void getLocation();
static void smartDelay(unsigned long ms);
static void printInt(unsigned long val, bool valid, int len);
static void printStr(const char *str, int len);
static void printFloat(float val, bool valid, int len, int prec);
static void printDateTime(TinyGPSDate &d, TinyGPSTime &t);