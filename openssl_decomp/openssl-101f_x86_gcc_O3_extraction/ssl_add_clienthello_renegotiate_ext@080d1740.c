
undefined4 ssl_add_clienthello_renegotiate_ext(int param_1,byte *param_2,int *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = *(int *)(param_1 + 0x58);
  if (param_2 == (byte *)0x0) goto LAB_080d17a2;
  if (param_4 <= (int)(uint)*(byte *)(iVar2 + 0x3d4)) {
    ERR_put_error(0x14,0x12a,0x14f,"t1_reneg.c",0x7b);
    return 0;
  }
  *param_2 = *(byte *)(iVar2 + 0x3d4);
  iVar2 = *(int *)(param_1 + 0x58);
  bVar1 = *(byte *)(iVar2 + 0x3d4);
  uVar3 = (uint)bVar1;
  if (uVar3 < 4) {
    if (uVar3 == 0) goto LAB_080d17a2;
    param_2[1] = *(byte *)(iVar2 + 0x394);
    if ((bVar1 & 2) != 0) {
      *(undefined2 *)(param_2 + (uVar3 - 1)) = *(undefined2 *)(iVar2 + 0x392 + uVar3);
      iVar2 = *(int *)(param_1 + 0x58);
      goto LAB_080d17a2;
    }
  }
  else {
    *(undefined4 *)(param_2 + 1) = *(undefined4 *)(iVar2 + 0x394);
    *(undefined4 *)(param_2 + (uVar3 - 3)) = *(undefined4 *)(iVar2 + 0x390 + uVar3);
    puVar4 = (undefined4 *)
             ((iVar2 + 0x394) -
             (int)(param_2 + (1 - (int)(undefined4 *)((uint)(param_2 + 5) & 0xfffffffc))));
    puVar5 = (undefined4 *)((uint)(param_2 + 5) & 0xfffffffc);
    for (uVar3 = (uint)(param_2 + (1 - (int)(undefined4 *)((uint)(param_2 + 5) & 0xfffffffc)) +
                       uVar3) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  iVar2 = *(int *)(param_1 + 0x58);
LAB_080d17a2:
  *param_3 = *(byte *)(iVar2 + 0x3d4) + 1;
  return 1;
}

