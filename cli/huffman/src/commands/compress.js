const { Command, flags } = require('@oclif/command')
let execFile = require('child_process').execFile
const process = require('process');
const os=require("os")

class CompressCommand extends Command {
  async run() {
    const {args}=this.parse(CompressCommand)
    const {flags} = this.parse(CompressCommand)
    const name = (flags.name || args["path"].split('.')[0])+".wtf"

    let executable;

    if(os.platform()=="linux"){
      executable="compress.out"
    }
    else if(os.platform()=="win32"){
      executable="compress.exe"
    }
    else{
      console.log("Your os is not supported at the moment.")
      process.exit(1)
    }
    
    execFile(__dirname+"/executables/"+executable, [process.cwd()+"/"+args["path"],name],function (error, stdout, stderr) {
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
