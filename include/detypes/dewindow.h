
#ifndef DE_WINDOW_H_
#define DE_WINDOW_H_

    #ifdef __ANDROID__

        #include <SDL.h>
        #include <SDL_syswm.h>

    #else
    
        #include <SDL2/SDL.h>
        #include <SDL2/SDL_syswm.h>

    #endif


    #include <stdio.h>

    #define defalt_windows_x_size 1000


    extern int i;


    extern void minhacoisa(void);


#endif /*DE_WINDOW_H_ */
