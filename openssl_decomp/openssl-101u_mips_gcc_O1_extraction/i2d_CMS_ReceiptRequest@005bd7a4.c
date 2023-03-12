
int i2d_CMS_ReceiptRequest(CMS_ReceiptRequest *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005bd7b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(a,out,PTR_CMS_ReceiptRequest_it_006a93ec);
  return iVar1;
}

