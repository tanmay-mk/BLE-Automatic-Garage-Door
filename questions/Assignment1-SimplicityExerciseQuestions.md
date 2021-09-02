Please include your answers to the questions below with your submission, entering into the space below each question
See [Mastering Markdown](https://guides.github.com/features/mastering-markdown/) for github markdown formatting if desired.

**1. How much current does the system draw (instantaneous measurement) when a single LED is on with the GPIO pin set to StrongAlternateStrong?**
   Answer: When a single LED, LED0, is ON with the GPIO pin set to StrongAlternateStrong, the system draws 5.47mA current. The output waveform is a square wave with 50% duty cycle. The system draws a current of 5.47mA when the LED0 glows (ON) and draws 4.91mA when LED0 is OFF. The power consumption is 17.07mW. The system uses 284.66uWh energy (u=micro) in 60.03 seconds. 


**2. How much current does the system draw (instantaneous measurement) when a single LED is on with the GPIO pin set to WeakAlternateWeak?**
   Answer: When a single LED, LED0, is ON with the GPIO pin set to WeakAlternateWeak, the system draws 5.43mA current. The output waveform is a square wave with 50% duty cycle. The system draws a current of 5.43mA when the LED0 glows (ON) and draws 4.96mA when LED0 is OFF. The power consumption is 17.05mW. The system uses 284.74uWh energy (u=micro) in 60.11 seconds. 


**3. Is there a meaningful difference in current between the answers for question 1 and 2? Please explain your answer, 
referencing the [Mainboard Schematic](https://www.silabs.com/documents/public/schematic-files/WSTK-Main-BRD4001A-A01-schematic.pdf) and [AEM Accuracy](https://www.silabs.com/documents/login/user-guides/ug279-brd4104a-user-guide.pdf) section of the user's guide where appropriate. Extra credit is avilable for this question and depends on your answer.**
   Answer: Since the current consumption in both the aforementioned cases is approximately equal, there seems to be no difference in the output at first. However, if we observe closely, we find out that the Rise time and Fall time of the square wave is changing with the change in drive strength of the GPIO pin. After careful observation, we observe that:
   
   Case 1: Drive Strength set to WeakAlternate Weak
   Rise Time: 600 micro seconds
   Fall Time: 500 micro seconds
   
   Case 2: Drive Strength set to StrongAlternateStrong
   Rise Time: 100 micro seconds
   Fall Time: 200 micro seconds
   
   Thus, we can now decisively say that there IS a meaningful difference between the two waveforms, and it is NOT about the current consumption. This Rise Time & Fall time are togetherly called as 'Slew Rate'. 

Based upon the observations, we can say that even though the current consumption remains approximately equal, the slew rate decreases with increase in output drive strength of the GPIO pin. As a result of this, we get a crisp change in the waveform with higher output drive strength.


**4. With the WeakAlternateWeak drive strength setting, what is the average current for 1 complete on-off cycle for 1 LED with an on-off duty cycle of 50% (approximately 1 sec on, 1 sec off)?**
   Answer: With output drive strength set to WeakAlternateWeak for both LED's, the average current that is consumed for 1 complete on-off cycle for single LED (LED0) with 50% duty cycle is 5.11mA. When the LED0 is ON, the system draws 5.40mA. When LED0 is OFF, the system draws 4.82mA. The power consumption for 1 complete on-off cycle is 16.95mW and the energy consumption is 9.37uWh. 


**5. With the WeakAlternateWeak drive strength setting, what is the average current for 1 complete on-off cycle for 2 LEDs (both on at the time same and both off at the same time) with an on-off duty cycle of 50% (approximately 1 sec on, 1 sec off)?**
   Answer: With output drive strength set to WeakAlternateWeak for both LEDs, the average current that is consumed for 1 complete on-off cycle for both LEDs (LED0 & LED1) with 50% duty cycle is 5.39mA. When both LEDs ON, the system draws 5.88mA. When both LEDs are OFF, the system draws 4.92mA. The power consumption for 1 complete on-off cycle is 17.80mW and the energy consumption is 9.89uWh.


