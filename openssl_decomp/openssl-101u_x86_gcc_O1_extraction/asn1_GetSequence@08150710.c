
int asn1_GetSequence(ASN1_const_CTX *c,long *length)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uchar *puVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar11;
  uint local_28;
  byte *local_24;
  byte *pbVar10;
  
  iVar7 = *length;
  if (iVar7 != 0) {
    pbVar3 = c->p;
    bVar1 = *pbVar3;
    uVar6 = bVar1 & 0x1f;
    if ((char)uVar6 == '\x1f') {
      iVar8 = iVar7 + -1;
      if (iVar8 != 0) {
        uVar6 = 0;
        pbVar11 = pbVar3;
        while( true ) {
          bVar2 = pbVar11[1];
          if (-1 < (char)bVar2) break;
          uVar6 = uVar6 << 7 | bVar2 & 0x7f;
          iVar8 = iVar8 + -1;
          if ((iVar8 == 0) || (pbVar11 = pbVar11 + 1, 0xffffff < (int)uVar6)) goto LAB_08150741;
        }
        iVar8 = iVar8 + -1;
        if (iVar8 != 0) {
          pbVar11 = pbVar11 + 2;
          uVar6 = (uint)bVar2 | uVar6 << 7;
          goto LAB_081507c6;
        }
      }
    }
    else {
      iVar8 = iVar7 + -1;
      if (iVar8 != 0) {
        pbVar11 = pbVar3 + 1;
LAB_081507c6:
        c->tag = uVar6;
        c->xclass = bVar1 & 0xc0;
        if (0 < iVar8) {
          bVar5 = bVar1 & 0x20;
          bVar2 = *pbVar11;
          if (bVar2 == 0x80) {
            local_24 = pbVar11 + 1;
            c->slen = 0;
            if ((bVar1 & 0x20) == 0) goto LAB_08150741;
            local_28 = 0;
            uVar6 = 1;
          }
          else {
            uVar6 = bVar2 & 0x7f;
            local_24 = pbVar11 + 1;
            local_28 = uVar6;
            if ((char)bVar2 < '\0') {
              if ((4 < uVar6) || (iVar8 <= (int)uVar6)) goto LAB_08150741;
              if ((bVar2 & 0x7f) == 0) {
                c->slen = 0;
                local_28 = 0;
                uVar6 = 0;
                goto LAB_08150821;
              }
              local_28 = 0;
              pbVar10 = local_24;
              do {
                pbVar9 = pbVar10 + 1;
                local_28 = local_28 << 8 | (uint)*pbVar10;
                pbVar10 = pbVar9;
              } while (pbVar9 != pbVar11 + uVar6 + 1);
              local_24 = local_24 + uVar6;
            }
            if ((int)local_28 < 0) goto LAB_08150741;
            c->slen = local_28;
            uVar6 = 0;
          }
LAB_08150821:
          if (iVar7 - ((int)local_24 - (int)pbVar3) < (int)local_28) {
            ERR_put_error(0xd,0x72,0x9b,"asn1_lib.c",0x93);
            bVar5 = bVar5 | 0x80;
          }
          uVar6 = uVar6 | bVar5;
          c->inf = uVar6;
          c->p = local_24;
          if ((bVar5 & 0x80) == 0) {
            if (c->tag != 0x10) {
              c->error = 0x3d;
              return 0;
            }
            puVar4 = c->max;
            iVar7 = *length - ((int)local_24 - (int)pbVar3);
            *length = iVar7;
            if ((puVar4 != (uchar *)0x0) && (iVar7 < 0)) {
              c->error = 0x3e;
              return bVar5 & 0x80;
            }
            if (uVar6 == 0x21) {
              c->slen = iVar7;
            }
            c->eos = 0;
            return 1;
          }
          goto LAB_08150763;
        }
      }
    }
  }
LAB_08150741:
  ERR_put_error(0xd,0x72,0x7b,"asn1_lib.c",0x9d);
  c->inf = 0x80;
LAB_08150763:
  c->error = 0x3c;
  return 0;
}

