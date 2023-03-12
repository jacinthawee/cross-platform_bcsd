
/* WARNING: Could not reconcile some variable overlaps */

int X509_cmp_time(ASN1_TIME *s,time_t *t)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  ASN1_TIME *pAVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  long offset_sec;
  int in_GS_OFFSET;
  time_t local_64;
  ASN1_TIME local_60;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  char local_44 [12];
  uchar local_38;
  char local_37;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar6 = s->type;
  puVar2 = (undefined4 *)s->data;
  if (iVar6 == 0x17) {
    if (s->length - 0xbU < 7) {
      local_50 = *puVar2;
      pcVar7 = (char *)((int)&local_48 + 2);
      puVar4 = (undefined4 *)((int)puVar2 + 10);
      local_4c = puVar2[1];
      local_48 = local_48 & 0xffff0000 | (uint)*(ushort *)(puVar2 + 2);
      goto LAB_0815f2fb;
    }
  }
  else if (0xc < s->length) {
    local_50 = *puVar2;
    pcVar7 = local_44;
    puVar4 = puVar2 + 3;
    local_4c = puVar2[1];
    local_48 = puVar2[2];
LAB_0815f2fb:
    cVar1 = *(char *)puVar4;
    if (((cVar1 - 0x2bU & 0xfd) == 0) || (cVar1 == 'Z')) {
      *pcVar7 = '0';
      pcVar7[1] = '0';
    }
    else {
      *pcVar7 = cVar1;
      pcVar7[1] = *(char *)((int)puVar4 + 1);
      if (*(char *)((int)puVar4 + 2) == '.') {
        cVar1 = *(char *)((int)puVar4 + 3);
        puVar4 = (undefined4 *)((int)puVar4 + 3);
        while ((byte)(cVar1 - 0x30U) < 10) {
          puVar4 = (undefined4 *)((int)puVar4 + 1);
          cVar1 = *(char *)puVar4;
        }
      }
      else {
        puVar4 = (undefined4 *)((int)puVar4 + 2);
      }
    }
    pcVar7[2] = 'Z';
    pcVar7[3] = '\0';
    cVar1 = *(char *)puVar4;
    if (cVar1 == 'Z') {
      offset_sec = 0;
    }
    else {
      if ((cVar1 - 0x2bU & 0xfd) != 0) goto LAB_0815f2bd;
      iVar8 = *(char *)(puVar4 + 1) + -0x30 + (*(char *)((int)puVar4 + 3) * 5 + -0xf0) * 2 +
              (*(char *)((int)puVar4 + 2) + -0x30 + (*(char *)((int)puVar4 + 1) * 5 + -0xf0) * 2) *
              0x3c;
      if (cVar1 == '-') {
        offset_sec = iVar8 * -0x3c;
      }
      else {
        offset_sec = iVar8 * 0x3c;
      }
    }
    local_60.flags = 0;
    local_60.length = 0x18;
    local_60.type = iVar6;
    local_60.data = &local_38;
    if (t == (time_t *)0x0) {
      time(&local_64);
      if ((local_60.flags & 0x40U) == 0) goto LAB_0815f3f1;
LAB_0815f403:
      pAVar5 = ASN1_TIME_adj(&local_60,local_64,0,offset_sec);
    }
    else {
      local_64 = *t;
LAB_0815f3f1:
      if (local_60.type == 0x17) {
        pAVar5 = ASN1_UTCTIME_adj(&local_60,local_64,0,offset_sec);
      }
      else {
        if (local_60.type != 0x18) goto LAB_0815f403;
        pAVar5 = ASN1_GENERALIZEDTIME_adj(&local_60,local_64,0,offset_sec);
      }
    }
    if (pAVar5 != (ASN1_TIME *)0x0) {
      if (s->type == 0x17) {
        iVar6 = local_50._1_1_ + -0x30 + ((char)local_50 * 5 + -0xf0) * 2;
        if (iVar6 < 0x32) {
          iVar6 = iVar6 + 100;
        }
        iVar8 = local_37 + -0x30 + ((char)local_38 * 5 + -0xf0) * 2;
        if (iVar8 < 0x32) {
          iVar8 = iVar8 + 100;
        }
        if (iVar6 < iVar8) {
          iVar3 = -1;
          goto LAB_0815f2bf;
        }
        iVar3 = 1;
        if (iVar8 < iVar6) goto LAB_0815f2bf;
      }
      iVar3 = strcmp((char *)&local_50,(char *)&local_38);
      if (iVar3 == 0) {
        iVar3 = -1;
      }
      goto LAB_0815f2bf;
    }
  }
LAB_0815f2bd:
  iVar3 = 0;
LAB_0815f2bf:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

