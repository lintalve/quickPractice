/*
The std::stringstream class in C++ is derived from std::iostream, and its primary purpose is to perform input/output operations on a string buffer. Below are the member functions provided by std::stringstream grouped according to their functionality:

Construction and Assignment
stringstream (constructor): Constructs a std::stringstream object.
operator=  : Assigns content to the stringstream.
 
 
Buffer Management
 
str()             : Gets the current content of the string buffer.
str(const std::string&)      : Sets the string buffer with new content.
 
Input/Output Operations
 
Since std::stringstream inherits from std::iostream, it can perform these common operations:

Input:
operator>>
get()
getline()
ignore()
read()
readsome()
peek()
unget()
 
Output:
 
operator<<
put()
write()
eof()  : Checks if the end of the buffer is reached.
fail()  : Checks if an operation has failed.
good()  : Checks if the stream is in a good state.
clear()  : Clears error flags on the stream.
flush()  : Flushes the output stream buffer.
 
Positioning
 
tellg()  : Returns the current get pointer (input position) within the string buffer.
tellp()  : Returns the current put pointer (output position) within the string buffer.
seekg(pos)  : Sets the get pointer to a specific position.
seekp(pos)  : Sets the put pointer to a specific position.
seekg(off, dir)  : Sets the get pointer relative to the current position, beginning, or end.
seekp(off, dir)  : Sets the put pointer relative to the current position, beginning, or end.
 
Other Common Functions
Inherited from std::ios:

Formatting: Functions like

precision()
width()
fill()
setf()
unsetf()
 
Locale Management:
 
imbue()
Inherited from std::basic_ios:

State:
rdstate()
setstate()
exceptions().
*/
