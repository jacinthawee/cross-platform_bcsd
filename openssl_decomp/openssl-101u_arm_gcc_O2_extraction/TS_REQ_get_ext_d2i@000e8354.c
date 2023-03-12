
void TS_REQ_get_ext_d2i(int param_1,int param_2,int *param_3,int *param_4)

{
  X509V3_get_d2i(*(stack_st_X509_EXTENSION **)(param_1 + 0x14),param_2,param_3,param_4);
  return;
}

