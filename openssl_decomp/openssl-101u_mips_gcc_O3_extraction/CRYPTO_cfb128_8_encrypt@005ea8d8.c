
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRYPTO_cfb128_8_encrypt
               (uint *param_1,uint *param_2,uint param_3,uint param_4,uint *param_5,
               undefined4 param_6,uint param_7,code *param_8)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint in_v1;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  code *in_t0;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  uint *puStack_54;
  undefined4 local_50;
  undefined local_4c;
  undefined3 uStack_4b;
  undefined local_48;
  undefined3 uStack_47;
  undefined local_44;
  undefined3 uStack_43;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  iVar5 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar9 = param_4;
  if (param_3 != 0) {
    puVar13 = (uint *)((int)param_1 + param_3);
    puVar14 = param_1;
    puVar15 = param_2;
    if (param_7 == 0) {
      do {
        uVar6 = (uint)param_5 & 3;
        puVar12 = (uint *)((int)puVar14 + 1);
        uVar8 = (uint)(param_5 + 1) & 3;
        uVar2 = (uint)(param_5 + 2) & 3;
        uVar3 = (uint)(param_5 + 3) & 3;
        uVar11 = (uint)(byte *)((int)param_5 + 3) & 3;
        local_50 = (code *)((*(int *)((int)param_5 - uVar6) << uVar6 * 8 |
                            (uint)in_t0 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar11 + 1) * 8 |
                           *(uint *)((byte *)((int)param_5 + 3) + -uVar11) >> (3 - uVar11) * 8);
        uVar6 = (uint)(byte *)((int)param_5 + 7) & 3;
        uVar11 = (*(int *)((int)(param_5 + 1) - uVar8) << uVar8 * 8 |
                 uVar9 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar6 + 1) * 8 |
                 *(uint *)((byte *)((int)param_5 + 7) + -uVar6) >> (3 - uVar6) * 8;
        uVar9 = (uint)(byte *)((int)param_5 + 0xb) & 3;
        uVar8 = (*(int *)((int)(param_5 + 2) - uVar2) << uVar2 * 8 |
                in_v1 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar9 + 1) * 8 |
                *(uint *)((byte *)((int)param_5 + 0xb) + -uVar9) >> (3 - uVar9) * 8;
        uVar9 = (uint)(byte *)((int)param_5 + 0xf) & 3;
        uVar6 = (*(int *)((int)(param_5 + 3) - uVar3) << uVar3 * 8 |
                param_7 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar9 + 1) * 8 |
                *(uint *)((byte *)((int)param_5 + 0xf) + -uVar9) >> (3 - uVar9) * 8;
        param_1 = param_5;
        param_2 = param_5;
        (*param_8)(param_5,param_5,param_4);
        bVar1 = *(byte *)puVar14 ^ *(byte *)param_5;
        in_t0 = (code *)(uint)bVar1;
        local_4c = (undefined)(uVar11 >> 0x18);
        uVar9 = CONCAT31(local_50._1_3_,local_4c);
        uStack_4b = (undefined3)uVar11;
        local_48 = (undefined)(uVar8 >> 0x18);
        param_3 = CONCAT31(uStack_4b,local_48);
        uStack_47 = (undefined3)uVar8;
        local_44 = (undefined)(uVar6 >> 0x18);
        in_v1 = CONCAT31(uStack_47,local_44);
        uStack_43 = (undefined3)uVar6;
        param_7 = CONCAT31(uStack_43,*(byte *)puVar14);
        *(byte *)puVar15 = bVar1;
        *param_5 = uVar9;
        param_5[1] = param_3;
        param_5[2] = in_v1;
        param_5[3] = param_7;
        puVar14 = puVar12;
        puVar15 = (uint *)((int)puVar15 + 1);
      } while (puVar12 != puVar13);
    }
    else {
      do {
        uVar6 = (uint)param_5 & 3;
        puVar12 = (uint *)((int)puVar14 + 1);
        uVar8 = (uint)(param_5 + 1) & 3;
        uVar2 = (uint)(param_5 + 2) & 3;
        uVar3 = (uint)(param_5 + 3) & 3;
        uVar11 = (uint)(byte *)((int)param_5 + 3) & 3;
        local_50 = (code *)((*(int *)((int)param_5 - uVar6) << uVar6 * 8 |
                            (uint)in_t0 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar11 + 1) * 8 |
                           *(uint *)((byte *)((int)param_5 + 3) + -uVar11) >> (3 - uVar11) * 8);
        uVar6 = (uint)(byte *)((int)param_5 + 7) & 3;
        uVar11 = (*(int *)((int)(param_5 + 1) - uVar8) << uVar8 * 8 |
                 uVar9 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar6 + 1) * 8 |
                 *(uint *)((byte *)((int)param_5 + 7) + -uVar6) >> (3 - uVar6) * 8;
        uVar9 = (uint)(byte *)((int)param_5 + 0xb) & 3;
        uVar8 = (*(int *)((int)(param_5 + 2) - uVar2) << uVar2 * 8 |
                in_v1 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar9 + 1) * 8 |
                *(uint *)((byte *)((int)param_5 + 0xb) + -uVar9) >> (3 - uVar9) * 8;
        uVar9 = (uint)(byte *)((int)param_5 + 0xf) & 3;
        uVar6 = (*(int *)((int)(param_5 + 3) - uVar3) << uVar3 * 8 |
                param_7 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar9 + 1) * 8 |
                *(uint *)((byte *)((int)param_5 + 0xf) + -uVar9) >> (3 - uVar9) * 8;
        uVar9 = uVar11;
        in_t0 = local_50;
        (*param_8)(param_5,param_5,param_4);
        bVar1 = *(byte *)puVar14 ^ *(byte *)param_5;
        param_7 = (uint)bVar1;
        local_4c = (undefined)(uVar11 >> 0x18);
        param_3 = CONCAT31(local_50._1_3_,local_4c);
        uStack_4b = (undefined3)uVar11;
        local_48 = (undefined)(uVar8 >> 0x18);
        param_2 = (uint *)CONCAT31(uStack_4b,local_48);
        uStack_47 = (undefined3)uVar8;
        local_44 = (undefined)(uVar6 >> 0x18);
        param_1 = (uint *)CONCAT31(uStack_47,local_44);
        uStack_43 = (undefined3)uVar6;
        in_v1 = CONCAT31(uStack_43,bVar1);
        *(byte *)puVar15 = bVar1;
        *param_5 = param_3;
        param_5[1] = (uint)param_2;
        param_5[2] = (uint)param_1;
        param_5[3] = in_v1;
        puVar14 = puVar12;
        puVar15 = (uint *)((int)puVar15 + 1);
      } while (puVar13 != puVar12);
    }
  }
  if (iVar5 == *(int *)puVar4) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  for (uVar6 = *puStack_54; uVar6 != 0; uVar6 = uVar6 + 1 & 0xf) {
    if (param_3 == 0) {
      if ((((uint)param_2 | (uint)param_1) & 3) != 0) goto LAB_005eabc0;
      goto LAB_005eac24;
    }
    bVar1 = *(byte *)param_1;
    param_1 = (uint *)((int)param_1 + 1);
    param_3 = param_3 - 1;
    *(byte *)param_2 = (&_gp)[uVar6] ^ bVar1;
    param_2 = (uint *)((int)param_2 + 1);
  }
  if ((((uint)param_1 | (uint)param_2) & 3) != 0) {
    puVar14 = (uint *)((int)param_1 + param_3);
    uVar6 = param_3;
    if (param_3 != 0) {
      uVar6 = 0;
      do {
        if (uVar6 == 0) {
          (*local_50)(&_gp,&_gp,uVar9);
        }
        pbVar7 = &_gp + uVar6;
        bVar1 = *(byte *)param_1;
        param_1 = (uint *)((int)param_1 + 1);
        uVar6 = uVar6 + 1 & 0xf;
        *(byte *)param_2 = *pbVar7 ^ bVar1;
        param_2 = (uint *)((int)param_2 + 1);
      } while (param_1 != puVar14);
    }
LAB_005eabc0:
    *puStack_54 = uVar6;
    return;
  }
  uVar6 = param_3;
  puVar14 = param_1;
  puVar15 = param_2;
  if (param_3 < 0x10) {
    if (param_3 != 0) {
      (*local_50)(&_gp,&_gp,uVar9);
      iVar5 = param_3 - 1;
      goto LAB_005ead2c;
    }
  }
  else {
    do {
      (*local_50)(&_gp,&_gp,uVar9);
      uVar6 = uVar6 - 0x10;
      *puVar15 = *puVar14 ^ __gp;
      puVar15[1] = puVar14[1] ^ _DAT_006aede4;
      puVar15[2] = puVar14[2] ^ _DAT_006aede8;
      puVar15[3] = puVar14[3] ^ _DAT_006aedec;
      puVar14 = puVar14 + 4;
      puVar15 = puVar15 + 4;
    } while (0xf < uVar6);
    iVar5 = (param_3 - 0x10 >> 4) + 1;
    param_2 = param_2 + iVar5 * 4;
    param_1 = param_1 + iVar5 * 4;
    if ((param_3 & 0xf) != 0) {
      iVar5 = (param_3 - 0x11) - (param_3 - 0x10 & 0xfffffff0);
      (*local_50)(&_gp,&_gp,uVar9);
LAB_005ead2c:
      uVar6 = iVar5 + 1;
      if ((uVar6 < 7 ||
           (param_2 < &DAT_006aede4 && &_gp < param_2 + 1 ||
           param_2 < param_1 + 1 && param_1 < param_2 + 1)) ||
         ((((uint)param_2 | (uint)param_1) & 3) != 0)) {
        *(byte *)param_2 = _gp ^ *(byte *)param_1;
        if (iVar5 != 0) {
          *(byte *)((int)param_2 + 1) = *(byte *)((int)param_1 + 1) ^ DAT_006aede1;
          if (iVar5 != 1) {
            *(byte *)((int)param_2 + 2) = *(byte *)((int)param_1 + 2) ^ DAT_006aede2;
            if (iVar5 != 2) {
              *(byte *)((int)param_2 + 3) = *(byte *)((int)param_1 + 3) ^ DAT_006aede3;
              if (iVar5 != 3) {
                *(byte *)(param_2 + 1) = *(byte *)(param_1 + 1) ^ DAT_006aede4;
                if (iVar5 != 4) {
                  *(byte *)((int)param_2 + 5) = *(byte *)((int)param_1 + 5) ^ DAT_006aede5;
                  if (iVar5 != 5) {
                    *(byte *)((int)param_2 + 6) = *(byte *)((int)param_1 + 6) ^ DAT_006aede6;
                    if (iVar5 != 6) {
                      *(byte *)((int)param_2 + 7) = *(byte *)((int)param_1 + 7) ^ DAT_006aede7;
                      if (iVar5 != 7) {
                        *(byte *)(param_2 + 2) = *(byte *)(param_1 + 2) ^ DAT_006aede8;
                        if (iVar5 != 8) {
                          *(byte *)((int)param_2 + 9) = *(byte *)((int)param_1 + 9) ^ DAT_006aede9;
                          if (iVar5 != 9) {
                            *(byte *)((int)param_2 + 10) =
                                 *(byte *)((int)param_1 + 10) ^ DAT_006aedea;
                            if (iVar5 != 10) {
                              *(byte *)((int)param_2 + 0xb) =
                                   *(byte *)((int)param_1 + 0xb) ^ DAT_006aedeb;
                              if (iVar5 != 0xb) {
                                *(byte *)(param_2 + 3) = *(byte *)(param_1 + 3) ^ DAT_006aedec;
                                if (iVar5 != 0xc) {
                                  *(byte *)((int)param_2 + 0xd) =
                                       *(byte *)((int)param_1 + 0xd) ^ DAT_006aeded;
                                  if (iVar5 != 0xd) {
                                    *(byte *)((int)param_2 + 0xe) =
                                         *(byte *)((int)param_1 + 0xe) ^ DAT_006aedee;
                                    *puStack_54 = uVar6;
                                    return;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        iVar10 = (iVar5 - 3U >> 2) + 1;
        *param_2 = __gp ^ *param_1;
        uVar9 = iVar10 * 4;
        if ((iVar10 != 1) && (param_2[1] = param_1[1] ^ _DAT_006aede4, iVar10 == 3)) {
          param_2[2] = param_1[2] ^ _DAT_006aede8;
        }
        iVar5 = iVar5 + iVar10 * -4;
        if (uVar6 != uVar9) {
          *(byte *)(param_2 + iVar10) = *(byte *)(param_1 + iVar10) ^ (&_gp)[uVar9];
          if (iVar5 != 0) {
            *(byte *)((int)param_2 + uVar9 + 1) =
                 *(byte *)((int)param_1 + uVar9 + 1) ^ (&DAT_006aede1)[uVar9];
            if (iVar5 != 1) {
              *(byte *)((int)param_2 + uVar9 + 2) =
                   *(byte *)((int)param_1 + uVar9 + 2) ^ (&DAT_006aede2)[uVar9];
              *puStack_54 = uVar6;
              return;
            }
          }
        }
      }
LAB_005eac24:
      *puStack_54 = uVar6;
      return;
    }
  }
  *puStack_54 = 0;
  return;
}

