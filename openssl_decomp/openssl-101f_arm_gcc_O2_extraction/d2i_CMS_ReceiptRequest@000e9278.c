
CMS_ReceiptRequest * d2i_CMS_ReceiptRequest(CMS_ReceiptRequest **a,uchar **in,long len)

{
  ASN1_VALUE *pAVar1;
  
  pAVar1 = ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)CMS_ReceiptRequest_it);
  return (CMS_ReceiptRequest *)pAVar1;
}

