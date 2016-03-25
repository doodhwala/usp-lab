/*
3. Experiment with set user bit.
   Create two users(same rama and krishna).
   rama creates a file junk.txt with permissions rw-------.
   rama creates an executable program to append the string "adding a line" to the file junk.txt.
   Let krishna login and check whether he can append.
   rama changes the permission on the executable program and adds set user bit.
   Let krishna try again. check what happens to the file junk.txt.
*/


Command-line

To add a user you must use the sudo command. Here are the commands:
To add a user. NOTE: do not use the useradd command.

$ sudo adduser <username>

To see the options for adding a user try the man command.

$ man adduser

Here is a useful example of the useradd command. Why use useradd? It gives a few more options for special cases. To add a user, give her a standard home directory in the /home folder and specify the shell she accesses by default do this:

$ sudo useradd username -m -s /bin/bash 
$ sudo passwd username 

Groups

You might also wish to create a new group for your users.

# sudo addgroup <groupname>

To add a new user to a existing group you would do this:

# sudo adduser <username> audio

To add an existing user to an existing group you can use the same command:

# sudo adduser <username> <groupname>

or

# sudo usermod -aG <groupname> <username>
