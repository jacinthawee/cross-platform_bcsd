
int asn1_GetSequence(ASN1_const_CTX *c,long *length)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint3 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uchar *puVar9;
  byte *pbVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  
  iVar8 = *length;
  if (iVar8 != 0) {
    pbVar12 = c->p;
    bVar1 = *pbVar12;
    uVar11 = (uint)bVar1;
    uVar5 = uVar11 & 0x1f;
    iVar6 = iVar8 + -1;
    if (uVar5 == 0x1f) {
      if (iVar6 != 0) {
        uVar5 = 0;
        pbVar10 = pbVar12;
        while( true ) {
          bVar2 = pbVar10[1];
          iVar6 = iVar6 + -1;
          if (-1 < (char)bVar2) break;
          uVar5 = bVar2 & 0x7f | uVar5 << 7;
          if ((iVar6 == 0) || (pbVar10 = pbVar10 + 1, 0xffffff < (int)uVar5)) goto LAB_005677f8;
        }
        pbVar10 = pbVar10 + 2;
        if (iVar6 != 0) {
          uVar5 = uVar5 << 7 | (uint)bVar2;
          goto LAB_005678a0;
        }
      }
    }
    else {
      pbVar10 = pbVar12 + 1;
      if (iVar6 != 0) {
LAB_005678a0:
        c->tag = uVar5;
        c->xclass = uVar11 & 0xc0;
        if (0 < iVar6) {
          bVar2 = *pbVar10;
          uVar11 = uVar11 & 0x20;
          if (bVar2 == 0x80) {
            c->slen = 0;
            if ((bVar1 & 0x20) == 0) goto LAB_005677f8;
            pbVar13 = pbVar10 + 1;
            uVar5 = 0;
            uVar7 = 1;
          }
          else {
            pbVar13 = pbVar10 + 1;
            uVar5 = bVar2 & 0x7f;
            if ((char)bVar2 < '\0') {
              if ((uVar5 < 5) && ((int)uVar5 < iVar6)) {
                if ((bVar2 & 0x7f) == 0) {
                  uVar5 = 0;
                  c->slen = 0;
                  uVar7 = 0;
                  goto LAB_005678e0;
                }
                uVar7 = (uint)pbVar10[1];
                if (uVar5 != 1) {
                  uVar3 = CONCAT11(pbVar10[1],pbVar10[2]);
                  uVar7 = (uint)uVar3;
                  if (uVar5 != 2) {
                    uVar4 = CONCAT21(uVar3,pbVar10[3]);
                    uVar7 = (uint)uVar4;
                    if (uVar5 != 3) {
                      uVar7 = CONCAT31(uVar4,pbVar10[4]);
                    }
                  }
                }
                pbVar13 = pbVar13 + uVar5;
                uVar5 = uVar7;
                if (-1 < (int)uVar7) goto LAB_005678dc;
              }
              goto LAB_005677f8;
            }
LAB_005678dc:
            uVar7 = 0;
            c->slen = uVar5;
          }
LAB_005678e0:
          if (iVar8 - ((int)pbVar13 - (int)pbVar12) < (int)uVar5) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x72,0x9b,"asn1_lib.c",0x93);
            uVar11 = uVar11 | 0x80;
          }
          c->p = pbVar13;
          c->inf = uVar11 | uVar7;
          if ((uVar11 & 0x80) == 0) {
            if (c->tag != 0x10) {
              c->error = 0x3d;
              return uVar11 & 0x80;
            }
            puVar9 = c->max;
            iVar8 = *length - ((int)pbVar13 - (int)pbVar12);
            *length = iVar8;
            if ((puVar9 != (uchar *)0x0) && (iVar8 < 0)) {
              c->error = 0x3e;
              return 0;
            }
            if ((uVar11 | uVar7) == 0x21) {
              c->slen = iVar8;
              c->eos = 0;
            }
            else {
              c->eos = 0;
            }
            return 1;
          }
          goto LAB_00567820;
        }
      }
    }
  }
LAB_005677f8:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x72,0x7b,"asn1_lib.c",0x9d);
  c->inf = 0x80;
LAB_00567820:
  c->error = 0x3c;
  return 0;
}

