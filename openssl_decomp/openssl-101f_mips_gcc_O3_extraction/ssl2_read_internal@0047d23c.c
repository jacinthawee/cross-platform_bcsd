
char * ssl2_read_internal(int param_1,char *param_2,char *param_3,int param_4)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  char **ppcVar10;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  ushort *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  char *pcVar18;
  char *pcVar19;
  undefined auStack_40 [20];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar11 = param_2;
  pcVar13 = param_3;
  while( true ) {
    uVar4 = (*(code *)PTR_SSL_state_006a88f4)(param_1);
    if (((uVar4 & 0x3000) != 0) && (*(int *)(param_1 + 0x1c) == 0)) {
      pcVar6 = (char *)(**(code **)(param_1 + 0x20))(param_1);
      if ((int)pcVar6 < 0) goto LAB_0047d63c;
      if (pcVar6 == (char *)0x0) {
        pcVar13 = (char *)0xe5;
        uVar7 = 0x8e;
        goto LAB_0047d6ac;
      }
    }
    puVar5 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
    *puVar5 = 0;
    *(undefined4 *)(param_1 + 0x18) = 1;
    pcVar6 = param_3;
    if ((int)param_3 < 1) goto LAB_0047d63c;
    ppcVar10 = *(char ***)(param_1 + 0x54);
    pcVar18 = ppcVar10[0x11];
    if (pcVar18 != (char *)0x0) {
      if ((int)pcVar18 < (int)param_3) {
        pcVar6 = pcVar18;
      }
      pcVar11 = ppcVar10[0x14];
      pcVar13 = pcVar6;
      (*(code *)PTR_memcpy_006aabf4)(param_2);
      if (param_4 == 0) {
        iVar15 = *(int *)(param_1 + 0x54);
        iVar16 = *(int *)(iVar15 + 0x44) - (int)pcVar6;
        *(int *)(iVar15 + 0x44) = iVar16;
        *(char **)(iVar15 + 0x50) = pcVar6 + *(int *)(iVar15 + 0x50);
        if (iVar16 == 0) {
          *(undefined4 *)(param_1 + 0x38) = 0xf0;
        }
      }
      goto LAB_0047d63c;
    }
    if (*(int *)(param_1 + 0x38) == 0xf0) {
      pcVar13 = (char *)0x8001;
      if (*(int *)(param_1 + 0x10c) == 0) {
        pcVar11 = (char *)0x2;
        pcVar6 = (char *)read_n(param_1,2,0x8001,0);
        if ((int)pcVar6 < 1) goto LAB_0047d63c;
        puVar14 = *(ushort **)(param_1 + 0x4c);
        ppcVar10 = *(char ***)(param_1 + 0x54);
        *(undefined4 *)(param_1 + 0x38) = 0xf1;
        ppcVar10[2] = (char *)0x0;
        pcVar6 = (char *)(uint)*puVar14;
        ppcVar10[0x10] = pcVar6;
        bVar1 = *(byte *)puVar14;
      }
      else {
        pcVar11 = (char *)0x5;
        pcVar6 = (char *)read_n(param_1,5,0x8001,0);
        if ((int)pcVar6 < 1) goto LAB_0047d63c;
        puVar14 = *(ushort **)(param_1 + 0x4c);
        *(undefined4 *)(param_1 + 0x10c) = 0;
        if ((-1 < (char)*(byte *)puVar14) ||
           ((*(byte *)(puVar14 + 1) != 1 && (*(byte *)(puVar14 + 1) != 4)))) {
          pcVar13 = (char *)0xaf;
          uVar7 = 0xbb;
          goto LAB_0047d6ac;
        }
        ppcVar10 = *(char ***)(param_1 + 0x54);
        *(undefined4 *)(param_1 + 0x38) = 0xf1;
        ppcVar10[2] = (char *)0x0;
        pcVar6 = (char *)(uint)*puVar14;
        ppcVar10[0x10] = pcVar6;
        bVar1 = *(byte *)puVar14;
      }
      if ((char)bVar1 < '\0') {
        pcVar11 = (char *)0x1;
        pcVar6 = (char *)((uint)pcVar6 & 0x7fff);
        *ppcVar10 = (char *)0x0;
        pcVar19 = (char *)0x0;
        ppcVar10[0x10] = pcVar6;
      }
      else {
        pcVar6 = (char *)((uint)pcVar6 & 0x3fff);
        pcVar19 = (char *)0x1;
        *ppcVar10 = (char *)0x1;
        pcVar18 = (char *)0x1;
        ppcVar10[0x10] = pcVar6;
        pcVar11 = (char *)(((uint)*(byte *)puVar14 << 0x19) >> 0x1f);
        ppcVar10[2] = pcVar11;
      }
    }
    else {
      if (*(int *)(param_1 + 0x38) != 0xf1) {
        pcVar13 = (char *)0x7e;
        uVar7 = 0x12f;
        goto LAB_0047d6ac;
      }
      pcVar19 = *ppcVar10;
      pcVar6 = ppcVar10[0x10];
      pcVar18 = pcVar19;
    }
    pcVar13 = *(char **)(param_1 + 0x50);
    if ((int)pcVar13 < (int)(pcVar6 + (int)pcVar19 + 2)) {
      pcVar11 = pcVar6 + (int)pcVar19 + 2 + -(int)pcVar13;
      pcVar13 = pcVar11;
      pcVar6 = (char *)read_n(param_1,pcVar11,pcVar11,1);
      if ((int)pcVar6 < 1) goto LAB_0047d63c;
      ppcVar10 = *(char ***)(param_1 + 0x54);
      pcVar18 = *ppcVar10;
    }
    iVar16 = *(int *)(param_1 + 0x4c);
    *(undefined4 *)(param_1 + 0x38) = 0xf0;
    if (pcVar18 != (char *)0x0) break;
    pcVar6 = (char *)(iVar16 + 2);
    ppcVar10[0xf] = (char *)0x0;
    if (ppcVar10[1] != (char *)0x0) {
      ppcVar10[0x16] = pcVar6;
      ppcVar10[0x14] = pcVar6;
      goto LAB_0047d35c;
    }
LAB_0047d454:
    uVar7 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(*(undefined4 *)(param_1 + 0x84));
    pcVar18 = (char *)(*(code *)PTR_EVP_MD_size_006a8f2c)(uVar7);
    if ((int)pcVar18 < 0) {
      pcVar6 = (char *)0xffffffff;
      goto LAB_0047d63c;
    }
    if (0x14 < (int)pcVar18) {
      pcVar13 = "mac_size <= MAX_MAC_SIZE";
      (*(code *)PTR_OpenSSLDie_006a8d4c)("s2_pkt.c",0xfc);
    }
    ppcVar10 = *(char ***)(param_1 + 0x54);
    pcVar11 = pcVar6 + (int)pcVar18;
    ppcVar10[0x16] = pcVar6;
    pcVar6 = ppcVar10[0x10];
    ppcVar10[0x14] = pcVar11;
    if (pcVar6 < pcVar18 + (int)ppcVar10[0xf]) {
      pcVar13 = (char *)0x11b;
      uVar7 = 0x101;
      goto LAB_0047d6ac;
    }
    ppcVar10[0x11] = pcVar6;
    if ((ppcVar10[1] == (char *)0x0) && (pcVar18 <= pcVar6)) {
      ssl2_enc(param_1,0);
      *(int *)(*(int *)(param_1 + 0x54) + 0x44) =
           *(int *)(*(int *)(param_1 + 0x54) + 0x44) - (int)pcVar18;
      ssl2_mac(param_1,auStack_40,0);
      puVar3 = PTR_CRYPTO_memcmp_006a9088;
      iVar16 = *(int *)(param_1 + 0x54);
      pcVar11 = *(char **)(iVar16 + 0x58);
      *(int *)(iVar16 + 0x44) = *(int *)(iVar16 + 0x44) - *(int *)(iVar16 + 0x3c);
      iVar16 = (*(code *)puVar3)(auStack_40);
      if (iVar16 == 0) {
        uVar17 = *(uint *)(*(int *)(param_1 + 0x54) + 0x40);
        uVar4 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)(*(undefined4 *)(param_1 + 0x80));
        if (uVar4 == 0) {
          trap(7);
        }
        if (uVar17 % uVar4 == 0) {
          ppcVar10 = *(char ***)(param_1 + 0x54);
          pcVar13 = pcVar18;
          goto LAB_0047d364;
        }
      }
      pcVar13 = (char *)0x71;
      uVar7 = 0x113;
      goto LAB_0047d6ac;
    }
