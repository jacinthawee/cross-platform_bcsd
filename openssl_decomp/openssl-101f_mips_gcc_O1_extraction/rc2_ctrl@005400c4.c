
undefined4 rc2_ctrl(EVP_CIPHER_CTX *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
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
    uVar2 = 0xffffffff;
    if (param_2 == 0) {
      piVar3 = (int *)param_1->cipher_data;
      iVar1 = EVP_CIPHER_CTX_key_length(param_1);
      *piVar3 = iVar1 << 3;
      return 1;
    }
  }
  return uVar2;
}

