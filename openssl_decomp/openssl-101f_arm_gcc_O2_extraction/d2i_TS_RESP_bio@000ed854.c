
void d2i_TS_RESP_bio(BIO *param_1,void **param_2)

{
  ASN1_d2i_bio(TS_RESP_new + 1,d2i_TS_RESP + 1,param_1,param_2);
  return;
}
