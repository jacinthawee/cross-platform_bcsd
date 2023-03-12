
int ASN1_item_i2d_fp(ASN1_ITEM *it,FILE *out,void *x)

{
  BIO_METHOD *type;
  BIO *bp;
  int len;
  int iVar1;
  int iVar2;
  uchar *puVar3;
  bool bVar4;
  uchar *local_1c [2];
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7b);
    return 0;
  }
  iVar2 = 0;
  BIO_ctrl(bp,0x6a,0,out);
  local_1c[0] = (uchar *)0x0;
  len = ASN1_item_i2d((ASN1_VALUE *)x,local_1c,it);
  puVar3 = local_1c[0];
  if (local_1c[0] == (uchar *)0x0) {
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
  }
  else {
    do {
      iVar1 = BIO_write(bp,local_1c[0] + iVar2,len);
      bVar4 = len == iVar1;
      iVar2 = iVar2 + iVar1;
      len = len - iVar1;
      if (bVar4) {
        puVar3 = (uchar *)0x1;
        goto LAB_000b1eee;
      }
    } while (0 < iVar1);
    puVar3 = (uchar *)0x0;
LAB_000b1eee:
    CRYPTO_free(local_1c[0]);
  }
  BIO_free(bp);
  return (int)puVar3;
}

