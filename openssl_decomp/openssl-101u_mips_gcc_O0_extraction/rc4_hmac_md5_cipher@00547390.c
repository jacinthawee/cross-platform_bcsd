
int rc4_hmac_md5_cipher(int param_1,undefined *param_2,undefined *param_3,undefined *param_4)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  EVP_CIPHER_CTX *ctx;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined *puVar12;
  undefined4 *puVar13;
  void *pvVar14;
  int iVar15;
  undefined4 *puVar16;
  undefined *puVar17;
  int iVar18;
  undefined auStack_34 [16];
  EVP_CIPHER_CTX *local_24;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iVar18 = *(int *)(param_1 + 0x60);
  local_24 = *(EVP_CIPHER_CTX **)PTR___stack_chk_guard_006a9ae8;
  iVar11 = *(int *)(iVar18 + 0x218);
  puVar17 = (undefined *)(iVar11 + 0x10);
  if (iVar11 == -1) {
    if (*(int *)(param_1 + 8) == 0) {
      (*(code *)PTR_RC4_006a7a30)(iVar18,param_4,param_3,param_2);
      (*(code *)PTR_MD5_Update_006a8ab0)(iVar18 + 0x1bc,param_2,param_4);
      param_4 = param_2;
    }
    else {
      (*(code *)PTR_MD5_Update_006a8ab0)(iVar18 + 0x1bc,param_3,param_4);
      (*(code *)PTR_RC4_006a7a30)(iVar18,param_4,param_3,param_2);
    }
  }
  else {
    bVar1 = puVar17 != param_4;
    iVar15 = 0;
    param_4 = param_2;
    if (bVar1) goto LAB_005473f4;
    iVar15 = *(int *)(param_1 + 8);
    if (iVar15 == 0) {
      (*(code *)PTR_RC4_006a7a30)(iVar18,puVar17,param_3,param_2);
      puVar13 = (undefined4 *)(iVar18 + 0x1bc);
      param_4 = auStack_34;
      (*(code *)PTR_MD5_Update_006a8ab0)(puVar13,param_2,iVar11);
      (*(code *)PTR_MD5_Final_006a8aac)(param_4,puVar13);
      puVar16 = (undefined4 *)(iVar18 + 0x160);
      puVar4 = puVar13;
      do {
        puVar5 = puVar4;
        puVar7 = puVar16;
        puVar16 = puVar7 + 4;
        uVar10 = puVar7[1];
        uVar9 = puVar7[2];
        uVar8 = puVar7[3];
        *puVar5 = *puVar7;
        puVar5[1] = uVar10;
        puVar5[2] = uVar9;
        puVar5[3] = uVar8;
        puVar17 = PTR_MD5_Update_006a8ab0;
        puVar4 = puVar5 + 4;
      } while (puVar16 != (undefined4 *)(iVar18 + 0x1b0));
      uVar9 = puVar7[5];
      uVar8 = puVar7[6];
      puVar5[4] = *puVar16;
      puVar5[5] = uVar9;
      puVar5[6] = uVar8;
      (*(code *)puVar17)(puVar13,param_4,0x10);
      (*(code *)PTR_MD5_Final_006a8aac)(param_4,puVar13);
      iVar11 = (*(code *)PTR_CRYPTO_memcmp_006a8128)(param_2 + iVar11,param_4,0x10);
      if (iVar11 != 0) goto LAB_005473f4;
    }
    else {
      puVar16 = (undefined4 *)(iVar18 + 0x1bc);
      (*(code *)PTR_MD5_Update_006a8ab0)(puVar16,param_3,iVar11);
      if (param_3 != param_2) {
        (*(code *)PTR_memcpy_006a9aec)(param_2,param_3,iVar11);
      }
      puVar12 = param_2 + iVar11;
      (*(code *)PTR_MD5_Final_006a8aac)(puVar12,puVar16);
      puVar4 = (undefined4 *)(iVar18 + 0x160);
      puVar13 = puVar16;
      do {
        puVar5 = puVar13;
        puVar7 = puVar4;
        puVar4 = puVar7 + 4;
        uVar10 = puVar7[1];
        uVar9 = puVar7[2];
        uVar8 = puVar7[3];
        *puVar5 = *puVar7;
        puVar5[1] = uVar10;
        puVar5[2] = uVar9;
        puVar5[3] = uVar8;
        puVar2 = PTR_MD5_Update_006a8ab0;
        puVar13 = puVar5 + 4;
      } while (puVar4 != (undefined4 *)(iVar18 + 0x1b0));
      uVar9 = puVar7[5];
      uVar8 = puVar7[6];
      puVar5[4] = *puVar4;
      puVar5[5] = uVar9;
      puVar5[6] = uVar8;
      (*(code *)puVar2)(puVar16,puVar12,0x10);
      (*(code *)PTR_MD5_Final_006a8aac)(puVar12,puVar16);
      (*(code *)PTR_RC4_006a7a30)(iVar18,puVar17,param_2,param_2);
      param_4 = puVar17;
    }
  }
  iVar15 = 1;
  *(undefined4 *)(iVar18 + 0x218) = 0xffffffff;
LAB_005473f4:
  if (local_24 != *(EVP_CIPHER_CTX **)puVar3) {
    ctx = local_24;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    pvVar14 = ctx->cipher_data;
    iVar11 = EVP_CIPHER_CTX_key_length(ctx);
    puVar13 = (undefined4 *)((int)pvVar14 + 0x104);
    (*(code *)PTR_RC4_set_key_006a79fc)(pvVar14,iVar11,param_4);
    (*(code *)PTR_MD5_Init_006a8160)(puVar13);
    puVar7 = (undefined4 *)((int)pvVar14 + 0x154);
    puVar16 = puVar13;
    puVar4 = (undefined4 *)((int)pvVar14 + 0x160);
    do {
      puVar6 = puVar4;
      puVar5 = puVar16 + 4;
      uVar10 = puVar16[1];
      uVar9 = puVar16[2];
      uVar8 = puVar16[3];
      *puVar6 = *puVar16;
      puVar6[1] = uVar10;
      puVar6[2] = uVar9;
      puVar6[3] = uVar8;
      puVar16 = puVar5;
      puVar4 = puVar6 + 4;
    } while (puVar5 != puVar7);
    uVar9 = *(undefined4 *)((int)pvVar14 + 0x158);
    uVar8 = *(undefined4 *)((int)pvVar14 + 0x15c);
    puVar6[4] = *puVar7;
    puVar6[5] = uVar9;
    puVar6[6] = uVar8;
    puVar16 = (undefined4 *)((int)pvVar14 + 0x1bc);
    do {
      puVar5 = puVar13;
      puVar4 = puVar16;
      puVar13 = puVar5 + 4;
      uVar10 = puVar5[1];
      uVar9 = puVar5[2];
      uVar8 = puVar5[3];
      *puVar4 = *puVar5;
      puVar4[1] = uVar10;
      puVar4[2] = uVar9;
      puVar4[3] = uVar8;
      puVar16 = puVar4 + 4;
    } while (puVar13 != puVar7);
    uVar9 = *puVar13;
    uVar8 = puVar5[5];
    puVar4[6] = puVar5[6];
    puVar4[4] = uVar9;
    puVar4[5] = uVar8;
    *(undefined4 *)((int)pvVar14 + 0x218) = 0xffffffff;
    return 1;
  }
  return iVar15;
}

