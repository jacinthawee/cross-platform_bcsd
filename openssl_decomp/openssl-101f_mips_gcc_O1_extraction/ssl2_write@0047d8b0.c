
uint ssl2_write(int param_1,int param_2,uint param_3)

{
  byte bVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  undefined4 uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  
  uVar3 = (*(code *)PTR_SSL_state_006a88f4)();
  if (((uVar3 & 0x3000) != 0) && (*(int *)(param_1 + 0x1c) == 0)) {
    uVar3 = (**(code **)(param_1 + 0x20))(param_1);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    if (uVar3 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x7f,0xe5,"s2_pkt.c",0x1ad);
      return 0xffffffff;
    }
  }
  if ((*(int *)(param_1 + 0xd4) != 0) && (ssl2_write_error(param_1), *(int *)(param_1 + 0xd4) != 0))
  {
    return 0xffffffff;
  }
  puVar4 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  *puVar4 = 0;
  *(undefined4 *)(param_1 + 0x18) = 1;
  if ((int)param_3 < 1) {
    return param_3;
  }
  puVar9 = *(uint **)(param_1 + 0x54);
  uVar3 = puVar9[4];
  puVar9[4] = 0;
  param_3 = param_3 - uVar3;
  iVar15 = param_2 + uVar3;
  if (puVar9[8] != 0) goto LAB_0047da90;
  do {
    iVar10 = 3;
    uVar7 = param_3;
    if (puVar9[1] == 0) {
      uVar8 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(*(undefined4 *)(param_1 + 0x90));
      iVar16 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar8);
      if (iVar16 < 0) {
        *(uint *)(*(int *)(param_1 + 0x54) + 0x10) = uVar3;
        return 0xffffffff;
      }
      puVar9 = *(uint **)(param_1 + 0x54);
      if (puVar9[1] != 0) {
        iVar10 = iVar16 + 3;
        goto LAB_0047d970;
      }
      uVar5 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)(*(undefined4 *)(param_1 + 0x80));
      uVar13 = param_3 + iVar16;
      if (0x3fff < uVar13) {
        puVar9 = *(uint **)(param_1 + 0x54);
        uVar12 = puVar9[2];
        if (uVar12 != 0) {
LAB_0047dc84:
          if (uVar5 == 0) {
            trap(7);
          }
          uVar14 = uVar13 % uVar5;
          if (uVar14 != 0) goto LAB_0047dc98;
LAB_0047dca4:
          *puVar9 = 1;
          goto LAB_0047dc20;
        }
        *puVar9 = 0;
        if (0x7fff < uVar13) {
          uVar13 = 0x7fff;
        }
        iVar10 = iVar16 + 3;
        if (uVar5 == 0) {
          trap(7);
        }
        uVar7 = (uVar13 - uVar13 % uVar5) - iVar16;
        goto LAB_0047d988;
      }
      puVar9 = *(uint **)(param_1 + 0x54);
      uVar12 = puVar9[2];
      if (uVar5 < 2) {
        if (uVar12 != 0) goto LAB_0047dc84;
        *puVar9 = 0;
        iVar10 = iVar16 + 3;
        goto LAB_0047d988;
      }
      if (uVar5 == 0) {
        trap(7);
      }
      uVar14 = uVar13 % uVar5;
      if (uVar14 != 0) {
LAB_0047dc98:
        uVar14 = uVar5 - uVar13 % uVar5;
      }
      if (uVar12 != 0) goto LAB_0047dca4;
      *puVar9 = (uint)(uVar14 != 0);
