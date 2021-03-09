huffman
=======

A cli tool to compress files usig huffman algorithm 

[![oclif](https://img.shields.io/badge/cli-oclif-brightgreen.svg)](https://oclif.io)
[![Version](https://img.shields.io/npm/v/huffman.svg)](https://npmjs.org/package/huffman)
[![Downloads/week](https://img.shields.io/npm/dw/huffman.svg)](https://npmjs.org/package/huffman)
[![License](https://img.shields.io/npm/l/huffman.svg)](https://github.com/adityameharia/huffmanCompression/blob/master/package.json)

<!-- toc -->
* [Usage](#usage)
* [Commands](#commands)
<!-- tocstop -->
# Usage
<!-- usage -->
```sh-session
$ npm install -g huffman-compressor
$ huffman COMMAND
running command...
$ huffman (-v|--version|version)
huffman-compressor/0.0.0 linux-x64 node-v14.15.4
$ huffman --help [COMMAND]
USAGE
  $ huffman COMMAND
...
```
<!-- usagestop -->
# Commands
<!-- commands -->
* [`huffman compress PATH`](#huffman-compress-path)
* [`huffman decompress PATH`](#huffman-decompress-path)
* [`huffman hello`](#huffman-hello)
* [`huffman help [COMMAND]`](#huffman-help-command)

## `huffman compress PATH`

Compress compresses the file using huffman algorithm

```
USAGE
  $ huffman compress PATH

ARGUMENTS
  PATH  path to input file with respect to the current working directory

OPTIONS
  -o, --name=name  name of output file
```

_See code: [src/commands/compress.js](https://github.com/adityameharia/huffmanCompression/blob/v0.0.0/src/commands/compress.js)_

## `huffman decompress PATH`

Decompress decompresses the file using huffman algorithm

```
USAGE
  $ huffman decompress PATH

ARGUMENTS
  PATH  path to input file with respect to the current working directory

OPTIONS
  -o, --name=name  name of output file
```

_See code: [src/commands/decompress.js](https://github.com/adityameharia/huffmanCompression/blob/v0.0.0/src/commands/decompress.js)_

## `huffman hello`

Describe the command here

```
USAGE
  $ huffman hello

OPTIONS
  -n, --name=name  name to print

DESCRIPTION
  ...
  Extra documentation goes here
```

_See code: [src/commands/hello.js](https://github.com/adityameharia/huffmanCompression/blob/v0.0.0/src/commands/hello.js)_

## `huffman help [COMMAND]`

display help for huffman

```
USAGE
  $ huffman help [COMMAND]

ARGUMENTS
  COMMAND  command to show help for

OPTIONS
  --all  see all commands in CLI
```

_See code: [@oclif/plugin-help](https://github.com/oclif/plugin-help/blob/v3.2.2/src/commands/help.ts)_
<!-- commandsstop -->
