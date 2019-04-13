from hyperopt import fmin, tpe, hp, rand
import os

space = [
    hp.quniform('scan_num', 100, 500, 1),
    hp.quniform('batch_size', 15, 200, 1),
    hp.quniform('check_num', 150, 250, 1),
    hp.uniform('len_delta', 0.05, 100),
    hp.quniform('priority_dead_line', 0, 1100, 1),
    hp.quniform('time_delta', 0, 200, 1)
]

best_loss = 1000000
num = 0

def func(args):
    global num
    num += 1
    cmd = './preCodeCraft-2019 ' + '2-map-training-1'
    idx = 0
    for val in args:
        cmd += ' '
        if idx != 3:
            cmd += str(int(val))
        else:
            cmd += str(val)
        idx += 1
    with os.popen(cmd) as f:
        loss = int(f.read().strip())
        global best_loss
        if loss < best_loss:
            best_loss = loss
            print(str(num) + ': '+ str(best_loss) + ' ' + str(args))
        return loss

best = fmin(func, space, algo=tpe.suggest, max_evals=600)
