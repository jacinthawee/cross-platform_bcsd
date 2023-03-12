
int mem_puts(BIO *param_1,undefined4 param_2)

{
  int iVar1;
  size_t sVar2;
  size_t len;
  BUF_MEM *str;
  size_t sVar3;
  
  iVar1 = (*(code *)PTR_strlen_006a9a24)(param_2);
  str = (BUF_MEM *)param_1->ptr;
  if ((param_1->flags & 0x200U) == 0) {
    BIO_clear_flags(param_1,0xf);
    sVar3 = str->length;
    len = sVar3 + iVar1;
    sVar2 = BUF_MEM_grow_clean(str,len);
    if (len != sVar2) {
      return -1;
    }
    (*(code *)PTR_memcpy_006a9aec)(str->data + sVar3,param_2,iVar1);
  }
  else {
    iVar1 = -1;
    ERR_put_error(0x20,0x75,0x7e,"bss_mem.c",0xb8);
  }
  return iVar1;
}

