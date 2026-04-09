/**
 * @file tkjhat/pins.h
 * \author Iván Sánchez Milara
 * @brief Macros including the pins of the HAT.
 *
 * 
 * @version 0.83
 */
 

/* =========================
 *  Board / pin macros
 * ========================= */

/**
 * @defgroup board_pins Board and pin definitions
 * @brief Default GPIO assignments for peripherals on the JTKJ HAT.
 *
 * @details
 * These macros define the GPIO pin numbers for peripherals and interfaces
 * used by the SDK. They can be referenced directly or overridden at compile time
 * if custom wiring is used.
 *
 * **Default pinout:**
 * | Function | Macro | GPIO | Notes |
 * |-----------|--------|------|-------|
 * | I²C SDA   | @ref DEFAULT_I2C_SDA_PIN | 12 | Default I²C data |
 * | I²C SCL   | @ref DEFAULT_I2C_SCL_PIN | 13 | Default I²C clock |
 * | UART0     | @ref DEFAULT_UART_0      | 0  | Primary UART port |
 * | UART1     | @ref DEFAULT_UART_1      | 1  | Secondary UART port |
 * | SW1       | @ref SW1_PIN / @ref BUTTON1 | 2  | User button 1 |
 * | SW2       | @ref SW2_PIN / @ref BUTTON2 | 22 | User button 2 |
 * | Red LED   | @ref RED_LED_PIN / @ref LED1 | 14 | Onboard LED |
 * | RGB LED R | @ref RGB_LED_R | 18 | RGB red channel |
 * | RGB LED G | @ref RGB_LED_G | 19 | RGB green channel |
 * | RGB LED B | @ref RGB_LED_B | 20 | RGB blue channel |
 * | Buzzer    | @ref BUZZER_PIN | 17 | Active buzzer |
 * | PDM DATA  | @ref PDM_DATA | 16 | Microphone data line |
 * | PDM CLK   | @ref PDM_CLK | 15 | Microphone clock line |
 * | VEML6030 Interrupt | @ref VEML6030_INTERRUPT | 9  | Light sensor INT pin |
 * | HDC2021 Interrupt  | @ref HDC2021_INTERRUPT | 21 | Temp/humidity INT pin |
 * | ICM42670 Interrupt | @ref ICM42670_INT | 6  | IMU INT1 pin |
 *
 * @note These pin numbers correspond to the Raspberry Pi Pico GPIO numbers.
 * @{
 */

/** @name I²C Bus (default)
 *  I2C bus pins.
 *  @{
 */

#define DEFAULT_I2C_SDA_PIN   12  /**< I²C data pin (SDA) */
#define DEFAULT_I2C_SCL_PIN   13  /**< I²C clock pin (SCL) */
/** @} */

/** @name Temperature/Humidity Sensor (HDC2021)
 *  @{
 */
#define HDC2021_INTERRUPT     21   /**< Temperature & humidity sensor interrupt pin (GPIO 21) */
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

/** @name Interrupts from Sensors
 *  @{
 */
#define VEML6030_INTERRUPT    9   /**< Ambient light sensor interrupt pin */
#define HDC2021_INTERRUPT     21  /**< Temperature & humidity sensor interrupt pin */
#define ICM42670_INT          6   /**< IMU interrupt pin */
/** @} */

/** @} */ /* end of group board_pins */


/**
 * @defgroup Macros Macros including addresses and registers of peripherals 
 * @brief Register addresses and constants for the different sensors and actuators of the HAT.
 * @{
 */

/** @name VEML6030
 *  Light sensor address, and registers
 *  @{ */
#define VEML6030_I2C_ADDR                       0x10   /**< I2C address of the VEML6030 sensor. */
#define VEML6030_CONFIG_REG                     0x00   /**< Configuration register. */
#define VEML6030_ALS_REG                        0x04   /**< Ambient Light Sensing (ALS) data register. */
/** @} */

/* =========================
 *  HDC2021
 * ========================= */

 /** @name HDC2021
 *  Humidity sensor address, registers and interruptions thresholds
 *  @{ */
#define HDC2021_I2C_ADDRESS                     0x40   /**< I2C address of the HDC2021 sensor. */
#define HDC2021_TEMP_LOW                        0x00   /**< Temperature low byte register. */
#define HDC2021_TEMP_HIGH                       0x01   /**< Temperature high byte register. */
#define HDC2021_HUMIDITY_LOW                    0x02   /**< Humidity low byte register. */
#define HDC2021_HUMIDITY_HIGH                   0x03   /**< Humidity high byte register. */
#define HDC2021_CONFIG                          0x0E   /**< Configuration register. */
#define HDC2021_MEASUREMENT_CONFIG              0x0F   /**< Measurement configuration register. */
#define HDC2021_TEMP_THR_L                      0x13   /**< Low temperature threshold. */
#define HDC2021_TEMP_THR_H                      0x14   /**< High temperature threshold. */
#define HDC2021_HUMID_THR_L                     0x15   /**< Low humidity threshold. */
#define HDC2021_HUMID_THR_H                     0x16   /**< High humidity threshold. */
/** @} */


/* =========================
 *  SSD1306
 * ========================= */

/** @name Display
 *  SSD1306 display address 
 *  @{ */
#define SSD1306_I2C_ADDRESS                     0x3C   /**< I2C address of the SSD1306 OLED display. */
/** @} */

/* =========================
 *  MEMS MICROPHONE
 * ========================= */
/** @name Microphone
 *  Microphone's sampling rate and buffer size. 
 *  @{ */
