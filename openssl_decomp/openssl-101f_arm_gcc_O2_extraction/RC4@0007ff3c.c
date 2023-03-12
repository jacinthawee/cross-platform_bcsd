
void RC4(RC4_KEY *key,size_t len,uchar *indata,uchar *outdata)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined uVar4;
  undefined uVar5;
  undefined uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  
  uVar7 = (uint)*(byte *)&key->x;
  uVar11 = (uint)*(byte *)((int)&key->x + 1);
  if ((((uint)indata | (uint)outdata) & 3) != 0) {
    uVar12 = len >> 3;
    uVar8 = uVar7;
    pbVar9 = indata;
    pbVar10 = outdata;
    if (uVar12 != 0) {
      do {
        uVar12 = uVar12 - 1;
        uVar15 = uVar8 + 1 & 0xff;
        uVar17 = uVar8 + 2 & 0xff;
        uVar13 = uVar8 + 3 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar15 - 6));
        uVar11 = uVar11 + bVar2 & 0xff;
        bVar1 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar15 - 6)) = bVar1;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar2;
        uVar15 = uVar8 + 4 & 0xff;
        *pbVar10 = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^ *pbVar9;
        bVar1 = *(byte *)((int)key->data + (uVar17 - 6));
        uVar11 = uVar11 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar17 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
        uVar17 = uVar8 + 5 & 0xff;
        pbVar10[1] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar9[1];
        bVar1 = *(byte *)((int)key->data + (uVar13 - 6));
        uVar11 = uVar11 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar13 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
        uVar13 = uVar8 + 6 & 0xff;
        pbVar10[2] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar9[2];
        bVar1 = *(byte *)((int)key->data + (uVar15 - 6));
        uVar11 = uVar11 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar15 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
        uVar15 = uVar8 + 7 & 0xff;
        pbVar10[3] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar9[3];
        bVar1 = *(byte *)((int)key->data + (uVar17 - 6));
        uVar8 = uVar8 + 8 & 0xff;
        uVar11 = uVar11 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar17 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
        pbVar10[4] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     pbVar9[4];
        bVar2 = *(byte *)((int)key->data + (uVar13 - 6));
        uVar11 = uVar11 + bVar2 & 0xff;
        bVar1 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar13 - 6)) = bVar1;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar2;
        pbVar10[5] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar9[5];
        bVar2 = *(byte *)((int)key->data + (uVar15 - 6));
        uVar11 = uVar11 + bVar2 & 0xff;
        bVar1 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar15 - 6)) = bVar1;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar2;
        pbVar10[6] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar9[6];
        bVar2 = *(byte *)((int)key->data + (uVar8 - 6));
        uVar11 = uVar11 + bVar2 & 0xff;
        bVar1 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar8 - 6)) = bVar1;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar2;
        pbVar10[7] = *(byte *)((int)key->data + (((uint)bVar2 + (uint)bVar1 & 0xff) - 6)) ^
                     pbVar9[7];
        pbVar9 = pbVar9 + 8;
        pbVar10 = pbVar10 + 8;
      } while (uVar12 != 0);
      uVar7 = uVar7 + (len & 0xfffffff8) & 0xff;
      outdata = outdata + (len & 0xfffffff8);
      indata = indata + (len & 0xfffffff8);
    }
    uVar12 = len & 7;
    uVar8 = uVar7;
    if (uVar12 != 0) {
      uVar8 = uVar7 + 1 & 0xff;
      bVar1 = *(byte *)((int)key->data + (uVar8 - 6));
      uVar11 = uVar11 + bVar1 & 0xff;
      bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
      *(byte *)((int)key->data + (uVar8 - 6)) = bVar2;
      *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
      *outdata = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^ *indata;
      if (uVar12 != 1) {
        uVar8 = uVar7 + 2 & 0xff;
        bVar1 = *(byte *)((int)key->data + (uVar8 - 6));
        uVar11 = uVar11 + bVar1 & 0xff;
        bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
        *(byte *)((int)key->data + (uVar8 - 6)) = bVar2;
        *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
        outdata[1] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                     indata[1];
        if (uVar12 != 2) {
          uVar8 = uVar7 + 3 & 0xff;
          bVar1 = *(byte *)((int)key->data + (uVar8 - 6));
          uVar11 = uVar11 + bVar1 & 0xff;
          bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
          *(byte *)((int)key->data + (uVar8 - 6)) = bVar2;
          *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
          outdata[2] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                       indata[2];
          if (uVar12 != 3) {
            uVar8 = uVar7 + 4 & 0xff;
            bVar1 = *(byte *)((int)key->data + (uVar8 - 6));
            uVar11 = uVar11 + bVar1 & 0xff;
            bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
            *(byte *)((int)key->data + (uVar8 - 6)) = bVar2;
            *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
            outdata[3] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                         indata[3];
            if (uVar12 != 4) {
              uVar8 = uVar7 + 5 & 0xff;
              bVar1 = *(byte *)((int)key->data + (uVar8 - 6));
              uVar11 = uVar11 + bVar1 & 0xff;
              bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
              *(byte *)((int)key->data + (uVar8 - 6)) = bVar2;
              *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
              outdata[4] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                           indata[4];
              if (uVar12 != 5) {
                uVar8 = uVar7 + 6 & 0xff;
                bVar1 = *(byte *)((int)key->data + (uVar8 - 6));
                uVar11 = uVar11 + bVar1 & 0xff;
                bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
                *(byte *)((int)key->data + (uVar8 - 6)) = bVar2;
                *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
                outdata[5] = *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) ^
                             indata[5];
                if (uVar12 != 6) {
                  uVar7 = uVar7 + 7 & 0xff;
                  bVar1 = *(byte *)((int)key->data + (uVar7 - 6));
                  uVar11 = uVar11 + bVar1 & 0xff;
                  bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
                  *(byte *)((int)key->data + (uVar7 - 6)) = bVar2;
                  *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
                  outdata[6] = indata[6] ^
                               *(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6));
                  *(char *)&key->x = (char)uVar7;
                  *(char *)((int)&key->x + 1) = (char)uVar11;
                  return;
                }
              }
            }
          }
        }
      }
    }
    goto LAB_000800b6;
  }
  uVar8 = len & 0xfffffffc;
  while (uVar8 != 0) {
    uVar8 = *(uint *)indata;
    uVar13 = uVar7 + 1 & 0xff;
    uVar12 = uVar7 + 2 & 0xff;
    uVar15 = uVar7 + 3 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar13 - 6));
    len = len - 4;
    uVar7 = uVar7 + 4 & 0xff;
    uVar11 = uVar11 + bVar1 & 0xff;
    bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
    *(byte *)((int)key->data + (uVar13 - 6)) = bVar2;
    bVar3 = *(byte *)((int)key->data + (uVar12 - 6));
    uVar4 = *(undefined *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6));
    uVar11 = uVar11 + bVar3 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar3;
    *(byte *)((int)key->data + (uVar12 - 6)) = bVar1;
    bVar2 = *(byte *)((int)key->data + (uVar15 - 6));
    uVar5 = *(undefined *)((int)key->data + (((uint)bVar3 + (uint)bVar1 & 0xff) - 6));
    uVar11 = uVar11 + bVar2 & 0xff;
    bVar3 = *(byte *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar2;
    *(byte *)((int)key->data + (uVar15 - 6)) = bVar3;
    bVar1 = *(byte *)((int)key->data + (uVar7 - 6));
    uVar6 = *(undefined *)((int)key->data + (((uint)bVar2 + (uint)bVar3 & 0xff) - 6));
    uVar11 = uVar11 + bVar1 & 0xff;
    bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
    *(byte *)((int)key->data + (uVar7 - 6)) = bVar2;
    *(uint *)outdata =
         CONCAT13(*(undefined *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)),
                  CONCAT12(uVar6,CONCAT11(uVar5,uVar4))) ^ uVar8;
    indata = (uchar *)((int)indata + 4);
    outdata = (uchar *)((int)outdata + 4);
    uVar8 = len & 0xfffffffc;
  }
  uVar8 = uVar7;
  if (len == 0) goto LAB_000800b6;
  uVar13 = *(uint *)indata;
  uVar15 = *(uint *)outdata;
  uVar12 = 0xffffffff >> ((4 - len) * 8 & 0xff);
  if (len == 2) {
    iVar14 = 0;
    uVar16 = 0;
    uVar17 = 8;
LAB_0008006a:
    uVar7 = uVar7 + 1 & 0xff;
    bVar1 = *(byte *)((int)key->data + (uVar7 - 6));
    uVar11 = uVar11 + bVar1 & 0xff;
    bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
    *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
    *(byte *)((int)key->data + (uVar7 - 6)) = bVar2;
    uVar16 = (uint)*(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)) << iVar14 |
             uVar16;
  }
  else {
    if (len == 3) {
      uVar17 = 0x10;
      iVar14 = 8;
      uVar7 = uVar7 + 1 & 0xff;
      bVar1 = *(byte *)((int)key->data + (uVar7 - 6));
      uVar11 = uVar11 + bVar1 & 0xff;
      bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
      *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
      *(byte *)((int)key->data + (uVar7 - 6)) = bVar2;
      uVar16 = (uint)*(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6));
      goto LAB_0008006a;
    }
    uVar16 = 0;
    uVar17 = uVar16;
  }
  uVar8 = uVar7 + 1 & 0xff;
  bVar1 = *(byte *)((int)key->data + (uVar8 - 6));
  uVar11 = uVar11 + bVar1 & 0xff;
  bVar2 = *(byte *)((int)key->data + (uVar11 - 6));
  *(byte *)((int)key->data + (uVar11 - 6)) = bVar1;
  *(byte *)((int)key->data + (uVar8 - 6)) = bVar2;
  *(uint *)outdata =
       uVar12 & (uVar13 ^ ((uint)*(byte *)((int)key->data + (((uint)bVar1 + (uint)bVar2 & 0xff) - 6)
                                          ) << uVar17 | uVar16)) | uVar15 & ~uVar12;
LAB_000800b6:
  *(char *)&key->x = (char)uVar8;
  *(char *)((int)&key->x + 1) = (char)uVar11;
  return;
}

