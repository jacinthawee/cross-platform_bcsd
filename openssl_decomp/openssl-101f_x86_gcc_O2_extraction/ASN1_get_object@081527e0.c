
int ASN1_get_object(uchar **pp,long *plength,int *ptag,int *pclass,long omax)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  ushort uVar4;
  uint3 uVar5;
  int iVar6;
  byte *pbVar7;
  byte bVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  uint local_24;
  
  if (omax != 0) {
    pbVar3 = *pp;
    bVar1 = *pbVar3;
    if ((bVar1 & 0x1f) == 0x1f) {
      iVar6 = omax + -1;
      if (iVar6 != 0) {
        uVar11 = 0;
        pbVar7 = pbVar3;
        while( true ) {
          bVar2 = pbVar7[1];
          if (-1 < (char)bVar2) break;
          uVar11 = uVar11 << 7 | bVar2 & 0x7f;
          iVar6 = iVar6 + -1;
          if ((0xffffff < (int)uVar11) || (pbVar7 = pbVar7 + 1, iVar6 == 0)) goto LAB_0815280b;
        }
        iVar6 = iVar6 + -1;
        if (iVar6 != 0) {
          pbVar7 = pbVar7 + 2;
          uVar11 = uVar11 << 7 | (uint)bVar2;
          goto LAB_08152886;
        }
      }
    }
    else {
      iVar6 = omax + -1;
      if (iVar6 != 0) {
        uVar11 = (uint)(bVar1 & 0x1f);
        pbVar7 = pbVar3 + 1;
LAB_08152886:
        *ptag = uVar11;
        *pclass = bVar1 & 0xc0;
        if (0 < iVar6) {
          bVar2 = *pbVar7;
          if (bVar2 == 0x80) {
            pbVar10 = pbVar7 + 1;
            uVar11 = 1;
            local_24 = 0;
          }
          else {
            pbVar10 = pbVar7 + 1;
            bVar8 = bVar2 & 0x7f;
            uVar11 = (uint)bVar8;
            local_24 = uVar11;
            if ((char)bVar2 < '\0') {
              if ((4 < bVar8) || (iVar6 == 1)) goto LAB_0815280b;
              if (bVar8 == 0) {
                uVar11 = 0;
                local_24 = 0;
                goto LAB_081528d8;
              }
              pbVar10 = pbVar7 + 2;
              local_24 = (uint)pbVar7[1];
              if (iVar6 == 2) goto LAB_0815280b;
              if (uVar11 != 1) {
                pbVar10 = pbVar7 + 3;
                uVar4 = CONCAT11(pbVar7[1],pbVar7[2]);
                local_24 = (uint)uVar4;
                if (iVar6 == 3) goto LAB_0815280b;
                if (uVar11 != 2) {
                  pbVar10 = pbVar7 + 4;
                  uVar5 = CONCAT21(uVar4,pbVar7[3]);
                  local_24 = (uint)uVar5;
                  if (iVar6 == 4) goto LAB_0815280b;
                  if (uVar11 != 3) {
                    pbVar10 = pbVar7 + 5;
                    local_24 = CONCAT31(uVar5,pbVar7[4]);
                    if ((iVar6 == 5) || (uVar11 != 4)) goto LAB_0815280b;
                  }
                }
              }
            }
            uVar11 = 0;
            if ((int)local_24 < 0) goto LAB_0815280b;
          }
LAB_081528d8:
          uVar9 = bVar1 & 0x20;
          *plength = local_24;
          if (omax - ((int)pbVar10 - (int)pbVar3) < (int)local_24) {
            ERR_put_error(0xd,0x72,0x9b,"asn1_lib.c",0x8e);
            uVar9 = uVar9 | 0x80;
          }
          *pp = pbVar10;
          return uVar9 | uVar11;
        }
      }
    }
  }
LAB_0815280b:
  ERR_put_error(0xd,0x72,0x7b,"asn1_lib.c",0x96);
  return 0x80;
}

