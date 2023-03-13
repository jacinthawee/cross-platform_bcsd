
int ssl3_get_next_proto(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  int in_GS_OFFSET;
  byte bVar7;
  int line;
  int local_24;
  int local_20;
  
  bVar7 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x41c) == 0) {
    line = 0xe06;
    iVar3 = 0x164;
  }
  else {
    iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x2210,0x2211,0x43,0x202,&local_24);
    if (local_24 == 0) goto LAB_08098f01;
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x180) != 0) {
      if (1 < iVar3) {
        pbVar2 = *(byte **)(param_1 + 0x40);
        bVar1 = *pbVar2;
        uVar5 = (uint)bVar1;
        if (((int)(uVar5 + 1) < *(int *)(param_1 + 0x44)) &&
           (*(int *)(param_1 + 0x44) == uVar5 + 2 + (uint)pbVar2[uVar5 + 1])) {
          puVar4 = (undefined4 *)CRYPTO_malloc(uVar5,"s3_srvr.c",0xe38);
          *(undefined4 **)(param_1 + 0x174) = puVar4;
          if (puVar4 == (undefined4 *)0x0) {
            ERR_put_error(0x14,0x132,0x41,"s3_srvr.c",0xe3a);
            *(undefined4 *)(param_1 + 0x34) = 5;
            iVar3 = 0;
          }
          else {
            if (uVar5 < 4) {
              if ((uVar5 != 0) && (*(byte *)puVar4 = pbVar2[1], (bVar1 & 2) != 0)) {
                *(undefined2 *)((int)puVar4 + (uVar5 - 2)) = *(undefined2 *)(pbVar2 + (uVar5 - 1));
              }
            }
            else {
              *puVar4 = *(undefined4 *)(pbVar2 + 1);
              *(undefined4 *)((int)puVar4 + (uVar5 - 4)) = *(undefined4 *)(pbVar2 + (uVar5 - 3));
              iVar3 = (int)puVar4 - (int)(undefined4 *)((uint)(puVar4 + 1) & 0xfffffffc);
              puVar6 = (undefined4 *)(pbVar2 + (1 - iVar3));
              puVar4 = (undefined4 *)((uint)(puVar4 + 1) & 0xfffffffc);
              for (uVar5 = uVar5 + iVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar4 = *puVar6;
                puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
                puVar4 = puVar4 + (uint)bVar7 * -2 + 1;
              }
            }
            *(byte *)(param_1 + 0x178) = bVar1;
            iVar3 = 1;
          }
          goto LAB_08098f01;
        }
      }
      *(undefined4 *)(param_1 + 0x34) = 5;
      iVar3 = 0;
      goto LAB_08098f01;
    }
    line = 0xe1a;
    iVar3 = 0x163;
  }
  ERR_put_error(0x14,0x132,iVar3,"s3_srvr.c",line);
  *(undefined4 *)(param_1 + 0x34) = 5;
  iVar3 = -1;
LAB_08098f01:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

