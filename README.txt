Authors: Shreyas Talluri and Revanth revanthBottu

Group members: Shreyas Talluri and Revanth Bottu

Functionality of our program:

Our hash function starts with an initial hash of a very large 32 bit number. 
We then go into a for loop that iterates over every character in the word.
We then set a value named weight based on the location of the character within the word.
After computing the length of the word, and performing a mod operation, we add that to the character, and assign all of this back into the hash variable.
Once this is done, we perform bitwise operations, rotating the hash value left by 17 bits and then 1 bit to the right, and these values were essentially gathered through trial and error.
We perform bitwise xor operation on hash and c*18, and then assign that value back into hash.
Finally, we return hash after performing one last bitwise & operation that ensures that the outputted value is positive.
