
uint ssl3_write_bytes(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined *puVar7;
  uint uVar8;
  int iVar9;
  undefined uVar10;
  undefined4 uVar11;
  int iVar12;
  undefined *puVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int local_44;
  int local_40;
  int local_3c;
  
  param_1[6] = 1;
  puVar6 = PTR_SSL_state_006a88f4;
  iVar14 = *(int *)(param_1[0x16] + 0x164);
  *(undefined4 *)(param_1[0x16] + 0x164) = 0;
  uVar3 = (*(code *)puVar6)();
  if (((uVar3 & 0x3000) != 0) && (param_1[7] == 0)) {
    uVar3 = (*(code *)param_1[8])(param_1);
    if (-1 < (int)uVar3) {
      if (uVar3 != 0) goto LAB_0048e15c;
      uVar3 = 0xffffffff;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9e,0xe5,"s3_pkt.c",0x254);
    }
    return uVar3;
  }
LAB_0048e15c:
  iVar16 = param_1[0x16];
  uVar3 = param_4 - iVar14;
  iVar9 = *(int *)(iVar16 + 0xfc);
  uVar2 = param_1[0x45];
  if (uVar3 <= (uint)param_1[0x45]) {
    uVar2 = uVar3;
  }
  do {
    iVar1 = param_3 + iVar14;
    if ((iVar9 == 0) && (iVar9 = ssl3_setup_write_buffer(param_1), iVar9 == 0)) {
LAB_0048e3f4:
      iVar9 = param_1[0x16];
      uVar15 = 0xffffffff;
LAB_0048e3fc:
      *(int *)(iVar9 + 0x164) = iVar14;
      return uVar15;
    }
    uVar15 = *(uint *)(iVar16 + 0x108);
    if (uVar15 == 0) {
      iVar9 = param_1[0x16];
      if (*(int *)(iVar9 + 0x18c) != 0) {
        uVar8 = (**(code **)(param_1[2] + 0x3c))(param_1);
        iVar9 = param_1[0x16];
        if ((int)uVar8 < 1) {
          *(int *)(iVar9 + 0x164) = iVar14;
          return uVar8;
        }
      }
      if (uVar2 == 0) goto LAB_0048e3fc;
      if (param_1[0x30] != 0) {
        if (param_1[0x23] == 0) goto LAB_0048e5d8;
        iVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1[0x24]);
        if (iVar4 == 0) goto LAB_0048e5cc;
        uVar5 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1[0x24]);
        local_44 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar5);
        if (local_44 < 0) goto LAB_0048e3f4;
LAB_0048e200:
        iVar4 = param_1[0x16];
        if (*(int *)(iVar4 + 0xe4) != 0) goto LAB_0048e22c;
        if ((*(int *)(iVar4 + 0xe0) == 0) || (param_2 != 0x17)) {
          *(undefined4 *)(iVar4 + 0xe4) = 1;
          goto LAB_0048e22c;
        }
        local_3c = do_ssl3_write(param_1,0x17,iVar1,0,1);
        if (local_3c < 1) goto LAB_0048e3f4;
        if (local_3c < 0x56) {
          iVar12 = *(int *)(iVar16 + 0x104);
          iVar4 = *(int *)(iVar16 + 0xfc);
          *(undefined4 *)(param_1[0x16] + 0xe4) = 1;
          puVar6 = (undefined *)(iVar4 + local_3c + iVar12);
          goto LAB_0048e248;
        }
        uVar11 = 0x44;
        uVar5 = 0x2c2;
LAB_0048e5f4:
        uVar15 = 0xffffffff;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x68,uVar11,"s3_pkt.c",uVar5);
        iVar9 = param_1[0x16];
        goto LAB_0048e3fc;
      }
LAB_0048e5cc:
      if (param_1[0x23] != 0) {
        local_44 = 0;
        goto LAB_0048e200;
      }
LAB_0048e5d8:
      local_44 = 0;
LAB_0048e22c:
      local_3c = 0;
      uVar15 = -(*(int *)(iVar16 + 0xfc) + 5) & 7;
      puVar6 = (undefined *)(*(int *)(iVar16 + 0xfc) + uVar15);
      *(uint *)(iVar16 + 0x104) = uVar15;
