
int ssl3_get_next_proto(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_GS_OFFSET;
  byte bVar7;
  int line;
  int local_34;
  int local_24;
  int local_20;
  
  bVar7 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x41c) == 0) {
    line = 0xdd4;
    iVar5 = 0x164;
  }
  else {
    local_34 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                         (param_1,0x2210,0x2211,0x43,0x202,&local_24);
    if (local_24 == 0) goto LAB_0809ccdc;
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x180) != 0) {
      if (local_34 < 2) {
        local_34 = 0;
      }
      else {
        pbVar2 = *(byte **)(param_1 + 0x40);
        local_34 = 0;
        bVar1 = *pbVar2;
        uVar4 = (uint)bVar1;
        if (((int)(uVar4 + 1) < *(int *)(param_1 + 0x44)) &&
           (*(int *)(param_1 + 0x44) == uVar4 + 2 + (uint)pbVar2[uVar4 + 1])) {
          local_34 = 0;
          puVar3 = (undefined4 *)CRYPTO_malloc(uVar4,"s3_srvr.c",0xdfd);
          *(undefined4 **)(param_1 + 0x174) = puVar3;
          if (puVar3 == (undefined4 *)0x0) {
            ERR_put_error(0x14,0x132,0x41,"s3_srvr.c",0xe00);
          }
          else {
            if (uVar4 < 4) {
              if ((uVar4 != 0) && (*(byte *)puVar3 = pbVar2[1], (bVar1 & 2) != 0)) {
                *(undefined2 *)((int)puVar3 + (uVar4 - 2)) = *(undefined2 *)(pbVar2 + (uVar4 - 1));
              }
            }
            else {
              *puVar3 = *(undefined4 *)(pbVar2 + 1);
              *(undefined4 *)((int)puVar3 + (uVar4 - 4)) = *(undefined4 *)(pbVar2 + (uVar4 - 3));
              iVar5 = (int)puVar3 - (int)(undefined4 *)((uint)(puVar3 + 1) & 0xfffffffc);
              puVar6 = (undefined4 *)(pbVar2 + (1 - iVar5));
              puVar3 = (undefined4 *)((uint)(puVar3 + 1) & 0xfffffffc);
              for (uVar4 = iVar5 + uVar4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
                *puVar3 = *puVar6;
                puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
                puVar3 = puVar3 + (uint)bVar7 * -2 + 1;
              }
            }
            *(byte *)(param_1 + 0x178) = bVar1;
            local_34 = 1;
          }
        }
      }
      goto LAB_0809ccdc;
    }
    line = 0xde7;
    iVar5 = 0x163;
  }
  ERR_put_error(0x14,0x132,iVar5,"s3_srvr.c",line);
  local_34 = -1;
LAB_0809ccdc:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_34;
}

