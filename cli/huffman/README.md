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
$ huffman-compressor COMMAND
running command...
$ huffman-compressor (-v|--version|version)
huffman-compressor/0.0.1 linux-x64 node-v14.15.4
$ huffman-compressor --help [COMMAND]
USAGE
  $ huffman-compressor COMMAND
...
```
<!-- usagestop -->
# Commands
<!-- commands -->
* [`huffman-compressor compress PATH`](#huffman-compressor-compress-path)
* [`huffman-compressor decompress PATH`](#huffman-compressor-decompress-path)
* [`huffman-compressor hello`](#huffman-compressor-hello)
* [`huffman-compressor help [COMMAND]`](#huffman-compressor-help-command)

## `huffman-compressor compress PATH`

Compress compresses the file using huffman algorithm

```
USAGE
  $ huffman-compressor compress PATH

ARGUMENTS
  PATH  path to input file with respect to the current working directory

OPTIONS
  -o, --name=name  name of output file
```

_See code: [src/commands/compress.js](https://github.com/adityameharia/huffmanCompression/blob/v0.0.1/src/commands/compress.js)_

## `huffman-compressor decompress PATH`

Decompress decompresses the file using huffman algorithm

```
USAGE
  $ huffman-compressor decompress PATH

ARGUMENTS
  PATH  path to input file with respect to the current working directory

OPTIONS
  -o, --name=name  name of output file
```

_See code: [src/commands/decompress.js](https://github.com/adityameharia/huffmanCompression/blob/v0.0.1/src/commands/decompress.js)_

## `huffman-compressor hello`

Describe the command here

```
USAGE
  $ huffman-compressor hello

OPTIONS
  -n, --name=name  name to print

DESCRIPTION
  ...
  Extra documentation goes here
```

_See code: [src/commands/hello.js](https://github.com/adityameharia/huffmanCompression/blob/v0.0.1/src/commands/hello.js)_

## `huffman-compressor help [COMMAND]`

display help for huffman-compressor

```
USAGE
  $ huffman-compressor help [COMMAND]

ARGUMENTS
  COMMAND  command to show help for

OPTIONS
  --all  see all commands in CLI
```

_See code: [@oclif/plugin-help](https://github.com/oclif/plugin-help/blob/v3.2.2/src/commands/help.ts)_
<!-- commandsstop -->
