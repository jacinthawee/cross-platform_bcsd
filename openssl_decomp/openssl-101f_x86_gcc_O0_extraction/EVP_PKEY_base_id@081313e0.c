
int EVP_PKEY_base_id(EVP_PKEY *pkey)

{
  int *piVar1;
  int iVar2;
  int in_GS_OFFSET;
  ENGINE *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  piVar1 = (int *)EVP_PKEY_asn1_find(&local_14,pkey->type);
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar1;
  }
  if (local_14 != (ENGINE *)0x0) {
    ENGINE_finish(local_14);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

