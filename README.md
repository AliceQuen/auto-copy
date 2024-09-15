# auto-copy
This Project is a tool set to copy things from servers. Featured with back stage running and auto-sync with rsync tool.


## Setup
### Compile
To setup this tool, compile **auto_copy.cc** with any suitable compilor you like.

The output **.o** file is the main excutable.

*Example*

~~~ bash
g++ -o auto.o auto_copy.cc 
~~~

### Setup Password and Destination
The tool uses password to connect ssh, in case your server only supports password. 

Password and destination are in **nohup_copy.exp** file. They should be very easy to find.
## Usage
### Copy from Server
Run the **.o** file with **nohup** and **&**, that is
~~~ bash
nohup .\auto.o &
~~~
### Monitor the Process
Run **show_results.sh** 
~~~ bash
source show_results.sh
~~~
### Stop Copying
Kill **./auto.o** (or names from compiling) process with any process manager.
## Implementation
### Synchronize
This tool uses **rsync** to copy and synchronize the files from server. It downloads whatever is newly added or modified from source with **scp** tech.
### Backstage Runing
This tool runs backstage with **nohup** and **&** mark of bash. The **nohup** tells bash not to hung up this process when terminal exits (or to ignore SIGHUP) and the **&** make the programe run backstage.

The **auto_copy.cc** programe creates a rsync process and monitors it, creates a new one once it dies.

The tool uses **expect** to connect **scp** without manually inputing password. The **expect** is a tool to excute commands without shell. It excute commands, take outputs from them, and then recact. For example, the **expect** lunches a **rsync** and receive password request output from **rsync**, then inputs the password to **rsync** to start copying. 

### Reading Output
The **nohup** redirect the output of the command follows it to a file named **nohup.out** (or other names given). And the script **show_results.sh** shows information in it with a certain format every second.
## Maintainers
[@Alice Quen](https://github.com/AliceQuen) - Project Lead
## TODOS
1. Add auto_delete from server
2. Store password encrypted.
3. Turn the project to fully cpp, maybe installed to be a command. Make password, destination config and monitering into one command.