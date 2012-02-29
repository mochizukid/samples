#! /usr/bin/python
# -*- coding: utf-8 -*-

class SuperClass:
    
    def __init__(self, name):
        self.name = name

    def work(self, place):
        print "%s works at %s" % (self.name, place)

if  __name__ == "__main__":

    nancy = SuperClass("Nancy")
    nancy.work("a restaurant")

