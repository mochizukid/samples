#! /usr/bin/python
# -*- coding: utf-8 -*-

import xml.dom.minidom

def printElements(element, indent = 0):

    indent_str = "\t" * indent

    if element.nodeType == element.ELEMENT_NODE:
        print "%s%s" % (indent_str, element.tagName)
        for node in element.childNodes:
            printElements(node, indent + 1)

    elif element.nodeType == element.TEXT_NODE and not element.data.isspace():
        print "%s%s" % (indent_str, element.data)


def printTags(dom, tagName):
    nodeList = dom.getElementsByTagName(tagName)
    for node in nodeList:
        print node.firstChild.data
    

if __name__ == "__main__":

    dom = xml.dom.minidom.parse("addressbook.xml")
    printElements(dom.documentElement)
    
    print "= names ========="
    printTags(dom, "name")

    print "= emails ========="
    printTags(dom, "email")
