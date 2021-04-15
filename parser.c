#include "stdio.h"

enum Token{
    logic_keyword, define_keyword, proof_keyword, true_keyword, false_keyword, identifier
};

enum Boolean {
    true_boolean, false_boolean
};

int returnToken(char token[6]) {
    if(token[0] == 'l' && token[1] == 'o' && token[2] == 'g' && token[3] == 'i' && token[4] == 'c')
	return logic_keyword;
    else if(token[0] == 'd' && token[1] == 'e' && token[2] == 'f' && token[3] == 'i' && token[4] == 'n' && token[5] == 'e')
	return define_keyword;
    else if(token[0] == 'p' && token[1] == 'r' && token[2] == 'o' && token[3] == 'o' && token[4] == 'f')
	return proof_keyword;
    else if(token[0] == 't' && token[1] == 'r' && token[2] == 'u' && token[3] == 'e')
	return true_keyword;
    else if(token[0] == 'f' && token[1] == 'a' && token[2] == 'l' && token[3] == 's' && token[4] == 'e')
	return false_keyword;
    else
	return identifier;
}

int stack[10];
int top = 0;
int identifiers = 0;

int push(enum Boolean value) {
   stack[top] = value;
   top++;
}

enum Boolean pop() {
   enum Boolean value = stack[top--];
}

int runtime_declare(int identifier) {

}

int returnLogic() {
   char token[1024];
   char value[1024];
   char brace = 0;
   int closecount = 0;
   while(1){
      
       scanf("%s %s [^\{]%c", token, value, &brace);
       if(brace == '{')
           closecount = closecount + 1;
       else
	   closecount = closecount - 1;
       printf("read token%s value%s\n", token, value);
       if(returnToken(token) == logic_keyword && returnToken(value) == identifier)
           push(identifiers++);

   } 
}

int main() {
   printf("PING LANGUAGE nocode\n");
   printf("VADAPALLI KRISHNA SATYA\n");
   returnLogic();	   
}
