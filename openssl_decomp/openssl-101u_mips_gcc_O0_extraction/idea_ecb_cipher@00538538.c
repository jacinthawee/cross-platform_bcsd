
undefined4 idea_ecb_cipher(int *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(*param_1 + 4);
  iVar1 = param_3;
  if (uVar3 <= param_4) {
    do {
      iVar2 = iVar1 + uVar3;
      (*(code *)PTR_idea_ecb_encrypt_006a89d4)(iVar1,param_2,param_1[0x18]);
      iVar1 = iVar2;
      param_2 = param_2 + uVar3;
    } while ((uint)(iVar2 - param_3) <= param_4 - uVar3);
  }
  return 1;
}

