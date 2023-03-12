
void ssl3_send_next_proto(int param_1)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  if (*(int *)(param_1 + 0x34) == 0x1200) {
    bVar1 = *(byte *)(param_1 + 0x178);
    uVar5 = (uint)bVar1;
    iVar3 = -(uVar5 + 2 & 0x1f);
    uVar6 = iVar3 + 0x20;
    puVar2 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
    puVar2[4] = bVar1;
    puVar7 = *(undefined4 **)(param_1 + 0x174);
    if (uVar5 < 4) {
      if ((uVar5 != 0) && (puVar2[5] = *(undefined *)puVar7, (bVar1 & 2) != 0)) {
        *(undefined2 *)(puVar2 + uVar5 + 3) = *(undefined2 *)((int)puVar7 + (uVar5 - 2));
      }
    }
    else {
      *(undefined4 *)(puVar2 + 5) = *puVar7;
      *(undefined4 *)(puVar2 + uVar5 + 1) = *(undefined4 *)((int)puVar7 + (uVar5 - 4));
      puVar7 = (undefined4 *)
               ((int)puVar7 -
               (int)(puVar2 + (5 - (int)(undefined4 *)((uint)(puVar2 + 9) & 0xfffffffc))));
      puVar9 = (undefined4 *)((uint)(puVar2 + 9) & 0xfffffffc);
      for (uVar4 = (uint)(puVar2 + (5 - (int)(undefined4 *)((uint)(puVar2 + 9) & 0xfffffffc)) +
                         uVar5) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
    }
    puVar2[uVar5 + 5] = (char)uVar6;
    puVar7 = (undefined4 *)(puVar2 + uVar5 + 6);
    if (uVar6 < 4) {
      if ((uVar6 != 0) && (*(undefined *)puVar7 = 0, (uVar6 & 2) != 0)) {
        *(undefined2 *)((int)puVar7 + iVar3 + 0x1e) = 0;
      }
    }
    else {
      *puVar7 = 0;
      *(undefined4 *)((int)puVar7 + iVar3 + 0x1c) = 0;
      uVar4 = (uint)((int)puVar7 + (uVar6 - ((uint)(puVar7 + 1) & 0xfffffffc))) & 0xfffffffc;
      if (3 < uVar4) {
        uVar8 = 0;
        do {
          *(undefined4 *)(((uint)(puVar7 + 1) & 0xfffffffc) + uVar8) = 0;
          uVar8 = uVar8 + 4;
        } while (uVar8 < uVar4);
      }
    }
    *puVar2 = 0x43;
    puVar2[1] = 0;
    puVar2[2] = (char)(uVar5 + uVar6 + 2 >> 8);
    puVar2[3] = bVar1 + 2 + (char)uVar6;
    *(undefined4 *)(param_1 + 0x34) = 0x1201;
    *(uint *)(param_1 + 0x44) = uVar5 + uVar6 + 6;
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  ssl3_do_write(param_1,0x16);
  return;
}

