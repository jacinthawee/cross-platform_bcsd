
void TS_RESP_set_tst_info(int param_1,undefined4 param_2,undefined4 param_3)

{
  PKCS7_free(*(PKCS7 **)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = param_2;
  TS_TST_INFO_free(*(undefined4 *)(param_1 + 8));
  *(undefined4 *)(param_1 + 8) = param_3;
  return;
}

