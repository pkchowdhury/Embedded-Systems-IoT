// #include <ModbusRTU.h>
// ModbusRTU mb;

// #include <SoftwareSerial.h>
// int DE_RE = 4; //D4  For MAX485 chip
// int RX = 12;
// int TX = 13;

// SoftwareSerial S(RX, TX);//D6/D7  (RX , TX)

// uint16_t Mread0[2];

// bool cbWrite(Modbus::ResultCode event, uint16_t transactionId, void* data) {
//   Serial.printf_P("Request result: 0x%02X, Mem: %d\n", event, ESP.getFreeHeap());
//   return true;
// }

// void setup() {
//   Serial.begin(115200);
//   S.begin(9600, SWSERIAL_8N2);
//   mb.begin(&S, DE_RE); //Assing Software serial port to Modbus instance for MAX485 chip having DI,DE,RE,RO Pin at TTL side
//   mb.master(); //Assing Modbus function as master
//   Serial.println(); //Print empty line
//   Serial.println(sizeof(Mread0)); //Reaing size of first array
// }
// void loop() {
//   if (!mb.slave()) {
//     mb.readHreg(1, 2699, Mread0, 2 , cbWrite);  //(SlaevID,Address,Buffer,Range of data,Modus call)
//     Serial.println(InttoFloat(Mread0[0], Mread0[1]));
//   }
//   mb.task();
//   delay(1000);
//   yield();
// }



































// // //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// // #include <SimpleModbusMaster.h>
// // //////////////////// Port information ///////////////////
// // #define baud 9600
// // #define timeout 100
// // #define polling 20 // the scan rate
// // #define retry_count 10

// // // used to toggle the receive/transmit pin on the driver
// // #define TxEnablePin 2
// // // The total amount of available memory on the master to store data
// // #define TOTAL_NO_OF_REGISTERS 30

// // // This is the easiest way to create new packets
// // // Add as many as you want. TOTAL_NO_OF_PACKETS
// // // is automatically u pdated.
// // enum
// // {
// //   PACKET1,
// //   PACKET2,
// //   //  PACKET3,
// //   //  PACKET4,
// //   //  PACKET5,
// //   //  PACKET6,
// //   //  PACKET7,
// //   //  PACKET8,
// //   //  PACKET9,
// //   //  PACKET10,
// //   //  PACKET11,
// //   //  PACKET12,
// //   //  PACKET13,
// //   //  PACKET14,
// //   //  PACKET15,
// //   //  PACKETn,

// //   TOTAL_NO_OF_PACKETS // leave this last entry
// // };

// // // Create an array of Packets to be configured
// // Packet packets[TOTAL_NO_OF_PACKETS];

// // // Masters register array
// // unsigned int regs[TOTAL_NO_OF_REGISTERS];

// // void setup()
// // {
// //   // Initialize each packet
// //   Serial.begin(9600);
// //   //    Serial1.begin(9600);READ_HOLDING_REGISTERS 43118
// //   //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// //   //  modbus_construct(&packets[PACKET1], 1(adres PM710 sampai ke n), READ_INPUT_REGISTERS, 4010(adress registry), 1(jenis data), 10(pengurutan data sampai ke n));
// //   //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// //   modbus_construct(&packets[PACKET1], 1, READ_HOLDING_REGISTERS, 3027, 2, 10); //L-N                  //A
// //   modbus_construct(&packets[PACKET2], 1, READ_HOLDING_REGISTERS, 3109, 2, 11); //Frekuency            //B
// //   //    modbus_construct(&packets[PACKET3], 1, READ_INPUT_REGISTERS, 4032, 1, 12); //A-N                  //C
// //   //    modbus_construct(&packets[PACKET4], 1, READ_INPUT_REGISTERS, 4033, 1, 13); //B-N                  //D
// //   //    modbus_construct(&packets[PACKET5], 1, READ_INPUT_REGISTERS, 4034, 1, 14); //C-N                  //E
// //   //
// //   //    modbus_construct(&packets[PACKET6], 2, READ_INPUT_REGISTERS, 3998, 2, 15); //REAL ENERGY          //F
// //   //    modbus_construct(&packets[PACKET7], 1, READ_INPUT_REGISTERS, 4005, 1, 16); //REAL POWER           //G
// //   //    modbus_construct(&packets[PACKET8], 1, READ_INPUT_REGISTERS, 4006, 1, 17); //AMP POWER            //H
// //   //    modbus_construct(&packets[PACKET9], 1, READ_INPUT_REGISTERS, 4007, 1, 18); //KVAR DAYA REAKTIF    //I
// //   //
// //   //    modbus_construct(&packets[PACKET10], 1, READ_INPUT_REGISTERS, 4029, 1, 19); //A-B                  //J
// //   //    modbus_construct(&packets[PACKET11], 1, READ_INPUT_REGISTERS, 4030, 1, 20); //B-C                  //K
// //   //    modbus_construct(&packets[PACKET12], 1, READ_INPUT_REGISTERS, 4031, 1, 21); //C-A                  //L
// //   //
// //   //    modbus_construct(&packets[PACKET13], 1, READ_INPUT_REGISTERS, 4019, 1, 22); //ARUS A               //M
// //   //    modbus_construct(&packets[PACKET14], 1, READ_INPUT_REGISTERS, 4020, 1, 23); //ARUS B               //N
// //   //    modbus_construct(&packets[PACKET15], 1, READ_INPUT_REGISTERS, 4021, 1, 24); //ARUS C               //O
// //   //
// //   //modbus_construct(&packets[PACKET2], 3, PRESET_MULTIPLE_REGISTERS, 0, 1, 20);
// //   /*
// //   Valid modbus byte formats are:
// //   SERIAL_8N2: 1 start bit, 8 data bits, 2 stop bits
// //   SERIAL_8E1: 1 start bit, 8 data bits, 1 Even parity bit, 1 stop bit
// //   SERIAL_8O1: 1 start bit, 8 data bits, 1 Odd parity bit, 1 stop bit
// //   */
// //   // Initialize the Modbus Finite State Machine
// //   modbus_configure(&Serial3, baud, SERIAL_8N1, timeout, polling, retry_count, TxEnablePin, packets, TOTAL_NO_OF_PACKETS, regs);
// // }

