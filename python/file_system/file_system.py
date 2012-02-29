#! /usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os

def usage(pname):
    print "usage:"
    print "    $ python %s <path>" % pname

def listFilesInDir(path):
    print

    for dirpath, dirnames, filenames in os.walk(path):
        print "%s:" % dirpath

        for dirname in dirnames:
            print "\t%s/" % dirname

        for filename in filenames:
            print "\t%s" % filename

        print

if __name__ == "__main__":

    if len(sys.argv) != 2:
        usage(sys.argv[0])
        sys.exit()
    
    path = sys.argv[1]
    
    if os.path.exists(path):
        print '"%s" exists' % path

        if os.path.isfile(path):
            print '"%s" is a file' % path

        if os.path.isdir(path):
            print '"%s" is a directory' % path
            listFilesInDir(path)

    else:
        print '"%s" does not exists' % path

    
