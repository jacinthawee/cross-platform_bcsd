
void TS_REQ_get_ext_by_OBJ(int param_1,ASN1_OBJECT *param_2,int param_3)

{
  X509v3_get_ext_by_OBJ(*(stack_st_X509_EXTENSION **)(param_1 + 0x14),param_2,param_3);
  return;
}

