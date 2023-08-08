#include <main.h>


bool can_quit = true;


int main(int argument_count, char *argument_values[])
{

    if (SDL_Init( SDL_INIT_EVENTS | SDL_INIT_VIDEO) != 0)
    {
    
        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());

        return 1;

    }
    

    if (setup_main_window("test", SDL_WINDOW_RESIZABLE) == false)
    {

        fprintf(stderr, "Failed on setup main window: %s\n", SDL_GetError());

        return 1;

    }
    
    /*Temp: */
        can_quit = false;

    SDL_Event event;

    while (can_quit == false)
    {

        while (SDL_PollEvent(&event))
        {

            switch (event.type)
            {
            
            case SDL_QUIT:

                can_quit = true;

                break;
            
            }

        }

    }


    return 0;

}


#if defined(_WIN32) && !defined(NDEBUG)

#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    UNREFERENCED_PARAMETER(hPrevInstance);

    return main(__argc, __argv);

}

#endif
