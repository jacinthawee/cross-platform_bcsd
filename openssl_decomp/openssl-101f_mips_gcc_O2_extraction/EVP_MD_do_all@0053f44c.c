
void EVP_MD_do_all(fn *fn,void *arg)

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
  code *pcStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  undefined *puStack_38;
  code *pcStack_34;
  undefined *local_20;
  void *local_14;
  fn *local_10;
  int local_c;
  
  puStack_38 = PTR___stack_chk_guard_006aabf0;
  pcStack_44 = do_all_md_fn;
  uStack_40 = 1;
  local_20 = &_gp;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_14 = arg;
  local_10 = fn;
  (*(code *)PTR_OBJ_NAME_do_all_006a9b94)(1,do_all_md_fn,&local_14);
  if (local_c == *(int *)puStack_38) {
    return;
  }
  pcStack_34 = EVP_MD_do_all_sorted;
  (**(code **)(local_20 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  ppcVar5 = &pcStack_44;
  pcVar4 = do_all_md_fn;
  iVar3 = 1;
  iStack_3c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_OBJ_NAME_do_all_sorted_006a8640)(1,do_all_md_fn,ppcVar5);
  if (iStack_3c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (0x3fffffff < in_a3) {
      pcVar6 = pcVar4;
      ppcVar7 = ppcVar5;
      uVar8 = in_a3;
      do {
        uVar8 = uVar8 + 0xc0000000;
        (*(code *)PTR_SEED_cbc_encrypt_006a8b40)
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
      (*(code *)PTR_SEED_cbc_encrypt_006a8b40)
                (ppcVar5,pcVar4,in_a3,*(undefined4 *)(iVar3 + 0x60),iVar3 + 0x20,
                 *(undefined4 *)(iVar3 + 8));
    }
    return;
  }
  return;
}
