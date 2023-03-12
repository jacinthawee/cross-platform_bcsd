
int mem_write(BIO *param_1,int param_2,int param_3)

{
  size_t sVar1;
  int line;
  int reason;
  BUF_MEM *str;
  size_t len;
  size_t sVar2;
  
  str = (BUF_MEM *)param_1->ptr;
  if (param_2 == 0) {
    reason = 0x73;
    line = 0xb2;
  }
  else {
    if ((param_1->flags & 0x200U) == 0) {
      BIO_clear_flags(param_1,0xf);
      sVar2 = str->length;
      len = sVar2 + param_3;
      sVar1 = BUF_MEM_grow_clean(str,len);
      if (len == sVar1) {
        (*(code *)PTR_memcpy_006aabf4)(str->data + sVar2,param_2,param_3);
        return param_3;
      }
      return -1;
    }
    reason = 0x7e;
    line = 0xb7;
  }
  ERR_put_error(0x20,0x75,reason,"bss_mem.c",line);
  return -1;
}

