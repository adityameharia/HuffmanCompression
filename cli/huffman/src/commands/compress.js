const {Command, flags} = require('@oclif/command')

class CompressCommand extends Command {
  async run() {
    const {flags} = this.parse(CompressCommand)
    const name = flags.name || 'world'
    this.log(`hello ${name} from /home/adi/HuffmanCompression/cli/huffman/src/commands/compress.js`)
  }
}

CompressCommand.description = `Describe the command here
...
Extra documentation goes here
`

CompressCommand.flags = {
  name: flags.string({char: 'n', description: 'name to print'}),
}

module.exports = CompressCommand
