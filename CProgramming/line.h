#ifndef LINE_H
#define LINE_H

void clear_line(void); // clear the current line

void add_word(const char *word); // adds word to the end of the current line.

int space_remaining();

void write_line(void); // writes the current line with justification

void flush_line(void); // writes the current line without justification

#endif // LINE_H
