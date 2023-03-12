
/* WARNING: Could not reconcile some variable overlaps */

int X509_cmp_current_time(ASN1_TIME *s)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  ASN1_TIME *pAVar5;
  int iVar6;
  int iVar7;
  long offset_sec;
  char *pcVar8;
  int in_GS_OFFSET;
  time_t local_54;
  ASN1_TIME local_50;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  char local_34 [12];
  uchar local_28;
  char local_27;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar6 = s->type;
  puVar2 = (undefined4 *)s->data;
  if (iVar6 == 0x17) {
    if (s->length - 0xbU < 7) {
      local_40 = *puVar2;
      pcVar8 = (char *)((int)&local_38 + 2);
      puVar4 = (undefined4 *)((int)puVar2 + 10);
      local_3c = puVar2[1];
      local_38 = local_38 & 0xffff0000 | (uint)*(ushort *)(puVar2 + 2);
      goto LAB_0815f053;
    }
  }
  else if (0xc < s->length) {
    local_40 = *puVar2;
    pcVar8 = local_34;
    puVar4 = puVar2 + 3;
    local_3c = puVar2[1];
    local_38 = puVar2[2];
LAB_0815f053:
    cVar1 = *(char *)puVar4;
    if (((cVar1 - 0x2bU & 0xfd) == 0) || (cVar1 == 'Z')) {
      *pcVar8 = '0';
      pcVar8[1] = '0';
    }
    else {
      *pcVar8 = cVar1;
      pcVar8[1] = *(char *)((int)puVar4 + 1);
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
    pcVar8[2] = 'Z';
    pcVar8[3] = '\0';
    cVar1 = *(char *)puVar4;
    if (cVar1 == 'Z') {
      offset_sec = 0;
    }
    else {
      if ((cVar1 - 0x2bU & 0xfd) != 0) goto LAB_0815f018;
      iVar7 = *(char *)(puVar4 + 1) + -0x30 + (*(char *)((int)puVar4 + 3) * 5 + -0xf0) * 2 +
              (*(char *)((int)puVar4 + 2) + -0x30 + (*(char *)((int)puVar4 + 1) * 5 + -0xf0) * 2) *
              0x3c;
      if (cVar1 == '-') {
        offset_sec = iVar7 * -0x3c;
      }
      else {
        offset_sec = iVar7 * 0x3c;
      }
    }
    local_50.flags = 0;
    local_50.length = 0x18;
    local_50.type = iVar6;
    local_50.data = &local_28;
    time(&local_54);
    if ((local_50.flags & 0x40U) == 0) {
      if (local_50.type == 0x17) {
        pAVar5 = ASN1_UTCTIME_adj(&local_50,local_54,0,offset_sec);
      }
      else {
        if (local_50.type != 0x18) goto LAB_0815f15f;
        pAVar5 = ASN1_GENERALIZEDTIME_adj(&local_50,local_54,0,offset_sec);
      }
    }
    else {
LAB_0815f15f:
      pAVar5 = ASN1_TIME_adj(&local_50,local_54,0,offset_sec);
    }
    if (pAVar5 != (ASN1_TIME *)0x0) {
      if (s->type == 0x17) {
        iVar6 = local_40._1_1_ + -0x30 + ((char)local_40 * 5 + -0xf0) * 2;
        if (iVar6 < 0x32) {
          iVar6 = iVar6 + 100;
        }
        iVar7 = local_27 + -0x30 + ((char)local_28 * 5 + -0xf0) * 2;
        if (iVar7 < 0x32) {
          iVar7 = iVar7 + 100;
        }
        if (iVar6 < iVar7) {
          iVar3 = -1;
          goto LAB_0815f01a;
        }
        iVar3 = 1;
        if (iVar7 < iVar6) goto LAB_0815f01a;
      }
      iVar3 = strcmp((char *)&local_40,(char *)&local_28);
      if (iVar3 == 0) {
        iVar3 = -1;
      }
      goto LAB_0815f01a;
    }
  }
LAB_0815f018:
  iVar3 = 0;
LAB_0815f01a:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

