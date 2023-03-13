
undefined4 ssl3_send_client_verify(int *param_1)

{
  undefined uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined *puVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined *puVar10;
  int *piVar11;
  int local_b4;
  int local_b0;
  undefined4 local_ac;
  undefined auStack_a8 [24];
  undefined auStack_90 [16];
  undefined auStack_80 [19];
  undefined uStack_6d;
  undefined auStack_6c [64];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_b4 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_a8);
  if (param_1[0xd] != 0x1190) {
    iVar9 = 0;
    goto LAB_0048352c;
  }
  puVar10 = *(undefined **)(param_1[0xf] + 4);
  piVar11 = *(int **)(*(int *)param_1[0x26] + 4);
  iVar9 = (*(code *)PTR_EVP_PKEY_CTX_new_006a6fe0)(piVar11,0);
  if (iVar9 == 0) {
LAB_004839c0:
    uVar7 = 0x44;
    uVar3 = 0xc25;
    goto LAB_00483870;
  }
  iVar4 = (*(code *)PTR_EVP_PKEY_sign_init_006a7cfc)(iVar9);
  if (iVar4 < 1) goto LAB_004839c0;
  uVar3 = (*(code *)PTR_EVP_sha1_006a75d0)();
  iVar4 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(iVar9,0xffffffff,0xf8,1,0,uVar3);
  if (iVar4 < 1) {
    (*(code *)PTR_ERR_clear_error_006a6ee0)();
LAB_00483650:
    if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
      piVar5 = (int *)param_1[0x26];
      goto LAB_00483760;
    }
    iVar4 = *piVar11;
    if (iVar4 == 6) {
      (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,4,auStack_90);
      iVar4 = (*(code *)PTR_RSA_sign_006a7a78)
                        (0x72,auStack_90,0x24,puVar10 + 6,&local_b4,piVar11[5]);
      if (iVar4 < 1) goto LAB_00483a2c;
      puVar10[5] = (char)local_b4;
      iVar8 = local_b4 + 2;
      puVar10[4] = (char)((uint)local_b4 >> 8);
    }
    else {
      if (iVar4 == 0x74) {
        iVar4 = (*(code *)PTR_DSA_sign_006a7a90)
                          (piVar11[1],auStack_80,0x14,puVar10 + 6,&local_b0,piVar11[5]);
        if (iVar4 == 0) {
          uVar7 = 10;
          uVar3 = 0xc61;
          goto LAB_00483870;
        }
      }
      else {
        if (iVar4 != 0x198) {
          if (1 < iVar4 - 0x32bU) {
            uVar7 = 0x44;
            uVar3 = 0xc86;
            goto LAB_00483870;
          }
          local_ac = 0x40;
          (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,0x329,auStack_90);
          iVar4 = (*(code *)PTR_EVP_PKEY_sign_006a7d10)(iVar9,auStack_6c,&local_ac,auStack_90,0x20);
          if (iVar4 < 1) {
            uVar7 = 0x44;
            uVar3 = 0xc7d;
            goto LAB_00483870;
          }
          puVar6 = auStack_6c + 0x3f;
          local_b0 = 0;
          iVar4 = local_b0;
          do {
            local_b0 = iVar4;
            uVar1 = *puVar6;
            puVar6 = puVar6 + -1;
            (puVar10 + 4)[local_b0 + 2] = uVar1;
            iVar4 = local_b0 + 1;
          } while (&uStack_6d != puVar6);
          puVar10[5] = (char)iVar4;
          iVar8 = local_b0 + 3;
          puVar10[4] = (char)((uint)iVar4 >> 8);
          local_b0 = iVar4;
          goto LAB_00483720;
        }
        iVar4 = (*(code *)PTR_ECDSA_sign_006a7a88)
                          (piVar11[1],auStack_80,0x14,puVar10 + 6,&local_b0,piVar11[5]);
        if (iVar4 == 0) {
          uVar7 = 0x2a;
          uVar3 = 0xc6e;
          goto LAB_00483870;
        }
      }
      puVar10[5] = (char)local_b0;
      iVar8 = local_b0 + 2;
      puVar10[4] = (char)((uint)local_b0 >> 8);
    }
  }
  else {
    if ((*param_1 >> 8 != 3) || (*param_1 < 0x303)) {
      (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,0x40,auStack_80);
      goto LAB_00483650;
    }
    piVar5 = (int *)param_1[0x26];
LAB_00483760:
    uVar3 = *(undefined4 *)(*piVar5 + 8);
    iVar4 = (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)(param_1[0x16] + 0x178),3,0,&local_ac);
    if (iVar4 < 1) {
LAB_00483888:
      uVar7 = 0x44;
      uVar3 = 0xc3b;
      goto LAB_00483870;
    }
    iVar8 = tls12_get_sigandhash(puVar10 + 4,piVar11,uVar3);
    if (iVar8 == 0) goto LAB_00483888;
    iVar8 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_a8,uVar3,0);
    if (iVar8 == 0) {
LAB_004839d8:
      uVar7 = 6;
      uVar3 = 0xc46;
      goto LAB_00483870;
    }
    iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_a8,local_ac,iVar4);
    if (iVar4 == 0) goto LAB_004839d8;
    iVar4 = (*(code *)PTR_EVP_SignFinal_006a7f70)(auStack_a8,puVar10 + 8,&local_b4,piVar11);
    if (iVar4 == 0) goto LAB_004839d8;
    puVar10[7] = (char)local_b4;
    iVar8 = local_b4 + 4;
    puVar10[6] = (char)((uint)local_b4 >> 8);
    iVar4 = ssl3_digest_cached_records(param_1);
    if (iVar4 == 0) goto LAB_0048382c;
  }
LAB_00483720:
  puVar10[3] = (char)iVar8;
  puVar10[2] = (char)((uint)iVar8 >> 8);
  *puVar10 = 0xf;
  puVar10[1] = (char)((uint)iVar8 >> 0x10);
  param_1[0xd] = 0x1191;
  param_1[0x11] = iVar8 + 4;
  param_1[0x12] = 0;
LAB_0048352c:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_a8);
  (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar9);
  uVar3 = ssl3_do_write(param_1,0x16);
  while (local_2c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00483a2c:
    uVar7 = 4;
    uVar3 = 0xc54;
LAB_00483870:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x99,uVar7,"s3_clnt.c",uVar3);
LAB_0048382c:
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_a8);
    (*(code *)PTR_EVP_PKEY_CTX_free_006a6e7c)(iVar9);
    uVar3 = 0xffffffff;
    param_1[0xd] = 5;
  }
  return uVar3;
}

