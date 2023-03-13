
void TS_STATUS_INFO_free(ASN1_VALUE *param_1)

{
  ASN1_item_free(param_1,(ASN1_ITEM *)TS_STATUS_INFO_it);
  return;
}