// // void loop()
// // {
// //   modbus_update();

// //   int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O;

// //   A = regs[10];
// //   B = regs[11];
// //   //    C = regs[12];
// //   //    D = regs[13];
// //   //    E = regs[14];
// //   //    F = regs[15];
// //   //    G = regs[16];
// //   //    H = regs[17];
// //   //    I = regs[18];
// //   //    J = regs[19];
// //   //    K = regs[20];
// //   //    L = regs[21];
// //   //    M = regs[22];
// //   //    N = regs[23];
// //   //    O = regs[24];
// //   //    n = regs[n];

// //   Serial.print("A = ");
// //   Serial.println(A);
// // //  Serial.println(A / 77.69624);

// //   Serial.print("B = ");
// //     Serial.println(B);
// // //  Serial.println(B / 333.333333);
// //   //
// //   //    Serial.print("C = ");
// //   //    Serial.println(C/10);
// //   //
// //   //    Serial.print("D = ");
// //   //    Serial.println(D/10);
// //   //
// //   //    Serial.print("E = ");
// //   //    Serial.println(E/10);
// //   //
// //   //    Serial.print("F = ");
// //   //    Serial.println(F);
// //   //
// //   //    Serial.print("G = ");
// //   //    Serial.println(G);
// //   //
// //   //    Serial.print("H = ");
// //   //    Serial.println(H);
// //   //
// //   //    Serial.print("I = ");
// //   //    Serial.println(I);
// //   //
// //   //    Serial.print("J = ");
// //   //    Serial.println(J);
// //   //
// //   //    Serial.print("K = ");
// //   //    Serial.println(K);
// //   //
// //   //    Serial.print("L = ");
// //   //    Serial.println(L);
// //   //
// //   //    Serial.print("M = ");
// //   //    Serial.println(M);
// //   //
// //   //    Serial.print("N = ");
// //   //    Serial.println(N);
// //   //
// //   //    Serial.print("O = ");
// //   //    Serial.println(O);
// //   Serial.println("============================================");
// //   delay(500);

// //   //Voltage2 = regs[12];
// //   //Serial.print("Voltage L-N : ");
// //   //Serial.print(Voltage);
// //   //Serial.println(" V");
// //   //Serial.println(Voltage1);
// //   //Serial.println(Voltage2);
// //   //Serial.println(regs[10]);
// //   //Serial.println(regs[11]);

// //   //  Serial.println("DEBUG                     || OUTPUT");
// //   //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// //   //  Serial.print("requests: ");
// //   //  Serial.print(packets[PACKET1].requests);
// //   //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// //   //    Serial.print(" || Voltage L-N :");
// //   //    Serial.println(Voltage);
// //   //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// //   //    Serial.print(" || Voltage L-N :");
// //   //    Serial.print(Voltage/10);
// //   //    Serial.println("   Volt");
// //   //    Serial.println("=======================================");
// //   //    Serial.print(" || Frekuency   :");
// //   //    Serial.print(F/100);
// //   //    Serial.println(" Hz");
// //   //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// //   //              Serial.println(" V");
// //   Serial.print("successful_requests: ");
// //   Serial.println(packets[PACKET1].successful_requests);
// //   Serial.println("                        || ");
// //   Serial.print("failed_requests: ");
// //   Serial.print(packets[PACKET1].failed_requests);
// //   Serial.println("     || ");
// //   Serial.print("exception_errors: ");
// //   Serial.print(packets[PACKET1].exception_errors);
// //   Serial.println("     || ");
// //   Serial.print("connection: ");
// //   Serial.print(packets[PACKET1].connection);
// //   Serial.println("           || ");
// //   //              Serial.println(" ");
// // }
// // }
