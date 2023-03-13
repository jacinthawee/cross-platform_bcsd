
int ASN1_get_object(uchar **pp,long *plength,int *ptag,int *pclass,long omax)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint3 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  
  if (omax != 0) {
    pbVar10 = *pp;
    bVar1 = *pbVar10;
    uVar8 = (uint)bVar1;
    uVar5 = uVar8 & 0x1f;
    iVar6 = omax + -1;
    if (uVar5 == 0x1f) {
      if (iVar6 != 0) {
        uVar5 = 0;
        pbVar9 = pbVar10;
        while( true ) {
          bVar2 = pbVar9[1];
          iVar6 = iVar6 + -1;
          if (-1 < (char)bVar2) break;
          uVar5 = bVar2 & 0x7f | uVar5 << 7;
          if ((iVar6 == 0) || (pbVar9 = pbVar9 + 1, 0xffffff < (int)uVar5)) goto LAB_005672c4;
        }
        pbVar9 = pbVar9 + 2;
        if (iVar6 != 0) {
          uVar5 = uVar5 << 7 | (uint)bVar2;
          goto LAB_00567354;
        }
      }
    }
    else {
      pbVar9 = pbVar10 + 1;
      if (iVar6 != 0) {
LAB_00567354:
        *ptag = uVar5;
        *pclass = uVar8 & 0xc0;
        if (0 < iVar6) {
          bVar2 = *pbVar9;
          if (bVar2 == 0x80) {
            *plength = 0;
            if ((bVar1 & 0x20) == 0) goto LAB_005672c4;
            pbVar11 = pbVar9 + 1;
            uVar5 = 0;
            uVar7 = 1;
          }
          else {
            pbVar11 = pbVar9 + 1;
            uVar5 = bVar2 & 0x7f;
            if ((char)bVar2 < '\0') {
              if ((4 < uVar5) || (iVar6 <= (int)uVar5)) goto LAB_005672c4;
              if ((bVar2 & 0x7f) == 0) {
                uVar5 = 0;
                *plength = 0;
                uVar7 = 0;
                goto LAB_00567394;
              }
              uVar7 = (uint)pbVar9[1];
              if (uVar5 != 1) {
                uVar3 = CONCAT11(pbVar9[1],pbVar9[2]);
                uVar7 = (uint)uVar3;
                if (uVar5 != 2) {
                  uVar4 = CONCAT21(uVar3,pbVar9[3]);
                  uVar7 = (uint)uVar4;
                  if (uVar5 != 3) {
                    uVar7 = CONCAT31(uVar4,pbVar9[4]);
                  }
                }
              }
              pbVar11 = pbVar11 + uVar5;
              uVar5 = uVar7;
              if ((int)uVar7 < 0) goto LAB_005672c4;
            }
            uVar7 = 0;
            *plength = uVar5;
          }
LAB_00567394:
          if ((int)uVar5 <= omax - ((int)pbVar11 - (int)pbVar10)) {
            *pp = pbVar11;
            return uVar8 & 0x20 | uVar7;
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x72,0x9b,"asn1_lib.c",0x93);
          *pp = pbVar11;
          return uVar8 & 0x20 | 0x80 | uVar7;
        }
      }
    }
  }
LAB_005672c4:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x72,0x7b,"asn1_lib.c",0x9d);
  return 0x80;
}

