# atas-controller
This is an Arduino supervisior for a simple Yaesu ATAS-100 / ATAS-120 
antenna controller

My Yaesu ATAS-100 died after a decade of exposure to road salt.  It
mostly completely ate away the aluminum body tube.  I replaced the
ATAS-100 with an ATAS-120 and fixed the ATAS-100 with a new aluminum
body tube.

This antenna works by placing either a +8V or +12V DC bias on the transmit
line.  +12V makes th antenna extend.  +8V makes the antenna retract.

I built a bias tee from the AD5X plans:

http://www.ad5x.com/images/Articles/BiasT3amp.pdf

...only one side is needed for the ATAS controller.

The controller is a simple center-off / momentary SPDT switch for
either +12 or a regulated +8.  But - I wanted some way to determine if
the antenna was at the end of travel or if there was an over-current
condition.

Normal current for raise or lower is around 200mA.  When the antenna
is at the end of travel / stalled, current is around 650mA.

The idea is to use a high-side DC current monitor, an INA219 that reports
back via I2C both voltage and current values.  A junkbox 1x16 LCD 
will report back up/down based on voltage and current values.



