huffman
=======

A cli tool written in nodejs which uses cpp binaries to compress files usig huffman algorithm.
Currently supports Windows,Mac OS and linux. 

[![oclif](https://img.shields.io/badge/cli-oclif-brightgreen.svg)](https://oclif.io)
[![Version](https://img.shields.io/npm/v/huffman.svg)](https://www.npmjs.com/package/huffman-compressor)
[![Downloads/week](https://img.shields.io/npm/dw/huffman.svg)](https://www.npmjs.com/package/huffman-compressor)
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
huffman-compressor/0.1.0 linux-x64 node-v14.15.4
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

_See code: [src/commands/compress.js](https://github.com/adityameharia/huffmanCompression/blob/v0.1.0/src/commands/compress.js)_

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

_See code: [src/commands/decompress.js](https://github.com/adityameharia/huffmanCompression/blob/v0.1.0/src/commands/decompress.js)_

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
