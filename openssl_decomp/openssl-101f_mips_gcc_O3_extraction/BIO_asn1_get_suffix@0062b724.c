
int BIO_asn1_get_suffix(BIO *b,undefined1 **psuffix,undefined1 **psuffix_free)

{
  undefined *puVar1;
  int iVar2;
  undefined1 *local_1c;
  undefined1 *local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(b,0x98,0,&local_1c);
  if (0 < iVar2) {
    *psuffix = local_1c;
    *psuffix_free = local_18;
  }
  if (local_14 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return (int)_bignum_nist_p_192;
}

