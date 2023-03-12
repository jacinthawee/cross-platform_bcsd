
bool TS_CONF_set_certs(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (param_3 == 0) {
    param_3 = (*(code *)PTR_NCONF_get_string_006a6ea8)(param_1,param_2,"certs");
    if (param_3 == 0) {
      iVar1 = 0;
      bVar3 = true;
      goto LAB_005c5c80;
    }
  }
  iVar1 = TS_CONF_load_certs(param_3);
  if (iVar1 == 0) {
    bVar3 = false;
  }
  else {
    iVar2 = TS_RESP_CTX_set_certs(param_4,iVar1);
    bVar3 = iVar2 != 0;
  }
LAB_005c5c80:
  (*(code *)PTR_sk_pop_free_006a7058)(iVar1,PTR_X509_free_006a6e90);
  return bVar3;
}

