[![Build Status](https://travis-ci.org/fair-exchange/safecoin.svg?branch=dev)](https://travis-ci.org/fair-exchange/safecoin)
---
![Safecoin Logo](https://i.imgur.com/vIwVtqv.png "Safecoin Logo")


## Safecoin

This is the official Safecoin sourcecode repository based on https://github.com/jl777/safecoin. 

## Development Resources

- Safecoin Website: [https://safecoinplatform.com](https://safecoinplatform.com/)
- Safecoin Blockexplorer: [https://safeexplorer.io](https://safeexplorer.io/)
- Safecoin Discord: [https://safecoinplatform.com/discord](https://safecoinplatform.com/discord)
- Forum: [https://forum.safecoinplatform.com](https://forum.safecoinplatform.com/)
- Mail: [info@safecoinplatform.com](mailto:info@safecoinplatform.com)
- Support: [https://support.safecoinplatform.com/support/home](https://support.safecoinplatform.com/support/home)
- Knowledgebase & How-to: [https://support.safecoinplatform.com/en/support/solutions](https://support.safecoinplatform.com/en/support/solutions)
- API references & Dev Documentation: [https://docs.safecoinplatform.com](https://docs.safecoinplatform.com/)
- Blog: [https://blog.safecoinplatform.com](https://blog.safecoinplatform.com/)
- Whitepaper: [Safecoin Whitepaper](https://safecoinplatform.com/whitepaper)
- Safecoin Platform public material: [Safecoin Platform public material](https://docs.google.com/document/d/1AbhWrtagu4vYdkl-vsWz-HSNyNvK-W-ZasHCqe7CZy0)

## List of Safecoin Platform Technologies

- Delayed Proof of Work (dPoW) - Additional security layer and Safecoins own consensus algorithm.
- zk-SNARKs - Safecoin Platform's privacy technology for shielded transactions
- Tokens/Assets Technology - create "colored coins" on the Safecoin Platform and use them as a layer for securites
- Reward API - Safecoin CC technology for securities
- CC - Crypto Conditions to realize "smart contract" logic on top of the Safecoin Platform
- Jumblr - Decentralized tumbler for SAFE and other cryptocurrencies
- Assetchains - Create your own Blockchain that inherits all Safecoin Platform functionalities and blockchain interoperability
- Pegged Assets - Chains that maintain a peg to fiat currencies
- Peerchains - Scalability solution where sibling chains form a network of blockchains
- More in depth covered [here](https://docs.google.com/document/d/1AbhWrtagu4vYdkl-vsWz-HSNyNvK-W-ZasHCqe7CZy0)
- Also note you receive 5% APR on your holdings.
[See this article for more details](https://safecoinplatform.atlassian.net/wiki/spaces/KPSD/pages/20480015/Claim+SAFE+Interest+in+Safewallet)

## Tech Specification
- Max Supply: 200 million SAFE.
- Block Time: 1M 2s
- Block Reward: 3SAFE
- Mining Algorithm: Equihash

## About this Project
Safecoin is based on Zcash and has been extended by our innovative consensus algorithm called dPoW which utilizes Bitcoin's hashrate to store Safecoin blockchain information into the Bitcoin blockchain. Other new and native Safecoin features are the privacy technology called JUMBLR, our assetchain capabilities (one click plug and play blockchain solutions) and a set of financial decentralization and interoperability technologies. More details are available under https://safecoinplatform.com/ and https://blog.safecoinplatform.com.

## Getting started

### Dependencies

```shell
#The following packages are needed:
sudo apt-get install build-essential pkg-config libc6-dev m4 g++-multilib autoconf libtool ncurses-dev unzip git python python-zmq zlib1g-dev wget libcurl4-openssl-dev bsdmainutils automake curl
```

### Build Safecoin

This software is based on zcash and considered experimental and is continously undergoing heavy development.

The dev branch is considered the bleeding edge codebase while the master-branch is considered tested (unit tests, runtime tests, functionality). At no point of time do the Safecoin Platform developers take any responsbility for any damage out of the usage of this software. 
Safecoin builds for all operating systems out of the same codebase. Follow the OS specific instructions from below.

#### Linux
```shell
git clone https://github.com/safecoinplatform/safecoin --branch master --single-branch
cd safecoin
./zcutil/fetch-params.sh
# -j8 = using 8 threads for the compilation - replace 8 with number of threads you want to use
./zcutil/build.sh -j8
#This can take some time.
```

#### OSX
Ensure you have [brew](https://brew.sh) and the command line tools installed (comes automatically with XCode) and run:
```shell
brew update && brew install gcc@6
git clone https://github.com/safecoinplatform/safecoin --branch master --single-branch
cd safecoin
./zcutil/fetch-params.sh
# -j8 = using 8 threads for the compilation - replace 8 with number of threads you want to use
./zcutil/build-mac.sh -j8
#This can take some time.
```

#### Windows
Use a debian cross-compilation setup with mingw for windows and run:
```shell
git clone https://github.com/safecoinplatform/safecoin --branch master --single-branch
cd safecoin
./zcutil/fetch-params.sh
# -j8 = using 8 threads for the compilation - replace 8 with number of threads you want to use
./zcutil/build-win.sh -j8
#This can take some time.
```
**safecoin is experimental and a work-in-progress.** Use at your own risk.

To reset the Safecoin blockchain change into the *~/.safecoin* data directory and delete the corresponding files by running `rm -rf blocks chainstate debug.log safecoinstate db.log`

#### Create safecoin.conf

Create a safecoin.conf file:

```
mkdir ~/.safecoin
cd ~/.safecoin
touch safecoin.conf

#Add the following lines to the safecoin.conf file:
rpcuser=yourrpcusername
rpcpassword=yoursecurerpcpassword
rpcbind=127.0.0.1
txindex=1
addnode=5.9.102.210
addnode=78.47.196.146
addnode=178.63.69.164
addnode=88.198.65.74
addnode=5.9.122.241
addnode=144.76.94.38
addnode=89.248.166.91
```
### Create your own Blockchain based on Safecoin

Safecoin allows anyone to create a runtime fork which represents an independent Blockchain. Below are the detailed instructions:
Setup two independent servers with at least 1 server having a static IP and build safecoind on those servers.  

#### On server 1 (with static IP) run:
```shell
./safecoind -ac_name=name_of_your_chain -ac_supply=100000 -bind=ip_of_server_1 &
```

#### On server 2 run:
```shell
./safecoind -ac_name=name_of_your_chain -ac_supply=100000 -addnode=ip_of_server_1 -gen &
```

**Safecoin is based on Zcash which is unfinished and highly experimental.** Use at your own risk.

License
-------
For license information see the file [COPYING](COPYING).

**NOTE TO EXCHANGES:**
https://bitcointalk.org/index.php?topic=1605144.msg17732151#msg17732151
There is a small chance that an outbound transaction will give an error due to mismatched values in wallet calculations. There is a -exchange option that you can run safecoind with, but make sure to have the entire transaction history under the same -exchange mode. Otherwise you will get wallet conflicts.

**To change modes:**

a) backup all privkeys (launch safecoind with `-exportdir=<path>` and `dumpwallet`)
b) start a totally new sync including `wallet.dat`, launch with same `exportdir`
c) stop it before it gets too far and import all the privkeys from a) using `safecoin-cli importwallet filename`
d) resume sync till it gets to chaintip

For example:
```shell
./safecoind -exportdir=/tmp &
./safecoin-cli dumpwallet example
./safecoin-cli stop
mv ~/.safecoin ~/.safecoin.old && mkdir ~/.safecoin && cp ~/.safecoin.old/safecoin.conf ~/.safecoin.old/peers.dat ~/.safecoin
./safecoind -exchange -exportdir=/tmp &
./safecoin-cli importwallet /tmp/example
```
---


Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
