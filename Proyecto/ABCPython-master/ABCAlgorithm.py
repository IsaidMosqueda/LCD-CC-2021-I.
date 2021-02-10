# github page: https://abcolony.github.io/
# github repository: https://github.com/abcolony/ABCPython


import datetime
import sys
import time
import ABC
import Config
from Reporter import Reporter
import multiprocessing 
import time 
import matplotlib.pyplot as plt

def main(argv):

    abc_times = []
    abcConf = Config.Config(argv)
    abcList = list()
    expT = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S").replace(" ","").replace(":","")
    for run in range(abcConf.RUN_TIME):

        abc = ABC.ABC(abcConf)
        abc.setExperimentID(run,expT)
        start_time = time.time() * 1000
        start_time_ = time.time()
        abc.initial()
        abc.memorize_best_source()

        while(not(abc.stopping_condition())):
            abc.send_employed_bees() #se lanzan abejitas
            abc.calculate_probabilities()
            abc.send_onlooker_bees()
            abc.memorize_best_source()
            abc.send_scout_bees()
            abc.increase_cycle()
            
        abc.globalTime = time.time() * 1000 - start_time
        abc_times.append(time.time() - start_time_)
        abcList.append(abc)
    Reporter(abcList)
    plt.plot(abc_times)
    plt.title('Tiempos de ejecucion')
    plt.grid()
    plt.ylabel('Segundos')
    plt.xlabel('Iteracion')
    plt.show()

if __name__ == '__main__':
    start_time = time.time()

    main(sys.argv[1:])    

    print('That took {} seconds'.format(time.time() - start_time))


