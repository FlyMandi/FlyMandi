# Components of a Typical Desktop

## Case

Ah, the good old case. It used to have features like a 5.25" bay for floppy drives. Then, there were 3.5" bays for zip drives. Now, the front of the case is usually a glass panel for pretty points or a mesh panel for airflow. And otherwise, the cases are bogstandard pieces of Aluminium that are powder-coated and fit all the things y'could want. Standard fan mounts are 120mm and 140mm today and many cases have mounts for both.

## Motherboard

Here's a list of all the parts of a typical motherboard.

### Socket

The Motherboard Socket is where the CPU sits and depending on the configuration, it can have pins or pads in the CPU socket. If it has pins, there's usually an extra socket cover because it really needs it.

//TODO: Link PGA/LGA

### Headers

Headers are male connectors on a Motherboard that are used to connect all the interface from your other components to it. These include stuff like your case frontal I/O, fans, aRGB and more.

#### Fans

You can find at least two PWM 4-Pin headers on a normal motherboard, one for the CPU heatsink (aka cooler) fan, and the other for the case fan(s). On a not-bottom-of-the-barrell motherboard, you'll find one or two for CPU and three or more case fan headers. They're usually labelled with CPU_FAN and CHA_FAN. Sometimes You'll see CPU_OPT or a W_PUMP for a PWM pump, or CHA_FAN instead of SYS_FAN. There are no differences between these PWM connections, other than where they're situated, usually laid out for a semblance of cable management within the case.

#### RGB

There are two different possible RGB headers on a motherboard, 12V 5-Pin and 5V offset 3-Pin.

//TODO

#### Case I/O

//TODO

Useful to know is that the layout is now standardized and that because of this, you can locate this group of pins on the motherboard and as long as the power supply is plugged in, you can operate the power button by shorting the PWR_BTN+ and PWR_BTN- pins on the motherboard with a conductive material, such as a scredriver. Or in my case, a spark plug with a nut welded to it that's actually a bottle opener. Suprisingly handy, that. Useful to know is also the location of the CLR_CMOS pins, in the event that you need to clear your BIOS to its defaults quickly and/or often. You can use these same pins to wire them to your front I/O reset button, which is rarely used anyway, and that way you can reset to BIOS defaults without having to even open up your side panel.

## CPU

## Cooling

### Air Cooling

### Water Cooling

## GPU

## Storage

## PSU

# All-in-Ones

# Obscure and Notable Computers

## Dell Dimension

Also known as the 'Beefy Computer' from Counter-Strike: Source, the Dell Dimension was otherwise a bogstandard Office PC that many people probably commited tax fraud on.

//TODO: specs

![Dell Dimension, Picture 1](Dell_1.png)
![Dell Dimension, Picture 2](Dell_2.png)
![Dell Dimension, Picture 3](Dell_3.png)