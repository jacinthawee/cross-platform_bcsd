
int dtls1_get_cipher(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ssl3_get_cipher(param_1);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x14) == 4) {
      iVar1 = 0;
    }
    return iVar1;
  }
  return 0;
}

