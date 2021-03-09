const { Command, flags } = require('@oclif/command')
let execFile = require('child_process').execFile
const process = require('process');

class CompressCommand extends Command {
  async run() {
    const {args}=this.parse(CompressCommand)
    const {flags} = this.parse(CompressCommand)
    const name = (flags.name || 'compressed')+".wtf"
    
    execFile(__dirname+"/executables/compress.out", [process.cwd()+"/"+args["path"],name],function (error, stdout, stderr) {
      // This callback is invoked once the child terminates
      // You'd want to check err/stderr as well!
      if(stdout)console.log(stdout)
      else if(error)
      console.log(stderr)
      else console.log(args["path"]+" has been compressed to "+name)
    });
    
  }
}

CompressCommand.description = `Compress compresses the file using huffman algorithm`

CompressCommand.flags = {
  name: flags.string({ char: 'o', description: 'name of output file' }),
}

CompressCommand.args=[{
  name:'path',
  description:'path to input file with respect to the current working directory',
  required:true,
}]

module.exports = CompressCommand
