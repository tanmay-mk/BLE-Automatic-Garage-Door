Please include your answers to the questions below with your submission, entering into the space below each question
See [Mastering Markdown](https://guides.github.com/features/mastering-markdown/) for github markdown formatting if desired.

**Note: All average currents should be taken at a time scale of 200mS/div. See the pop-up menu in the lower-right corner of the Energy Profiler window**

**1. Fill in the below chart based on currents measured in each energy mode, replacing each TBD with measured values.  Use the [Selecting Ranges](https://www.silabs.com/documents/public/user-guides/ug343-multinode-energy-profiler.pdf) feature of the profiler to select the appropriate measurement range.  Your measurements should be accurate to 10%**

Energy Mode | Period average current (uA)    | Average Current with LED off (uA)  | Average Current with LED On (uA)
------------| -------------------------------|------------------------------------|-------------------------
EM0         |           5190                 |           4990                     |         5490
EM1         |           3300                 |           3220                     |         3940
EM2         |           43.83                |           4.94                     |         502.66
EM3         |           45.49                |           4.25                     |         509.35

**2. Fill in the below chart based on time measured period and LED on time measurements for EM2 and EM3 modes, replacing each TBD with measured values.  Use the [Selecting Ranges](https://www.silabs.com/documents/public/user-guides/ug343-multinode-energy-profiler.pdf) feature of the profiler to select the appropriate measurement range.  When measuring time, measure from peak current to peak current.  Your LED on time measurement should be accurate to 1ms and your period measurement should be accurate to within 10ms**

Energy Mode | Period (s) | LED On Time (ms) |
------------| -----------|-------------------
EM2         |   2.25     |        176
EM3         |   2.22     |        176


**3. ScreenShots**  

***EM0***  
Period average current    
![em0_avg_current_period][em0_avg_current_period]  
Average Current with LED ***off***  
![em0_avg_current_ledoff][em0_avg_current_ledoff]  
Average Current with LED ***on***  
![em0_avg_current_ledon][em0_avg_current_ledon]  

***EM1***  
Period average current    
![em1_avg_current_period][em1_avg_current_period]  
Average Current with LED ***off***  
![em1_avg_current_ledoff][em1_avg_current_ledoff]  
Average Current with LED ***on***  
![em1_avg_current_ledon][em1_avg_current_ledon]  

***EM2***  
Period average current  
![em2_avg_current_period][em2_avg_current_period]  
Average Current with LED ***off***  
![em2_avg_current_ledoff][em2_avg_current_ledoff]  
Average Current with LED ***on***  
![em2_avg_current_ledon][em2_avg_current_ledon]   
LED measurement - Period   
![em2_led_period][em2_led_period]  
LED measurement - LED on time   
![em2_led_ledOnTime][em2_led_ledOnTime]  

***EM3***  
Period average current    
![em3_avg_current_period][em3_avg_current_period]  
Average Current with LED ***off***  
![em3_avg_current_period][em3_avg_current_ledoff]   
Average Current with LED ***on***  
![em3_avg_current_period][em3_avg_current_ledon]   
LED measurement - Period   
![em3_led_period][em3_led_period]  
LED measurement - LED on time   
![em3_led_ledOnTime][em3_led_ledOnTime]  

[em0_avg_current_period]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM0%20Avg%20Current.png
[em0_avg_current_ledoff]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM0%20LED%20Off%20Avg%20Current.png
[em0_avg_current_ledon]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM0%20LED%20On%20Avg%20Current.png

[em1_avg_current_period]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM1%20Avg%20Current.png
[em1_avg_current_ledoff]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM1%20LED%20Off%20Avg%20Current.png
[em1_avg_current_ledon]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM1%20LED%20On%20Avg%20Current.png

[em2_avg_current_period]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM2%20Avg%20Current.png
[em2_avg_current_ledoff]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM2%20LED%20Off%20Avg%20Current.png
[em2_avg_current_ledon]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM2%20LED%20On%20Period.png
[em2_led_period]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM2%20Period.png
[em2_led_ledOnTime]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM2%20LED%20On%20Period.png

[em3_avg_current_period]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM3%20Avg%20Current.png
[em3_avg_current_ledoff]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM3%20LED%20OFF%20Avg%20Current.png
[em3_avg_current_ledon]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM3%20LED%20On%20Avg%20Current.png
[em3_led_period]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM3%20Period.png
[em3_led_ledOnTime]: https://github.com/CU-ECEN-5823/ecen5823-assignment2-tanmay-mk/blob/main/Assignment%202%20Screenshots/EM3%20LED%20On%20Period.png
