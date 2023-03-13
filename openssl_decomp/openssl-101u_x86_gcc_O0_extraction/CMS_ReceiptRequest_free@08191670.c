
void CMS_ReceiptRequest_free(CMS_ReceiptRequest *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)CMS_ReceiptRequest_it);
  return;
}

