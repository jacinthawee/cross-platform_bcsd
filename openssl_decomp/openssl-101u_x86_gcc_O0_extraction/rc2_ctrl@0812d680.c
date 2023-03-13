
undefined4 rc2_ctrl(EVP_CIPHER_CTX *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == 2) {
                    /* WARNING: Load size is inaccurate */
    *param_4 = *param_1->cipher_data;
    return 1;
  }
  if (param_2 == 3) {
    if (0 < param_3) {
      *(int *)param_1->cipher_data = param_3;
      return 1;
    }
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      piVar1 = (int *)param_1->cipher_data;
      iVar3 = EVP_CIPHER_CTX_key_length(param_1);
      *piVar1 = iVar3 << 3;
      return 1;
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

