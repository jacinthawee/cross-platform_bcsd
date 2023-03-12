
void EVP_MD_do_all_sorted(fn *fn,void *arg)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  void **ppvVar5;
  uint in_a3;
  code *pcVar6;
  void **ppvVar7;
  uint uVar8;
  void *local_14;
  fn *local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  ppvVar5 = &local_14;
  pcVar4 = do_all_md_fn;
  iVar3 = 1;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_14 = arg;
  local_10 = fn;
  (*(code *)PTR_OBJ_NAME_do_all_sorted_006a8640)(1,do_all_md_fn,ppvVar5);
  if (local_c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (0x3fffffff < in_a3) {
      pcVar6 = pcVar4;
      ppvVar7 = ppvVar5;
      uVar8 = in_a3;
      do {
        uVar8 = uVar8 + 0xc0000000;
        (*(code *)PTR_SEED_cbc_encrypt_006a8b40)
                  (ppvVar7,pcVar6,0x40000000,*(undefined4 *)(iVar3 + 0x60),iVar3 + 0x20,
                   *(undefined4 *)(iVar3 + 8));
        ppvVar7 = ppvVar7 + 0x10000000;
        pcVar6 = pcVar6 + 0x40000000;
      } while (0x3fffffff < uVar8);
      uVar8 = in_a3 + 0xc0000000;
      in_a3 = in_a3 & 0x3fffffff;
      iVar2 = (uVar8 >> 0x1e) + 1;
      ppvVar5 = ppvVar5 + iVar2 * 0x10000000;
      pcVar4 = pcVar4 + iVar2 * 0x40000000;
    }
    if (in_a3 != 0) {
      (*(code *)PTR_SEED_cbc_encrypt_006a8b40)
                (ppvVar5,pcVar4,in_a3,*(undefined4 *)(iVar3 + 0x60),iVar3 + 0x20,
                 *(undefined4 *)(iVar3 + 8));
    }
    return;
  }
  return;
}

