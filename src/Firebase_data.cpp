// #include "Firebase_data.h"
// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>
// #include "addons/TokenHelper.h"
// #include "addons/RTDBHelper.h"

// #define WIFI_SSID "iPhone"
// #define WIFI_PASSWORD "kan12345"
// #define API_KEY "AIzaSyDoxlplEQ5gAo4pZ3ApEUS_B-WvmLe-AoE"
// #define DATABASE_URL "https://smart-pill-dispenser-cf9be-default-rtdb.asia-southeast1.firebasedatabase.app/"
// #define WIFI_CONNECTION_TIMEOUT 15000  

// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// unsigned long sendDataPrevMillis = 0;
// int count = 0;
// bool signupOK = false;

// void setupFirebase() {
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   Serial.print("Connecting to Wi-Fi");

//   unsigned long connectionStartTime = millis();

//   while (WiFi.status() != WL_CONNECTED && millis() - connectionStartTime < WIFI_CONNECTION_TIMEOUT){
//     Serial.print(".");
//     delay(300);
//   }

//   Serial.println();
//   Serial.print("Connected with IP: ");
//   Serial.println(WiFi.localIP());
//   Serial.println();

//   config.api_key = API_KEY;
//   config.database_url = DATABASE_URL;

//   if (Firebase.signUp(&config, &auth, "", "")){
//     Serial.println("ok");
//     signupOK = true;
//   }
//   else{
//     Serial.printf("%s\n", config.signer.signupError.message.c_str());
//   }

//   config.token_status_callback = tokenStatusCallback;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);
// }

// void sendDataToFirebase(const String& path, int value) {
//   if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)){
//     sendDataPrevMillis = millis();

//     if (Firebase.RTDB.setInt(&fbdo, path.c_str(), value)){
//       Serial.println("PASSED");
//       Serial.println("PATH: " + fbdo.dataPath());
//       Serial.println("TYPE: " + fbdo.dataType());
//     }
//     else {
//       Serial.println("FAILED");
//       Serial.println("REASON: " + fbdo.errorReason());
//     }
//   }
// }