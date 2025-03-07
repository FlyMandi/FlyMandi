## Backface Culling

When drawing a triangle, the order of specified vertices (points that make up the triangle) determines whether we're 
looking at the front or back of it. Since most (if not all) meshes are not a flat, 0-width plane, we can use Backface Culling
to just not draw the triangle if we're looking at the wrong side. In more practical terms, when looking at a player character,
only the faces (triangles) that make up the side we're looking at should be drawn, not the ones that are invisible (duh).
The order of vertices drawn determines whether the face will be culled or not, and that same order can be altered by the
viewport; because of course, walking around to the other side of the character would present... the other side.

