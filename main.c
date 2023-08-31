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

        update_mouse();

        update_main_window_attributes();


        while (SDL_PollEvent(&event))
        {

            switch (event.type)
            {
            
            case SDL_QUIT:

                can_quit = true;

                break;


            case SDL_WINDOWEVENT:

                if (event.window.windowID == SDL_GetWindowID(main_window))
                {

                    handle_main_window(&event.window);

                }

                break;

            default:
                break;
            
            }

        }

        // system("cls");

        // for (int i = 0; i < numButtons; i++)
        // {   

        //     printf("controleer butom %d, value: %d\n", i, SDL_JoystickGetButton(gGameController, i));

        // }

        SDL_Delay(1);

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
