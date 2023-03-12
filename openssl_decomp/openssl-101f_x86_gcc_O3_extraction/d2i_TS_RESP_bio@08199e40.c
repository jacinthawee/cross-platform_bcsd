
void d2i_TS_RESP_bio(BIO *param_1,void **param_2)

{
  ASN1_d2i_bio(TS_RESP_new,d2i_TS_RESP,param_1,param_2);
  return;
}

