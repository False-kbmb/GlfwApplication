#include <GLFW/glfw3.h>
#include <math.h>

#define PI 3.14159265358979323846

void drawCircle(float x, float y, float radius, float red, float green, float blue, float alpha) {
    glPushMatrix();
    glBegin(GL_LINE_LOOP);

    glColor4f(red / 255, green / 255, blue / 255, alpha / 255);

    for (int i = 0; i <= 360; i++) {
        glVertex2f((float)cos(i * PI / 180) * radius + x, (float)sin(i * PI / 180) * radius + y);
    }

    glEnd();
    glPopMatrix();
}

void drawCircle(float x, float y, float z, float radius, float red, float green, float blue, float alpha) {
    glPushMatrix();
    glBegin(GL_LINE_LOOP);

    glColor4f(red / 255, green / 255, blue / 255, alpha / 255);

    for (int i = 0; i <= 360; i++) {
        glVertex3f((float)cos(i * PI / 180) * radius + x, (float)sin(i * PI / 180) * radius + y, z);
    }

    glEnd();
    glPopMatrix();
}

void drawSineGraph(double x, double wavelength, float red, float green, float blue, float alpha) {
    glBegin(GL_LINE_STRIP);
    glColor4f(red / 255, green / 255, blue / 255, alpha / 255);

    for (double d = x * PI; d <= x + wavelength; d += 0.001) {
        glVertex2d(d / 10, sin(d) / 10);
    }

    glEnd();
}

void drawCosineGraph(double x, double wavelength, float red, float green, float blue, float alpha) {
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glColor4f(red / 255, green / 255, blue / 255, alpha / 255);

    for (double d = x * PI; d <= x + wavelength; d += 0.001) {
        glVertex2d(d / 10, cos(d) / 10);
    }

    glEnd();
    glPopMatrix();
}