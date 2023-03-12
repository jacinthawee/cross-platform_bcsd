
int ssl3_output_cert_chain(int param_1,int param_2)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined *puVar8;
  char *pcVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  char *pcVar15;
  int iVar16;
  int iVar17;
  byte *pbVar18;
  int iVar19;
  uint local_d0;
  undefined4 *puStack_cc;
  undefined *local_b8;
  undefined *local_b4 [21];
  undefined4 local_60;
  undefined4 *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  if ((*(uint *)(param_1 + 0x104) & 8) == 0) {
    iVar19 = *(int *)(param_1 + 0x3c);
    iVar17 = *(int *)(*(int *)(param_1 + 0xe4) + 0x94);
    iVar3 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(iVar19);
    bVar1 = iVar17 != 0;
  }
  else {
    iVar19 = *(int *)(param_1 + 0x3c);
    bVar1 = true;
    iVar3 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(iVar19,10);
  }
  if (iVar3 == 0) {
    uVar13 = 7;
    pcVar15 = "s3_both.c";
    local_d0 = 0x16e;
    uVar12 = 0x93;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14);
    iVar3 = 0;
    goto LAB_00490964;
  }
  if (param_2 == 0) {
    iVar3 = 7;
  }
  else if (bVar1) {
    iVar17 = (*(code *)PTR_i2d_X509_006a87d4)(param_2,0);
    iVar3 = iVar17 + 10;
    iVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(iVar19,iVar3);
    puVar8 = PTR_i2d_X509_006a87d4;
    if (iVar4 == 0) {
LAB_00490b40:
      uVar13 = 7;
      pcVar15 = "s3_both.c";
      local_d0 = 0x152;
      uVar12 = 0x128;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14);
      iVar3 = 0;
      goto LAB_00490964;
    }
    iVar4 = *(int *)(iVar19 + 4);
    local_b4[0] = (undefined *)(iVar4 + 10);
    *(char *)(iVar4 + 7) = (char)((uint)iVar17 >> 0x10);
    *(char *)(iVar4 + 8) = (char)((uint)iVar17 >> 8);
    *(char *)(iVar4 + 9) = (char)iVar17;
    (*(code *)puVar8)(param_2,local_b4);
  }
  else {
    iVar3 = (*(code *)PTR_X509_STORE_CTX_init_006a8304)
                      (local_b4,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0xc),param_2,0);
    if (iVar3 == 0) {
      uVar13 = 0xb;
      pcVar15 = "s3_both.c";
      local_d0 = 0x17e;
      uVar12 = 0x93;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14);
      iVar3 = 0;
      goto LAB_00490964;
    }
    (*(code *)PTR_X509_verify_cert_006a8308)(local_b4);
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
    iVar3 = 7;
    for (iVar17 = 0; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(local_60), iVar17 < iVar4;
        iVar17 = iVar17 + 1) {
      uVar7 = (*(code *)PTR_sk_value_006a7f24)(local_60,iVar17);
      iVar4 = (*(code *)PTR_i2d_X509_006a87d4)(uVar7,0);
      iVar16 = iVar4 + 3 + iVar3;
      iVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(iVar19,iVar16);
      puVar8 = PTR_i2d_X509_006a87d4;
      if (iVar5 == 0) {
        uVar13 = 7;
        pcVar15 = "s3_both.c";
        local_d0 = 0x152;
        uVar12 = 0x128;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14);
        (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(local_b4);
        iVar3 = 0;
        goto LAB_00490964;
      }
      local_b8 = (undefined *)(*(int *)(iVar19 + 4) + iVar3);
      *local_b8 = (char)((uint)iVar4 >> 0x10);
      local_b8[1] = (char)((uint)iVar4 >> 8);
      local_b8[2] = (char)iVar4;
      local_b8 = local_b8 + 3;
      (*(code *)puVar8)(uVar7,&local_b8);
      iVar3 = iVar16;
    }
    (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(local_b4);
  }
  for (iVar17 = 0;
      iVar4 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x94)),
      iVar17 < iVar4; iVar17 = iVar17 + 1) {
    uVar7 = (*(code *)PTR_sk_value_006a7f24)
                      (*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x94),iVar17);
    iVar4 = (*(code *)PTR_i2d_X509_006a87d4)(uVar7,0);
    iVar16 = iVar4 + 3 + iVar3;
    iVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(iVar19,iVar16);
    puVar8 = PTR_i2d_X509_006a87d4;
    if (iVar5 == 0) goto LAB_00490b40;
    local_b4[0] = (undefined *)(*(int *)(iVar19 + 4) + iVar3);
    *local_b4[0] = (char)((uint)iVar4 >> 0x10);
    local_b4[0][1] = (char)((uint)iVar4 >> 8);
    local_b4[0][2] = (char)iVar4;
    local_b4[0] = local_b4[0] + 3;
    (*(code *)puVar8)(uVar7,local_b4);
    iVar3 = iVar16;
  }
  iVar4 = iVar3 + -7;
  iVar17 = *(int *)(iVar19 + 4);
  uVar10 = iVar3 - 4;
  *(char *)(iVar17 + 6) = (char)iVar4;
  pcVar15 = (char *)0xb;
  *(char *)(iVar17 + 4) = (char)((uint)iVar4 >> 0x10);
  uVar13 = uVar10 >> 0x10;
  *(char *)(iVar17 + 5) = (char)((uint)iVar4 >> 8);
  uVar12 = uVar10 >> 8;
  puVar8 = *(undefined **)(iVar19 + 4);
  *puVar8 = 0xb;
  puVar8[1] = (char)(uVar10 >> 0x10);
  puVar8[2] = (char)(uVar10 >> 8);
  puVar8[3] = (char)uVar10;
