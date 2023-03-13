
void d2i_TS_TST_INFO_bio(BIO *param_1,void **param_2)

{
  ASN1_d2i_bio(TS_TST_INFO_new,d2i_TS_TST_INFO,param_1,param_2);
  return;
}

