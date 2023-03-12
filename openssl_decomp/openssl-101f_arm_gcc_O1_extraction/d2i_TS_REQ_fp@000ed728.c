
void d2i_TS_REQ_fp(FILE *param_1,void **param_2)

{
  ASN1_d2i_fp(TS_REQ_new + 1,d2i_TS_REQ + 1,param_1,param_2);
  return;
}

