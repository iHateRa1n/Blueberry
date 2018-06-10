# Blueberry

Blueberry is a kernel exploit inside of KEYMAP.h, which is a header inside of the [electron kernel](https://github.com/electronOS/electron).

In KEYMAP.h, there is one variable; called key_map. 

There was (before electron 0.1), this line:

```c
unsigned char key_map[128] {...};
```

What is in the brackets doesn't matter, what matters is that is wasn't a const.

So, you can overflow this buffer, and then write to any location you like. 

Example:

```c
key_map[0x80 + 0xbeef] = 'A';
```

Would overflow the buffer, and then write to the byte which is 0xbeef bytes after the end of the buffer, a capital A. (\x41 / 0x41)

And to read the buffer: (which is unpatchable)

```c
char demo;
demo = key_map[0x80 + 0x4];
```

Which would read the byte, that is 4 bytes after the end of the buffer, and store it in demo. 

# Patch

It was patched (for writing), by turning this line:

```c
unsigned char key_map[128] {...};
```

Into this line:

```c
const unsigned char key_map[128] {...};
```

Which makes it so none of the buffer can be changed, so you can't write past the buffer anymore. 

However, you CAN still read past the buffer. 

\- iH8Ra1n, 2018. 
