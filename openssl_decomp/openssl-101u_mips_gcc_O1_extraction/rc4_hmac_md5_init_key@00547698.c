
undefined4 rc4_hmac_md5_init_key(EVP_CIPHER_CTX *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  void *pvVar11;
  
  pvVar11 = param_1->cipher_data;
  iVar1 = EVP_CIPHER_CTX_key_length(param_1);
  puVar10 = (undefined4 *)((int)pvVar11 + 0x104);
  (*(code *)PTR_RC4_set_key_006a79fc)(pvVar11,iVar1,param_2);
  (*(code *)PTR_MD5_Init_006a8160)(puVar10);
  puVar5 = (undefined4 *)((int)pvVar11 + 0x154);
  puVar2 = puVar10;
  puVar7 = (undefined4 *)((int)pvVar11 + 0x160);
  do {
    puVar4 = puVar7;
    puVar3 = puVar2 + 4;
    uVar9 = puVar2[1];
    uVar8 = puVar2[2];
    uVar6 = puVar2[3];
    *puVar4 = *puVar2;
    puVar4[1] = uVar9;
    puVar4[2] = uVar8;
    puVar4[3] = uVar6;
    puVar2 = puVar3;
    puVar7 = puVar4 + 4;
  } while (puVar3 != puVar5);
  uVar8 = *(undefined4 *)((int)pvVar11 + 0x158);
  uVar6 = *(undefined4 *)((int)pvVar11 + 0x15c);
  puVar4[4] = *puVar5;
  puVar4[5] = uVar8;
  puVar4[6] = uVar6;
  puVar2 = (undefined4 *)((int)pvVar11 + 0x1bc);
  do {
    puVar3 = puVar10;
    puVar7 = puVar2;
    puVar10 = puVar3 + 4;
    uVar9 = puVar3[1];
    uVar8 = puVar3[2];
    uVar6 = puVar3[3];
    *puVar7 = *puVar3;
    puVar7[1] = uVar9;
    puVar7[2] = uVar8;
    puVar7[3] = uVar6;
    puVar2 = puVar7 + 4;
  } while (puVar10 != puVar5);
  uVar8 = *puVar10;
  uVar6 = puVar3[5];
  puVar7[6] = puVar3[6];
  puVar7[4] = uVar8;
  puVar7[5] = uVar6;
  *(undefined4 *)((int)pvVar11 + 0x218) = 0xffffffff;
  return 1;
}

