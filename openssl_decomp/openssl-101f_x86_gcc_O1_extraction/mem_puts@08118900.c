
size_t mem_puts(BIO *param_1,char *param_2)

{
  size_t len;
  BUF_MEM *str;
  size_t sVar1;
  size_t __n;
  size_t sVar2;
  
  __n = strlen(param_2);
  str = (BUF_MEM *)param_1->ptr;
  if ((*(byte *)((int)&param_1->flags + 1) & 2) == 0) {
    BIO_clear_flags(param_1,0xf);
    sVar1 = str->length;
    len = sVar1 + __n;
    sVar2 = BUF_MEM_grow_clean(str,len);
    if (len != sVar2) {
      return 0xffffffff;
    }
    memcpy(str->data + sVar1,param_2,__n);
  }
  else {
    __n = 0xffffffff;
    ERR_put_error(0x20,0x75,0x7e,"bss_mem.c",0xb7);
  }
  return __n;
}