LAB_0048e248:
      *puVar6 = (char)param_2;
      iVar4 = *param_1;
      *(int *)(iVar9 + 0x130) = param_2;
      puVar6[1] = (char)((uint)iVar4 >> 8);
      if ((param_1[0xd] == 0x1111) && (param_1[100] == 0)) {
        iVar4 = *param_1;
        if ((iVar4 >> 8 != 3) || (iVar4 < 0x302)) goto LAB_0048e274;
        uVar10 = 1;
      }
      else {
        iVar4 = *param_1;
LAB_0048e274:
        uVar10 = (undefined)iVar4;
      }
      puVar6[2] = uVar10;
      puVar13 = puVar6 + 5;
      if ((param_1[0x23] == 0) || (*param_1 < 0x302)) {
LAB_0048e29c:
        local_40 = 0;
LAB_0048e2a0:
        iVar4 = param_1[0x25];
        puVar7 = puVar13 + local_40;
        *(uint *)(iVar9 + 0x134) = uVar2;
        *(int *)(iVar9 + 0x140) = iVar1;
        *(undefined **)(iVar9 + 0x13c) = puVar7;
        if (iVar4 != 0) goto LAB_0048e2b8;
LAB_0048e52c:
        (*(code *)PTR_memcpy_006aabf4)(puVar7,iVar1,uVar2);
        *(undefined4 *)(iVar9 + 0x140) = *(undefined4 *)(iVar9 + 0x13c);
      }
      else {
        uVar15 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a9230)();
        if ((uVar15 & 0xf0007) == 2) {
          local_40 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a9164)(param_1[0x23]);
          if (local_40 < 2) goto LAB_0048e29c;
          goto LAB_0048e2a0;
        }
        if ((uVar15 & 0xf0007) != 6) goto LAB_0048e29c;
        iVar4 = param_1[0x25];
        *(uint *)(iVar9 + 0x134) = uVar2;
        *(int *)(iVar9 + 0x140) = iVar1;
        local_40 = 8;
        puVar7 = puVar6 + 0xd;
        *(undefined **)(iVar9 + 0x13c) = puVar7;
        if (iVar4 == 0) goto LAB_0048e52c;
LAB_0048e2b8:
        iVar12 = param_1[0x16];
        iVar4 = (*(code *)PTR_COMP_compress_block_006a9244)
                          (iVar4,*(undefined4 *)(iVar12 + 0x13c),0x4400,
                           *(undefined4 *)(iVar12 + 0x140),*(undefined4 *)(iVar12 + 0x134));
        if (iVar4 < 0) {
          uVar11 = 0x8d;
          uVar5 = 0x318;
          goto LAB_0048e5f4;
        }
        *(int *)(iVar12 + 0x134) = iVar4;
        *(undefined4 *)(iVar12 + 0x140) = *(undefined4 *)(iVar12 + 0x13c);
      }
      if (local_44 != 0) {
        iVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                          (param_1,puVar13 + local_40 + *(int *)(iVar9 + 0x134),1);
        if (iVar4 < 0) goto LAB_0048e3f4;
        *(int *)(iVar9 + 0x134) = *(int *)(iVar9 + 0x134) + local_44;
      }
      *(undefined **)(iVar9 + 0x140) = puVar13;
      *(undefined **)(iVar9 + 0x13c) = puVar13;
      if (local_40 != 0) {
        *(int *)(iVar9 + 0x134) = *(int *)(iVar9 + 0x134) + local_40;
      }
      (***(code ***)(param_1[2] + 100))(param_1,1);
      puVar6[3] = (char)((uint)*(undefined4 *)(iVar9 + 0x134) >> 8);
      puVar6[4] = (char)*(undefined4 *)(iVar9 + 0x134);
      iVar4 = param_1[0x16];
      *(int *)(iVar9 + 0x130) = param_2;
      iVar12 = *(int *)(iVar9 + 0x134) + 5;
      *(int *)(iVar9 + 0x134) = iVar12;
      *(int *)(iVar16 + 0x108) = iVar12 + local_3c;
      *(uint *)(iVar4 + 0x168) = uVar2;
      *(int *)(iVar4 + 0x174) = iVar1;
      *(int *)(iVar4 + 0x16c) = param_2;
      *(uint *)(iVar4 + 0x170) = uVar2;
      uVar15 = ssl3_write_pending(param_1,param_2,iVar1,uVar2);
    }
    else {
      uVar15 = ssl3_write_pending(param_1,param_2,iVar1,uVar2);
    }
    if ((int)uVar15 < 1) {
      iVar9 = param_1[0x16];
      goto LAB_0048e3fc;
    }
    if ((uVar3 == uVar15) || ((param_2 == 0x17 && ((param_1[0x41] & 1U) != 0)))) {
      *(undefined4 *)(param_1[0x16] + 0xe4) = 0;
      return uVar15 + iVar14;
    }
    iVar14 = iVar14 + uVar15;
    uVar3 = uVar3 - uVar15;
    iVar16 = param_1[0x16];
    iVar9 = *(int *)(iVar16 + 0xfc);
    uVar2 = param_1[0x45];
    if (uVar3 <= (uint)param_1[0x45]) {
      uVar2 = uVar3;
    }
  } while( true );
}