LAB_00490964:
  if (local_2c == *(undefined4 **)puVar2) {
    return iVar3;
  }
  puVar11 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = puVar11[0x16];
  iVar19 = *(int *)(iVar3 + 0x354);
  if (iVar19 != 0) {
    *(undefined4 *)(iVar3 + 0x354) = 0;
    if (((int)pcVar15 < 0) || (pcVar15 == *(char **)(iVar3 + 0x340))) {
      iVar19 = *(int *)(iVar3 + 0x33c);
      iVar3 = *(int *)(puVar11[0xf] + 4);
      *puStack_cc = 1;
      puVar11[0x11] = iVar19;
      puVar11[0x10] = iVar3 + 4;
    }
    else {
      uVar7 = 0x1b6;
LAB_00490fb8:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8e,0xf4,"s3_both.c",uVar7);
      uVar7 = 10;
LAB_00490fd0:
      ssl3_send_alert(puVar11,2,uVar7);
LAB_00490fe4:
      *puStack_cc = 0;
      iVar19 = -1;
    }
    return iVar19;
  }
  uVar10 = puVar11[0xd];
  iVar17 = puVar11[0xf];
  if (uVar10 == uVar12) {
    pbVar18 = *(byte **)(iVar17 + 4);
    pcVar6 = (char *)puVar11[0x11];
joined_r0x00490dc0:
    while (3 < (int)pcVar6) {
      pcVar6 = (char *)puVar11[9];
      pcVar9 = (char *)(uint)*pbVar18;
      if ((pcVar6 != (char *)0x0) || (pcVar9 != (char *)0x0)) {
        if ((int)pcVar15 < 0) {
          pcVar6 = pcVar9;
          if (pcVar9 == (char *)0x1) {
            if ((uVar10 == 0x2180) && (uVar13 == 0x2181)) {
              ssl3_init_finished_mac(puVar11,0x16,0x16,pbVar18);
              pcVar6 = (char *)(uint)*pbVar18;
            }
            else {
              pcVar6 = (char *)0x1;
            }
          }
        }
        else {
LAB_00490e80:
          pcVar6 = pcVar9;
          if (pcVar15 != pcVar9) {
            uVar7 = 0x1eb;
            goto LAB_00490fb8;
          }
        }
LAB_00490e88:
        iVar3 = puVar11[0x16];
        *(char **)(iVar3 + 0x340) = pcVar6;
        uVar12 = (uint)pbVar18[1] << 0x10 | (uint)pbVar18[2] << 8 | (uint)pbVar18[3];
        if (local_d0 < uVar12) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8e,0x98,"s3_both.c",0x200);
          uVar7 = 0x2f;
          goto LAB_00490fd0;
        }
        if (uVar12 != 0) {
          iVar3 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(puVar11[0xf],uVar12 + 4);
          if (iVar3 == 0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8e,7,"s3_both.c",0x20b);
            goto LAB_00490fe4;
          }
          iVar3 = puVar11[0x16];
        }
        iVar17 = puVar11[0xf];
        iVar4 = 0;
        *(uint *)(iVar3 + 0x33c) = uVar12;
        puVar11[0xd] = uVar13;
        iVar3 = *(int *)(iVar17 + 4);
        puVar11[0x11] = 0;
        iVar3 = iVar3 + 4;
        puVar11[0x10] = iVar3;
        goto LAB_00490c88;
      }
      if (((pbVar18[1] != 0) || (pbVar18[2] != 0)) || (pbVar18[3] != 0)) {
        if (-1 < (int)pcVar15) goto LAB_00490e80;
        goto LAB_00490e88;
      }
      puVar11[0x11] = 0;
      if ((code *)puVar11[0x19] == (code *)0x0) break;
      (*(code *)puVar11[0x19])(0,*puVar11,0x16,pbVar18,4,puVar11,puVar11[0x1a]);
      pcVar6 = (char *)puVar11[0x11];
    }
    iVar17 = (**(code **)(puVar11[2] + 0x34))(puVar11,0x16,pbVar18 + (int)pcVar6,4 - (int)pcVar6,0);
    if (0 < iVar17) {
      pcVar6 = (char *)(iVar17 + puVar11[0x11]);
      puVar11[0x11] = pcVar6;
      goto joined_r0x00490dc0;
    }
