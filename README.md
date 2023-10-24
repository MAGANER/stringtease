# stringtease
Linux cli tool - the combination of head and tail with improvements

# How to build
```
git clone https://github.com/MAGANER/stringtease.git
cd stringtease/
./build
```

# How to use
## Examples 
```cat file | stringtease --head 0s```    - read first 10 strings from file's beginning<br>
```cat file | stringtease --tail 0c -r``` - read first 10 characters from file's end and reverse output to make it human-readable<br>
```cat file | stringtease --head 6s 10s``` - read from 6 to 10 string.
