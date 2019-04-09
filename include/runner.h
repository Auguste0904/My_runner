/*
** EPITECH PROJECT, 2018
** runner
** File description:
** Proto
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>

#ifndef RUNNER_H_
#define RUNNER_H_
#define READ_SIZE 10000

typedef struct chara
{
    sfSprite *chara_s;
    sfTexture *chara;
    sfSprite *wolf_s;
    sfTexture *wolf;
    sfSprite *bird_s;
    sfTexture *bird;
    sfSprite *flag_s;
    sfTexture *flag;
    sfClock *clock;
    sfTime time;
    sfClock *clock_bird;
    sfTime time_bird;
    sfClock *clock_wolf;
    sfTime time_wolf;
    sfVector2f jumping;
}chara_t;

typedef struct vege
{
    sfSprite *plantes_s;
    sfTexture *plantes;
    sfSprite *mountain_s;
    sfTexture *mountain;
    sfClock *clock;
    sfTime time;
}vege_t;

typedef struct ground
{
    sfSprite *ground_s;
    sfTexture *ground;
    sfSprite *tree_s;
    sfTexture *tree;
}ground_t;

typedef struct back
{
    char *map;
    sfRenderWindow *window;
    int i;
    sfClock *cl_score;
    sfText *score_nb;
    sfText *score;
    sfFont *font;
    sfTexture *menu;
    sfSprite *menu_s;
    sfTexture *background;
    sfSprite *background_s;
    sfTexture *trees;
    sfSprite *trees_s;
    sfTexture *cloud;
    sfSprite *cloud_s;
    sfTexture *far_cloud;
    sfSprite *far_cloud_s;
    sfTexture *far_cloud2;
    sfSprite *far_cloud2_s;
    sfTexture *fog;
    sfSprite *fog_s;
    sfSprite *end_menu_s;
    sfTexture *end_menu;
    sfSprite *win_s;
    sfTexture *win;
    sfMusic *music;
    sfMusic *begining;
    sfMusic *loose;
    sfMusic *win_sound;
}back_t;

void my_putchar(char c);
int my_strlen(char const *str);
void help(void);
int my_putstr(char const *str);
int my_runner(chara_t *chara, vege_t *vege, back_t *back, ground_t *ground);
void draw_menu(back_t *back);
void create_menu(back_t *back);
void menu(back_t *back, chara_t *chara, vege_t *vege, ground_t *ground);
void score(back_t *back);
void move_rect(chara_t *chara, int offset, int max_value);
void all_destroy(back_t *back, chara_t *chara, vege_t *vege, ground_t *ground);
void move_para(back_t *back, vege_t *vege, ground_t *ground);
void draw_back(back_t *back);
void draw_para(back_t *back, vege_t *vege, ground_t *ground);
void forward(back_t *back, vege_t *vege, ground_t *ground);
void backward(back_t *back, vege_t *vege, ground_t *ground);
void background(back_t *back);
void plantes(vege_t *vege);
void chara_sprite(chara_t *chara);
void sol(ground_t *ground, vege_t *vege);
int my_strcmp(char const *s1, char const *s2);
void move_rect_down(chara_t *chara, int offset, int max_value);
void move_rect_jump(chara_t *chara, float offset, int max_value);
void move_rect_bird(chara_t *chara, int offset, int max_value);
void move_rect_wolf(chara_t *chara, int offset, int max_value);
void event_close(back_t *back, chara_t *chara);
void create_all(back_t *back, chara_t *chara, vege_t *vege, ground_t *ground);
char *my_itoa(int nb);
void clock_score(back_t *back);
void end_menu_loop(back_t *back);
void end_menu_win(back_t *back);

#endif
