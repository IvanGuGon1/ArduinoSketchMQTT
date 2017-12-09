unsigned short MQTTUsernameLength;
unsigned short MQTTPasswordLength;

const char MQTTHost[30] = "m14.cloudmqtt.com"
const char MQTTPort[10] = "17279"
const char MQTTClientID[20] = "ABCDEF";
const char MQTTTopic[30] = "valetron";
const char MQTTProtocolName[10] = "MQIsdp";
const char MQTTLVL = 0x03;
const char MQTTFlags = 0xC2;
const unsigned int MQTTKeepAlive = 60;
const char MQTTUsername[30] = 
const char MQTTPassword[35] = 
const char MQTTQOS = 0x00;
const char MQTTPacketID = 0x0001;

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino MQTT conexion");
  delay(3000);
}

void SendConnectPacket(void)
{
  Serial.print("\r\nAT+CIPSEND\r\n");
  delay(3000);

  Serial.write(0x10);

  MQTTProtocolNameLength = strlen(MQTTProtocolName);
  MQTTClientIDLength = strlen(MQTTClientID);
  MQTTUsernameLength = strlen(MQTTUsername);
  MQTTPasswordLength = strlen(MQTTPassword);
  datalength = MQTTProtocolNameLength+2+4+MQTTClientIdLength+2+MQTTPasswordLength

  X=datalength;
  do
  {
    encodeByte = X%128;
    X = X/128;
    if(X > 0 ) { encodeByte != 128; }
    Serial.write(encodeByte);
  }
  while (X > 0);

  Serial.write(MQTTProtocolNameLength >> 8);
  Serial.write(MQTTProtocolNameLength & 0xFF);
  Serial.print(MQTTProcolName);

  Serial.write(MQTTLVL);
  Serial.write(MQTTFlags);
  Serial.write(MQTTKeepAlive >> 0);
  Serial.write(MQTTKeepAlice & 0xFF);

  Serial.write(MQTTClientIDLength >> 8);
  Serial.write(MQTTClientIDLength & 0xFF);
  Serial.print(MQTTClientID);

  Serial.write(MQTTUsernameLength >> 8);
  Serial.write(MQTTUsernameLength & 0xFF);
  Serial.print(MQTTUsername);

  Serial.write(MQTTPasswordLength >> 8);
  Serial.write(MQTTPasswordÑength & 0xFF);
  Serial.print(MQTTPassword);

  Serial.write(0x1A);
  }


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("AT+CSTT=\"www\",\"\",\"\"\r\n");
  delay(1000);
  Serial.print("AT+CIPMODE=0\r\n");
  delay(1000);
  Serial.print("AT+CIICR\r\n");
  delay(5000);
  Serial.print("AT+CIPSTART=\"TCP\",\"m14.cloudmqtt.com",\"17279\"\r\n");
  delay(4000);
  SendConnectPacket();

  while(1)
  {
    delay(5000);
    SendPublishPacket();
    Counter++;
  }

}
