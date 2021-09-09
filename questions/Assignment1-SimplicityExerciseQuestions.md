Please include your answers to the questions below with your submission, entering into the space below each question
See [Mastering Markdown](https://guides.github.com/features/mastering-markdown/) for github markdown formatting if desired.

<<<<<<< HEAD
**1. How much current does the system draw (instantaneous measurement) when a single LED (LED0) is on with the GPIO pin set to StrongAlternateStrong?**
   Answer: The system draws a current of 5.47mA when a single LED is on with the GPIO pin set to output drive strength StrongAlternateStrong. When the LED0 is ON, the system draws 5.47mA and when LED0 is OFF, the system draws 4.89mA. 


**2. How much current does the system draw (instantaneous measurement) when a single LED is on with the GPIO pin set to WeakAlternateWeak?**
   Answer: The system draws a current of 5.51mA when a single LED is on with the GPIO pin set to output drive strength WeakAlternateWeak. When the LED0 is ON, the system draws 5.51mA and when LED0 is OFF, the system draws 4.91mA. 
=======
**1. How much current does the system draw (instantaneous measurement) when a single LED is on with the GPIO pin set to StrongAlternateStrong?**
   Answer: When a single LED, LED0, is ON with the GPIO pin set to StrongAlternateStrong, the system draws 5.47mA current. The output waveform is a square wave with 50% duty cycle. The system draws a current of 5.47mA when the LED0 glows (ON) and draws 4.91mA when LED0 is OFF. The power consumption is 17.07mW. The system uses 284.66uWh energy (u=micro) in 60.03 seconds. 


**2. How much current does the system draw (instantaneous measurement) when a single LED is on with the GPIO pin set to WeakAlternateWeak?**
   Answer: When a single LED, LED0, is ON with the GPIO pin set to WeakAlternateWeak, the system draws 5.43mA current. The output waveform is a square wave with 50% duty cycle. The system draws a current of 5.43mA when the LED0 glows (ON) and draws 4.96mA when LED0 is OFF. The power consumption is 17.05mW. The system uses 284.74uWh energy (u=micro) in 60.11 seconds. 
>>>>>>> a9f693a817195710a96f22aae4b1ac6df607d4b3


**3. Is there a meaningful difference in current between the answers for question 1 and 2? Please explain your answer, 
referencing the [Mainboard Schematic](https://www.silabs.com/documents/public/schematic-files/WSTK-Main-BRD4001A-A01-schematic.pdf) and [AEM Accuracy](https://www.silabs.com/documents/login/user-guides/ug279-brd4104a-user-guide.pdf) section of the user's guide where appropriate. Extra credit is avilable for this question and depends on your answer.**
<<<<<<< HEAD
   Answer: At first, there seems to be no difference as the current drawn during both the output drive strengths is approximately equal. However, the difference is not in the current drawn, but in the time that is needed for LED (LED0) to go from ON state to OFF state and vice versa. 
=======
   Answer: Since the current consumption in both the aforementioned cases is approximately equal, there seems to be no difference in the output at first. However, if we observe closely, we find out that the Rise time and Fall time of the square wave is changing with the change in drive strength of the GPIO pin. After careful observation, we observe that:
   
   Case 1: Drive Strength set to WeakAlternate Weak
   Rise Time: 600 micro seconds
   Fall Time: 500 micro seconds
   
   Case 2: Drive Strength set to StrongAlternateStrong
   Rise Time: 100 micro seconds
   Fall Time: 200 micro seconds
   
   Thus, we can now decisively say that there IS a meaningful difference between the two waveforms, and it is NOT about the current consumption. This Rise Time & Fall time are togetherly called as 'Slew Rate'. 

Based upon the observations, we can say that even though the current consumption remains approximately equal, the slew rate decreases with increase in output drive strength of the GPIO pin. As a result of this, we get a crisp change in the waveform with higher output drive strength.
>>>>>>> a9f693a817195710a96f22aae4b1ac6df607d4b3

	According to the energy profiler output:
		Case 1: Output Drive strength set to StrongAlternateStrong
		Rise Time (OFF to ON): 200us
		Fall Time (ON to OFF): 100us

		Case 2: Output Drive strength set to WeakAlternateWeak
		Rise Time (OFF to ON): 500us
		Fall Time (ON to OFF): 600us

	Based on these observations, it is evident that the output drive strength decreases the slew rate of the system. If we are using a weaker drive strength, that will result in increasing slew rate, ultimately increasing the time difference between ON and OFF. In this particular duration, due to the increased slew rate, the POWER and GND might get short circuit and system will get affected. Thus, to avoid such fatal consequences, it is necessary for the output waveform to have as less slew rate as possible.
	

**4. With the WeakAlternateWeak drive strength setting, what is the average current for 1 complete on-off cycle for 1 LED with an on-off duty cycle of 50% (approximately 1 sec on, 1 sec off)?**
<<<<<<< HEAD
   Answer: With the WeakAlternateWeak drive strength setting, the average current for 1 complete on-off cycle for 1 LED with an on-off duty cycle of 50% is 5.25mA. The system draws 5.55mA when the LED0 is turned ON whereas the system draws 4.95mA when the LED is OFF. 


**5. With the WeakAlternateWeak drive strength setting, what is the average current for 1 complete on-off cycle for 2 LEDs (both on at the time same and both off at the same time) with an on-off duty cycle of 50% (approximately 1 sec on, 1 sec off)?**
   Answer: With the WeakAlternateWeak drive strength setting, what is the average current for 1 complete on-off cycle for 2 LEDs with an on-off duty cycle of 50% is 5.40mA. The system draws 5.90mA when both the LEDs are ON, whereas the system draws 4.90mA when both the LEDs are OFF.
=======
   Answer: With output drive strength set to WeakAlternateWeak for both LED's, the average current that is consumed for 1 complete on-off cycle for single LED (LED0) with 50% duty cycle is 5.11mA. When the LED0 is ON, the system draws 5.40mA. When LED0 is OFF, the system draws 4.82mA. The power consumption for 1 complete on-off cycle is 16.95mW and the energy consumption is 9.37uWh. 


**5. With the WeakAlternateWeak drive strength setting, what is the average current for 1 complete on-off cycle for 2 LEDs (both on at the time same and both off at the same time) with an on-off duty cycle of 50% (approximately 1 sec on, 1 sec off)?**
   Answer: With output drive strength set to WeakAlternateWeak for both LEDs, the average current that is consumed for 1 complete on-off cycle for both LEDs (LED0 & LED1) with 50% duty cycle is 5.39mA. When both LEDs ON, the system draws 5.88mA. When both LEDs are OFF, the system draws 4.92mA. The power consumption for 1 complete on-off cycle is 17.80mW and the energy consumption is 9.89uWh.
>>>>>>> a9f693a817195710a96f22aae4b1ac6df607d4b3


