
int ASN1_item_i2d_fp(ASN1_ITEM *it,FILE *out,void *x)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    iVar1 = 0;
    ERR_put_error(0xd,0xc1,7,"a_i2d_fp.c",0x7f);
  }
  else {
    BIO_ctrl(bp,0x6a,0,out);
    local_24 = (uchar *)0x0;
    iVar1 = ASN1_item_i2d((ASN1_VALUE *)x,&local_24,it);
    if (local_24 == (uchar *)0x0) {
      iVar1 = 0;
      ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x91);
    }
    else {
      iVar3 = 0;
      while( true ) {
        iVar2 = BIO_write(bp,local_24 + iVar3,iVar1);
        if (iVar1 == iVar2) break;
        if (iVar2 < 1) {
          iVar1 = 0;
          goto LAB_0813be8d;
        }
        iVar3 = iVar3 + iVar2;
        iVar1 = iVar1 - iVar2;
      }
      iVar1 = 1;
LAB_0813be8d:
      CRYPTO_free(local_24);
    }
    BIO_free(bp);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