#define MEMS_SAMPLING_FREQUENCY                 8000   /**< Sampling frequency in Hz for PDM microphone. */
#define MEMS_BUFFER_SIZE                        256    /**< Number of samples in each microphone buffer. */
/** @} */

/* =========================
 *  ICM-42670 (IMU)
 * ========================= */

/** @name I2C addressing
 *  I2C address and identity registers.
 *  @{ */
#define ICM42670_I2C_ADDRESS                    0x69   /**< Default I2C address (AD0 pulled). */
#define ICM42670_I2C_ADDRESS_ALT                0x69   /**< Alternate I2C address (autodetect helper uses both). */
#define ICM42670_REG_WHO_AM_I                   0x75   /**< WHO_AM_I register address. */
#define ICM42670_WHO_AM_I_RESPONSE              0x67   /**< Expected WHO_AM_I value. */
/** @} */

/** @name Interrupts
 *  Interrupt configuration registers and defaults.
 *  @{ */
#define ICM42670_INT_CONFIG                     0x06   /**< INT1/INT2 routing/config register. */
#define ICM42670_INT1_CONFIG_VALUE              0x02   /**< Default INT1 config: active-low, pulsed (course default). */
/** @} */

/** @name Transfer limits
 *  Helper limits for SDK buffer handling.
 *  @{ */
#define ICM42670_MAX_READ_LENGTH                256    /**< Max contiguous read length used by the SDK. */
#define ICM42670_MAX_WRITE_LENGTH               256    /**< Max contiguous write length used by the SDK. */
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

/** @name Accelerometer FSR encodings
 *  ACCEL_CONFIG0[7:5]. Full-scale range selection.
 *  @{ */
#define ICM42670_ACCEL_FSR_2G                   0x03   /**< ±2 g. */
#define ICM42670_ACCEL_FSR_4G                   0x02   /**< ±4 g. */
#define ICM42670_ACCEL_FSR_8G                   0x01   /**< ±8 g. */
#define ICM42670_ACCEL_FSR_16G                  0x00   /**< ±16 g. */
#define ICM42670_ACCEL_FSR_DEFAULT              4      /**< SDK default FSR in g (±4 g). */
/** @} */

/** @name Gyroscope FSR encodings
 *  GYRO_CONFIG0[7:5]. Full-scale range selection.
 *  @{ */
#define ICM42670_GYRO_FSR_250DPS                0x03   /**< ±250 dps. */
#define ICM42670_GYRO_FSR_500DPS                0x02   /**< ±500 dps. */
#define ICM42670_GYRO_FSR_1000DPS               0x01   /**< ±1000 dps. */
#define ICM42670_GYRO_FSR_2000DPS               0x00   /**< ±2000 dps. */
#define ICM42670_GYRO_FSR_DEFAULT               250    /**< SDK default FSR in dps (±250 dps). */
/** @} */

/** @name Accelerometer ODR encodings (LN mode)
 *  ACCEL_CONFIG0[3:0]. Output Data Rate selection in Low-Noise mode.
 *  @{ */
#define ICM42670_ACCEL_ODR_25HZ                 0x0B   /**< 25 Hz. */
#define ICM42670_ACCEL_ODR_50HZ                 0x0A   /**< 50 Hz. */
#define ICM42670_ACCEL_ODR_100HZ                0x09   /**< 100 Hz. */
#define ICM42670_ACCEL_ODR_200HZ                0x08   /**< 200 Hz. */
#define ICM42670_ACCEL_ODR_400HZ                0x07   /**< 400 Hz. */
#define ICM42670_ACCEL_ODR_800HZ                0x06   /**< 800 Hz. */
#define ICM42670_ACCEL_ODR_1600HZ               0x05   /**< 1600 Hz. */
#define ICM42670_ACCEL_ODR_DEFAULT              100    /**< SDK default ODR in Hz (100 Hz). */
/** @} */

/** @name Gyroscope ODR encodings
 *  GYRO_CONFIG0[3:0]. Output Data Rate selection.
 *  @{ */
#define ICM42670_GYRO_ODR_25HZ                  0x0B   /**< 25 Hz. */
#define ICM42670_GYRO_ODR_50HZ                  0x0A   /**< 50 Hz. */
#define ICM42670_GYRO_ODR_100HZ                 0x09   /**< 100 Hz. */
#define ICM42670_GYRO_ODR_200HZ                 0x08   /**< 200 Hz. */
#define ICM42670_GYRO_ODR_400HZ                 0x07   /**< 400 Hz. */
#define ICM42670_GYRO_ODR_800HZ                 0x06   /**< 800 Hz. */
#define ICM42670_GYRO_ODR_1600HZ                0x05   /**< 1600 Hz. */
#define ICM42670_GYRO_ODR_DEFAULT               100    /**< SDK default ODR in Hz (100 Hz). */
/** @} */

/** @name Power / mode bits
 *  Encodings for PWR_MGMT0 sensor-mode fields.
 *  @{ */
#define ICM42670_ACCEL_MODE_LN                  0x03   /**< Accel Low-Noise mode code for PWR_MGMT0 accel field. */
#define ICM42670_GYRO_MODE_LN                   0x0C   /**< Gyro Low-Noise mode code for PWR_MGMT0 gyro field. */
/** @} */

/** @name Sensor data window
 *  Starting register for burst reads of temp/accel/gyro data.
 *  @{ */
#define ICM42670_SENSOR_DATA_START_REG          0x09   /**< First data register for TEMP/ACCEL/GYRO burst read. */
/** @} */

/** @} */ /* end of group  of registers*/
