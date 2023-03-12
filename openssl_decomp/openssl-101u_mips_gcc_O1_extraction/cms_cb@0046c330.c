
int cms_cb(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  puVar1 = &_gp;
  verify_err = (*(code *)PTR_X509_STORE_CTX_get_error_006a729c)(param_2);
  if ((verify_err != 0x2b) && ((verify_err != 0 || (param_1 != 2)))) {
    return param_1;
  }
  policies_print(0,param_2,param_3,param_4,puVar1);
  return param_1;
}

