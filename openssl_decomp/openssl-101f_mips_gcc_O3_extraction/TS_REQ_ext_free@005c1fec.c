
void TS_REQ_ext_free(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != 0) {
    (*(code *)PTR_sk_pop_free_006a8158)
              (*(undefined4 *)(param_1 + 0x14),PTR_X509_EXTENSION_free_006a8268,param_3,param_4,&_gp
              );
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}

