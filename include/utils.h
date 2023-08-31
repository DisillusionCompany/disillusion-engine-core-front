

#ifndef UTILS_H
#define UTILS_H

    #ifdef __ANDROID__

        #include <SDL.h>
    
    #else
    
        #include <SDL2/SDL.h>
    
    #endif


    #include <stdio.h>


    extern void print_str_SDL_Rect(char *str, SDL_Rect rect);

#endif
