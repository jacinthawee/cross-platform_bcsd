
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void EVP_cleanup(void)

{
  undefined *puVar1;
  
  (*(code *)PTR_OBJ_NAME_cleanup_006a9b84)(2);
  (*(code *)PTR_OBJ_NAME_cleanup_006a9b84)(1);
  (*(code *)PTR_OBJ_NAME_cleanup_006a9b84)(0xffffffff);
  EVP_PBE_cleanup();
  puVar1 = PTR_OBJ_cleanup_006a7f98;
  if (*(int *)PTR_obj_cleanup_defer_006a9b8c != 2) {
                    /* WARNING: Could not recover jumptable at 0x0053f33c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_OBJ_sigid_free_006a9b90)();
    return;
  }
  *(undefined4 *)PTR_obj_cleanup_defer_006a9b8c = 0;
  (*(code *)puVar1)();
                    /* WARNING: Could not recover jumptable at 0x0053f35c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_OBJ_sigid_free_006a9b90)();
  return;
}

