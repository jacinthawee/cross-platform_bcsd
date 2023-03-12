
int EVP_PKEY_type(int type)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_18;
  int *local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int **)PTR___stack_chk_guard_006a9ae8;
  piVar2 = (int *)(*(code *)PTR_EVP_PKEY_asn1_find_006a6fd4)(&local_18,type);
  if (piVar2 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar2;
  }
  if (local_18 != 0) {
    (*(code *)PTR_ENGINE_finish_006a6fc4)();
  }
  if (local_14 == *(int **)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return *local_14;
}

