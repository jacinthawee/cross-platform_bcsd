
int ssl_get_server_send_cert(int param_1,undefined4 param_2,int *param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  undefined *puVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  uint uVar16;
  ASN1_OBJECT *o;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  bool bVar26;
  uint uVar25;
  int local_3c;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar12 = PTR___stack_chk_guard_006a9ae8;
  iVar13 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  local_34 = 0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar24 = *(int *)(param_1 + 0x98);
  if (iVar24 != 0) {
    iVar20 = 0x400;
    if ((*(uint *)(iVar13 + 0x20) & 8) != 0) {
      iVar20 = 0x200;
    }
    if (*(int *)(iVar24 + 0x18) == 0) {
      bVar26 = *(int *)(iVar24 + 0x1c) != 0;
      bVar4 = bVar26;
      if (*(int *)(iVar24 + 0x20) == 0) goto LAB_004aac28;
LAB_004aa718:
      if (*(int *)(iVar24 + 0x24) == 0) {
        iVar13 = (*(code *)PTR_DH_size_006a8348)();
        bVar5 = iVar13 << 3 <= iVar20;
      }
      else {
        bVar5 = true;
      }
      bVar10 = true;
      if (*(int *)(iVar24 + 0x28) != 0) goto LAB_004aa738;
LAB_004aac3c:
      bVar9 = *(int *)(iVar24 + 0x2c) != 0;
    }
    else {
      if (*(int *)(iVar24 + 0x1c) == 0) {
        iVar13 = (*(code *)PTR_RSA_size_006a7640)();
        bVar4 = iVar13 << 3 <= iVar20;
      }
      else {
        bVar4 = true;
      }
      bVar26 = true;
      if (*(int *)(iVar24 + 0x20) != 0) goto LAB_004aa718;
LAB_004aac28:
      bVar5 = *(int *)(iVar24 + 0x24) != 0;
      bVar10 = bVar5;
      if (*(int *)(iVar24 + 0x28) == 0) goto LAB_004aac3c;
LAB_004aa738:
      bVar9 = true;
    }
    if ((*(int *)(iVar24 + 0x30) == 0) || (*(int *)(iVar24 + 0x34) == 0)) {
      uVar23 = 0;
      bVar1 = false;
      if (*(int *)(iVar24 + 0x3c) != 0) goto LAB_004aa778;
LAB_004aabec:
      bVar6 = false;
      if (*(int *)(iVar24 + 0x48) == 0) goto LAB_004aabf8;
LAB_004aa790:
      bVar7 = *(int *)(iVar24 + 0x4c) != 0;
    }
    else {
      uVar23 = 1;
      iVar13 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
      bVar1 = iVar13 << 3 <= iVar20;
      if (*(int *)(iVar24 + 0x3c) == 0) goto LAB_004aabec;
LAB_004aa778:
      bVar6 = *(int *)(iVar24 + 0x40) != 0;
      if (*(int *)(iVar24 + 0x48) != 0) goto LAB_004aa790;
LAB_004aabf8:
      bVar7 = false;
    }
    param_3 = (int *)0x0;
    if ((*(int *)(iVar24 + 0x54) == 0) || (*(int *)(iVar24 + 0x58) == 0)) {
      bVar2 = false;
    }
    else {
      iVar13 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
      param_3 = (int *)0x1;
      bVar2 = iVar13 << 3 <= iVar20;
    }
    if ((*(int *)(iVar24 + 0x60) == 0) || (*(int *)(iVar24 + 100) == 0)) {
      iVar13 = *(int *)(iVar24 + 0x6c);
      bVar11 = false;
      bVar3 = false;
      if (iVar13 != 0) goto LAB_004aa818;
LAB_004aaba8:
      bVar8 = false;
      if (*(int *)(iVar24 + 0x84) == 0) goto LAB_004aabb4;
LAB_004aa828:
      uVar19 = 0x100;
      if (*(int *)(iVar24 + 0x88) != 0) {
        uVar19 = 0x300;
      }
      uVar18 = 0x200;
      if (*(int *)(iVar24 + 0x88) == 0) {
        uVar18 = 0;
      }
      if (*(int *)(iVar24 + 0x78) != 0) goto LAB_004aa84c;
LAB_004aabc4:
      uVar19 = uVar18;
      if (uVar23 != 0) goto LAB_004aa870;
LAB_004aa860:
      if ((bVar26) && (bVar6)) goto LAB_004aa870;
    }
    else {
      iVar14 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
      bVar11 = true;
      iVar13 = *(int *)(iVar24 + 0x6c);
      bVar3 = iVar14 << 3 <= iVar20;
      if (iVar13 == 0) goto LAB_004aaba8;
LAB_004aa818:
      bVar8 = *(int *)(iVar24 + 0x70) != 0;
      if (*(int *)(iVar24 + 0x84) != 0) goto LAB_004aa828;
LAB_004aabb4:
      uVar19 = 0x100;
      uVar18 = 0;
      if (*(int *)(iVar24 + 0x78) == 0) goto LAB_004aabc4;
LAB_004aa84c:
      if (*(int *)(iVar24 + 0x7c) == 0) {
        uVar19 = uVar18;
      }
      if (*(int *)(iVar24 + 0x7c) != 0) {
        uVar18 = 0x200;
      }
      if (uVar23 == 0) goto LAB_004aa860;
LAB_004aa870:
      uVar18 = uVar18 | 1;
    }
    if (bVar1) {
      if (bVar10) {
        uVar18 = uVar18 | 8;
      }
      uVar25 = 1;
      if (bVar5) {
        uVar25 = 9;
      }
      if (bVar2) {
        uVar25 = uVar25 | 2;
      }
      if (param_3 != (int *)0x0) {
        uVar18 = uVar18 | 2;
      }
      if (bVar3) {
        uVar25 = uVar25 | 4;
      }
      if (bVar11) {
        uVar18 = uVar18 | 4;
      }
      if (uVar23 == 0) goto LAB_004aa8cc;
LAB_004aa9ec:
      uVar19 = uVar19 | 1;
      uVar16 = 5;
      uVar21 = 7;
      uVar17 = 3;
      uVar23 = 1;
      if (!bVar7) goto LAB_004aaa04;
LAB_004aa8ec:
      uVar22 = uVar19 | 6;
      uVar19 = uVar19 | 2;
      uVar23 = uVar17;
      uVar16 = uVar21;
    }
    else {
      uVar25 = 0;
      if ((bVar4) && (uVar25 = 1, !bVar6)) {
        uVar25 = uVar23;
      }
      if (bVar5) {
        uVar25 = uVar25 | 8;
      }
      if (bVar10) {
        uVar18 = uVar18 | 8;
      }
      if (bVar2) {
        uVar25 = uVar25 | 2;
      }
      if (param_3 != (int *)0x0) {
        uVar18 = uVar18 | 2;
      }
      if (bVar3) {
        uVar25 = uVar25 | 4;
      }
      if (bVar11) {
        uVar18 = uVar18 | 4;
      }
      if (uVar23 != 0) goto LAB_004aa9ec;
LAB_004aa8cc:
      if (bVar6) goto LAB_004aa9ec;
      uVar16 = 4;
      uVar21 = 6;
      uVar17 = 2;
      uVar23 = 0;
      if (bVar7) goto LAB_004aa8ec;
LAB_004aaa04:
      uVar22 = uVar19 | 4;
    }
    if (bVar8) {
      param_3 = (int *)0x0;
      (*(code *)PTR_X509_check_purpose_006a771c)(iVar13,0xffffffff);
      if ((*(uint *)(iVar13 + 0x28) & 2) == 0) {
        uVar21 = 1;
        uVar17 = 1;
      }
      else {
        uVar21 = *(uint *)(iVar13 + 0x2c) & 8;
        uVar17 = *(uint *)(iVar13 + 0x2c) & 0x80;
      }
      iVar20 = (*(code *)PTR_X509_get_pubkey_006a6f08)(iVar13);
      if (iVar20 == 0) {
        local_3c = 0;
      }
      else {
        local_3c = (*(code *)PTR_EVP_PKEY_bits_006a6fe4)(iVar20);
      }
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar20);
      if ((*(ASN1_OBJECT ***)(iVar13 + 4) != (ASN1_OBJECT **)0x0) &&
         (o = **(ASN1_OBJECT ***)(iVar13 + 4), o != (ASN1_OBJECT *)0x0)) {
        iVar13 = OBJ_obj2nid(o);
        param_3 = &local_34;
        OBJ_find_sigid_algs(iVar13,&local_30,param_3);
      }
      if (uVar21 != 0) {
        if ((local_34 == 6) || (local_34 == 0x13)) {
          uVar18 = uVar18 | 0x20;
          uVar22 = uVar19 | 0x14;
          if (local_3c < 0xa4) {
            uVar25 = uVar25 | 0x20;
            uVar16 = uVar23 | 0x14;
            goto LAB_004aab4c;
          }
        }
        if (local_34 == 0x198) {
          uVar18 = uVar18 | 0x40;
          uVar22 = uVar22 | 0x10;
          if (local_3c < 0xa4) {
            uVar25 = uVar25 | 0x40;
            uVar16 = uVar16 | 0x10;
          }
        }
      }
LAB_004aab4c:
      if (uVar17 != 0) {
        uVar22 = uVar22 | 0x40;
        uVar16 = uVar16 | 0x40;
      }
    }
    if (bVar9) {
      uVar18 = uVar18 | 0x80;
      uVar25 = uVar25 | 0x80;
    }
    iVar13 = *(int *)(param_1 + 0x58);
    *(uint *)(iVar24 + 8) = uVar18 | 0x100;
    *(uint *)(iVar24 + 0xc) = uVar22 | 0x80;
    *(uint *)(iVar24 + 0x10) = uVar25 | 0x100;
    *(uint *)(iVar24 + 0x14) = uVar16 | 0x80;
    *(undefined4 *)(iVar24 + 4) = 1;
    iVar13 = *(int *)(iVar13 + 0x344);
  }
  uVar23 = *(uint *)(iVar13 + 0xc);
  uVar19 = uVar23 & 0x60;
  if (uVar19 == 0) {
    uVar18 = *(uint *)(iVar13 + 0x10);
    uVar19 = uVar23 & 2;
    if ((uVar18 & 0x40) != 0) goto LAB_004aa960;
    if (uVar19 != 0) {
      iVar13 = 0x24;
      goto LAB_004aa964;
    }
    if ((uVar23 & 4) != 0) {
      iVar13 = 0x30;
      goto LAB_004aa964;
    }
    if ((uVar18 & 2) != 0) {
      iVar13 = 0x18;
      goto LAB_004aa964;
    }
    if ((uVar18 & 1) != 0) {
      iVar13 = (uint)(*(int *)(iVar24 + 0x30) == 0) * 0xc;
      goto LAB_004aa964;
    }
    if ((uVar18 & 0x20) == 0) {
      if ((uVar18 & 0x100) == 0) {
        iVar13 = 0x54;
        if ((uVar18 & 0x200) == 0) {
          param_3 = (int *)0x44;
          uVar19 = 0x13d;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13d,0x44,"ssl_lib.c",0x944);
          goto LAB_004aad20;
        }
      }
      else {
        iVar13 = 0x48;
      }
      goto LAB_004aa964;
    }
