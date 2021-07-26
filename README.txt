Author: Josiah Anderson
Language: C++

Current State:
Right now, the program runs for an initial 120 seconds, a new customer arrives at random 1-5 seconds after the previous customer arrival. The customer also is assigned a random "shoptime" that ranges from 5-35 seconds long. Each customer has its own thread and the threads are all executing concurrently.

The idea: A program that simulates a grocery store during some length of time. It will keep track of average waiting times for customers per cashier (perhaps I will add functionality to write the data to a text file or excel spreadsheet). If the wait time gets above a certain threshold, a new register opens up, adding to the pool of available registers. It is just a contrived way for me to practice using linked lists, queues, and OOP in C++, but also seems like fun. I plan to make changes to it to be more 'game-like', and maybe implement it in Unreal Engine.
