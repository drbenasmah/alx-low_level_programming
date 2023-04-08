/**
 * hash_djb2 - djb2 hash function
 * @str: string to be hashed
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash; // initialize hash variable as unsigned long int
    int c; // initialize c variable as an integer

    hash = 5381; // initialize hash variable with 5381
    while ((c = *str++)) // loop through each character in the string
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        // left-shift hash by 5 and add hash to it; then add the ASCII value of the current character
        // this is equivalent to multiplying by 33 and adding the ASCII value of the current character
    }
    return (hash); // return the hash value
}
