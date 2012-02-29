#! /usr/bin/python
# -*- coding: utf-8 -*-

import sys

def usage(pname):
    print "usage:"
    print "    $ python %s <infile> <outfile>" % pname

def copyFile(infile, outfile):
    print u"ファイル %s を %s にコピーします。" % (infile, outfile)

    try:
        fin = open(infile, "r")
        fout = open(outfile, "w")
        for line in fin:
            if not line.startswith("#"):
                fout.write(line)

    except:
        print "file open failed"

    finally:
        fin.close();
        fout.close();


if __name__ == "__main__":

    if len(sys.argv) != 3:
        usage(sys.argv[0])
        sys.exit()

    copyFile(sys.argv[1], sys.argv[2])

    print "finished"
