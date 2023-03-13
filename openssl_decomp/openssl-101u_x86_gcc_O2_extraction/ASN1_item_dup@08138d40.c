
void * ASN1_item_dup(ASN1_ITEM *it,void *x)

{
  int len;
  ASN1_VALUE *pAVar1;
  int in_GS_OFFSET;
  uchar *local_18;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_18 = (uchar *)0x0;
  if (x == (void *)0x0) {
    pAVar1 = (ASN1_VALUE *)0x0;
  }
  else {
    len = ASN1_item_i2d((ASN1_VALUE *)x,&local_18,it);
    if (local_18 == (uchar *)0x0) {
      ERR_put_error(0xd,0xbf,0x41,"a_dup.c",0x6e);
      pAVar1 = (ASN1_VALUE *)0x0;
    }
    else {
      local_14 = local_18;
      pAVar1 = ASN1_item_d2i((ASN1_VALUE **)0x0,&local_14,len,it);
      CRYPTO_free(local_18);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

