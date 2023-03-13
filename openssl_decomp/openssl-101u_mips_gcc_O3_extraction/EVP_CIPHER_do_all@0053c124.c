
void EVP_CIPHER_do_all(fn *fn,void *arg)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  code **ppcVar5;
  uint in_a3;
  code *pcVar6;
  code **ppcVar7;
  uint uVar8;
  code *pcStack_a4;
  undefined4 uStack_a0;
  int iStack_9c;
  undefined *puStack_98;
  code *pcStack_94;
  undefined *puStack_80;
  code *pcStack_74;
  undefined4 uStack_70;
  int iStack_6c;
  undefined *puStack_68;
  code *pcStack_64;
  undefined *puStack_50;
  code *pcStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  undefined *puStack_38;
  code *pcStack_34;
  undefined *local_20;
  void *local_14;
  fn *local_10;
  int local_c;
  
  puStack_38 = PTR___stack_chk_guard_006a9ae8;
  pcStack_44 = do_all_cipher_fn;
  uStack_40 = 2;
  local_20 = &_gp;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_14 = arg;
  local_10 = fn;
  (*(code *)PTR_OBJ_NAME_do_all_006a8a78)(2,do_all_cipher_fn,&local_14);
  if (local_c == *(int *)puStack_38) {
    return;
  }
  pcStack_34 = EVP_CIPHER_do_all_sorted;
  (**(code **)(local_20 + -0x5330))();
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  pcStack_74 = do_all_cipher_fn;
  uStack_70 = 2;
  puStack_50 = &_gp;
  iStack_3c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_OBJ_NAME_do_all_sorted_006a7548)(2,do_all_cipher_fn,&pcStack_44);
  if (iStack_3c == *(int *)puStack_68) {
    return;
  }
  pcStack_64 = EVP_MD_do_all;
  (**(code **)(puStack_50 + -0x5330))();
  puStack_98 = PTR___stack_chk_guard_006a9ae8;
  pcStack_a4 = do_all_md_fn;
  uStack_a0 = 1;
  puStack_80 = &_gp;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_OBJ_NAME_do_all_006a8a78)(1,do_all_md_fn,&pcStack_74);
  if (iStack_6c == *(int *)puStack_98) {
    return;
  }
  pcStack_94 = EVP_MD_do_all_sorted;
  (**(code **)(puStack_80 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  ppcVar5 = &pcStack_a4;
  pcVar4 = do_all_md_fn;
  iVar3 = 1;
  iStack_9c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_OBJ_NAME_do_all_sorted_006a7548)(1,do_all_md_fn,ppcVar5);
  if (iStack_9c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    if (0x3fffffff < in_a3) {
      pcVar6 = pcVar4;
      ppcVar7 = ppcVar5;
      uVar8 = in_a3;
      do {
        uVar8 = uVar8 + 0xc0000000;
        (*(code *)PTR_SEED_cbc_encrypt_006a7a50)
                  (ppcVar7,pcVar6,0x40000000,*(undefined4 *)(iVar3 + 0x60),iVar3 + 0x20,
                   *(undefined4 *)(iVar3 + 8));
        ppcVar7 = ppcVar7 + 0x10000000;
        pcVar6 = pcVar6 + 0x40000000;
      } while (0x3fffffff < uVar8);
      uVar8 = in_a3 + 0xc0000000;
      in_a3 = in_a3 & 0x3fffffff;
      iVar2 = (uVar8 >> 0x1e) + 1;
      ppcVar5 = ppcVar5 + iVar2 * 0x10000000;
      pcVar4 = pcVar4 + iVar2 * 0x40000000;
    }
    if (in_a3 != 0) {
      (*(code *)PTR_SEED_cbc_encrypt_006a7a50)
                (ppcVar5,pcVar4,in_a3,*(undefined4 *)(iVar3 + 0x60),iVar3 + 0x20,
                 *(undefined4 *)(iVar3 + 8));
    }
    return;
  }
  return;
}

