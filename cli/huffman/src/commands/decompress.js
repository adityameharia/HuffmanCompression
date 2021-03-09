const {Command, flags} = require('@oclif/command')
let execFile = require('child_process').execFile
const process = require('process');

class DecompressCommand extends Command {
  async run() {
    const {args}=this.parse(DecompressCommand)
    const {flags} = this.parse(DecompressCommand)
    const name = (flags.name || args["path"])+".txt"
    
    execFile(__dirname+"/executables/decompress.out", [process.cwd()+"/"+args["path"],name],function (error, stdout, stderr) {
      // This callback is invoked once the child terminates
      // You'd want to check err/stderr as well!
      if(stdout)console.log(stdout)
      else if(error)
      console.log(stderr)
      else console.log(args["path"]+" has been decompressed to "+name)
    });
    
  }
}

DecompressCommand.description = `Decompress decompresses the file using huffman algorithm`

DecompressCommand.flags = {
  name: flags.string({ char: 'o', description: 'name of output file' }),
}

DecompressCommand.args=[{
  name:'path',
  description:'path to input file with respect to the current working directory',
  required:true,
}]

module.exports = DecompressCommand
