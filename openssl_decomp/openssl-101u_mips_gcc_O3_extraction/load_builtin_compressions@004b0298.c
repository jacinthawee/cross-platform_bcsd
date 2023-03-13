
/* WARNING: Removing unreachable block (ram,0x004bcc7c) */
/* WARNING: Removing unreachable block (ram,0x004bcd00) */
/* WARNING: Removing unreachable block (ram,0x004bccac) */
/* WARNING: Removing unreachable block (ram,0x004bccc8) */
/* WARNING: Removing unreachable block (ram,0x004bcd24) */
/* WARNING: Removing unreachable block (ram,0x004bcd6c) */
/* WARNING: Removing unreachable block (ram,0x004bcd90) */
/* WARNING: Removing unreachable block (ram,0x004bce1c) */
/* WARNING: Removing unreachable block (ram,0x004bce2c) */
/* WARNING: Removing unreachable block (ram,0x004bce3c) */
/* WARNING: Removing unreachable block (ram,0x004bce6c) */
/* WARNING: Removing unreachable block (ram,0x004bceb0) */
/* WARNING: Removing unreachable block (ram,0x004bce7c) */
/* WARNING: Removing unreachable block (ram,0x004bcdac) */
/* WARNING: Removing unreachable block (ram,0x004bcea0) */
/* WARNING: Removing unreachable block (ram,0x004bcdbc) */
/* WARNING: Removing unreachable block (ram,0x004bcde0) */
/* WARNING: Removing unreachable block (ram,0x004bcdf4) */
/* WARNING: Removing unreachable block (ram,0x004bcdf8) */

undefined * load_builtin_compressions(void)

{
  int iVar1;
  undefined4 *ptr;
  int *piVar2;
  int iVar3;
  undefined *puVar4;
  
  CRYPTO_lock(5,0x10,"ssl_ciph.c",0x1c7);
  if (ssl_comp_methods == 0) {
    CRYPTO_lock(6,0x10,"ssl_ciph.c",0x1c9);
    CRYPTO_lock(9,0x10,"ssl_ciph.c",0x1ca);
    if (ssl_comp_methods == 0) {
      CRYPTO_mem_ctrl(3);
      ssl_comp_methods = (*(code *)PTR_sk_new_006a806c)(sk_comp_cmp);
      if (ssl_comp_methods != 0) {
        ptr = (undefined4 *)CRYPTO_malloc(0xc,"ssl_ciph.c",0x1d3);
        if (ptr != (undefined4 *)0x0) {
          piVar2 = (int *)(*(code *)PTR_COMP_zlib_006a83b8)();
          ptr[2] = piVar2;
          iVar1 = ssl_comp_methods;
          puVar4 = PTR_sk_push_006a6fa8;
          if ((piVar2 == (int *)0x0) || (*piVar2 != 0)) {
            iVar3 = piVar2[1];
            *ptr = 1;
            ptr[1] = iVar3;
            (*(code *)puVar4)(iVar1,ptr);
          }
          else {
            CRYPTO_free(ptr);
          }
        }
        (*(code *)PTR_sk_sort_006a83bc)(ssl_comp_methods);
      }
      CRYPTO_mem_ctrl(2);
    }
  }
  if (locking_callback != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004bcc74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar4 = (undefined *)(*locking_callback)();
    return puVar4;
  }
  return &_gp_1;
}

