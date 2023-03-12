
int X509_cmp_time(ASN1_TIME *s,time_t *t)

{
  byte bVar1;
  uint uVar2;
  ASN1_TIME *pAVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  long offset_sec;
  int iVar9;
  uint *puVar10;
  byte *pbVar11;
  time_t local_6c;
  ASN1_TIME local_68;
  uint local_58;
  uint uStack_54;
  undefined4 local_50;
  byte local_4c [12];
  byte local_40;
  byte local_3f;
  int local_24;
  
  iVar9 = s->type;
  iVar6 = s->length;
  puVar8 = (uint *)s->data;
  local_24 = __stack_chk_guard;
  if (iVar9 == 0x17) {
    if (iVar6 - 0xbU < 7) {
      local_58 = *puVar8;
      uStack_54 = puVar8[1];
      iVar4 = -10;
      puVar10 = (uint *)((int)puVar8 + 10);
      pbVar11 = (byte *)((int)&local_50 + 2);
      local_50 = local_50 & 0xffff0000 | (uint)*(ushort *)(puVar8 + 2);
      goto LAB_000c796e;
    }
  }
  else if (iVar6 - 0xdU < 0xb) {
    local_58 = *puVar8;
    uStack_54 = puVar8[1];
    iVar4 = -0xc;
    local_50 = puVar8[2];
    pbVar11 = local_4c;
    puVar10 = puVar8 + 3;
LAB_000c796e:
    iVar6 = iVar6 + iVar4;
    bVar1 = *(byte *)puVar10;
    if ((bVar1 == 0x2d || bVar1 == 0x5a) || (iVar4 = 0, bVar1 == 0x2b)) {
      *pbVar11 = 0x30;
      pbVar11[1] = 0x30;
      puVar8 = puVar10;
LAB_000c7a0a:
      pbVar11[2] = 0x5a;
      pbVar11[3] = 0;
      goto LAB_000c7a12;
    }
    if (iVar6 != 1) {
      *pbVar11 = bVar1;
      pbVar11[1] = *(byte *)((int)puVar10 + 1);
      if (iVar6 + -2 != 0) {
        if (*(byte *)((int)puVar10 + 2) != 0x2e) {
          puVar8 = (uint *)((int)puVar10 + 2);
          iVar6 = iVar6 + -2;
          goto LAB_000c7a0a;
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
            if (iVar6 == 0) goto LAB_000c7942;
          }
          else {
            pbVar11[3] = 0;
            pbVar11[2] = 0x5a;
          }
LAB_000c7a12:
          bVar1 = *(byte *)puVar8;
          if (bVar1 == 0x5a) {
            if (iVar6 == 1) {
              offset_sec = 0;
              goto LAB_000c7a80;
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
LAB_000c7a80:
            local_68.flags = 0;
            local_68.length = 0x18;
            local_68.type = iVar9;
            local_68.data = &local_40;
            if (t == (time_t *)0x0) {
              time(&local_6c);
              if ((local_68.flags & 0x40U) == 0) goto LAB_000c7a9a;
LAB_000c7aa4:
              pAVar3 = ASN1_TIME_adj(&local_68,local_6c,0,offset_sec);
            }
            else {
              local_6c = *t;
LAB_000c7a9a:
              if (local_68.type == 0x17) {
                pAVar3 = ASN1_UTCTIME_adj(&local_68,local_6c,0,offset_sec);
              }
              else {
                if (local_68.type != 0x18) goto LAB_000c7aa4;
                pAVar3 = ASN1_GENERALIZEDTIME_adj(&local_68,local_6c,0,offset_sec);
              }
            }
            if (pAVar3 != (ASN1_TIME *)0x0) {
              if (s->type == 0x17) {
                iVar6 = ((local_58 >> 8 & 0xff) - 0x30) + ((local_58 & 0xff) - 0x30) * 10;
                if (iVar6 < 0x32) {
                  iVar6 = iVar6 + 100;
                }
                iVar9 = (local_3f - 0x30) + (local_40 - 0x30) * 10;
                if (iVar9 < 0x32) {
                  iVar9 = iVar9 + 100;
                }
                if (iVar6 < iVar9) {
                  iVar6 = -1;
                  goto LAB_000c7944;
                }
                if (iVar9 < iVar6) {
                  iVar6 = 1;
                  goto LAB_000c7944;
                }
              }
              iVar6 = strcmp((char *)&local_58,(char *)&local_40);
              if (iVar6 == 0) {
                iVar6 = -1;
              }
              goto LAB_000c7944;
            }
          }
        }
      }
    }
  }
LAB_000c7942:
  iVar6 = 0;
LAB_000c7944:
  if (local_24 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}

