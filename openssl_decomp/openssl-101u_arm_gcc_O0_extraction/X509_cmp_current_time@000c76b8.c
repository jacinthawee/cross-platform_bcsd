
int X509_cmp_current_time(ASN1_TIME *s)

{
  byte bVar1;
  uint uVar2;
  ASN1_TIME *pAVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  long offset_sec;
  uint *puVar10;
  byte *pbVar11;
  time_t local_64;
  ASN1_TIME local_60;
  uint local_50;
  uint uStack_4c;
  undefined4 local_48;
  byte local_44 [12];
  byte local_38;
  byte local_37;
  int local_1c;
  
  iVar9 = s->type;
  iVar6 = s->length;
  puVar8 = (uint *)s->data;
  local_1c = __stack_chk_guard;
  if (iVar9 == 0x17) {
    if (iVar6 - 0xbU < 7) {
      local_50 = *puVar8;
      uStack_4c = puVar8[1];
      iVar4 = -10;
      puVar10 = (uint *)((int)puVar8 + 10);
      pbVar11 = (byte *)((int)&local_48 + 2);
      local_48 = local_48 & 0xffff0000 | (uint)*(ushort *)(puVar8 + 2);
      goto LAB_000c770c;
    }
  }
  else if (iVar6 - 0xdU < 0xb) {
    local_50 = *puVar8;
    uStack_4c = puVar8[1];
    iVar4 = -0xc;
    local_48 = puVar8[2];
    pbVar11 = local_44;
    puVar10 = puVar8 + 3;
LAB_000c770c:
    iVar6 = iVar6 + iVar4;
    bVar1 = *(byte *)puVar10;
    if ((bVar1 == 0x2d || bVar1 == 0x5a) || (iVar4 = 0, bVar1 == 0x2b)) {
      *pbVar11 = 0x30;
      pbVar11[1] = 0x30;
      puVar8 = puVar10;
LAB_000c77a8:
      pbVar11[2] = 0x5a;
      pbVar11[3] = 0;
      goto LAB_000c77b0;
    }
    if (iVar6 != 1) {
      *pbVar11 = bVar1;
      pbVar11[1] = *(byte *)((int)puVar10 + 1);
      if (iVar6 + -2 != 0) {
        if (*(byte *)((int)puVar10 + 2) != 0x2e) {
          puVar8 = (uint *)((int)puVar10 + 2);
          iVar6 = iVar6 + -2;
          goto LAB_000c77a8;
        }
        iVar6 = iVar6 + -3;
        puVar8 = (uint *)((int)puVar10 + 3);
        if (iVar6 != 0) {
          if (*(byte *)((int)puVar10 + 3) - 0x30 < 10) {
            puVar10 = puVar10 + 1;
            do {
              puVar8 = puVar10;
              iVar6 = iVar6 + -1;
              iVar4 = iVar4 + 1;
              if (2 < iVar4 || iVar6 == 0) break;
              puVar10 = (uint *)((int)puVar8 + 1);
            } while (*(byte *)puVar8 - 0x30 < 10);
            pbVar11[2] = 0x5a;
            pbVar11[3] = 0;
            if (iVar6 == 0) goto LAB_000c76e0;
          }
          else {
            pbVar11[3] = 0;
            pbVar11[2] = 0x5a;
          }
LAB_000c77b0:
          bVar1 = *(byte *)puVar8;
          if (bVar1 == 0x5a) {
            if (iVar6 == 1) {
              offset_sec = 0;
              goto LAB_000c781e;
            }
          }
          else if ((((bVar1 == 0x2d || bVar1 == 0x2b) && (iVar6 == 5)) &&
                   (uVar7 = *(byte *)((int)puVar8 + 1) - 0x30, (uVar7 & 0xff) < 10)) &&
                  (((uVar5 = *(byte *)((int)puVar8 + 2) - 0x30, (uVar5 & 0xff) < 10 &&
                    (uVar2 = *(byte *)((int)puVar8 + 3) - 0x30, (uVar2 & 0xff) < 10)) &&
                   ((*(byte *)(puVar8 + 1) - 0x30 & 0xff) < 10)))) {
            if (bVar1 == 0x2d) {
              iVar6 = -0x3c;
            }
            else {
              iVar6 = 0x3c;
            }
            offset_sec = ((*(byte *)(puVar8 + 1) - 0x30) + uVar2 * 10 + (uVar5 + uVar7 * 10) * 0x3c)
                         * iVar6;
LAB_000c781e:
            local_60.flags = 0;
            local_60.length = 0x18;
            local_60.type = iVar9;
            local_60.data = &local_38;
            time(&local_64);
            if ((local_60.flags & 0x40U) == 0) {
              if (local_60.type == 0x17) {
                pAVar3 = ASN1_UTCTIME_adj(&local_60,local_64,0,offset_sec);
              }
              else {
                if (local_60.type != 0x18) goto LAB_000c7844;
                pAVar3 = ASN1_GENERALIZEDTIME_adj(&local_60,local_64,0,offset_sec);
              }
            }
            else {
LAB_000c7844:
              pAVar3 = ASN1_TIME_adj(&local_60,local_64,0,offset_sec);
            }
            if (pAVar3 != (ASN1_TIME *)0x0) {
              if (s->type == 0x17) {
                iVar6 = ((local_50 >> 8 & 0xff) - 0x30) + ((local_50 & 0xff) - 0x30) * 10;
                if (iVar6 < 0x32) {
                  iVar6 = iVar6 + 100;
                }
                iVar9 = (local_37 - 0x30) + (local_38 - 0x30) * 10;
                if (iVar9 < 0x32) {
                  iVar9 = iVar9 + 100;
                }
                if (iVar6 < iVar9) {
                  iVar6 = -1;
                  goto LAB_000c76e2;
                }
                if (iVar9 < iVar6) {
                  iVar6 = 1;
                  goto LAB_000c76e2;
                }
              }
              iVar6 = strcmp((char *)&local_50,(char *)&local_38);
              if (iVar6 == 0) {
                iVar6 = -1;
              }
              goto LAB_000c76e2;
            }
          }
        }
      }
    }
  }
LAB_000c76e0:
  iVar6 = 0;
LAB_000c76e2:
  if (local_1c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}

