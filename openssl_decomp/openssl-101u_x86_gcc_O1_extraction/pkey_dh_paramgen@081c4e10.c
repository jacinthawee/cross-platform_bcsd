
int pkey_dh_paramgen(int param_1,EVP_PKEY *param_2)

{
  int *piVar1;
  DH *dh;
  int iVar2;
  BN_GENCB *cb;
  int in_GS_OFFSET;
  BN_GENCB local_2c;
  int local_20;
  
  cb = (BN_GENCB *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  piVar1 = *(int **)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x1c) != 0) {
    cb = &local_2c;
    evp_pkey_set_cb_translate(cb,param_1);
  }
  dh = DH_new();
  iVar2 = 0;
  if (dh != (DH *)0x0) {
    iVar2 = DH_generate_parameters_ex(dh,*piVar1,piVar1[1],cb);
    if (iVar2 == 0) {
      DH_free(dh);
      iVar2 = 0;
    }
    else {
      EVP_PKEY_assign(param_2,0x1c,dh);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

