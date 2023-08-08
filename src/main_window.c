#include <main_window.h>


bool        main_window_quit = true;


Uint32      main_window_flags = 0x00;

SDL_Rect    main_window_rect  = { SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720 };

SDL_Window *main_window       = NULL;


SDL_SysWMinfo main_window_info;


bool setup_main_window(const char *title, Uint32 flags)
{

    if ((main_window = SDL_CreateWindow(title, main_window_rect.x, main_window_rect.y, main_window_rect.w, main_window_rect.h, flags)) == NULL)
    {

        fprintf(stderr, "todo: %s\n", SDL_GetError());

        return false;

    }

    
    SDL_VERSION(&main_window_info.version);

    if (SDL_GetWindowWMInfo(main_window, &main_window_info) == SDL_FALSE)
    {

        fprintf(stderr, "todo: %s\n", SDL_GetError());
    
        return false;

    }


    main_window_quit = false;


    return true;

}


void update_main_window_attributes()
{




    return;

}

