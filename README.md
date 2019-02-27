# 42__Project--ft_p
*A simple, lightweight, concurrent, single-port ftp server implemented in c with select().*

# Usage

```sh
$ make
$ ./server
$ ./client localhost 7777
```
* server can accept port as parameter.
* client can accept both ip(can be ip6) and port.
### Supported Commands
```sh
ls get put cd pwd
```
### Bounus Commands
| Command | Description |
| ------ | ------ |
| lls | [local ls, ls the current directory] |
| lcd | [local cd, navigate between directory] |
| lpwd | [local pwd, get the local path] |
| mkdir | [create a directory on the server side] |
| unlink | [delete a file on the server side] |
| rmdir | [remove a directory on the server side] |

### Bonus Feature
- [x] Nice color 
- [x] IP6 support.
- [ ] RFC (hell no)
