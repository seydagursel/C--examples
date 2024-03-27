#include <stdio.h>
#include <string.h>

void fill_table(char table[10][100]);
void print_table(char table[10][100]);
int find_and_replace_string(char * sentence, char * word);
void reverse(char * sentence, int position, char * word);
void find_and_replace_table(char table[10][100], char * word);

void fill_table(char table[10][100])
{
    int i=0;
    while( i<10)
    {
        printf("Please enter a sentence: ");
        scanf(" %[^\n]",*(table+i));

        int len = strlen(*(table+i));

        if (strcmp(*(table+i),"end")==0)
            break;
        i++;
    }
}

void print_table(char table[10][100]) {
    int k=0;
    while( k<10) {
        
        int len = strlen(*(table+k));
        if (strcmp(*(table+k),"end")==0){
            break;
        }
        
        printf("%s\n",*(table+k));
        k++;
    }
}

int find_and_replace_string(char * sentence, char * word) {
    int len = strlen(sentence);
    int len_Word = strlen(word);
    
    for( int i = 0;i <= len - len_Word; i++) {
        int k;
        for (k = 0; k < len_Word; k++){
            if (*(sentence+i+k) != *(word+k))
                break;
        }
            
        if (k == len_Word){
            reverse(sentence, i, word);
        }
            
    }
    return 0;
}

void reverse(char * sentence, int position, char * word) {
    
    int right = position + strlen(word)-1;
    int left = position; 
    while(left < right) {
        char temp = *(sentence + left);
        *(sentence + left) = *(sentence + right);
        *(sentence + right) = temp;
        
        right--;
        left++;
    }
}

void find_and_replace_table(char table[10][100], char * word) {
    int i=0;
    while( i<10) {
        
        int len = strlen(*(table+i));
        if (strcmp(*(table+i),"end")==0){
            break;
        }
            
                
        find_and_replace_string(*(table+i), word);
        i++;
    }
}

int main() {
    char table[10][100];
    char word[100];
    fill_table(table);
    printf("Please enter the word:");
    scanf(" %s[^\n]",word);
    find_and_replace_table(table, word);
    print_table(table);
    return 0;
}
