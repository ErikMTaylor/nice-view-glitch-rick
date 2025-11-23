#include <stdlib.h>
#include <zephyr/kernel.h>
#include "rick_animation.h"

LV_IMG_DECLARE(rick_01);
LV_IMG_DECLARE(rick_02);
LV_IMG_DECLARE(rick_03);
LV_IMG_DECLARE(rick_04);
LV_IMG_DECLARE(rick_05);
LV_IMG_DECLARE(rick_06);
LV_IMG_DECLARE(rick_07);
LV_IMG_DECLARE(rick_08);
LV_IMG_DECLARE(rick_09);
LV_IMG_DECLARE(rick_10);
LV_IMG_DECLARE(rick_11);
LV_IMG_DECLARE(rick_12);
LV_IMG_DECLARE(rick_13);
LV_IMG_DECLARE(rick_14);
LV_IMG_DECLARE(rick_15);
LV_IMG_DECLARE(rick_16);

const lv_img_dsc_t *anim_imgs[] = {
    &rick_01, &rick_02, &rick_03, &rick_04, &rick_05, &rick_06,
    &rick_07, &rick_08, &rick_09, &rick_10, &rick_11, &rick_12,
    &rick_13, &rick_14, &rick_15, &rick_16,
};

void draw_rick_animation(lv_obj_t *canvas) {
#if IS_ENABLED(CONFIG_NICE_VIEW_RICK_ANIMATION)
    lv_obj_t *art = lv_animimg_create(canvas);
    lv_obj_center(art);

    lv_animimg_set_src(art, (const void **)anim_imgs, 16);
    lv_animimg_set_duration(art, CONFIG_NICE_VIEW_RICK_ANIMATION_MS);
    lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(art);
#else
    lv_obj_t *art = lv_img_create(canvas);

    int length = sizeof(anim_imgs) / sizeof(anim_imgs[0]);
    srand(k_uptime_get_32());
    int random_index = rand() % length;

    lv_img_set_src(art, anim_imgs[random_index]);
#endif

    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 34, 0);
}