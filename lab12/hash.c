#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define strsize 30
#define capacity 25

struct Hash{
    char *Table[capacity];
    int size;
}typedef Hash;
Hash *hash;

//Function to calculate a hashvalue
long long polynomialRoll(char *str){
    // P and M
    int p = 31;
    int m = 1e9 + 9;
    long long powerOfP = 1;
    long long hashVal = 0;
 
    // Loop to calculate the hash value
    // by iterating over the elements of string
    for (int i = 0; i < strlen(str); i++) {
        hashVal = (hashVal + (str[i] - 'a' + 1) * powerOfP) % m;
        powerOfP = (powerOfP * p) % m;
    }
    return hashVal;
}

//Function to calculate the hashindex using hashvalue
int hashCode(long long x){
    return x%capacity;
}

//Function to insert the string into the hashtable
int insert(char *str){
    if(hash->size<capacity){
        int hashIndex = hashCode(polynomialRoll(str));
        
        //linear probing to find the appropriate location if the hashindex is not empty
        while(hash->Table[hashIndex]!=NULL){
            hashIndex++;
            hashIndex %= capacity;
        }

        if(hash->Table[hashIndex]==NULL){
            hash->size++;
            hash->Table[hashIndex] = str;
        }
    }else{
        printf("\nOut of space, hashing not done.");
    }

}

//function to return the hashindex of the given string, if not found returns -1
int search(char *str){
    if(hash->size>0){
        int hashIndex = hashCode(polynomialRoll(str));
        int num = hashIndex;
        while(1){
            if(hash->Table[hashIndex] == NULL){
                num++;
                num %= capacity;
            }else if(strcmp(hash->Table[num], str)){
                num++;
                num %= capacity;
            }else{
                break;
            }

            if(hashIndex==num)
                return -1;
        }
        return num;
    }else{
        return -1;
    }
}

//Function to delete a string (if present in the hashtable)
int dehash(char *str){
    if(hash->size>0){
        int hashIndex = search(str);
        if(hashIndex!=-1){
            char *temp = hash->Table[hashIndex];
            hash->Table[hashIndex] = NULL;
            hash->size--;
            free (temp);
        }
        return hashIndex;
    }else{
        return -1;
    }
}


//Function to print the hashtable
void display(){
    int i;
    printf("\nhashIndex\tString");
    printf("\n=================================");
    for(i=0; i<capacity; i++){
        if(hash->Table[i]!=NULL){
            printf("\n\t%d\t%s", i, hash->Table[i]);
        }
    }
}

//Function to get string from the user
void getstr(char *str){
    int i,c;
    for(i=0; (i<strsize) && ((c = getchar()) != '\n'); i++)
        str[i]=c;

    str[i] ='\0';
}

//Function to intiate the hash
void createHash(){
    hash = (Hash *) malloc(sizeof(Hash));
    int i;
    for(i=0; i<capacity; i++){
        hash->Table[i] = NULL;
    }
    hash->size = 0;
}

//Driver function
int main(){
    createHash();
    int ch,num;
    char *temp;
    do{
        printf("\n\n1.INSERT \n2.DELETE \n3.SEARCH \n4. DISPLAY TABLE \n0. EXIT");
        printf("\nEnter your choice(0-4): ");
        scanf("%d", &ch);
        getchar();

        if(ch==0)
            break;
        
        switch (ch)
        {
        case 1:
            printf("Enter the string you want to enter : ");
            temp = (char *) malloc(strsize * sizeof(char));
            getstr(temp);
            insert(temp);
            break;
        
        case 2:
            printf("Enter the string you want to delete : ");
            temp = (char *) malloc(strsize * sizeof(char));
            getstr(temp);
            num = dehash(temp);
            if(num==-1){
                printf("%s Was not found, not deleted.", temp);
            }else{
                printf("%s was found at hashIndex = %d. String deleted.", temp, num);
            }
            free(temp);
            break;

        case 3:
            printf("Enter the string you want to search its existence : ");
            temp = (char *) malloc(strsize * sizeof(char));
            getstr(temp);
            num = search(temp);
            if(num==-1){
                printf("%s Was not found", temp);
            }else{
                printf("%s was found at hashIndex = %d.", temp, num);
            }
            break;

        case 4:
            display();
            break;
        default:
            break;
        }


    }while(ch>=0 && ch<=4);

    return 0;
}