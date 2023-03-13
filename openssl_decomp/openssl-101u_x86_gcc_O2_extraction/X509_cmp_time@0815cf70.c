
/* WARNING: Could not reconcile some variable overlaps */

int X509_cmp_time(ASN1_TIME *s,time_t *t)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  ASN1_TIME *pAVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  long offset_sec;
  undefined4 *puVar8;
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
  
  iVar7 = s->length;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  puVar8 = (undefined4 *)s->data;
  if (s->type == 0x17) {
    if (iVar7 - 0xbU < 7) {
      local_50 = *puVar8;
      puVar3 = (undefined4 *)((int)puVar8 + 10);
      local_4c = puVar8[1];
      local_48 = local_48 & 0xffff0000 | (uint)*(ushort *)(puVar8 + 2);
      iVar7 = iVar7 + -10;
      pcVar5 = (char *)((int)&local_48 + 2);
      goto LAB_0815cfee;
    }
  }
  else if (iVar7 - 0xdU < 0xb) {
    local_50 = *puVar8;
    puVar3 = puVar8 + 3;
    local_4c = puVar8[1];
    local_48 = puVar8[2];
    iVar7 = iVar7 + -0xc;
    pcVar5 = local_44;
LAB_0815cfee:
    cVar1 = *(char *)puVar3;
    if (((cVar1 - 0x2bU & 0xfd) == 0) || (cVar1 == 'Z')) {
      *pcVar5 = '0';
      pcVar5[1] = '0';
      puVar8 = puVar3;
LAB_0815d06a:
      pcVar5[2] = 'Z';
      pcVar5[3] = '\0';
      goto LAB_0815d071;
    }
    if (iVar7 != 1) {
      *pcVar5 = cVar1;
      pcVar5[1] = *(char *)((int)puVar3 + 1);
      if (iVar7 + -2 != 0) {
        if (*(char *)((int)puVar3 + 2) != '.') {
          puVar8 = (undefined4 *)((int)puVar3 + 2);
          iVar7 = iVar7 + -2;
          goto LAB_0815d06a;
        }
        iVar7 = iVar7 + -3;
        puVar8 = (undefined4 *)((int)puVar3 + 3);
        if (iVar7 != 0) {
          if ((byte)(*(char *)((int)puVar3 + 3) - 0x30U) < 10) {
            iVar6 = 0;
            do {
              iVar6 = iVar6 + 1;
              puVar8 = (undefined4 *)((int)puVar8 + 1);
              iVar7 = iVar7 + -1;
              if ((2 < iVar6) || (iVar7 == 0)) break;
            } while ((byte)(*(char *)puVar8 - 0x30U) < 10);
            pcVar5[2] = 'Z';
            pcVar5[3] = '\0';
            if (iVar7 == 0) goto LAB_0815cfac;
          }
          else {
            pcVar5[2] = 'Z';
            pcVar5[3] = '\0';
          }
LAB_0815d071:
          cVar1 = *(char *)puVar8;
          if (cVar1 == 'Z') {
            offset_sec = 0;
            if (iVar7 == 1) goto LAB_0815d120;
          }
          else if (((((cVar1 - 0x2bU & 0xfd) == 0) && (iVar7 == 5)) &&
                   ((byte)(*(char *)((int)puVar8 + 1) - 0x30U) < 10)) &&
                  ((((byte)(*(char *)((int)puVar8 + 2) - 0x30U) < 10 &&
                    ((byte)(*(char *)((int)puVar8 + 3) - 0x30U) < 10)) &&
                   ((byte)(*(char *)(puVar8 + 1) - 0x30U) < 10)))) {
            iVar7 = 0x3c;
            if (cVar1 == '-') {
              iVar7 = -0x3c;
            }
            offset_sec = ((*(char *)((int)puVar8 + 2) + -0x30 +
                          (*(char *)((int)puVar8 + 1) * 5 + -0xf0) * 2) * 0x3c +
                         *(char *)(puVar8 + 1) + -0x30 +
                         (*(char *)((int)puVar8 + 3) * 5 + -0xf0) * 2) * iVar7;
LAB_0815d120:
            local_60.type = s->type;
            local_60.flags = 0;
            local_60.length = 0x18;
            local_60.data = &local_38;
            if (t == (time_t *)0x0) {
              time(&local_64);
              if ((local_60.flags & 0x40U) == 0) goto LAB_0815d151;
LAB_0815d163:
              pAVar4 = ASN1_TIME_adj(&local_60,local_64,0,offset_sec);
            }
            else {
              local_64 = *t;
LAB_0815d151:
              if (local_60.type == 0x17) {
                pAVar4 = ASN1_UTCTIME_adj(&local_60,local_64,0,offset_sec);
              }
              else {
                if (local_60.type != 0x18) goto LAB_0815d163;
                pAVar4 = ASN1_GENERALIZEDTIME_adj(&local_60,local_64,0,offset_sec);
              }
            }
            if (pAVar4 != (ASN1_TIME *)0x0) {
              if (s->type == 0x17) {
                iVar7 = local_50._1_1_ + -0x30 + ((char)local_50 * 5 + -0xf0) * 2;
                if (iVar7 < 0x32) {
                  iVar7 = iVar7 + 100;
                }
                iVar6 = local_37 + -0x30 + ((char)local_38 * 5 + -0xf0) * 2;
                if (iVar6 < 0x32) {
                  iVar6 = iVar6 + 100;
                }
                if (iVar7 < iVar6) {
                  iVar2 = -1;
                  goto LAB_0815cfae;
                }
                iVar2 = 1;
                if (iVar6 < iVar7) goto LAB_0815cfae;
              }
              iVar2 = strcmp((char *)&local_50,(char *)&local_38);
              if (iVar2 == 0) {
                iVar2 = -1;
              }
              goto LAB_0815cfae;
            }
          }
        }
      }
    }
  }
LAB_0815cfac:
  iVar2 = 0;
LAB_0815cfae:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

