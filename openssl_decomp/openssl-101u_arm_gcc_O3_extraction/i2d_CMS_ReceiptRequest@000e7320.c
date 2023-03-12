
int i2d_CMS_ReceiptRequest(CMS_ReceiptRequest *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)CMS_ReceiptRequest_it);
  return iVar1;
}

