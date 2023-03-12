
void RC4(RC4_KEY *key,size_t len,uchar *indata,uchar *outdata)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  undefined uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  undefined uVar12;
  byte *pbVar13;
  uint uVar14;
  int iVar15;
  byte *pbVar16;
  int iVar17;
  byte *pbVar18;
  byte *pbVar19;
  byte *pbVar20;
  byte *pbVar21;
  byte *pbVar22;
  byte *pbVar23;
  byte *pbVar24;
  byte *pbVar25;
  
  uVar10 = (uint)*(byte *)&key->x;
  uVar6 = (uint)*(byte *)((int)&key->x + 1);
  if ((((uint)indata | (uint)outdata) & 3) == 0) {
    uVar8 = len & 0xfffffffc;
    uVar11 = uVar10;
    while (uVar8 != 0) {
      uVar10 = *(uint *)indata;
      pbVar25 = (byte *)((int)key->data + ((uVar11 + 1 & 0xff) - 6));
      pbVar24 = (byte *)((int)key->data + ((uVar11 + 2 & 0xff) - 6));
      bVar1 = *pbVar25;
      pbVar19 = (byte *)((int)key->data + ((uVar11 + 3 & 0xff) - 6));
      uVar6 = uVar6 + bVar1 & 0xff;
      pbVar9 = (byte *)((int)key->data + (uVar6 - 6));
      uVar11 = uVar11 + 4 & 0xff;
      pbVar13 = (byte *)((int)key->data + (uVar11 - 6));
      bVar2 = *pbVar9;
      len = len - 4;
      *pbVar9 = bVar1;
      *pbVar25 = bVar2;
      indata = (uchar *)((int)indata + 4);
      bVar3 = *pbVar24;
      bVar1 = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6));
      uVar6 = uVar6 + bVar3 & 0xff;
      pbVar9 = (byte *)((int)key->data + (uVar6 - 6));
      bVar2 = *pbVar9;
      *pbVar9 = bVar3;
      *pbVar24 = bVar2;
      bVar4 = *pbVar19;
      bVar2 = *(byte *)((int)key->data + (((uint)bVar3 + (uint)bVar2 & 0xff) - 6));
      uVar6 = uVar6 + bVar4 & 0xff;
      pbVar9 = (byte *)((int)key->data + (uVar6 - 6));
      bVar3 = *pbVar9;
      *pbVar9 = bVar4;
      *pbVar19 = bVar3;
      bVar5 = *pbVar13;
      bVar3 = *(byte *)((int)key->data + (((uint)bVar4 + (uint)bVar3 & 0xff) - 6));
      uVar6 = uVar6 + bVar5 & 0xff;
      pbVar9 = (byte *)((int)key->data + (uVar6 - 6));
      bVar4 = *pbVar9;
      *pbVar9 = bVar5;
      *pbVar13 = bVar4;
      *(uint *)outdata =
           ((uint)*(byte *)((int)key->data + (((uint)bVar5 + (uint)bVar4 & 0xff) - 6)) |
           (uint)bVar3 << 8 | (uint)bVar2 << 0x10 | (uint)bVar1 << 0x18) ^ uVar10;
      outdata = (uchar *)((int)outdata + 4);
      uVar8 = len & 0xfffffffc;
    }
    if (len != 0) {
      uVar10 = *(uint *)indata;
      uVar8 = *(uint *)outdata;
      if (len == 2) {
        iVar17 = 0x10;
        uVar14 = 0;
        iVar15 = 0x18;
LAB_004e4c1c:
        uVar11 = uVar11 + 1 & 0xff;
        pbVar9 = (byte *)((int)key->data + (uVar11 - 6));
        bVar1 = *pbVar9;
        uVar6 = uVar6 + bVar1 & 0xff;
        pbVar13 = (byte *)((int)key->data + (uVar6 - 6));
        bVar2 = *pbVar13;
        *pbVar13 = bVar1;
        *pbVar9 = bVar2;
        uVar14 = (uint)*(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) <<
                 iVar15 | uVar14;
      }
      else {
        uVar14 = 0;
        if (len == 3) {
          iVar17 = 8;
          uVar11 = uVar11 + 1 & 0xff;
          pbVar9 = (byte *)((int)key->data + (uVar11 - 6));
          iVar15 = 0x10;
          bVar1 = *pbVar9;
          uVar6 = bVar1 + uVar6 & 0xff;
          pbVar13 = (byte *)((int)key->data + (uVar6 - 6));
          bVar2 = *pbVar13;
          *pbVar13 = bVar1;
          *pbVar9 = bVar2;
          uVar14 = (uint)*(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) <<
                   0x18;
          goto LAB_004e4c1c;
        }
        iVar17 = 0x18;
      }
      uVar11 = uVar11 + 1 & 0xff;
      pbVar9 = (byte *)((int)key->data + (uVar11 - 6));
      bVar1 = *pbVar9;
      uVar6 = uVar6 + bVar1 & 0xff;
      pbVar13 = (byte *)((int)key->data + (uVar6 - 6));
      bVar2 = *pbVar13;
      *pbVar13 = bVar1;
      *pbVar9 = bVar2;
      *(uint *)outdata =
           uVar8 ^ (((uint)*(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) <<
                     iVar17 | uVar14) ^ uVar10 ^ uVar8) & -1 << ((4 - len) * 8 & 0x1f);
    }
  }
  else {
    if (len >> 3 != 0) {
      pbVar19 = indata + (len & 0xfffffff8);
      uVar8 = uVar10;
      pbVar9 = indata;
      pbVar13 = outdata;
      do {
        pbVar24 = (byte *)((int)key->data + ((uVar8 + 1 & 0xff) - 6));
        pbVar22 = (byte *)((int)key->data + ((uVar8 + 2 & 0xff) - 6));
        bVar1 = *pbVar24;
        indata = pbVar9 + 8;
        uVar6 = uVar6 + bVar1 & 0xff;
        pbVar25 = (byte *)((int)key->data + (uVar6 - 6));
        pbVar21 = (byte *)((int)key->data + ((uVar8 + 3 & 0xff) - 6));
        bVar2 = *pbVar25;
        pbVar18 = (byte *)((int)key->data + ((uVar8 + 4 & 0xff) - 6));
        *pbVar24 = bVar2;
        *pbVar25 = bVar1;
        pbVar16 = (byte *)((int)key->data + ((uVar8 + 5 & 0xff) - 6));
        pbVar25 = (byte *)((int)key->data + ((uVar8 + 6 & 0xff) - 6));
        *pbVar13 = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^ *pbVar9;
        pbVar24 = (byte *)((int)key->data + ((uVar8 + 7 & 0xff) - 6));
        bVar1 = *pbVar22;
        uVar8 = uVar8 + 8 & 0xff;
        pbVar20 = (byte *)((int)key->data + (uVar8 - 6));
        uVar6 = uVar6 + bVar1 & 0xff;
        pbVar23 = (byte *)((int)key->data + (uVar6 - 6));
        bVar2 = *pbVar23;
        *pbVar22 = bVar2;
        *pbVar23 = bVar1;
        pbVar13[1] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar9[1];
        bVar1 = *pbVar21;
        uVar6 = uVar6 + bVar1 & 0xff;
        pbVar22 = (byte *)((int)key->data + (uVar6 - 6));
        bVar2 = *pbVar22;
        *pbVar21 = bVar2;
        *pbVar22 = bVar1;
        pbVar13[2] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar9[2];
        bVar1 = *pbVar18;
        uVar6 = uVar6 + bVar1 & 0xff;
        pbVar21 = (byte *)((int)key->data + (uVar6 - 6));
        bVar2 = *pbVar21;
        *pbVar18 = bVar2;
        *pbVar21 = bVar1;
        pbVar13[3] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar9[3];
        bVar1 = *pbVar16;
        uVar6 = uVar6 + bVar1 & 0xff;
        pbVar18 = (byte *)((int)key->data + (uVar6 - 6));
        bVar2 = *pbVar18;
        *pbVar16 = bVar2;
        *pbVar18 = bVar1;
        pbVar13[4] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar9[4];
        bVar1 = *pbVar25;
        uVar6 = uVar6 + bVar1 & 0xff;
        pbVar16 = (byte *)((int)key->data + (uVar6 - 6));
        bVar2 = *pbVar16;
        *pbVar25 = bVar2;
        *pbVar16 = bVar1;
        pbVar13[5] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar9[5];
        bVar1 = *pbVar24;
        uVar6 = uVar6 + bVar1 & 0xff;
        pbVar25 = (byte *)((int)key->data + (uVar6 - 6));
        bVar2 = *pbVar25;
        *pbVar24 = bVar2;
        *pbVar25 = bVar1;
        pbVar13[6] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar9[6];
        bVar1 = *pbVar20;
        uVar6 = uVar6 + bVar1 & 0xff;
        pbVar24 = (byte *)((int)key->data + (uVar6 - 6));
        bVar2 = *pbVar24;
        *pbVar20 = bVar2;
        *pbVar24 = bVar1;
        pbVar13[7] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar9[7];
        pbVar9 = indata;
        pbVar13 = pbVar13 + 8;
      } while (indata != pbVar19);
      outdata = outdata + (len & 0xfffffff8);
      uVar10 = (len & 0xfffffff8) + uVar10 & 0xff;
    }
    uVar7 = (undefined)uVar6;
    uVar12 = (undefined)uVar10;
    uVar8 = len & 7;
    if (uVar8 == 0) goto LAB_004e4cb4;
    uVar11 = uVar10 + 1 & 0xff;
    pbVar13 = (byte *)((int)key->data + (uVar11 - 6));
    bVar1 = *pbVar13;
    uVar6 = uVar6 + bVar1 & 0xff;
    pbVar9 = (byte *)((int)key->data + (uVar6 - 6));
    bVar2 = *pbVar9;
    *pbVar13 = bVar2;
    *pbVar9 = bVar1;
    *outdata = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^ *indata;
    if (uVar8 != 1) {
      uVar11 = uVar10 + 2 & 0xff;
      pbVar13 = (byte *)((int)key->data + (uVar11 - 6));
      bVar1 = *pbVar13;
      uVar6 = uVar6 + bVar1 & 0xff;
      pbVar9 = (byte *)((int)key->data + (uVar6 - 6));
      bVar2 = *pbVar9;
      *pbVar13 = bVar2;
      *pbVar9 = bVar1;
      outdata[1] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^ indata[1];
      if (uVar8 != 2) {
        uVar11 = uVar10 + 3 & 0xff;
        pbVar13 = (byte *)((int)key->data + (uVar11 - 6));
        bVar1 = *pbVar13;
        uVar6 = uVar6 + bVar1 & 0xff;
        pbVar9 = (byte *)((int)key->data + (uVar6 - 6));
        bVar2 = *pbVar9;
        *pbVar13 = bVar2;
        *pbVar9 = bVar1;
        outdata[2] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     indata[2];
        if (uVar8 != 3) {
          uVar11 = uVar10 + 4 & 0xff;
          pbVar13 = (byte *)((int)key->data + (uVar11 - 6));
          bVar1 = *pbVar13;
          uVar6 = uVar6 + bVar1 & 0xff;
          pbVar9 = (byte *)((int)key->data + (uVar6 - 6));
          bVar2 = *pbVar9;
          *pbVar13 = bVar2;
          *pbVar9 = bVar1;
          outdata[3] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                       indata[3];
          if (uVar8 != 4) {
            uVar11 = uVar10 + 5 & 0xff;
            pbVar13 = (byte *)((int)key->data + (uVar11 - 6));
            bVar1 = *pbVar13;
            uVar6 = uVar6 + bVar1 & 0xff;
            pbVar9 = (byte *)((int)key->data + (uVar6 - 6));
            bVar2 = *pbVar9;
            *pbVar13 = bVar2;
            *pbVar9 = bVar1;
            outdata[4] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                         indata[4];
            if (uVar8 != 5) {
              uVar11 = uVar10 + 6 & 0xff;
              pbVar13 = (byte *)((int)key->data + (uVar11 - 6));
              bVar1 = *pbVar13;
              uVar6 = uVar6 + bVar1 & 0xff;
              pbVar9 = (byte *)((int)key->data + (uVar6 - 6));
              bVar2 = *pbVar9;
              *pbVar13 = bVar2;
              *pbVar9 = bVar1;
              outdata[5] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                           indata[5];
              if (uVar8 != 6) {
                uVar10 = uVar10 + 7 & 0xff;
                pbVar13 = (byte *)((int)key->data + (uVar10 - 6));
                bVar1 = *pbVar13;
                uVar6 = uVar6 + bVar1 & 0xff;
                pbVar9 = (byte *)((int)key->data + (uVar6 - 6));
                bVar2 = *pbVar9;
                *pbVar13 = bVar2;
                *pbVar9 = bVar1;
                outdata[6] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                             indata[6];
                *(char *)&key->x = (char)uVar10;
                *(char *)((int)&key->x + 1) = (char)uVar6;
                return;
              }
            }
          }
        }
      }
    }
  }
  uVar7 = (undefined)uVar6;
  uVar12 = (undefined)uVar11;
LAB_004e4cb4:
  *(undefined *)&key->x = uVar12;
  *(undefined *)((int)&key->x + 1) = uVar7;
  return;
}

