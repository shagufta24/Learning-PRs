# -*- coding: utf-8 -*-
"""
Created on Mon Oct 28 10:46:10 2019

@author: Finney Graham
"""

num = int(input())
a = 0
for i in range(2,int(num)):
    remainder = int(num) % i
    if remainder == 0:
        a= 1
        break       
       
if a==0:
    print(str(num)+" is prime")
else:
    print((str(num)) + " is not prime:")    

