# static_linkedlist

Hi!

I am using this project to develop a particular kind of linked list, one that is stored in statically allocated memory.
The purpose of this is to get the behaviour of a linked list, without having to use dynamic memory allocation, which is often avoided on small embedded system.


This is implemented by means of an array, whose size limits the number of elements the linked list can contain, and to functions for allocating and deallocating list elements to array elements

In addition, I am implementing functionality such that elements in the list can be tracked regarding to transmission attempts.
This is related to the application of the list: Storing packets that will be sent over a wireless network link.

//Audun Knudsroed
