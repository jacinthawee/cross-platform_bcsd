
char * DES_crypt(char *buf,char *salt)

{
  char *pcVar1;
  
  pcVar1 = DES_fcrypt(buf,salt,&buff_8906);
  return pcVar1;
}

