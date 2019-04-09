/*
** EPITECH PROJECT, 2019
** menu
** File description:
** Creation of menu
*/

#include "../include/runner.h"

void handle_event(back_t *back, chara_t *chara, vege_t *vege, ground_t *ground)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(back->window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(back->window);
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            back->begining = sfMusic_createFromFile("sound/here_we_go.wav");
            sfMusic_play(back->begining);
            my_runner(chara, vege, back, ground);
        }
    }
}

void create_menu(back_t *back)
{
    back->menu_s = sfSprite_create();
    back->menu = sfTexture_createFromFile("img/menu.png", NULL);
    sfSprite_setTexture(back->menu_s, back->menu, sfTrue);
}

void menu(back_t *back, chara_t *chara, vege_t *vege, ground_t *ground)
{
    sfVideoMode video_mode = {1920, 1080, 32};

    back->window = sfRenderWindow_create(video_mode, "My_runner", sfResize |
    sfFullscreen, NULL);
    create_all(back, chara, vege, ground);
    sfMusic_play(back->music);
    sfMusic_setLoop(back->music, sfTrue);
    create_menu(back);
    sfRenderWindow_setMouseCursorVisible(back->window, sfFalse);
    while (sfRenderWindow_isOpen(back->window)) {
        sfRenderWindow_clear(back->window, sfBlack);
        handle_event(back, chara, vege, ground);
        sfRenderWindow_drawSprite(back->window, back->menu_s, NULL);
        sfRenderWindow_display(back->window);
    }
    sfMusic_destroy(back->begining);
    sfMusic_destroy(back->music);
    sfSprite_destroy(back->menu_s);
    sfTexture_destroy(back->menu);
}
