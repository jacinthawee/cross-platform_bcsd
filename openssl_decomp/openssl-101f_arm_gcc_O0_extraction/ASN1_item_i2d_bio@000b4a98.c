
int ASN1_item_i2d_bio(ASN1_ITEM *it,BIO *out,void *x)

{
  int len;
  int iVar1;
  int iVar2;
  uchar *puVar3;
  bool bVar4;
  uchar *local_1c [2];
  
  iVar2 = 0;
  local_1c[0] = (uchar *)0x0;
  len = ASN1_item_i2d((ASN1_VALUE *)x,local_1c,it);
  puVar3 = local_1c[0];
  if (local_1c[0] == (uchar *)0x0) {
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
  }
  else {
    do {
      iVar1 = BIO_write(out,local_1c[0] + iVar2,len);
      bVar4 = iVar1 == len;
      iVar2 = iVar2 + iVar1;
      len = len - iVar1;
      if (bVar4) {
        puVar3 = (uchar *)0x1;
        goto LAB_000b4ad8;
      }
    } while (0 < iVar1);
    puVar3 = (uchar *)0x0;
LAB_000b4ad8:
    CRYPTO_free(local_1c[0]);
  }
  return (int)puVar3;
}

