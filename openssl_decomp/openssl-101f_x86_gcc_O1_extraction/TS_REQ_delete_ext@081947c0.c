
void TS_REQ_delete_ext(int param_1,int param_2)

{
  X509v3_delete_ext(*(stack_st_X509_EXTENSION **)(param_1 + 0x14),param_2);
  return;
}

