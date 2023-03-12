
char * RAND_file_name(char *file,size_t num)

{
  int iVar1;
  char *src;
  size_t sVar2;
  
  iVar1 = (*(code *)PTR_OPENSSL_issetugid_006a9a34)();
  if ((iVar1 == 0) && (src = (char *)(*(code *)PTR_getenv_006aab6c)("RANDFILE"), src != (char *)0x0)
     ) {
    if ((*src != '\0') && (iVar1 = (*(code *)PTR_strlen_006aab30)(src), iVar1 + 1U < num)) {
      sVar2 = BUF_strlcpy(file,src,num);
      if (num <= sVar2) {
        file = (char *)0x0;
      }
      return file;
    }
    iVar1 = (*(code *)PTR_OPENSSL_issetugid_006a9a34)();
    if (iVar1 == 0) goto LAB_0052ff6c;
  }
  else {
    iVar1 = (*(code *)PTR_OPENSSL_issetugid_006a9a34)();
    if (iVar1 != 0) goto LAB_0052ff88;
LAB_0052ff6c:
    src = (char *)(*(code *)PTR_getenv_006aab6c)(&DAT_00668868);
    if (src == (char *)0x0) goto LAB_0052ff88;
  }
  if ((*src != '\0') && (iVar1 = (*(code *)PTR_strlen_006aab30)(src), iVar1 + 6U < num)) {
    BUF_strlcpy(file,src,num);
    BUF_strlcat(file,"/",num);
    BUF_strlcat(file,".rnd",num);
    return file;
  }
LAB_0052ff88:
  *file = '\0';
  return file;
}

