
size_t mem_write(BIO *param_1,void *param_2,size_t param_3)

{
  size_t len;
  BUF_MEM *str;
  size_t sVar1;
  size_t sVar2;
  int reason;
  int line;
  
  str = (BUF_MEM *)param_1->ptr;
  if (param_2 == (void *)0x0) {
    line = 0xb2;
    reason = 0x73;
  }
  else {
    if ((*(byte *)((int)&param_1->flags + 1) & 2) == 0) {
      BIO_clear_flags(param_1,0xf);
      sVar1 = str->length;
      len = sVar1 + param_3;
      sVar2 = BUF_MEM_grow_clean(str,len);
      if (len == sVar2) {
        memcpy(str->data + sVar1,param_2,param_3);
        return param_3;
      }
      return 0xffffffff;
    }
    line = 0xb7;
    reason = 0x7e;
  }
  ERR_put_error(0x20,0x75,reason,"bss_mem.c",line);
  return 0xffffffff;
}

