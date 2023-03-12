
size_t mem_puts(BIO *param_1,char *param_2)

{
  size_t __n;
  size_t sVar1;
  size_t len;
  BUF_MEM *str;
  size_t sVar2;
  
  __n = strlen(param_2);
  str = (BUF_MEM *)param_1->ptr;
  if (param_2 == (char *)0x0) {
    __n = 0xffffffff;
    ERR_put_error(0x20,0x75,0x73,"bss_mem.c",0xb2);
  }
  else if (param_1->flags << 0x16 < 0) {
    __n = 0xffffffff;
    ERR_put_error(0x20,0x75,0x7e,"bss_mem.c",0xb7);
  }
  else {
    BIO_clear_flags(param_1,0xf);
    sVar2 = str->length;
    len = __n + sVar2;
    sVar1 = BUF_MEM_grow_clean(str,len);
    if (len == sVar1) {
      memcpy(str->data + sVar2,param_2,__n);
    }
    else {
      __n = 0xffffffff;
    }
  }
  return __n;
}

