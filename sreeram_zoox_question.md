
Premise

We have a simple robot that can only take a few actions. The commands are sent one byte at a time over a serial link as command packets. These packets have the following format:

Header (4 bytes)

Header = "ZOOX", ASCII

Length (1 byte)

1 ASCII decimal digit character, so between '0' and '9' (inclusive).

Length = command length + repeat length (excludes header, length, checksum)

Command (Length-1 bytes)

ASCII, one of: "LEFT", "RIGHT", "FORWARD", "BEEP"

Repeat (1 byte)

1 ASCII decimal digit character, so between '0' and '9' (inclusive).

Number of times to repeat the command

Checksum (1 byte)

Open in Window case alphabetic character, so between 'A' and 'Z'
(inclusive).

Simple computation to check content for bit errors

Calculated over the following section: [Length, Command, Repeat] (excludes header, checksum)

Assignment

Using the provided code, implement the parse(c) function to identify and execute each command packet. The parse(c) function takes one byte at a time because that is

how the data will arrive for the simple robot.

Feel free to add more functions and definitions, but do not change main().

execute_packet_command(...) has been provided to assist with the test output.

A few example inputs -> outputs for the complete system:

ZOOX6RIGHT3X -> Cmd: RRR

ZOOX5LEFT2QZ00X5BEEP3C> Cmd: LL!!!

If there are multiple complete packets, they should all get called as parameters to execute_packet_command(...).

This simple robot lives in a harsh world. These packets are coming in over a bad link. There may be lots of bit errors, random erroneous bytes, and all kinds of data loss. We need this code to silently drop all the junk data, but output packets that pass the checksum. For example, this means we could have the following inputs -> outputs:

abcZOOX6RIGHT2Wabc -> Cmd: RR

abcZ00X6lmnopRIGHT3Xabc ->

ZOOXGRIGHT3abc > Cmd:

Cmd:

(notice the checksum byte is lost on that last one)
If your parser identifies bytes as belonging to a complete packet, those bytes will not be used for any later packets.

Code development workflow

Please use the provided in-browser RemoteInterview coding environment. It records your progress. This way the person reviewing your submission will be able to review your development and debugging process. Having a clean and clear process will earn you the appreciation of the person reviewing your code.

