
int ASN1_get_object(uchar **pp,long *plength,int *ptag,int *pclass,long omax)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  byte bVar5;
  byte *pbVar6;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar7;
  
  if (omax != 0) {
    pbVar2 = *pp;
    bVar5 = *pbVar2;
    if ((bVar5 & 0x1f) == 0x1f) {
      iVar3 = omax + -1;
      if (iVar3 != 0) {
        uVar8 = 0;
        pbVar4 = pbVar2;
        while( true ) {
          bVar1 = pbVar4[1];
          if (-1 < (char)bVar1) break;
          uVar8 = uVar8 << 7 | bVar1 & 0x7f;
          iVar3 = iVar3 + -1;
          if ((0xffffff < (int)uVar8) || (pbVar4 = pbVar4 + 1, iVar3 == 0)) goto LAB_0815029b;
        }
        iVar3 = iVar3 + -1;
        if (iVar3 != 0) {
          pbVar4 = pbVar4 + 2;
          uVar8 = uVar8 << 7 | (uint)bVar1;
          goto LAB_08150316;
        }
      }
    }
    else {
      iVar3 = omax + -1;
      if (iVar3 != 0) {
        uVar8 = (uint)(bVar5 & 0x1f);
        pbVar4 = pbVar2 + 1;
LAB_08150316:
        *ptag = uVar8;
        *pclass = bVar5 & 0xc0;
        if (0 < iVar3) {
          bVar1 = *pbVar4;
          bVar5 = bVar5 & 0x20;
          if (bVar1 == 0x80) {
            pbVar10 = pbVar4 + 1;
            *plength = 0;
            if (bVar5 != 0) {
              uVar8 = 0;
              uVar9 = 1;
              goto LAB_08150367;
            }
          }
          else {
            pbVar10 = pbVar4 + 1;
            uVar9 = bVar1 & 0x7f;
            uVar8 = uVar9;
            if ((char)bVar1 < '\0') {
              if ((4 < uVar9) || (iVar3 <= (int)uVar9)) goto LAB_0815029b;
              if ((bVar1 & 0x7f) == 0) {
                uVar8 = 0;
                uVar9 = 0;
                *plength = 0;
                goto LAB_08150367;
              }
              uVar8 = 0;
              pbVar7 = pbVar10;
              do {
                pbVar6 = pbVar7 + 1;
                uVar8 = uVar8 << 8 | (uint)*pbVar7;
                pbVar7 = pbVar6;
              } while (pbVar6 != pbVar4 + uVar9 + 1);
              pbVar10 = pbVar10 + uVar9;
            }
            if (-1 < (int)uVar8) {
              uVar9 = 0;
              *plength = uVar8;
LAB_08150367:
              if (omax - ((int)pbVar10 - (int)pbVar2) < (int)uVar8) {
                ERR_put_error(0xd,0x72,0x9b,"asn1_lib.c",0x93);
                bVar5 = bVar5 | 0x80;
              }
              *pp = pbVar10;
              return bVar5 | uVar9;
            }
          }
        }
      }
    }
  }
LAB_0815029b:
  ERR_put_error(0xd,0x72,0x7b,"asn1_lib.c",0x9d);
  return 0x80;
}

