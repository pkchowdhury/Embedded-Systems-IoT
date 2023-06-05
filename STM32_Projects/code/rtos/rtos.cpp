// #include <Arduino.h>
// #include <STM32FreeRTOS.h>
// #include <queue.h>
// #include <modem.h>

// QueueHandle_t xQueue;

// // MQTT details
// String broker = "thinkiot.com.bd";
// String clientId = "SN002";
// String userName = "SN002";
// String pass = "SN002";

// void gpsTask( void *pvParameters );
// void flashReceive( void *pvParameters );
// void modemReceive( void *pvParameters);
// void loraTask(void *pvParameters);

// void setup() 
// {
//   Serial.begin(9600);
//   xQueue = xQueueCreate( 5, sizeof( char* ) );

// if( xQueue != NULL )
// {
// xTaskCreate( gpsTask, "GPS Sender", 240, NULL, 1, NULL );
// xTaskCreate( loraTask, "Lora Sender", 240, NULL, 2, NULL );
// xTaskCreate( modemReceive, "Modem Receive", 240, NULL, 1, NULL );
// xTaskCreate( flashReceive, "Flash Receive", 240, NULL, 2, NULL );

// vTaskStartScheduler();
// }
// else
// {
// /* The queue could not be created. */
// }

// }

// void loop()
// {
//   // put your main code here, to run repeatedly:

// }

// void vSenderTask( void *pvParameters )
// {
// char* data = "{\"id\":69}";
// char* rData = "{\"clientKeys\":\"id\"}";

    
//     // modemInit();
//     // delay(30000);

//     // gprsInit();
//     // delay(2000);
//     // mqttConnect(clientId, broker, userName, pass);
//     // delay(1000);
//     // subscribe(0);
//     // delay(2000);



// for( ;; )
// {
// xQueueSend( xQueue, &data, portMAX_DELAY == pdPASS );
// Serial.print( "Sent = ");
// Serial.println(data);

// vTaskDelay(1000);
// }
// }


// void vReceiverTask( void *pvParameters )
// {
// char* lReceivedValue;
// for( ;; )
// {

// if (xQueueReceive( xQueue, &lReceivedValue, portMAX_DELAY ) == pdPASS)
// {
// Serial.print( "Received = ");
// Serial.println(lReceivedValue);
// vTaskDelay(1000);
// }
// taskYIELD();

// }
// }