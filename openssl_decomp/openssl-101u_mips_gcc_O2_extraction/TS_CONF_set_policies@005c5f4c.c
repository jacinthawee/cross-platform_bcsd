
undefined4 TS_CONF_set_policies(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = (*(code *)PTR_NCONF_get_string_006a6ea8)(param_1,param_2,"other_policies");
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_X509V3_parse_list_006a7b48)(iVar1);
    if (iVar1 == 0) {
LAB_005c6060:
      uVar5 = 0;
      (*(code *)PTR___fprintf_chk_006a9980)
                (*(undefined4 *)PTR_stderr_006a9af8,1,"invalid variable value for %s::%s\n",param_2,
                 "other_policies");
      goto LAB_005c6090;
    }
  }
  iVar4 = 0;
  while( true ) {
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(iVar1);
    if (iVar3 <= iVar4) break;
    iVar3 = (*(code *)PTR_sk_value_006a6e24)(iVar1,iVar4);
    if (*(int *)(iVar3 + 8) == 0) {
      iVar3 = (*(code *)PTR_OBJ_txt2obj_006a7000)(*(undefined4 *)(iVar3 + 4));
    }
    else {
      iVar3 = (*(code *)PTR_OBJ_txt2obj_006a7000)(*(int *)(iVar3 + 8),0);
    }
    if (iVar3 == 0) goto LAB_005c6060;
    iVar2 = TS_RESP_CTX_add_policy(param_3,iVar3);
    if (iVar2 == 0) {
      uVar5 = 0;
      goto LAB_005c6090;
    }
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iVar3);
    iVar4 = iVar4 + 1;
  }
  uVar5 = 1;
LAB_005c6090:
  (*(code *)PTR_sk_pop_free_006a7058)(iVar1,PTR_X509V3_conf_free_006a7b4c);
  return uVar5;
}

