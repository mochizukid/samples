#! /usr/bin/python
# -*- coding: utf-8 -*0

from super import SuperClass
from sub import SubClass

if __name__ == "__main__":

    nancy = SuperClass("Nancy")
    nancy.work("a restaurant")

    mike = SubClass("Mike", "a manager")
    mike.work("a book store")

