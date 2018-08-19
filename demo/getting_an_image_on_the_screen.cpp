#include <SDL2/SDL.h>
#include <cstdio>


// global var
// the window we'll br rendering to
SDL_Window* gWindow = NULL;

// the surface contained bby the window
SDL_Surface* gScreenSurface = NULL;

// the image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const char * IMAGE_PATH = "data/show_hello.bmp";

// start up sdl and creates window
bool init();

// loads media
bool loadMedia();

// frees media and shuts down sdl
void close();


bool init() {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        printf("sdl could not initialize! sdl error; %s\n", SDL_GetError());
    } else {
        // creae window
        gWindow = SDL_CreateWindow("sdl tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, \
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("window could not be created！ sdl error: %s\n", SDL_GetError());
            success = false;
        } else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

bool loadMedia() {
    // loading success flag
    bool success = true;
    char * hello_image_file_path = "data/show_hello.bmp";
    gHelloWorld = SDL_LoadBMP(hello_image_file_path);
    if (gHelloWorld == NULL) {
        printf("unable to load image %s! sdl error: %s\n", hello_image_file_path);
        success = false;
    }
    return success;
}

void close() {
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow=NULL;
    SDL_Quit();
}


int main() {

    if (!init()) {
        printf("failed to initialize!\n");
    } else {
        if (!loadMedia()) {
            printf("failed to load media!\n");
        } else {
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);
            //wait 2000 ms
            SDL_Delay(2000);
        }
    }
    close();
    return 0;
}
