
uint ssl3_write_bytes(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  undefined uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined *puVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int local_44;
  int local_40;
  int local_3c;
  
  iVar1 = param_1[0x16];
  param_1[6] = 1;
  if (*(int *)(iVar1 + 0x164) < 0) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("s3_pkt.c",0x274,"s->s3->wnum <= INT_MAX");
    iVar1 = param_1[0x16];
  }
  puVar5 = PTR_SSL_state_006a7808;
  iVar13 = *(int *)(iVar1 + 0x164);
  *(undefined4 *)(iVar1 + 0x164) = 0;
  uVar2 = (*(code *)puVar5)(param_1);
  if (((uVar2 & 0x3000) != 0) && (param_1[7] == 0)) {
    uVar2 = (*(code *)param_1[8])(param_1);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (uVar2 == 0) {
      uVar10 = 0xe5;
      uVar4 = 0x27d;
      goto LAB_0048a680;
    }
  }
  uVar2 = param_4 - iVar13;
  if (iVar13 <= param_4) {
    iVar15 = param_1[0x16];
    uVar14 = *(uint *)(iVar15 + 0x108);
    iVar1 = param_3 + iVar13;
    uVar7 = param_1[0x45];
    if (uVar2 <= (uint)param_1[0x45]) {
      uVar7 = uVar2;
    }
    if (uVar14 != 0) goto LAB_0048a418;
    while( true ) {
      if ((*(int *)(iVar15 + 0x18c) != 0) &&
         (uVar8 = (**(code **)(param_1[2] + 0x3c))(param_1), (int)uVar8 < 1)) {
        *(int *)(param_1[0x16] + 0x164) = iVar13;
        return uVar8;
      }
      if ((*(int *)(iVar15 + 0xfc) == 0) && (iVar16 = ssl3_setup_write_buffer(param_1), iVar16 == 0)
         ) break;
      if (uVar7 == 0) goto LAB_0048a44c;
      iVar16 = param_1[0x16];
      if (param_1[0x30] == 0) {
LAB_0048a604:
        if (param_1[0x23] == 0) goto LAB_0048a610;
        local_44 = 0;
LAB_0048a234:
        iVar3 = param_1[0x16];
        if (*(int *)(iVar3 + 0xe4) != 0) goto LAB_0048a260;
        if ((*(int *)(iVar3 + 0xe0) == 0) || (param_2 != 0x17)) {
          *(undefined4 *)(iVar3 + 0xe4) = 1;
          goto LAB_0048a260;
        }
        local_3c = do_ssl3_write(param_1,0x17,iVar1,0,1);
        if (local_3c < 1) break;
        if (local_3c < 0x56) {
          iVar11 = *(int *)(iVar15 + 0x104);
          iVar3 = *(int *)(iVar15 + 0xfc);
          *(undefined4 *)(param_1[0x16] + 0xe4) = 1;
          puVar5 = (undefined *)(iVar3 + local_3c + iVar11);
          goto LAB_0048a27c;
        }
        uVar10 = 0x44;
        uVar4 = 0x2fa;
LAB_0048a62c:
        uVar14 = 0xffffffff;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x68,uVar10,"s3_pkt.c",uVar4);
        iVar1 = param_1[0x16];
        goto LAB_0048a450;
      }
      if (param_1[0x23] != 0) {
        iVar3 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1[0x24]);
        if (iVar3 == 0) goto LAB_0048a604;
        uVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1[0x24]);
        local_44 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar4);
        if (local_44 < 0) break;
        goto LAB_0048a234;
      }
LAB_0048a610:
      local_44 = 0;
LAB_0048a260:
      local_3c = 0;
      uVar14 = -(*(int *)(iVar15 + 0xfc) + 5) & 7;
      puVar5 = (undefined *)(*(int *)(iVar15 + 0xfc) + uVar14);
      *(uint *)(iVar15 + 0x104) = uVar14;