LAB_004aad20:
    iVar13 = 0;
  }
  else {
LAB_004aa960:
    iVar13 = 0x3c;
LAB_004aa964:
    piVar15 = (int *)(iVar24 + 0x30 + iVar13);
    iVar13 = 0;
    if (piVar15 != (int *)0x0) {
      iVar13 = *piVar15;
    }
  }
  if (local_2c == *(int *)puVar12) {
    return iVar13;
  }
  iVar13 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar23 = *(uint *)(uVar19 + 0x10);
  iVar13 = *(int *)(iVar13 + 0x98);
  if (((uVar23 & 2) == 0) || (iVar24 = *(int *)(iVar13 + 0x4c), iVar24 == 0)) {
    if ((uVar23 & 1) == 0) {
      if ((uVar23 & 0x40) != 0) {
        iVar24 = *(int *)(iVar13 + 0x70);
        iVar20 = 5;
        if (iVar24 != 0) goto LAB_004aad70;
      }
LAB_004aaddc:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb7,0x44,"ssl_lib.c",0x96a);
      return 0;
    }
    iVar24 = *(int *)(iVar13 + 0x40);
    iVar20 = 1;
    if (iVar24 == 0) {
      iVar24 = *(int *)(iVar13 + 0x34);
      iVar20 = 0;
      if (iVar24 == 0) goto LAB_004aaddc;
    }
  }
  else {
    iVar20 = 2;
  }
LAB_004aad70:
  if (param_3 != (int *)0x0) {
    iVar13 = iVar13 + iVar20 * 0xc;
    *param_3 = *(int *)(iVar13 + 0x38);
    iVar24 = *(int *)(iVar13 + 0x34);
  }
  return iVar24;
}

