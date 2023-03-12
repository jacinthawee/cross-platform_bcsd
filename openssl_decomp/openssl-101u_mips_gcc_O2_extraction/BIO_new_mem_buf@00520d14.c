
BIO * BIO_new_mem_buf(void *buf,int len)

{
  BIO *pBVar1;
  uint uVar2;
  int *piVar3;
  
  if (buf == (void *)0x0) {
    ERR_put_error(0x20,0x7e,0x73,"bss_mem.c",0x65);
    pBVar1 = (BIO *)0x0;
  }
  else {
    if (len < 0) {
      len = (*(code *)PTR_strlen_006a9a24)();
    }
    pBVar1 = BIO_new((BIO_METHOD *)mem_method);
    if (pBVar1 == (BIO *)0x0) {
      pBVar1 = (BIO *)0x0;
    }
    else {
      uVar2 = pBVar1->flags;
      piVar3 = (int *)pBVar1->ptr;
      piVar3[1] = (int)buf;
      *piVar3 = len;
      piVar3[2] = len;
      pBVar1->flags = uVar2 | 0x200;
      pBVar1->num = 0;
    }
  }
  return pBVar1;
}
