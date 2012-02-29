#! /usr/bin/python
# -*- coding: utf-8 -*-

from super import SuperClass

class SubClass(SuperClass):

    def __init__(self, name, position):
        SuperClass.__init__(self, name)

        self.position = position

    def work(self, place):
        print "%s works at %s as %s" % (self.name, place, self.position)


if  __name__ == "__main__":

    mike = SubClass("Mike", "a manager")
    mike.work("a book store")

