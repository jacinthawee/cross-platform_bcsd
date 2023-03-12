
void CRYPTO_ctr128_encrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,int *param_5,
               uint *param_6,uint *param_7,code *param_8)

{
  byte bVar1;
  byte *pbVar2;
  char cVar5;
  uint uVar3;
  int iVar4;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  
  for (uVar13 = *param_7; uVar13 != 0; uVar13 = uVar13 + 1 & 0xf) {
    if (param_3 == 0) goto LAB_005eb0a4;
    bVar1 = *(byte *)param_1;
    param_1 = (uint *)((int)param_1 + 1);
    param_3 = param_3 - 1;
    *(byte *)param_2 = *(byte *)((int)param_6 + uVar13) ^ bVar1;
    param_2 = (uint *)((int)param_2 + 1);
  }
  if ((((uint)param_5 | (uint)param_1 | (uint)param_2) & 3) == 0) {
    puVar15 = param_1;
    puVar14 = param_2;
    uVar13 = param_3;
    if (0xf < param_3) {
      do {
        (*param_8)(param_5,param_6,param_4);
        uVar13 = uVar13 - 0x10;
        iVar6 = param_5[3];
        param_5[3] = iVar6 + 1;
        if (((iVar6 + 1 == 0) && (iVar6 = param_5[2], param_5[2] = iVar6 + 1, iVar6 + 1 == 0)) &&
           (iVar6 = param_5[1], param_5[1] = iVar6 + 1, iVar6 + 1 == 0)) {
          *param_5 = *param_5 + 1;
        }
        *puVar14 = *puVar15 ^ *param_6;
        puVar14[1] = puVar15[1] ^ param_6[1];
        puVar14[2] = puVar15[2] ^ param_6[2];
        puVar14[3] = puVar15[3] ^ param_6[3];
        puVar15 = puVar15 + 4;
        puVar14 = puVar14 + 4;
      } while (0xf < uVar13);
      uVar13 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      iVar6 = (uVar13 >> 4) + 1;
      param_2 = param_2 + iVar6 * 4;
      param_1 = param_1 + iVar6 * 4;
    }
    uVar13 = param_3;
    if (param_3 != 0) {
      (*param_8)(param_5,param_6,param_4);
      iVar6 = param_5[3];
      param_5[3] = iVar6 + 1;
      if (((iVar6 + 1 == 0) && (iVar6 = param_5[2], param_5[2] = iVar6 + 1, iVar6 + 1 == 0)) &&
         (iVar6 = param_5[1], param_5[1] = iVar6 + 1, iVar6 + 1 == 0)) {
        *param_5 = *param_5 + 1;
      }
      uVar9 = param_3 - 1;
      if ((param_3 < 7 ||
           (param_2 < param_6 + 1 && param_6 < param_2 + 1 ||
           param_2 < param_1 + 1 && param_1 < param_2 + 1)) ||
         ((((uint)param_2 | (uint)param_6 | (uint)param_1) & 3) != 0)) {
        puVar15 = param_1;
        do {
          puVar14 = (uint *)((int)puVar15 + 1);
          bVar1 = *(byte *)param_6;
          param_6 = (uint *)((int)param_6 + 1);
          *(byte *)param_2 = bVar1 ^ *(byte *)puVar15;
          puVar15 = puVar14;
          param_2 = (uint *)((int)param_2 + 1);
        } while (puVar14 != (uint *)((int)param_1 + param_3));
      }
      else {
        uVar7 = (param_3 - 4 >> 2) + 1;
        uVar3 = uVar7 * 4;
        if (uVar9 < 3) {
          uVar3 = 0;
        }
        else {
          uVar11 = 0;
          puVar15 = param_2;
          puVar14 = param_6;
          puVar10 = param_1;
          do {
            uVar8 = *puVar14;
            uVar11 = uVar11 + 1;
            uVar12 = *puVar10;
            puVar14 = puVar14 + 1;
            puVar10 = puVar10 + 1;
            *puVar15 = uVar8 ^ uVar12;
            puVar15 = puVar15 + 1;
          } while (uVar11 < uVar7);
          uVar9 = uVar9 + uVar7 * -4;
          if (param_3 == uVar3) goto LAB_005eb0a4;
        }
        iVar6 = uVar3 + 1;
        *(byte *)((int)param_2 + uVar3) =
             *(byte *)((int)param_6 + uVar3) ^ *(byte *)((int)param_1 + uVar3);
        if (uVar9 != 0) {
          iVar4 = uVar3 + 2;
          *(byte *)((int)param_2 + iVar6) =
               *(byte *)((int)param_1 + iVar6) ^ *(byte *)((int)param_6 + iVar6);
          if (uVar9 != 1) {
            *(byte *)((int)param_2 + iVar4) =
                 *(byte *)((int)param_6 + iVar4) ^ *(byte *)((int)param_1 + iVar4);
            *param_7 = param_3;
            return;
          }
        }
      }
    }
  }
  else {
    puVar15 = (uint *)((int)param_1 + param_3);
    if (param_3 == 0) {
      uVar13 = 0;
    }
    else {
      uVar13 = 0;
      do {
        if (uVar13 == 0) {
          (*param_8)(param_5,param_6,param_4);
          cVar5 = *(char *)((int)param_5 + 0xf) + '\x01';
          *(char *)((int)param_5 + 0xf) = cVar5;
          if ((((((cVar5 == '\0') &&
                 (cVar5 = *(char *)((int)param_5 + 0xe) + '\x01',
                 *(char *)((int)param_5 + 0xe) = cVar5, cVar5 == '\0')) &&
                (cVar5 = *(char *)((int)param_5 + 0xd) + '\x01',
                *(char *)((int)param_5 + 0xd) = cVar5, cVar5 == '\0')) &&
               ((cVar5 = *(char *)(param_5 + 3), *(char *)(param_5 + 3) = cVar5 + '\x01',
                (char)(cVar5 + '\x01') == '\0' &&
                (cVar5 = *(char *)((int)param_5 + 0xb) + '\x01',
                *(char *)((int)param_5 + 0xb) = cVar5, cVar5 == '\0')))) &&
              ((cVar5 = *(char *)((int)param_5 + 10) + '\x01', *(char *)((int)param_5 + 10) = cVar5,
               cVar5 == '\0' &&
               ((cVar5 = *(char *)((int)param_5 + 9) + '\x01', *(char *)((int)param_5 + 9) = cVar5,
                cVar5 == '\0' &&
                (cVar5 = *(char *)(param_5 + 2), *(char *)(param_5 + 2) = cVar5 + '\x01',
                (char)(cVar5 + '\x01') == '\0')))))) &&
             ((cVar5 = *(char *)((int)param_5 + 7) + '\x01', *(char *)((int)param_5 + 7) = cVar5,
              cVar5 == '\0' &&
              (((((cVar5 = *(char *)((int)param_5 + 6) + '\x01', *(char *)((int)param_5 + 6) = cVar5
                  , cVar5 == '\0' &&
                  (cVar5 = *(char *)((int)param_5 + 5) + '\x01', *(char *)((int)param_5 + 5) = cVar5
                  , cVar5 == '\0')) &&
                 (cVar5 = *(char *)(param_5 + 1), *(char *)(param_5 + 1) = cVar5 + '\x01',
                 (char)(cVar5 + '\x01') == '\0')) &&
                ((cVar5 = *(char *)((int)param_5 + 3) + '\x01', *(char *)((int)param_5 + 3) = cVar5,
                 cVar5 == '\0' &&
                 (cVar5 = *(char *)((int)param_5 + 2) + '\x01', *(char *)((int)param_5 + 2) = cVar5,
                 cVar5 == '\0')))) &&
               (cVar5 = *(char *)((int)param_5 + 1) + '\x01', *(char *)((int)param_5 + 1) = cVar5,
               cVar5 == '\0')))))) {
            *(char *)param_5 = *(char *)param_5 + '\x01';
          }
        }
        pbVar2 = (byte *)((int)param_6 + uVar13);
        bVar1 = *(byte *)param_1;
        param_1 = (uint *)((int)param_1 + 1);
        uVar13 = uVar13 + 1 & 0xf;
        *(byte *)param_2 = *pbVar2 ^ bVar1;
        param_2 = (uint *)((int)param_2 + 1);
      } while (param_1 != puVar15);
    }
  }
LAB_005eb0a4:
  *param_7 = uVar13;
  return;
}

