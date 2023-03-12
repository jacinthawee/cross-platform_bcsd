
void i2d_NETSCAPE_ENCRYPTED_PKEY(ASN1_VALUE *param_1,uchar **param_2)

{
  ASN1_item_i2d(param_1,param_2,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
  return;
}

