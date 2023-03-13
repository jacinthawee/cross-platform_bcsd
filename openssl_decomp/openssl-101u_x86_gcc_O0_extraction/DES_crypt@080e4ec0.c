
char * DES_crypt(char *buf,char *salt)

{
  char *pcVar1;
  
  pcVar1 = DES_fcrypt(buf,salt,buff_6367);
  return pcVar1;
}

