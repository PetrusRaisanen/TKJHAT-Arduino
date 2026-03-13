/**
 * @file tkjhat/pins.h
 */

/** @name I²C Bus (default)
 *  I2C bus pins.
 *  @{
 */
#define DEFAULT_I2C_SDA_PIN   12  /**< I²C data pin (SDA) */
#define DEFAULT_I2C_SCL_PIN   13  /**< I²C clock pin (SCL) */
/** @} */

/** @name Buttons / Switches
 *  @{
 */
#define SW1_PIN               2   /**< SW1 button pin (GPIO 2) */
#define SW2_PIN               22  /**< SW2 button pin (GPIO 22) */
/** @} */


/** @name LEDs
 *  @{
 */
#define RED_LED_PIN           14  /**< Onboard red LED pin (GPIO 14) */
/** @} */

/** @name Buzzer
 *  @{
 */
#define BUZZER_PIN            17  /**< Buzzer control pin (GPIO 17) */
/** @} */


/** @name RGB LED (common-anode)
 *  @{
 */
#define RGB_LED_R             18  /**< RGB LED red channel (GPIO 18) */
#define RGB_LED_G             19  /**< RGB LED green channel (GPIO 19) */
#define RGB_LED_B             20  /**< RGB LED blue channel (GPIO 20) */
/** @} */


/** @name PDM Microphone
 *  @{
 */
#define PDM_DATA              16  /**< Microphone data input (GPIO 16) */
#define PDM_CLK               15  /**< Microphone clock output (GPIO 15) */
/** @} */

/** @name Display
 *  SSD1306 display address 
 *  @{ */
#define SSD1306_I2C_ADDRESS                     0x3C   /**< I2C address of the SSD1306 OLED display. */
/** @} */

/** @name I2C addressing
 *  I2C address and identity registers.
 *  @{ */
#define ICM42670_I2C_ADDRESS                    0x69   /**< Default I2C address (AD0 pulled). */
#define ICM42670_I2C_ADDRESS_ALT                0x69   /**< Alternate I2C address (autodetect helper uses both). */
#define ICM42670_REG_WHO_AM_I                   0x75   /**< WHO_AM_I register address. */
#define ICM42670_WHO_AM_I_RESPONSE              0x67   /**< Expected WHO_AM_I value. */
/** @} */

/** @name Configuration registers
 *  Top-level configuration register addresses.
 *  @{ */
#define ICM42670_ACCEL_CONFIG0_REG              0x21   /**< Accelerometer ODR/FSR (see bit fields below). */
#define ICM42670_GYRO_CONFIG0_REG               0x20   /**< Gyroscope ODR/FSR (see bit fields below). */
#define ICM42670_PWR_MGMT0_REG                  0x1F   /**< Power state / sensor mode control. */
#define ICM42670_REG_SIGNAL_PATH_RESET          0x02   /**< Signal path reset register. */
#define ICM42670_RESET_CONFIG_BITS              0x10   /**< Value used for soft reset sequence. */
/** @} */
