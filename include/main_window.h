
#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

    #include <input/mouse.h>

    #ifdef __ANDROID__

        #include <SDL.h>
        #include <SDL_syswm.h>

    #else
    
        #include <SDL2/SDL.h>
        #include <SDL2/SDL_syswm.h>

    #endif


    #include <stdbool.h>
    #include <stdio.h>


    extern bool        main_window_quit;


    extern Uint32      main_window_flags;

    extern SDL_Rect    main_window_rect;

    extern SDL_Rect    main_window_min_rect;

    extern SDL_Rect    main_window_max_rect;


    extern SDL_Window *main_window;


    extern SDL_SysWMinfo main_window_info;


    extern bool setup_main_window(const char *title, Uint32 flags);
    

    extern void update_main_window_attributes(void);

    extern void handle_main_window(SDL_WindowEvent *event);


    extern void quit_main_window(void);

#endif
