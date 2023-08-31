#include <main_window.h>


bool        main_window_quit = true;


Uint32      main_window_flags = 0x00;


SDL_Rect    main_window_rect     = { SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720 };

SDL_Rect    main_window_min_rect = { -1, -1, 1280, 720  };

SDL_Rect    main_window_max_rect = { -1, -1, 1920, 1080 };


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

    main_window_flags = SDL_GetWindowFlags(main_window);


    return true;

}


void update_main_window_attributes()
{

    main_window_flags = SDL_GetWindowFlags(main_window);

    
    SDL_GetWindowSize    (main_window, &main_window_rect.w, &main_window_rect.h);

    SDL_GetWindowPosition(main_window, &main_window_rect.x, &main_window_rect.y);


    // printf("%d, %d\n", main_window_rect.y, main_window_rect.x);
    

    return;

}


void handle_main_window(SDL_WindowEvent *window_event)
{

    switch (window_event->event)
    {
    
    case SDL_WINDOWEVENT_RESIZED:

        printf("%d, %d\n", mouse_global_point.x, mouse_global_point.y);

        if (main_window_rect.w < main_window_min_rect.w)
        {

            printf("window x: %d, mouse x: %d", main_window_rect.x, mouse_global_point.x);

            if (main_window_rect.x >= mouse_global_point.x)
            {

                SDL_SetWindowPosition(main_window, main_window_rect.x -= (main_window_min_rect.w - main_window_rect.w), main_window_rect.y);

            }


            main_window_rect.w = main_window_min_rect.w;

            SDL_SetWindowSize(main_window, main_window_min_rect.w, main_window_rect.h);

        }


        if (main_window_rect.h < main_window_min_rect.h)
        {

            if (main_window_rect.y >= mouse_global_point.y)
            {

                SDL_SetWindowPosition(main_window, main_window_rect.x, main_window_rect.y -= (main_window_min_rect.h - main_window_rect.h));

            }


            main_window_rect.h = main_window_min_rect.h;

            SDL_SetWindowSize(main_window, main_window_rect.w, main_window_min_rect.h);      

        }


        break;

    case SDL_WINDOWEVENT_MOVED:
        
        main_window_rect.x = window_event->data1;
        
        main_window_rect.y = window_event->data2;

        break;

    case SDL_WINDOWEVENT_SIZE_CHANGED:

        main_window_rect.w = window_event->data1;
        
        main_window_rect.h = window_event->data2;

        break;

    case SDL_WINDOWEVENT_MINIMIZED:
        
        
        
        break;
        
    case SDL_WINDOWEVENT_MAXIMIZED:



        break;

    default:

#ifndef NDEBUG

        fprintf(stderr, "todo: %d\n", window_event->event);

#endif

        break;
    
    }

    return;

}