LAB_0047d364:
    ppcVar10[0x34] = ppcVar10[0x34] + 1;
  }
  bVar1 = *(byte *)(iVar16 + 2);
  pcVar6 = (char *)(iVar16 + 3);
  ppcVar10[0xf] = (char *)(uint)bVar1;
  if (ppcVar10[1] == (char *)0x0) goto LAB_0047d454;
  ppcVar10[0x16] = pcVar6;
  ppcVar10[0x14] = pcVar6;
  if ((char *)(uint)bVar1 == (char *)0x0) {
LAB_0047d35c:
    ppcVar10[0x11] = ppcVar10[0x10];
    goto LAB_0047d364;
  }
  pcVar13 = (char *)0x11b;
  uVar7 = 0xf3;
LAB_0047d6ac:
  pcVar11 = (char *)0xec;
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xec,pcVar13,"s2_pkt.c",uVar7);
  pcVar6 = (char *)0xffffffff;
LAB_0047d63c:
  if (local_2c == *(int *)puVar2) {
    return pcVar6;
  }
  iVar16 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar15 = *(int *)(iVar16 + 0x54);
  if (((int)pcVar13 < *(int *)(iVar15 + 0x14)) ||
     ((*(char **)(iVar15 + 0x18) != pcVar11 && ((*(uint *)(iVar16 + 0x104) & 2) == 0)))) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd4,0x7f,"s2_pkt.c",0x1e0);
    pcVar11 = (char *)0xffffffff;
  }
  else {
    puVar5 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
    while( true ) {
      puVar2 = PTR_BIO_write_006a7f14;
      iVar9 = *(int *)(iVar16 + 0x10);
      *puVar5 = 0;
      if (iVar9 == 0) break;
      iVar12 = *(int *)(iVar15 + 0x38);
      iVar8 = *(int *)(iVar15 + 0x1c);
      uVar7 = *(undefined4 *)(iVar15 + 0x20);
      *(undefined4 *)(iVar16 + 0x18) = 2;
      pcVar11 = (char *)(*(code *)puVar2)(iVar9,iVar12 + iVar8,uVar7);
      iVar15 = *(int *)(iVar16 + 0x54);
      if (pcVar11 == *(char **)(iVar15 + 0x20)) goto LAB_0047d830;
      if ((int)pcVar11 < 1) {
        return pcVar11;
      }
      *(int *)(iVar15 + 0x20) = (int)*(char **)(iVar15 + 0x20) - (int)pcVar11;
      *(char **)(iVar15 + 0x1c) = pcVar11 + *(int *)(iVar15 + 0x1c);
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd4,0x104,"s2_pkt.c",0x1f0);
    iVar15 = *(int *)(iVar16 + 0x54);
    if (*(int *)(iVar15 + 0x20) != -1) {
      return (char *)0xffffffff;
    }
LAB_0047d830:
    pcVar11 = *(char **)(iVar15 + 0x24);
    *(undefined4 *)(iVar15 + 0x20) = 0;
    *(undefined4 *)(iVar16 + 0x18) = 1;
  }
  return pcVar11;
}

