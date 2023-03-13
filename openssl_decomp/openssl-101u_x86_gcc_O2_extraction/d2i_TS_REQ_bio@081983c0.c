
void d2i_TS_REQ_bio(BIO *param_1,void **param_2)

{
  ASN1_d2i_bio(TS_REQ_new,d2i_TS_REQ,param_1,param_2);
  return;
}

