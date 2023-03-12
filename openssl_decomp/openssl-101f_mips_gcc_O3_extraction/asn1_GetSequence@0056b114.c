
int asn1_GetSequence(ASN1_const_CTX *c,long *length)

{
  byte bVar1;
  ushort uVar2;
  uint3 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uchar *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  uint uVar12;
  
  iVar5 = *length;
  if (iVar5 != 0) {
    pbVar10 = c->p;
    uVar6 = (uint)*pbVar10;
    uVar4 = uVar6 & 0x1f;
    iVar7 = iVar5 + -1;
    if (uVar4 == 0x1f) {
      if (iVar7 != 0) {
        uVar4 = 0;
        pbVar9 = pbVar10;
        while( true ) {
          bVar1 = pbVar9[1];
          iVar7 = iVar7 + -1;
          if (-1 < (char)bVar1) break;
          uVar4 = bVar1 & 0x7f | uVar4 << 7;
          if ((iVar7 == 0) || (pbVar9 = pbVar9 + 1, 0xffffff < (int)uVar4)) goto LAB_0056b174;
        }
        pbVar9 = pbVar9 + 2;
        if (iVar7 != 0) {
          uVar4 = uVar4 << 7 | (uint)bVar1;
          goto LAB_0056b21c;
        }
      }
    }
    else {
      pbVar9 = pbVar10 + 1;
      if (iVar7 != 0) {
LAB_0056b21c:
        c->tag = uVar4;
        c->xclass = uVar6 & 0xc0;
        if (0 < iVar7) {
          bVar1 = *pbVar9;
          if (bVar1 == 0x80) {
            pbVar11 = pbVar9 + 1;
            uVar12 = 1;
            uVar4 = 0;
          }
          else {
            pbVar11 = pbVar9 + 1;
            uVar4 = bVar1 & 0x7f;
            if ((char)bVar1 < '\0') {
              if ((uVar4 < 5) && (iVar7 != 1)) {
                if ((bVar1 & 0x7f) == 0) {
                  uVar12 = 0;
                  uVar4 = 0;
                  goto LAB_0056b250;
                }
                pbVar11 = pbVar9 + 2;
                if (iVar7 != 2) {
                  uVar12 = (uint)pbVar9[1];
                  if (uVar4 != 1) {
                    pbVar11 = pbVar9 + 3;
                    uVar2 = CONCAT11(pbVar9[1],pbVar9[2]);
                    if (iVar7 == 3) goto LAB_0056b174;
                    uVar12 = (uint)uVar2;
                    if (uVar4 != 2) {
                      pbVar11 = pbVar9 + 4;
                      uVar3 = CONCAT21(uVar2,pbVar9[3]);
                      if (iVar7 == 4) goto LAB_0056b174;
                      uVar12 = (uint)uVar3;
                      if (uVar4 != 3) {
                        pbVar11 = pbVar9 + 5;
                        if ((iVar7 == 5) || (uVar12 = CONCAT31(uVar3,pbVar9[4]), uVar4 != 4))
                        goto LAB_0056b174;
                      }
                    }
                  }
                  uVar4 = uVar12;
                  uVar12 = 0;
                  if (-1 < (int)uVar4) goto LAB_0056b250;
                }
              }
              goto LAB_0056b174;
            }
            uVar12 = 0;
          }
LAB_0056b250:
          c->slen = uVar4;
          uVar6 = uVar6 & 0x20;
          if (iVar5 - ((int)pbVar11 - (int)pbVar10) < (int)uVar4) {
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x72,0x9b,"asn1_lib.c",0x8e);
            uVar6 = uVar6 | 0x80;
          }
          c->p = pbVar11;
          c->inf = uVar6 | uVar12;
          if ((uVar6 & 0x80) == 0) {
            if (c->tag != 0x10) {
              c->error = 0x3d;
              return uVar6 & 0x80;
            }
            puVar8 = c->max;
            iVar5 = *length - ((int)pbVar11 - (int)pbVar10);
            *length = iVar5;
            if ((puVar8 != (uchar *)0x0) && (iVar5 < 0)) {
              c->error = 0x3e;
              return 0;
            }
            if ((uVar6 | uVar12) == 0x21) {
              puVar8 = *c->pp;
              c->eos = 0;
              c->slen = (long)(puVar8 + (iVar5 - (int)pbVar11));
            }
            else {
              c->eos = 0;
            }
            return 1;
          }
          goto LAB_0056b19c;
        }
      }
    }
  }
LAB_0056b174:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x72,0x7b,"asn1_lib.c",0x96);
  c->inf = 0x80;
LAB_0056b19c:
  c->error = 0x3c;
  return 0;
}

