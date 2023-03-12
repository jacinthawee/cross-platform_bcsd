
undefined4 crl_inf_cb(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (((*param_2 != 0) && (iVar1 = *(int *)(*param_2 + 0x14), iVar1 != 0)) && (param_1 == 5)) {
    (*(code *)PTR_sk_set_cmp_func_006a9090)(iVar1,X509_REVOKED_cmp,param_3,param_4,&_gp);
    return 1;
  }
  return 1;
}