LAB_0048a27c:
      *puVar5 = (char)param_2;
      iVar3 = *param_1;
      *(int *)(iVar16 + 0x130) = param_2;
      puVar5[1] = (char)((uint)iVar3 >> 8);
      if ((param_1[0xd] == 0x1111) && (param_1[100] == 0)) {
        iVar3 = *param_1;
        if ((iVar3 >> 8 != 3) || (iVar3 < 0x302)) goto LAB_0048a2a8;
        uVar9 = 1;
      }
      else {
        iVar3 = *param_1;
LAB_0048a2a8:
        uVar9 = (undefined)iVar3;
      }
      puVar5[2] = uVar9;
      puVar12 = puVar5 + 5;
      if ((param_1[0x23] == 0) || (*param_1 < 0x302)) {
LAB_0048a2d0:
        local_40 = 0;
LAB_0048a2d4:
        iVar3 = param_1[0x25];
        puVar6 = puVar12 + local_40;
        *(uint *)(iVar16 + 0x134) = uVar7;
        *(int *)(iVar16 + 0x140) = iVar1;
        *(undefined **)(iVar16 + 0x13c) = puVar6;
        if (iVar3 != 0) goto LAB_0048a2ec;
LAB_0048a558:
        (*(code *)PTR_memcpy_006a9aec)(puVar6,iVar1,uVar7);
        *(undefined4 *)(iVar16 + 0x140) = *(undefined4 *)(iVar16 + 0x13c);
      }
      else {
        uVar14 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a8108)();
        if ((uVar14 & 0xf0007) == 2) {
          local_40 = (*(code *)PTR_EVP_CIPHER_CTX_iv_length_006a7ff8)(param_1[0x23]);
          if (local_40 < 2) goto LAB_0048a2d0;
          goto LAB_0048a2d4;
        }
        if ((uVar14 & 0xf0007) != 6) goto LAB_0048a2d0;
        iVar3 = param_1[0x25];
        *(uint *)(iVar16 + 0x134) = uVar7;
        *(int *)(iVar16 + 0x140) = iVar1;
        local_40 = 8;
        puVar6 = puVar5 + 0xd;
        *(undefined **)(iVar16 + 0x13c) = puVar6;
        if (iVar3 == 0) goto LAB_0048a558;
LAB_0048a2ec:
        iVar11 = param_1[0x16];
        iVar3 = (*(code *)PTR_COMP_compress_block_006a811c)
                          (iVar3,*(undefined4 *)(iVar11 + 0x13c),0x4400,
                           *(undefined4 *)(iVar11 + 0x140),*(undefined4 *)(iVar11 + 0x134));
        if (iVar3 < 0) {
          uVar10 = 0x8d;
          uVar4 = 0x348;
          goto LAB_0048a62c;
        }
        *(int *)(iVar11 + 0x134) = iVar3;
        *(undefined4 *)(iVar11 + 0x140) = *(undefined4 *)(iVar11 + 0x13c);
      }
      if (local_44 != 0) {
        iVar3 = (**(code **)(*(int *)(param_1[2] + 100) + 4))
                          (param_1,puVar12 + local_40 + *(int *)(iVar16 + 0x134),1);
        if (iVar3 < 0) break;
        *(int *)(iVar16 + 0x134) = *(int *)(iVar16 + 0x134) + local_44;
      }
      *(undefined **)(iVar16 + 0x140) = puVar12;
      *(undefined **)(iVar16 + 0x13c) = puVar12;
      if (local_40 != 0) {
        *(int *)(iVar16 + 0x134) = *(int *)(iVar16 + 0x134) + local_40;
      }
      iVar3 = (***(code ***)(param_1[2] + 100))(param_1,1);
      if (iVar3 < 1) break;
      puVar5[3] = (char)((uint)*(undefined4 *)(iVar16 + 0x134) >> 8);
      puVar5[4] = (char)*(undefined4 *)(iVar16 + 0x134);
      iVar3 = param_1[0x16];
      *(int *)(iVar16 + 0x130) = param_2;
      iVar11 = *(int *)(iVar16 + 0x134) + 5;
      *(int *)(iVar16 + 0x134) = iVar11;
      *(int *)(iVar15 + 0x108) = iVar11 + local_3c;
      *(uint *)(iVar3 + 0x168) = uVar7;
      *(int *)(iVar3 + 0x174) = iVar1;
      *(int *)(iVar3 + 0x16c) = param_2;
      *(uint *)(iVar3 + 0x170) = uVar7;
      uVar14 = ssl3_write_pending(param_1,param_2,iVar1,uVar7);
      while( true ) {
        if ((int)uVar14 < 1) goto LAB_0048a44c;
        if ((uVar2 == uVar14) || ((param_2 == 0x17 && ((param_1[0x41] & 1U) != 0)))) {
          *(undefined4 *)(param_1[0x16] + 0xe4) = 0;
          return uVar14 + iVar13;
        }
        iVar13 = iVar13 + uVar14;
        uVar2 = uVar2 - uVar14;
        iVar15 = param_1[0x16];
        iVar1 = param_3 + iVar13;
        uVar14 = *(uint *)(iVar15 + 0x108);
        uVar7 = param_1[0x45];
        if (uVar2 <= (uint)param_1[0x45]) {
          uVar7 = uVar2;
        }
        if (uVar14 == 0) break;
LAB_0048a418:
        uVar14 = ssl3_write_pending(param_1,param_2,iVar1,uVar7);
      }
    }
    uVar14 = 0xffffffff;
LAB_0048a44c:
    iVar1 = param_1[0x16];
LAB_0048a450:
    *(int *)(iVar1 + 0x164) = iVar13;
    return uVar14;
  }
  uVar10 = 0x10f;
  uVar4 = 0x28c;
LAB_0048a680:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9e,uVar10,"s3_pkt.c",uVar4);
  return 0xffffffff;
}

