
int PEM_def_callback(char *buf,int num,int w,void *key)

{
  size_t sVar1;
  char *prompt;
  size_t __n;
  int iVar2;
  
  if (key == (void *)0x0) {
    prompt = EVP_get_pw_prompt();
    if (prompt == (char *)0x0) {
      prompt = "Enter PEM pass phrase:";
    }
    while( true ) {
      iVar2 = EVP_read_pw_string_min(buf,4,num,prompt,w);
      if (iVar2 != 0) {
        ERR_put_error(9,100,0x6d,"pem_lib.c",0x6f);
        memset(buf,0,num);
        return -1;
      }
      __n = strlen(buf);
      if (3 < (int)__n) break;
      __fprintf_chk(stderr,1,"phrase is too short, needs to be at least %d chars\n",4);
    }
  }
  else {
    sVar1 = strlen((char *)key);
    __n = num;
    if ((int)sVar1 <= num) {
      __n = sVar1;
    }
    memcpy(buf,key,__n);
  }
  return __n;
}

