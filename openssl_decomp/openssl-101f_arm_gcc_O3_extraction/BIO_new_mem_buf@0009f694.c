
BIO * BIO_new_mem_buf(void *buf,int len)

{
  BIO *pBVar1;
  size_t *psVar2;
  uint uVar3;
  
  if (buf == (void *)0x0) {
    ERR_put_error(0x20,0x7e,0x73,"bss_mem.c",100);
    pBVar1 = (BIO *)buf;
  }
  else {
    if (len < 0) {
      len = strlen((char *)buf);
    }
    pBVar1 = BIO_new((BIO_METHOD *)&mem_method);
    if (pBVar1 != (BIO *)0x0) {
      psVar2 = (size_t *)pBVar1->ptr;
      uVar3 = pBVar1->flags;
      psVar2[1] = (size_t)buf;
      *psVar2 = len;
      psVar2[2] = len;
      pBVar1->flags = uVar3 | 0x200;
      pBVar1->num = 0;
    }
  }
  return pBVar1;
}

