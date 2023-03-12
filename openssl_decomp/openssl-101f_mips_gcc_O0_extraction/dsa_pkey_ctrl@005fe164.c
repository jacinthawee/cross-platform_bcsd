
undefined4 dsa_pkey_ctrl(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_20;
  int *local_1c;
  undefined4 local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = 2;
  if (param_2 == 3) {
    *param_4 = 0x40;
    goto LAB_005fe1b8;
  }
  uVar2 = 1;
  if (param_2 == 5) {
    if (param_3 != 0) goto LAB_005fe1b8;
    (*(code *)PTR_CMS_SignerInfo_get0_algs_006aa420)(param_4,0,0,&local_1c,&local_18);
  }
  else {
    uVar2 = 0xfffffffe;
    if (param_2 != 1) goto LAB_005fe1b8;
    if (param_3 != 0) {
      uVar2 = 1;
      goto LAB_005fe1b8;
    }
    (*(code *)PTR_PKCS7_SIGNER_INFO_get0_algs_006aa7c0)(param_4,0,&local_1c,&local_18);
  }
  if (((local_1c != (int *)0x0) && (*local_1c != 0)) &&
     (iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(), iVar3 != 0)) {
    uVar2 = (*(code *)PTR_EVP_PKEY_id_006a80d0)(param_1);
    iVar3 = (*(code *)PTR_OBJ_find_sigid_by_algs_006aa7c4)(&local_20,iVar3,uVar2);
    if (iVar3 != 0) {
      uVar2 = (*(code *)PTR_OBJ_nid2obj_006a8240)(local_20);
      (*(code *)PTR_X509_ALGOR_set0_006a9e04)(local_18,uVar2,0xffffffff,0);
      uVar2 = 1;
      goto LAB_005fe1b8;
    }
  }
  uVar2 = 0xffffffff;
LAB_005fe1b8:
  if (local_14 != *(int *)puVar1) {
    iVar3 = local_14;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x005fe2e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)PTR_DSA_free_006a862c)(*(undefined4 *)(iVar3 + 0x14));
    return uVar2;
  }
  return uVar2;
}

