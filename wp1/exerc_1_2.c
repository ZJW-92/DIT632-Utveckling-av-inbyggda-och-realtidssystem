#include<stdio.h>
int wordcount(char *str);

int main () {
	int n;
	char str[100];
	printf("Enter a sentence: \n");

 // gets(str);
 fgets(str, (sizeof str / sizeof str [0]), stdin);

	n=wordcount(str);
  printf("there are %d words in the sentence.\n", n);
}


int wordcount(char *str) {
	int n =0;
	for(int i= 0; str[i]!= '\0'; i++) {
		if(str[i]!=' ' && (str[i+1]== ' ' || str[i+1]== '\0')) {
			n ++;
		}
	}
	return n;
}

/*#include<stdio.h>
int wordcount(char *s);
void input(char s[]){
	int i=0;
	for(int c;(c=getchar())!='\n';i++){
		s[i]=c;
	}
	s[i]='\0';//读取完成，记得对这个字符数组封口
}
char* findmax(char s[]){
	int max=0,word_length=0,p=0,i=0;//这个p是用来记录最长单词的位置
	for(i=0;s[i]!='\0';i++){
		if(s[i]==' '){//扫到空格，则结算是否为最长的单词
			if(max<word_length){
				max=word_length;
				p=i;
			}
			word_length=0;
		}
		else{//如果i扫到的不是空格，那么开始计算单词的长度
			word_length++;
		}
	}
	if(max<word_length){//此乃用于最长的单词在结尾的情况
		max=word_length;
		p=i;
	}
	static char longest_word[255];
	for(p=p-max,i=0;max>0;max--,p++,i++){
		longest_word[i]=s[p];
	}
	longest_word[i]='\0';
	return longest_word;
}

int main(){
	int n;
	char s[255];
	printf("Enter a String,please:\n");
	input(s);	
	
	char* longest_word=findmax(s);
	printf("The longest word is:%s\n",longest_word);
	// n=wordcount(s);
  // printf("there are %d words in the sentence.\n", n);
}
*/