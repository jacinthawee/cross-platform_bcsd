
/* WARNING: Removing unreachable block (ram,0x0813bac7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * ASN1_item_d2i_bio(ASN1_ITEM *it,BIO *in,void *x)

{
  int len;
  ASN1_VALUE *pAVar1;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  len = asn1_d2i_read_bio_constprop_0();
  if (len < 0) {
    pAVar1 = (ASN1_VALUE *)0x0;
  }
  else {
    local_14 = _DAT_00000004;
    pAVar1 = ASN1_item_d2i((ASN1_VALUE **)x,&local_14,len,it);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pAVar1;
}

