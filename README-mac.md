
You will need Apple's Xcode (at least version 7, preferably 8.x) and the Xcode Command Line Tools:

https://itunes.apple.com/us/app/xcode/id497799835?mt=12

And Homebrew:

http://brew.sh/

Use the brewfile to install the necessary packages:

```shell
brew bundle
```

or 

```shell
brew tap discoteq/discoteq; brew install flock autoconf autogen automake gcc@6 binutils protobuf coreutils wget
```

Get all that installed, then run:

```shell
git clone https://github.com/Fair-Exchange/safecoin.git
cd safecoin
./zcutil/build-mac.sh
./zcutil/fetch-params.sh
```

To build a distributable version of VerusCoin then run the makeReleaseMac.sh script after building. This will fix the dependency references and move the safecoind and safecoin-cli binaries to the safe/mac/verus-cli directory along with the 6 libraries required for it to work properly.

When you are done building, you need to create `Safecoin.conf` the Mac way. 

```shell
mkdir ~/Library/Application\ Support/Safecoin
touch ~/Library/Application\ Support/Safecoin/Safecoin.conf
nano ~/Library/Application\ Support/Safecoin/Safecoin.conf
```

Add the following lines to the Safecoin.conf file:

```shell
rpcuser=dontuseweakusernameoryougetrobbed
rpcpassword=dontuseweakpasswordoryougetrobbed
txindex=1
addnode=dnsseed.ipv6admin.com
addnode=dnsseed.fair.exchange
addnode=explorer.safecoin.org
addnode=45.63.13.60
addnode=176.107.179.32
addnode=node.safc.cc
```

Happy Building
