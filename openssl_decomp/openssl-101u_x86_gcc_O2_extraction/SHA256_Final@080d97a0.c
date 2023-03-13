
int SHA256_Final(uchar *md,SHA256_CTX *c)

{
  uint *ptr;
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar1 = c->num;
  ptr = c->data;
  *(undefined *)((int)c->data + uVar1) = 0x80;
  uVar1 = uVar1 + 1;
  if (uVar1 < 0x39) {
    uVar3 = 0x38 - uVar1;
  }
  else {
    memset((void *)(uVar1 + (int)ptr),0,0x40 - uVar1);
    sha256_block_data_order();
    uVar3 = 0x38;
    uVar1 = 0;
  }
  puVar2 = (undefined4 *)(uVar1 + (int)ptr);
  if (uVar3 < 4) {
    if ((uVar3 != 0) && (*(undefined *)puVar2 = 0, (uVar3 & 2) != 0)) {
      *(undefined2 *)((int)puVar2 + (uVar3 - 2)) = 0;
    }
  }
  else {
    *puVar2 = 0;
    *(undefined4 *)((int)puVar2 + (uVar3 - 4)) = 0;
    uVar1 = (uint)((int)puVar2 + (uVar3 - ((uint)(puVar2 + 1) & 0xfffffffc))) & 0xfffffffc;
    if (3 < uVar1) {
      uVar3 = 0;
      do {
        *(undefined4 *)(((uint)(puVar2 + 1) & 0xfffffffc) + uVar3) = 0;
        uVar3 = uVar3 + 4;
      } while (uVar3 < uVar1);
    }
  }
  uVar1 = c->Nh;
  c->data[0xe] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = c->Nl;
  c->data[0xf] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  sha256_block_data_order();
  c->num = 0;
  OPENSSL_cleanse(ptr,0x40);
  uVar1 = c->md_len;
  if (uVar1 == 0x1c) {
    uVar1 = c->h[0];
    *(uint *)md = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[1];
    *(uint *)(md + 4) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[2];
    *(uint *)(md + 8) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[3];
    *(uint *)(md + 0xc) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[4];
    *(uint *)(md + 0x10) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[5];
    *(uint *)(md + 0x14) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[6];
    *(uint *)(md + 0x18) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  }
  else if (uVar1 == 0x20) {
    uVar1 = c->h[0];
    *(uint *)md = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[1];
    *(uint *)(md + 4) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[2];
    *(uint *)(md + 8) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[3];
    *(uint *)(md + 0xc) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[4];
    *(uint *)(md + 0x10) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[5];
    *(uint *)(md + 0x14) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[6];
    *(uint *)(md + 0x18) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    uVar1 = c->h[7];
    *(uint *)(md + 0x1c) =
         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  }
  else {
    if (0x20 < uVar1) {
      return 0;
    }
    if (uVar1 >> 2 != 0) {
      uVar1 = c->h[0];
      *(uint *)md = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      if (7 < c->md_len) {
        uVar1 = c->h[1];
        *(uint *)(md + 4) =
             uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
        if (0xb < c->md_len) {
          uVar1 = c->h[2];
          *(uint *)(md + 8) =
               uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
          if (0xf < c->md_len) {
            uVar1 = c->h[3];
            *(uint *)(md + 0xc) =
                 uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
            if (0x13 < c->md_len) {
              uVar1 = c->h[4];
              *(uint *)(md + 0x10) =
                   uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
              if (0x17 < c->md_len) {
                uVar1 = c->h[5];
                *(uint *)(md + 0x14) =
                     uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
                ;
                if (0x1b < c->md_len) {
                  uVar1 = c->h[6];
                  *(uint *)(md + 0x18) =
                       uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 |
                       uVar1 << 0x18;
                  if (0x1f < c->md_len) {
                    uVar1 = c->h[7];
                    *(uint *)(md + 0x1c) =
                         uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 |
                         uVar1 << 0x18;
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

