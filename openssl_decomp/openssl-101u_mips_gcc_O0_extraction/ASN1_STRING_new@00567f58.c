
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_STRING * ASN1_STRING_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = (ASN1_STRING *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x10,"asn1_lib.c",0x19c);
  if (pAVar1 == (ASN1_STRING *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x82,0x41,"asn1_lib.c",0x19e);
    pAVar1 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar1->length = 0;
    pAVar1->data = (uchar *)0x0;
    pAVar1->flags = 0;
    pAVar1->type = 4;
  }
  return pAVar1;
}

