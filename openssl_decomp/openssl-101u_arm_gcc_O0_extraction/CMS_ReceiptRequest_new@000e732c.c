
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CMS_ReceiptRequest * CMS_ReceiptRequest_new(void)

{
  ASN1_VALUE *pAVar1;
  
  pAVar1 = ASN1_item_new((ASN1_ITEM *)CMS_ReceiptRequest_it);
  return (CMS_ReceiptRequest *)pAVar1;
}

