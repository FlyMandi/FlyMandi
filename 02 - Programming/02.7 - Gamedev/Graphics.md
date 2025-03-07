## Anti-Aliasing

Anti-Aliasing (AA) is needed to get rid of jagged edges. We all know that. But why are edges jagged in the first place?
Well, when drawing a face, we're defining an area of pixels to be drawn in a certain way, in a certain colour. But also
not really, because what we're actually defining is a list of vertices (points), that then get traced together, depending
on how they are interpreted, to form a set of edges that then make up a face. In the case of the triangle, there's 3 vertices
and 3 edges. Now, before the proper pixels can be drawn, a decision is made upon whether the pixel is considered _in_ or _out_
of the face. This is, for example in an API like Vulkan, defined by whether the centre of the pixel lies above or below that edge.
In a diagonal line, this creates a staircase effect because there's a lot of pixels that might have say, their lower left
corner in the face and should be drawn, but we can't draw anything smaller than a pixel (sorta kinda maybe, not yet). So,
enter Anti-Aliasing.

### MSAA

Multi-Sample AA (MSAA) would break up a pixel into subpixel areas, sampling it multiple times. Those samples would then
determine an alpha (transparency) coefficient with which to shade that pixel, so the staircase-effect now has a bit of 
shading around it, but with high enough pixel count and from far enough away (which is kinda what ppi is) it looks good 
enough.
