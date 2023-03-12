
int ASN1_get_object(uchar **pp,long *plength,int *ptag,int *pclass,long omax)

{
  byte bVar1;
  ushort uVar2;
  uint3 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  if (omax != 0) {
    pbVar9 = *pp;
    uVar5 = (uint)*pbVar9;
    uVar4 = uVar5 & 0x1f;
    iVar7 = omax + -1;
    if (uVar4 == 0x1f) {
      if (iVar7 != 0) {
        uVar4 = 0;
        pbVar8 = pbVar9;
        while( true ) {
          bVar1 = pbVar8[1];
          iVar7 = iVar7 + -1;
          if (-1 < (char)bVar1) break;
          uVar4 = bVar1 & 0x7f | uVar4 << 7;
          if ((iVar7 == 0) || (pbVar8 = pbVar8 + 1, 0xffffff < (int)uVar4)) goto LAB_0056ac34;
        }
        pbVar8 = pbVar8 + 2;
        if (iVar7 != 0) {
          uVar4 = uVar4 << 7 | (uint)bVar1;
          goto LAB_0056acc4;
        }
      }
    }
    else {
      pbVar8 = pbVar9 + 1;
      if (iVar7 != 0) {
LAB_0056acc4:
        *ptag = uVar4;
        *pclass = uVar5 & 0xc0;
        if (0 < iVar7) {
          bVar1 = *pbVar8;
          if (bVar1 == 0x80) {
            pbVar10 = pbVar8 + 1;
            uVar4 = 1;
            uVar6 = 0;
          }
          else {
            pbVar10 = pbVar8 + 1;
            uVar6 = bVar1 & 0x7f;
            if ((char)bVar1 < '\0') {
              if ((uVar6 < 5) && (iVar7 != 1)) {
                uVar4 = 0;
                if ((bVar1 & 0x7f) == 0) {
                  uVar6 = 0;
                  goto LAB_0056acfc;
                }
                pbVar10 = pbVar8 + 2;
                if (iVar7 != 2) {
                  uVar4 = (uint)pbVar8[1];
                  if (uVar6 != 1) {
                    pbVar10 = pbVar8 + 3;
                    uVar2 = CONCAT11(pbVar8[1],pbVar8[2]);
                    if (iVar7 == 3) goto LAB_0056ac34;
                    uVar4 = (uint)uVar2;
                    if (uVar6 != 2) {
                      pbVar10 = pbVar8 + 4;
                      uVar3 = CONCAT21(uVar2,pbVar8[3]);
                      if (iVar7 == 4) goto LAB_0056ac34;
                      uVar4 = (uint)uVar3;
                      if (uVar6 != 3) {
                        pbVar10 = pbVar8 + 5;
                        if ((iVar7 == 5) || (uVar4 = CONCAT31(uVar3,pbVar8[4]), uVar6 != 4))
                        goto LAB_0056ac34;
                      }
                    }
                  }
                  uVar6 = uVar4;
                  uVar4 = 0;
                  if (-1 < (int)uVar6) goto LAB_0056acfc;
                }
              }
              goto LAB_0056ac34;
            }
            uVar4 = 0;
          }
LAB_0056acfc:
          *plength = uVar6;
          if ((int)uVar6 <= omax - ((int)pbVar10 - (int)pbVar9)) {
            *pp = pbVar10;
            return uVar5 & 0x20 | uVar4;
          }
          (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x72,0x9b,"asn1_lib.c",0x8e);
          *pp = pbVar10;
          return uVar5 & 0x20 | 0x80 | uVar4;
        }
      }
    }
  }
LAB_0056ac34:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x72,0x7b,"asn1_lib.c",0x96);
  return 0x80;
}

