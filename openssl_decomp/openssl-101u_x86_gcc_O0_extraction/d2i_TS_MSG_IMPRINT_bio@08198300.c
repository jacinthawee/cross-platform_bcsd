
void d2i_TS_MSG_IMPRINT_bio(BIO *param_1,void **param_2)

{
  ASN1_d2i_bio(TS_MSG_IMPRINT_new,d2i_TS_MSG_IMPRINT,param_1,param_2);
  return;
}

