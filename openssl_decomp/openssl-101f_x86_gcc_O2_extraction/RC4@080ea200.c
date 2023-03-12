
void RC4(RC4_KEY *key,size_t len,uchar *indata,uchar *outdata)

{
  char cVar1;
  char cVar2;
  undefined uVar3;
  undefined uVar4;
  char cVar5;
  undefined uVar6;
  byte bVar7;
  uint uVar8;
  uchar *puVar9;
  uchar *puVar10;
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  uint uVar14;
  byte bVar15;
  byte local_25;
  byte *local_20;
  sbyte local_18;
  sbyte local_14;
  
  local_25 = *(byte *)&key->x;
  bVar15 = *(byte *)((int)&key->x + 1);
  if ((((uint)indata | (uint)outdata) & 3) != 0) {
    if (len >> 3 != 0) {
      puVar10 = indata + (len & 0xfffffff8);
      local_20 = outdata;
      bVar7 = local_25;
      do {
        pcVar12 = (char *)((int)key->data + ((byte)(bVar7 + 1) - 6));
        cVar1 = *pcVar12;
        pcVar13 = (char *)((int)key->data + ((byte)(bVar15 + cVar1) - 6));
        cVar2 = *pcVar13;
        *pcVar12 = cVar2;
        *pcVar13 = cVar1;
        pcVar12 = (char *)((int)key->data + ((byte)(bVar7 + 2) - 6));
        *local_20 = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ *indata;
        cVar2 = *pcVar12;
        bVar15 = bVar15 + cVar1 + cVar2;
        pcVar13 = (char *)((int)key->data + (bVar15 - 6));
        cVar1 = *pcVar13;
        *pcVar12 = cVar1;
        *pcVar13 = cVar2;
        pcVar12 = (char *)((int)key->data + ((byte)(bVar7 + 3) - 6));
        local_20[1] = *(byte *)((int)key->data + ((byte)(cVar2 + cVar1) - 6)) ^ indata[1];
        cVar1 = *pcVar12;
        bVar15 = bVar15 + cVar1;
        pcVar13 = (char *)((int)key->data + (bVar15 - 6));
        cVar2 = *pcVar13;
        *pcVar12 = cVar2;
        *pcVar13 = cVar1;
        pcVar12 = (char *)((int)key->data + ((byte)(bVar7 + 4) - 6));
        local_20[2] = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ indata[2];
        cVar1 = *pcVar12;
        bVar15 = bVar15 + cVar1;
        pcVar13 = (char *)((int)key->data + (bVar15 - 6));
        cVar2 = *pcVar13;
        *pcVar12 = cVar2;
        *pcVar13 = cVar1;
        pcVar12 = (char *)((int)key->data + ((byte)(bVar7 + 5) - 6));
        local_20[3] = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ indata[3];
        cVar1 = *pcVar12;
        bVar15 = bVar15 + cVar1;
        pcVar13 = (char *)((int)key->data + (bVar15 - 6));
        cVar2 = *pcVar13;
        *pcVar12 = cVar2;
        *pcVar13 = cVar1;
        pcVar12 = (char *)((int)key->data + ((byte)(bVar7 + 6) - 6));
        local_20[4] = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ indata[4];
        cVar1 = *pcVar12;
        bVar15 = bVar15 + cVar1;
        pcVar13 = (char *)((int)key->data + (bVar15 - 6));
        cVar2 = *pcVar13;
        *pcVar12 = cVar2;
        *pcVar13 = cVar1;
        pcVar12 = (char *)((int)key->data + ((byte)(bVar7 + 7) - 6));
        local_20[5] = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ indata[5];
        cVar1 = *pcVar12;
        bVar15 = bVar15 + cVar1;
        pcVar13 = (char *)((int)key->data + (bVar15 - 6));
        cVar2 = *pcVar13;
        *pcVar12 = cVar2;
        *pcVar13 = cVar1;
        bVar7 = bVar7 + 8;
        puVar9 = indata + 8;
        pcVar13 = (char *)((int)key->data + (bVar7 - 6));
        local_20[6] = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ indata[6];
        cVar1 = *pcVar13;
        bVar15 = bVar15 + cVar1;
        pcVar12 = (char *)((int)key->data + (bVar15 - 6));
        cVar2 = *pcVar12;
        *pcVar13 = cVar2;
        *pcVar12 = cVar1;
        local_20[7] = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ indata[7];
        indata = puVar9;
        local_20 = local_20 + 8;
      } while (puVar9 != puVar10);
      local_18 = (sbyte)(len >> 3);
      local_25 = local_25 + local_18 * '\b';
      outdata = outdata + (len & 0xfffffff8);
    }
    uVar11 = len & 7;
    bVar7 = local_25;
    if (uVar11 != 0) {
      pcVar13 = (char *)((int)key->data + ((byte)(local_25 + 1) - 6));
      cVar1 = *pcVar13;
      bVar15 = bVar15 + cVar1;
      pcVar12 = (char *)((int)key->data + (bVar15 - 6));
      cVar2 = *pcVar12;
      *pcVar13 = cVar2;
      *pcVar12 = cVar1;
      *outdata = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ *indata;
      bVar7 = local_25 + 1;
      if (uVar11 != 1) {
        pcVar12 = (char *)((int)key->data + ((byte)(local_25 + 2) - 6));
        cVar1 = *pcVar12;
        bVar15 = bVar15 + cVar1;
        pcVar13 = (char *)((int)key->data + (bVar15 - 6));
        cVar2 = *pcVar13;
        *pcVar12 = cVar2;
        *pcVar13 = cVar1;
        outdata[1] = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ indata[1];
        bVar7 = local_25 + 2;
        if (uVar11 != 2) {
          pcVar12 = (char *)((int)key->data + ((byte)(local_25 + 3) - 6));
          cVar1 = *pcVar12;
          bVar15 = bVar15 + cVar1;
          pcVar13 = (char *)((int)key->data + (bVar15 - 6));
          cVar2 = *pcVar13;
          *pcVar12 = cVar2;
          *pcVar13 = cVar1;
          outdata[2] = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ indata[2];
          bVar7 = local_25 + 3;
          if (uVar11 != 3) {
            pcVar12 = (char *)((int)key->data + ((byte)(local_25 + 4) - 6));
            cVar1 = *pcVar12;
            bVar15 = bVar15 + cVar1;
            pcVar13 = (char *)((int)key->data + (bVar15 - 6));
            cVar2 = *pcVar13;
            *pcVar12 = cVar2;
            *pcVar13 = cVar1;
            outdata[3] = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ indata[3];
            bVar7 = local_25 + 4;
            if (uVar11 != 4) {
              pcVar12 = (char *)((int)key->data + ((byte)(local_25 + 5) - 6));
              cVar1 = *pcVar12;
              bVar15 = bVar15 + cVar1;
              pcVar13 = (char *)((int)key->data + (bVar15 - 6));
              cVar2 = *pcVar13;
              *pcVar12 = cVar2;
              *pcVar13 = cVar1;
              outdata[4] = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ indata[4];
              bVar7 = local_25 + 5;
              if (uVar11 != 5) {
                pcVar12 = (char *)((int)key->data + ((byte)(local_25 + 6) - 6));
                cVar1 = *pcVar12;
                bVar15 = bVar15 + cVar1;
                pcVar13 = (char *)((int)key->data + (bVar15 - 6));
                cVar2 = *pcVar13;
                *pcVar12 = cVar2;
                *pcVar13 = cVar1;
                outdata[5] = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ indata[5];
                bVar7 = local_25 + 6;
                if (uVar11 != 6) {
                  pcVar12 = (char *)((int)key->data + ((byte)(local_25 + 7) - 6));
                  cVar1 = *pcVar12;
                  bVar15 = bVar15 + cVar1;
                  pcVar13 = (char *)((int)key->data + (bVar15 - 6));
                  cVar2 = *pcVar13;
                  *pcVar12 = cVar2;
                  *pcVar13 = cVar1;
                  outdata[6] = *(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) ^ indata[6];
                  bVar7 = local_25 + 7;
                }
              }
            }
          }
        }
      }
    }
    goto LAB_080ea433;
  }
  uVar11 = len & 0xfffffffc;
  while (uVar11 != 0) {
    uVar11 = *(uint *)indata;
    pcVar12 = (char *)((int)key->data + ((byte)(local_25 + 1) - 6));
    cVar1 = *pcVar12;
    pcVar13 = (char *)((int)key->data + ((byte)(bVar15 + cVar1) - 6));
    cVar2 = *pcVar13;
    *pcVar13 = cVar1;
    *pcVar12 = cVar2;
    uVar3 = *(undefined *)((int)key->data + ((byte)(cVar1 + cVar2) - 6));
    pcVar12 = (char *)((int)key->data + ((byte)(local_25 + 2) - 6));
    cVar2 = *pcVar12;
    bVar15 = bVar15 + cVar1 + cVar2;
    pcVar13 = (char *)((int)key->data + (bVar15 - 6));
    cVar1 = *pcVar13;
    *pcVar13 = cVar2;
    *pcVar12 = cVar1;
    uVar4 = *(undefined *)((int)key->data + ((byte)(cVar2 + cVar1) - 6));
    pcVar12 = (char *)((int)key->data + ((byte)(local_25 + 3) - 6));
    cVar1 = *pcVar12;
    bVar15 = bVar15 + cVar1;
    pcVar13 = (char *)((int)key->data + (bVar15 - 6));
    cVar2 = *pcVar13;
    *pcVar13 = cVar1;
    *pcVar12 = cVar2;
    pcVar13 = (char *)((int)key->data + ((byte)(local_25 + 4) - 6));
    cVar5 = *pcVar13;
    uVar6 = *(undefined *)((int)key->data + ((byte)(cVar1 + cVar2) - 6));
    bVar15 = bVar15 + cVar5;
    pcVar12 = (char *)((int)key->data + (bVar15 - 6));
    cVar1 = *pcVar12;
    *pcVar12 = cVar5;
    *pcVar13 = cVar1;
    *(uint *)outdata =
         CONCAT13(*(undefined *)((int)key->data + ((byte)(cVar5 + cVar1) - 6)),
                  CONCAT12(uVar6,CONCAT11(uVar4,uVar3))) ^ uVar11;
    indata = (uchar *)((int)indata + 4);
    len = len - 4;
    outdata = (uchar *)((int)outdata + 4);
    local_25 = local_25 + 4;
    uVar11 = len & 0xfffffffc;
  }
  bVar7 = local_25;
  if (len == 0) goto LAB_080ea433;
  uVar11 = *(uint *)indata;
  uVar8 = *(uint *)outdata;
  if (len == 2) {
    local_18 = 8;
    uVar14 = 0;
    local_14 = 0;
LAB_080ea3af:
    local_25 = local_25 + 1;
    pcVar13 = (char *)((int)key->data + (local_25 - 6));
    cVar1 = *pcVar13;
    bVar15 = bVar15 + cVar1;
    pcVar12 = (char *)((int)key->data + (bVar15 - 6));
    cVar2 = *pcVar12;
    *pcVar12 = cVar1;
    *pcVar13 = cVar2;
    uVar14 = uVar14 | (uint)*(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) << local_14;
  }
  else {
    if (len == 3) {
      local_25 = local_25 + 1;
      local_18 = 0x10;
      local_14 = 8;
      pcVar13 = (char *)((int)key->data + (local_25 - 6));
      cVar1 = *pcVar13;
      bVar15 = bVar15 + cVar1;
      pcVar12 = (char *)((int)key->data + (bVar15 - 6));
      cVar2 = *pcVar12;
      *pcVar12 = cVar1;
      *pcVar13 = cVar2;
      uVar14 = (uint)*(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6));
      goto LAB_080ea3af;
    }
    uVar14 = 0;
    local_18 = 0;
  }
  pcVar13 = (char *)((int)key->data + ((byte)(local_25 + 1) - 6));
  cVar1 = *pcVar13;
  bVar15 = bVar15 + cVar1;
  pcVar12 = (char *)((int)key->data + (bVar15 - 6));
  cVar2 = *pcVar12;
  *pcVar12 = cVar1;
  *pcVar13 = cVar2;
  *(uint *)outdata =
       (uVar11 ^ uVar8 ^
       (uVar14 | (uint)*(byte *)((int)key->data + ((byte)(cVar1 + cVar2) - 6)) << local_18)) &
       0xffffffffU >> (('\x04' - (char)len) * '\b' & 0x1fU) ^ uVar8;
  bVar7 = local_25 + 1;
LAB_080ea433:
  local_25 = bVar7;
  *(byte *)&key->x = local_25;
  *(byte *)((int)&key->x + 1) = bVar15;
  return;
}

