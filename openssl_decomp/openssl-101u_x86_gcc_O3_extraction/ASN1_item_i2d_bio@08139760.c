
int ASN1_item_i2d_bio(ASN1_ITEM *it,BIO *out,void *x)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (uchar *)0x0;
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)x,&local_14,it);
  if (local_14 == (uchar *)0x0) {
    ERR_put_error(0xd,0xc0,0x41,"a_i2d_fp.c",0x8c);
    iVar1 = 0;
  }
  else {
    iVar3 = 0;
    while( true ) {
      iVar2 = BIO_write(out,local_14 + iVar3,iVar1);
      if (iVar1 == iVar2) break;
      if (iVar2 < 1) {
        iVar1 = 0;
        goto LAB_081397cd;
      }
      iVar3 = iVar3 + iVar2;
      iVar1 = iVar1 - iVar2;
    }
    iVar1 = 1;
LAB_081397cd:
    CRYPTO_free(local_14);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

