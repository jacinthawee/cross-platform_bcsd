
undefined4 param_copy_gost94(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_1);
  iVar3 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_2);
  iVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_1);
  if (iVar3 != iVar4) {
    ERR_GOST_error(0x75,0x69,"gost_ameth.c",0x216);
    return 0;
  }
  if (iVar1 == 0) {
    ERR_GOST_error(0x75,0x73,"gost_ameth.c",0x21c);
    uVar5 = 0;
  }
  else {
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_DSA_new_006a8624)();
      uVar5 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_2);
      (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,uVar5,iVar2);
    }
    if (*(int *)(iVar2 + 0xc) != 0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
    uVar5 = (*(code *)PTR_BN_dup_006a9100)(*(undefined4 *)(iVar1 + 0xc));
    *(undefined4 *)(iVar2 + 0xc) = uVar5;
    if (*(int *)(iVar2 + 0x10) != 0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
    uVar5 = (*(code *)PTR_BN_dup_006a9100)(*(undefined4 *)(iVar1 + 0x10));
    *(undefined4 *)(iVar2 + 0x10) = uVar5;
    if (*(int *)(iVar2 + 0x14) != 0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
    uVar5 = (*(code *)PTR_BN_dup_006a9100)(*(undefined4 *)(iVar1 + 0x14));
    *(undefined4 *)(iVar2 + 0x14) = uVar5;
    if (*(int *)(iVar2 + 0x1c) == 0) {
      return 1;
    }
    (*(code *)PTR_gost94_compute_public_006aa974)(iVar2);
    uVar5 = 1;
  }
  return uVar5;
}

