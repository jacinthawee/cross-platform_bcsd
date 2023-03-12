
undefined4 aes_ecb_cipher(int *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(*param_1 + 4);
  if (uVar3 <= param_4) {
    iVar4 = param_1[0x18];
    iVar1 = param_3;
    do {
      iVar2 = iVar1 + uVar3;
      (**(code **)(iVar4 + 0xf4))(iVar1,param_2,iVar4);
      param_2 = param_2 + uVar3;
      iVar1 = iVar2;
    } while ((uint)(iVar2 - param_3) <= param_4 - uVar3);
  }
  return 1;
}

