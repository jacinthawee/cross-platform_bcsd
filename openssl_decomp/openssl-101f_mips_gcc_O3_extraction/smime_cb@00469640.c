
int smime_cb(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = &_gp;
  iVar1 = (*(code *)PTR_X509_STORE_CTX_get_error_006a8314)(param_2);
  if ((iVar1 != 0x2b) && ((iVar1 != 0 || (param_1 != 2)))) {
    return param_1;
  }
  policies_print(0,param_2,param_3,param_4,puVar2);
  return param_1;
}

