
BIO * BIO_new_mem_buf(void *buf,int len)

{
  size_t *psVar1;
  BIO *pBVar2;
  
  if (buf == (void *)0x0) {
    ERR_put_error(0x20,0x7e,0x73,"bss_mem.c",0x65);
    pBVar2 = (BIO *)0x0;
  }
  else {
    if (len < 0) {
      len = strlen((char *)buf);
    }
    pBVar2 = BIO_new((BIO_METHOD *)mem_method);
    if (pBVar2 == (BIO *)0x0) {
      pBVar2 = (BIO *)0x0;
    }
    else {
      psVar1 = (size_t *)pBVar2->ptr;
      psVar1[1] = (size_t)buf;
      *psVar1 = len;
      psVar1[2] = len;
      pBVar2->flags = pBVar2->flags | 0x200;
      pBVar2->num = 0;
    }
  }
  return pBVar2;
}

