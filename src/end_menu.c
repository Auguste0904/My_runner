/*
** EPITECH PROJECT, 2019
** end_menu
** File description:
** end_menu
*/

#include "../include/runner.h"

void event_menu(back_t *back)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(back->window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(back->window);
        if (sfKeyboard_isKeyPressed(sfKeyReturn))
            sfRenderWindow_close(back->window);
    }
}

void create_end_menu(back_t *back)
{
    back->end_menu_s = sfSprite_create();
    back->end_menu = sfTexture_createFromFile("img/end_menu.png", NULL);
    sfSprite_setTexture(back->end_menu_s, back->end_menu, sfTrue);
}

void create_end_menu2(back_t *back)
{
    back->win_s = sfSprite_create();
    back->win = sfTexture_createFromFile("img/victory_menu.png", NULL);
    sfSprite_setTexture(back->win_s, back->win, sfTrue);
}

void end_menu_win(back_t *back)
{
    create_end_menu2(back);
    while (sfRenderWindow_isOpen(back->window)) {
        event_menu(back);
        sfRenderWindow_drawSprite(back->window, back->win_s, NULL);
        sfRenderWindow_display(back->window);
    }
    sfSprite_destroy(back->win_s);
    sfTexture_destroy(back->win);
    sfMusic_destroy(back->win_sound);
}

void end_menu_loop(back_t *back)
{
    create_end_menu(back);
    while (sfRenderWindow_isOpen(back->window)) {
        event_menu(back);
        sfRenderWindow_drawSprite(back->window, back->end_menu_s, NULL);
        sfRenderWindow_drawText(back->window, back->score_nb, NULL);
        sfText_setPosition(back->score_nb, (sfVector2f){1050, 420});
        sfText_setColor(back->score_nb, sfBlack);
        sfText_setCharacterSize(back->score_nb, 120);
        sfRenderWindow_display(back->window);
    }
    sfMusic_destroy(back->loose);
    sfSprite_destroy(back->end_menu_s);
    sfTexture_destroy(back->end_menu);
}