import random


def randomMAC():
    mac = [
        random.randint(0x00, 0xff),
        random.randint(0x00, 0xff),
        random.randint(0x00, 0xff),
        random.randint(0x00, 0xff),
        random.randint(0x00, 0xff),
        random.randint(0x00, 0xff) 
        ]
    return ':'.join(map(lambda x: "%02x" % x, mac))


def randomIP():
    ip = [
        random.randint(0x00, 0xff),
        random.randint(0x00, 0xff),
        random.randint(0x00, 0xff),
        random.randint(0x00, 0xff)
        ]
    return '.'.join(map(lambda x: "%u" % x, ip))


def randomPort():
    port = random.randint(0x01, 0xffff)
    return str(port)
