#include "Watchy_DOS.h"
#include <Watchy.h>

WatchyDOS::WatchyDOS(){} //constructor

void WatchyDOS::drawWatchFace(){

  if(currentTime.Hour == 00 && currentTime.Minute == 00) {
        sensor.resetStepCounter();
  }
   
    char time[6];
    time[0] = '0' + ((currentTime.Hour/10)%10);
    time[1] = '0' + (currentTime.Hour%10); 
    time[2] = ':';
    time[3] = '0' + ((currentTime.Minute/10)%10);
    time[4] = '0' + (currentTime.Minute%10); 
    time[5] = 0;
    display.fillScreen(GxEPD_BLACK);
    display.setTextColor(GxEPD_WHITE);
    display.setFont(&Px437_IBM_BIOS5pt7b);
    display.setCursor(0, 24);
    display.print(" HAPPY-DOS ");
    display.println(getBatteryVoltage());
    display.println(" Copyright (c) 2021");
    display.println(" ");
    display.print(" WRITE  EXE ");
    display.println(time);
    display.print(" SLEEP  COM ");
    display.println(time);
    display.print(" COFFEE SYS ");
    display.println(time);
    display.print(" DREAM  PY  ");
    display.println(time);
    display.println(" ");
    display.print("  ");
    display.print(currentTime.Month);
    display.print(" files ");
    display.print(currentTime.Day);
    display.println(" bytes");
    display.print("  ");
    display.print(sensor.getCounter());
    display.println(" bytes free");
    display.println(" ");
    display.print(" <C:\\>");
    display.print(dayStr(currentTime.Wday));
    display.println(".exe");
}
