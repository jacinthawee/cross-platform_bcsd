
/* WARNING: Could not reconcile some variable overlaps */

void CRYPTO_cbc128_decrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               code *param_6)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (param_1 == param_2) {
    puVar6 = param_2;
    if ((((uint)param_2 | (uint)param_5) & 3) == 0) {
      if (0xf < param_3) {
        puVar6 = param_1;
        uVar8 = param_3;
        puVar9 = param_1;
        do {
          uVar8 = uVar8 - 0x10;
          (*param_6)(puVar6,&local_3c,param_4);
          uVar5 = *puVar9;
          *puVar9 = local_3c ^ *param_5;
          *param_5 = uVar5;
          uVar5 = puVar6[1];
          puVar6[1] = local_38 ^ param_5[1];
          param_5[1] = uVar5;
          uVar5 = puVar6[2];
          puVar6[2] = local_34 ^ param_5[2];
          param_5[2] = uVar5;
          uVar5 = puVar6[3];
          puVar6[3] = local_30 ^ param_5[3];
          param_5[3] = uVar5;
          puVar6 = puVar6 + 4;
          puVar9 = puVar9 + 4;
        } while (0xf < uVar8);
LAB_00083e2c:
        uVar8 = param_3 - 0x10;
        param_3 = param_3 & 0xf;
        param_2 = (uint *)((int)param_1 + (uVar8 & 0xfffffff0) + 0x10);
        puVar6 = param_2;
      }
    }
    else if (0xf < param_3) {
      puVar6 = param_1;
      uVar8 = param_3;
      puVar9 = param_1;
      do {
        uVar8 = uVar8 - 0x10;
        (*param_6)(puVar6,&local_3c,param_4);
        bVar1 = *(byte *)puVar9;
        *(byte *)puVar9 = (byte)local_3c ^ *(byte *)param_5;
        *(byte *)param_5 = bVar1;
        bVar1 = *(byte *)((int)puVar6 + 1);
        *(byte *)((int)puVar6 + 1) = local_3c._1_1_ ^ *(byte *)((int)param_5 + 1);
        *(byte *)((int)param_5 + 1) = bVar1;
        bVar1 = *(byte *)((int)puVar6 + 2);
        *(byte *)((int)puVar6 + 2) = local_3c._2_1_ ^ *(byte *)((int)param_5 + 2);
        *(byte *)((int)param_5 + 2) = bVar1;
        bVar1 = *(byte *)((int)puVar6 + 3);
        *(byte *)((int)puVar6 + 3) = local_3c._3_1_ ^ *(byte *)((int)param_5 + 3);
        *(byte *)((int)param_5 + 3) = bVar1;
        bVar1 = *(byte *)(puVar6 + 1);
        *(byte *)(puVar6 + 1) = (byte)local_38 ^ *(byte *)(param_5 + 1);
        *(byte *)(param_5 + 1) = bVar1;
        bVar1 = *(byte *)((int)puVar6 + 5);
        *(byte *)((int)puVar6 + 5) = local_38._1_1_ ^ *(byte *)((int)param_5 + 5);
        *(byte *)((int)param_5 + 5) = bVar1;
        bVar1 = *(byte *)((int)puVar6 + 6);
        *(byte *)((int)puVar6 + 6) = local_38._2_1_ ^ *(byte *)((int)param_5 + 6);
        *(byte *)((int)param_5 + 6) = bVar1;
        bVar1 = *(byte *)((int)puVar6 + 7);
        *(byte *)((int)puVar6 + 7) = local_38._3_1_ ^ *(byte *)((int)param_5 + 7);
        *(byte *)((int)param_5 + 7) = bVar1;
        bVar1 = *(byte *)(puVar6 + 2);
        *(byte *)(puVar6 + 2) = (byte)local_34 ^ *(byte *)(param_5 + 2);
        *(byte *)(param_5 + 2) = bVar1;
        bVar1 = *(byte *)((int)puVar6 + 9);
        *(byte *)((int)puVar6 + 9) = local_34._1_1_ ^ *(byte *)((int)param_5 + 9);
        *(byte *)((int)param_5 + 9) = bVar1;
        bVar1 = *(byte *)((int)puVar6 + 10);
        *(byte *)((int)puVar6 + 10) = local_34._2_1_ ^ *(byte *)((int)param_5 + 10);
        *(byte *)((int)param_5 + 10) = bVar1;
        bVar1 = *(byte *)((int)puVar6 + 0xb);
        *(byte *)((int)puVar6 + 0xb) = local_34._3_1_ ^ *(byte *)((int)param_5 + 0xb);
        *(byte *)((int)param_5 + 0xb) = bVar1;
        bVar1 = *(byte *)(puVar6 + 3);
        *(byte *)(puVar6 + 3) = (byte)local_30 ^ *(byte *)(param_5 + 3);
        *(byte *)(param_5 + 3) = bVar1;
        bVar1 = *(byte *)((int)puVar6 + 0xd);
        *(byte *)((int)puVar6 + 0xd) = local_30._1_1_ ^ *(byte *)((int)param_5 + 0xd);
        *(byte *)((int)param_5 + 0xd) = bVar1;
        bVar1 = *(byte *)((int)puVar6 + 0xe);
        *(byte *)((int)puVar6 + 0xe) = local_30._2_1_ ^ *(byte *)((int)param_5 + 0xe);
        *(byte *)((int)param_5 + 0xe) = bVar1;
        bVar1 = *(byte *)((int)puVar6 + 0xf);
        *(byte *)((int)puVar6 + 0xf) = local_30._3_1_ ^ *(byte *)((int)param_5 + 0xf);
        *(byte *)((int)param_5 + 0xf) = bVar1;
        puVar6 = puVar6 + 4;
        puVar9 = puVar9 + 4;
      } while (0xf < uVar8);
      goto LAB_00083e2c;
    }
  }
  else {
    puVar6 = param_5;
    if ((((uint)param_2 | (uint)param_5 | (uint)param_1) & 3) == 0) {
      if (0xf < param_3) {
        uVar8 = param_3;
        puVar6 = param_2;
        puVar9 = param_5;
        puVar10 = param_1;
        puVar11 = param_2 + 4;
        do {
          uVar8 = uVar8 - 0x10;
          (*param_6)(puVar10,puVar6,param_4);
          puVar11[-4] = *puVar9 ^ puVar11[-4];
          puVar6[1] = puVar9[1] ^ puVar6[1];
          puVar6[2] = puVar9[2] ^ puVar6[2];
          puVar6[3] = puVar6[3] ^ puVar9[3];
          puVar6 = puVar6 + 4;
          puVar9 = puVar10;
          puVar10 = puVar10 + 4;
          puVar11 = puVar11 + 4;
        } while (0xf < uVar8);
        goto LAB_00083c24;
      }
    }
    else if (0xf < param_3) {
      uVar8 = param_3;
      puVar6 = param_2;
      puVar9 = param_5;
      puVar10 = param_1;
      puVar11 = param_2 + 4;
      do {
        uVar8 = uVar8 - 0x10;
        (*param_6)(puVar10,puVar6,param_4);
        *(byte *)(puVar11 + -4) = *(byte *)puVar9 ^ *(byte *)(puVar11 + -4);
        *(byte *)((int)puVar6 + 1) = *(byte *)((int)puVar6 + 1) ^ *(byte *)((int)puVar9 + 1);
        *(byte *)((int)puVar6 + 2) = *(byte *)((int)puVar6 + 2) ^ *(byte *)((int)puVar9 + 2);
        *(byte *)((int)puVar6 + 3) = *(byte *)((int)puVar6 + 3) ^ *(byte *)((int)puVar9 + 3);
        *(byte *)(puVar6 + 1) = *(byte *)(puVar6 + 1) ^ *(byte *)(puVar9 + 1);
        *(byte *)((int)puVar6 + 5) = *(byte *)((int)puVar6 + 5) ^ *(byte *)((int)puVar9 + 5);
        *(byte *)((int)puVar6 + 6) = *(byte *)((int)puVar6 + 6) ^ *(byte *)((int)puVar9 + 6);
        *(byte *)((int)puVar6 + 7) = *(byte *)((int)puVar6 + 7) ^ *(byte *)((int)puVar9 + 7);
        *(byte *)(puVar6 + 2) = *(byte *)(puVar6 + 2) ^ *(byte *)(puVar9 + 2);
        *(byte *)((int)puVar6 + 9) = *(byte *)((int)puVar6 + 9) ^ *(byte *)((int)puVar9 + 9);
        *(byte *)((int)puVar6 + 10) = *(byte *)((int)puVar6 + 10) ^ *(byte *)((int)puVar9 + 10);
        *(byte *)((int)puVar6 + 0xb) = *(byte *)((int)puVar6 + 0xb) ^ *(byte *)((int)puVar9 + 0xb);
        *(byte *)(puVar6 + 3) = *(byte *)(puVar6 + 3) ^ *(byte *)(puVar9 + 3);
        *(byte *)((int)puVar6 + 0xd) = *(byte *)((int)puVar6 + 0xd) ^ *(byte *)((int)puVar9 + 0xd);
        *(byte *)((int)puVar6 + 0xe) = *(byte *)((int)puVar6 + 0xe) ^ *(byte *)((int)puVar9 + 0xe);
        *(byte *)((int)puVar6 + 0xf) = *(byte *)((int)puVar6 + 0xf) ^ *(byte *)((int)puVar9 + 0xf);
        puVar6 = puVar6 + 4;
        puVar9 = puVar10;
        puVar10 = puVar10 + 4;
        puVar11 = puVar11 + 4;
      } while (0xf < uVar8);
LAB_00083c24:
      uVar8 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      iVar4 = (uVar8 >> 4) + 1;
      puVar6 = (uint *)((int)param_1 + (uVar8 & 0xfffffff0));
      param_2 = param_2 + iVar4 * 4;
      param_1 = param_1 + iVar4 * 4;
    }
    uVar8 = puVar6[1];
    uVar5 = puVar6[2];
    uVar7 = puVar6[3];
    *param_5 = *puVar6;
    param_5[1] = uVar8;
    param_5[2] = uVar5;
    param_5[3] = uVar7;
    puVar6 = param_1;
  }
  if (param_3 != 0) {
    (*param_6)(puVar6,&local_3c,param_4);
    uVar8 = 0;
    do {
      bVar1 = *(byte *)((int)puVar6 + uVar8);
      *(byte *)((int)param_2 + uVar8) =
           *(byte *)((int)&local_3c + uVar8) ^ *(byte *)((int)param_5 + uVar8);
      *(byte *)((int)param_5 + uVar8) = bVar1;
      uVar8 = uVar8 + 1;
      uVar5 = (uint)(uVar8 < param_3);
      if (0xf < uVar8) {
        uVar5 = 0;
      }
    } while (uVar5 != 0);
    if (uVar8 != 0x10) {
      pbVar2 = (byte *)((int)puVar6 + uVar8);
      pbVar3 = (byte *)((int)param_5 + uVar8);
      uVar7 = 0x10 - uVar8;
      if ((((uint)pbVar3 | (uint)pbVar2) & 3) == 0 &&
          (9 < uVar7 && (pbVar3 + 4 <= pbVar2 || pbVar2 + 4 <= pbVar3))) {
        uVar12 = uVar5;
        if (uVar7 >> 2 != 0) {
          do {
            uVar12 = uVar12 + 1;
            *(undefined4 *)(pbVar3 + uVar5) = *(undefined4 *)(pbVar2 + uVar5);
            uVar5 = uVar5 + 4;
          } while (uVar12 < uVar7 >> 2);
          uVar8 = uVar8 + (uVar7 & 0xfffffffc);
          if (uVar7 == (uVar7 & 0xfffffffc)) goto LAB_00083cfe;
        }
        uVar5 = uVar8 + 1;
        *(byte *)((int)param_5 + uVar8) = *(byte *)((int)puVar6 + uVar8);
        if (uVar5 != 0x10) {
          iVar4 = uVar8 + 2;
          *(byte *)((int)param_5 + uVar5) = *(byte *)((int)puVar6 + uVar5);
          if (iVar4 != 0x10) {
            uVar5 = (uint)*(byte *)((int)puVar6 + iVar4);
          }
          if (iVar4 != 0x10) {
            *(byte *)((int)param_5 + iVar4) = (byte)uVar5;
          }
        }
      }
      else {
        do {
          *(byte *)((int)param_5 + uVar8) = *(byte *)((int)puVar6 + uVar8);
          iVar4 = uVar8 + 1;
          if (iVar4 == 0x10) break;
          *(byte *)((int)param_5 + iVar4) = *(byte *)((int)puVar6 + iVar4);
          uVar8 = uVar8 + 2;
        } while (uVar8 != 0x10);
      }
    }
  }
LAB_00083cfe:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

