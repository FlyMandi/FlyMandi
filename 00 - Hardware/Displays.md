# Modern Display Basics

//TODO

## Pixels

//TODO

### RGB

//TODO

## Resolution

Display Resolution, or Pixel Count, can be understood as the canvas size for a Display. In most cases, Displays have a fixed place for each pixel, physically. 

### Display resolutions and names

Resolutions are usually called by their vertical pixel count. '480p', for example. The problem with this approach is that '480p' can either mean 640x480, which has an aspect ratio of 4:3, or 854x480, its 16:9 equivalent. They can also be called 'SD' or 'Standard Definition', as if it wasn't confusing enough. So, for example, 'SD Widescreen' is the same as '480p 16:9'.

Here's a fairly exhaustive list of Display Resolutions:

- `4:3` Aspect Ratio:
    - `160x120`, other names: QQVGA or Quarter Quarter VGA;
    - `320x240`, other names: QVGA or Quarter VGA;
    - `480x320`, other names: HVGA or Half-size VGA; The first iPhone used this resolution.
    - `640x480`, other names: VGA, SD, Standard Definition; that name stems from the [VGA](../00%20-%20Hardware/Interfaces.md#VGA) Standard Resolution.
    - `800x600`, other names: SVGA or Super VGA;
    - `1024x768`, other names: XGA or eXtended Graphics Array; 
    - `1152x864`, other names: XGA+ or eXtended Graphics Array Plus;
    - `2048x1536`, other names: QXGA or Quad XGA;
    - `3200x2400`, other names: QUXGA or Quad Ultra XGA;


- `16:9` Aspect Ratio, other names: Widescreen:
    - `256x144`, other names: 144p; Youtube's lowest supported [transcode](../01%20-%20BIOS%20&%20OS/File%20Types.md#transcoding) resolution.
    - `320x240`, other names: 240p;
    - `640x360`, other names: 360p;
    - `854x480`, other names: 480p, SD or Standard Definition; The Widescreen VGA equivalent.
    - `960x540`, other names: qHD or quarter HD;
    - `1280x720`, other names: 720p, HD or High Definition; The most common resolution in the late 2000s.
    - `1366x768`, sometimes called 768p; The 16:9 XGA equivalent; Still found in some not-that-old budget laptops, like the 2015 Acer Aspire 3 (that I happen to own, lol).
    - `1920x1080`, other names: 1080p, FHD or Full HD; the most common resolution throughout the 2010s.
    - `2560x1440`, other names: 1440p, QHD or Quad HD; exactly 4x the size of HD and 100x the size of 144p. Sometimes called 'WQHD' just to distinguish from qHD.
    - `3840x2160`, other names: 2160p, 4K UHD, 4K; 4x the size of 1080p and our infamous, very well known 4K. Known for many as 'the last resolution we'll ever need', but I'm sure that'll age just as well as the infamous [Bill Gates line](https://quoteinvestigator.com/2011/09/08/640k-enough/).
    - `7680x4320`, other names: 8K UHD; Used for tech demos and insane projects like [these](https://www.holoxica.com/looking-glass-8k-gen2), but I'm sure that'll change in a couple generations of hardware.
    - `15360x8640`, other names: 16K UHD; there are very few 16K-capable devices, let alone videos or similar media in this resolution.

Other notable Aspect Ratios include `32:9`, sometimes `21:9`, both commonly called 'Ultrawide' and `1:1`, a square aspect ratios found rarely on any type of monitor, but sometimes.

## Image Refresh

Now, a Display doesn't just display a static image. Unless it's a Digital Signage exclusive, in which case, fair enough. In any other case, the image needs to be refreshed a certain amount of times per second, measured in Hz. 1Hz is 1 time every second, 60Hz is 60 times a second. This measured by how often the image on screen is refreshed, not how many full frames are shown in a second, which is an important distinction when talking about Progressive vs. Interlaced Scan signals.

### Progressive Scan vs. Interlaced Scan

The difference between 1080p and 1080i is not that the 'p' in '1080p' stands for the word 'pixels', but rather 'Progressive Scan'. What this means, is that the image is fully rendered for every frame. The image (usually) still has scanlines, but it's shown and rendered in full.

'Interlaced Scan' on the other hand, refers to the technique of showing the image in sequences of scanlines that alternate between each other, rather than all at once. If every scanline was numbered, frame #1 would only show the evenly numbered scanlines and frame #2 only the odd ones. Having to only refresh half of the image, Interlacing was mainly used on CRTs with analog video signals in order to save on bandwidth.

![Interlacing Shown](CRT_Scanlines.gif)[^1]

The above GIF shows interlacing in action. For a Progressive Scan signal, you can imagine the same scanlines, but the Scan proceeding from top to bottom _without_ skipping every other line, for every refreshed image.

Not applying the proper techniques to de-interlace an interlaced signal can lead to artifacting and ghosting, such as follows.

![Ghosting on a Car Wheel](CRT_Scanlines_artifacting.jpg)[^2]

You can very easily see the scanlines in action, two different frames being displayed at once. The lower the overall framerate, the worse this artifacting, since the distance between frames is likely higher.

# Display Types

## CRT

Cathode Ray Tube (CRT) Technology is //TODO
CRTs don't have a native res!!

## LCD

//TODO

### TN

//TODO

### IPS

//TODO

### VA

//TODO

## OLED

//TODO

### QD-OLED

//TODO

### wOLED

//TODO

# Display Technologies

## HDR

High Dynamic Range (HDR) is a technology that makes it possible to have an image *pop*, by achieving very deep blacks (or completely turned off pixels) and very bright Highlights, one next to another, if needed. HDR was not needed for a CRT, since CRTs can just choose not to illuminate a pixel, so their percieved Dynamic Range was already high from the get-go. They can't quite compare to a modern wOLED panel though, because CRTs just don't get bright enough (usually around a couple hundred nits at most).

## Local Dimming Zones

//TODO

## Motion Smoothing

//TODO

# Connections

//TODO

## Other Display Transmission Methods

Wireless, etc. //TODO

[^1]: Laserlicht, CC BY-SA 4.0 <https://creativecommons.org/licenses/by-sa/4.0>, via Wikimedia Commons
[^2]: This work has been released into the public domain by its author, Mikus at English Wikipedia. [More info.](https://en.wikipedia.org/w/index.php?title=File:Interlaced_video_frame_%28car_wheel%29.jpg)