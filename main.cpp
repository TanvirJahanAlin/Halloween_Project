/*

© Tanvir Jahan Alin & Tamal Sutradhar Rudra, 2024. All Rights Reserved.

This project, including its design, code, and all visual elements, is the intellectual property of Tamal Sutradhar Rudra and Tanvir Jahan Alin. It is protected by copyright laws. Unauthorized reproduction, distribution, or modification of any part of this project is strictly prohibited without explicit permission.

For inquiries, collaborations, or permissions, please contact tanvialin13@gmail.com or tsrudra27@gmail.com

*/

#ifdef __APPLE__
#include <GLUT/glut.h> //If compiling on a Mac, this includes the GLUT header specific to Mac.
#else
#include <GL/glut.h> // If compiling on other platforms, this includes the standard GLUT header.
#endif
#include <math.h> // Includes mathematical functions, like sine, cosine, and square root.
#include <stdlib.h> // Includes standard library functions, such as memory allocation, process control, and conversions.
#include <windows.h> // This includes the Windows API header file, which contains declarations for all Windows functions, constants, and types.
#include <mmsystem.h>
float spin = 0.0f;
float moving = 0.0f;
float speed = 0.2f;

float witchPosX = 0.0f; // X-axis position
float witchPosY = 0.0f; // Y-axis position
float witchSpeedX = 0.1f; // Speed along the X-axis
float witchSpeedY = 0.1f; // Speed along the Y-axis

void updateWitchPosition(int value)
{
    // Update witch's position for diagonal movement
    witchPosX += witchSpeedX;
    witchPosY += witchSpeedY;

    // Check for boundaries (to keep the witch within a certain area)
    if (witchPosX > 35.0f)
    {
        witchPosX = 0.0f;
        //witchSpeedX = -witchSpeedX; // Reverse direction on X-axis
    }
    if (witchPosY > 35.0f)
    {
        witchPosY = 0.0f;
        //witchSpeedY = -witchSpeedY; // Reverse direction on Y-axis
    }

    // Redraw the scene
    glutPostRedisplay(); // Update witch position without creating new one

    // Call this function again after 16 milliseconds (~60 FPS)
    glutTimerFunc(16, updateWitchPosition, 0);
}

void timer(int) // timer function for bats
{
    moving += speed; // Move witch to the right

    // Wrap around when reaching the end of the screen
    if (moving > 100.0f)
        moving = -5.0f;

    glutPostRedisplay();        // Redisplay after updating
    glutTimerFunc(16, timer, 0); // 60 FPS
}

void drawCircle(float cx, float cy, float rx, float ry, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for(int ii=0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.14159f * float(ii)/float(num_segments);
        float x = rx * cosf(theta);
        float y = ry * sinf(theta);
        glVertex2d(x+cx, y+cy);
    }
    glEnd();
}

