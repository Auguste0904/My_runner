/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner game
*/

#include "../include/runner.h"

void colision(chara_t *chara, back_t *back)
{
    sfFloatRect player = sfSprite_getGlobalBounds(chara->chara_s);
    sfFloatRect wolf = sfSprite_getGlobalBounds(chara->wolf_s);
    sfFloatRect bird = sfSprite_getGlobalBounds(chara->bird_s);

    if (sfFloatRect_intersects(&player, &wolf, NULL) == sfTrue) {
        back->loose = sfMusic_createFromFile("sound/game_over.wav");
        sfMusic_play(back->loose);
        sfMusic_stop(back->music);
        end_menu_loop(back);
    }
    if (sfFloatRect_intersects(&player, &bird, NULL) == sfTrue) {
        back->loose = sfMusic_createFromFile("sound/game_over.wav");
        sfMusic_play(back->loose);
        sfMusic_stop(back->music);
        end_menu_loop(back);
    }
}

void draw_chara(back_t *back, chara_t *chara)
{
    sfVector2f move_wolf = {-10, 0};
    sfVector2f move_bird = {1920, 653};
    sfVector2f speed_bird = {-14, 0};

    sfRenderWindow_drawSprite(back->window, chara->chara_s, NULL);
    sfSprite_move(chara->chara_s, chara->jumping);
    sfRenderWindow_drawSprite(back->window, chara->wolf_s, NULL);
    sfSprite_move(chara->wolf_s, move_wolf);
    if (sfSprite_getPosition(chara->wolf_s).x < -140)
        sfSprite_setPosition(chara->wolf_s, (sfVector2f){1920, 825});
    sfRenderWindow_drawSprite(back->window, chara->bird_s, NULL);
    sfSprite_move(chara->bird_s, speed_bird);
    if (sfSprite_getPosition(chara->bird_s).x < -170) {
        sfSprite_setPosition(chara->bird_s, move_bird);
    }
}

void jumping(chara_t *chara)
{
    if (sfSprite_getPosition(chara->chara_s).y > 750)
        chara->jumping.y = 0;
    else
        chara->jumping.y += 0.4;
}

void display(back_t *back, chara_t *chara, vege_t *vege, ground_t *ground)
{
    chara->jumping = (sfVector2f){0, 0};

    while (sfRenderWindow_isOpen(back->window)) {
        draw_back(back);
        draw_para(back, vege, ground);
        move_para(back, vege, ground);
        event_close(back, chara);
        draw_chara(back, chara);
        sfRenderWindow_drawText(back->window, back->score, NULL);
        sfRenderWindow_drawSprite(back->window, chara->flag_s, NULL);
        sfSprite_move(chara->flag_s, (sfVector2f){-10, 0});
        move_rect(chara, 154, 884);
        jumping(chara);
        clock_score(back);
        colision(chara, back);
        sfRenderWindow_display(back->window);
    }
    all_destroy(back, chara, vege, ground);
}

int my_runner(chara_t *chara, vege_t *vege, back_t *back, ground_t *ground)
{
    sfSprite_setPosition(chara->wolf_s, (sfVector2f){1920, 825});
    sfSprite_setPosition(chara->bird_s, (sfVector2f){1920, 653});
    sfRenderWindow_setFramerateLimit(back->window, 60);
    sfSprite_setPosition(chara->chara_s, (sfVector2f){250, 750});
    display(back, chara, vege, ground);
    return (0);
}
