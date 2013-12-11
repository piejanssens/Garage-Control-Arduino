Garage Control with Arduino
===========================

Arduino Garage Control project including sketch and tutorial.

[Watch it in action!]

#Overview
The purpose of this project was to create a DIY garage control utitlity that can be remotely controlled via my iPhone.
I chose for BLE (Bluetooth Low Energy a.k.a. Bluetooth 4.0) as it - what's in a name - very energy efficient and above all has better connectivity (range + connectiontime) then its predecessors.

I wrote two iOS companion apps. Note that you need to compile these yourself, the apps are not available on the App Store.
* [Carage Controller](https://github.com/piejanssens/Garage-Control-iOS) - Monitor sensors and control the garage door
* [My Garage](https://github.com/piejanssens/My-Garage-iOS) - Only function is to connect and immediately send the door switch command and close. This can be used with Siri by giving the command "Open my garage" which will just open the app and let it do it's thing.

Both apps are using a modified BLE Shield library and will keep scanning for the device until it's found and then connect. This is very useful since (in case your so lucky that your car supports this) you can drive up to your house, press the steering wheel button (or activate Siri with the home button) and say "Open my garage". As soon as you come in range of the Arduino it will open the garage!

The requirements describe the parts you need to create the same Arduino project as I did and is almost plug and play (that is whilst using my sketch and iOS app). It's up to you to decide what you want to build. E.g. you could go for something cheaper without the base shield, light and temperature sensor and directly connecting the magnetic switch and relay to the Arduino.

#Requirements
* Automated garage that can be controlled with a relay. What's a relay? 
* Power source (I used the 24V power source from the garage door itself.)
* Arduino Uno or compatible Arduino board
* [Bluetooth BLE Shield ](http://redbearlab.com/bleshield/) 
* [Grove Base Shield](http://www.seeedstudio.com/depot/grove-base-shield-p-754.html)
* [Grove Relay](http://www.seeedstudio.com/depot/grove-relay-p-769.html?cPath=39_42) or other relay
* Magnetic switch: Any magnetic window switch will do, some are better (stronger) than others. I used the ones displayed in this picture which are great!
* [Grove (analog) Light Sensor](http://www.seeedstudio.com/depot/grove-light-sensor-p-746.html?cPath=25_27)
* [Grove (analog) Temperature Sensor](http://www.seeedstudio.com/depot/grove-temperature-sensor-p-774.html?cPath=25_27)
* A box to fit everything in
* Tools (drill, screwdriver, wires, ...)
* Optional [Power Converter e.g. 24V to 5V](http://www.seeedstudio.com/depot/cptc5-power-converter-12v24v-switch-to-5v-p-1066.html?cPath=1_4) to power the Arduino
* Optional but recommended 2.4GHz SMA antenna. Caution: you need an antenna with middle pin or adapter.

#How To

