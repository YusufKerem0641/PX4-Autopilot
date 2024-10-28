#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/tasks.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <parameters/param.h>

__EXPORT int servo_control_main(int argc, char *argv[]);

int servo_control_main(int argc, char *argv[]) {
    // PWM_AUX_DIS1 parametresinin handle'ını al
    param_t pwm_aux_dis1_handle = param_find("PWM_AUX_DIS1");
    
    if (pwm_aux_dis1_handle == PARAM_INVALID) {
        printf("PWM_AUX_DIS1 parametresi bulunamadı.\n");
        return -1;
    }

    // PWM_AUX_DIS1 değerini 1200 olarak ayarla
    int pwm_value = 1600;
    if (param_set(pwm_aux_dis1_handle, &pwm_value) != OK) {
        printf("PWM_AUX_DIS1 parametresi ayarlanamadı.\n");
        return -1;
    }

    printf("PWM_AUX_DIS1 başarıyla %d olarak ayarlandı.\n", pwm_value);
    
    return 0;
}

