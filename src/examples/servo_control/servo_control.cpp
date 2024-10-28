#include <px4_platform_common/log.h>
#include <px4_platform_common/module.h>
#include <drivers/drv_pwm_output.h>
#include <px4_platform_common/px4_config.h>
#include <unistd.h>

class SimplePWMServoController : public ModuleBase<SimplePWMServoController>
{
public:
    SimplePWMServoController() = default;
    ~SimplePWMServoController() = default;

    int start() {
        PX4_INFO("Servo kontrol başlatılıyor...");

        // Servo pin numarasını ve PWM ayarlarını belirle
        const int pwm_pin = 1; // Servo motorunun bağlı olduğu pin
        const int min_pwm = 1000; // Minimum PWM değeri (1ms)
        const int max_pwm = 2000; // Maksimum PWM değeri (2ms)

        // Servo açısını belirle (örnek olarak 90 derece)
        float angle = 0.5f; // 0.5 = 90 derece

        // PWM değerini hesapla
        int pwm_value = min_pwm + (int)((max_pwm - min_pwm) * angle);

        // PWM sinyali gönder
        pwm_out_set(pwm_pin, pwm_value);

        PX4_INFO("Servo %d için PWM değeri ayarlandı: %d", pwm_pin, pwm_value);

        return 0;
    }

    void stop() {
        PX4_INFO("Servo kontrol durduruluyor...");
    }

private:
    void pwm_out_set(int pin, int pwm_value) {
        // PWM değerini pin'e ayarlamak için kullanılan fonksiyon
        int ret = up_pwm_servo_set(pin, pwm_value);
        if (ret < 0) {
            PX4_ERR("PWM ayarlanamadı: %d", ret);
        } else {
            PX4_INFO("PWM %d için %d ayarlandı.", pin, pwm_value);
        }
    }
};

extern "C" __EXPORT int simple_pwm_servo_controller_main(int argc, char *argv[]);

int simple_pwm_servo_controller_main(int argc, char *argv[])
{
    PX4_INFO("Simple PWM Servo Controller başlatılıyor...");
    SimplePWMServoController controller;
    controller.start();
    return 0;
}

