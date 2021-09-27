Please include your answers to the questions below with your submission, entering into the space below each question
See [Mastering Markdown](https://guides.github.com/features/mastering-markdown/) for github markdown formatting if desired.

*Be sure to take measurements with logging disabled to ensure your logging logic is not impacting current/time measurements.*

*Please include screenshots of the profiler window detailing each current measurement captured.  See the file Instructions to add screenshots in assignment.docx in the ECEN 5823 Student Public Folder.* 

1. What is the average current per period?
   Answer:
   <br>Screenshot:  
   ![Avg_current_per_period]https://github.com/CU-ECEN-5823/ecen5823-assignment4-tanmay-mk/blob/main/Assignment%204%20Screenshots/Q1.png

2. What is the average current when the Si7021 is Powered Off?
   Answer: 10.10uA
   <br>Screenshot:  
   ![Avg_current_LPM_Off]https://github.com/CU-ECEN-5823/ecen5823-assignment4-tanmay-mk/blob/main/Assignment%204%20Screenshots/Q2.png 

3. What is the average current when the Si7021 is Powered On?
   Answer:
   <br>Screenshot:  
   ![Avg_current_LPM_Off]https://github.com/CU-ECEN-5823/ecen5823-assignment4-tanmay-mk/blob/main/Assignment%204%20Screenshots/Q3.png

4. How long is the Si7021 Powered On for 1 temperature reading?
   Answer:
   <br>Screenshot:  
   ![duration_lpm_on]https://github.com/CU-ECEN-5823/ecen5823-assignment4-tanmay-mk/blob/main/Assignment%204%20Screenshots/Q4.png

5. Compute what the total operating time of your design for assignment 4 would be in hours, assuming a 1000mAh battery power supply?
   Answer: One operating cycle requires 25.88uA. The total battery life of design is equal to total battery power supply divided by load current consumption per cycle. 
		Thus, 1000mAh/25.88uA = 1000/0.02588 = 38639 hours 52 minutes.  
   
6. How has the power consumption performance of your design changed since the previous assignment?
   Answer: The power consumption is slightly increased as we are now sleeping in EM1 during the I2C transfers. During I2C transfer, the current is approximately 3mA. 
   
7. Describe how you have tested your code to ensure you are sleeping in EM1 mode during I2C transfers.
   Answer: By looking at the energy profiler output, we can easily ensure that the MCU is sleeping in EM1 during I2C transfers. As we know, the current consumption of MCU in 
		EM1 is approximately 3mA. By looking at the energy profiler output, we see that after providing power to SI7021 (PD15), we wait for 80mS and during these
		80mS, the MCU sleeps in EM3. Following this wait period, we start I2C write operation, and until the operation is complete, we observe a current consumption of
		upto 4mA. After I2C write operation, the MCU again sleeps in EM3 as we wait for another 10.8 seconds. After this operation, we proceed to I2C read operation. 
		Again, during this operation, we see the current consumption of the MCU is around 4mA. 
   

