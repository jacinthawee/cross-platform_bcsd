
size_t mem_write(BIO *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  BUF_MEM *str;
  size_t len;
  size_t sVar2;
  
  str = (BUF_MEM *)param_1->ptr;
  if (param_2 == (void *)0x0) {
    param_3 = 0xffffffff;
    ERR_put_error(0x20,0x75,0x73,"bss_mem.c",0xb3);
  }
  else if (param_1->flags << 0x16 < 0) {
    param_3 = 0xffffffff;
    ERR_put_error(0x20,0x75,0x7e,"bss_mem.c",0xb8);
  }
  else {
    BIO_clear_flags(param_1,0xf);
    sVar2 = str->length;
    len = sVar2 + param_3;
    sVar1 = BUF_MEM_grow_clean(str,len);
    if (len == sVar1) {
      memcpy(str->data + sVar2,param_2,param_3);
    }
    else {
      param_3 = 0xffffffff;
    }
  }
  return param_3;
}

