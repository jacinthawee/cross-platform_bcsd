
int X509_cmp_time(ASN1_TIME *s,time_t *t)

{
  ASN1_TIME *pAVar1;
  byte *pbVar2;
  byte bVar3;
  uint *puVar4;
  long offset_sec;
  int iVar5;
  uint *puVar6;
  int iVar7;
  byte *pbVar8;
  time_t local_64;
  ASN1_TIME local_60;
  uint local_50;
  uint uStack_4c;
  undefined4 local_48;
  byte abStack_44 [12];
  byte local_38;
  byte local_37;
  int local_1c;
  
  iVar7 = s->type;
  puVar4 = (uint *)s->data;
  local_1c = __TMC_END__;
  if (iVar7 == 0x17) {
    if (s->length - 0xbU < 7) {
      local_50 = *puVar4;
      uStack_4c = puVar4[1];
      puVar6 = (uint *)((int)puVar4 + 10);
      pbVar8 = (byte *)((int)&local_48 + 2);
      local_48 = local_48 & 0xffff0000 | (uint)*(ushort *)(puVar4 + 2);
      bVar3 = *(byte *)puVar6;
      if (bVar3 != 0x2d && bVar3 != 0x5a) goto LAB_000c9ef6;
      goto LAB_000c9e24;
    }
  }
  else if (0xc < s->length) {
    local_48 = puVar4[2];
    local_50 = *puVar4;
    puVar6 = puVar4 + 3;
    uStack_4c = puVar4[1];
    pbVar8 = abStack_44;
    bVar3 = *(byte *)puVar6;
    if (bVar3 == 0x2d || bVar3 == 0x5a) {
LAB_000c9e24:
      pbVar2 = pbVar8 + 2;
      *pbVar8 = 0x30;
      pbVar8[1] = 0x30;
    }
    else {
LAB_000c9ef6:
      if (bVar3 == 0x2b) goto LAB_000c9e24;
      pbVar2 = pbVar8 + 2;
      *pbVar8 = bVar3;
      pbVar8[1] = *(byte *)((int)puVar6 + 1);
      if (*(byte *)((int)puVar6 + 2) == 0x2e) {
        pbVar8 = (byte *)((int)puVar6 + 3);
        puVar6 = (uint *)((int)puVar6 + 3);
        bVar3 = *pbVar8;
        while (bVar3 - 0x30 < 10) {
          puVar6 = (uint *)((int)puVar6 + 1);
          bVar3 = *(byte *)puVar6;
        }
      }
      else {
        puVar6 = (uint *)((int)puVar6 + 2);
      }
    }
    offset_sec = 0;
    *pbVar2 = 0x5a;
    pbVar2[1] = 0;
    bVar3 = *(byte *)puVar6;
    if (bVar3 != 0x5a) {
      if (bVar3 != 0x2d && bVar3 != 0x2b) goto LAB_000c9df0;
      iVar5 = (*(byte *)(puVar6 + 1) - 0x30) + (*(byte *)((int)puVar6 + 3) - 0x30) * 10 +
              ((*(byte *)((int)puVar6 + 2) - 0x30) + (*(byte *)((int)puVar6 + 1) - 0x30) * 10) *
              0x3c;
      if (bVar3 == 0x2d) {
        iVar5 = -iVar5;
      }
      offset_sec = iVar5 * 0x3c;
    }
    local_60.flags = 0;
    local_60.length = 0x18;
    local_60.type = iVar7;
    local_60.data = &local_38;
    if (t == (time_t *)0x0) {
      time(&local_64);
      if ((local_60.flags & 0x40U) == 0) goto LAB_000c9e9e;
LAB_000c9ea8:
      pAVar1 = ASN1_TIME_adj(&local_60,local_64,0,offset_sec);
    }
    else {
      local_64 = *t;
LAB_000c9e9e:
      if (local_60.type == 0x17) {
        pAVar1 = ASN1_UTCTIME_adj(&local_60,local_64,0,offset_sec);
      }
      else {
        if (local_60.type != 0x18) goto LAB_000c9ea8;
        pAVar1 = ASN1_GENERALIZEDTIME_adj(&local_60,local_64,0,offset_sec);
      }
    }
    if (pAVar1 != (ASN1_TIME *)0x0) {
      if (s->type == 0x17) {
        iVar7 = ((local_50 >> 8 & 0xff) - 0x30) + ((local_50 & 0xff) - 0x30) * 10;
        if (iVar7 < 0x32) {
          iVar7 = iVar7 + 100;
        }
        iVar5 = (local_37 - 0x30) + (local_38 - 0x30) * 10;
        if (iVar5 < 0x32) {
          iVar5 = iVar5 + 100;
        }
        if (iVar7 < iVar5) {
          iVar7 = -1;
          goto LAB_000c9df2;
        }
        if (iVar5 < iVar7) {
          iVar7 = 1;
          goto LAB_000c9df2;
        }
      }
      iVar7 = strcmp((char *)&local_50,(char *)&local_38);
      if (iVar7 == 0) {
        iVar7 = -1;
      }
      goto LAB_000c9df2;
    }
  }
LAB_000c9df0:
  iVar7 = 0;
LAB_000c9df2:
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}

