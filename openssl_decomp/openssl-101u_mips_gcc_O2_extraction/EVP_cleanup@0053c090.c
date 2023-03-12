
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void EVP_cleanup(void)

{
  undefined *puVar1;
  
  (*(code *)PTR_OBJ_NAME_cleanup_006a8a68)(2);
  (*(code *)PTR_OBJ_NAME_cleanup_006a8a68)(1);
  (*(code *)PTR_OBJ_NAME_cleanup_006a8a68)(0xffffffff);
  EVP_PBE_cleanup();
  puVar1 = PTR_OBJ_cleanup_006a6e98;
  if (*(int *)PTR_obj_cleanup_defer_006a8a70 != 2) {
                    /* WARNING: Could not recover jumptable at 0x0053c0fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_OBJ_sigid_free_006a8a74)();
    return;
  }
  *(undefined4 *)PTR_obj_cleanup_defer_006a8a70 = 0;
  (*(code *)puVar1)();
                    /* WARNING: Could not recover jumptable at 0x0053c11c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_OBJ_sigid_free_006a8a74)();
  return;
}

