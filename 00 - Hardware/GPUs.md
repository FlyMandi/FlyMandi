# Graphics Processing Unit (GPU)

## Connectors

### AGP

### PCI

### PCIe

## Features

### Anti-Aliasing (AA)

#### FXAA

#### SMAA

#### TAA

## Anisotropic Filtering (AF)

### Ray-traced and Path-traced lighting

### Super-Sampling/Super-Resolution (XeSS/DLSS/FSR)

//TODO: where does it run? Cuda/tensor? etc

Intel's XeSS, NVIDIA's DLSS and AMD's FSR have become the go-to for enhancing framerates at a minimal quality loss for years now. In essence, the practice of upscaling is to render the game at a lesser resolution than desired, then taking that generated frame and upscaling it on the GPU itself to the output resolution. This occures through a Generative AI Deep Learning model that's been trained to the extent that it can, well, extend a frame to another resolution.

The closer the render resolution to the actual output, the better the image quality. There are differences between the way XeSS/DLSS/FSR operate, but the main difference is that DLSS is only available on specific, supported NVIDIA Graphics Cards, while AMD's FSR and Intel's equivalent are available on any compatible GPU (there's tons!). The scaling factors also vary between presets of the different technologies.

Due to the nature of the technology, Supersampling is usually incompatible with Anti-Aliasing, since it provides its own anti-aliasing by upscaling the image, which usually gets rid of any jagged lines on its own. There are, however, presets for these technologies that utilize the same Deep Learning Technology, but simply get rid of jagged lines. DLAA & FSR Native AA both render at 100% resolution, so in theory, no information is lost, as opposed to a lower render resolution.

### Frame Generation

Frame generation utilizes the same core technology as Supersampling, but in a completely different way. Instead of scaling down every frame and re-sizing it, frame generation takes already finished frames and fills in the gaps. So, in theory, if you were generating an in-between frame, every other frame, this would result in double the framerate. In practice, this technology takes some processing overhead, so you'll usually see about 1.5x to (maybe) _almost_ 2x the frames, probably. Frame generation is available from DLSS 3 and FSR 3 on, respectively. But, good news, there's nothing preventing you from using both Supersampling and Frame Generation at the same time. This way, achieving a 2x performance boost with little to no downsides is plausible.

Speaking of the downsides, Frame Generation is prone to, like any generative AI, hallucinate and not be entirely accurate

Note: the game itself has to support this technology and made it available to interface with the GPU. This means that Framegen is available on AAA titles, rather than indie games, but the AAA titles are where you'd really need those extra frames, since those games tend to be much harder to run.

### NVIDIA G-Sync and AMD Freesync

### NVIDIA's other gimmicks

#### PhysX

#### Hairworks

#### Gibs & Fluids