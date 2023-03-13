
void TS_MSG_IMPRINT_set_msg(int param_1,void *param_2,int param_3)

{
  ASN1_OCTET_STRING_set(*(ASN1_STRING **)(param_1 + 4),param_2,param_3);
  return;
}

