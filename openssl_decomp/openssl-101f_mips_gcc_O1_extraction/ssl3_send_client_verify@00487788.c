
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
  undefined4 uVar9;
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
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_b4 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_a8);
  if (param_1[0xd] != 0x1190) {
    uVar9 = 0;
    goto LAB_004877fc;
  }
  puVar10 = *(undefined **)(param_1[0xf] + 4);
  piVar11 = *(int **)(*(int *)param_1[0x26] + 4);
  uVar9 = (*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(piVar11,0);
  (*(code *)PTR_EVP_PKEY_sign_init_006a8dec)(uVar9);
  uVar3 = (*(code *)PTR_EVP_sha1_006a86c4)();
  iVar4 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(uVar9,0xffffffff,0xf8,1,0,uVar3);
  if (iVar4 < 1) {
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
LAB_00487918:
    if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
      piVar5 = (int *)param_1[0x26];
      goto LAB_00487a28;
    }
    iVar4 = *piVar11;
    if (iVar4 == 6) {
      (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,4,auStack_90);
      iVar4 = (*(code *)PTR_RSA_sign_006a8b64)
                        (0x72,auStack_90,0x24,puVar10 + 6,&local_b4,piVar11[5]);
      if (iVar4 < 1) goto LAB_00487cd4;
      puVar10[5] = (char)local_b4;
      iVar8 = local_b4 + 2;
      puVar10[4] = (char)((uint)local_b4 >> 8);
    }
    else {
      if (iVar4 == 0x74) {
        iVar4 = (*(code *)PTR_DSA_sign_006a8b7c)
                          (piVar11[1],auStack_80,0x14,puVar10 + 6,&local_b0,piVar11[5]);
        if (iVar4 == 0) {
          uVar7 = 10;
          uVar3 = 0xbcb;
          goto LAB_00487b44;
        }
      }
      else {
        if (iVar4 != 0x198) {
          if (1 < iVar4 - 0x32bU) {
            uVar7 = 0x44;
            uVar3 = 0xbf9;
            goto LAB_00487b44;
          }
          local_ac = 0x40;
          (**(code **)(*(int *)(param_1[2] + 100) + 0x1c))(param_1,0x329,auStack_90);
          iVar4 = (*(code *)PTR_EVP_PKEY_sign_006a8e00)(uVar9,auStack_6c,&local_ac,auStack_90,0x20);
          if (iVar4 < 1) {
            uVar7 = 0x44;
            uVar3 = 0xbee;
            goto LAB_00487b44;
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
          goto LAB_004879e8;
        }
        iVar4 = (*(code *)PTR_ECDSA_sign_006a8b74)
                          (piVar11[1],auStack_80,0x14,puVar10 + 6,&local_b0,piVar11[5]);
        if (iVar4 == 0) {
          uVar7 = 0x2a;
          uVar3 = 0xbdc;
          goto LAB_00487b44;
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
      goto LAB_00487918;
    }
    piVar5 = (int *)param_1[0x26];
LAB_00487a28:
    uVar3 = *(undefined4 *)(*piVar5 + 8);
    iVar4 = (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)(param_1[0x16] + 0x178),3,0,&local_ac);
    if (iVar4 < 1) {
LAB_00487b30:
      uVar7 = 0x44;
      uVar3 = 0xb9b;
      goto LAB_00487b44;
    }
    iVar8 = tls12_get_sigandhash(puVar10 + 4,piVar11,uVar3);
    if (iVar8 == 0) goto LAB_00487b30;
    iVar8 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_a8,uVar3,0);
    if (iVar8 == 0) {
LAB_00487c80:
      uVar7 = 6;
      uVar3 = 0xba8;
      goto LAB_00487b44;
    }
    iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_a8,local_ac,iVar4);
    if (iVar4 == 0) goto LAB_00487c80;
    iVar4 = (*(code *)PTR_EVP_SignFinal_006a9094)(auStack_a8,puVar10 + 8,&local_b4,piVar11);
    if (iVar4 == 0) goto LAB_00487c80;
    puVar10[7] = (char)local_b4;
    iVar8 = local_b4 + 4;
    puVar10[6] = (char)((uint)local_b4 >> 8);
    iVar4 = ssl3_digest_cached_records(param_1);
    if (iVar4 == 0) goto LAB_00487af4;
  }
LAB_004879e8:
  puVar10[3] = (char)iVar8;
  puVar10[2] = (char)((uint)iVar8 >> 8);
  *puVar10 = 0xf;
  puVar10[1] = (char)((uint)iVar8 >> 0x10);
  param_1[0xd] = 0x1191;
  param_1[0x11] = iVar8 + 4;
  param_1[0x12] = 0;
LAB_004877fc:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_a8);
  (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(uVar9);
  uVar3 = ssl3_do_write(param_1,0x16);
  while (local_2c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00487cd4:
    uVar7 = 4;
    uVar3 = 0xbbb;
LAB_00487b44:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x99,uVar7,"s3_clnt.c",uVar3);
LAB_00487af4:
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_a8);
    (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(uVar9);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

