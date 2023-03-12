
int v2i_POLICY_MAPPINGS(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar2 = (*(code *)PTR_sk_new_null_006a80a4)();
  if (iVar2 == 0) {
    uVar7 = 0x7c;
LAB_0059978c:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x91,0x41,"v3_pmaps.c",uVar7);
    return 0;
  }
  iVar8 = 0;
  do {
    iVar6 = (*(code *)PTR_sk_num_006a7f2c)(param_3);
    if (iVar6 <= iVar8) {
      return iVar2;
    }
    puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(param_3,iVar8);
    if ((puVar3[2] == 0) || (puVar3[1] == 0)) {
      (*(code *)PTR_sk_pop_free_006a8158)(iVar2,POLICY_MAPPING_free);
      uVar7 = 0x84;
LAB_005996b8:
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x91,0x6e,"v3_pmaps.c",uVar7);
      (*(code *)PTR_ERR_add_error_data_006a9264)
                (6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
      return 0;
    }
    iVar6 = (*(code *)PTR_OBJ_txt2obj_006a8100)(puVar3[1],0);
    iVar4 = (*(code *)PTR_OBJ_txt2obj_006a8100)(puVar3[2],0);
    if ((iVar6 == 0) || (iVar4 == 0)) {
      (*(code *)PTR_sk_pop_free_006a8158)(iVar2,POLICY_MAPPING_free);
      uVar7 = 0x8c;
      goto LAB_005996b8;
    }
    piVar5 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)(POLICY_MAPPING_it);
    puVar1 = PTR_sk_push_006a80a8;
    if (piVar5 == (int *)0x0) {
      (*(code *)PTR_sk_pop_free_006a8158)(iVar2,POLICY_MAPPING_free);
      uVar7 = 0x93;
      goto LAB_0059978c;
    }
    *piVar5 = iVar6;
    piVar5[1] = iVar4;
    (*(code *)puVar1)(iVar2,piVar5);
    iVar8 = iVar8 + 1;
  } while( true );
}

