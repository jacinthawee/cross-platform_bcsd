
/* WARNING: Removing unreachable block (ram,0x004bfddc) */
/* WARNING: Removing unreachable block (ram,0x004bfe60) */
/* WARNING: Removing unreachable block (ram,0x004bfe0c) */
/* WARNING: Removing unreachable block (ram,0x004bfe28) */
/* WARNING: Removing unreachable block (ram,0x004bfe84) */
/* WARNING: Removing unreachable block (ram,0x004bfecc) */
/* WARNING: Removing unreachable block (ram,0x004bfef0) */
/* WARNING: Removing unreachable block (ram,0x004bff7c) */
/* WARNING: Removing unreachable block (ram,0x004bff8c) */
/* WARNING: Removing unreachable block (ram,0x004bff9c) */
/* WARNING: Removing unreachable block (ram,0x004bffcc) */
/* WARNING: Removing unreachable block (ram,0x004c0010) */
/* WARNING: Removing unreachable block (ram,0x004bffdc) */
/* WARNING: Removing unreachable block (ram,0x004bff0c) */
/* WARNING: Removing unreachable block (ram,0x004c0000) */
/* WARNING: Removing unreachable block (ram,0x004bff1c) */
/* WARNING: Removing unreachable block (ram,0x004bff40) */
/* WARNING: Removing unreachable block (ram,0x004bff54) */
/* WARNING: Removing unreachable block (ram,0x004bff58) */

undefined1 * load_builtin_compressions(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *ptr;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  
  CRYPTO_lock(5,0x10,"ssl_ciph.c",0x1bd);
  if (ssl_comp_methods == 0) {
    CRYPTO_lock(6,0x10,"ssl_ciph.c",0x1c0);
    CRYPTO_lock(9,0x10,"ssl_ciph.c",0x1c1);
    if (ssl_comp_methods == 0) {
      CRYPTO_mem_ctrl(3);
      ssl_comp_methods = (*(code *)PTR_sk_new_006a91b4)(sk_comp_cmp);
      if (ssl_comp_methods != 0) {
        ptr = (undefined4 *)CRYPTO_malloc(0xc,"ssl_ciph.c",0x1cc);
        if (ptr != (undefined4 *)0x0) {
          piVar3 = (int *)(*(code *)PTR_COMP_zlib_006a94d4)();
          ptr[2] = piVar3;
          iVar2 = ssl_comp_methods;
          puVar1 = PTR_sk_push_006a80a8;
          if ((piVar3 == (int *)0x0) || (*piVar3 != 0)) {
            iVar4 = piVar3[1];
            *ptr = 1;
            ptr[1] = iVar4;
            (*(code *)puVar1)(iVar2,ptr);
          }
          else {
            CRYPTO_free(ptr);
          }
        }
        (*(code *)PTR_sk_sort_006a94d8)(ssl_comp_methods);
      }
      CRYPTO_mem_ctrl(2);
    }
  }
  if (locking_callback != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004bfdd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar5 = (undefined1 *)(*locking_callback)();
    return puVar5;
  }
  return &_ITM_registerTMCloneTable;
}

