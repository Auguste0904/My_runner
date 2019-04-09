/*
** EPITECH PROJECT, 2018
** event_close
** File description:
** event_close
*/

#include "../include/runner.h"

void key_pressed_move_rect(chara_t *chara)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        sfSprite_setPosition(chara->chara_s, (sfVector2f){250, 780});
        move_rect_down(chara, 220, 603);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) ||
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        move_rect_jump(chara, 148.99999, 860);
    }
}

void event_close(back_t *back, chara_t *chara)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(back->window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(back->window);
        if ((sfKeyboard_isKeyPressed(sfKeySpace) ||
            sfKeyboard_isKeyPressed(sfKeyUp)) &&
            sfSprite_getPosition(chara->chara_s).y >= 750)
            chara->jumping.y = -12;
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyDown)
            sfSprite_setPosition(chara->chara_s, (sfVector2f){250, 750});
    }
    key_pressed_move_rect(chara);
    move_rect_bird(chara, 171, 505);
    move_rect_wolf(chara, 108, 430);
}
