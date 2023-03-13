
/* WARNING: Could not reconcile some variable overlaps */

void CRYPTO_cbc128_decrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               code *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  uint *puVar11;
  int in_GS_OFFSET;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1 == param_2) {
    uVar8 = param_3;
    puVar6 = param_1;
    puVar9 = param_2;
    puVar11 = param_1;
    if (0xf < param_3) {
      do {
        uVar8 = uVar8 - 0x10;
        (*param_6)(puVar6,&local_30,param_4);
        uVar4 = *puVar6;
        *puVar11 = local_30 ^ *param_5;
        *param_5 = uVar4;
        uVar4 = puVar6[1];
        puVar11[1] = local_2c ^ param_5[1];
        param_5[1] = uVar4;
        uVar4 = puVar6[2];
        puVar11[2] = local_28 ^ param_5[2];
        param_5[2] = uVar4;
        uVar4 = puVar6[3];
        puVar11[3] = local_24 ^ param_5[3];
        param_5[3] = uVar4;
        puVar6 = puVar6 + 4;
        puVar11 = puVar11 + 4;
      } while (0xf < uVar8);
      uVar8 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      param_2 = (uint *)((int)param_1 + (uVar8 & 0xfffffff0) + 0x10);
      puVar9 = param_2;
    }
  }
  else {
    puVar6 = param_5;
    uVar8 = param_3;
    puVar9 = param_1;
    puVar11 = param_2;
    if (0xf < param_3) {
      do {
        uVar8 = uVar8 - 0x10;
        (*param_6)(puVar9,puVar11,param_4);
        *puVar11 = *puVar11 ^ *puVar6;
        puVar11[1] = puVar11[1] ^ puVar6[1];
        puVar11[2] = puVar11[2] ^ puVar6[2];
        puVar11[3] = puVar11[3] ^ puVar6[3];
        puVar11 = puVar11 + 4;
        puVar6 = puVar9;
        puVar9 = puVar9 + 4;
      } while (0xf < uVar8);
      uVar8 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      iVar7 = (uVar8 >> 4) + 1;
      puVar6 = (uint *)((uVar8 & 0xfffffff0) + (int)param_1);
      param_1 = param_1 + iVar7 * 4;
      param_2 = param_2 + iVar7 * 4;
    }
    uVar8 = puVar6[1];
    uVar4 = puVar6[2];
    uVar5 = puVar6[3];
    *param_5 = *puVar6;
    param_5[2] = uVar4;
    param_5[3] = uVar5;
    param_5[1] = uVar8;
    puVar9 = param_1;
  }
  if (param_3 != 0) {
    (*param_6)(puVar9,&local_30,param_4);
    bVar3 = *(byte *)puVar9;
    *(byte *)param_2 = (byte)local_30 ^ *(byte *)param_5;
    *(byte *)param_5 = bVar3;
    if (param_3 == 1) {
      iVar7 = 1;
    }
    else {
      bVar3 = *(byte *)((int)puVar9 + 1);
      *(byte *)((int)param_2 + 1) = local_30._1_1_ ^ *(byte *)((int)param_5 + 1);
      *(byte *)((int)param_5 + 1) = bVar3;
      if (param_3 == 2) {
        iVar7 = 2;
      }
      else {
        bVar3 = *(byte *)((int)puVar9 + 2);
        *(byte *)((int)param_2 + 2) = local_30._2_1_ ^ *(byte *)((int)param_5 + 2);
        *(byte *)((int)param_5 + 2) = bVar3;
        if (param_3 == 3) {
          iVar7 = 3;
        }
        else {
          bVar3 = *(byte *)((int)puVar9 + 3);
          *(byte *)((int)param_2 + 3) = local_30._3_1_ ^ *(byte *)((int)param_5 + 3);
          *(byte *)((int)param_5 + 3) = bVar3;
          if (param_3 == 4) {
            iVar7 = 4;
          }
          else {
            bVar3 = *(byte *)(puVar9 + 1);
            *(byte *)(param_2 + 1) = (byte)local_2c ^ *(byte *)(param_5 + 1);
            *(byte *)(param_5 + 1) = bVar3;
            if (param_3 == 5) {
              iVar7 = 5;
            }
            else {
              bVar3 = *(byte *)((int)puVar9 + 5);
              *(byte *)((int)param_2 + 5) = local_2c._1_1_ ^ *(byte *)((int)param_5 + 5);
              *(byte *)((int)param_5 + 5) = bVar3;
              if (param_3 == 6) {
                iVar7 = 6;
              }
              else {
                bVar3 = *(byte *)((int)puVar9 + 6);
                *(byte *)((int)param_2 + 6) = local_2c._2_1_ ^ *(byte *)((int)param_5 + 6);
                *(byte *)((int)param_5 + 6) = bVar3;
                if (param_3 == 7) {
                  iVar7 = 7;
                }
                else {
                  bVar3 = *(byte *)((int)puVar9 + 7);
                  *(byte *)((int)param_2 + 7) = local_2c._3_1_ ^ *(byte *)((int)param_5 + 7);
                  *(byte *)((int)param_5 + 7) = bVar3;
                  if (param_3 == 8) {
                    iVar7 = 8;
                  }
                  else {
                    bVar3 = *(byte *)(puVar9 + 2);
                    *(byte *)(param_2 + 2) = (byte)local_28 ^ *(byte *)(param_5 + 2);
                    *(byte *)(param_5 + 2) = bVar3;
                    if (param_3 == 9) {
                      iVar7 = 9;
                    }
                    else {
                      bVar3 = *(byte *)((int)puVar9 + 9);
                      *(byte *)((int)param_2 + 9) = local_28._1_1_ ^ *(byte *)((int)param_5 + 9);
                      *(byte *)((int)param_5 + 9) = bVar3;
                      if (param_3 == 10) {
                        iVar7 = 10;
                      }
                      else {
                        bVar3 = *(byte *)((int)puVar9 + 10);
                        *(byte *)((int)param_2 + 10) = local_28._2_1_ ^ *(byte *)((int)param_5 + 10)
                        ;
                        *(byte *)((int)param_5 + 10) = bVar3;
                        if (param_3 == 0xb) {
                          iVar7 = 0xb;
                        }
                        else {
                          bVar3 = *(byte *)((int)puVar9 + 0xb);
                          *(byte *)((int)param_2 + 0xb) =
                               local_28._3_1_ ^ *(byte *)((int)param_5 + 0xb);
                          *(byte *)((int)param_5 + 0xb) = bVar3;
                          if (param_3 == 0xc) {
                            iVar7 = 0xc;
                          }
                          else {
                            bVar3 = *(byte *)(puVar9 + 3);
                            *(byte *)(param_2 + 3) = (byte)local_24 ^ *(byte *)(param_5 + 3);
                            *(byte *)(param_5 + 3) = bVar3;
                            if (param_3 == 0xd) {
                              iVar7 = 0xd;
                            }
                            else {
                              bVar3 = *(byte *)((int)puVar9 + 0xd);
                              *(byte *)((int)param_2 + 0xd) =
                                   local_24._1_1_ ^ *(byte *)((int)param_5 + 0xd);
                              *(byte *)((int)param_5 + 0xd) = bVar3;
                              if (param_3 == 0xf) {
                                bVar3 = *(byte *)((int)puVar9 + 0xe);
                                *(byte *)((int)param_2 + 0xe) =
                                     local_24._2_1_ ^ *(byte *)((int)param_5 + 0xe);
                                *(byte *)((int)param_5 + 0xe) = bVar3;
                                *(byte *)((int)param_5 + 0xf) = *(byte *)((int)puVar9 + 0xf);
                                goto LAB_080eeaff;
                              }
                              iVar7 = 0xe;
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
    puVar2 = (undefined4 *)((int)param_5 + iVar7);
    uVar8 = 0x10 - iVar7;
    iVar1 = iVar7 + 4;
    if ((uVar8 < 10 ||
         (byte *)((int)puVar9 + iVar7) < (byte *)((int)param_5 + iVar1) &&
         puVar2 < (undefined4 *)((int)puVar9 + iVar1)) ||
       ((((uint)puVar2 | (uint)(byte *)((int)puVar9 + iVar7)) & 3) != 0)) {
      *(byte *)puVar2 = *(byte *)((int)puVar9 + iVar7);
      *(byte *)((int)param_5 + iVar7 + 1) = *(byte *)((int)puVar9 + iVar7 + 1);
      if (((((iVar7 != 0xe) &&
            (((*(byte *)((int)param_5 + iVar7 + 2) = *(byte *)((int)puVar9 + iVar7 + 2),
              iVar7 != 0xd &&
              (*(byte *)((int)param_5 + iVar7 + 3) = *(byte *)((int)puVar9 + iVar7 + 3),
              iVar1 != 0x10)) &&
             (*(byte *)((int)param_5 + iVar7 + 4) = *(byte *)((int)puVar9 + iVar7 + 4), iVar7 != 0xb
             )))) && (((*(byte *)((int)param_5 + iVar7 + 5) = *(byte *)((int)puVar9 + iVar7 + 5),
                       iVar7 != 10 &&
                       (*(byte *)((int)param_5 + iVar7 + 6) = *(byte *)((int)puVar9 + iVar7 + 6),
                       iVar7 != 9)) &&
                      (*(byte *)((int)param_5 + iVar7 + 7) = *(byte *)((int)puVar9 + iVar7 + 7),
                      iVar7 != 8)))) &&
          ((*(byte *)((int)param_5 + iVar7 + 8) = *(byte *)((int)puVar9 + iVar7 + 8), iVar7 != 7 &&
           (*(byte *)((int)param_5 + iVar7 + 9) = *(byte *)((int)puVar9 + iVar7 + 9), iVar7 != 6))))
         && ((*(byte *)((int)param_5 + iVar7 + 10) = *(byte *)((int)puVar9 + iVar7 + 10), iVar7 != 5
             && (((*(byte *)((int)param_5 + iVar7 + 0xb) = *(byte *)((int)puVar9 + iVar7 + 0xb),
                  iVar7 != 4 &&
                  (*(byte *)((int)param_5 + iVar7 + 0xc) = *(byte *)((int)puVar9 + iVar7 + 0xc),
                  iVar7 != 3)) &&
                 (*(byte *)((int)param_5 + iVar7 + 0xd) = *(byte *)((int)puVar9 + iVar7 + 0xd),
                 iVar7 != 2)))))) {
        *(byte *)((int)param_5 + 0xf) = *(byte *)((int)puVar9 + 0xf);
      }
    }
    else {
      iVar10 = (0xcU - iVar7 >> 2) + 1;
      iVar1 = iVar10 * 4;
      if (2 < 0xfU - iVar7) {
        *puVar2 = *(undefined4 *)((int)puVar9 + iVar7);
        puVar2[1] = *(undefined4 *)((int)puVar9 + iVar7 + 4);
        if (iVar10 == 3) {
          puVar2[2] = *(undefined4 *)((int)puVar9 + iVar7 + 8);
        }
        iVar7 = iVar7 + iVar1;
        if (iVar1 - uVar8 == 0) goto LAB_080eeaff;
      }
      *(byte *)((int)param_5 + iVar7) = *(byte *)((int)puVar9 + iVar7);
      if ((iVar7 != 0xf) &&
         (*(byte *)((int)param_5 + iVar7 + 1) = *(byte *)((int)puVar9 + iVar7 + 1), iVar7 != 0xe)) {
        *(byte *)((int)param_5 + iVar7 + 2) = *(byte *)((int)puVar9 + iVar7 + 2);
      }
    }
  }
LAB_080eeaff:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

