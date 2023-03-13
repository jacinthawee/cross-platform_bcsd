
int OBJ_create_objects(BIO *in)

{
  byte *buf;
  byte bVar1;
  byte bVar2;
  ushort *puVar3;
  int iVar4;
  ushort **ppuVar5;
  byte *pbVar6;
  byte *sn;
  byte *pbVar7;
  int in_GS_OFFSET;
  int local_234;
  byte abStack_221 [513];
  int local_20;
  
  pbVar7 = (byte *)0x0;
  buf = abStack_221 + 1;
  local_234 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  while (iVar4 = BIO_gets(in,(char *)buf,0x200), 0 < iVar4) {
    abStack_221[iVar4] = 0;
    ppuVar5 = __ctype_b_loc();
    puVar3 = *ppuVar5;
    if ((puVar3[abStack_221[1]] & 8) == 0) break;
    pbVar6 = buf;
    bVar1 = abStack_221[1];
    if ((puVar3[abStack_221[1]] & 0x800) != 0) goto LAB_080d5348;
    while (bVar1 == 0x2e) {
LAB_080d5348:
      do {
        pbVar6 = pbVar6 + 1;
        bVar1 = *pbVar6;
      } while ((*(byte *)((int)puVar3 + (uint)bVar1 * 2 + 1) & 8) != 0);
    }
    sn = (byte *)0x0;
    if (bVar1 != 0) {
      bVar1 = pbVar6[1];
      *pbVar6 = 0;
      sn = pbVar6 + 1;
      bVar2 = *(byte *)((int)puVar3 + (uint)bVar1 * 2 + 1);
      while ((bVar2 & 0x20) != 0) {
        sn = sn + 1;
        bVar1 = *sn;
        bVar2 = *(byte *)((int)puVar3 + (uint)bVar1 * 2 + 1);
      }
      pbVar6 = sn;
      if (bVar1 == 0) {
        sn = (byte *)0x0;
      }
      else {
        do {
          pbVar7 = pbVar6;
          pbVar6 = pbVar7 + 1;
          if (*pbVar6 == 0) {
            pbVar7 = (byte *)0x0;
            goto joined_r0x080d53e4;
          }
        } while ((*(byte *)((int)puVar3 + (uint)*pbVar6 * 2 + 1) & 0x20) == 0);
        bVar1 = pbVar7[2];
        *pbVar6 = 0;
        pbVar7 = pbVar7 + 2;
        bVar2 = *(byte *)((int)puVar3 + (uint)bVar1 * 2 + 1);
        while ((bVar2 & 0x20) != 0) {
          pbVar7 = pbVar7 + 1;
          bVar1 = *pbVar7;
          bVar2 = *(byte *)((int)puVar3 + (uint)bVar1 * 2 + 1);
        }
        if (bVar1 == 0) {
          pbVar7 = (byte *)0x0;
        }
      }
    }
joined_r0x080d53e4:
    if ((abStack_221[1] == 0) ||
       (iVar4 = OBJ_create((char *)buf,(char *)sn,(char *)pbVar7), iVar4 == 0)) break;
    local_234 = local_234 + 1;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_234;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

