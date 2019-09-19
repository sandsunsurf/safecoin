import platform
import os
import re
import random
from slickrpc import Proxy


# define function that fetchs rpc creds from .conf
def def_credentials(chain):
    rpcport ='';
    operating_system = platform.system()
    if operating_system == 'Darwin':
        ac_dir = os.environ['HOME'] + '/Library/Application Support/Safecoin'
    elif operating_system == 'Linux':
        ac_dir = os.environ['HOME'] + '/.safecoin'
    elif operating_system == 'Windows':
        ac_dir = '%s/safecoin/' % os.environ['APPDATA']
    if chain == 'SAFE':
        coin_config_file = str(ac_dir + '/safecoin.conf')
    else:
        coin_config_file = str(ac_dir + '/' + chain + '/' + chain + '.conf')
    with open(coin_config_file, 'r') as f:
        for line in f:
            l = line.rstrip()
            if re.search('rpcuser', l):
                rpcuser = l.replace('rpcuser=', '')
            elif re.search('rpcpassword', l):
                rpcpassword = l.replace('rpcpassword=', '')
            elif re.search('rpcport', l):
                rpcport = l.replace('rpcport=', '')
    if len(rpcport) == 0:
        if chain == 'SAFE':
            rpcport = 7771
        else:
            print("rpcport not in conf file, exiting")
            print("check "+coin_config_file)
            exit(1)

    return(Proxy("http://%s:%s@127.0.0.1:%d"%(rpcuser, rpcpassword, int(rpcport))))


