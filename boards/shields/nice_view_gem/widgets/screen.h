#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>
#include "util.h"

#define CANVAS_WIDTH  SCREEN_WIDTH
#define CANVAS_HEIGHT SCREEN_HEIGHT
#define CANVAS_PIXELS (CANVAS_WIDTH * CANVAS_HEIGHT)

struct zmk_widget_screen {
    sys_snode_t node;
    lv_obj_t *obj;
    lv_color_t cbuf[CANVAS_PIXELS];
    struct status_state state;
};

int zmk_widget_screen_init(struct zmk_widget_screen *widget, lv_obj_t *parent);
lv_obj_t *zmk_widget_screen_obj(struct zmk_widget_screen *widget);
