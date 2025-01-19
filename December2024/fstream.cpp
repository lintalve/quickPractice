/*
 std::ios_base
     ├── std::basic_ios
           ├── std::istream
           │     ├── std::ifstream
           │     └── std::iostream
           │            └── std::fstream
           ├── std::ostream
           │     ├── std::ofstream
           │     └── std::iostream

 
 
 
                                             iostream_base
                                                   |
                                                   |
                                               basic_ios
                                                /      \
                                               /        \
                                  ________istream       ostream_________
                                 /        /    \        /   \           \
                                /        /      \      /     \           \
                               /        /        \    /       \           \
                    istringstream    ifstream    iostream    ofstream    ostringstream
                                                   |
                                                   |
                                                   |
                                                fstream
                                                 /    \
                                                /      \
                                          ifstream     ofstram
 
 In C++'s Standard Library, std::fstream is used for file input and output operations. It inherits from both std::istream (for reading input) and std::ostream (for writing output), and provides various methods. Below is a categorized list of the commonly used methods available through an std::fstream object:
 
 
//////////////////////////  std::fstream  ////////////////////////
 
 File Handling Methods
 
 open(const char* filename, ios_base::openmode mode)     //file.open(const std::string path, std::ios::in); //to read
 Opens a file with the specified filename and mode.
 
 is_open()                                                               Checks if the file is successfully opened.
 close()                                                                 Closes the file.
 setstate(std::ios_base::iostate)                                        Sets the stream state flags.
 clear(std::ios_base::iostate = std::ios_base::goodbit)                  Clears error flags on the stream.
 
 Input Methods (from std::istream)
 
 getline(char* buffer, std::streamsize count, char delimiter = '\n')    Reads a line of text from the file into a buffer.
 read(char* s, std::streamsize n)                                       Reads a specified number of characters into a buffer.
 get()                                                           Reads a single character or retrieves the next character in the stream.
 peek()                                                          Returns the next character in the input sequence without extracting it.
 ignore(std::streamsize n = 1, int delim = EOF)                   Skips characters in the input sequence.
 seekg(std::streamoff offset, std::ios_base::seekdir direction)   Sets the position of the next input operation.
 tellg()                                                          Returns the current position of the input pointer.
 operator>>     (extraction operator)                             Reads formatted data from the stream.
 
 Output Methods (from std::ostream)
 
 write(const char* s, std::streamsize n)                           Writes a specified number of characters to the file.
 put(char c)                                                       Writes a single character to the stream.
 flush()                                                           Flushes the output buffer to the file.
 seekp(std::streamoff offset, std::ios_base::seekdir direction)    Sets the position of the next output operation.
 tellp()                                                           Returns the current position of the output pointer.
 operator<< (insertion operator)                                   Writes formatted data to the stream.
 
 
 Stream State Management Methods
 
                                                        
 eof()                          Checks if the end of the file is reached.
 fail()                         Checks if a logical error occurred on the stream.
 bad()                          Checks if a serious error occurred on the stream.
 good()                         Checks if the stream is in a good state.
 rdstate()                      Returns the current stream state.
 
 Destructor
 
 ~fstream()                      Closes the file if it is open and performs cleanup.
 
 Helper Methods
 
 rdbuf()                        Accesses the stream's underlying buffer.
 
 By leveraging these methods, you can handle a wide range of file input/output operations.
 Remember to include <fstream> in your code to use std::fstream.







 
