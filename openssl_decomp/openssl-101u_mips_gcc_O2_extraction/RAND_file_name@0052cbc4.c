
char * RAND_file_name(char *file,size_t num)

{
  int iVar1;
  char *src;
  size_t sVar2;
  
  iVar1 = (*(code *)PTR_OPENSSL_issetugid_006a8914)();
  if ((iVar1 == 0) && (src = (char *)(*(code *)PTR_getenv_006a9a60)("RANDFILE"), src != (char *)0x0)
     ) {
    if ((*src != '\0') && (iVar1 = (*(code *)PTR_strlen_006a9a24)(src), iVar1 + 1U < num)) {
      sVar2 = BUF_strlcpy(file,src,num);
      if (num <= sVar2) {
        file = (char *)0x0;
      }
      return file;
    }
    iVar1 = (*(code *)PTR_OPENSSL_issetugid_006a8914)();
    if (iVar1 == 0) goto LAB_0052cc10;
  }
  else {
    iVar1 = (*(code *)PTR_OPENSSL_issetugid_006a8914)();
    if (iVar1 != 0) goto LAB_0052cc2c;
LAB_0052cc10:
    src = (char *)(*(code *)PTR_getenv_006a9a60)(&DAT_00667da8);
    if (src == (char *)0x0) goto LAB_0052cc2c;
  }
  if ((*src != '\0') && (iVar1 = (*(code *)PTR_strlen_006a9a24)(src), iVar1 + 6U < num)) {
    BUF_strlcpy(file,src,num);
    BUF_strlcat(file,"/",num);
    BUF_strlcat(file,".rnd",num);
    return file;
  }
LAB_0052cc2c:
  *file = '\0';
  return file;
}

