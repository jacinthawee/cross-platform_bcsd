
void i2d_TS_TST_INFO_bio(BIO *param_1,uchar *param_2)

{
  ASN1_i2d_bio(i2d_TS_TST_INFO + 1,param_1,param_2);
  return;
}

