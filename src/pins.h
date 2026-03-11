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

