#!/usr/bin/env python
import serial
import glob

_M = 100.0/16
_B = -(400.0/16)

dev = glob.glob('/dev/tty.usb*')[0]
print "Using " + dev
s = serial.Serial(dev, 9600)
while True:
    print s.readline().rstrip()
    continue
    vOut = float(s.readline().rstrip())
    i = (vOut / 250) * 1000
    print "vOut = " + str(vOut)
    print "R = " + str(i)
    t = _M * i + _B
    print 'T = ' + str(t)
    print 'Tf = ' + str(t * 1.8 +32)
