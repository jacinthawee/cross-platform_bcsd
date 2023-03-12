
void ESS_ISSUER_SERIAL_free(ASN1_VALUE *param_1)

{
  ASN1_item_free(param_1,(ASN1_ITEM *)ESS_ISSUER_SERIAL_it);
  return;
}

