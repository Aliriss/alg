typedef struct string{
	char *ch;
	int length;
}String;

void initString(String &Str,int size){//Init String with size space.
	Str.ch=(char*)malloc(size*sizeof(char));
	Str.length=size;
}
void addSpaceStr(String &str,int size){
	str.length=str.length+size-1;
	str.ch=(char*)realloc(str.ch,(str.length+size-1)*sizeof(char));
}
int strLength(char *str) {  
	char *p=str;
	int num=0;
	while(*p!='\0') {
		num++;
		p++;
	}
	return num;
}
void strAssign(String &str1,String str2) {    //Cover s1 with s2.
	if(str1.ch) {
		free(str1.ch);
	}
	str1.ch=(char*)malloc(str2.length*sizeof(char));
	char *p1=str1.ch,*p2=str2.ch;
	for(int i=1; i<=str2.length; i++) {        //Able to copy '\0'.
		*p1=*p2;
		p2++;p1++;     
	}
}
void strConcat(String &str1,String str2){  //s1=s1+s2
	addSpaceStr(str1,str2.length);
	char* p=str1.ch;
	while(*p!='\0'){    //P point str1's tail('\0').
		p++;
	}
	char* q=str2.ch;
	while(*q!='\0'){   //String concat.
		*p=*q;
		p++;q++;
	}
	*p=*q;  //String end with '\0'
}
String subStr(String str,int i,int length){  //Return subString, start at i position, length is length.
	String S;
	initString(S,length+1);
	for(i=i-1;i<length;i++){
		*(S.ch+i)=*(str.ch+i);
	}
	*(S.ch+length)='\0';
	return S;
}
bool strCmp(String str1,String str2){      //Compare str1 to str2.
	if(str1.length!=str2.length) return false;
	for(int i=0;i<str1.length;i++){
		if(*(str1.ch+i)!=*(str2.ch+i)) return false;
	}
	return true;
}
void strInsert(String &str1,int i,String str2){  //Insert str2 into i position of str1, if i position exit.
	if(i>str1.length)  printf("\nOut index.");
	String S1=subStr(str1,1,i);
	String S2=subStr(str1,i,str1.length-i+1);
	strAssign(str1,S1);
	strConcat(str1,str2);
	strConcat(str1,S2);
}
//int strIndex(String str1,String str2){   //return the position where str2 first appear in str1.
//	for(int i=0;i<str1.length;i++){
//		if(*(str1.ch+i)==*())
//	}
//}
