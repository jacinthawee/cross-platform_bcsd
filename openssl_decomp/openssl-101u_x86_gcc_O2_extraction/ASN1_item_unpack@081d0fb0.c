
void * ASN1_item_unpack(ASN1_STRING *oct,ASN1_ITEM *it)

{
  ASN1_VALUE *pAVar1;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = oct->data;
  pAVar1 = ASN1_item_d2i((ASN1_VALUE **)0x0,&local_14,oct->length,it);
  if (pAVar1 == (ASN1_VALUE *)0x0) {
    ERR_put_error(0xd,199,0x6e,"asn_pack.c",0xcd);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

