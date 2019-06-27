#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <fcntl.h>
#define BUFSIZE 1024 //每次读取文件内容的长度

int fdin = -1, fdout = -1, int bytenum, writenum; //变量初始化

int Die(char* mess) //错误处理
{
	if(fdin > -1) close(fdin);
	if(fdout > -1) close(fdout);
	perror(mess);
	exit(1);
}

int main(int argc, char* argv[])
{
	char buf[BUFSIZE];
	if(argc < 3)
	{
		fprintf(stderr, "usage:copy source destination\n");
		exit;
	}
	fdout = open(argv[2], O_WRONLY|O_CREAT); //open是UNIX系统系统调用函数，打开文件，返回值：成功则返回文件描述符，否则返回-1
	if(fdout == -1) Die("out file");
	fdin = open(argv[1], O_RDONLY);
	if(fdin == -1) Die("in file");
	bytenum = 1;
	while(bytenum > 0) //拷贝文件
	{
		bytenum = read(fdin, buf, BUFSIZE);
		if(bytenum < 0) Die("read");
		writenum = write(fdout, buf, bytenum);
		if(writenum < 0) Die("write");
	}
	close(fdout); //关闭文件
	close(fdin);
	return 0;
}