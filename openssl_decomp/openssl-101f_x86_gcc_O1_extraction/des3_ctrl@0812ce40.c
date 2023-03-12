
undefined4 des3_ctrl(int param_1,int param_2,undefined4 param_3,DES_cblock *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 6) {
    uVar2 = 0;
    iVar1 = RAND_bytes((uchar *)param_4,*(int *)(param_1 + 0x58));
    if (0 < iVar1) {
      uVar2 = 1;
      DES_set_odd_parity(param_4);
      if (0xf < *(int *)(param_1 + 0x58)) {
        DES_set_odd_parity(param_4[1]);
        if (0x17 < *(int *)(param_1 + 0x58)) {
          DES_set_odd_parity(param_4[2]);
          return 1;
        }
      }
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

