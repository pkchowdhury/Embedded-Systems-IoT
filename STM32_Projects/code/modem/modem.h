
void modemInit();
void showSerialdata();
void mqttConnect();
void gprsInit();
void mqttConnect(String clientId, String broker, String user, String pass);
void mqttStop();
void mqttDisconnect(int timeout);
void clientRelease();
void publishData(String data, String dataType, int qos);
void subscribe(int qos);
void reqData(int qos, String data);
