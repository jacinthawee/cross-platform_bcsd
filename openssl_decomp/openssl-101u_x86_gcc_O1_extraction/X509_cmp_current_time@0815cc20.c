
/* WARNING: Could not reconcile some variable overlaps */

int X509_cmp_current_time(ASN1_TIME *s)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  ASN1_TIME *pAVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
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
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar6 = s->length;
  puVar8 = (undefined4 *)s->data;
  if (s->type == 0x17) {
    if (iVar6 - 0xbU < 7) {
      local_50 = *puVar8;
      iVar6 = iVar6 + -10;
      puVar3 = (undefined4 *)((int)puVar8 + 10);
      pcVar7 = (char *)((int)&local_48 + 2);
      local_4c = puVar8[1];
      local_48 = local_48 & 0xffff0000 | (uint)*(ushort *)(puVar8 + 2);
      goto LAB_0815cc8e;
    }
  }
  else if (iVar6 - 0xdU < 0xb) {
    local_50 = *puVar8;
    pcVar7 = local_44;
    puVar3 = puVar8 + 3;
    iVar6 = iVar6 + -0xc;
    local_4c = puVar8[1];
    local_48 = puVar8[2];
LAB_0815cc8e:
    cVar1 = *(char *)puVar3;
    if (((cVar1 - 0x2bU & 0xfd) == 0) || (cVar1 == 'Z')) {
      *pcVar7 = '0';
      pcVar7[1] = '0';
      puVar8 = puVar3;
LAB_0815cd0a:
      pcVar7[2] = 'Z';
      pcVar7[3] = '\0';
      goto LAB_0815cd11;
    }
    if (iVar6 != 1) {
      *pcVar7 = cVar1;
      pcVar7[1] = *(char *)((int)puVar3 + 1);
      if (iVar6 + -2 != 0) {
        if (*(char *)((int)puVar3 + 2) != '.') {
          puVar8 = (undefined4 *)((int)puVar3 + 2);
          iVar6 = iVar6 + -2;
          goto LAB_0815cd0a;
        }
        iVar6 = iVar6 + -3;
        puVar8 = (undefined4 *)((int)puVar3 + 3);
        if (iVar6 != 0) {
          if ((byte)(*(char *)((int)puVar3 + 3) - 0x30U) < 10) {
            iVar5 = 0;
            do {
              iVar5 = iVar5 + 1;
              puVar8 = (undefined4 *)((int)puVar8 + 1);
              iVar6 = iVar6 + -1;
              if ((2 < iVar5) || (iVar6 == 0)) break;
            } while ((byte)(*(char *)puVar8 - 0x30U) < 10);
            pcVar7[2] = 'Z';
            pcVar7[3] = '\0';
            if (iVar6 == 0) goto LAB_0815cc51;
          }
          else {
            pcVar7[2] = 'Z';
            pcVar7[3] = '\0';
          }
LAB_0815cd11:
          cVar1 = *(char *)puVar8;
          if (cVar1 == 'Z') {
            offset_sec = 0;
            if (iVar6 == 1) goto LAB_0815cdc0;
          }
          else if (((((cVar1 - 0x2bU & 0xfd) == 0) && (iVar6 == 5)) &&
                   ((byte)(*(char *)((int)puVar8 + 1) - 0x30U) < 10)) &&
                  ((((byte)(*(char *)((int)puVar8 + 2) - 0x30U) < 10 &&
                    ((byte)(*(char *)((int)puVar8 + 3) - 0x30U) < 10)) &&
                   ((byte)(*(char *)(puVar8 + 1) - 0x30U) < 10)))) {
            iVar6 = 0x3c;
            if (cVar1 == '-') {
              iVar6 = -0x3c;
            }
            offset_sec = (*(char *)(puVar8 + 1) + -0x30 +
                          (*(char *)((int)puVar8 + 3) * 5 + -0xf0) * 2 +
                         (*(char *)((int)puVar8 + 2) + -0x30 +
                         (*(char *)((int)puVar8 + 1) * 5 + -0xf0) * 2) * 0x3c) * iVar6;
LAB_0815cdc0:
            local_60.type = s->type;
            local_60.flags = 0;
            local_60.length = 0x18;
            local_60.data = &local_38;
            time(&local_64);
            if ((local_60.flags & 0x40U) == 0) {
              if (local_60.type == 0x17) {
                pAVar4 = ASN1_UTCTIME_adj(&local_60,local_64,0,offset_sec);
              }
              else {
                if (local_60.type != 0x18) goto LAB_0815ce0c;
                pAVar4 = ASN1_GENERALIZEDTIME_adj(&local_60,local_64,0,offset_sec);
              }
            }
            else {
LAB_0815ce0c:
              pAVar4 = ASN1_TIME_adj(&local_60,local_64,0,offset_sec);
            }
            if (pAVar4 != (ASN1_TIME *)0x0) {
              if (s->type == 0x17) {
                iVar6 = local_50._1_1_ + -0x30 + ((char)local_50 * 5 + -0xf0) * 2;
                if (iVar6 < 0x32) {
                  iVar6 = iVar6 + 100;
                }
                iVar5 = local_37 + -0x30 + ((char)local_38 * 5 + -0xf0) * 2;
                if (iVar5 < 0x32) {
                  iVar5 = iVar5 + 100;
                }
                if (iVar6 < iVar5) {
                  iVar2 = -1;
                  goto LAB_0815cc53;
                }
                iVar2 = 1;
                if (iVar5 < iVar6) goto LAB_0815cc53;
              }
              iVar2 = strcmp((char *)&local_50,(char *)&local_38);
              if (iVar2 == 0) {
                iVar2 = -1;
              }
              goto LAB_0815cc53;
            }
          }
        }
      }
    }
  }
LAB_0815cc51:
  iVar2 = 0;
LAB_0815cc53:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

