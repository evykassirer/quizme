quizme
======

This is a really simple program that reads a text file and asks you the 
questions you created for yourself.

**WHEN CREATING THE TEXT FILE:
Make sure you start each section with the top 2 lines as follows:
name_of_topic
TF *or* CUE *or* MC (depending on which format the questions will be)

At the end of each question topic/section, end with a line containing only * 
before starting another section.

At the very end of the file, add ~ as the line after the * to signal end of file.

For TF questions, you can use capital or lowercase t and f on the line
after the question.
For cue cards, alternate between the two sides of the card.
For MC, enter question/answer pairs on two lines each just like the other two, 
and the algorithm will ask the question with the answer as well as three other 
answers randomly selected from the same question topic/category.

There is a ton I still want to do with this!
The next step will probably be adding graphics.
I'd also like to improve the way input works, 
and adding some better error handling.
