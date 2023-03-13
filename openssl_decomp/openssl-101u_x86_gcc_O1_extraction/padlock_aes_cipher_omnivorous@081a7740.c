
/* WARNING: Removing unreachable block (ram,0x081a7766) */
/* WARNING: Removing unreachable block (ram,0x081a776a) */

longlong __regparm3
padlock_aes_cipher_omnivorous
          (EVP_CIPHER_CTX *param_1_00,undefined4 param_2,undefined4 param_3,uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ulong uVar4;
  uint uVar5;
  uint extraout_EDX;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)((-(int)param_1_00->cipher_data & 0xfU) + (int)param_1_00->cipher_data);
  padlock_saved_context = puVar7;
  uVar4 = EVP_CIPHER_CTX_flags(param_1_00);
  uVar5 = uVar4 & 0xf0007;
  if (uVar5 == 2) {
    uVar1 = *(undefined4 *)(param_1_00->iv + 0xc);
    uVar2 = *(undefined4 *)(param_1_00->iv + 8);
    uVar3 = *(undefined4 *)param_1_00->iv;
    puVar7[1] = *(undefined4 *)(param_1_00->iv + 4);
    puVar7[2] = uVar2;
    *puVar7 = uVar3;
    puVar7[3] = uVar1;
    xcrypt_cbc(param_1 >> 4,puVar7,puVar7 + 4,puVar7 + 8,param_3,param_2);
  }
  else {
    if (uVar5 < 3) {
      if (uVar5 != 1) {
LAB_081a7890:
        return (ulonglong)extraout_EDX << 0x20;
      }
      puVar6 = puVar7 + 4;
      xcrypt_ecb(param_1 >> 4,puVar6,puVar7 + 8,param_3,param_2);
      goto LAB_081a77ed;
    }
    if (uVar5 != 3) {
      if (uVar5 != 4) goto LAB_081a7890;
      uVar1 = *(undefined4 *)(param_1_00->iv + 0xc);
      uVar2 = *(undefined4 *)(param_1_00->iv + 8);
      uVar3 = *(undefined4 *)param_1_00->iv;
      puVar7[1] = *(undefined4 *)(param_1_00->iv + 4);
      puVar7[2] = uVar2;
      *puVar7 = uVar3;
      puVar7[3] = uVar1;
      xcrypt_ofb(param_1 >> 4,puVar7,puVar7 + 4,puVar7 + 8,param_3,param_2);
      uVar1 = puVar7[1];
      puVar6 = (undefined4 *)puVar7[2];
      uVar2 = puVar7[3];
      *(undefined4 *)param_1_00->iv = *puVar7;
      *(undefined4 *)(param_1_00->iv + 4) = uVar1;
      *(undefined4 **)(param_1_00->iv + 8) = puVar6;
      *(undefined4 *)(param_1_00->iv + 0xc) = uVar2;
      goto LAB_081a77ed;
    }
    uVar1 = *(undefined4 *)(param_1_00->iv + 0xc);
    uVar2 = *(undefined4 *)(param_1_00->iv + 8);
    uVar3 = *(undefined4 *)param_1_00->iv;
    puVar7[1] = *(undefined4 *)(param_1_00->iv + 4);
    puVar7[2] = uVar2;
    *puVar7 = uVar3;
    puVar7[3] = uVar1;
    xcrypt_cfb(param_1 >> 4,puVar7,puVar7 + 4,puVar7 + 8,param_3,param_2);
  }
  uVar1 = puVar7[1];
  puVar6 = (undefined4 *)puVar7[2];
  uVar2 = puVar7[3];
  *(undefined4 *)param_1_00->iv = *puVar7;
  *(undefined4 *)(param_1_00->iv + 4) = uVar1;
  *(undefined4 **)(param_1_00->iv + 8) = puVar6;
  *(undefined4 *)(param_1_00->iv + 0xc) = uVar2;
LAB_081a77ed:
  *puVar7 = 0;
  puVar7[1] = 0;
  puVar7[2] = 0;
  puVar7[3] = 0;
  return CONCAT44(puVar6,1);
}

