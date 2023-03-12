
undefined4 des_ctrl(undefined4 param_1,int param_2,undefined4 param_3,DES_cblock *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 6) {
    iVar1 = RAND_bytes((uchar *)param_4,8);
    uVar2 = 0;
    if (0 < iVar1) {
      DES_set_odd_parity(param_4);
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

