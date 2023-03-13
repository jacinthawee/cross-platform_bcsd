
int pkey_rsa_keygen(int param_1,EVP_PKEY *param_2)

{
  int *piVar1;
  RSA *rsa;
  BN_GENCB *cb;
  int iVar2;
  BIGNUM *a;
  int in_GS_OFFSET;
  BN_GENCB local_2c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  piVar1 = *(int **)(param_1 + 0x14);
  if (piVar1[1] == 0) {
    a = BN_new();
    piVar1[1] = (int)a;
    if (a != (BIGNUM *)0x0) {
      iVar2 = BN_set_word(a,0x10001);
      if (iVar2 != 0) goto LAB_081c10c5;
    }
  }
  else {
LAB_081c10c5:
    rsa = RSA_new();
    if (rsa != (RSA *)0x0) {
      cb = (BN_GENCB *)0x0;
      if (*(int *)(param_1 + 0x1c) != 0) {
        evp_pkey_set_cb_translate(&local_2c,param_1);
        cb = &local_2c;
      }
      iVar2 = RSA_generate_key_ex(rsa,*piVar1,(BIGNUM *)piVar1[1],cb);
      if (iVar2 < 1) {
        RSA_free(rsa);
      }
      else {
        EVP_PKEY_assign(param_2,6,rsa);
      }
      goto LAB_081c1116;
    }
  }
  iVar2 = 0;
LAB_081c1116:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

