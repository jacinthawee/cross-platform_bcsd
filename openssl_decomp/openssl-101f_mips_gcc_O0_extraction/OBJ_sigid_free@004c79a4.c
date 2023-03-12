
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void OBJ_sigid_free(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_sig_app_006a95d0;
  if (*(int *)PTR_sig_app_006a95d0 != 0) {
    (*(code *)PTR_sk_pop_free_006a8158)(*(int *)PTR_sig_app_006a95d0,sid_free);
    *(undefined4 *)puVar1 = 0;
  }
  puVar1 = PTR_sigx_app_006a95d4;
  if (*(int *)PTR_sigx_app_006a95d4 != 0) {
    (*(code *)PTR_sk_free_006a7f80)();
    *(undefined4 *)puVar1 = 0;
  }
  return;
}

