
int pkey_dsa_paramgen(int param_1,EVP_PKEY *param_2)

{
  undefined4 *puVar1;
  DSA *r;
  int iVar2;
  undefined *puVar3;
  int in_GS_OFFSET;
  undefined local_2c [12];
  int local_20;
  
  puVar3 = (undefined *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x1c) != 0) {
    puVar3 = local_2c;
    evp_pkey_set_cb_translate(puVar3,param_1);
  }
  r = DSA_new();
  iVar2 = 0;
  if (r != (DSA *)0x0) {
    iVar2 = dsa_builtin_paramgen(r,*puVar1,puVar1[1],puVar1[2],0,0,0,0,0,puVar3);
    if (iVar2 == 0) {
      DSA_free(r);
      iVar2 = 0;
    }
    else {
      EVP_PKEY_assign(param_2,0x74,r);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

