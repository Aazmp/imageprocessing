imageprocessing
===============

Set of image processing algorithms like canny, histogram equalization, graph segmentation, etc with simple Qt-based interface.

Some algorithms are very common and written exactly according to wikipedia.
Some details made up.
Graph based segmentation algorithms are based on http://cs.brown.edu/~pff/segment/
Gradient vector flow is based on http://www.iacl.ece.jhu.edu/static/gvf/
DCT based on VP8 spec: webmproject.org

Interface is made from Qt Widgets and Layouts, no xml-resources.
All algorithms are packed by themes in classes (GVF and simple gradient, for example, in same class "gradients")
Each class has some slots for updating different coefficients like "update_XXX(const QString&)"
and for applying image processing "apply_XXX()". 
Also each image processing class has a pointer to source image "QImage *srcImage" and rpcessed image "QImage *dstImage".
These QImages must be created outside of processing classes and their pointers must be told to constructors of image processing classes (done in main.cpp -> int main(argc argv)). 
Class "image_interface" holds pointers to QImages(that contain original and processed pictures) and QLabels(widgets that will display corresponding QImages on updateSrcImage/updateDstImage calls);

Each apply_XXX() method(slot)  takes data from *srcImage processes it and puts into *dstImage.
It also emits signals:
image_ready() -> when finished;
print_message(const QString&) -> some messages to put them in graphical widgets instead of std streams
print_progress(const int) -> progress with 0 - the very start and 100 - end

my_user_types.h is a set of some helper types. Most important rawArray2D<T> which is a very very simple 2D array based on raw memory block with no protection for its members.
NOTE: all cell are addressed with this param order A(y, x) (same as A[y*A.width + x]).

All algorithms(except of graph segmentation) operate on luma values. They take RGB from QImage, convert to Y (luma/brightness from Y'CbCr). 
After processing R=G=B=Y-output (image stays grayscale).

Current abilities:
gradient - counts gradient in each piixel using Sobel matrix; normalize gradient value to 0-255 in all frame
nGradient - the same, but gradient value is normalized in small local area
GVF - gradient vector flow
canny - edge detection
long lines - deletes all lines on image that are shorter than some value (must be executed after canny, line point - pixel with luma >128). Made up and not very effective algorithm.
Show frequency - deletes/leaves picked luma frequencies (based on VP8 Descrette Cosine Transform with overlapping blocks)
Smooth - smooths image by finding local maximums and lowering them below their neighbours (and rising local minimums same way)
One snake - snake minimizing three terms: curvature, elasticity and image interest (coefficients must be tweaked in code for now).
Segment graph - segmentation that builds a tree of pixels for each segment. Nodes connected or disconnected based on square difference between colors (only method that works with color)
biSegment graph - the same, but connects nodes if the are on the same side of some level value separator (for example luma < N for both)



