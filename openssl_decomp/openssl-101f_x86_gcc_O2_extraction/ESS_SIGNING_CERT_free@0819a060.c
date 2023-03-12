
void ESS_SIGNING_CERT_free(ASN1_VALUE *param_1)

{
  ASN1_item_free(param_1,(ASN1_ITEM *)ESS_SIGNING_CERT_it);
  return;
}

