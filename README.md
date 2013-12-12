Garage Control with Arduino
===========================

Arduino Garage Control project including sketch and tutorial.

#Demo
[Watch it in action!](https://www.youtube.com/watch?v=utPfQMeuSUI)

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
* [Grove 4pin connector cables](http://www.seeedstudio.com/depot/grove-universal-4-pin-buckled-5cm-cable-5-pcs-pack-p-925.html?cPath=98_106_57)
* A box to fit everything in
* Tools (drill, screwdriver, wires, ...)
* Optional [Power Converter e.g. 24V to 5V](http://www.seeedstudio.com/depot/cptc5-power-converter-12v24v-switch-to-5v-p-1066.html?cPath=1_4) to power the Arduino
* Optional but recommended 2.4GHz SMA antenna. Caution: you need an antenna with middle pin or adapter.
* [RedBearLab Arduino BLE Library](https://github.com/RedBearLab/BLEShield)

#How To
1. Mount the grove base shield on the BLE shield, and mount the BLE shield on the Arduino
2. Connect the light sensor connector with A3 on the base shield
3. Connect the temperature sensor connector with A2 on the base shield
4. Connect the relay with D4 on the base shield
5. Cut one grove connector cable in two. 
6. Plug the connector side in D6 and wirethe black and yellow cables to either side of the magnetic switch.
7. Upload the sketch
8. Open the console and enable debugging (= send 'd') or connect with one of the companion iOS apps
9. Optional add a random authentication bytes "handshake" to both the sketch and the iOS app. These bytes are sent before switching the relay. Without this handshake the command to open the garage door will not be accepted.

