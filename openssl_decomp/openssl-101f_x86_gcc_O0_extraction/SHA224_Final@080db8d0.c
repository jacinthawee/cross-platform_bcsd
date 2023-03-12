
int SHA224_Final(uchar *md,SHA256_CTX *c)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  uVar2 = c->num;
  *(undefined *)((int)c->data + uVar2) = 0x80;
  uVar1 = uVar2 + 1;
  if (uVar1 < 0x39) {
    uVar2 = 0x38 - uVar1;
  }
  else {
    memset((void *)((int)c->data + uVar2 + 1),0,0x40 - uVar1);
    sha256_block_data_order();
    uVar2 = 0x38;
    uVar1 = 0;
  }
  puVar3 = (undefined4 *)((int)c->data + uVar1);
  if (uVar2 < 4) {
    if ((uVar2 != 0) && (*(undefined *)puVar3 = 0, (uVar2 & 2) != 0)) {
      *(undefined2 *)((int)puVar3 + (uVar2 - 2)) = 0;
    }
  }
  else {
    *puVar3 = 0;
    *(undefined4 *)((int)puVar3 + (uVar2 - 4)) = 0;
    uVar2 = (uint)((int)puVar3 + (uVar2 - ((uint)(puVar3 + 1) & 0xfffffffc))) & 0xfffffffc;
    if (3 < uVar2) {
      uVar1 = 0;
      do {
        *(undefined4 *)(((uint)(puVar3 + 1) & 0xfffffffc) + uVar1) = 0;
        uVar1 = uVar1 + 4;
      } while (uVar1 < uVar2);
    }
  }
  uVar2 = c->Nh;
  puVar3 = (undefined4 *)((uint)(c->data + 1) & 0xfffffffc);
  c->data[0xe] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar2 = c->Nl;
  c->data[0xf] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  sha256_block_data_order();
  c->num = 0;
  c->data[0] = 0;
  c->data[0xf] = 0;
  uVar2 = (uint)((int)c + (0x68 - (int)puVar3)) >> 2;
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
  }
  uVar2 = c->md_len;
  if (uVar2 == 0x1c) {
    uVar2 = c->h[0];
    *(uint *)md = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[1];
    *(uint *)(md + 4) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[2];
    *(uint *)(md + 8) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[3];
    *(uint *)(md + 0xc) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[4];
    *(uint *)(md + 0x10) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[5];
    *(uint *)(md + 0x14) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[6];
    *(uint *)(md + 0x18) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  }
  else if (uVar2 == 0x20) {
    uVar2 = c->h[0];
    *(uint *)md = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[1];
    *(uint *)(md + 4) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[2];
    *(uint *)(md + 8) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[3];
    *(uint *)(md + 0xc) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[4];
    *(uint *)(md + 0x10) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[5];
    *(uint *)(md + 0x14) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[6];
    *(uint *)(md + 0x18) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = c->h[7];
    *(uint *)(md + 0x1c) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  }
  else {
    if (0x20 < uVar2) {
      return 0;
    }
    if (uVar2 >> 2 != 0) {
      uVar2 = c->h[0];
      *(uint *)md = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      if (7 < c->md_len) {
        uVar2 = c->h[1];
        *(uint *)(md + 4) =
             uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
        if (0xb < c->md_len) {
          uVar2 = c->h[2];
          *(uint *)(md + 8) =
               uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
          if (0xf < c->md_len) {
            uVar2 = c->h[3];
            *(uint *)(md + 0xc) =
                 uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
            if (0x13 < c->md_len) {
              uVar2 = c->h[4];
              *(uint *)(md + 0x10) =
                   uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
              if (0x17 < c->md_len) {
                uVar2 = c->h[5];
                *(uint *)(md + 0x14) =
                     uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18
                ;
                if (0x1b < c->md_len) {
                  uVar2 = c->h[6];
                  *(uint *)(md + 0x18) =
                       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 |
                       uVar2 << 0x18;
                  if (0x1f < c->md_len) {
                    uVar2 = c->h[7];
                    *(uint *)(md + 0x1c) =
                         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 |
                         uVar2 << 0x18;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}
