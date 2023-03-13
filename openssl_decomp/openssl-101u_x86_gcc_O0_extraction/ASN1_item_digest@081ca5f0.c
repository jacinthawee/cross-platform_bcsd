
int ASN1_item_digest(ASN1_ITEM *it,EVP_MD *type,void *data,uchar *md,uint *len)

{
  size_t count;
  int iVar1;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (uchar *)0x0;
  count = ASN1_item_i2d((ASN1_VALUE *)data,&local_14,it);
  if (local_14 != (uchar *)0x0) {
    iVar1 = EVP_Digest(local_14,count,md,len,type,(ENGINE *)0x0);
    if (iVar1 != 0) {
      CRYPTO_free(local_14);
      iVar1 = 1;
      goto LAB_081ca64b;
    }
  }
  iVar1 = 0;
LAB_081ca64b:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

