#!/usr/bin/env python
import serial
import glob
import socket

_M = 100.0/16
_B = -(400.0/16)

_telegraf_addr = ('127.0.0.1', 8092)
_telegraf_conn = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def parse_line(l):
    parts = l.rstrip().split(' ')
    if len(parts) != 2:
        return
    pin, v_out_str = parts
    v_out = float(v_out_str)
    milliamps = (v_out / 250) * 1000
    t_cel = _M * milliamps + _B
    t_far = t_cel * 1.8 + 32
    return {
        "pin": pin,
        "v_out": v_out,
        "milliamps": milliamps,
        "t_cel": t_cel,
        "t_far": t_far,
    }

def send_line(l):
    msg = "temp_probe,pin={pin} v_out={v_out},milliamps={milliamps},t_cel={t_cel},t_far={t_far}\n".format(**l)
    print msg
    _telegraf_conn.sendto(msg, _telegraf_addr)

dev = glob.glob('/dev/tty.usb*')[0]
print "Using " + dev
s = serial.Serial(dev, 9600)
while True:
    try:
        parsed = parse_line(s.readline())
        send_line(parsed)
    except Exception as e:
        print e
