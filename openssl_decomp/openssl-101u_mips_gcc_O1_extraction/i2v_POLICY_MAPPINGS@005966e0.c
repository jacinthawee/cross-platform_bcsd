
stack_st_CONF_VALUE *
i2v_POLICY_MAPPINGS(undefined4 param_1,undefined4 param_2,stack_st_CONF_VALUE *param_3)

{
  undefined *puVar1;
  int iVar2;
  stack_st_CONF_VALUE **ppsVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  undefined local_cc [88];
  char acStack_74 [80];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_cc._0_4_ = param_3;
  for (iVar8 = 0; iVar2 = (*(code *)PTR_sk_num_006a6e2c)(param_2), iVar8 < iVar2; iVar8 = iVar8 + 1)
  {
    puVar4 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(param_2,iVar8);
    (*(code *)PTR_i2t_ASN1_OBJECT_006a8c48)(local_cc + 8,0x50,*puVar4);
    (*(code *)PTR_i2t_ASN1_OBJECT_006a8c48)(acStack_74,0x50,puVar4[1]);
    param_3 = (stack_st_CONF_VALUE *)local_cc;
    X509V3_add_value(local_cc + 8,acStack_74,(stack_st_CONF_VALUE **)(stack_st_CONF_VALUE *)local_cc
                    );
  }
  if (local_24 == *(int *)puVar1) {
    return local_cc._0_4_;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppsVar3 = (stack_st_CONF_VALUE **)(*(code *)PTR_sk_new_null_006a6fa4)();
  if (ppsVar3 == (stack_st_CONF_VALUE **)0x0) {
    uVar7 = 0x7b;
LAB_00596a3c:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x91,0x41,"v3_pmaps.c",uVar7);
    return (stack_st_CONF_VALUE *)(stack_st_CONF_VALUE **)0x0;
  }
  iVar8 = 0;
  do {
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(param_3);
    if (iVar2 <= iVar8) {
      return (stack_st_CONF_VALUE *)ppsVar3;
    }
    puVar4 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(param_3,iVar8);
    if ((puVar4[2] == 0) || (puVar4[1] == 0)) {
      (*(code *)PTR_sk_pop_free_006a7058)(ppsVar3,POLICY_MAPPING_free);
      uVar7 = 0x84;
LAB_00596968:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x91,0x6e,"v3_pmaps.c",uVar7);
      (*(code *)PTR_ERR_add_error_data_006a813c)
                (6,"section:",*puVar4,",name:",puVar4[1],",value:",puVar4[2]);
      return (stack_st_CONF_VALUE *)(stack_st_CONF_VALUE **)0x0;
    }
    iVar2 = (*(code *)PTR_OBJ_txt2obj_006a7000)(puVar4[1],0);
    iVar5 = (*(code *)PTR_OBJ_txt2obj_006a7000)(puVar4[2],0);
    if ((iVar2 == 0) || (iVar5 == 0)) {
      (*(code *)PTR_sk_pop_free_006a7058)(ppsVar3,POLICY_MAPPING_free);
      uVar7 = 0x8d;
      goto LAB_00596968;
    }
    piVar6 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(POLICY_MAPPING_it);
    puVar1 = PTR_sk_push_006a6fa8;
    if (piVar6 == (int *)0x0) {
      (*(code *)PTR_sk_pop_free_006a7058)(ppsVar3,POLICY_MAPPING_free);
      uVar7 = 0x94;
      goto LAB_00596a3c;
    }
    *piVar6 = iVar2;
    piVar6[1] = iVar5;
    (*(code *)puVar1)(ppsVar3,piVar6);
    iVar8 = iVar8 + 1;
  } while( true );
}

