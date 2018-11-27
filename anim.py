import sys,time

def animation(counter, length):
    stage = counter % (length * 2 + 2)
    if stage < length + 1:
        left_spaces = stage
    else:
        left_spaces = length * 2 - 1 - stage
    return '[' + ' ' * left_spaces + '=' + ' ' * (length - left_spaces) + ']'

for i in range(100):
    sys.stdout.write('\b\b\b')
    sys.stdout.write(animation(i, 6))
    sys.stdout.flush()
    time.sleep(0.2)


animation_strings = ('[=      ]', '[ =     ]', '[  =    ]', '[   =   ]',
                     '[    =  ]', '[     = ]', '[      =]', '[      =]',
                     '[     = ]', '[    =  ]', '[   =   ]', '[  =    ]',
                     '[ =     ]', '[=      ]')
for i in range(100):
    sys.stdout.write('\b\b\b')
    sys.stdout.write(animation_strings[i % len(animation_strings)])
    sys.stdout.flush()
    time.sleep(0.2)


import sys, time
from itertools import cycle
animation = cycle('[=      ]', '[ =     ]', '[  =    ]', '[   =   ]',
                  '[    =  ]', '[     = ]', '[      =]', '[      =]',
                  '[     = ]', '[    =  ]', '[   =   ]', '[  =    ]',
                  '[ =     ]', '[=      ]')
# alternatively:
# animation = cycle('[' + ' ' * n + '=' + ' ' * (6 - n) + ']' 
#                   for n in range(7) + range(6, -1, -1))

for _ in range(100):
    sys.stdout.write('\b\b\b')
    sys.stdout.write(animation.next())
    sys.stdout.flush()
    time.sleep(0.2)


def animation_generator(length):
    while True:
        for n in range(length + 1):
            yield '[' + ' ' * n + '=' + ' ' * (length - n) + ']'
        for n in range(length + 1):
            yield '[' + ' ' * (length - n) + '=' + ' ' * n + ']'

animation = animation_generator(6)
for _ in range(100):
    sys.stdout.write('\b\b\b')
    sys.stdout.write(animation.next())
    sys.stdout.flush()
    time.sleep(0.2)