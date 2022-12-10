# Lab3_q2_816019835
Branching and versioning strategy:
The usage of branching to create versions was thought to be used.
It would have utilized 'git checkout -b [release-vx.y]
where x denoted the final issue or push to GitHub
and y denoted the updates of small changes of the code
The above would have used release branches when the master branch is at a stable point and specific chnages need to be made.
Therefore, master would be branched and the changes made before would have been merged into master 
Only two changes were made where the task were created and worked as expected when the functions were created and ran
And the other was to recreate the operation of unity , where the task was deleted after it was created to lower memory utiliziation.

#Discussion 
No driver function was used because the task1 in lab2_q1 where the light should be turned on was the function that called the unit tested function active_delay().
The different functions of the task1:
1. access the mutex that allows the setting hihg or low of GPIO2
1. GPIO2 pin set to high
2. active_delay(), scheduler ticks use to acquire 500ms of time passing
3. Give the mutex
4. Taskdelay(), switches to another task
where all were tested individually, and such the test cases are as followed below

Test Case #1
Test Case ID: TC001
Test Case Description: xSemaphore mutex was given to task that was created
Test Steps: 
1) Enter integrated_test1 task
2) Check if the mutex created is not equal to NULL
Test Data	: xSemaphore
Expected Results: GPIO2 pin should turn on since mutex was accessed
Actual Results: GPIO2 pin was turned on with message "Checking if GPIO2 is actually set"
Pass/Fail: PASS

Test Case #2
Test Case ID: TC002	
Test Case Description: xSemaphore mutex was not given to task that was created
Test Steps:
1) call integrated_test1 Task
2) call gpio_task_3_message (void *arg) that does not return mutex
Test Data: xSempahore
Expected Results: "Waiting for the semaphore to release resource from low\n"
Actual Results: "Waiting for the semaphore to release resource from low \n"
Pass/Fail: PASS

Test Case #3
Test Case ID: TC003
Test Case Description: GPIO2 pin was set to high through mutex
Test Steps:
1)call the intergated_test1 Task
2) enter the mutex , xSemaphore
3) set the GPIO2 pin to 0
Test Data: GPIO_OUTPUT_IO_0
Expected Results: "PASS: GPIO2 was set correctly"
Actual Results: "PASS: GPIO2 was set correctly"
Pass/Fail: PASS

Test Case #4
Test Case ID: TC004
Test Case Description: GPIO2 pin was set to low through mutex
Test Steps:
1)call the intergated_test1 Task
2) enter the mutex , xSemaphore
3) set the GPIO2 pin to 1
Test Data: GPIO_OUTPUT_IO_0
Expected Results: "PASS: GPIO2 was set correctly"
Actual Results: "PASS: GPIO2 was set correctly"	
Pass/Fail: PASS

Test Case #5
Test Case ID: TC005 
Test Case Description: GPIO2 pin was set to some other logic level
Test Steps:
1)call the intergated_test1 Task
2) enter the mutex , xSemaphore
3) set the GPIO2 pin to 0
Test Data: GPIO_OUTPUT_IO_0	
Expected Results: "FAIL: GPIO2 was not set correctly"
Actual Results: "FAIL: GPIO2 was not set correctly"
Pass/Fail: PASS

Test Case #6
Test Case ID: TC006
Test Case Description: Active delay function was called within function 
Test Steps:
1)call the intergated_test1 Task
2) enter the mutex , xSemaphore
3) set the GPIO2 pin to 0
4) call the active_delay() function
5) check if the time delayed is 50
Test Data: active_delay()
Expected Results: "Difference time: 50"
Actual Results: "Difference time: 50"
Pass/Fail: PASS

Test Case #7
Test Case ID: TC007
Test Case Description: Active delay function waits for 500ms
Test Steps:
1)call the intergated_test1 Task
2) enter the mutex , xSemaphore
3) set the GPIO2 pin to 0
4) call the active_delay() function
5) check if the time delayed is 500
Test Data: diif_tick
Expected Results: "PASS: time = 500ms"	
Actual Results : "PASS: time = 500ms"	
Pass/Fail: PASS

Test Case #8
Test Case ID: TC008
Test Case Description: Active delay function waits for 500ms with tolerance of 100ms
Test Steps:
1)call the intergated_test1 Task
2) enter the mutex , xSemaphore
3) set the GPIO2 pin to 0
4) call the active_delay() function
5) check if the time delayed is 500
Test Data: diff_tick
Expected Results:	"PASS: time delay within 100ms tolerance"
Actual Results: "PASS: time delay within 100ms tolerance"
Pass/Fail: PASS


Test Case #9
Test Case ID: TC009
Test Case Description: Active delay function waits for a time outisde of 500ms plus tolerance of 100ms
Test Steps:
1)call the intergated_test1 Task
2) enter the mutex , xSemaphore
3) set the GPIO2 pin to 0
4) call the active_delay() function
5) check if the time delayed is 500
Test Data: diff_tick
Expected Results: "FAIL: time delay not within 100ms tolerance"
Actual Results: "FAIL: time delay not within 100ms tolerance"
Pass/Fail: PASS
