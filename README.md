# ping
> our version of ping.

[![Build Status](https://travis-ci.org/Z1NZ/ping.svg?branch=master)](https://travis-ci.org/Z1NZ/ping)

The goal of this project is to make you recode the Ping command and to have you step a foot in the wondrous world of network.

![](header.png)

## Installation

Linux :

```sh
	make install
```

## Usage example

A few motivating and useful examples of how your product can be used. Spice this up with code blocks and potentially more screenshots.

_For more examples and usage, please refer to the [Wiki][wiki]._
```sh
$ ping www.example.com
PING www.example.com (93.184.216.34): 56 data bytes
64 bytes from 93.184.216.34: icmp_seq=0 ttl=56 time=11.632 ms
64 bytes from 93.184.216.34: icmp_seq=1 ttl=56 time=11.726 ms
64 bytes from 93.184.216.34: icmp_seq=2 ttl=56 time=10.683 ms
64 bytes from 93.184.216.34: icmp_seq=3 ttl=56 time=9.674 ms
64 bytes from 93.184.216.34: icmp_seq=4 ttl=56 time=11.127 ms

--- www.example.com ping statistics ---
5 packets transmitted, 5 packets received, 0.0% packet loss
round-trip min/avg/max/stddev = 9.674/10.968/11.726/0.748 ms
```

## Development setup

Within the mandatory part, you are allowed to use the following functions:
 - getpid
 - getuid
 - getaddrinfo
 - gettimeofday
 - inet_ntop
 - inet_pton
 - exit
 - signal
 - alarm
 - setsockopt
 - recvmsg
 - sendto
 - socket

```
make
```

## Release History

- nothing yet

## Meta

sofiane rabah – [@srabah](https://twitter.com/srabah) – sofiane.rabah@gmail.com

## Contributing

1. Fork it (<https://github.com/z1nz/ping/fork>)
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request

<!-- Markdown link & img dfn's -->
[travis-url]: https://travis-ci.org/Z1NZ/ping	"Travis"
