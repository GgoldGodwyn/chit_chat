# chit_chat
Chit_Chat is a simple arduino-server chat bot, designed to demonstrate communication using post request on arduino esp8266 to chat and a php server



**Arduino libraries**

- ESP8266HTTPClient
- WiFiClient
- Arduino_JSON
- ESP8266WiFi
## Table of Contents (Optional)

- [Testing](#Test Endpoint)
- [Installation](#installation)
- [Contributing](#contributing)
---


## Test Endpoint

- Use this endpoint/Api for test using postman
`https://www.wattsandgrid.com/aslms/cht_chat.php`
## Example 1 ( if all values are correct)

```json
// json parameter!

{
    "key" : "34@_rteyknjvs#25x",
    "password" : "degree360",
    "word" : "did you go to school"
}
```

```json
// json reponse!

{
    "valid":1,
    "question":"did you go to school",
    "answer":"we are on vacation\n"
}
```

---


## Example 2 ( if one or all values are not correct)

```json
// json parameter!

{
    "key" : "34@_rteyknjvs#25x",
    "password" : "degree36 0",
    "word" : "did you go to school"
}
```

```json
// json reponse!

{
    "valid":0,
    "reason":"Wrong details. Adviced to Restart module!"
}
```

---
## Installation

- Clone this repo to your local machine using `https://github.com/GgoldGodwyn/chit_chat`
- Compile and install chit_chat.ino into ESP8266
- Open serial monitor
- Set baud rate to 115200bps
- Enter your desired question from the terminal and press the "Enter" key
- you should get response from the server if question entered is within servers scope


