# 42__Project--ft_p
a simple, lightweight, concurrent, single-port ftp server implemented in c with select(). 


### Usage

```sh
$ make
$ ./server
$ ./client localhost 7777
``

### Supported commands
```sh
ls get put cd pwd
``
## bounus commands
| Command | Description |
| ------ | ------ |
| lls | [local ls, ls the current directory] |
| lcd | [local cd, navigate between directory] |
| lpwd | [local pwd, get the local path] |
| mkdir | [create a directory on the server side] |
| unlink | [delete a file on the server side] |
| rmdir | [remove a directory on the server side] |

## bounus feature
nice color and IP6 support.
