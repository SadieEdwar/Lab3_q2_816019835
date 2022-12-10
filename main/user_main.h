/* gpio example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "driver/gpio.h"

#include "esp_log.h"
#include "esp_system.h"

static const char *TAG = "main";
static const char *active_delay_tag = "Actively waited ...";
static const char *status_message = "Status message";
static const char *UnityStrPass  = "PASS";
static const char *UnityStrFail = "FAIL";
static const char *active_delay_fail = "Did not actively wait for ...";
/**
 * Brief:
 * This test code shows how to configure gpio and how to use mutex
 * GPIO status messages
 * GPIO2: output
 */

#define GPIO_OUTPUT_IO_0     2
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<GPIO_OUTPUT_IO_0) 

//Global variables
//static xQueueHandle gpio_evt_queue = NULL;
static SemaphoreHandle_t xSemaphore = NULL;

static TaskHandle_t Handle1 = NULL;

static TaskHandle_t Handle2 = NULL;

static TaskHandle_t Handle3 = NULL;

static TaskHandle_t Handle_test1 = NULL;

static TaskHandle_t Handle_integrated_test1 = NULL;

static void active_delay();

static void gpio_task_1_sharingPin( void *arg );

static void gpio_task_2_sharingPin( void *arg );

static void gpio_task_3_message(void *arg);

static void unitTest_active_delay(void *arg);

static int unitTest_gpio_task_3_message();

static void integrated_test1(void *arg);

void app_main(void);
