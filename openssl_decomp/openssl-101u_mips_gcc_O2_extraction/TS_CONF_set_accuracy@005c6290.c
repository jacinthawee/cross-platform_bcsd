
bool TS_CONF_set_accuracy(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_30;
  
  iVar1 = (*(code *)PTR_NCONF_get_string_006a6ea8)(param_1,param_2,"accuracy");
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_X509V3_parse_list_006a7b48)(iVar1);
    if (iVar1 == 0) {
LAB_005c649c:
      bVar5 = false;
      (*(code *)PTR___fprintf_chk_006a9980)
                (*(undefined4 *)PTR_stderr_006a9af8,1,"invalid variable value for %s::%s\n",param_2,
                 "accuracy");
      goto LAB_005c63d0;
    }
  }
  iVar4 = 0;
  local_30 = 0;
  iVar2 = (*(code *)PTR_sk_num_006a6e2c)(iVar1);
  uVar8 = 0;
  uVar7 = 0;
  if (0 < iVar2) {
    do {
      iVar2 = (*(code *)PTR_sk_value_006a6e24)(iVar1,iVar4);
      uVar6 = *(undefined4 *)(iVar2 + 4);
      iVar3 = (*(code *)PTR_strcmp_006a9b18)(uVar6,&DAT_00673074);
      if (iVar3 == 0) {
        if (*(int *)(iVar2 + 8) != 0) {
          uVar7 = (*(code *)PTR_strtol_006a9958)(*(int *)(iVar2 + 8),0,10);
        }
      }
      else {
        iVar3 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"millisecs");
        if (iVar3 == 0) {
          if (*(int *)(iVar2 + 8) != 0) {
            uVar8 = (*(code *)PTR_strtol_006a9958)(*(int *)(iVar2 + 8),0,10);
          }
        }
        else {
          iVar3 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"microsecs");
          if (iVar3 != 0) goto LAB_005c649c;
          if (*(int *)(iVar2 + 8) != 0) {
            local_30 = (*(code *)PTR_strtol_006a9958)(*(int *)(iVar2 + 8),0,10);
          }
        }
      }
      iVar4 = iVar4 + 1;
      iVar2 = (*(code *)PTR_sk_num_006a6e2c)(iVar1);
    } while (iVar4 < iVar2);
  }
  iVar2 = TS_RESP_CTX_set_accuracy(param_3,uVar7,uVar8,local_30);
  bVar5 = iVar2 != 0;
LAB_005c63d0:
  (*(code *)PTR_sk_pop_free_006a7058)(iVar1,PTR_X509V3_conf_free_006a7b4c);
  return bVar5;
}

