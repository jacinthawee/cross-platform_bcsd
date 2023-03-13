
undefined4 ssl_add_serverhello_renegotiate_ext(int param_1,char *param_2,int *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar2 = *(int *)(param_1 + 0x58);
  if (param_2 == (char *)0x0) goto LAB_080cf3c0;
  if (param_4 <= (int)((uint)*(byte *)(iVar2 + 0x415) + (uint)*(byte *)(iVar2 + 0x3d4))) {
    ERR_put_error(0x14,299,0x14f,"t1_reneg.c",0xca);
    return 0;
  }
  *param_2 = *(byte *)(iVar2 + 0x415) + *(byte *)(iVar2 + 0x3d4);
  iVar2 = *(int *)(param_1 + 0x58);
  bVar1 = *(byte *)(iVar2 + 0x3d4);
  uVar3 = (uint)bVar1;
  if (uVar3 < 4) {
    if (uVar3 != 0) {
      param_2[1] = *(char *)(iVar2 + 0x394);
      if ((bVar1 & 2) == 0) goto LAB_080cf396;
      *(undefined2 *)(param_2 + (uVar3 - 1)) = *(undefined2 *)(iVar2 + 0x392 + uVar3);
      iVar2 = *(int *)(param_1 + 0x58);
    }
  }
  else {
    *(undefined4 *)(param_2 + 1) = *(undefined4 *)(iVar2 + 0x394);
    *(undefined4 *)(param_2 + (uVar3 - 3)) = *(undefined4 *)(iVar2 + 0x390 + uVar3);
    puVar4 = (undefined4 *)
             ((iVar2 + 0x394) -
             (int)(param_2 + (1 - (int)(undefined4 *)((uint)(param_2 + 5) & 0xfffffffc))));
    puVar6 = (undefined4 *)((uint)(param_2 + 5) & 0xfffffffc);
    for (uVar3 = (uint)(param_2 + (1 - (int)(undefined4 *)((uint)(param_2 + 5) & 0xfffffffc)) +
                       uVar3) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
LAB_080cf396:
    iVar2 = *(int *)(param_1 + 0x58);
  }
  bVar1 = *(byte *)(iVar2 + 0x415);
  uVar3 = (uint)bVar1;
  puVar4 = (undefined4 *)(param_2 + *(byte *)(iVar2 + 0x3d4) + 1);
  if (uVar3 < 4) {
    if (uVar3 == 0) goto LAB_080cf3c0;
    *(undefined *)puVar4 = *(undefined *)(iVar2 + 0x3d5);
    if ((bVar1 & 2) != 0) {
      *(undefined2 *)((int)puVar4 + (uVar3 - 2)) = *(undefined2 *)(iVar2 + 0x3d3 + uVar3);
      iVar2 = *(int *)(param_1 + 0x58);
      goto LAB_080cf3c0;
    }
  }
  else {
    *puVar4 = *(undefined4 *)(iVar2 + 0x3d5);
    *(undefined4 *)((int)puVar4 + (uVar3 - 4)) = *(undefined4 *)(iVar2 + 0x3d1 + uVar3);
    iVar5 = (int)puVar4 - (int)(undefined4 *)((uint)(puVar4 + 1) & 0xfffffffc);
    puVar6 = (undefined4 *)((iVar2 + 0x3d5) - iVar5);
    puVar4 = (undefined4 *)((uint)(puVar4 + 1) & 0xfffffffc);
    for (uVar3 = uVar3 + iVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  iVar2 = *(int *)(param_1 + 0x58);
LAB_080cf3c0:
  *param_3 = *(byte *)(iVar2 + 0x3d4) + 1 + (uint)*(byte *)(iVar2 + 0x415);
  return 1;
}

