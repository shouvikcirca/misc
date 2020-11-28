import asyncio
import numpy as np
from tensorflow.keras.preprocessing.image import array_to_img
import time

async def createmore(f,l):
    return np.zeros([f,l])

def createmores(f,l):
    return np.zeros([f,l])


def main():
    loop = asyncio.get_event_loop()
    s = time.time()
    a = loop.create_task(createmore(10000,10000))
    b = loop.create_task(createmore(10000, 10000))
    c = loop.create_task(createmore(10000, 10000))
    done, pending = loop.run_until_complete(asyncio.wait([a,b,c]))
    loop.close()
    e = time.time() - s
    print('async ', e)

    ss = time.time()
    a = createmores(10000,10000)
    b = createmores(10000,10000)
    c = createmores(10000,10000)
    ee = time.time() - ss
    print('sync ', ee)

    #for f in done:
    #    print(f.result().shape)

if __name__ == '__main__':
    main()

