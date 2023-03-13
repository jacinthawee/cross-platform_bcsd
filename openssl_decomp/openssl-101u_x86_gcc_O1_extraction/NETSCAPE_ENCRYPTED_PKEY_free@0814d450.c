
void NETSCAPE_ENCRYPTED_PKEY_free(ASN1_VALUE *param_1)

{
  ASN1_item_free(param_1,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
  return;
}

