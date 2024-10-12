# Types of connections

## Electrical

## Optical

# Data Interfaces

Technically, (almost) all of these interfaces transmit Data. But, when somebody says "Data Bus" they probably mean Multi-Purpose interfaces like the ones used by peripheral devices like the keyboard and mouse you're using to navigate this very page.

## Serial Port

## Parallel Port

## PS2

## USB

Aptly named "Universal Serial Bus"...

Their naming sucks. USB 3.0 Gen 1, etc.

### USB Type A

### USB Type B

USB Type B is mostly found on audio interfaces, MIDI controllers and other Digital Instruments.

### USB Type C

### Micro-USB

### Micro-USB Type B

### USB Type E

## SATA

## IDE

## PCIe

### AIC

### NVMe

#### M.2

#### U.2

#### U.3

#### ESDFF

### NVMe-oF

## Ethernet

Ethernet, also known as IEEE 802.3, is the standard interface for connecting computers to a Local Area Network (LAN) through cable.

### RJ45 and CAT Cables

//TODO

### Ethernet Speeds:
| IEEE Spec | Cable  | Max. Data Rate | Bandwidth |
| --- | ---   | ---       | ---       |
| - | CAT-1 | 1 Mb/s    | 0.4 MHz   | 
| - | CAT-2 | 4 Mb/s    | 4 MHz     |
| - | CAT-3 | 10 Mb/s   | 16 MHz    |
| - | CAT-4 | 16 Mb/s   | 20 MHz    |
| IEEE 802.3u | CAT-5 | 100 Mb/s  | 100 MHz   |
| IEEE 802.3u | CAT-5e| 1 Gb/s  | 100 MHz     |
| IEEE 802.3an | CAT-6 | 1 Gb/s | 250 MHz      |
| IEEE 802.3an | CAT-6a | 10 Gb/s | 500 MHz    |
| IEEE 802.3an | CAT-7 | 10 Gb/s | 600 MHz     |
| IEEE 802.3an | CAT-7a | 10 Gb/s | 1000 MHz   |
| IEEE 802.3bq | CAT-8.1 | 25 Gb/s | 2000 MHz  |
| IEEE 802.3bq | CAT-8.2 | 40 Gb/s | 2000 MHz  |

CAT-8.2 doesn't use RJ45 anymore, but a particular, high-speed connector.

//TODO: expand

### PoE
There is also another use for Ethernet, and that's PoE. No, not the ARPG. Power over Ethernet. This connection is especially useful since some Ethernet cables can easily be more than 100 metres long, and that's only the cut-off for data loss reasons, so with PoE, since you're only putting power through the pins, you can go much higher. You do lose power, so the power drawn vs. power received by the device isn't the same, and at times not even close.

| IEEE Spec       | Max. Power Draw | Max. Power to Device |
| ---             | ---             | --- |
| 802.3af         | 15.4 W          | 12.95 W |
| 802.3at         | 30 W            | 25.5 W |
| 802.3bt, Type 3 | 60 W            | 51 W |
| 802.3bt, Type 4 | 100 W           | 71 W |

CAT-5 or higher cables are required to utilize PoE. Technically, even 802.3bt can use CAT-5 cabling, but all PoE standards benefit from higher CAT standards like CAT-7 for a better output with less interference. 

If you ever need to power a security camera that's an awfully long distance away from the next power source, you can use PoE. There are other uses, now that you can get more power out of PoE, such as PoE LED lighting and higher resolution cameras with cooling built-in.

## WLAN vs. Wi-Fi

Known as 802.11, WLAN for us germans or Wi-Fi for everybody else.

//TODO

### Wi-Fi Speeds
| IEEE Spec | Name | Theoretical Max. Link Speed | Frequency  |
| ---       | ---  | ---            | ---        |
| 802.11    | Wi-Fi 0 | 2 Mb/s | 2.4 GHz |
| 802.11b    | Wi-Fi 1 | 11 Mb/s | 2.4 GHz |
| 802.11a    | Wi-Fi 2 | 54 Mb/s | 5 GHz |
| 802.11g    | Wi-Fi 3 | 54 Mb/s | 2.4 GHz |
| 802.11n    | Wi-Fi 4 | 600 Mb/s | 2.4 GHz, 5 GHz |
| 802.11ac    | Wi-Fi 5 | 6.9 Gb/s | 2.4 GHz, 5 GHz |
| 802.11ax    | Wi-Fi 6 | 9.6 Gb/s | 2.4 GHz, 5 GHz |
| 802.11ax    | Wi-Fi 6e | 9.6 Gb/s | 2.4 GHz, 5 GHz, 6 GHz |
| 802.11be    | Wi-Fi 7 | 23 Gb/s | 2.4 GHz, 5 GHz, 6 GHz |


# Video

## Composite/RCA/coaxial

## DVI

## VGA

## HDMI

## DisplayPort

# Audio

## 3.5mm

## 6.35mm

## XLR