#include "Button.h"

Button::Button(){
    x = -1;
    y = -1;
    width = -1;
    height = -1;
    lastPos = NULL;
    icon = NULL;
}


void Button::sleep(){
    lastPos = NULL;
}

bool Button::checkMouseClick(int X, int Y, bool click){

        if(click && checkMouseOver(X, Y))
            return true;

    return false;
}
bool Button::checkMouseOver(int X, int Y){

    if(Y >= y &&
       Y <= y + height &&
       X >= x &&
       X <= x + width)//If the mouse is within the bounds of the button when the click happens
       {
           return true;
       }
    return false;
}

bool Button::checkMouseExit(int X, int Y){
    if(lastPos == NULL)//If we don't know if the mouse was previously on or outside the button
    {
        lastPos = checkMouseOver(X, Y);//Check it now
        return false;
    }
    else
    {
        if(lastPos == true && checkMouseOver(X, Y) == false)//If the mouse was on the button last time we checked, but it is no more
        {
            lastPos = false;
            return true;
        }
    }
    return false;
}

bool Button::checkIfValid() {
    if( x >= 0 && x < SCREEN_WIDTH &&
        y >= 0 && y < SCREEN_HEIGHT &&
        width > 0 && width < SCREEN_WIDTH &&
        height > 0 && height < SCREEN_HEIGHT &&
        icon != NULL)//Checks if the variables are set to a correct number
        return true;

    return false;
}


int Button::getX(){
    return x;
}

int Button::getY(){
    return y;
}

void Button::setX(int val){
    x = val;
}

void Button::setY(int val){
    y = val;
}

int Button::getWidth(){
    return width;
}

int Button::getHeight(){
    return height;
}

void Button::setWidth(int val){
    width = val;
}

void Button::setHeight(int val){
    height = val;
}

SDL_Surface* Button::getIcon(){
    return *icon;
}

void Button::setIcon(SDL_Surface** newIcon){
    icon = newIcon;
}
