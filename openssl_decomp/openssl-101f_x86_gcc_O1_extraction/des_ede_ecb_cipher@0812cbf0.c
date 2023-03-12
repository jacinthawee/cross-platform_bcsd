
/* WARNING: Type propagation algorithm not settling */

undefined4
des_ede_ecb_cipher(int *param_1,DES_cblock *param_2,const_DES_cblock *param_3,uint param_4)

{
  uint uVar1;
  DES_key_schedule *ks1;
  const_DES_cblock *input;
  const_DES_cblock *pauVar2;
  
  uVar1 = *(uint *)(*param_1 + 4);
  if (uVar1 <= param_4) {
    input = param_3;
    do {
      ks1 = (DES_key_schedule *)param_1[0x18];
      pauVar2 = (const_DES_cblock *)((int)*input + uVar1);
      DES_ecb3_encrypt(input,param_2,ks1,ks1 + 1,ks1 + 2,param_1[2]);
      input = pauVar2;
      param_2 = (DES_cblock *)((int)*param_2 + uVar1);
    } while ((uint)((int)pauVar2 - (int)param_3) <= param_4 - uVar1);
  }
  return 1;
}

