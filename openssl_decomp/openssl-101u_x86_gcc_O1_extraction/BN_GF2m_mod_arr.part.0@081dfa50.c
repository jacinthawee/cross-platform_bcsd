
undefined4 __regparm3 BN_GF2m_mod_arr_part_0(uint **param_1,int *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  
  iVar5 = *param_2;
  puVar1 = *param_1;
  iVar6 = iVar5 + 0x1f;
  if (-1 < iVar5) {
    iVar6 = iVar5;
  }
  puVar3 = (uint *)(iVar6 >> 5);
  puVar2 = param_1[1];
  while (puVar2 = (uint *)((int)puVar2 + -1), (int)puVar3 < (int)puVar2) {
    while( true ) {
      uVar8 = puVar1[(int)puVar2];
      if (uVar8 == 0) break;
      puVar1[(int)puVar2] = 0;
      iVar5 = param_2[1];
      piVar9 = param_2 + 2;
      while (iVar5 != 0) {
        iVar5 = *param_2 - iVar5;
        iVar6 = iVar5;
        if (iVar5 < 0) {
          iVar6 = iVar5 + 0x1f;
        }
        iVar6 = (int)puVar2 - (iVar6 >> 5);
        bVar4 = (byte)(iVar5 % 0x20);
        puVar1[iVar6] = puVar1[iVar6] ^ uVar8 >> (bVar4 & 0x1f);
        if (iVar5 % 0x20 != 0) {
          puVar1[iVar6 + -1] = puVar1[iVar6 + -1] ^ uVar8 << (0x20 - bVar4 & 0x1f);
        }
        iVar5 = *piVar9;
        piVar9 = piVar9 + 1;
      }
      iVar5 = *param_2;
      bVar4 = (byte)(iVar5 % 0x20);
      puVar1[(int)puVar2 - (int)puVar3] =
           puVar1[(int)puVar2 - (int)puVar3] ^ uVar8 >> (bVar4 & 0x1f);
      if (iVar5 % 0x20 != 0) {
        puVar1[((int)puVar2 - (int)puVar3) + -1] =
             puVar1[((int)puVar2 - (int)puVar3) + -1] ^ uVar8 << (0x20 - bVar4 & 0x1f);
      }
      if ((int)puVar2 <= (int)puVar3) goto LAB_081dfb50;
    }
  }
LAB_081dfb50:
  if (puVar3 == puVar2) {
    puVar3 = puVar1 + (int)puVar3;
    iVar5 = *param_2 % 0x20;
    uVar8 = *puVar3;
    uVar10 = uVar8 >> ((byte)iVar5 & 0x1f);
    while (uVar10 != 0) {
      uVar7 = 0;
      if (iVar5 != 0) {
        bVar4 = 0x20 - (char)iVar5;
        uVar7 = (uVar8 << (bVar4 & 0x1f)) >> (bVar4 & 0x1f);
      }
      *puVar3 = uVar7;
      *puVar1 = *puVar1 ^ uVar10;
      iVar5 = param_2[1];
      if (iVar5 != 0) {
        piVar9 = param_2 + 2;
        do {
          iVar6 = iVar5;
          if (iVar5 < 0) {
            iVar6 = iVar5 + 0x1f;
          }
          bVar4 = (byte)(iVar5 % 0x20);
          puVar1[iVar6 >> 5] = puVar1[iVar6 >> 5] ^ uVar10 << (bVar4 & 0x1f);
          uVar8 = uVar10 >> (0x20 - bVar4 & 0x1f);
          if ((iVar5 % 0x20 != 0) && (uVar8 != 0)) {
            puVar1[(iVar6 >> 5) + 1] = puVar1[(iVar6 >> 5) + 1] ^ uVar8;
          }
          iVar5 = *piVar9;
          piVar9 = piVar9 + 1;
        } while (iVar5 != 0);
      }
      iVar5 = *param_2 % 0x20;
      uVar8 = *puVar3;
      uVar10 = uVar8 >> ((byte)iVar5 & 0x1f);
    }
  }
  puVar3 = param_1[1];
  if (0 < (int)puVar3) {
    do {
      if (puVar1[(int)puVar3 + -1] != 0) break;
      puVar3 = (uint *)((int)puVar3 + -1);
    } while (puVar3 != (uint *)0x0);
    param_1[1] = puVar3;
  }
  return 1;
}

