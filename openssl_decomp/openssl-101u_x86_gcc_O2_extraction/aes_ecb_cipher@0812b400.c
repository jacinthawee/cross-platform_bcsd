
undefined4 aes_ecb_cipher(int *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(uint *)(*param_1 + 4);
  if (uVar1 <= param_4) {
    iVar2 = param_1[0x18];
    iVar3 = param_3;
    do {
      iVar4 = iVar3 + uVar1;
      (**(code **)(iVar2 + 0xf4))(iVar3,param_2,iVar2);
      iVar3 = iVar4;
      param_2 = param_2 + uVar1;
    } while ((uint)(iVar4 - param_3) <= param_4 - uVar1);
  }
  return 1;
}

