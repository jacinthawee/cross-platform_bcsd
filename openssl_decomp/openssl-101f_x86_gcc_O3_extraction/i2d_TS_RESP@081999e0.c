
void i2d_TS_RESP(ASN1_VALUE *param_1,uchar **param_2)

{
  ASN1_item_i2d(param_1,param_2,(ASN1_ITEM *)TS_RESP_it);
  return;
}

