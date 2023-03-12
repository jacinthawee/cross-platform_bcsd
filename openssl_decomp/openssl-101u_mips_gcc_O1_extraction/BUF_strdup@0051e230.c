
char * BUF_strdup(char *str)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  
  if (str == (char *)0x0) {
    return (char *)0x0;
  }
  uVar1 = (*(code *)PTR_strlen_006a9a24)();
  if (uVar1 < 0x7fffffff) {
    iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar1 + 1,"buf_str.c",0x51);
    if (iVar2 == 0) {
      ERR_put_error(7,0x68,0x41,"buf_str.c",0x53);
      pcVar3 = (char *)0x0;
    }
    else {
      pcVar3 = (char *)(*(code *)PTR_memcpy_006a9aec)(iVar2,str,uVar1);
      pcVar3[uVar1] = '\0';
    }
    return pcVar3;
  }
  return (char *)0x0;
}

