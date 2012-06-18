#include "Button.h"

Button::Button(){
    x = -1;
    y = -1;
    width = -1;
    height = -1;
    icon = NULL;
    lastPos = NULL;
}

void Button::sleep(){
    lastPos == NULL;
}

bool Button::checkMouseClick(int X, int Y, bool click){
        if(click == true)
        {
             if(Y >= y &&
               Y <= y + height &&
               X >= x &&
               X <= x + width)
               {
                   return true;
               }
        }
    return false;
}
bool Button::checkMouseOver(int X, int Y){

    if(Y >= y &&
       Y <= y + height &&
       X >= x &&
       X <= x + width)
       {
           return true;
       }
    return false;
}

bool Button::checkMouseExit(int X, int Y){
    if(lastPos == NULL)
    {
        lastPos = checkMouseOver(X, Y);
        return false;
    }
    else
    {
        if(lastPos == true && checkMouseOver(X, Y) == false)
        {
            lastPos = false;
            return true;
        }
    }
    return false;
}

bool Button::checkIfValid() {
    if( x > 0 && x < 2000 &&
        y > 0 && y < 2000 &&
        width > 0 && width < 2000 &&
        height > 0 && height < 2000)
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
    return icon;
}

void Button::setIcon(SDL_Surface* newIcon){
    icon = newIcon;
}