void init()
{
    glClearColor(0.0f, 0.0f,0.25f,0.0f);
    glOrtho(-100,100,-100,100,-100,100); // Sets up a 2D orthographic viewing region with the given boundaries.
}
void background()
{
    //background
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.25f); //color
    glVertex3d(100.0,100.0,0.0);
    glColor3f(0.0f,0.0f,0.25f); //color
    glVertex3d(-100.0,100.0,0.0);
    glColor3f(0.0f,0.0f,0.25f); //color
    glVertex3d(-100.0,-100.0,0.0);
    glColor3f(0.0f,0.0f,0.7f); //color
    glVertex3d(100.0,-100.0,0.0);
    glEnd();
}
void star()
{
    //star
    for(int i=-100; i<=100; i+=55)
    {
        for(int j=0; j<=100; j+=42)
        {
            glColor3f(1.0f,1.0f,1.0f); //color
            drawCircle(i,j,0.3,0.3,100);
        }
    }

    for(int i=-100; i<=100; i+=40)
    {
        for(int j=0; j<=100; j+=36)
        {
            glColor3f(1.0f,1.0f,1.0f); //color
            drawCircle(i,j,0.3,0.3,100);
        }
    }

    for(int i=-100; i<=100; i+=88.8)
    {
        for(int j=0; j<=100; j+=56.8)
        {
            glColor3f(1.0f,1.0f,1.0f); //color
            drawCircle(i,j,0.3,0.3,100);
        }
    }

    for(int i=-100; i<=100; i+=72.5)
    {
        for(int j=0; j<=100; j+=60.5)
        {
            glColor3f(1.0f,1.0f,1.0f); //color
            drawCircle(i,j,0.3,0.3,100);
        }
    }
    for(int i=-100; i<=100; i+=37)
    {
        for(int j=0; j<=100; j+=28)
        {
            glColor3f(1.0f,1.0f,1.0f); //color
            drawCircle(i,j,0.3,0.3,100);
        }
    }
    for(int i=-100; i<=100; i+=30)
    {
        for(int j=0; j<=100; j+=22)
        {
            glColor3f(1.0f,1.0f,1.0f); //color
            drawCircle(i,j,0.3,0.3,100);
        }
    }
    for(int i=-100; i<=100; i+=17)
    {
        for(int j=0; j<=100; j+=30)
        {
            glColor3f(1.0f,1.0f,1.0f); //color
            drawCircle(i,j,0.3,0.3,100);
        }
    }

    for(int i=-100; i<=100; i+=27)
    {
        for(int j=0; j<=100; j+=13)
        {
            glColor3f(1.0f,1.0f,1.0f); //color
            drawCircle(i,j,0.3,0.3,100);
        }
    }

    for(int i=-100; i<=100; i++) //line star
    {
        glColor3f(0.0f,0.0f,0.15f); //color
        drawCircle(i,0,0.3,0.3,100);
    }
}
void moon()
{
    glColor3f(1.0f,1.0f,0.9f); //color
    drawCircle(-20,20,35,35,100);
}
void witch()
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glTranslatef(-35.0, 40.0, 0.0);
    glTranslatef(witchPosX, witchPosY, 0.0f); // Automatically move the witch

    glBegin(GL_TRIANGLES);      //body a
    glColor3f(0.0f,0.0f,0.0f);  //color
    glVertex3d(1.0,-2.0,0.0);
    glVertex3d(-1.0,-3.0,0.0);
    glVertex3d(2.0,-5.0,0.0);
    glEnd();
    //witch head

    glColor3f(1.0f,0.9f,0.9f); //color
    drawCircle(0,0,3,3,100);

    //witch hat

    //H1
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(4.0,6.0,0.0);     //x
    glVertex3d(-4.0,5.0,0.0);    //y
    glVertex3d(-5.0,-3.0,0.0);   //z
    glEnd();

    //H2
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(-4.0,0.0,0.0);
    glVertex3d(0.0,4.0,0.0);
    glVertex3d(-6.0,6.0,0.0);
    glEnd();

    //H3
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(-5.0,3.0,0.0);
    glVertex3d(-6.0,6.0,0.0);
    glVertex3d(-10.0,6.0,0.0);
    glEnd();

    glBegin(GL_TRIANGLES); //body b
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(-1.0,-9.0,0.0);
    glVertex3d(-1.0,-3.0,0.0);
    glVertex3d(5.0,-7.0,0.0);
    glEnd();

    glBegin(GL_TRIANGLES); //body c
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(5.0,-7.0,0.0);
    glVertex3d(9.0,-5.0,0.0);
    glVertex3d(2.0,-5.0,0.0);
    glEnd();

    glBegin(GL_QUADS); //broom stick
    glColor3f(0.9f,0.5f,0.3f); //color
    glVertex3d(13.0,-6.0,0.0);
    glVertex3d(-4.0,-16.0,0.0);
    glColor3f(0.6f,0.3f,0.0f); //color
    glVertex3d(-3.0,-17.0,0.0);
    glVertex3d(14.0,-7.0,0.0);
    glEnd();

    glBegin(GL_TRIANGLES); //body d
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(-1.0,-9.0,0.0);
    glVertex3d(2.0,-14.0,0.0);
    glVertex3d(5.0,-7.0,0.0);
    glEnd();

    glBegin(GL_TRIANGLES); //body e
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(5.0,-7.0,0.0);
    glVertex3d(1.0,-16.0,0.0);
    glVertex3d(9.0,-12.0,0.0);
    glEnd();

    glBegin(GL_QUADS); //broom stick back
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(-4.0,-14.0,0.0);
    glVertex3d(-1.0,-17.0,0.0);
    glVertex3d(-2.0,-17.0,0.0);
    glVertex3d(-4.0,-16.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3d(-2.0,-17.0,0.0);
    glVertex3d(-3.0,-16.0,0.0);
    glVertex3d(-6.0,-22.0,0.0);
    glVertex3d(-10.0,-18.0,0.0);
    glEnd();

    glPopMatrix();
}
void house()
{
    glBegin(GL_QUADS);
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(5.0,17.0,0.0);  //Ta
    glVertex3d(5.0,35.0,0.0); //Tb
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(-5.0,35.0,0.0); //Tc
    glVertex3d(-5.0,17.0,0.0);  //Td
    glEnd();

    /////////////////////////////////

    glBegin(GL_TRIANGLES);
    glVertex3d(10.0,35.0,0.0);
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(0.0,45.0,0.0);
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(-10.0,35.0,0.0);
    glEnd();

    //////////////////////////////////////

    glColor3f(1.0f,0.6f,0.1f); //color
    glColor3f(1.0f,0.8f,0.1f); //color
    drawCircle(0,30,3,3,100);
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.6f,0.1f); //color
    glVertex3d(3,21.0,0.0);  //Ta'
    glVertex3d(3,30.0,0.0); //Tb'
    glColor3f(1.0f,0.8f,0.1f); //color
    glVertex3d(-3,30.0,0.0); //Tc'
    glVertex3d(-3,21.0,0.0);  //Td'
    glEnd();

    //1st block end

    //2nd block start

    glBegin(GL_QUADS);
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(18.0,-3.0,0.0);  //a
    glVertex3d(18.0,17.0,0.0); //b
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(-18.0,17.0,0.0); //c
    glVertex3d(-18.0,-3.0,0.0);  //d

    //1
    glVertex3d(18.0,17.0,0.0);
    glVertex3d(18.0,20.0,0.0);
    glVertex3d(14.0,20.0,0.0);
    glVertex3d(14.0,17.0,0.0);

    //2
    glVertex3d(10.0,17.0,0.0);
    glVertex3d(10.0,20.0,0.0);
    glVertex3d(6.0,20.0,0.0);
    glVertex3d(6.0,17.0,0.0);

    //3
    glVertex3d(2.0,17.0,0.0);
    glVertex3d(2.0,20.0,0.0);
    glVertex3d(-2.0,20.0,0.0);
    glVertex3d(-2.0,17.0,0.0);

    //4
    glVertex3d(-6.0,17.0,0.0);
    glVertex3d(-6.0,20.0,0.0);
    glVertex3d(-10.0,20.0,0.0);
    glVertex3d(-10.0,17.0,0.0);

    //5
    glVertex3d(-14.0,17.0,0.0);
    glVertex3d(-14.0,20.0,0.0);
    glVertex3d(-18.0,20.0,0.0);
    glVertex3d(-18.0,0.0,0.0);

    glEnd();

    //Right window start

    glColor3f(1.0f,0.8f,0.1f); //color
    drawCircle(9,10,4,4,100);

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.6f,0.1f); //color
    glVertex3d(13.0,2.0,0.0);
    glVertex3d(13.0,10.0,0.0);
    glColor3f(1.0f,0.8f,0.1f); //color
    glVertex3d(5.0,10.0,0.0);
    glVertex3d(5.0,2.0,0.0);
    glEnd();

    //Right window end

    //Left window start

    glColor3f(1.0f,0.8f,0.1f); //color
    drawCircle(-9,10,4,4,100);

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.6f,0.1f); //color
    glVertex3d(-5.0,2.0,0.0);
    glVertex3d(-5.0,10.0,0.0);
    glColor3f(1.0f,0.8f,0.1f); //color
    glVertex3d(-13.0,10.0,0.0);
    glVertex3d(-13.0,2.0,0.0);
    glEnd();

    //left window end

    //2nd block end

    //3rd block start

    //middle block start

    glBegin(GL_QUADS);
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(26.0,-40.0,0.0); //A
    glVertex3d(26.0,-3.0,0.0);   //B
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(-26.0,-3.0,0.0);     //C
    glVertex3d(-26.0,-40.0,0.0);   //D

    //1
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(26.0,-3.0,0.0);
    glVertex3d(26.0,0.0,0.0);
    glVertex3d(22.0,0.0,0.0);
    glVertex3d(22.0,-3.0,0.0);

    //2
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(18.0,-3.0,0.0);
    glVertex3d(18.0,0.0,0.0);
    glVertex3d(14.0,0.0,0.0);
    glVertex3d(14.0,-3.0,0.0);

    //3
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(10.0,-3.0,0.0);
    glVertex3d(10.0,0.0,0.0);
    glVertex3d(6.0,0.0,0.0);
    glVertex3d(6.0,-3.0,0.0);

    //4
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(2.0,-3.0,0.0);
    glVertex3d(2.0,0.0,0.0);
    glVertex3d(-2.0,0.0,0.0);
    glVertex3d(-2.0,-3.0,0.0);

    //5
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(-6.0,-3.0,0.0);
    glVertex3d(-6.0,0.0,0.0);
    glVertex3d(-10.0,0.0,0.0);
    glVertex3d(-10.0,-3.0,0.0);

    //6
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(-14.0,-3.0,0.0);
    glVertex3d(-14.0,0.0,0.0);
    glVertex3d(-18.0,0.0,0.0);
    glVertex3d(-18.0,-3.0,0.0);

    //7
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(-22.0,-3.0,0.0);
    glVertex3d(-22.0,0.0,0.0);
    glVertex3d(-26.0,0.0,0.0);
    glVertex3d(-26.0,-3.0,0.0);
    glEnd();

    //door start

    glColor3f(1.0f,0.8f,0.1f); //color
    drawCircle(0,-12,6,6,100);

    glBegin(GL_QUADS);

    glColor3f(1.0f,0.6f,0.1f); //color
    glVertex3d(6.0,-40.0,0.0);  //A'
    glVertex3d(6.0,-11.0,0.0); //B'
    glColor3f(1.0f,0.8f,0.1f); //color
    glVertex3d(-6.0,-11.0,0.0); //C'
    glVertex3d(-6.0,-40.0,0.0);  //D'

    //door end

    glEnd();

    // middle block end

    //right block start

    glBegin(GL_QUADS);
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(46.0,-40.0,0.0);  //q
    glVertex3d(46.0,-10.0,0.0); //r
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(26.0,-10.0,0.0); //s
    glVertex3d(26.0,-40.0,0.0);  //t

    //1
    glVertex3d(46.0,-10.0,0.0);
    glVertex3d(46.0,-5.0,0.0);
    glVertex3d(42.0,-5.0,0.0);
    glVertex3d(42.0,-10.0,0.0);

    //2
    glVertex3d(38.0,-10.0,0.0);
    glVertex3d(38.0,-5.0,0.0);
    glVertex3d(34.0,-5.0,0.0);
    glVertex3d(34.0,-10.0,0.0);

    //3
    glVertex3d(30.0,-10.0,0.0);
    glVertex3d(30.0,-5.0,0.0);
    glVertex3d(26.0,-5.0,0.0);
    glVertex3d(26.0,-10.0,0.0);

    glEnd();

    //right door

    glColor3f(1.0f,0.8f,0.1f); //color
    drawCircle(36,-23,4,4,100);

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.6f,0.1f); //color
    glVertex3d(40.0,-35.0,0.0);
    glVertex3d(40.0,-23.0,0.0);
    glColor3f(1.0f,0.8f,0.1f); //color
    glVertex3d(32.0,-23.0,0.0);
    glVertex3d(32.0,-35.0,0.0);

    glEnd();

    //right block end

    //left block start

    glBegin(GL_QUADS);
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(-26.0,-40.0,0.0);  //m
    glVertex3d(-26.0,-10.0,0.0); //n
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(-46.0,-10.0,0.0); //o
    glVertex3d(-46.0,-40.0,0.0);  //p

    //1
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(-26.0,-10.0,0.0);
    glVertex3d(-26.0,-5.0,0.0);
    glVertex3d(-30.0,-5.0,0.0);
    glVertex3d(-30.0,-10.0,0.0);

    //2
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(-34.0,-10.0,0.0);
    glVertex3d(-34.0,-5.0,0.0);
    glVertex3d(-38.0,-5.0,0.0);
    glVertex3d(-38.0,-10.0,0.0);

    //3
    glVertex3d(-42.0,-10.0,0.0);
    glVertex3d(-42.0,-5.0,0.0);
    glVertex3d(-46.0,-5.0,0.0);
    glVertex3d(-46.0,-10.0,0.0);

    glEnd();
    // left block end

    //right door

    glColor3f(1.0f,0.8f,0.1f); //color
    drawCircle(-36,-23,4,4,100);

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.6f,0.1f); //color
    glVertex3d(-40.0,-35.0,0.0);
    glVertex3d(-40.0,-23.0,0.0);
    glColor3f(1.0f,0.8f,0.1f); //color
    glVertex3d(-32.0,-23.0,0.0);
    glVertex3d(-32.0,-35.0,0.0);
    glEnd();

    //right pillar

    glBegin(GL_QUADS);
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(40.0,-10.0,0.0);
    glVertex3d(40.0,10.0,0.0);
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(32.0,10.0,0.0);
    glVertex3d(32.0,-10.0,0.0);
    glEnd();

    /////////////////////////////

    glBegin(GL_TRIANGLES);
    glVertex3d(43.0,8.0,0.0);
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(36.0,20.0,0.0);
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(29.0,8.0,0.0);
    glEnd();

    //right pillar window

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.8f,0.1f); //color
    glVertex3d(38.0,-3.0,0.0);
    glVertex3d(38.0,5.0,0.0);
    glColor3f(1.0f,0.6f,0.1f); //color
    glVertex3d(34.0,5.0,0.0);
    glVertex3d(34.0,-3.0,0.0);
    glEnd();

    //left pillar

    glBegin(GL_QUADS);
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(-32.0,-10.0,0.0);
    glVertex3d(-32.0,10.0,0.0);
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(-40.0,10.0,0.0);
    glVertex3d(-40.0,-10.0,0.0);
    glEnd();

    //////////////////////////

    glBegin(GL_TRIANGLES);
    glVertex3d(-29.0,8.0,0.0);
    glColor3f(0.7f,0.4f,1.0f); //color
    glVertex3d(-36.0,20.0,0.0);
    glColor3f(0.6f,0.1f,0.7f); //color
    glVertex3d(-43.0,8.0,0.0);
    glEnd();

    //left pillar window

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.8f,0.1f); //color
    glVertex3d(-34.0,-3.0,0.0);
    glVertex3d(-34.0,5.0,0.0);
    glColor3f(1.0f,0.6f,0.1f); //color
    glVertex3d(-38.0,5.0,0.0);
    glVertex3d(-38.0,-3.0,0.0);
    glEnd();
    //3rd block end
}
void scarecrowleft()
{
    //hat

    glBegin(GL_TRIANGLES);
    glVertex3d(-56.0,-24.0,0.0);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-60.0,-22.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-64.0,-24.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-58.0,-24.0,0.0);
    glVertex3d(-58.0,-21.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-62.0,-21.0,0.0);
    glVertex3d(-62.0,-24.0,0.0);
    glEnd();

    //body

    glBegin(GL_TRIANGLES);
    glVertex3d(-58.0,-30.0,0.0);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-60.0,-24.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-62.0,-30.0,0.0);
    glEnd();

    //face

    glColor3f(0.6f,0.6f,0.5f); //color
    drawCircle(-60,-25,2,2,100);


    //hand

    // right hand
    glBegin(GL_QUADS);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-55.0,-28.0,0.0);
    glVertex3d(-55.0,-27.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-59.0,-27.0,0.0);
    glVertex3d(-59.0,-28.0,0.0);
    glEnd();

    //left hand
    glBegin(GL_QUADS);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-61.0,-28.0,0.0);
    glVertex3d(-61.0,-27.0,0.0);
    glVertex3d(-65.0,-27.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-65.0,-28.0,0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-60.0,-30.0,0.0);
    glVertex3d(-60.0,-35.0,0.0);
    glEnd();

}
void scarecrowRight()
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glTranslatef(120.0f, 0.0f, 0.0f);
    //hat

    glBegin(GL_TRIANGLES);
    glVertex3d(-56.0,-24.0,0.0);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-60.0,-22.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-64.0,-24.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-58.0,-24.0,0.0);
    glVertex3d(-58.0,-21.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-62.0,-21.0,0.0);
    glVertex3d(-62.0,-24.0,0.0);
    glEnd();

    //body

    glBegin(GL_TRIANGLES);
    glVertex3d(-58.0,-30.0,0.0);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-60.0,-24.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-62.0,-30.0,0.0);
    glEnd();

    //face

    glColor3f(0.6f,0.6f,0.5f); //color
    drawCircle(-60,-25,2,2,100);


    //hand

    // right hand
    glBegin(GL_QUADS);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-55.0,-28.0,0.0);
    glVertex3d(-55.0,-27.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-59.0,-27.0,0.0);
    glVertex3d(-59.0,-28.0,0.0);
    glEnd();

    //left hand
    glBegin(GL_QUADS);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-61.0,-28.0,0.0);
    glVertex3d(-61.0,-27.0,0.0);
    glVertex3d(-65.0,-27.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-65.0,-28.0,0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-60.0,-30.0,0.0);
    glVertex3d(-60.0,-35.0,0.0);
    glEnd();
    glPopMatrix();
}
void scarecrow1()
{
    //hat
    glBegin(GL_TRIANGLES);
    glVertex3d(73.0,-8.0,0.0);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(71.0,-10.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(75.0,-10.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(72.0,-8.0,0.0);
    glVertex3d(72.0,-10.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(74.0,-10.0,0.0);
    glVertex3d(74.0,-8.0,0.0);
    glEnd();

    //body
    glBegin(GL_TRIANGLES);
    glVertex3d(73.0,-10.0,0.0);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(71.0,-14.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(75.0,-14.0,0.0);
    glEnd();

    //face
    glColor3f(0.6f,0.6f,0.5f); //color
    drawCircle(73,-10,1,1,100);

    //hand
    // right hand
    glBegin(GL_QUADS);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(73.0,-11.0,0.0);
    glVertex3d(73.0,-12.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(76.0,-12.0,0.0);
    glVertex3d(76.0,-11.0,0.0);
    glEnd();

    //left hand
    glBegin(GL_QUADS);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(70.0,-11.0,0.0);
    glVertex3d(70.0,-12.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(73.0,-12.0,0.0);
    glVertex3d(73.0,-11.0,0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(73.0,-13.0,0.0);
    glVertex3d(73.0,-16.0,0.0);
    glEnd();
}
void scarecrow2()
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glTranslatef(0.0, 7.0, 0.0);
    //hat

    glBegin(GL_TRIANGLES);
    glVertex3d(-72.0,-15.0,0.0);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-74.0,-17.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-70.0,-17.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-73.0,-15.0,0.0);
    glVertex3d(-73.0,-17.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-71.0,-17.0,0.0);
    glVertex3d(-71.0,-15.0,0.0);
    glEnd();

    //body
    glBegin(GL_TRIANGLES);
    glVertex3d(-72.0,-17.0,0.0);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-74.0,-20.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-70.0,-20.0,0.0);
    glEnd();

    //face
    glColor3f(0.6f,0.6f,0.5f); //color
    drawCircle(-72,-17,1,1,100);

    //hand

    // right hand
    glBegin(GL_QUADS);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-72.0,-18.0,0.0);
    glVertex3d(-72.0,-19.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-69.0,-19.0,0.0);
    glVertex3d(-69.0,-18.0,0.0);
    glEnd();

    //left hand
    glBegin(GL_QUADS);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-75.0,-18.0,0.0);
    glVertex3d(-75.0,-19.0,0.0);
    glColor3f(0.8f,0.8f,0.3f); //color
    glVertex3d(-72.0,-19.0,0.0);
    glVertex3d(-72.0,-18.0,0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.8f,0.7f,0.4f); //color
    glVertex3d(-72.0,-20.0,0.0);
    glVertex3d(-72.0,-23.0,0.0);
    glEnd();
    glPopMatrix();
}
void bat1(float dy)
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glTranslatef(0.0f, dy, 0.0f);
    //ear start

    //right ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(47.0,35.0,0.0);
    glVertex3d(48.0,37.0,0.0);
    glColor3f(0.5f,0.4f,0.4f); //color
    glVertex3d(46.0,36.0,0.0);
    glEnd();

    //left ear
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(44.0,36.0,0.0);
    glVertex3d(42.0,37.0,0.0);
    glColor3f(0.5f,0.4f,0.4f); //color
    glVertex3d(43.0,35.0,0.0);
    glEnd();

    //ear end
    //head start
    glColor3f(0.1f,0.1f,0.1); //color
    drawCircle(45,35,2,2,100);

    glBegin(GL_TRIANGLES);
    glColor3f(0.1f,0.1f,0.1f); //color
    glVertex3d(47.0,32.0,0.0);
    glVertex3d(45.0,37.0,0.0);
    glVertex3d(43.0,32.0,0.0);
    glEnd();

    //head end

    //body start

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(49.0,29.0,0.0);
    glVertex3d(47.0,32.0,0.0);
    glColor3f(0.5f,0.4f,0.4f); //color
    glVertex3d(43.0,32.0,0.0);
    glVertex3d(41.0,29.0,0.0);
    glEnd();

    //////////////////////

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(49.0,29.0,0.0);
    glVertex3d(45.0,22.0,0.0);
    glColor3f(0.5f,0.4f,0.4f); //color
    glVertex3d(41.0,29.0,0.0);
    glEnd();

    //body end

    //wing start

    //right wing

    //1
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(65.0,31.0,0.0);
    glVertex3d(53.0,36.0,0.0);
    glColor3f(0.5f,0.4f,0.4f); //color
    glVertex3d(56.0,30.0,0.0);
    glEnd();

    //2
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(56.0,30.0,0.0);
    glVertex3d(53.0,36.0,0.0);
    glColor3f(0.5f,0.4f,0.4f); //color
    glVertex3d(53.0,27.0,0.0);
    glEnd();

    //3
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(53.0,27.0,0.0);
    glVertex3d(53.0,36.0,0.0);
    glColor3f(0.5f,0.4f,0.4f); //color
    glVertex3d(49.0,29.0,0.0);
    glEnd();

    //4
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(49.0,29.0,0.0);
    glVertex3d(53.0,36.0,0.0);
    glColor3f(0.5f,0.4f,0.4f); //color
    glVertex3d(47.0,32.0,0.0);
    glEnd();


    //left wing

    //1
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(25.0,31.0,0.0);
    glVertex3d(37.0,36.0,0.0);
    glColor3f(0.5f,0.4f,0.4f); //color
    glVertex3d(34.0,30.0,0.0);
    glEnd();

    //2
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(34.0,30.0,0.0);
    glVertex3d(37.0,36.0,0.0);
    glColor3f(0.5f,0.4f,0.4f); //color
    glVertex3d(37.0,27.0,0.0);
    glEnd();

    //3
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(37.0,27.0,0.0);
    glVertex3d(37.0,36.0,0.0);
    glColor3f(0.5f,0.4f,0.4f); //color
    glVertex3d(41.0,29.0,0.0);
    glEnd();

    //4
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f); //color
    glVertex3d(41.0,29.0,0.0);
    glVertex3d(37.0,36.0,0.0);
    glColor3f(0.5f,0.4f,0.4f); //color
    glVertex3d(43.0,32.0,0.0);
    glEnd();

    //wing end
    //bat end
    glPopMatrix();
}
void bat2 (float cx, float cy, float spin)
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glScalef(2.0,2.0,0.0);
    glRotatef(spin,0.0, 0.0, 1.0);

    // body
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+0.0,cy+0.0,0.0);
    glVertex3d(cx+1.0,cy+1.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx+1.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+0.0,cy-2.0,0.0);
    glVertex3d(cx-1.0,cy+0.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx-1.0,cy+1.0,0.0);
    glEnd();

    //wings
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+1.0,cy+0.0,0.0);
    glVertex3d(cx+3.0,cy+2.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx+7.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+3.0,cy+1.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx-1.0,cy+0.0,0.0);
    glVertex3d(cx-3.0,cy+2.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx-7.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx-3.0,cy+1.0,0.0);
    glEnd();

    glPopMatrix();
}
void bat3 (float cx, float cy, float spin)
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glScalef(2.0,2.0,0.0);
    glRotatef(spin,0.0, 0.0, 1.0);

    // body
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+0.0,cy+0.0,0.0);
    glVertex3d(cx+1.0,cy+1.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx+1.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+0.0,cy-2.0,0.0);
    glVertex3d(cx-1.0,cy+0.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx-1.0,cy+1.0,0.0);
    glEnd();

    //wings
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+1.0,cy+0.0,0.0);
    glVertex3d(cx+3.0,cy+2.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx+7.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+3.0,cy+1.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx-1.0,cy+0.0,0.0);
    glVertex3d(cx-3.0,cy+2.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx-7.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx-3.0,cy+1.0,0.0);
    glEnd();

    glPopMatrix();
}
void bat4 (float cx, float cy, float spin)
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glScalef(2.0,2.0,0.0);
    glRotatef(spin,0.0, 0.0, 1.0);

    // body
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+0.0,cy+0.0,0.0);
    glVertex3d(cx+1.0,cy+1.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx+1.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+0.0,cy-2.0,0.0);
    glVertex3d(cx-1.0,cy+0.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx-1.0,cy+1.0,0.0);
    glEnd();

    //wings
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+1.0,cy+0.0,0.0);
    glVertex3d(cx+3.0,cy+2.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx+7.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+3.0,cy+1.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx-1.0,cy+0.0,0.0);
    glVertex3d(cx-3.0,cy+2.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx-7.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx-3.0,cy+1.0,0.0);
    glEnd();

    glPopMatrix();
}
void bat5 (float cx, float cy, float spin)
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glScalef(2.0,2.0,0.0);
    glRotatef(spin,0.0, 0.0, -1.0);

    // body
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+0.0,cy+0.0,0.0);
    glVertex3d(cx+1.0,cy+1.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx+1.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+0.0,cy-2.0,0.0);
    glVertex3d(cx-1.0,cy+0.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx-1.0,cy+1.0,0.0);
    glEnd();

    //wings
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+1.0,cy+0.0,0.0);
    glVertex3d(cx+3.0,cy+2.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx+7.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+3.0,cy+1.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx-1.0,cy+0.0,0.0);
    glVertex3d(cx-3.0,cy+2.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx-7.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx-3.0,cy+1.0,0.0);
    glEnd();

    glPopMatrix();
}
void bat6 (float cx, float cy, float spin)
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glScalef(2.0,2.0,0.0);
    glRotatef(spin,0.0, 0.0, -1.0);

    // body
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+0.0,cy+0.0,0.0);
    glVertex3d(cx+1.0,cy+1.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx+1.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+0.0,cy-2.0,0.0);
    glVertex3d(cx-1.0,cy+0.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx-1.0,cy+1.0,0.0);
    glEnd();

    //wings
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+1.0,cy+0.0,0.0);
    glVertex3d(cx+3.0,cy+2.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx+7.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+3.0,cy+1.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx-1.0,cy+0.0,0.0);
    glVertex3d(cx-3.0,cy+2.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx-7.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx-3.0,cy+1.0,0.0);
    glEnd();

    glPopMatrix();
}
void bat7 (float cx, float cy, float spin)
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glScalef(2.0,2.0,0.0);
    glRotatef(spin,0.0, 0.0, -1.0);

    // body
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+0.0,cy+0.0,0.0);
    glVertex3d(cx+1.0,cy+1.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx+1.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+0.0,cy-2.0,0.0);
    glVertex3d(cx-1.0,cy+0.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx-1.0,cy+1.0,0.0);
    glEnd();

    //wings
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+1.0,cy+0.0,0.0);
    glVertex3d(cx+3.0,cy+2.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx+7.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx+3.0,cy+1.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx-1.0,cy+0.0,0.0);
    glVertex3d(cx-3.0,cy+2.0,0.0);
    glColor3f(0.5f, 0.4f, 0.4f); //color
    glVertex3d(cx-7.0,cy+0.0,0.0);
    glColor3f(0.1f, 0.1f, 0.1f); //color
    glVertex3d(cx-3.0,cy+1.0,0.0);
    glEnd();

    glPopMatrix();
}
void fence()
{
    //fench right start

    //fench horizontal line 1

    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(100.0,-26.0,0.0);
    glVertex3d(100.0,-25.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(46.0,-25.0,0.0);
    glVertex3d(46.0,-26.0,0.0);

    glEnd();


    //fench horizontal line 2

    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(100.0,-38.0,0.0);
    glVertex3d(100.0,-37.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(46.0,-37.0,0.0);
    glVertex3d(46.0,-38.0,0.0);

    glEnd();

    //fench vertical lines start

    //1
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(50.0,-38.0,0.0);
    glVertex3d(50.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(49.0,-23.0,0.0);
    glVertex3d(49.0,-39.0,0.0);

    glEnd();

    //2
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(54.0,-38.0,0.0);
    glVertex3d(54.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(53.0,-23.0,0.0);
    glVertex3d(53.0,-39.0,0.0);

    glEnd();

    //3
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(58.0,-38.0,0.0);
    glVertex3d(58.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(57.0,-23.0,0.0);
    glVertex3d(57.0,-39.0,0.0);

    glEnd();

    //4
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(62.0,-38.0,0.0);
    glVertex3d(62.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(61.0,-23.0,0.0);
    glVertex3d(61.0,-39.0,0.0);

    glEnd();

    //5
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(66.0,-38.0,0.0);
    glVertex3d(66.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(65.0,-23.0,0.0);
    glVertex3d(65.0,-39.0,0.0);

    glEnd();

    //6
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(70.0,-38.0,0.0);
    glVertex3d(70.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(69.0,-23.0,0.0);
    glVertex3d(69.0,-39.0,0.0);

    glEnd();

    //7
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(74.0,-38.0,0.0);
    glVertex3d(74.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(73.0,-23.0,0.0);
    glVertex3d(73.0,-39.0,0.0);

    glEnd();

    //8
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(78.0,-38.0,0.0);
    glVertex3d(78.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(77.0,-23.0,0.0);
    glVertex3d(77.0,-39.0,0.0);

    glEnd();

    //9
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(82.0,-38.0,0.0);
    glVertex3d(82.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(81.0,-23.0,0.0);
    glVertex3d(81.0,-39.0,0.0);

    glEnd();

    //10
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(86.0,-38.0,0.0);
    glVertex3d(86.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(85.0,-23.0,0.0);
    glVertex3d(85.0,-39.0,0.0);

    glEnd();

    //11
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(90.0,-38.0,0.0);
    glVertex3d(90.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(89.0,-23.0,0.0);
    glVertex3d(89.0,-39.0,0.0);

    glEnd();

    //12
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(94.0,-38.0,0.0);
    glVertex3d(94.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(93.0,-23.0,0.0);
    glVertex3d(93.0,-39.0,0.0);

    glEnd();

    //13
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(98.0,-38.0,0.0);
    glVertex3d(98.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(97.0,-23.0,0.0);
    glVertex3d(97.0,-39.0,0.0);

    glEnd();

    //fench vertical lines end

    //fench  right end


    //fench left start

    //fench horizontal line 1

    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-100.0,-26.0,0.0);
    glVertex3d(-100.0,-25.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-46.0,-25.0,0.0);
    glVertex3d(-46.0,-26.0,0.0);

    glEnd();


    //fench horizontal line 2

    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-100.0,-38.0,0.0);
    glVertex3d(-100.0,-37.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-46.0,-37.0,0.0);
    glVertex3d(-46.0,-38.0,0.0);

    glEnd();

    //fench vertical lines start

    //1
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-50.0,-38.0,0.0);
    glVertex3d(-50.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-49.0,-23.0,0.0);
    glVertex3d(-49.0,-39.0,0.0);

    glEnd();

    //2
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-54.0,-38.0,0.0);
    glVertex3d(-54.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-53.0,-23.0,0.0);
    glVertex3d(-53.0,-39.0,0.0);

    glEnd();

    //3
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-58.0,-38.0,0.0);
    glVertex3d(-58.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-57.0,-23.0,0.0);
    glVertex3d(-57.0,-39.0,0.0);

    glEnd();

    //4
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-62.0,-38.0,0.0);
    glVertex3d(-62.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-61.0,-23.0,0.0);
    glVertex3d(-61.0,-39.0,0.0);

    glEnd();

    //5
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-66.0,-38.0,0.0);
    glVertex3d(-66.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-65.0,-23.0,0.0);
    glVertex3d(-65.0,-39.0,0.0);

    glEnd();

    //6
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-70.0,-38.0,0.0);
    glVertex3d(-70.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-69.0,-23.0,0.0);
    glVertex3d(-69.0,-39.0,0.0);

    glEnd();

    //7
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-74.0,-38.0,0.0);
    glVertex3d(-74.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-73.0,-23.0,0.0);
    glVertex3d(-73.0,-39.0,0.0);

    glEnd();

    //8
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-78.0,-38.0,0.0);
    glVertex3d(-78.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-77.0,-23.0,0.0);
    glVertex3d(-77.0,-39.0,0.0);

    glEnd();

    //9
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-82.0,-38.0,0.0);
    glVertex3d(-82.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-81.0,-23.0,0.0);
    glVertex3d(-81.0,-39.0,0.0);

    glEnd();

    //10
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-86.0,-38.0,0.0);
    glVertex3d(-86.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-85.0,-23.0,0.0);
    glVertex3d(-85.0,-39.0,0.0);

    glEnd();

    //11
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-90.0,-38.0,0.0);
    glVertex3d(-90.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-89.0,-23.0,0.0);
    glVertex3d(-89.0,-39.0,0.0);

    glEnd();

    //12
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-94.0,-38.0,0.0);
    glVertex3d(-94.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-93.0,-23.0,0.0);
    glVertex3d(-93.0,-39.0,0.0);

    glEnd();

    //13
    glBegin(GL_QUADS);

    glColor3f(0.9f,0.5f,0.3f); //color

    glVertex3d(-98.0,-38.0,0.0);
    glVertex3d(-98.0,-22.0,0.0);

    glColor3f(0.6f,0.3f,0.0f); //color

    glVertex3d(-97.0,-23.0,0.0);
    glVertex3d(-97.0,-39.0,0.0);

    glEnd();

    //fench vertical lines end

    //fench  right end
}
void graveyard1(float x, float y)
{
    glColor3f(0.5f,0.6f,0.7f);
    drawCircle(x+58,y-2,2,2,100);

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+56.0,y-2.0,0.0);
    glVertex3d(x+56.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-2.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+55.0,y-5.0,0.0);
    glVertex3d(x+55.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-5.0,0.0);
    glEnd();
}
void graveyard2(float x, float y)
{
    glColor3f(0.5f,0.6f,0.7f);
    drawCircle(x+58,y-2,2,2,100);

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+56.0,y-2.0,0.0);
    glVertex3d(x+56.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-2.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+55.0,y-5.0,0.0);
    glVertex3d(x+55.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-5.0,0.0);
    glEnd();
}
void graveyard3(float x, float y)
{
    glColor3f(0.5f,0.6f,0.7f);
    drawCircle(x+58,y-2,2,2,100);

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+56.0,y-2.0,0.0);
    glVertex3d(x+56.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-2.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+55.0,y-5.0,0.0);
    glVertex3d(x+55.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-5.0,0.0);
    glEnd();
}
void graveyard4(float x, float y)
{
    glColor3f(0.5f,0.6f,0.7f);
    drawCircle(x+58,y-2,2,2,100);

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+56.0,y-2.0,0.0);
    glVertex3d(x+56.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-2.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+55.0,y-5.0,0.0);
    glVertex3d(x+55.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-5.0,0.0);
    glEnd();
}
void graveyard5(float x, float y)
{
    glColor3f(0.5f,0.6f,0.7f);
    drawCircle(x+58,y-2,2,2,100);

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+56.0,y-2.0,0.0);
    glVertex3d(x+56.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-2.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+55.0,y-5.0,0.0);
    glVertex3d(x+55.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-5.0,0.0);
    glEnd();
}
void graveyard6(float x, float y)
{
    glColor3f(0.5f,0.6f,0.7f);
    drawCircle(x+58,y-2,2,2,100);

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+56.0,y-2.0,0.0);
    glVertex3d(x+56.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-2.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+55.0,y-5.0,0.0);
    glVertex3d(x+55.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-5.0,0.0);
    glEnd();
}
void graveyard7(float x, float y)
{
    glColor3f(0.5f,0.6f,0.7f);
    drawCircle(x+58,y-2,2,2,100);

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+56.0,y-2.0,0.0);
    glVertex3d(x+56.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-2.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+55.0,y-5.0,0.0);
    glVertex3d(x+55.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-5.0,0.0);
    glEnd();
}
void graveyard8(float x, float y)
{
    glColor3f(0.5f,0.6f,0.7f);
    drawCircle(x+58,y-2,2,2,100);

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+56.0,y-2.0,0.0);
    glVertex3d(x+56.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-5.0,0.0);
    glVertex3d(x+60.0,y-2.0,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f,0.6f,0.7f);
    glVertex3d(x+55.0,y-5.0,0.0);
    glVertex3d(x+55.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-6.0,0.0);
    glVertex3d(x+61.0,y-5.0,0.0);
    glEnd();
}
void pumpkin1(float cx, float cy)
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glScalef(1.5f, 1.5f, 0.0f);
    // body
    glColor3f(1.0f, 0.5f, 0.0f); // Pumpkin color
    drawCircle(cx, cy, 5, 5, 100); // Main body

    // Mouth
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(cx, cy, 4, 4, 100);
    glColor3f(1.0f, 0.5f, 0.0f);
    drawCircle(cx, cy + 1, 4, 4, 100);


    // eyes
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for eyes
    drawCircle(cx - 2, cy + 2, 1, 1, 100); // Left eye
    drawCircle(cx + 2, cy + 2, 1, 1, 100); // Right eye

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3d(cx - 3, cy + 4, 0.0);
    glVertex3d(cx + 3, cy + 4, 0.0);
    glVertex3d(cx, cy, 0.0);
    glEnd();


    // stem
    glColor3f(0.5f, 0.25f, 0.0f); // Brown color for the stem
    glBegin(GL_QUADS);
    glVertex3d(cx - 0.5, cy + 5, 0.0); // Left bottom of stem
    glVertex3d(cx + 0.5, cy + 5, 0.0); // Right bottom of stem
    glVertex3d(cx + 0.3, cy + 6, 0.0); // Right top of stem
    glVertex3d(cx - 0.3, cy + 6, 0.0); // Left top of stem
    glEnd();
    glPopMatrix();
}
void pumpkin2(float cx, float cy)
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glScalef(1.5f, 1.5f, 1.5f);
    // Draw pumpkin body (using multiple segments for a more textured look)
    glColor3f(1.0f, 0.5f, 0.0f); // Pumpkin color
    drawCircle(cx, cy, 5, 5, 100); // Main body

    // Mouth
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(cx, cy, 4, 4, 100);
    glColor3f(1.0f, 0.5f, 0.0f);
    drawCircle(cx, cy + 1, 4, 4, 100);


    // Draw pumpkin eyes
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for eyes
    drawCircle(cx - 2, cy + 2, 1, 1, 100); // Left eye
    drawCircle(cx + 2, cy + 2, 1, 1, 100); // Right eye

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3d(cx - 3, cy + 4, 0.0);
    glVertex3d(cx + 3, cy + 4, 0.0);
    glVertex3d(cx, cy, 0.0);
    glEnd();


    // Draw pumpkin stem
    glColor3f(0.5f, 0.25f, 0.0f); // Brown color for the stem
    glBegin(GL_QUADS);
    glVertex3d(cx - 0.5, cy + 5, 0.0); // Left bottom of stem
    glVertex3d(cx + 0.5, cy + 5, 0.0); // Right bottom of stem
    glVertex3d(cx + 0.3, cy + 6, 0.0); // Right top of stem
    glVertex3d(cx - 0.3, cy + 6, 0.0); // Left top of stem
    glEnd();
    glPopMatrix();
}
void candle1()
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glTranslatef(-40.0f, -80.0f, 0.0f);
    //flame
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.4f,0.0f); //color
    glVertex3d(0.0,8.0,0.0);
    glVertex3d(-1.0,6.0,0.0);
    glColor3f(1.0f,0.8f,0.0f); //color
    glVertex3d(0.0,4.0,0.0);
    glVertex3d(1.0,6.0,0.0);
    glEnd();
    //thread
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f); //color
    glVertex3d(0.0,3.0,0.0);
    glVertex3d(0.0,5.0,0.0);
    glEnd();
    //body
    glBegin(GL_QUADS);
    glColor3f(0.9f,1.0f,1.0f); //color
    glVertex3d(-1.0,3.0,0.0);
    glVertex3d(-1.0,-5.0,0.0);
    glVertex3d(1.0,-5.0,0.0);
    glVertex3d(1.0,3.0,0.0);
    glEnd();
    glPopMatrix();
}
void candle2()
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glTranslatef(40.0f, -80.0f, 0.0f);
    //flame
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.4f,0.0f); //color
    glVertex3d(0.0,8.0,0.0);
    glVertex3d(-1.0,6.0,0.0);
    glColor3f(1.0f,0.8f,0.0f); //color
    glVertex3d(0.0,4.0,0.0);
    glVertex3d(1.0,6.0,0.0);
    glEnd();
    //thread
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f); //color
    glVertex3d(0.0,3.0,0.0);
    glVertex3d(0.0,5.0,0.0);
    glEnd();
    //body
    glBegin(GL_QUADS);
    glColor3f(0.9f,1.0f,1.0f); //color
    glVertex3d(-1.0,3.0,0.0);
    glVertex3d(-1.0,-5.0,0.0);
    glVertex3d(1.0,-5.0,0.0);
    glVertex3d(1.0,3.0,0.0);
    glEnd();
    glPopMatrix();
}
void candle3()
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glTranslatef(0.0f, -60.0f, 0.0f);
    //flame
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.4f,0.0f); //color
    glVertex3d(0.0,8.0,0.0);
    glVertex3d(-1.0,6.0,0.0);
    glColor3f(1.0f,0.8f,0.0f); //color
    glVertex3d(0.0,4.0,0.0);
    glVertex3d(1.0,6.0,0.0);
    glEnd();
    //thread
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f); //color
    glVertex3d(0.0,3.0,0.0);
    glVertex3d(0.0,5.0,0.0);
    glEnd();
    //body
    glBegin(GL_QUADS);
    glColor3f(0.9f,1.0f,1.0f); //color
    glVertex3d(-1.0,3.0,0.0);
    glVertex3d(-1.0,-5.0,0.0);
    glVertex3d(1.0,-5.0,0.0);
    glVertex3d(1.0,3.0,0.0);
    glEnd();
    glPopMatrix();
}
void candle4()
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glTranslatef(90.0f, -70.0f, 0.0f);
    //flame
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.4f,0.0f); //color
    glVertex3d(0.0,8.0,0.0);
    glVertex3d(-1.0,6.0,0.0);
    glColor3f(1.0f,0.8f,0.0f); //color
    glVertex3d(0.0,4.0,0.0);
    glVertex3d(1.0,6.0,0.0);
    glEnd();
    //thread
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f); //color
    glVertex3d(0.0,3.0,0.0);
    glVertex3d(0.0,5.0,0.0);
    glEnd();
    //body
    glBegin(GL_QUADS);
    glColor3f(0.9f,1.0f,1.0f); //color
    glVertex3d(-1.0,3.0,0.0);
    glVertex3d(-1.0,-5.0,0.0);
    glVertex3d(1.0,-5.0,0.0);
    glVertex3d(1.0,3.0,0.0);
    glEnd();
    glPopMatrix();
}
void candle5()
{
    glPushMatrix(); // Saves the current state of the transformation matrix.
    glTranslatef(-90.0f, -70.0f, 0.0f);
    //flame
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.4f,0.0f); //color
    glVertex3d(0.0,8.0,0.0);
    glVertex3d(-1.0,6.0,0.0);
    glColor3f(1.0f,0.8f,0.0f); //color
    glVertex3d(0.0,4.0,0.0);
    glVertex3d(1.0,6.0,0.0);
    glEnd();
    //thread
    glBegin(GL_LINES);
    glColor3f(1.0f,1.0f,1.0f); //color
    glVertex3d(0.0,3.0,0.0);
    glVertex3d(0.0,5.0,0.0);
    glEnd();
    //body
    glBegin(GL_QUADS);
    glColor3f(0.9f,1.0f,1.0f); //color
    glVertex3d(-1.0,3.0,0.0);
    glVertex3d(-1.0,-5.0,0.0);
    glVertex3d(1.0,-5.0,0.0);
    glVertex3d(1.0,3.0,0.0);
    glEnd();
    glPopMatrix(); // Restores the transformation matrix to the state before glPushMatrix was called.
}
void halloween()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clears the window to the current background color.

    background();

    star();

    moon();

    witch();

    house();

    scarecrowleft();
    scarecrowRight();

    scarecrow1();
    scarecrow2();

    bat1(moving);  // Pass the moving (dy) to move the bat

    //right bat
    bat2(35,22, moving);
    bat3(40,29, moving);
    bat4(30,35, moving);

    //left bat
    bat5(-35,22, moving);
    bat6(-40,29, moving);
    bat7(-30,35, moving);

    fence();

    // right graveyards
    graveyard1(-2,-10);
    graveyard2(25,-15);
    graveyard3(12,0);
    graveyard4(35,0);
    //left graveyards
    graveyard5(-150,0);
    graveyard6(-140,-15);
    graveyard7(-130,0);
    graveyard8(-115,-10);

    pumpkin1(-45, -40);
    pumpkin2(45, -40);

    candle1();
    candle2();
    candle3();
    candle4();
    candle5();
    glutSwapBuffers();

    glFlush(); // Forces execution of OpenGL commands to ensure all commands are completed.
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(750,750);
    glutInitWindowPosition(400,10);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Halloween Night");
    init();                                     // Call the initialization function.
    glutDisplayFunc(halloween);
    glutTimerFunc(0, timer, 0);                 // Start the animation
    glutTimerFunc(0, updateWitchPosition, 0);   // Start the timer for automatic movement
    sndPlaySound("halloween-story-256807.wav", SND_ASYNC);
    glutMainLoop();                             // Enter the GLUT event processing loop.
    return 0;
}
