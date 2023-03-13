
char * RAND_file_name(char *file,size_t num)

{
  char *pcVar1;
  int iVar2;
  char *__s;
  size_t sVar3;
  
  pcVar1 = (char *)OPENSSL_issetugid();
  if ((pcVar1 == (char *)0x0) && (__s = getenv("RANDFILE"), __s != (char *)0x0)) {
    if ((*__s != '\0') && (sVar3 = strlen(__s), sVar3 + 1 < num)) {
      sVar3 = BUF_strlcpy(file,__s,num);
      if (sVar3 < num) {
        pcVar1 = file;
      }
      return pcVar1;
    }
    iVar2 = OPENSSL_issetugid();
    if (iVar2 == 0) goto LAB_08120961;
  }
  else {
    iVar2 = OPENSSL_issetugid();
    if (iVar2 != 0) goto LAB_08120977;
LAB_08120961:
    __s = getenv("HOME");
    if (__s == (char *)0x0) goto LAB_08120977;
  }
  if ((*__s != '\0') && (sVar3 = strlen(__s), sVar3 + 6 < num)) {
    BUF_strlcpy(file,__s,num);
    BUF_strlcat(file,"/",num);
    BUF_strlcat(file,".rnd",num);
    return file;
  }
LAB_08120977:
  *file = '\0';
  return file;
}

