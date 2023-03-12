
int ASN1_get_object(uchar **pp,long *plength,int *ptag,int *pclass,long omax)

{
  byte bVar1;
  ushort uVar2;
  uint3 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  byte *unaff_r10;
  
  pbVar7 = *pp;
  if (omax != 0) {
    uVar10 = (uint)*pbVar7;
    uVar8 = uVar10 & 0x1f;
    if (uVar8 == 0x1f) {
      iVar4 = omax + -1;
      if (iVar4 != 0) {
        uVar8 = 0;
        pbVar9 = pbVar7 + 1;
        while( true ) {
          bVar1 = *pbVar9;
          if ((bVar1 & 0x80) == 0) break;
          iVar4 = iVar4 + -1;
          uVar8 = bVar1 & 0x7f | uVar8 << 7;
          if ((iVar4 == 0) || (pbVar9 = pbVar9 + 1, 0xffffff < (int)uVar8)) goto LAB_000c1d7e;
        }
        iVar4 = iVar4 + -1;
        if (iVar4 != 0) {
          unaff_r10 = pbVar9 + 1;
        }
        if (iVar4 != 0) {
          uVar8 = (uint)bVar1 | uVar8 << 7;
          goto LAB_000c1dd8;
        }
      }
    }
    else {
      iVar4 = omax + -1;
      if (iVar4 != 0) {
        unaff_r10 = pbVar7 + 1;
LAB_000c1dd8:
        *ptag = uVar8;
        *pclass = uVar10 & 0xc0;
        if (0 < iVar4) {
          uVar8 = (uint)*unaff_r10;
          if (uVar8 == 0x80) {
            pbVar9 = unaff_r10 + 1;
            uVar8 = 1;
            uVar5 = 0;
          }
          else {
            uVar6 = uVar8 & 0x7f;
            pbVar9 = unaff_r10 + 1;
            uVar5 = uVar6;
            if ((int)(uVar8 << 0x18) < 0) {
              if ((4 < uVar6) || (iVar4 == 1)) goto LAB_000c1d7e;
              if ((*unaff_r10 & 0x7f) != 0) {
                pbVar9 = unaff_r10 + 2;
                uVar5 = (uint)unaff_r10[1];
                if (iVar4 == 2) goto LAB_000c1d7e;
                if (uVar6 != 1) {
                  pbVar9 = unaff_r10 + 3;
                  uVar2 = CONCAT11(unaff_r10[1],unaff_r10[2]);
                  uVar5 = (uint)uVar2;
                  if (iVar4 == 3) goto LAB_000c1d7e;
                  if (uVar6 != 2) {
                    pbVar9 = unaff_r10 + 4;
                    uVar3 = CONCAT21(uVar2,unaff_r10[3]);
                    uVar5 = (uint)uVar3;
                    if (iVar4 == 4) goto LAB_000c1d7e;
                    if (uVar6 != 3) {
                      pbVar9 = unaff_r10 + 5;
                      uVar5 = CONCAT31(uVar3,unaff_r10[4]);
                      if (iVar4 == 5) goto LAB_000c1d7e;
                    }
                  }
                }
              }
            }
            if ((int)uVar5 < 0) goto LAB_000c1d7e;
            uVar8 = 0;
          }
          uVar10 = uVar10 & 0x20;
          *plength = uVar5;
          if ((int)(pbVar7 + (omax - (int)pbVar9)) < (int)uVar5) {
            ERR_put_error(0xd,0x72,0x9b,"asn1_lib.c",0x8e);
            uVar10 = uVar10 | 0x80;
          }
          *pp = pbVar9;
          return uVar10 | uVar8;
        }
      }
    }
  }
LAB_000c1d7e:
  ERR_put_error(0xd,0x72,0x7b,"asn1_lib.c",0x96);
  return 0x80;
}

