
char * BUF_strndup(char *str,size_t siz)

{
  int iVar1;
  char *pcVar2;
  
  if ((str != (char *)0x0) && (siz < 0x7fffffff)) {
    iVar1 = (*(code *)PTR_CRYPTO_malloc_006a7008)(siz + 1,"buf_str.c",0x51);
    if (iVar1 == 0) {
      ERR_put_error(7,0x68,0x41,"buf_str.c",0x53);
      pcVar2 = (char *)0x0;
    }
    else {
      pcVar2 = (char *)(*(code *)PTR_memcpy_006a9aec)(iVar1,str,siz);
      pcVar2[siz] = '\0';
    }
    return pcVar2;
  }
  return (char *)0x0;
}

