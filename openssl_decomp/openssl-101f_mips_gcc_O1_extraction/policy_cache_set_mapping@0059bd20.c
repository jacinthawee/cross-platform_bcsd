
undefined4 policy_cache_set_mapping(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  int iVar8;
  uint **ppuVar9;
  
  ppuVar9 = *(uint ***)(param_1 + 0x40);
  iVar2 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
  if (iVar2 == 0) {
LAB_0059beac:
    uVar7 = 0xffffffff;
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x800;
  }
  else {
    iVar8 = 0;
    iVar2 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
    if (0 < iVar2) {
      do {
        puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(param_2,iVar8);
        iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(puVar3[1]);
        if (iVar2 == 0x2ea) goto LAB_0059beac;
        iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar3);
        if (iVar2 == 0x2ea) goto LAB_0059beac;
        puVar4 = (uint *)policy_cache_find_data(ppuVar9,*puVar3);
        if (puVar4 == (uint *)0x0) {
          if (*ppuVar9 != (uint *)0x0) {
            puVar4 = (uint *)policy_data_new(0,*puVar3,**ppuVar9 & 0x10);
            puVar1 = PTR_sk_push_006a80a8;
            if (puVar4 == (uint *)0x0) goto LAB_0059bef8;
            puVar6 = ppuVar9[1];
            uVar5 = (*ppuVar9)[2];
            *puVar4 = *puVar4 | 6;
            puVar4[2] = uVar5;
            iVar2 = (*(code *)puVar1)(puVar6,puVar4);
            if (iVar2 != 0) goto LAB_0059bdf8;
            uVar7 = 0;
            policy_data_free(puVar4);
            goto LAB_0059bebc;
          }
        }
        else {
          *puVar4 = *puVar4 | 1;
LAB_0059bdf8:
          iVar2 = (*(code *)PTR_sk_push_006a80a8)(puVar4[3],puVar3[1]);
          if (iVar2 == 0) {
LAB_0059bef8:
            uVar7 = 0;
            goto LAB_0059bebc;
          }
          puVar3[1] = 0;
        }
        iVar8 = iVar8 + 1;
        iVar2 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
      } while (iVar8 < iVar2);
    }
    uVar7 = 1;
  }
LAB_0059bebc:
  (*(code *)PTR_sk_pop_free_006a8158)(param_2,PTR_POLICY_MAPPING_free_006aa1d0);
  return uVar7;
}
