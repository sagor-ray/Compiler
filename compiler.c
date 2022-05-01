#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isKeyword(char buffer[]){
	char keywords[33][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while","main"};
	int i, flag = 0;

	for(i = 0; i < 33; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}

	return flag;
}

int main(){
	char ch, buffer[15], operators[] = "+-*/%=", brackets[] = "()[]{}";
	FILE *fp;
	int i,j=0;

	fp = fopen("program.txt","r");

	if(fp == NULL){
		printf("error while opening the file\n");
		exit(0);
	}

	while((ch = fgetc(fp)) != EOF){
   		for(i = 0; i < 6; ++i){
   			if(ch == operators[i])
   				printf("%c is operator\n", ch);

   				else if(ch == brackets[i])
   				printf("%c is bracket\n", ch);
   		}



   		if(isalnum(ch)){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0)){
   				buffer[j] = '\0';
   				int k=j;
   				int m,sign;

               j = 0;

   				if(isKeyword(buffer) == 1)
   					printf("%s is keyword\n", buffer);
   				else if(buffer[0]=='1' ||buffer[0]=='2'||buffer[0]=='3'||buffer[0]=='4'||buffer[0]=='5'||buffer[0]=='6'||buffer[0]=='7'||buffer[0]=='8'||buffer[0]=='9')
   					{
   					    for(m=0;m<k;m++)
                        if(buffer[m]=='1'||buffer[m]=='2'||buffer[m]=='3'||buffer[m]=='4'||buffer[m]=='5'||buffer[m]=='6'||buffer[m]=='7'||buffer[m]=='8'||buffer[m]=='9')
   					    {
   					        sign=1;
   					    }
   					    else {

                            sign=0;
                            break;
   					    }
   					}
   					if(sign==1)
                    {
                printf("%s is  a valid  indentifier\n", buffer);
                    }
   					else
                        {
   					printf("%s is not valid  indentifier\n", buffer);
   					}
   		}

	}

	fclose(fp);

	return 0;
}
