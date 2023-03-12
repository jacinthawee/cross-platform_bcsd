
int asn1_GetSequence(ASN1_const_CTX *c,long *length)

{
  byte bVar1;
  ushort uVar2;
  uint3 uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uchar *puVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  bool bVar14;
  
  iVar8 = *length;
  pbVar4 = c->p;
  if (iVar8 != 0) {
    uVar13 = (uint)*pbVar4;
    uVar9 = uVar13 & 0x1f;
    if (uVar9 == 0x1f) {
      iVar5 = iVar8 + -1;
      if (iVar5 != 0) {
        uVar9 = 0;
        pbVar10 = pbVar4 + 1;
        while( true ) {
          pbVar12 = pbVar10 + 1;
          bVar1 = *pbVar10;
          if ((bVar1 & 0x80) == 0) break;
          iVar5 = iVar5 + -1;
          uVar9 = bVar1 & 0x7f | uVar9 << 7;
          if ((iVar5 == 0) || (pbVar10 = pbVar12, 0xffffff < (int)uVar9)) goto LAB_000c2070;
        }
        iVar5 = iVar5 + -1;
        if (iVar5 != 0) {
          uVar9 = (uint)bVar1 | uVar9 << 7;
          goto LAB_000c20d0;
        }
      }
    }
    else {
      iVar5 = iVar8 + -1;
      if (iVar5 != 0) {
        pbVar12 = pbVar4 + 1;
LAB_000c20d0:
        c->tag = uVar9;
        c->xclass = uVar13 & 0xc0;
        if (0 < iVar5) {
          uVar9 = (uint)*pbVar12;
          if (uVar9 == 0x80) {
            pbVar10 = pbVar12 + 1;
            uVar6 = 0;
            uVar9 = 1;
          }
          else {
            uVar11 = uVar9 & 0x7f;
            pbVar10 = pbVar12 + 1;
            uVar6 = uVar11;
            if ((int)(uVar9 << 0x18) < 0) {
              if ((4 < uVar11) || (iVar5 == 1)) goto LAB_000c2070;
              if ((*pbVar12 & 0x7f) != 0) {
                pbVar10 = pbVar12 + 2;
                uVar6 = (uint)pbVar12[1];
                if (iVar5 == 2) goto LAB_000c2070;
                if (uVar11 != 1) {
                  pbVar10 = pbVar12 + 3;
                  uVar2 = CONCAT11(pbVar12[1],pbVar12[2]);
                  uVar6 = (uint)uVar2;
                  if (iVar5 == 3) goto LAB_000c2070;
                  if (uVar11 != 2) {
                    pbVar10 = pbVar12 + 4;
                    uVar3 = CONCAT21(uVar2,pbVar12[3]);
                    uVar6 = (uint)uVar3;
                    if (iVar5 == 4) goto LAB_000c2070;
                    if (uVar11 != 3) {
                      pbVar10 = pbVar12 + 5;
                      uVar6 = CONCAT31(uVar3,pbVar12[4]);
                      if (iVar5 == 5) goto LAB_000c2070;
                    }
                  }
                }
              }
            }
            if ((int)uVar6 < 0) goto LAB_000c2070;
            uVar9 = 0;
          }
          uVar13 = uVar13 & 0x20;
          c->slen = uVar6;
          if ((int)(pbVar4 + (iVar8 - (int)pbVar10)) < (int)uVar6) {
            ERR_put_error(0xd,0x72,0x9b,"asn1_lib.c",0x8e);
            uVar13 = uVar13 | 0x80;
          }
          uVar9 = uVar13 | uVar9;
          c->p = pbVar10;
          c->inf = uVar9;
          if ((uVar13 & 0x80) == 0) {
            bVar14 = c->tag != 0x10;
            if (bVar14) {
              uVar9 = 0x3d;
            }
            if (bVar14) {
              c->error = uVar9;
              return 0;
            }
            puVar7 = c->max;
            pbVar4 = pbVar4 + (*length - (int)pbVar10);
            *length = (long)pbVar4;
            if (puVar7 != (uchar *)0x0) {
              if ((int)pbVar4 < 0) {
                uVar9 = 0x3e;
              }
              if ((int)pbVar4 < 0) {
                c->error = uVar9;
                return 0;
              }
            }
            if (uVar9 == 0x21) {
              pbVar10 = *c->pp + ((int)pbVar4 - (int)pbVar10);
            }
            c->eos = 0;
            if (uVar9 == 0x21) {
              c->slen = (long)pbVar10;
            }
            return 1;
          }
          goto LAB_000c208a;
        }
      }
    }
  }
LAB_000c2070:
  ERR_put_error(0xd,0x72,0x7b,"asn1_lib.c",0x96);
  c->inf = 0x80;
LAB_000c208a:
  c->error = 0x3c;
  return 0;
}

