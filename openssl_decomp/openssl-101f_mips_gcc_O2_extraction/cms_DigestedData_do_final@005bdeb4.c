
uint cms_DigestedData_do_final(int param_1,undefined4 param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int local_78;
  undefined auStack_74 [24];
  undefined auStack_5c [64];
  undefined4 *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_74);
  iVar6 = *(int *)(param_1 + 4);
  iVar2 = cms_DigestAlgorithm_find_ctx(auStack_74,param_2,*(undefined4 *)(iVar6 + 4));
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_74,auStack_5c,&local_78);
    if (0 < iVar2) {
      if (param_3 == 0) {
        iVar2 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)
                          (*(undefined4 *)(iVar6 + 0xc),auStack_5c,local_78);
        uVar7 = (uint)(iVar2 != 0);
        goto LAB_005bdf30;
      }
      if (**(int **)(iVar6 + 0xc) == local_78) {
        iVar2 = (*(code *)PTR_memcmp_006aabd8)(auStack_5c,(*(int **)(iVar6 + 0xc))[2]);
        if (iVar2 == 0) {
          uVar7 = 1;
          goto LAB_005bdf30;
        }
        uVar5 = 0x9e;
        uVar3 = 0x84;
      }
      else {
        uVar5 = 0x79;
        uVar3 = 0x7e;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x75,uVar5,"cms_dd.c",uVar3);
    }
  }
  uVar7 = 0;
LAB_005bdf30:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_74);
  if (local_1c == *(undefined4 **)puVar1) {
    return uVar7;
  }
  puVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar4);
  if (iVar2 == 0x17) {
    return puVar4[1];
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x83,0x6b,"cms_env.c",0x4f);
  return 0;
}