LAB_0047dc20:
      puVar2 = PTR_memcpy_006aabf4;
      puVar9[0x12] = param_3;
      uVar5 = puVar9[0xd] + iVar16 + 3;
      puVar9[0xf] = uVar14;
      puVar9[0x15] = uVar5;
      puVar9[0x16] = puVar9[0xd] + 3;
      (*(code *)puVar2)(uVar5,iVar15,param_3);
      if (uVar14 != 0) {
        (*(code *)PTR_memset_006aab00)(*(int *)(*(int *)(param_1 + 0x54) + 0x54) + param_3,0,uVar14)
        ;
      }
    }
    else {
      iVar16 = 0;
LAB_0047d970:
      *puVar9 = 0;
      uVar7 = 0x7fff;
      if (param_3 < 0x8000) {
        uVar7 = param_3;
      }
LAB_0047d988:
      puVar2 = PTR_memcpy_006aabf4;
      puVar9[0x12] = uVar7;
      uVar14 = 0;
      uVar5 = puVar9[0xd] + iVar10;
      puVar9[0xf] = 0;
      puVar9[0x15] = uVar5;
      puVar9[0x16] = puVar9[0xd] + 3;
      (*(code *)puVar2)(uVar5,iVar15,uVar7);
    }
    piVar6 = *(int **)(param_1 + 0x54);
    if (piVar6[1] == 0) {
      piVar6[0x13] = uVar7 + uVar14;
      ssl2_mac(param_1,piVar6[0x16],1);
      *(uint *)(*(int *)(param_1 + 0x54) + 0x48) =
           uVar14 + *(int *)(*(int *)(param_1 + 0x54) + 0x48) + iVar16;
      ssl2_enc(param_1,1);
      piVar6 = *(int **)(param_1 + 0x54);
    }
    iVar10 = piVar6[0x12];
    piVar6[8] = iVar10;
    if (*piVar6 == 0) {
      iVar16 = piVar6[0x16];
      iVar11 = iVar16 + -2;
      *(byte *)(iVar16 + -2) = (byte)((uint)iVar10 >> 8) | 0x80;
      *(char *)(iVar16 + -1) = (char)*(undefined4 *)(*(int *)(param_1 + 0x54) + 0x48);
      iVar10 = *(int *)(param_1 + 0x54);
      *(int *)(iVar10 + 0x20) = *(int *)(iVar10 + 0x20) + 2;
    }
    else {
      iVar16 = piVar6[0x16];
      bVar1 = (byte)((uint)(iVar10 << 0x12) >> 0x18);
      *(byte *)(iVar16 + -3) = bVar1 >> 2;
      iVar10 = *(int *)(param_1 + 0x54);
      iVar11 = iVar16 + -3;
      if (*(int *)(iVar10 + 8) != 0) {
        *(byte *)(iVar16 + -3) = bVar1 >> 2 | 0x40;
        iVar10 = *(int *)(param_1 + 0x54);
      }
      *(char *)(iVar16 + -2) = (char)*(undefined4 *)(iVar10 + 0x48);
      *(char *)(iVar16 + -1) = (char)*(undefined4 *)(*(int *)(param_1 + 0x54) + 0x3c);
      iVar10 = *(int *)(param_1 + 0x54);
      *(int *)(iVar10 + 0x20) = *(int *)(iVar10 + 0x20) + 3;
    }
    *(int *)(iVar10 + 0x38) = iVar11;
    *(uint *)(iVar10 + 0x14) = param_3;
    *(int *)(iVar10 + 0x18) = iVar15;
    *(uint *)(iVar10 + 0x24) = uVar7;
    *(undefined4 *)(iVar10 + 0x1c) = 0;
    *(int *)(iVar10 + 0xd4) = *(int *)(iVar10 + 0xd4) + 1;
    uVar7 = write_pending(param_1,iVar15,param_3);
    while( true ) {
      if ((int)uVar7 < 1) {
        *(uint *)(*(int *)(param_1 + 0x54) + 0x10) = uVar3;
        return uVar7;
      }
      if ((param_3 == uVar7) || (param_3 = param_3 - uVar7, (*(uint *)(param_1 + 0x104) & 1) != 0))
      {
        return uVar7 + uVar3;
      }
      puVar9 = *(uint **)(param_1 + 0x54);
      uVar3 = uVar3 + uVar7;
      iVar15 = param_2 + uVar3;
      if (puVar9[8] == 0) break;
LAB_0047da90:
      uVar7 = write_pending(param_1,iVar15,param_3);
    }
  } while( true );
}

