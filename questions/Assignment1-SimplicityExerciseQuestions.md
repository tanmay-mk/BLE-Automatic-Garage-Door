Please include your answers to the questions below with your submission, entering into the space below each question
See [Mastering Markdown](https://guides.github.com/features/mastering-markdown/) for github markdown formatting if desired.

**1. How much current does the system draw (instantaneous measurement) when a single LED (LED0) is on with the GPIO pin set to StrongAlternateStrong?**
   Answer: The system draws a current of 5.47mA when a single LED is on with the GPIO pin set to output drive strength StrongAlternateStrong. When the LED0 is ON, the system draws 5.47mA and when LED0 is OFF, the system draws 4.89mA. 


**2. How much current does the system draw (instantaneous measurement) when a single LED is on with the GPIO pin set to WeakAlternateWeak?**
   Answer: The system draws a current of 5.51mA when a single LED is on with the GPIO pin set to output drive strength WeakAlternateWeak. When the LED0 is ON, the system draws 5.51mA and when LED0 is OFF, the system draws 4.91mA. 


**3. Is there a meaningful difference in current between the answers for question 1 and 2? Please explain your answer, 
referencing the [Mainboard Schematic](https://www.silabs.com/documents/public/schematic-files/WSTK-Main-BRD4001A-A01-schematic.pdf) and [AEM Accuracy](https://www.silabs.com/documents/login/user-guides/ug279-brd4104a-user-guide.pdf) section of the user's guide where appropriate. Extra credit is avilable for this question and depends on your answer.**
   Answer: At first, there seems to be no difference as the current drawn during both the output drive strengths is approximately equal. However, the difference is not in the current drawn, but in the time that is needed for LED (LED0) to go from ON state to OFF state and vice versa. 

	According to the energy profiler output:
		Case 1: Output Drive strength set to StrongAlternateStrong
		Rise Time (OFF to ON): 200us
		Fall Time (ON to OFF): 100us

		Case 2: Output Drive strength set to WeakAlternateWeak
		Rise Time (OFF to ON): 500us
		Fall Time (ON to OFF): 600us

	Based on these observations, it is evident that the output drive strength decreases the slew rate of the system. If we are using a weaker drive strength, that will result in increasing slew rate, ultimately increasing the time difference between ON and OFF. In this particular duration, due to the increased slew rate, the POWER and GND might get short circuit and system will get affected. Thus, to avoid such fatal consequences, it is necessary for the output waveform to have as less slew rate as possible.
	

**4. With the WeakAlternateWeak drive strength setting, what is the average current for 1 complete on-off cycle for 1 LED with an on-off duty cycle of 50% (approximately 1 sec on, 1 sec off)?**
   Answer: With the WeakAlternateWeak drive strength setting, the average current for 1 complete on-off cycle for 1 LED with an on-off duty cycle of 50% is 5.25mA. The system draws 5.55mA when the LED0 is turned ON whereas the system draws 4.95mA when the LED is OFF. 


**5. With the WeakAlternateWeak drive strength setting, what is the average current for 1 complete on-off cycle for 2 LEDs (both on at the time same and both off at the same time) with an on-off duty cycle of 50% (approximately 1 sec on, 1 sec off)?**
   Answer: With the WeakAlternateWeak drive strength setting, what is the average current for 1 complete on-off cycle for 2 LEDs with an on-off duty cycle of 50% is 5.40mA. The system draws 5.90mA when both the LEDs are ON, whereas the system draws 4.90mA when both the LEDs are OFF.


