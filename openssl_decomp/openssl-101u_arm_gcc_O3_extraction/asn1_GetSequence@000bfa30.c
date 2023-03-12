
int asn1_GetSequence(ASN1_const_CTX *c,long *length)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar6;
  uchar *puVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  byte *pbVar5;
  
  iVar8 = *length;
  pbVar3 = c->p;
  if (iVar8 != 0) {
    bVar1 = *pbVar3;
    uVar13 = (uint)bVar1;
    uVar9 = uVar13 & 0x1f;
    if (uVar9 == 0x1f) {
      iVar6 = iVar8 + -1;
      if (iVar6 != 0) {
        uVar9 = 0;
        pbVar10 = pbVar3 + 1;
        while( true ) {
          pbVar11 = pbVar10 + 1;
          bVar2 = *pbVar10;
          if ((bVar2 & 0x80) == 0) break;
          iVar6 = iVar6 + -1;
          uVar9 = bVar2 & 0x7f | uVar9 << 7;
          if ((iVar6 == 0) || (pbVar10 = pbVar11, 0xffffff < (int)uVar9)) goto LAB_000bfa50;
        }
        iVar6 = iVar6 + -1;
        if (iVar6 != 0) {
          uVar9 = (uint)bVar2 | uVar9 << 7;
          goto LAB_000bfab2;
        }
      }
    }
    else {
      iVar6 = iVar8 + -1;
      if (iVar6 != 0) {
        pbVar11 = pbVar3 + 1;
LAB_000bfab2:
        c->tag = uVar9;
        c->xclass = uVar13 & 0xc0;
        if (0 < iVar6) {
          bVar2 = *pbVar11;
          uVar13 = uVar13 & 0x20;
          if (bVar2 == 0x80) {
            uVar9 = 0;
            c->slen = 0;
            if ((bVar1 & 0x20) == 0) goto LAB_000bfa50;
            pbVar10 = pbVar11 + 1;
            uVar12 = 1;
          }
          else {
            uVar9 = bVar2 & 0x7f;
            pbVar10 = pbVar11 + 1;
            if ((bVar2 & 0x80) == 0) {
LAB_000bfadc:
              if ((int)uVar9 < 0) goto LAB_000bfa50;
            }
            else {
              uVar12 = (uint)(4 < uVar9);
              if (iVar6 <= (int)uVar9) {
                uVar12 = 1;
              }
              if (uVar12 != 0) goto LAB_000bfa50;
              if ((bVar2 & 0x7f) != 0) {
                pbVar5 = pbVar10;
                do {
                  pbVar4 = pbVar5 + 1;
                  uVar12 = (uint)*pbVar5 | uVar12 << 8;
                  pbVar5 = pbVar4;
                } while (pbVar4 != pbVar11 + uVar9 + 1);
                pbVar10 = pbVar10 + uVar9;
                uVar9 = uVar12;
                goto LAB_000bfadc;
              }
            }
            uVar12 = 0;
            c->slen = uVar9;
          }
          if ((int)(pbVar3 + (iVar8 - (int)pbVar10)) < (int)uVar9) {
            ERR_put_error(0xd,0x72,0x9b,"asn1_lib.c",0x93);
            uVar13 = uVar13 | 0x80;
          }
          c->p = pbVar10;
          c->inf = uVar13 | uVar12;
          if ((uVar13 & 0x80) == 0) {
            iVar8 = c->tag;
            bVar14 = iVar8 != 0x10;
            if (bVar14) {
              iVar8 = 0x3d;
            }
            if (bVar14) {
              c->error = iVar8;
              return 0;
            }
            puVar7 = c->max;
            pbVar3 = pbVar3 + (*length - (int)pbVar10);
            *length = (long)pbVar3;
            if (puVar7 != (uchar *)0x0) {
              bVar14 = (int)pbVar3 < 0;
              if (bVar14) {
                pbVar3 = (byte *)0x3e;
              }
              if (bVar14) {
                c->error = (int)pbVar3;
                return 0;
              }
            }
            if ((uVar13 | uVar12) == 0x21) {
              c->slen = (long)pbVar3;
            }
            c->eos = 0;
            return 1;
          }
          goto LAB_000bfa6a;
        }
      }
    }
  }
LAB_000bfa50:
  ERR_put_error(0xd,0x72,0x7b,"asn1_lib.c",0x9d);
  c->inf = 0x80;
LAB_000bfa6a:
  c->error = 0x3c;
  return 0;
}

