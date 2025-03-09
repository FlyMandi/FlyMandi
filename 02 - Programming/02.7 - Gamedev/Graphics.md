## Anti-Aliasing

Anti-Aliasing (AA) is needed to get rid of jagged edges. We all know that. But why are edges jagged in the first place?
Well, when drawing a face, we're defining an area of pixels to be drawn in a certain way, in a certain colour. But also
not really, because what we're actually defining is a list of vertices (points), that then get traced together, depending
on how they are interpreted, to form a set of edges that then make up a face. In the case of the triangle, there's 3 vertices
and 3 edges. Now, before the proper pixels can be drawn, a decision is made upon whether the pixel is considered _in_ or _out_
of the face. This is, for example in an API like Vulkan, defined by whether the centre of the pixel lies above or below that edge.
In a diagonal line, this creates a staircase effect because there's a lot of pixels that might have say, their lower left
corner in the face and should be drawn, but we can't draw anything smaller than a pixel. So, enter Anti-Aliasing.

### MSAA

Multi-Sample AA (MSAA) would break up a pixel into subpixel areas, sampling it multiple times. Those samples would then
determine an alpha (transparency) coefficient with which to shade that pixel, so the staircase-effect now has a bit of 
shading around it, but with high enough pixel count and from far enough away (which is kinda what ppi is) it looks good 
enough.

## V-Sync

The simple principle behind V-sync is waiting for the frame that's to be drawn next to be completely finished drawing
before actually drawing it on screen. But, we don't do that by asynchronously displaying the frame whenever it's done, but
by updating the frame (swapping framebuffers in the swapchain) every set interval, usually tied to your monitor refresh
rate. So, for a 60Hz Display, you will get a 60fps V-sync. Sometimes when you have a multiple, like 120Hz or 240Hz, you will
get the option of using that same refresh rate, but also half of it, in this case 60Hz or 120Hz, respectively. Not using 
V-Sync has the benefit of keeping the GPU occupied and drawing the frames as fast as possible to the screen, but since
we're drawing the frame line by line, if the framerate is low enough and the movement on screen is fast enough, you may 
encounter tearing. Not using V-Sync also comes with the added benefit of reduced input lag. Something like V-Sync triple 
buffering eliminates the issue of not occupying the GPU, since we're calculating more frames in advance, but we're still
limiting the frames themselves to update only as fast as the display and input lag is unchanged, ever present.
