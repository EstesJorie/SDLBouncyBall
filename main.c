#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 900
#define HEIGHT 600

struct Circle
{
    double x;
    double y;
    double vx; 
    double vy; 
    double gravity;
    double radius;
    double dampening;
};

void updatePosition(struct Circle *pcircle)
{
    double newX = pcircle->x + pcircle->vx;
    double newY = pcircle->y + pcircle->vy;
    double newVy = pcircle->vy - pcircle->gravity;
    double radius = pcircle->radius;

    pcircle->x = newX;
    pcircle->y = newY;
    pcircle->vy = newVy;

    if(pcircle->x < 0+radius)
    {
        pcircle->x = radius;
        pcircle->vx = -pcircle->vx; //invert
        pcircle->vx *= pcircle->dampening;
    }
    if(pcircle->x > WIDTH+radius)
    {
        pcircle->x = WIDTH-radius;
        pcircle->vx = -pcircle->vx; //invert
        pcircle->vx *= pcircle->dampening;

    }
    if(pcircle->y < 0+radius)
    {
        pcircle->y = radius;
        pcircle->vy = -pcircle->vy; //invert
        pcircle->vy *= pcircle->dampening;

    }
    if(pcircle->y > HEIGHT-radius)
    {
        pcircle->y = HEIGHT-radius;
        pcircle->vy = -pcircle->vy; //invert
        pcircle->vy *= pcircle->dampening;

    }
}

void drawCircle(SDL_Renderer *prenderer, struct Circle *pcircle)
 {
    SDL_SetRenderDrawColor(prenderer, 0x00, 0xff, 0x00, 0x00);
    double y = pcircle->y;
    double x = pcircle->x;
    for(double i=x-pcircle->radius; i<x+pcircle->radius; i++)
    {
        for(double j=y-pcircle->radius;j<y+pcircle->radius; j++)
        {
            double dist = sqrt(pow(i-x, 2) + pow(j-y, 2));
            if(dist< pcircle->radius)
            {
                SDL_RenderDrawPoint(prenderer, i, j);
            }
        }
    }
    SDL_RenderPresent(prenderer);
}

int main(){
    printf("Hello Circle\n");
    SDL_Init(SDL_INIT_VIDEO);

    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *pwindow = SDL_CreateWindow("Bouncing Circle", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    
    SDL_Renderer *prenderer = SDL_CreateRenderer(pwindow, 0, 0);
    SDL_RenderClear(prenderer); //clear renderer

    SDL_Rect background_rect = (struct SDL_Rect) {0, 0, WIDTH, HEIGHT};
    SDL_SetRenderDrawColor(prenderer, 0x00, 0x00, 0x00, 0x00); //background color
    SDL_RenderFillRect(prenderer, &background_rect);

    int quit = 0;
    struct Circle circle = (struct Circle){100, 100, 10 ,10, -10, 60, 0.9};

    while(!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                printf("Quit application\n");
                quit=1;
            }
        }
        SDL_SetRenderDrawColor(prenderer, 0x00, 0x00, 0x00, 0x00); //background color

        SDL_RenderClear(prenderer);
        updatePosition(&circle);
        drawCircle(prenderer, &circle);
        SDL_Delay(20); //20ms delay

    }


    Uint32 start = SDL_GetTicks();
    SDL_Event e;
    int running = 1;

    while (running && (SDL_GetTicks() - start < 3000)) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = 0;
            }
        }
        SDL_Delay(10);  
    }

    SDL_DestroyRenderer(prenderer);
    SDL_DestroyWindow(pwindow);
    SDL_Quit();

    return 0;
}