#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>
#include "ESP8266WiFi.h"

const char* ssid = "Alcatel A3 PLUS";
const char* password = "queenestking";

//Your Domain name with URL path or IP address with path
const char* url = "http://www.wattsandgrid.com/aslms/cht_chat.php";

char Data1 [100]= "{\"key\" : \"34@_rteyknjvs#25x\",\"password\" : \"";//degree360\",\"word\" : \"";did you go to school\"}"; //\"username\" : \"degree360\",
char Data[200];
//char data1 []= "{\"key\" : \"34@_rteyknjvs#25x\",\"password\" :";
char c;int go=0;
char question[50];
char userpassword[15];

int  authenticateUser(){
  int v=0; // initialise a variable to be used as a flag
                Serial.println("Please enter password");
  while(1){
                  delay(200);
//  Serial.print('}');
        while(Serial.available()){
          c=Serial.read();   // capture incoming serial data
//   Serial.print(c);
          if(c=='\n' || c =='\r'){
            v=1;
//   Serial.println("checking....");
          while(Serial.available())
          c=Serial.read(); // waste other incomming eg: /r/n
            }
            else{
              sprintf(userpassword,"%s%c",userpassword,c);  // patch incoming serial data to recent ones
//   Serial.println(userpassword);
              if((strlen (userpassword)) >13){ // password must not be greater than 13
                memset(userpassword,'\0',sizeof userpassword); //clear the data
                Serial.println("Wrong password!! try again");
                
                while(Serial.available()){
                c=Serial.read(); //wipe all junck coming in
                delay(200); // delay so all junck can come in and be wiped
                }
                      return 0;
              }
            }
            if(v==1){
              if((strcmp(userpassword,"degree360"))==0){ // if password is correct
                Serial.println("Login sucessful");  // output "success" to serial monitor
                sprintf(Data1,"%s%s%s",Data1,userpassword,"\",\"word\" : \"");  // patch incoming serial data to recent ones
//    Serial.println(Data1);
                return 1;
              }
              else{
              v=0;
                memset(userpassword,'\0',sizeof userpassword);  //clear the data
                Serial.println("wrong password!! try again");
                while(Serial.available()){
                c=Serial.read();
//    Serial.print(c);
                }
                      return 0;
                
            
              }
              }
        
  }
}
      }
      
void setup() {
  Serial.begin(115200);

  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  while(authenticateUser()==0);

  
  Serial.println("Now you can chat with ChitChat\n");
  memset(question,'\0',sizeof question);  //clear the data
}

void loop() {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){

      while(Serial.available()){
        c=Serial.read();
        if(c=='\n' || c =='\r'){
          go=1;
          delay(200);
        while(Serial.available())
        c=Serial.read(); // waste other incomming eg: /r/n
          }
          else{
            sprintf(question,"%s%c",question,c);  // patch incoming serial data to recent ones
          }
      }
      if(go==1){
        go=0;
        sprintf(question,"%s%s",question,"\"}");  // patch incoming serial data to recent ones
//    Serial.println(question);
        sprintf(Data,"%s%s",Data1,question);  // patch incoming serial data to recent ones
        //Serial.println(Data);
     String response = PostRequest(url, Data);
//    Serial.println(response);
     
     ///////////////
      JSONVar myObject = JSON.parse(response);
  
      if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
        return;
      }
    
  // myObject.hasOwnProperty(key) checks if the object contains an entry for key
  if (myObject.hasOwnProperty("valid")) {
    if((int) myObject["valid"]){
  if (myObject.hasOwnProperty("question")) {
    Serial.print("\"User\" : ");
    Serial.println((const char*) myObject["question"]);
  }
  if (myObject.hasOwnProperty("answer")) {
    Serial.print("\"Server\" : ");
    Serial.println((const char*) myObject["answer"]);
  }
      }
      else{
    Serial.println("An Error Ocurred");
  if (myObject.hasOwnProperty("reason")) {
    Serial.print("\"Reason\" : ");
    Serial.println((const char*) myObject["reason"]);
  }
        }
  }
  memset(question,'\0',sizeof question);  //clear the data
  memset(Data,'\0',sizeof Data);  //clear the data
    }
     ///////////////
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  
}

/*
the below function take two parameter, 
uses the "dURL" to connect to the API
and "jsonData" as a json to post the request.

 it respond with a string response from the server
*/

String PostRequest(const char* dURL, const char* jsonData) { 
  HTTPClient http;
    
  // Your IP address with path or Domain name with URL path 
  http.begin(dURL);
  
      http.addHeader("Content-Type", "application/json"); //content-type header type
  // Send HTTP POST request
  int ResponseCode = http.POST(jsonData); // post the data
  
  String feedback = "{}";  //init string to hold response from the server
  
  if (ResponseCode>0) {
  if (ResponseCode>=200 && ResponseCode<=201) { // if http Response code is 200 or 201, it must have got some good response
   // Serial.print("HTTP Response code: ");
   // Serial.println(ResponseCode);
    feedback = http.getString(); //append response to feedback
    }
  else { // else, something must have gone wrong
    Serial.print("Http Response code : ");
    Serial.println(ResponseCode);
  }
  }
  else {
    Serial.print("Error Occured.\n Error code: ");
    Serial.println(ResponseCode);
  }
  
        
      // Free resources
      http.end(); // end the session
      
    return feedback; // return the feedback
  }
