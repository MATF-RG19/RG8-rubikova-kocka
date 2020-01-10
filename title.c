#ifndef LIB_H
    #define LIB_H
    #include "lib.h"
#endif

void init_texture(){
    
    Image * image;
    
    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

    image = image_init(0, 0);

    
    image_read(image, FILENAME0);

    
    glGenTextures(1, &name);

    glBindTexture(GL_TEXTURE_2D, name);

    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    
    
    
    
    glBindTexture(GL_TEXTURE_2D, 0);
    image_done(image);
}
void title(){
    //iscrtavanje slova R
    
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-21, -10, 25);

         glTexCoord2f(1, 0);
        glVertex3f(-20, -10, 25);

         glTexCoord2f(1, 1);
        glVertex3f(-20, 0, 25);

         glTexCoord2f(0, 1);
        glVertex3f(-21, 0, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-20, -1, 25);

         glTexCoord2f(0, 0.5);
        glVertex3f(-17, -1, 25);

         glTexCoord2f(0.5, 0.5);
        glVertex3f(-17, 0, 25);

         glTexCoord2f(0.5, 0);
        glVertex3f(-20, 0, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    
    
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

         glTexCoord2f(0, 0);
        glVertex3f(-18, -1, 25);

          glTexCoord2f(0, 0.5);
        glVertex3f(-17, -1, 25);

          glTexCoord2f(0.75, 0.5);
        glVertex3f(-17, -4, 25);

          glTexCoord2f(0.75, 0);
        glVertex3f(-18, -4, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(-20, -5, 25);

        glTexCoord2f(0, 0.5);
        glVertex3f(-17, -5, 25);

        glTexCoord2f(0.5, 0.5);
        glVertex3f(-17, -4, 25);

        glTexCoord2f(0.5, 0);
        glVertex3f(-20, -4, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(-18, -10, 25);

        glTexCoord2f(1, 0);
        glVertex3f(-17, -10, 25);

        glTexCoord2f(1, 1);
        glVertex3f(-19, -5, 25);

        glTexCoord2f(0, 1);
        glVertex3f(-20, -5, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    
    //iscrtavanje slova u
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(-15, -10, 25);

        glTexCoord2f(1, 0);
        glVertex3f(-14, -10, 25);

        glTexCoord2f(1, 1);
        glVertex3f(-14, -4, 25);

        glTexCoord2f(0, 1);
        glVertex3f(-15, -4, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(-14, -10, 25);

        glTexCoord2f(0, 1);
        glVertex3f(-12, -10, 25);

        glTexCoord2f(0.5, 1);
        glVertex3f(-12, -9, 25);

        glTexCoord2f(0.5, 0);
        glVertex3f(-14, -9, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(-12, -10, 25);

        glTexCoord2f(1, 0);
        glVertex3f(-11, -10, 25);

        glTexCoord2f(1, 1);
        glVertex3f(-11, -4, 25);

        glTexCoord2f(0, 1);
        glVertex3f(-12, -4, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    
    //iscrtavanje slova b
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(-9, -10, 25);

        glTexCoord2f(1, 0);
        glVertex3f(-8, -10, 25);

        glTexCoord2f(1, 1);
        glVertex3f(-8, -3, 25);

        glTexCoord2f(0, 1);
        glVertex3f(-9, -3, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(-8, -7, 25);

        glTexCoord2f(0, 1);
        glVertex3f(-6, -7, 25);

        glTexCoord2f(0.5, 1);
        glVertex3f(-6, -6, 25);

        glTexCoord2f(0.5, 0);
        glVertex3f(-8, -6, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(-7, -9, 25);

        glTexCoord2f(1, 0);
        glVertex3f(-6, -9, 25);

        glTexCoord2f(1, 1);
        glVertex3f(-6, -6, 25);

        glTexCoord2f(0, 1);
        glVertex3f(-7, -6, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(-8, -10, 25);

        glTexCoord2f(0, 1);
        glVertex3f(-6, -10, 25);

        glTexCoord2f(0.5, 1);
        glVertex3f(-6, -9, 25);

        glTexCoord2f(0.5, 0);
        glVertex3f(-8, -9, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    //iscrtavanje slova i
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(-4.5, -10, 25);

        glTexCoord2f(1, 0);
        glVertex3f(-3.5, -10, 25);

        glTexCoord2f(1, 1);
        glVertex3f(-3.5, -6, 25);

        glTexCoord2f(0, 1);
        glVertex3f(-4.5, -6, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    //iscrtavanje slova k
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(-1, -10, 25);

        glTexCoord2f(0.5, 0);
        glVertex3f(0, -10, 25);

        glTexCoord2f(0.5, 1);
        glVertex3f(0, -2, 25);

        glTexCoord2f(0, 1);
        glVertex3f(-1, -2, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(0, -7, 25);

        glTexCoord2f(0.5, 0);
        glVertex3f(1, -7, 25);

        glTexCoord2f(0.5, 1);
        glVertex3f(2, -4, 25);

        glTexCoord2f(0, 1);
        glVertex3f(1, -4, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D, name);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        
        glTexCoord2f(0, 0);
        glVertex3f(1, -10, 25);

        glTexCoord2f(0.5, 0);
        glVertex3f(2, -10, 25);

        glTexCoord2f(0.5, 1);
        glVertex3f(1, -7, 25);

        glTexCoord2f(0, 1);
        glVertex3f(0, -7, 25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}
