
void ESS_CERT_ID_free(ASN1_VALUE *param_1)

{
  ASN1_item_free(param_1,(ASN1_ITEM *)ESS_CERT_ID_it);
  return;
}

