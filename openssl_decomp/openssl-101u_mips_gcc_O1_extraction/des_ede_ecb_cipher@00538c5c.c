
undefined4 des_ede_ecb_cipher(int *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(*param_1 + 4);
  iVar2 = param_3;
  if (uVar4 <= param_4) {
    do {
      iVar1 = param_1[0x18];
      iVar3 = iVar2 + uVar4;
      (*(code *)PTR_DES_ecb3_encrypt_006a89e4)
                (iVar2,param_2,iVar1,iVar1 + 0x80,iVar1 + 0x100,param_1[2]);
      iVar2 = iVar3;
      param_2 = param_2 + uVar4;
    } while ((uint)(iVar3 - param_3) <= param_4 - uVar4);
  }
  return 1;
}

