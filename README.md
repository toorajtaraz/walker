# WALKER

WALKER is a simple command line program that walks through directories.
You can look up and locate any kind of file or directory on your system.

## Installation
First of all clone this repo:

```bash
git clone https://gitlab.com/tooraj.info/walker.git
```
Then you need to make and install it as simple as this:

```bash
make
sudo make install
```
## Usage

```bash
walker -h
```

Output is going to be like:

```bash
'||      ||`      /.\      '||     '||  //' '||''''| '||'''|,
 ||      ||      // \\      ||      || //    ||   .   ||   || 
 ||  /\  ||     //...\\     ||      ||<<     ||'''|   ||...|' 
  \\//\\//     //     \\    ||      || \\    ||       || \\   
   \/  \/    .//       \\. .||...| .||  \\. .||....| .||  \\.
for indentifing path to walk use -D:
===>walker -D /home
for configuring maximum depth use -d:
===>walker -d 200
for creating/updating DB for queries use -u:
===>walker -u
for locating any file or directory on your system use -q:
===>walker -q ".jpg"
===> NOTE THAT ALL SPACES OR TABS ARE REMOVED FROM YOUR INPUT SO IF YOU WANT THEM
===> USE "\" TO ESCAPE THEM!
for help use -h
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