LAB_00490cd8:
    puVar11[6] = 3;
    *puStack_cc = 0;
    return iVar17;
  }
  iVar4 = puVar11[0x11];
  uVar12 = *(uint *)(iVar3 + 0x33c);
  iVar3 = puVar11[0x10];
  iVar19 = iVar4;
LAB_00490c88:
  iVar4 = uVar12 - iVar4;
  if (iVar4 < 1) {
    pcVar15 = *(char **)(iVar17 + 4);
  }
  else {
    do {
      iVar17 = (**(code **)(puVar11[2] + 0x34))(puVar11,0x16,iVar3 + iVar19,iVar4,0);
      iVar4 = iVar4 - iVar17;
      if (iVar17 < 1) goto LAB_00490cd8;
      iVar19 = iVar17 + puVar11[0x11];
      puVar11[0x11] = iVar19;
    } while (0 < iVar4);
    pcVar15 = *(char **)(puVar11[0xf] + 4);
  }
  if ((*pcVar15 == '\x14') && (iVar3 = puVar11[0x16], *(int *)(iVar3 + 0x344) != 0)) {
    if ((puVar11[0xd] & 0x1000) == 0) {
      iVar19 = *(int *)(puVar11[2] + 100);
      uVar7 = *(undefined4 *)(iVar19 + 0x20);
      uVar14 = *(undefined4 *)(iVar19 + 0x24);
    }
    else {
      iVar19 = *(int *)(puVar11[2] + 100);
      uVar7 = *(undefined4 *)(iVar19 + 0x28);
      uVar14 = *(undefined4 *)(iVar19 + 0x2c);
    }
    uVar7 = (**(code **)(iVar19 + 0x14))(puVar11,uVar7,uVar14,iVar3 + 0x2b8);
    iVar17 = puVar11[0xf];
    iVar19 = puVar11[0x11];
    *(undefined4 *)(iVar3 + 0x338) = uVar7;
    pcVar15 = *(char **)(iVar17 + 4);
  }
  ssl3_finish_mac(puVar11,pcVar15,iVar19 + 4);
  if ((code *)puVar11[0x19] != (code *)0x0) {
    (*(code *)puVar11[0x19])
              (0,*puVar11,0x16,*(undefined4 *)(puVar11[0xf] + 4),puVar11[0x11] + 4,puVar11,
               puVar11[0x1a]);
  }
  *puStack_cc = 1;
  return puVar11[0x11];
}

