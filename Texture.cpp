#include "Texture.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <math.h>   // include math functions, such as sin, cos, M_PI
#include <iostream>
#include "Skybox.h"
using namespace std;

Texture* Texture::emptyTexture = new Texture();

Texture::Texture()
{
    id = 0;
}
Texture::Texture(const char* fname)
{
    
    filename = fname;
    
    GLuint texture[1];  // storage for one texture
    int twidth, theight;   // texture width/height [pixels]
    unsigned char* tdata;  // texture pixel data
    // Load image file
    
    tdata = loadPPM(filename, twidth, theight);
    
    //If the image wasn't loaded, can't continue
    if(tdata == NULL)
        return;
    
    // Create ID for texture
    
    glGenTextures(1, &texture[0]);
    id=texture[0];
    
    // Set this texture to be the one we are working with
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    
    // Generate the texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, twidth, theight, 0, GL_RGB, GL_UNSIGNED_BYTE, tdata);
    
    // Make sure no bytes are padded:
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    
    // Select GL_MODULATE to mix texture with quad color for shading:
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    // Use bilinear interpolation:
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::initGL()
{
    glEnable(GL_TEXTURE_2D);// enable texture mapping
    glShadeModel(GL_SMOOTH);   // enable smooth shading
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // black background
    glClearDepth(1.0f);        // depth buffer setup
    glEnable(GL_DEPTH_TEST);   // enables depth testing
    glDepthFunc(GL_LEQUAL);    // configure depth testing
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);          // really nice perspective calculations
}


/*void Texture::loadTexture()
{
    
    int twidth, theight;   // texture width/height [pixels]
    unsigned char* tdata;  // texture pixel data
    
    const char* face = "base.ppm";    // Load image file
        tdata = loadPPM(face, twidth, theight);
        if (tdata==NULL) return;
        
        // Create ID for texture
        glGenTextures(6, &texture[6]);
        
        // Set this texture to be the one we are working with
        glBindTexture(GL_TEXTURE_2D, texture[6]);
        
        // Generate the texture
        glTexImage2D(GL_TEXTURE_2D, 0, 3, twidth, theight, 0, GL_RGB, GL_UNSIGNED_BYTE, tdata);
        
        // Set bi-linear filtering for both minification and magnification
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
}*/

Texture::~Texture()
{
    //
}

void Texture::bind(void)
{
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unbind(void)
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

/** Load a ppm file from disk.
 @input filename The location of the PPM file.  If the file is not found, an error message
 will be printed and this function will return 0
 @input width This will be modified to contain the width of the loaded image, or 0 if file not found
 @input height This will be modified to contain the height of the loaded image, or 0 if file not found
 @return Returns the RGB pixel data as interleaved unsigned chars (R0 G0 B0 R1 G1 B1 R2 G2 B2 .... etc) or 0 if an error ocured
 **/
unsigned char* Texture::loadPPM(const char* filename, int& width, int& height)
{
    
    const int BUFSIZE = 128;
    FILE* fp;
    size_t read;
    unsigned char* rawData;
    char buf[3][BUFSIZE];
    char* retval_fgets;
    size_t retval_sscanf;
    
    //Open the texture file
    if((fp=fopen(filename, "rb")) == NULL)
    {
        std::cerr << "error reading ppm file, could not locate " << filename << std::endl;
        width = 0;
        height = 0;
        return NULL;
    }
    
    // Read magic number:
    retval_fgets = fgets(buf[0], BUFSIZE, fp);
    
    // Read width and height:
    do
    {
        retval_fgets=fgets(buf[0], BUFSIZE, fp);
    } while (buf[0][0] == '#');
    
    retval_sscanf=sscanf(buf[0], "%s %s", buf[1], buf[2]);
    width  = atoi(buf[1]);
    height = atoi(buf[2]);
    
    // Read maxval:
    do
    {
        retval_fgets=fgets(buf[0], BUFSIZE, fp);
    } while (buf[0][0] == '#');
    
    // Read image data:
    rawData = new unsigned char[width * height * 3];
    read = fread(rawData, width * height * 3, 1, fp);
    fclose(fp);
    if (read != 1)
    {
        std::cerr << "error parsing ppm file, incomplete data" << std::endl;
        delete[] rawData;
        width = 0;
        height = 0;
        return NULL;
    }
    return rawData;
}




/*! glut display callback function.  Every time the window needs to be drawn,
 glut will call this function.  This includes when the window size
 changes, or when another window covering part of this window is
 moved so this window is uncovered.
 */

/*! glut reshape callback function.  GLUT calls this function whenever
 the window is resized, including the first time it is created.
 You can use variables to keep track the current window size.
 */
void Texture::reshape(int width, int height)
{
       
    /* tell OpenGL we want to display in a recangle that is the
     same size as the window
     */
    glViewport(0,0,width,height);
    
    /* switch to the projection matrix */
    glMatrixMode(GL_PROJECTION);
    
    /* clear the projection matrix */
    glLoadIdentity();
    
    /* set the camera view, orthographic projection with 4x4 unit square canvas*/
    glOrtho(-2,2,-2,2,2,-2);
    
    /* switch back to the model view matrix */
    glMatrixMode(GL_MODELVIEW);
}




/*void Texture::Drawface(float size)
{
    glPushMatrix();
   
    // front
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    //glColor3f(1, 0, 0);
    glTexCoord2f(0, 0);      glVertex3f(size, size, size);
    glTexCoord2f(1, 0);      glVertex3f(-size, size, size);
    glTexCoord2f(1, 1);      glVertex3f(-size, -size, size);
    glTexCoord2f(0, 1);      glVertex3f(size, -size, size);
    glEnd();
    
    
    // back
    
    glBegin(GL_QUADS);
    glNormal3f(0, 0, -1);
    glColor3f(1,1,0);
     glVertex3f(-size, size, -size);
    glVertex3f(size, size, -size);
     glVertex3f(size, -size, -size);
     glVertex3f(-size, -size, -size);
    glEnd();
    
    // top
    
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glColor3f(1,1,0);
    glVertex3f(-size, size, -size);
    glVertex3f(-size, size, size);
    glVertex3f(size, size, size);
    glVertex3f(size, size, -size);
    glEnd();
    
    // bottom
    
    glBegin(GL_QUADS);
    glNormal3f(0, -1, 0);
    glColor3f(1,1,0);
    glVertex3f(-size, -size, -size);
    glVertex3f(size, -size, -size);
    glVertex3f(size, -size, size);
    glVertex3f(-size, -size, size);
    glEnd();
    
    // left
    
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glColor3f(1,1,0);
    glVertex3f(-size, size, -size);
    glVertex3f(-size, -size, -size);
    glVertex3f(-size, -size, size);
    glVertex3f(-size, size, size);
    glEnd();
    
    // right
    
    glBegin(GL_QUADS);
    glNormal3f(1, 0, 0);
    glColor3f(1,1,0);
    glVertex3f(size, size, size);
    glVertex3f(size, -size, size);
    glVertex3f(size, -size, -size);
    glVertex3f(size, size, -size);
    glEnd();
}*/

/* Gets called whenever computer doesn't have anything else to do
 
void Texture::idle()
{
    cerr << "idle callback" << endl;
    display(size);     // call display callback, useful for animation
}*/