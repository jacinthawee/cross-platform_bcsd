
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CMS_ReceiptRequest * CMS_ReceiptRequest_new(void)

{
  CMS_ReceiptRequest *pCVar1;
  
  pCVar1 = (CMS_ReceiptRequest *)
           (*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_ReceiptRequest_it_006a93ec);
  return pCVar1;
}

