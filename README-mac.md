## Install for Mac OS X

First off you need Apple's Xcode (at least version 7, preferably 8.x or later) and the Xcode Command Line Tools:

https://itunes.apple.com/us/app/xcode/id497799835?mt=12

And Homebrew:

http://brew.sh/

And this is the list of brew packages you'll need installed:

```shell
brew tap discoteq/discoteq; brew install flock
brew install autoconf autogen automake
brew install gcc@6
brew install binutils
brew install protobuf
brew install coreutils
brew install wget
```

or 

```shell
brew tap discoteq/discoteq; brew install flock autoconf autogen automake gcc@6 binutils protobuf coreutils wget
```

Get all that installed, then run:

```shell
git clone https://github.com/fair-exchange/safecoin.git
cd safecoin
./zcutil/build-mac.sh
./zcutil/fetch-params.sh
```

To build a distributable version of safecoin then run the makeDistrib.sh script after building.

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
addnode=dnsseedua.local.support
addnode=dnsseed.ipv6admin.com
```

Happy Building
