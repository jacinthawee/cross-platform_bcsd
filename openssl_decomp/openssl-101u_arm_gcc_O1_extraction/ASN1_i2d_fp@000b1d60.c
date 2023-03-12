
int ASN1_i2d_fp(undefined1 *i2d,FILE *out,void *x)

{
  BIO_METHOD *type;
  BIO *bp;
  int num;
  void *ptr;
  int iVar1;
  void *pvVar2;
  int iVar3;
  bool bVar4;
  void *local_1c;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x49);
    return 0;
  }
  BIO_ctrl(bp,0x6a,0,out);
  num = (*(code *)i2d)(x,0);
  ptr = CRYPTO_malloc(num,"a_i2d_fp.c",0x5a);
  if (ptr == (void *)0x0) {
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
  }
  else {
    local_1c = ptr;
    (*(code *)i2d)(x,&local_1c);
    iVar3 = 0;
    do {
      iVar1 = BIO_write(bp,(void *)((int)ptr + iVar3),num);
      bVar4 = num == iVar1;
      iVar3 = iVar3 + iVar1;
      num = num - iVar1;
      if (bVar4) {
        pvVar2 = (void *)0x1;
        goto LAB_000b1dc4;
      }
    } while (0 < iVar1);
    pvVar2 = (void *)0x0;
LAB_000b1dc4:
    CRYPTO_free(ptr);
    ptr = pvVar2;
  }
  BIO_free(bp);
  return (int)ptr;
}

