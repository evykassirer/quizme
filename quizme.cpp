#include<stdio.h>
#include<iostream>
#include<string>
#include <ctime>
//#include <allegro.h>
#include"quizme.h"
#include"quizme_functions.cpp"
using namespace std;


int main(/*int argc, char *argv[]*/) {  
    /*
    //initialize Allegro
    allegro_init();
    set_color_depth(32); 
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 540,550,0,0); 
    
    //install mouse
    install_mouse();
    enable_hardware_cursor();
    select_mouse_cursor(MOUSE_CURSOR_ARROW);
    show_mouse(screen);
    
    //install keyboard
    install_keyboard(); 
    */        
    if(takeinput()) return 1;
    if(mainMenu()) return 0;
}
//END_OF_MAIN();



