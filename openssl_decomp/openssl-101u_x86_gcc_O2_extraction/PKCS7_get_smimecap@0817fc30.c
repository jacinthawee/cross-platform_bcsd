
stack_st_X509_ALGOR * PKCS7_get_smimecap(PKCS7_SIGNER_INFO *si)

{
  ASN1_TYPE *pAVar1;
  stack_st_X509_ALGOR *psVar2;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  pAVar1 = PKCS7_get_signed_attribute(si,0xa7);
  if (pAVar1 == (ASN1_TYPE *)0x0) {
    psVar2 = (stack_st_X509_ALGOR *)0x0;
  }
  else {
    psVar2 = (stack_st_X509_ALGOR *)0x0;
    if (pAVar1->type == 0x10) {
      local_14 = ((pAVar1->value).asn1_string)->data;
      psVar2 = (stack_st_X509_ALGOR *)
               ASN1_item_d2i((ASN1_VALUE **)0x0,&local_14,((pAVar1->value).asn1_string)->length,
                             (ASN1_ITEM *)X509_ALGORS_it);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return psVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

