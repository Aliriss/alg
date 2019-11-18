
//字符串结构体，包含字符串指针和字符串内存的长度 
typedef struct string{
	char *ch;   //字符串指针 
	int length;  //字符串内存的长度，包含字符串结束的长度 
}String;

//初始化字符串，即给字符串分配内存 
void initString(String &Str,int size){//Init String with size space.
	Str.ch=(char*)malloc(size*sizeof(char));
	Str.length=size;
}
//扩展字符串的内存 
void addSpaceStr(String &str,int size){
	str.length=str.length+size-1;
	str.ch=(char*)realloc(str.ch,(str.length+size-1)*sizeof(char));
}
//返回字符串常量的长度，不包含结束标记的长度 
int strLength(char *str) {  
	char *p=str;
	int num=0;
	while(*p!='\0') {
		num++;
		p++;
	}
	return num;
}
//创建一个字符串。 
void createString(String &str1,char* str2){
	int length = strLength(str2);
	initString(str1,length+1);
	for(int i=0;i<length;i++){
		str1.ch[i]=str2[i];
	}
	str1.ch[length]='\0';
}
//用str2覆盖str1 
void strAssign(String &str1,String str2) {    //Cover s1 with s2.
	//首先需要释放str1的内存，然后将str2复制到str1中 
	if(str1.ch) {  
		free(str1.ch);
	}
	createString(str1,str2.ch);
}
//将str2接到str1的末尾 
void strConcat(String &str1,String str2){  //s1=s1+s2
	addSpaceStr(str1,str2.length);  //扩展str1的空间 
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
//返回子串 
String subStr(String str,int i,int length){  //Return subString, start at i position, length is length.
	//length是子串的长度 
	String S;       //定义一个字符串 用来保存子串 
	initString(S,length+1); //初始化该字符串 
	int j=0;
	for(j=0,i=i-1;j<length;i++,j++){   //使用j表示S的下标，用i表示str的下标 
	//当子串的长度达到要求（即length长）时，结束循环 
		*(S.ch+j)=*(str.ch+i);  
	}
	*(S.ch+length)='\0';     //结束符号 
	return S;  //返回该子串 
}
//字符串比较 
bool strCmp(String str1,String str2){      //Compare str1 to str2.
	if(str1.length!=str2.length) return false;
	for(int i=0;i<str1.length;i++){
		if(*(str1.ch+i)!=*(str2.ch+i)) return false;
	}
	return true;
}
//按位置插入字符串 
void strInsert(String &str1,int i,String str2){  //Insert str2 into position i of str1, if i position exit.
	if(i>str1.length-1)  printf("\nOut index!");  //下标越界  
	else if(i<1)         printf("\nOut index!");
	else{
		String S1=subStr(str1,1,i-1);       //S1用来存储i位置之前的子串 
		String S2=subStr(str1,i,str1.length-i);   //s2用来存储i位置及之后的子串 
		strAssign(str1,S1);      //用S1覆盖原字符串 
		strConcat(str1,str2);   //将要插入的字符串接到该字符串 
		strConcat(str1,S2);    //将源字符串i位置之后的字符串接到该字符串 
	}
}
//删除某一位开始的长度为length的子串 
void strDelete(String &str, int i, int length){  //删除串中第i个位置上长度为length的子串 
	//方法是：将后面的字符串接到第i个位置上，实现删除。
	if(i>str.length-1) printf("\nOut index!");
	else if(i<1)       printf("\nOut index!");
	else{
		String S1 = subStr(str,1,i-1);//记录第i个位置之前的子串 
		String S2 = subStr(str,i+length,str.length-length-1);//记录第i+length位置上的子串 
		strAssign(str,S1);  //用S1覆盖源字符串
		strConcat(str,S2);  //将S2接到该字符串中来，实现删除元素 
	}
}

//查找子串首次出现的位置 
int strIndex(String str1,String str2){   //return the position where str2 first appear in str1.
	//查找串2首次出现在字符串1中的位置 
	//非kmp算法，需要改进 
	for(int i=0;i<str1.length-str2.length;i++){
		int index=i;
		int j=0;
		for(j=0;j<str2.length-1;i++,j++){
			if(str1.ch[i]!=str2.ch[j]){
				break;
			}
		}
		if(j==str2.length-1){  //找到返回串2在串1中的位置 
			return index+1;
		}else{
			i=index; 
		}
	}
	return -1;  //如果串2不在串1中就返回-1 
}
//子串替换 
void strRep(String &str1,String str2,String str3){
	if(!str2.ch)  printf("\nStr2 is empty.");
	else{
		int index = strIndex(str1,str2);  //找到串2在串1中的首位置 
		while(index!=-1){     //如果串1中不包含串2，则退出
			String S1 = subStr(str1,1,index);
			String S2 = subStr(str1,index+str2.length,str1.length-str2.length);
			strAssign(str1,S1);
			strConcat(str1,str3);
			strConcat(str1,S2);
			index = strIndex(str1,str2);   //重新查找串2在串1中的位置 
		}
		
	}
} 