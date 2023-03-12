
/* WARNING: Heritage AFTER dead removal. Example location: r0x006a9ab0 : 0x005ea8cc */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void CRYPTO_cfb128_1_encrypt
               (uint *param_1,uint *param_2,uint *param_3,uint *param_4,byte *param_5,
               undefined4 param_6,int param_7,code *param_8)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint in_t0;
  uint uVar11;
  uint uVar12;
  uint in_t1;
  uint uVar13;
  byte *pbVar14;
  uint *puVar15;
  uint *puVar16;
  uint *puVar17;
  uint *puVar18;
  uint uVar19;
  uint uVar20;
  uint *puVar21;
  uint *puVar22;
  uint uVar23;
  uint *puVar24;
  uint **ppuStack_10c;
  undefined4 uStack_108;
  undefined uStack_104;
  undefined3 uStack_103;
  undefined uStack_100;
  undefined3 uStack_ff;
  undefined uStack_fc;
  undefined3 uStack_fb;
  uint *local_a8;
  int iStack_a0;
  uint *local_9c;
  char local_50;
  byte bStack_4f;
  byte bStack_47;
  byte bStack_46;
  char cStack_45;
  byte local_44;
  byte bStack_43;
  byte bStack_42;
  char cStack_41;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_a8 = (uint *)&_gp;
  iVar3 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar7 = param_1;
  puVar8 = param_2;
  puVar15 = param_3;
  puVar9 = param_4;
  if (param_3 != (uint *)0x0) {
    puVar16 = (uint *)0x0;
    pcVar5 = param_8;
    do {
      uVar4 = (uint)(param_5 + 4) & 3;
      uVar20 = ~(uint)puVar16;
      uVar6 = (uint)param_5 & 3;
      uVar10 = (uint)(param_5 + 8) & 3;
      uVar11 = (uint)(param_5 + 0xc) & 3;
      uVar19 = 0x80;
      uVar12 = (uint)(param_5 + 7) & 3;
      uVar12 = (*(int *)(param_5 + 4 + -uVar4) << uVar4 * 8 | in_t0 & 0xffffffffU >> (4 - uVar4) * 8
               ) & -1 << (uVar12 + 1) * 8 | *(uint *)(param_5 + 7 + -uVar12) >> (3 - uVar12) * 8;
      uVar4 = (uint)(param_5 + 3) & 3;
      uVar13 = (*(int *)(param_5 + -uVar6) << uVar6 * 8 | in_t1 & 0xffffffffU >> (4 - uVar6) * 8) &
               -1 << (uVar4 + 1) * 8 | *(uint *)(param_5 + 3 + -uVar4) >> (3 - uVar4) * 8;
      uVar4 = (uint)(param_5 + 0xb) & 3;
      uVar10 = (*(int *)(param_5 + 8 + -uVar10) << uVar10 * 8 |
               (uint)puVar9 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar4 + 1) * 8 |
               *(uint *)(param_5 + 0xb + -uVar4) >> (3 - uVar4) * 8;
      uVar4 = (uint)(param_5 + 0xf) & 3;
      uVar6 = (*(int *)(param_5 + 0xc + -uVar11) << uVar11 * 8 |
              (uint)pcVar5 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar4 + 1) * 8 |
              *(uint *)(param_5 + 0xf + -uVar4) >> (3 - uVar4) * 8;
      uVar4 = (int)(uint)*(byte *)((int)param_1 + ((uint)puVar16 >> 3)) >> (uVar20 & 7) & 1;
      local_9c = (uint *)(uint)(uVar4 != 0);
      if (uVar4 == 0) {
        uVar19 = 0;
      }
      (*param_8)(param_5,param_5,param_4);
      if (param_7 == 0) {
        uVar19 = uVar19 ^ *param_5;
      }
      else {
        uVar19 = uVar19 ^ *param_5;
        local_9c = (uint *)(uVar19 >> 7);
      }
      uVar4 = uVar13 >> 8 & 0xff;
      pbVar14 = (byte *)((int)param_2 + ((uint)puVar16 >> 3));
      bStack_4f = (byte)(uVar13 >> 0x10);
      uVar23 = uVar12 >> 0x10 & 0xff;
      local_44 = (byte)(uVar6 >> 0x18);
      local_50 = (char)(uVar13 >> 0x18);
      cStack_41 = (char)uVar6;
      uVar11 = uVar12 >> 8 & 0xff;
      bStack_46 = (byte)(uVar10 >> 8);
      puVar9 = (uint *)((int)(uVar6 & 0xff) >> 7);
      bStack_47 = (byte)(uVar10 >> 0x10);
      cStack_45 = (char)uVar10;
      bStack_43 = (byte)(uVar6 >> 0x10);
      bStack_42 = (byte)(uVar6 >> 8);
      *param_5 = local_50 << 1 | (byte)((int)(uint)bStack_4f >> 7);
      param_5[1] = bStack_4f << 1 | (byte)((int)uVar4 >> 7);
      param_5[9] = bStack_47 << 1 | (byte)((int)(uint)bStack_46 >> 7);
      in_t1 = (uVar13 & 0xff) << 1 | (int)(uVar12 >> 0x18) >> 7;
      param_5[2] = (byte)(uVar4 << 1) | (byte)((int)(uVar13 & 0xff) >> 7);
      param_5[3] = (byte)in_t1;
      param_5[4] = (byte)((uVar12 >> 0x18) << 1) | (byte)((int)uVar23 >> 7);
      param_5[0xd] = bStack_43 << 1 | (byte)((int)(uint)bStack_42 >> 7);
      in_t0 = uVar11 << 1 | (int)(uVar12 & 0xff) >> 7;
      param_5[10] = bStack_46 << 1 | (byte)((int)(uVar10 & 0xff) >> 7);
      param_5[0xc] = local_44 << 1 | (byte)((int)(uint)bStack_43 >> 7);
      param_5[5] = (byte)(uVar23 << 1) | (byte)((int)uVar11 >> 7);
      param_5[6] = (byte)in_t0;
      param_5[7] = (byte)((uVar12 & 0xff) << 1) | (byte)((int)(uVar10 >> 0x18) >> 7);
      param_5[8] = (byte)((uVar10 >> 0x18) << 1) | (byte)((int)(uint)bStack_47 >> 7);
      puVar8 = (uint *)((uint)puVar16 & 7);
      puVar7 = (uint *)((int)(uVar19 & 0xffffff80) >> (int)puVar8);
      param_5[0xf] = (byte)local_9c | cStack_41 << 1;
      puVar16 = (uint *)((int)puVar16 + 1);
      param_5[0xb] = cStack_45 << 1 | (byte)((int)(uint)local_44 >> 7);
      param_5[0xe] = bStack_42 << 1 | (byte)puVar9;
      pcVar5 = (code *)~(1 << (uVar20 & 7));
      *pbVar14 = (byte)pcVar5 & *pbVar14 | (byte)puVar7;
      puVar15 = local_9c;
    } while (param_3 != puVar16);
  }
  if (iVar3 == *(int *)puVar2) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iVar3 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar16 = puVar9;
  if (puVar15 != (uint *)0x0) {
    puVar21 = (uint *)((int)puVar7 + (int)puVar15);
    puVar22 = puVar7;
    puVar24 = puVar8;
    if (iStack_a0 == 0) {
      do {
        uVar4 = _DAT_006aedec;
        puVar18 = _DAT_006aede8;
        puVar16 = _DAT_006aede4;
        puVar15 = __gp;
        puVar17 = (uint *)((int)puVar22 + 1);
        uStack_108 = __gp;
        puVar7 = local_a8;
        puVar8 = local_a8;
        (*(code *)local_9c)(&_gp,&_gp,puVar9);
        uStack_108._1_3_ = SUB43(puVar15,0);
        uStack_104 = (undefined)((uint)puVar16 >> 0x18);
        __gp = (uint *)CONCAT31(uStack_108._1_3_,uStack_104);
        uStack_103 = SUB43(puVar16,0);
        uStack_100 = (undefined)((uint)puVar18 >> 0x18);
        puVar15 = (uint *)CONCAT31(uStack_103,uStack_100);
        uStack_ff = SUB43(puVar18,0);
        uStack_fc = (undefined)(uVar4 >> 0x18);
        _DAT_006aede8 = (uint *)CONCAT31(uStack_ff,uStack_fc);
        uStack_fb = (undefined3)uVar4;
        _DAT_006aedec = CONCAT31(uStack_fb,*(byte *)puVar22);
        *(byte *)puVar24 = *(byte *)puVar22 ^ _gp;
        puVar16 = __gp;
        puVar22 = puVar17;
        puVar24 = (uint *)((int)puVar24 + 1);
        _DAT_006aede4 = puVar15;
      } while (puVar17 != puVar21);
    }
    else {
      do {
        uVar4 = _DAT_006aedec;
        puVar7 = _DAT_006aede8;
        puVar8 = _DAT_006aede4;
        puVar15 = __gp;
        puVar18 = (uint *)((int)puVar22 + 1);
        uStack_108 = __gp;
        (*(code *)local_9c)(&_gp,&_gp,puVar9);
        uStack_108._1_3_ = SUB43(puVar15,0);
        uStack_104 = (undefined)((uint)puVar8 >> 0x18);
        puVar15 = (uint *)CONCAT31(uStack_108._1_3_,uStack_104);
        uStack_103 = SUB43(puVar8,0);
        uStack_100 = (undefined)((uint)puVar7 >> 0x18);
        puVar8 = (uint *)CONCAT31(uStack_103,uStack_100);
        uStack_ff = SUB43(puVar7,0);
        uStack_fc = (undefined)(uVar4 >> 0x18);
        puVar7 = (uint *)CONCAT31(uStack_ff,uStack_fc);
        uStack_fb = (undefined3)uVar4;
        _DAT_006aedec = CONCAT31(uStack_fb,*(byte *)puVar22 ^ _gp);
        *(byte *)puVar24 = *(byte *)puVar22 ^ _gp;
        puVar16 = _DAT_006aede4;
        puVar22 = puVar18;
        puVar24 = (uint *)((int)puVar24 + 1);
        __gp = puVar15;
        _DAT_006aede4 = puVar8;
        _DAT_006aede8 = puVar7;
      } while (puVar21 != puVar18);
    }
  }
  if (iVar3 == *(int *)puVar2) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  for (puVar9 = *ppuStack_10c; puVar9 != (uint *)0x0;
      puVar9 = (uint *)((uint)((int)puVar9 + 1) & 0xf)) {
    if (puVar15 == (uint *)0x0) {
      if ((((uint)puVar8 | (uint)puVar7) & 3) != 0) goto LAB_005eabc0;
      goto LAB_005eac24;
    }
    bVar1 = *(byte *)puVar7;
    puVar7 = (uint *)((int)puVar7 + 1);
    puVar15 = (uint *)((int)puVar15 + -1);
    *(byte *)puVar8 = *(byte *)(puVar9 + 0x1abb78) ^ bVar1;
    puVar8 = (uint *)((int)puVar8 + 1);
  }
  if ((((uint)puVar7 | (uint)puVar8) & 3) != 0) {
    puVar22 = (uint *)((int)puVar7 + (int)puVar15);
    puVar9 = puVar15;
    if (puVar15 != (uint *)0x0) {
      puVar9 = (uint *)0x0;
      do {
        if (puVar9 == (uint *)0x0) {
          (*(code *)uStack_108)(&_gp,&_gp,puVar16);
        }
        puVar15 = puVar9 + 0x1abb78;
        bVar1 = *(byte *)puVar7;
        puVar7 = (uint *)((int)puVar7 + 1);
        puVar9 = (uint *)((uint)((int)puVar9 + 1) & 0xf);
        *(byte *)puVar8 = *(byte *)puVar15 ^ bVar1;
        puVar8 = (uint *)((int)puVar8 + 1);
      } while (puVar7 != puVar22);
    }
LAB_005eabc0:
    *ppuStack_10c = puVar9;
    return;
  }
  puVar9 = puVar15;
  puVar22 = puVar7;
  puVar24 = puVar8;
  if (puVar15 < &SUB_00000010) {
    if (puVar15 != (uint *)0x0) {
      (*(code *)uStack_108)(&_gp,&_gp,puVar16);
      pbVar14 = (byte *)((int)puVar15 + -1);
      goto LAB_005ead2c;
    }
  }
  else {
    do {
      (*(code *)uStack_108)(&_gp,&_gp,puVar16);
      puVar9 = puVar9 + -4;
      *puVar24 = *puVar22 ^ (uint)__gp;
      puVar24[1] = puVar22[1] ^ (uint)_DAT_006aede4;
      puVar24[2] = puVar22[2] ^ (uint)_DAT_006aede8;
      puVar24[3] = puVar22[3] ^ _DAT_006aedec;
      puVar22 = puVar22 + 4;
      puVar24 = puVar24 + 4;
    } while (&DAT_0000000f < puVar9);
    iVar3 = ((uint)(puVar15 + -4) >> 4) + 1;
    puVar8 = puVar8 + iVar3 * 4;
    puVar7 = puVar7 + iVar3 * 4;
    if (((uint)puVar15 & 0xf) != 0) {
      pbVar14 = (byte *)((int)puVar15 + (-0x11 - ((uint)(puVar15 + -4) & 0xfffffff0)));
      (*(code *)uStack_108)(&_gp,&_gp,puVar16);
LAB_005ead2c:
      puVar9 = (uint *)(pbVar14 + 1);
      if ((puVar9 < &DAT_00000007 ||
           (puVar8 < &DAT_006aede4 && &_gp < puVar8 + 1 ||
           puVar8 < puVar7 + 1 && puVar7 < puVar8 + 1)) ||
         ((((uint)puVar8 | (uint)puVar7) & 3) != 0)) {
        *(byte *)puVar8 = _gp ^ *(byte *)puVar7;
        if (pbVar14 != (byte *)0x0) {
          *(byte *)((int)puVar8 + 1) = *(byte *)((int)puVar7 + 1) ^ DAT_006aede1;
          if (pbVar14 != (byte *)0x1) {
            *(byte *)((int)puVar8 + 2) = *(byte *)((int)puVar7 + 2) ^ DAT_006aede2;
            if (pbVar14 != &SUB_00000002) {
              *(byte *)((int)puVar8 + 3) = *(byte *)((int)puVar7 + 3) ^ DAT_006aede3;
              if (pbVar14 != (byte *)0x3) {
                *(byte *)(puVar8 + 1) = *(byte *)(puVar7 + 1) ^ DAT_006aede4;
                if (pbVar14 != &SUB_00000004) {
                  *(byte *)((int)puVar8 + 5) = *(byte *)((int)puVar7 + 5) ^ DAT_006aede5;
                  if (pbVar14 != &DAT_00000005) {
                    *(byte *)((int)puVar8 + 6) = *(byte *)((int)puVar7 + 6) ^ DAT_006aede6;
                    if (pbVar14 != &DAT_00000006) {
                      *(byte *)((int)puVar8 + 7) = *(byte *)((int)puVar7 + 7) ^ DAT_006aede7;
                      if (pbVar14 != &DAT_00000007) {
                        *(byte *)(puVar8 + 2) = *(byte *)(puVar7 + 2) ^ DAT_006aede8;
                        if (pbVar14 != &DAT_00000008) {
                          *(byte *)((int)puVar8 + 9) = *(byte *)((int)puVar7 + 9) ^ DAT_006aede9;
                          if (pbVar14 != &DAT_00000009) {
                            *(byte *)((int)puVar8 + 10) = *(byte *)((int)puVar7 + 10) ^ DAT_006aedea
                            ;
                            if (pbVar14 != &DAT_0000000a) {
                              *(byte *)((int)puVar8 + 0xb) =
                                   *(byte *)((int)puVar7 + 0xb) ^ DAT_006aedeb;
                              if (pbVar14 != &DAT_0000000b) {
                                *(byte *)(puVar8 + 3) = *(byte *)(puVar7 + 3) ^ DAT_006aedec;
                                if (pbVar14 != &SUB_0000000c) {
                                  *(byte *)((int)puVar8 + 0xd) =
                                       *(byte *)((int)puVar7 + 0xd) ^ DAT_006aeded;
                                  if (pbVar14 != &DAT_0000000d) {
                                    *(byte *)((int)puVar8 + 0xe) =
                                         *(byte *)((int)puVar7 + 0xe) ^ DAT_006aedee;
                                    *ppuStack_10c = puVar9;
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
        iVar3 = ((uint)(pbVar14 + -3) >> 2) + 1;
        *puVar8 = (uint)__gp ^ *puVar7;
        puVar15 = (uint *)(iVar3 * 4);
        if ((iVar3 != 1) && (puVar8[1] = puVar7[1] ^ (uint)_DAT_006aede4, iVar3 == 3)) {
          puVar8[2] = puVar7[2] ^ (uint)_DAT_006aede8;
        }
        if (puVar9 != puVar15) {
          *(byte *)(puVar8 + iVar3) = *(byte *)(puVar7 + iVar3) ^ *(byte *)(puVar15 + 0x1abb78);
          if (pbVar14 + iVar3 * -4 != (byte *)0x0) {
            *(byte *)((int)puVar8 + (int)(byte *)((int)puVar15 + 1)) =
                 *(byte *)((int)puVar7 + (int)(byte *)((int)puVar15 + 1)) ^
                 *(byte *)((int)puVar15 + 0x6aede1);
            if (pbVar14 + iVar3 * -4 != (byte *)0x1) {
              *(byte *)((int)puVar8 + (int)(byte *)((int)puVar15 + 2)) =
                   *(byte *)((int)puVar7 + (int)(byte *)((int)puVar15 + 2)) ^
                   *(byte *)((int)puVar15 + 0x6aede2);
              *ppuStack_10c = puVar9;
              return;
            }
          }
        }
      }
LAB_005eac24:
      *ppuStack_10c = puVar9;
      return;
    }
  }
  *ppuStack_10c = (uint *)0x0;
  return;
}

