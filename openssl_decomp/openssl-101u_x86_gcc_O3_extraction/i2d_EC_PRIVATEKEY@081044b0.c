
void i2d_EC_PRIVATEKEY(ASN1_VALUE *param_1,uchar **param_2)

{
  ASN1_item_i2d(param_1,param_2,(ASN1_ITEM *)EC_PRIVATEKEY_it);
  return;
}

