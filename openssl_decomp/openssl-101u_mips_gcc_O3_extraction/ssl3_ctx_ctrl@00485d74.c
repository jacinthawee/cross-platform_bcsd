
bool ssl3_ctx_ctrl(int param_1,int param_2,int param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar11;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar12;
  uint in_t1;
  uint uVar13;
  uint uVar14;
  uint in_t2;
  uint uVar15;
  uint uVar16;
  uint in_t3;
  uint in_t4;
  int iVar17;
  
  iVar17 = *(int *)(param_1 + 0xb0);
  switch(param_2) {
  default:
    goto switchD_00485db8_caseD_0;
  case 1:
    if (*(int *)(iVar17 + 0x18) == 0) {
      if (*(int *)(iVar17 + 0x34) != 0) {
        iVar17 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
        return 0x40 < iVar17;
      }
      goto LAB_004860d0;
    }
    goto switchD_00485db8_caseD_0;
  case 2:
    if ((param_4 == (uint *)0x0) ||
       (iVar9 = (*(code *)PTR_RSAPrivateKey_dup_006a80bc)(param_4), iVar9 == 0)) {
      uVar12 = 4;
      uVar8 = 0xdb1;
      goto LAB_00485dd4;
    }
    if (*(int *)(iVar17 + 0x18) != 0) {
      (*(code *)PTR_RSA_free_006a7600)();
    }
    *(int *)(iVar17 + 0x18) = iVar9;
    goto LAB_004860d0;
  case 3:
    iVar9 = (*(code *)PTR_DHparams_dup_006a7f8c)(param_4);
    if (iVar9 != 0) {
      if (*(int *)(iVar17 + 0x20) != 0) {
        (*(code *)PTR_DH_free_006a7508)();
      }
      *(int *)(iVar17 + 0x20) = iVar9;
      return true;
    }
    uVar12 = 5;
    uVar8 = 0xdc9;
    goto LAB_00485dd4;
  case 4:
    if (param_4 == (uint *)0x0) {
      uVar12 = 0x2b;
      uVar8 = 0xde1;
    }
    else {
      iVar9 = (*(code *)PTR_EC_KEY_dup_006a7f74)(param_4);
      if (iVar9 == 0) {
        uVar12 = 0x10;
        uVar8 = 0xde6;
      }
      else {
        if ((*(int *)(param_1 + 0xa4) << 0xc < 0) ||
           (iVar10 = (*(code *)PTR_EC_KEY_generate_key_006a71d0)(iVar9), iVar10 != 0)) {
          if (*(int *)(iVar17 + 0x28) != 0) {
            (*(code *)PTR_EC_KEY_free_006a71d4)();
          }
          *(int *)(iVar17 + 0x28) = iVar9;
          return true;
        }
        (*(code *)PTR_EC_KEY_free_006a71d4)(iVar9);
        uVar12 = 0x2b;
        uVar8 = 0xdec;
      }
    }
    goto LAB_00485dd4;
  case 5:
    uVar12 = 0x42;
    uVar8 = 0xdbd;
    goto LAB_00485dd4;
  case 6:
    uVar12 = 0x42;
    uVar8 = 0xdd6;
    goto LAB_00485dd4;
  case 7:
    uVar12 = 0x42;
    uVar8 = 0xdfa;
    goto LAB_00485dd4;
  case 0xe:
    iVar17 = *(int *)(param_1 + 0x94);
    if (iVar17 == 0) {
      iVar17 = (*(code *)PTR_sk_new_null_006a6fa4)();
      *(int *)(param_1 + 0x94) = iVar17;
      if (iVar17 == 0) goto switchD_00485db8_caseD_0;
    }
    (*(code *)PTR_sk_push_006a6fa8)(iVar17,param_4);
    bVar11 = true;
    break;
  case 0x36:
    *(uint **)(param_1 + 0x104) = param_4;
    bVar11 = true;
    break;
  case 0x3a:
  case 0x3b:
    if (param_4 == (uint *)0x0) {
      return (bool)0x30;
    }
    if (param_3 == 0x30) {
      if (param_2 != 0x3b) {
        uVar7 = param_1 + 0x108U & 3;
        uVar14 = param_1 + 0x10cU & 3;
        iVar17 = *(int *)((param_1 + 0x10cU) - uVar14);
        uVar15 = *(uint *)(param_1 + 0x110);
        uVar13 = *(uint *)(param_1 + 0x114);
        uVar16 = param_1 + 0x10bU & 3;
        uVar1 = param_1 + 0x10fU & 3;
        uVar3 = *(uint *)((param_1 + 0x10fU) - uVar1);
        *param_4 = (*(int *)((param_1 + 0x108U) - uVar7) << uVar7 * 8 |
                   in_t4 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar16 + 1) * 8 |
                   *(uint *)((param_1 + 0x10bU) - uVar16) >> (3 - uVar16) * 8;
        param_4[1] = (iVar17 << uVar14 * 8 | in_t3 & 0xffffffffU >> (4 - uVar14) * 8) &
                     -1 << (uVar1 + 1) * 8 | uVar3 >> (3 - uVar1) * 8;
        param_4[2] = uVar15;
        param_4[3] = uVar13;
        uVar16 = *(uint *)(param_1 + 0x11c);
        uVar14 = *(uint *)(param_1 + 0x120);
        uVar7 = *(uint *)(param_1 + 0x124);
        param_4[4] = *(uint *)(param_1 + 0x118);
        param_4[5] = uVar16;
        param_4[6] = uVar14;
        param_4[7] = uVar7;
        uVar16 = *(uint *)(param_1 + 300);
        uVar14 = *(uint *)(param_1 + 0x130);
        uVar7 = *(uint *)(param_1 + 0x134);
        param_4[8] = *(uint *)(param_1 + 0x128);
        param_4[9] = uVar16;
        param_4[10] = uVar14;
        param_4[0xb] = uVar7;
        return true;
      }
      uVar7 = (uint)param_4 & 3;
      uVar14 = (uint)(param_4 + 1) & 3;
      iVar17 = *(int *)((int)(param_4 + 1) - uVar14);
      uVar16 = (uint)(param_4 + 2) & 3;
      iVar9 = *(int *)((int)(param_4 + 2) - uVar16);
      uVar1 = (uint)(param_4 + 3) & 3;
      iVar10 = *(int *)((int)(param_4 + 3) - uVar1);
      uVar3 = (uint)(char *)((int)param_4 + 3U) & 3;
      uVar13 = (uint)(char *)((int)param_4 + 7U) & 3;
      uVar4 = *(uint *)((char *)((int)param_4 + 7U) + -uVar13);
      uVar15 = (uint)(char *)((int)param_4 + 0xbU) & 3;
      uVar5 = *(uint *)((char *)((int)param_4 + 0xbU) + -uVar15);
      uVar2 = (uint)(char *)((int)param_4 + 0xfU) & 3;
      uVar6 = *(uint *)((char *)((int)param_4 + 0xfU) + -uVar2);
      *(uint *)(param_1 + 0x108) =
           (*(int *)((int)param_4 - uVar7) << uVar7 * 8 | in_t4 & 0xffffffffU >> (4 - uVar7) * 8) &
           -1 << (uVar3 + 1) * 8 |
           *(uint *)((char *)((int)param_4 + 3U) + -uVar3) >> (3 - uVar3) * 8;
      *(uint *)(param_1 + 0x10c) =
           (iVar17 << uVar14 * 8 | in_t3 & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar13 + 1) * 8
           | uVar4 >> (3 - uVar13) * 8;
      *(uint *)(param_1 + 0x110) =
           (iVar9 << uVar16 * 8 | in_t2 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar15 + 1) * 8
           | uVar5 >> (3 - uVar15) * 8;
      *(uint *)(param_1 + 0x114) =
           (iVar10 << uVar1 * 8 | in_t1 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8 |
           uVar6 >> (3 - uVar2) * 8;
      uVar16 = param_4[5];
      uVar14 = param_4[6];
      uVar7 = param_4[7];
      *(uint *)(param_1 + 0x118) = param_4[4];
      *(uint *)(param_1 + 0x11c) = uVar16;
      *(uint *)(param_1 + 0x120) = uVar14;
      *(uint *)(param_1 + 0x124) = uVar7;
      uVar16 = param_4[9];
      uVar14 = param_4[10];
      uVar7 = param_4[0xb];
      *(uint *)(param_1 + 0x128) = param_4[8];
      *(uint *)(param_1 + 300) = uVar16;
      *(uint *)(param_1 + 0x130) = uVar14;
      *(uint *)(param_1 + 0x134) = uVar7;
      return true;
    }
    uVar12 = 0x145;
    uVar8 = 0xe0a;
LAB_00485dd4:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x85,uVar12,"s3_lib.c",uVar8);
switchD_00485db8_caseD_0:
    bVar11 = false;
    break;
  case 0x40:
    *(uint **)(param_1 + 0x140) = param_4;
    bVar11 = true;
    break;
  case 0x4e:
    bVar11 = true;
    *(uint **)(param_1 + 0x164) = param_4;
    *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) | 0x400;
    break;
  case 0x4f:
    *(uint *)(param_1 + 0x1a0) = *(uint *)(param_1 + 0x1a0) | 0x400;
    if (*(int *)(param_1 + 0x174) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    *(undefined4 *)(param_1 + 0x174) = 0;
    if (param_4 != (uint *)0x0) {
      uVar7 = (*(code *)PTR_strlen_006a9a24)(param_4);
      if ((uVar7 < 0x100) && (*(char *)param_4 != '\0')) {
        iVar17 = (*(code *)PTR_BUF_strdup_006a6fdc)(param_4);
        *(int *)(param_1 + 0x174) = iVar17;
        if (iVar17 != 0) goto LAB_004860d0;
        uVar12 = 0x44;
        uVar8 = 0xe32;
      }
      else {
        uVar12 = 0x165;
        uVar8 = 0xe2e;
      }
      goto LAB_00485dd4;
    }
    goto LAB_004860d0;
  case 0x50:
    *(int *)(param_1 + 0x19c) = param_3;
    bVar11 = true;
    break;
  case 0x51:
    *(uint **)(param_1 + 0x198) = param_4;
    bVar11 = true;
    *(code **)(param_1 + 0x170) = srp_password_from_info_cb;
    break;
  case 0x52:
    bVar11 = true;
    *param_4 = *(uint *)(param_1 + 0x94);
    break;
  case 0x53:
    if (*(int *)(param_1 + 0x94) != 0) {
      (*(code *)PTR_sk_pop_free_006a7058)(*(int *)(param_1 + 0x94),PTR_X509_free_006a6e90);
      *(undefined4 *)(param_1 + 0x94) = 0;
      return true;
    }
LAB_004860d0:
    bVar11 = true;
  }
  return bVar11;
}

