
bool TS_CONF_set_def_policy(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (param_3 == 0) {
    param_3 = (*(code *)PTR_NCONF_get_string_006a6ea8)(param_1,param_2,"default_policy");
    if (param_3 == 0) {
      bVar3 = false;
      iVar1 = 0;
      (*(code *)PTR___fprintf_chk_006a9980)
                (*(undefined4 *)PTR_stderr_006a9af8,1,"variable lookup failed for %s::%s\n",param_2,
                 "default_policy");
      goto LAB_005c5e98;
    }
  }
  iVar1 = (*(code *)PTR_OBJ_txt2obj_006a7000)(param_3,0);
  if (iVar1 == 0) {
    bVar3 = false;
    (*(code *)PTR___fprintf_chk_006a9980)
              (*(undefined4 *)PTR_stderr_006a9af8,1,"invalid variable value for %s::%s\n",param_2,
               "default_policy");
  }
  else {
    iVar2 = TS_RESP_CTX_set_def_policy(param_4,iVar1);
    bVar3 = iVar2 != 0;
  }
LAB_005c5e98:
  (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iVar1);
  return bVar3;
}

