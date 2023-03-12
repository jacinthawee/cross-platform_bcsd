
void * ASN1_item_dup(ASN1_ITEM *it,void *x)

{
  int len;
  ASN1_VALUE *local_18;
  ASN1_VALUE *local_14;
  
  local_18 = (ASN1_VALUE *)0x0;
  if (x != (void *)0x0) {
    len = ASN1_item_i2d((ASN1_VALUE *)x,(uchar **)&local_18,it);
    x = local_18;
    if (local_18 == (ASN1_VALUE *)0x0) {
      ERR_put_error(0xd,0xbf,0x41,"a_dup.c",0x6e);
    }
    else {
      local_14 = local_18;
      x = ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)&local_14,len,it);
      CRYPTO_free(local_18);
    }
  }
  return x;
}

