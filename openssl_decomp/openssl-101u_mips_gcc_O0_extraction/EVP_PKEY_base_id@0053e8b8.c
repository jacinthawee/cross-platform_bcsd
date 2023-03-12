
int EVP_PKEY_base_id(EVP_PKEY *pkey)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  piVar2 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_006a6fd4)(&local_18,pkey->type);
  if (piVar2 == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *piVar2;
  }
  if (local_18 != 0) {
    (*(code *)PTR_ENGINE_finish_006a6fc4)();
  }
  if (local_14 != *(int *)puVar1) {
    iVar4 = local_14;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    iVar3 = 0x17f;
    if ((iVar4 != 0) &&
       (iVar3 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(iVar4 + 8,0xffffffff,10,"p_lib.c",0x17f),
       iVar3 < 1)) {
      if ((*(int *)(iVar4 + 0xc) != 0) &&
         (pcVar5 = *(code **)(*(int *)(iVar4 + 0xc) + 0x54), pcVar5 != (code *)0x0)) {
        (*pcVar5)(iVar4);
        *(undefined4 *)(iVar4 + 0x14) = 0;
      }
      if (*(int *)(iVar4 + 0x10) != 0) {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
        *(undefined4 *)(iVar4 + 0x10) = 0;
      }
      if (*(_STACK **)(iVar4 + 0x1c) != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)(iVar4 + 0x1c),(func *)PTR_X509_ATTRIBUTE_free_006a8ae4);
      }
                    /* WARNING: Could not recover jumptable at 0x0053ea20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar4 = (*(code *)PTR_CRYPTO_free_006a6e88)(iVar4);
      return iVar4;
    }
    return iVar3;
  }
  return iVar4;
}

